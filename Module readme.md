# Module help/readme

Modules are used to specify implementation of functions and thus how the game acts.

Each modification needs a module for every .h file, so that modifications aren't dependant on each other. If you want to add a module from an already existing modification without changing it, then just copy it and change the name of the file to fit your modification's name.

## Information about modules

### What rules modules need to follow:

* All modules need to contain all functions specified inside their respective .h (header) file
* Name of module needs to use this naming convention: <header name><game mod's abbreviated name>.c/dll (e.g. unitEX.c)

### How to create a module:

* You make a .c file, that is a source file in the C programming language, that follows the rules stated above.
* Convert the the file or files into .dll using the dllfier or mass dllfier, which can support up to 9 files at once.
* Now you should have a .dll which you just need to put into mods directory inside the game/engine or create a new one if there isn't one already.

### How to call the dllfier:

You can either:

* Drag the .c or .o (if you have already compiled the .c file) file onto the dllfier, which should act like supplying the file names as arguments to the dllfier.
* Open the commandline, cd into the directory of the file and call dllfier with the file name being the first argument and optionally with more arguments inside quotes that will be given to gcc, when it compiles the .c file

In case of using the Mass dllfier:

* Drag the .c or .o files (you can combine both kinds) onto the Mass dllfier
* Open the commandline, cd into the directory of the files and call the Mass dllfier (you might need quotes around the file name) with the file names of the files. Adding optional gcc arguments isn't possible currently

## Information about the dllfier

The dllfier transforms .c or .o files into .dll files that are ready to be used as modules. Every .c file is compiled under the C11 standard.