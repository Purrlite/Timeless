#include <stdio.h>

#include "map.h"
#include "node.h"
#include "defines.h"

int main(void) {
  map_s map;
  node_s node1;
  node_s node2;
  node_s default_node;

  printf("\n%d", create_node(&node1, "Test me", NULL));
  printf("\n%d", create_node(&node2, "Earth", NULL));
  printf("\n%d", create_node(&default_node, NULL, NULL));

  printf("\nPlanet health: %d", node1.planet_health);

  node1.planet_health = 12e3;

  printf("\nPlanet health: %d", node1.planet_health);

  printf("\n%d", create_map(&map, "Test map", &((map_settings_s){4, 2})));

  printf("\n%d", connect_nodes(&node1, &node2, _1_TO_2));

  printf("\n%d", add_node_to_map(&map, &node1));
  printf("\n%d", add_node_to_map(&map, &node2));

  printf("\n%d", save_map(&map, "map.yaml", &default_node, 1));

  free_node(&node1);
  free_node(&node2);
  free_node(&default_node);

  return 0;
}
