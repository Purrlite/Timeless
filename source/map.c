#include <stdlib.h>
#include <stdio.h>

#include "map.h"
#include "errors.h"
#include "node.h"
#include "warnings.h"

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


error_flag save_map(map_s *new_map, char *file_name) {
  FILE *map_file;
  int flag;
  char line[128];

  map_file = fopen(file_name, "wx");

  if(map_file == NULL) {
    flag = overwrite_file_message(file_name);

    if(flag == true) {
      map_file = fopen(file_name, "w");

      if(map_file == NULL)
        return FILE_ERROR;
    } else
      return ABORTED_BY_USER;
  }


}


error_flag load_map(map_s *new_map, char *file_name) {


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
