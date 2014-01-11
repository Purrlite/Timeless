#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include "node.h"
#include "errors.h"

typedef struct {
  unsigned min_players :4 ;
  unsigned max_players :4 ;
  unsigned modes :24 ;
} map_settings;

typedef struct {
  node **nodes;

  char *name;

  char *description;

  map_settings settings;

  uint8_t amount_of_nodes;
} map;

// Creates a new map, assumes that the map given by a pointer from new_map isn't initialized
error_flag create_map(map *new_map, char *name, map_settings settings) ;

error_flag save_map(map *new_map, char *file_name) ;
error_flag load_map(map *new_map, char *file_name) ;

#endif // MAP_H_INCLUDED
