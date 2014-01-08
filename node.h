#ifndef PLANET_H_INCLUDED
#define PLANET_H_INCLUDED

#include "structure.h"

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

  // Array of structures on the planet
  structure *structures;

  // Array of connected nodes and a number of them
  struct NODE *nodes;

  node_bools bools;

  uint16_t shield_health;

  // Number of nodes connected to this node
  uint8_t number_of_connections;

  uint8_t type;

  // The one owning the planet; 0 = neutral, 1 = player 1, etc.
  uint8_t owner;
} node;

#endif // PLANET_H_INCLUDED
