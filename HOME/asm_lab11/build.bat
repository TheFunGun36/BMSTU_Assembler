@echo off
cls

SET PATH=E:\masm32\bin
SET INCLUDE=E:\masm32\include
SET LIB=E:\masm32\lib
SET APPNAME=app

ml /nologo -c -coff %APPNAME%.asm
if errorlevel 1 goto terminate

LINK /nologo %APPNAME%.obj /SUBSYSTEM:WINDOWS /RELEASE
if errorlevel 1 goto terminate

echo OK

:terminate
pause