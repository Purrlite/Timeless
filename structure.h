#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED

#include <stdint.h>

#include "defines.h"

typedef struct {
  char *name;

  uint64_t structure_ID;

  int16_t current_health;
  uint16_t max_health;

  uint8_t type;

  uint8_t faction;

  uint8_t planet_at; // ID of the planet at which the structure is

  uint8_t placement; // placement on the planet
} structure;

#endif // STRUCTURE_H_INCLUDED
