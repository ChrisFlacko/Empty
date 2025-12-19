cmake_minimum_required(VERSION 3.20)

project(EMPTY C ASM)

# Sources
add_executable(${PROJECT_NAME}
    src/main.c
    src/startup.c
    src/os.c
    src/adc_driver.c 
    src/dma_driver.c 
    src/i2c_driver.c 
    src/spi_driver.c 
    src/rcc_driver.c
    src/gpio_driver.c
    src/tim_driver.c
    src/nvic_driver.c
    src/flash_driver.c
)
set_target_properties(EMPTY PROPERTIES OUTPUT_NAME "EMPTY.elf")
# Convert ELF to BIN after build
add_custom_command(TARGET EMPTY POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:EMPTY> $<TARGET_FILE:EMPTY>.bin
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Compile options for ARM Cortex-M
target_compile_options(${PROJECT_NAME} PRIVATE
    -mcpu=cortex-m4
    -mthumb
    -ffreestanding
    -nostdlib
    -O0
    -g
)

# Linker options
target_link_options(${PROJECT_NAME} PRIVATE
    -T${CMAKE_SOURCE_DIR}/linker.ld
    -nostdlib
    -Wl,--gc-sections
)