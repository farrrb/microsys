# MicroSys - A bare-metal micro:bit environment in C

This project provides an open source bare-metal system environment for the BBC [micro:bit](https://microbit.org/) board. The project is completely written in C and does not depend on the standard library.

Features:
- Written in C
- Structured CMake build environment
- Build from scratch
- Based on FOSS software
  + [GCC & GDB - arm-none-eabi-gcc](https://developer.arm.com/open-source/gnu-toolchain/gnu-rm/downloads)
  + [OpenOCD](http://openocd.org/)
  + [CMake](https://cmake.org/)
  + [Ninja Build](https://ninja-build.org/)

## Build Status
[![Build Status](https://travis-ci.org/farrrb/microsys.svg?branch=master)](https://travis-ci.org/farrrb/microsys)

## Project Structure
The project is structured as following:
- **build**
  + The temporary build directory for cmake
- **cmake**
  + Toolchain file for arm-none-eabi-gcc
- **openocd**
  + Configuration script for OpenOCD gdb server
- **out**
  + A temporary folder for the output files (.elf, .hex, .map, ...)
- **src**     - The source directory
  + **application**
    * The application
  + **ld**
    * Linker script file
  + **microhal**
    * A tiny (minimalistic) hardware abstraction library
  + **startup**
    * The startup code to initialize the microcontroller and the c runtime environment

## Getting Started
### Install Toolchain
Install the following tools:

- GCC & GDB [arm-none-eabi-gcc](https://developer.arm.com/open-source/gnu-toolchain/gnu-rm/downloads)
- [OpenOCD](http://openocd.org/)
- [CMake](https://cmake.org/)
- [Ninja Build](https://ninja-build.org/)

Make them available to your environment (e.g. via PATH on windows or write a script you can source).

### Run CMake
```
cmake -DCMAKE_TOOLCHAIN_FILE=./cmake/arm-none-eabi-gcc.cmake -G "Ninja" ..
```

### Flash the Target
You can flash the target via two methods:
1. Copy the microsys.hex file from the *out* directory to the mass storage device of the miro:bit
2. Flash using gdb (see using gdb)


## Using GDB with OpenOCD
TODO
