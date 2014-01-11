#include <stdlib.h>

#include "map.h"
#include "errors.h"

error_flag create_map(map *new_map, char *name, map_settings settings) {
  if(new_map == NULL) {
    new_map = malloc( sizeof(map) );

    if(new_map == NULL)
      return OUT_OF_MEMORY_ERROR;
  }

  new_map->nodes = NULL;
  new_map->amount_of_nodes = 0;
  new_map->name = name;
  new_map->settings = settings;
  new_map->description = "No description yet";

  return SUCCESS;
}


error_flag save_map(map *new_map, char *file_name) {

}


error_flag load_map(map *new_map, char *file_name) {

}
