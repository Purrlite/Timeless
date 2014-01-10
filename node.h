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
  unsigned has_shield           :1 ;

  unsigned is_colonized         :1 ;
  unsigned is_colonizable       :1 ;

  // For hiding planets that you don't have connection to
  unsigned is_visible           :1 ;

  // If yes, then you shouldn't be able to see what happens on it
  unsigned is_in_FOW            :1 ;

  // Might not be needed, but could be useful when loading maps
  unsigned is_a_starting_planet :1 ;
} node_bools;

typedef struct NODE {
  char *name;

  // Array of pointers to structures on the planet
  structure *structures;

  // Array of pointers to units on the planet
  unit *units;

  // Array of pointers of connected nodes
  struct NODE **nodes;

  node_bools bools;

  uint16_t shield_health;

  // Number of nodes connected to this node
  uint8_t number_of_connections;

  uint8_t type;

  // The one owning the planet; -1 = AI, 0 = neutral, 1 = player 1, etc.
  int8_t owner;
} node;

#define new_node_bool(shield, colonized, colonizable, visible, in_FOW, starting_planet)\
  ( (node_bools){ shield, colonized, colonizable, visible, in_FOW, starting_planet } )

// Creates a new node (might rework later)
#define new_node(name, structures, units, connected_nodes, bools, shield_health,\
                    number_of_connections, type, owner)\
  { name, structures, units, connected_nodes, bools, shield_health, number_of_connections,\
type, owner }

error_flag connect_nodes(node *node1, node *node2, node_connection_type type) ;

#endif // PLANET_H_INCLUDED
