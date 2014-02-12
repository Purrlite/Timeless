#ifndef YAML_PARSER_H_INCLUDED
#define YAML_PARSER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "errors.h"

#define YAML_START_OF_FILE( file )    fputs("---\n\n", file)
#define YAML_START_OF_STREAM( file )  fputs("---\n\n", file)
#define YAML_END_OF_FILE( file )      fputs("...", file)

error_flag YAML_print_list(FILE *file, char **list, int number_of_items, int indentation_level) ;
error_flag YAML_print_inlined_list(FILE *file, char **list, int number_of_items) ;

#endif // YAML_PARSER_H_INCLUDED
