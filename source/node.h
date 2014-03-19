#ifndef PLANET_H_INCLUDED
#define PLANET_H_INCLUDED

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#include "defines.h"
#include "structure.h"
#include "unit.h"
#include "errors.h"

typedef int node_connection_type;

typedef struct {
  // True if planet has shield protecting it (even if at 0 health)
  unsigned has_shield                      :1 ;

  unsigned is_colonized                    :1 ;
  unsigned is_colonizable                  :1 ;

  unsigned is_destroyable                  :1 ;

  // For hiding planets that you don't have connection to
  unsigned is_visible                      :1 ;

  // If yes, then you shouldn't be able to see what happens on it
  unsigned is_in_FOW                       :1 ;

  // Might not be needed, but could be useful when loading maps
  unsigned is_a_starting_planet            :1 ;
} node_bools_s;


typedef struct node_s {
  char *name;

  // Array of pointers to structures on the planet
  structure_s **structures;

  // Array of pointers to units on the planet
  unit_s **units;

  // Array of pointers of connected nodes
  struct node_s **connected_nodes;

  node_bools_s bools;

  uint32_t shield_health;

  // Health of planet if it's destructible
  uint32_t planet_health;

  // Number of nodes connected to this node
  uint8_t number_of_connections;

  uint8_t number_of_structures;
  uint8_t number_of_units;

  uint8_t type;

  // The one owning the planet; -1 = AI player 1, 0 = neutral, 1 = player 1, etc.
  int8_t owner;
} node_s;


#define create_node_bools(shield, colonized, colonizable, destroyable, visible, in_FOW, \
                          starting_planet) \
  (node_bools_s){ shield, colonized, colonizable, destroyable, visible, in_FOW, starting_planet }

#define create_node_bools_NULL() \
  (node_bools_s){ .has_shield = 0 }

error_flag create_node(node_s *new_node, char *name, node_bools_s *bools) ;

#define create_node_NULL(node) create_node(node, NULL, NULL, NULL);

void free_node(node_s *node);

// Connects 2 node_ss together; can connect them to work only 1 way or both ways
error_flag connect_nodes(node_s *node1, node_s *node2, node_connection_type type) ;

// Disconnects specified connection(s) between node_ss
error_flag unconnect_nodes(node_s *node1, node_s *node2, node_connection_type type) ;

// Returns whether or not it's possible to reach destination from origin
bool is_reachable(node_s *origin, node_s *destination) ;

#endif // PLANET_H_INCLUDED
