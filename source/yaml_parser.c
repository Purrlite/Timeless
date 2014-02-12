#include "yaml_parser.h"

error_flag YAML_print_list(FILE *file, char **list, int number_of_items, int indentation_level) {
  int i;
  char *total_indentation;

  if(file == NULL || list == NULL)
    return BAD_FUNCTION_ARGUMENT;

  total_indentation = malloc(indentation_level * 4 + 1);
  for(i = 0; i < indentation_level; i++) {
    total_indentation[i * 4] = ' ';
    total_indentation[i * 4 + 1] = ' ';
    total_indentation[i * 4 + 2] = ' ';
    total_indentation[i * 4 + 3] = ' ';
  }
  total_indentation[i * 4 + 4] = '\n';

  for(i = 0; i < number_of_items; i++)
    fprintf(file, "%s- %s\n", total_indentation, list[i]);

  return SUCCESS;
}

error_flag YAML_print_inlined_list(FILE *file, char **list, int number_of_items) {
  int i;

  if(file == NULL || list == NULL)
    return BAD_FUNCTION_ARGUMENT;

  fputs(" [ ", file);

  fprintf(file, "%s", list[0]);
  for(i = 1; i < number_of_items; i++) {
    fprintf(file, ", %s", list[i]);
  }

  fputs(" ]\n", file);

  return SUCCESS;
}
