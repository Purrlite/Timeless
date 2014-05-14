#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED

#include <stdint.h>

#include "node.h"
#include "defines.h"

// Needed because of structure.h being sometimes included inside node.h first
typedef struct node_s node_s;

typedef struct {
  char *name;

  // Pointer to the node the unit is at
  node_s *node_at;

  uint64_t structure_ID;

  int16_t current_health;
  uint16_t max_health;

  uint8_t type;

  uint8_t faction;

  // placement on the planet (e.g. top, bottom, etc.)
  uint8_t placement;

  int8_t owner;
} structure_s;

#endif // STRUCTURE_H_INCLUDED
