#ifndef MODULE_H_INCLUDED
#define MODULE_H_INCLUDED

#include <windows.h>

typedef struct {
  HMODULE *modules;
  char **names;
  int number_of_loaded_modules;
} module_list_s;

typedef struct {
  HMODULE module;
  char name;
} module_s;

#endif // MODULE_H_INCLUDED
