#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include "node.h"
#include "errors.h"

typedef struct {
  unsigned min_players :4 ;
  unsigned max_players :4 ;
  unsigned modes :24 ;
} map_settings_s;

typedef struct {
  node_s **nodes;

  char *name;

  char *description;

  map_settings_s settings;

  uint8_t number_of_nodes;
} map_s;

// Creates a new map, assumes that the map given by a pointer from new_map isn't initialized
error_flag create_map(map_s *new_map, char *name, map_settings_s *settings) ;

// Frees/deallocs the map
error_flag free_map(map_s *map) ;

error_flag save_map(map_s *new_map, char *file_name) ;
error_flag load_map(map_s *new_map, char *file_name) ;

error_flag add_node_s_to_map(map_s *map, node_s *node) ;
error_flag remove_node_s_from_map(map_s *map, node_s *node) ;

#endif // MAP_H_INCLUDED
