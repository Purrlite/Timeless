#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "yaml_parser.h"
#include "map.h"
#include "node.h"
#include "errors.h"
#include "warnings.h"

#define IF_PRINT(node, default, string)  if(node != default) { \
    sprintf(temporary, string"%s\n", (node == true ? "Yes" : "No")); \
    YAML_print_list(file, &temporary, 1, 1); \
  }

static char ** get_node_names(map_s *map, node_s **nodes, int number_of_nodes) {
  int i, j;
  int sequential_number;
  char **names = NULL;

  for(i = 0; i < number_of_nodes; i++) {
    names = realloc(names, sizeof(char*) * (i + 1));
    names[i] = malloc(9); // 1 for '*', 4 for "node", 3 for numbers, 1 for '\0'
    sequential_number = 0;

    for(j = 0; j < map->number_of_nodes; j++) {
      if(&(map->nodes[j]) == nodes[i]) {
        sequential_number = j + 1;
        break;
      }
    }

    if(sequential_number != 0)
      sprintf(names[i], "*node%d", sequential_number);
  }

  return names;
}


static error_flag save_node(FILE *file, map_s *map, node_s *node, node_s *default_values,
                       int number_of_defaults) {
  int i;
  int _default;
  char **node_names;
  char *temporary = malloc(32);

  if(file == NULL || map == NULL || node == NULL || default_values == NULL)
    return BAD_FUNCTION_ARGUMENT;

  for(i = 0; i < map->number_of_nodes; i++)
    if(node == &(map->nodes[i]))
      break;

  for(_default = 0; _default < number_of_defaults; _default++) {
    if(node->type == default_values[_default].type)
      break;

    // If it can't find the correct type, then use the first one.
    if(_default == number_of_defaults - 1)
      _default = 0;
  }

  YAML_START_OF_STREAM(file);

  fprintf(file, "Name: %s    &node%d\n"
                "Type: %s\n",
          node->name, i, node->type);

  if(node->owner > 0)
    fprintf(file, "Owner: Player %d\n", node->owner);
  else if(node->owner < 0)
    fprintf(file, "Owner: AI %d\n", -node->owner);
  else
    fputs("Owner: Neutral\n", file);

  if(node->planet_health != default_values[_default].planet_health)
    fprintf(file, "Planet health: %ld\n", node->planet_health);
  if(node->shield_health != default_values[_default].shield_health)
    fprintf(file, "Shield health: %ld\n", node->shield_health);

  fputs("\nBools:\n", file);

  IF_PRINT(node->bools.has_shield, default_values[_default].bools.has_shield, "Has shield: ")
  IF_PRINT(node->bools.is_a_starting_planet, default_values[_default].bools.is_a_starting_planet,
           "Is a starting planet: ")
  IF_PRINT(node->bools.is_colonized, default_values[_default].bools.is_colonized, "Is colonized: ")
  IF_PRINT(node->bools.is_colonizable, default_values[_default].bools.is_colonizable,
           "Is colonizable: ")
  IF_PRINT(node->bools.is_destroyable, default_values[_default].bools.is_destroyable,
           "Is destroyable: ")
  IF_PRINT(node->bools.is_in_FOW, default_values[_default].bools.is_in_FOW, "Is in FOW: ")
  IF_PRINT(node->bools.is_visible, default_values[_default].bools.is_visible, "Is visible: ")

  fputs("\nConnected nodes:\n", file);

  if(node->number_of_connections == 0) {
    node_names = malloc(sizeof(node_names));
    *node_names = malloc(5);
    strncpy(*node_names, "none", 5);

    YAML_print_list(file, node_names, 1, 1 );

    free(*node_names);
    free(node_names);
  } else {
    node_names = get_node_names(map, node->connected_nodes, node->number_of_connections);

    YAML_print_list(file, node_names, node->number_of_connections, 1);

    for(i = 0; i < node->number_of_connections; i++)
      free(node_names[i]);
    free(node_names);
  }

  fputs("\n", file);

  return SUCCESS;
}


error_flag create_map(map_s *new_map, char *name, map_settings_s *settings) {
  if(name == NULL || new_map == NULL)
    return BAD_FUNCTION_ARGUMENT;

  if(settings == NULL)
    new_map->settings = (map_settings_s){0};
  else
    new_map->settings = *settings;

  new_map->nodes = NULL;
  new_map->number_of_nodes = 0;
  new_map->modes = NULL;
  new_map->number_of_modes = 0;
  new_map->name = name;
  new_map->description = "-";

  return SUCCESS;
}


error_flag free_map(map_s *map) {
  if(map == NULL)
    return BAD_FUNCTION_ARGUMENT;

  free(map->nodes);
  free(map);

  return SUCCESS;
}


error_flag save_map(map_s *map, char *file_name, node_s *default_values, int number_of_defaults) {
  FILE *map_file;
  bool overwrite;
  int i;

  if(map == NULL || default_values == NULL)
    return BAD_FUNCTION_ARGUMENT;

  map_file = fopen(file_name, "wx");

  if(map_file == NULL) {
    overwrite = overwrite_file_message(file_name);

    if(overwrite == true) {
      map_file = fopen(file_name, "w");

      if(map_file == NULL)
        return FILE_ERROR;
    } else
      return ABORTED_BY_USER;
  }

  YAML_START_OF_FILE(map_file);

  fprintf(map_file, "Name: %s\n"
                    "Description: %s\n\n",
          map->name, map->description);

  fputs("Map settings:\n", map_file);
  fprintf(map_file, "    min players: %d\n"
                    "    max players: %d\n"
                    "    modes:",
          map->settings.min_players, map->settings.max_players);
  YAML_print_inlined_list(map_file, map->modes, map->number_of_modes);

  fputs("\n", map_file);

  for(i = 0; i < map->number_of_nodes; i++) {
    save_node(map_file, map, &(map->nodes[i]), default_values, number_of_defaults);
  }

  YAML_END_OF_FILE(map_file);

  fclose(map_file);

  return SUCCESS;
}


error_flag load_map(map_s *map, char *file_name, node_s *default_values, int number_of_defaults) {
  FILE *map_file;
  char *line;
  error_flag error = SUCCESS;

  if(map == NULL || default_values == NULL)
    return BAD_FUNCTION_ARGUMENT;

  line = malloc(128);

  if(line == NULL) {
    error = OUT_OF_MEMORY_ERROR;
    goto line_error;
  }

  map_file = fopen(file_name, "r");
  if(map_file == NULL) {
    error = FILE_ERROR;
    goto fopen_error;
  }





  fclose(map_file);
fopen_error:

  free(line);
line_error:

  return error;
}

error_flag add_node_to_map(map_s *map, node_s *node) {
  if(map == NULL || node == NULL)
    return BAD_FUNCTION_ARGUMENT;

  map->nodes = realloc(map->nodes, (map->number_of_nodes + 1) * sizeof(node_s));

  if(map->nodes == NULL)
    return OUT_OF_MEMORY_ERROR;

  map->nodes[map->number_of_nodes] = *node;

  map->number_of_nodes++;

  return SUCCESS;
}


error_flag remove_node_from_map(map_s *map, node_s *node) {
  int i;
  bool node_found = false;
  node_s exchange_node;

  if(map == NULL || node == NULL)
    return BAD_FUNCTION_ARGUMENT;

  for(i = 0; i < map->number_of_nodes; i++) {
    if(&(map->nodes[i]) == node) {
      node_found = true;
      break;
    }
  }

  if(node_found == true) {
    for( ; i < map->number_of_nodes - 1; i++) {
      exchange_node = map->nodes[i];
      map->nodes[i] = map->nodes[i+1];
      map->nodes[i+1] = exchange_node;
    }

    map->number_of_nodes--;
  } else {
    return BAD_FUNCTION_ARGUMENT;
  }

  return SUCCESS;
}

#undef IF_PRINT
