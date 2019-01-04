@echo off
rem ////////////////////////////////////////////////////////////////////////////////
rem /// Copyright (c) 2018-2019 Fabian Zahn - 0xFAB
rem /// See provided LICENSE file for more information
rem ///
rem /// Start GDB and connect to OpenOCD's GDB server
rem ////////////////////////////////////////////////////////////////////////////////

rem source environment: compiler, openocd, cmake, ...
call %~dp0source_env.bat

rem change to working dir
cd %~dp0..\gdb\

rem start GDB with command file
arm-none-eabi-gdb --command commands.gdb
