#ifndef UNIT_H_INCLUDED
#define UNIT_H_INCLUDED

#include <stdint.h>

#include "defines.h"

typedef struct {
  int16_t current_health;
  uint16_t max_health;

  uint16_t damage_per_attack;
  float attack_cooldown;
  // Current cooldown = time before next attack
  float current_attack_cooldown;

  // Time it takes before planet jump is finished
  float jump_cooldown;
  // Time before the current jump finishes
  float current_jump_cooldown;
} unit_stats;


typedef struct {
  // Might use this to assign short names like TOR, NOVA, XER
  char *name;

  unit_stats *stats;

  // Needs to be hashed based on time of creation, place and (type or name)
  uint64_t unit_ID;

  uint8_t type;

  uint8_t faction;

  // Planet ID of the planet the unit is at
  uint8_t planet_at;
} unit;

#endif // UNIT_H_INCLUDED
