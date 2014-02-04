#ifndef MODULE_H_INCLUDED
#define MODULE_H_INCLUDED

#include <windows.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  HMODULE module;
  char *name;
  char *modification_abbr; // Abbreviation of the name of the modification the module belongs to
} module_s;

typedef struct {
  module_s *modules;
  int number_of_loaded_modules;
} module_list_s;


module_s * module_open(char *path, char *name, char *modification_name) ;
void module_close(module_s module) ;

#endif // MODULE_H_INCLUDED
