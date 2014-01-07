#ifndef PLANET_H_INCLUDED
#define PLANET_H_INCLUDED

#include "structure.h"

typedef struct NODE {
  char *name;

  // Array of structures on the planet
  structure *structures;

  // Array of connected nodes and a number of them
  struct NODE *nodes;

  uint16_t shield_health;

  // Number of nodes connected to this node
  uint8_t number_of_connections;

  // True if planet has shield protecting it (even if at 0 health)
  uint8_t has_shield;

  uint8_t type;

  // The one owning the planet; 0 = neutral, 1 = player 1, etc.
  uint8_t owner;
} node;

#endif // PLANET_H_INCLUDED
