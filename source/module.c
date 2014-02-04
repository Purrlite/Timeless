#include "module.h"
#include "errors.h"

module_s * module_open(char *path, char *name, char *modification_abbr) {
  char *full_filename = malloc(512);
  module_s * new_module = malloc( sizeof(module_s) );

  strncpy(full_filename, path, 500);
  strcat(full_filename, name);
  strcat(full_filename, modification_abbr);

  new_module.module = LoadLibrary(full_filename);

  if(new_module.module == NULL)
    return NULL;

  new_module.name = name;
  new_module.modification_abbr = modification_abbr;

  return new_module;
}

error_flag module_close(module_s * module) {
  if(module == NULL)
    return BAD_FUNCTION_ARGUMENT;

  if(FreeLibrary(module.module) == 0)
    return IO_ERROR;

  free(module.name);
  free(module.modification_abbr);
  free(module);

  return SUCCESS;
}
