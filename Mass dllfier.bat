:: Makes up to 9 .dll files from .o or .c files

@echo off

if "%~9" == ""  goto empty9

  if /I %~x9 == .o  call gcc -shared -o %~n9.dll %9

  if /I %~x9 == .c  call gcc -c -std=c11 %9
  if /I %~x9 == .c  call gcc -shared -o %~n9.dll %~n9.o
  if /I %~x9 == .c  del %~n9.o

:empty9

if "%~8" == ""  goto empty8

  if /I %~x8 == .o  call gcc -shared -o %~n8.dll %8

  if /I %~x8 == .c  call gcc -c -std=c11 %8
  if /I %~x8 == .c  call gcc -shared -o %~n8.dll %~n8.o
  if /I %~x8 == .c  del %~n8.o

:empty8

if "%~7" == ""  goto empty7

  if /I %~x7 == .o  call gcc -shared -o %~n7.dll %7

  if /I %~x7 == .c  call gcc -c -std=c11 %7
  if /I %~x7 == .c  call gcc -shared -o %~n7.dll %~n7.o
  if /I %~x7 == .c  del %~n7.o

:empty7

if "%~6" == ""  goto empty6

  if /I %~x6 == .o  call gcc -shared -o %~n6.dll %6

  if /I %~x6 == .c  call gcc -c -std=c11 %6
  if /I %~x6== .c  call gcc -shared -o %~n6.dll %~n6.o
  if /I %~x6 == .c  del %~n6.o

:empty6

if "%~5" == ""  goto empty5

  if /I %~x5 == .o  call gcc -shared -o %~n5.dll %5

  if /I %~x5 == .c  call gcc -c -std=c11 %5
  if /I %~x5 == .c  call gcc -shared -o %~n5.dll %~n5.o
  if /I %~x5 == .c  del %~n5.o

:empty5

if "%~4" == ""  goto empty4

  if /I %~x4 == .o  call gcc -shared -o %~n4.dll %4

  if /I %~x4 == .c  call gcc -c -std=c11 %4
  if /I %~x4 == .c  call gcc -shared -o %~n4.dll %~n4.o
  if /I %~x4 == .c  del %~n4.o

:empty4

if "%~3" == ""  goto empty3

  if /I %~x3 == .o  call gcc -shared -o %~n3.dll %3

  if /I %~x3 == .c  call gcc -c -std=c11 %3
  if /I %~x3 == .c  call gcc -shared -o %~n3.dll %~n3.o
  if /I %~x3 == .c  del %~n3.o

:empty3

if "%~2" == ""  goto empty2

  if /I %~x2 == .o  call gcc -shared -o %~n2.dll %2

  if /I %~x2 == .c  call gcc -c -std=c11 %2
  if /I %~x2 == .c  call gcc -shared -o %~n2.dll %~n2.o
  if /I %~x2 == .c  del %~n2.o

:empty2

if "%~1" == ""  goto empty1

  if /I %~x1 == .o  call gcc -shared -o %~n1.dll %1

  if /I %~x1 == .c  call gcc -c -std=c11 %1
  if /I %~x1 == .c  call gcc -shared -o %~n1.dll %~n1.o
  if /I %~x1 == .c  del %~n1.o

:empty1