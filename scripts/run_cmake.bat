@echo off
rem ////////////////////////////////////////////////////////////////////////////////
rem /// Copyright (c) 2018-2019 Fabian Zahn - 0xFAB
rem /// See provided LICENSE file for more information
rem ///
rem /// Start GDB and connect to OpenOCD's GDB server
rem ////////////////////////////////////////////////////////////////////////////////

rem source environment: compiler, openocd, cmake, ...
call %~dp0source_env.bat

rem create build folder
cd ..
mkdir build
cd build

rem start CMake
cmd /K cmake -DCMAKE_TOOLCHAIN_FILE=./cmake/arm-none-eabi-gcc.cmake -G "Ninja" ..
