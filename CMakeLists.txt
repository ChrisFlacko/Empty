cmake_minimum_required(VERSION 3.20)

project(EMPTY C ASM)

# Sources
add_executable(${PROJECT_NAME}
    src/main.c
    src/startup.c
)

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