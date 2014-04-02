#ifndef UNIT_H_INCLUDED
#define UNIT_H_INCLUDED

#include <stdint.h>

#include "defines.h"

typedef struct {
  int16_t current_health;
  int16_t max_health;

  uint16_t damage_per_attack;
  // Attack cooldown = time between attacks
  float attack_cooldown;
  // Current cooldown = time before next attack
  float current_attack_cooldown;

  // Time it takes before planet jump is finished
  float jump_cooldown;
  // Time before the current jump finishes
  float current_jump_cooldown;
} unit_stats_s;


typedef struct {
  // Not sure if I need it, but would be good in general
  char *name;

  unit_stats_s *stats;

  // Pointer to the node the unit is at
  node_s *node_at;

  // Needs to be hashed based on time of creation, place and (type or name)
  uint64_t unit_ID;

  // CE consumption is always rounded up to nearest int.
  float CE_coefficient;

  uint8_t type;

  uint8_t faction;

  // The one owning the planet; -1 = AI player 1, 0 = neutral, 1 = player 1, etc.
  int8_t owner;
} unit_s;

#endif // UNIT_H_INCLUDED
