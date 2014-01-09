#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include "node.h"

typedef struct {
  node *nodes;

  char *name;

  // Intended amount of players
  uint16_t intended_players;
} map;

#endif // MAP_H_INCLUDED
