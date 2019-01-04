@echo off
rem ////////////////////////////////////////////////////////////////////////////////
rem /// Copyright (c) 2018-2019 Fabian Zahn - 0xFAB
rem /// See provided LICENSE file for more information
rem ///
rem /// Start a command shell with the development environment sourced
rem ////////////////////////////////////////////////////////////////////////////////

rem source environment: compiler, openocd, cmake, ...
call %~dp0source_env.bat

rem Open a shell in the current working directory
cmd /K cd %~dp0
