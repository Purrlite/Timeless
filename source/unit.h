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

  // Number of seconds before planet jump is finished
  float jump_cooldown;
  // Current amount of seconds before the current planet jump finishes
  float current_jump_cooldown;
} unit_stats_s;


typedef struct {
  unit_stats_s *stats;

  // Pointer to the node the unit is at
  node_s *node_at;

  // Needs to be hashed based on time of creation, place and type
  uint64_t unit_ID;

  // Coefficient of how much CE an order of this type of unit takes; Always rounded up when used.
  float CE_coefficient;

  uint8_t type;

  uint8_t faction;

  int8_t owner;
} unit_s;

#endif // UNIT_H_INCLUDED
