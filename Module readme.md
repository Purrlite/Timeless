# Module help/readme

Modules are used to specify implementation of functions and thus how the game acts.

Each modification needs a module for every .h file, so that modifications aren't dependant on each other.

## Information about modules:

### What rules modules need to follow:

* All modules need to contain all functions specified inside their respective .h (header) file
* All modules need to contain the module_info structure with information about the module. The information inside the module_info struct:
    * Modification name
	* Modification abbreviation (max 7 characters)
	* Version of the file (not of the modification/game itself)
* Name of module needs to use this naming convention: <header name><game mod's abbreviated name>.c/dll (e.g. unitEX.c)

### How to create a module:

* You make a .c file, that is a source file in the C programming language, that follows the rules stated above.
* Either drag the .c file onto the Dllfier or open up the commandline, call Dllifier with the file path as the first argument and optionally with second argument inside quotes being arguments for gcc for compilation of the file.
* Now you should have a .dll which you just need to put into mods directory inside the game/engine or create a new one if there isn't one already.