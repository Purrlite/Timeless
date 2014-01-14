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
  unsigned has_shield                    :1 ;

  unsigned is_colonized                  :1 ;
  unsigned is_colonizable                :1 ;

  unsigned is_destructible               :1 ;

  // For hiding planets that you don't have connection to
  unsigned is_visible                    :1 ;

  // If yes, then you shouldn't be able to see what happens on it
  unsigned is_in_FOW                     :1 ;

  // Might not be needed, but could be useful when loading maps
  unsigned is_a_starting_planet          :1 ;

  // If it has limited or unlimited amount of resources.
  unsigned has_unlimited_common_resource :1 ;
  unsigned has_unlimited_rare_resource   :1 ;
} node_bools;

// Max and current amount of resources on the planet
typedef struct {
  uint32_t max_common;
  uint32_t max_uncommon;
  uint32_t max_rare;
  uint32_t common;
  uint32_t uncommon;
  uint32_t rare;
} node_resources;

typedef struct NODE {
  char *name;

  // Array of pointers to structures on the planet
  structure *structures;

  // Array of pointers to units on the planet
  unit *units;

  node_resources *resources;

  // Array of pointers of connected nodes
  struct NODE **connected_nodes;

  node_bools bools;

  uint32_t shield_health;

  // Health of planet if it's destructible
  uint32_t planet_health;

  // Number of nodes connected to this node
  uint8_t number_of_connections;

  uint8_t type;

  // The one owning the planet; -1 = AI, 0 = neutral, 1 = player 1, etc.
  int8_t owner;
} node;

#define create_node_bool(shield, colonized, colonizable, visible, in_FOW, starting_planet,\
                         unlimited_CR, unlimited_RR)\
  ( { shield, colonized, colonizable, visible, in_FOW, starting_planet, unlimited_CR,\
unlimited_RR } )

#define create_node_resources(max_common, max_uncommon, max_rare, common, uncommon, rare)\
  ( { max_common, max_uncommon, max_rare, common, uncommon, rare } )

// Creates a new node (might rework later)
#define create_node(name, structures, units, connected_nodes, bools, resources, shield_health,\
                 planet_health, number_of_connections, type, owner)\
  ( { name, structures, units, connected_nodes, bools, resources, shield_health, planet_health,\
number_of_connections, type, owner } )

#define create_node_NULL() \
  (node){.name = NULL }

// Connects 2 nodes together; can connect them to work only 1 way or both ways
error_flag connect_nodes(node *node1, node *node2, node_connection_type type) ;

// Disconnects specified connection(s) between nodes
error_flag unconnect_nodes(node *node1, node *node2, node_connection_type type) ;

#endif // PLANET_H_INCLUDED
