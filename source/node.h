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

  // For completely hiding planets so you don't see they are there at all until they are revealed
  unsigned is_visible                      :1 ;

  // If true, then you shouldn't be able to see what happens on it
  unsigned is_in_FOW                       :1 ;

  // A planet which a player starts with control over.
  unsigned is_a_starting_planet            :1 ;
} node_bools_s;


typedef struct node_s {
  char *name;

  // Structures located on the planet
  structure_s **structures;

  // Units located on the planet
  unit_s **units;

  struct node_s **connected_nodes;

  node_bools_s bools;

  uint32_t shield_health;

  // Health of planet if it's destructible, 0 otherwise.
  uint32_t planet_health;

  // Number of connections to other nodes
  uint8_t number_of_connections;

  uint8_t number_of_structures;
  uint8_t number_of_units;

  uint8_t type;

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

// Connects 2 nodes together; can connect them only 1 way or both ways
error_flag connect_nodes(node_s *node1, node_s *node2, node_connection_type type) ;

// Disconnects specified connection(s) between nodes
error_flag unconnect_nodes(node_s *node1, node_s *node2, node_connection_type type) ;

bool is_reachable(node_s *origin, node_s *destination) ;

#endif // PLANET_H_INCLUDED
