:: Makes a .dll file from .c or .o file.
::  - second argument is for optional arguments for gcc compilation

@echo off
if /I %~x1 == .o  call gcc -shared -o %~n1.dll %1

if /I %~x1 == .c  call gcc -c -std=c11 %1 %~2
if /I %~x1 == .c  call gcc -shared -o %~n1.dll %~n1.o
if /I %~x1 == .c  del %~n1.o