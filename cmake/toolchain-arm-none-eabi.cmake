# =============================
# ARM Cortex-M Toolchain File
# =============================

# This tells CMake that we are cross-compiling
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

# Path prefix of the ARM toolchain
# If arm-none-eabi-gcc is in PATH, no change needed.
set(TOOLCHAIN_PREFIX arm-none-eabi)

# Compilers
set(CMAKE_C_COMPILER     /opt/homebrew/bin/arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER   /opt/homebrew/bin/arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER   /opt/homebrew/bin/arm-none-eabi-gcc)

# Tools
#set(CMAKE_OBJCOPY        ${TOOLCHAIN_PREFIX}-objcopy)
#set(CMAKE_SIZE           ${TOOLCHAIN_PREFIX}-size)

# No standard libraries from host system
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# CPU settings
#set(MCU_FLAGS "-mcpu=cortex-m4 -mthumb")

# Common C flags
#set(CMAKE_C_FLAGS_INIT "${MCU_FLAGS} -ffreestanding -fno-builtin -Wall -Wextra")

# ASM flags
#set(CMAKE_ASM_FLAGS_INIT "${MCU_FLAGS}")

# C++ flags (if needed)
#set(CMAKE_CXX_FLAGS_INIT "${MCU_FLAGS} -fno-exceptions -fno-rtti")

# Linker flags (the main CMakeLists passes the linker script)
#set(CMAKE_EXE_LINKER_FLAGS_INIT "${MCU_FLAGS} -nostdlib -Wl,--gc-sections")