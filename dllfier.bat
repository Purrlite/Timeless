:: Makes a .dll file from .c file.
::  - second argument is for optional arguments for gcc compilation
call gcc -c %1 %~2
call gcc -shared -o %~n1.dll %~n1.o
del %~n1.o