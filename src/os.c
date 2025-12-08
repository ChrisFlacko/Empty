/*
 * os.c
 *
 *  Created on: Jul 15, 2025
 *      Author: chris
 */

#include "os.h"

/* Tasks */
TCB mainTask;
TCB sensorTask;
TCB sendTask;

TCB *currentTask;

/* Reserve the memory space for the two tasks */
/* Make sure they are 8byte aligned */
__attribute__((aligned(8))) uint32_t u32Task1Stack[STACK_SIZE];
__attribute__((aligned(8))) uint32_t u32Task2Stack[STACK_SIZE];
__attribute__((aligned(8))) uint32_t u32MainTask[STACK_SIZE];
__attribute__((aligned(8))) uint32_t u32SensorTask[STACK_SIZE];
__attribute__((aligned(8))) uint32_t u32SendTask[STACK_SIZE];


void mainTaskFunc(void)
{
    for (;;)
    {
        // ... do work, maybe wait for tick or event
    }
}

void sensorTaskFunc(void)
{
    for (;;)
    {
        // ... do work, maybe wait for tick or event
    }
}

void sendTaskFunc(void)
{
    for (;;)
    {
        // ... do work, maybe wait for tick or event
    }
}

__attribute__((noreturn)) static void TaskExit(void)
{
    for (;;) { __asm volatile("WFI"); }
}

static uint32_t *mainTaskTop;
static uint32_t *sensorTaskTop;
static uint32_t *sendTaskTop;

void OS_vSetupStackFrame()
{
	mainTaskTop = (uint32_t*)(((uintptr_t)&u32MainTask[STACK_SIZE]) & ~((uintptr_t)0x7));
	sensorTaskTop = (uint32_t*)(((uintptr_t)&u32SensorTask[STACK_SIZE]) & ~((uintptr_t)0x7));
	sendTaskTop = (uint32_t*)(((uintptr_t)&u32SendTask[STACK_SIZE]) & ~((uintptr_t)0x7));
    OS_vInitialStackFrame(mainTask, mainTaskTop, mainTaskFunc);
    OS_vInitialStackFrame(sensorTask, sensorTaskTop, sensorTaskFunc);
    OS_vInitialStackFrame(sendTask, sendTaskTop, sendTaskFunc);
}

void OS_vInitialStackFrame(TCB task, uint32_t *sp, void (*entry)(void))
{
    sp -= 8;                                 // HW frame
    sp[0] = 0;                               // R0
    sp[1] = 0;                               // R1
    sp[2] = 0;                               // R2
    sp[3] = 0;                               // R3
    sp[4] = 0;                               // R12
    sp[5] = (uint32_t)TaskExit;              // LR if Task2 returns
    sp[6] = ((uint32_t)entry) | 1U;      // PC (Thumb)
    sp[7] = 0x01000000;                      // xPSR (Thumb)

    sp -= 8;                                 // R4..R11 spill area
    for (int i = 0; i < 8; ++i) sp[i] = 0xAAAAAAAA;

    sp = (uint32_t*)(((uintptr_t)sp) & ~((uintptr_t)0x7));
    sensorTask.psp = sp;                          // PSP for Task2 restore in PendSV
}

/*
 * This function initialize the first context of the ROTS
 * Therefore it pops manually the register R4-R11
 * Afterwards, through the "BX LR" instruction the rest of the registers get popped and the executing of the first task is starting
 */
void OS_vStartRTOS(void)
{
    __asm volatile(
        "CPSID   i                  \n"

        // Use PSP in Thread mode
        "MOV     r0, #2             \n"
        "MSR     CONTROL, r0        \n"
        "ISB                        \n"

        // PSP = top of Task1 stack (clean stack for direct start)
        "LDR     r0, =mainTaskTop     \n"
        "LDR     r0, [r0]           \n"
        "MSR     PSP, r0            \n"

        // If Task1 returns, go to TaskExit
        "LDR     r1, =TaskExit      \n"
        "ORR     r1, r1, #1         \n"   // ensure Thumb bit
        "MOV     LR, r1             \n"

        "CPSIE   i                  \n"

        // Branch to Task1 entry (Thumb)
        "LDR     r0, =mainTaskFunc     \n"
        "ORR     r0, r0, #1         \n"
        "BX      r0                 \n"
    );
}

void OS_vConfigureTasks(void)
{
	mainTask.nextPt = &sensorTask;
	mainTask.prio = 4;
	mainTask.state = t_ready;
	currentTask = &mainTask;
}

/* By entering, R0-R3, R12, LR and xPSR are automatically saved */
__attribute__((naked)) void PendSV_Handler(void)
{
	/* Disable interrupts */
	__asm volatile ("CPSID i");

	/* Load psp for saving r4-r11 */
	__asm("MRS R0, psp");

	/* Saving r4-r11 on the stack of the current task */
	__asm("STMDB R0!, {R4-R11}");

	/* Load the psp of the current task */
	__asm("LDR R1, =currentTask");		// Load address
	__asm("LDR R2, [R1]");				// Load value of the address of R1

	/* Store the new psp (R1) into current stack pointer of the current task (R0) */
	__asm("STR R0, [R2]");

	/* Access the nextPt element by increment the address of the current task by 4. R0 is now the address of the next task */
	/* Load the value of the next Task pointer */
	__asm("LDR R3, [R2, #4]");

	/* Store the next task pointer into the currentTask */
	__asm("STR R3, [R1]");

	/* Load the psp of the next task, which is still in R3 */
	__asm("LDR R0, [R3]");

	/* Pop the registers r4-r11 */
	__asm("LDMIA R0!, {R4-R11}");

	/* Store the next task pointer into the psp */
	__asm("MSR psp, R0");

	/* Enable interrupts */
	__asm volatile ("CPSIE i");

	/* Exit the handler */
	__asm("BX LR");
}
