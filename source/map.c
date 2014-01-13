#include <stdlib.h>
#include <stdio.h>

#include "map.h"
#include "errors.h"
#include "node.h"
#include "warnings.h"

error_flag create_map(map *new_map, char *name, map_settings *settings) {
  if(name == NULL)
    return BAD_FUNCTION_ARGUMENT;

  if(new_map == NULL) {
    new_map = malloc( sizeof(map) );

    if(new_map == NULL)
      return OUT_OF_MEMORY_ERROR;
  }

  new_map->nodes = NULL;
  new_map->amount_of_nodes = 0;
  new_map->name = name;
  new_map->settings = *settings;
  new_map->description = "No description yet";

  return SUCCESS;
}


error_flag free_map(map *_map) {
  if(_map == NULL)
    return BAD_FUNCTION_ARGUMENT;

  free(_map->nodes);
  free(_map);

  return SUCCESS;
}


error_flag save_map(map *new_map, char *file_name) {
  FILE *map_file;
  int flag;

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


error_flag load_map(map *new_map, char *file_name) {


}

error_flag add_node_to_map(map *_map, node *_node) {
  int i = _map->amount_of_nodes;

  if(_map == NULL)
    return BAD_FUNCTION_ARGUMENT;

  _map->nodes = realloc(_map->nodes, (i + 1) * sizeof(node **));

  if(_map->nodes == NULL)
    return OUT_OF_MEMORY_ERROR;

  if(_node == NULL) {
    _map->nodes[i] = &(create_node_NULL());
  } else {
    _map->nodes[i] = _node;
  }

  _map->amount_of_nodes++;

  return SUCCESS;
}


error_flag remove_node_from_map(map *_map, node *_node) {
  int i;
  bool node_found = false;
  node *exchange_node;

  if(_map == NULL || _node == NULL)
    return BAD_FUNCTION_ARGUMENT;

  for(i = 0; i < _map->amount_of_nodes; i++) {
    if(_map->nodes[i] == _node) {
      node_found = true;
      break;
    }
  }

  if(node_found == true) {
    for( ; i < _map->amount_of_nodes - 1; i++) {
      exchange_node = _map->nodes[i];
      _map->nodes[i] = _map->nodes[i+1];
      _map->nodes[i+1] = exchange_node;
    }

    _map->amount_of_nodes--;
  } else { // The specified node wasn't found
    return BAD_FUNCTION_ARGUMENT;
  }

  return SUCCESS;
}
