#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED

#include <stdint.h>

#include "defines.h"

typedef struct {
  char *name;

  // Pointer to the node the unit is at
  node *node_at;

  uint64_t structure_ID;

  int16_t current_health;
  uint16_t max_health;

  uint8_t type;

  uint8_t faction;

  // placement on the planet (e.g. top, bottom, etc.)
  uint8_t placement;

  // The one owning the planet; -1 = AI player 1, 0 = neutral, 1 = player 1, etc.
  int8_t owner;
} structure;

#endif // STRUCTURE_H_INCLUDED
