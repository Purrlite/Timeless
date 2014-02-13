#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

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
  int sequential_number = 0;
  char **names = NULL;

  for(i = 0; i < number_of_nodes; i++) {
    names = realloc(names, sizeof(char*) * (i + 1));
    names[i] = malloc(9); // 1 for '*', 4 for "node", 3 for numbers, 1 for '\0'

    for(j = 0; j < map->number_of_nodes; j++) {
      if(map->nodes[j] == nodes[i]) {
        sequential_number = j + 1;
        break;
      }
    }

    sprintf(names[i], "*node%d", sequential_number);
  }

  return names;
}


static void save_node(FILE *file, map_s *map, node_s *node, node_s **default_values,
                       int number_of_defaults) {
  int i;
  int _default;
  char **node_names;
  char *temporary = malloc(32);

  for(i = 0; i < map->number_of_nodes; i++)
    if(node == map->nodes[i])
      break;

  for(_default = 0; _default < number_of_defaults; _default++) {
    if(node->type == default_values[_default]->type)
      break;
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

  if(node->resources->common != default_values[_default]->resources->common)
    fprintf(file, "Common resources: %ld\n", node->resources->common);
  if(node->resources->uncommon != default_values[_default]->resources->uncommon)
    fprintf(file, "Uncommon resources: %ld\n", node->resources->uncommon);
  if(node->resources->rare != default_values[_default]->resources->rare)
    fprintf(file, "Rare resources: %ld\n", node->resources->rare);
  if(node->resources->max_common != default_values[_default]->resources->max_common)
    fprintf(file, "Common resources: %ld\n", node->resources->max_common);
  if(node->resources->max_uncommon != default_values[_default]->resources->max_uncommon)
    fprintf(file, "Uncommon resources: %ld\n", node->resources->max_uncommon);
  if(node->resources->max_rare != default_values[_default]->resources->max_rare)
    fprintf(file, "Rare resources: %ld\n", node->resources->max_rare);

  if(node->planet_health != default_values[_default]->planet_health)
    fprintf(file, "Planet health: %ld\n", node->planet_health);
  if(node->shield_health != default_values[_default]->shield_health)
    fprintf(file, "Shield health: %ld\n", node->shield_health);

  fputs("\nBools:\n", file);

  IF_PRINT(node->bools.has_unlimited_common_resource,
           default_values[_default]->bools.has_unlimited_common_resource, "Has unlimited CR: ")
  IF_PRINT(node->bools.has_unlimited_uncommon_resource,
           default_values[_default]->bools.has_unlimited_uncommon_resource, "Has unlimited UR: ")
  IF_PRINT(node->bools.has_unlimited_rare_resource,
           default_values[_default]->bools.has_unlimited_rare_resource, "Has unlimited RR: ")
  IF_PRINT(node->bools.has_shield, default_values[_default]->bools.has_shield, "Has shield: ")
  IF_PRINT(node->bools.is_a_starting_planet, default_values[_default]->bools.is_a_starting_planet,
           "Is a starting planet: ")
  IF_PRINT(node->bools.is_colonized, default_values[_default]->bools.is_colonized, "Is colonized: ")
  IF_PRINT(node->bools.is_colonizable, default_values[_default]->bools.is_colonizable,
           "Is colonizable: ")
  IF_PRINT(node->bools.is_destroyable, default_values[_default]->bools.is_destroyable,
           "Is destroyable: ")
  IF_PRINT(node->bools.is_in_FOW, default_values[_default]->bools.is_in_FOW, "Is in FOW: ")
  IF_PRINT(node->bools.is_visible, default_values[_default]->bools.is_visible, "Is visible: ")

  fputs("\nConnected nodes:\n", file);

  if(node->number_of_connections == 0) {
    YAML_print_list(file, &"None", 1, 1 );
  } else {
    YAML_print_list(file, node_names = get_node_names(map, node->connected_nodes,
                    node->number_of_connections), node->number_of_connections, 1);

    for(i = 0; i < node->number_of_connections; i++)
      free(node_names[i]);
    free(node_names);
  }

  fputs("\n", file);

  return;
}


error_flag create_map(map_s *new_map, char *name, map_settings_s *settings) {
  if(name == NULL)
    return BAD_FUNCTION_ARGUMENT;

  if(new_map == NULL) {
    new_map = malloc( sizeof(map_s) );

    if(new_map == NULL)
      return OUT_OF_MEMORY_ERROR;
  }

  new_map->nodes = NULL;
  new_map->number_of_nodes = 0;
  new_map->name = name;
  new_map->settings = *settings;
  new_map->description = "No description yet";

  return SUCCESS;
}


error_flag free_map(map_s *map) {
  if(map == NULL)
    return BAD_FUNCTION_ARGUMENT;

  free(map->nodes);
  free(map);

  return SUCCESS;
}


error_flag save_map(map_s *map, char *file_name, node_s **default_values, int number_of_defaults) {
  FILE *map_file;
  bool overwrite;
  int i;

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

  for(i = 0; i < map->number_of_nodes; i++)
    save_node(map_file, map, map->nodes[i], default_values, number_of_defaults);

  YAML_END_OF_FILE(map_file);

  fclose(map_file);

  return SUCCESS;
}


error_flag load_map(map_s *map, char *file_name, node_s **default_values, int number_of_defaults) {


}

error_flag add_node_to_map(map_s *map, node_s *node) {
  int i = map->number_of_nodes;

  if(map == NULL)
    return BAD_FUNCTION_ARGUMENT;

  map->nodes = realloc(map->nodes, (i + 1) * sizeof(node_s **));

  if(map->nodes == NULL)
    return OUT_OF_MEMORY_ERROR;

  if(node == NULL) {
    map->nodes[i] = &(create_node_NULL());
  } else {
    map->nodes[i] = node;
  }

  map->number_of_nodes++;

  return SUCCESS;
}


error_flag remove_node_from_map(map_s *map, node_s *node) {
  int i;
  bool node_found = false;
  node_s *exchange_node;

  if(map == NULL || node == NULL)
    return BAD_FUNCTION_ARGUMENT;

  for(i = 0; i < map->number_of_nodes; i++) {
    if(map->nodes[i] == node) {
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
  } else { // The specified node_s wasn't found
    return BAD_FUNCTION_ARGUMENT;
  }

  return SUCCESS;
}

#undef IF_PRINT
