#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include "node.h"
#include "errors.h"

typedef struct {
  unsigned min_players :4 ;
  unsigned max_players :4 ;
} map_settings_s;


typedef struct {
  node_s *nodes;

  char *name;

  char *description;

  char **modes;

  map_settings_s settings;

  uint8_t number_of_nodes;

  uint8_t number_of_modes;
} map_s;


error_flag create_map(map_s *new_map, char *name, map_settings_s *settings) ;

error_flag free_map(map_s *map) ;

/* Saves/Loads a map
 *  - default values are used for each node type, but if node type isn't found, then 1. node in
 *    default nodes is used.
 */
error_flag save_map(map_s *map, char *file_name, node_s *default_values, int number_of_defaults) ;
error_flag load_map(map_s *map, char *file_name, node_s *default_values, int number_of_defaults) ;

error_flag add_node_to_map(map_s *map, node_s *node) ;
error_flag remove_node_from_map(map_s *map, node_s *node) ;

#endif // MAP_H_INCLUDED
