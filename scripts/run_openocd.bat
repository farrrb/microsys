@echo off
rem ////////////////////////////////////////////////////////////////////////////////
rem /// Copyright (c) 2018-2019 Fabian Zahn - 0xFAB
rem /// See provided LICENSE file for more information
rem ///
rem /// Start OpenOCD's GDB server: localhost:3333
rem ////////////////////////////////////////////////////////////////////////////////

rem source environment: compiler, openocd, cmake, ...
call %~dp0source_env.bat

rem change working directory
cd %~dp0..\openocd\

rem start OpenOCD
openocd -f microbit.cfg
