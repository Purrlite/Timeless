#include "node.h"

error_flag connect_nodes(node *node1, node *node2, node_connection_type type) {
  if((type & _1_TO_2) == true) {
    if(node1->nodes == NULL) {
      node1->nodes = malloc( sizeof(node *) );
    } else {
      node1->nodes = realloc( node1->nodes, sizeof(node *) * (node1->number_of_connections + 1) );
    }

    if(node1->nodes == NULL)
      return OUT_OF_MEMORY_ERROR;

    node1->nodes[node1->number_of_connections] = node2;
  }

  if((type & _2_TO_1) == true) {
    if(node2->nodes == NULL) {
      node2->nodes = malloc( sizeof(node *) );
    } else {
      node2->nodes = realloc( node2->nodes, sizeof(node *) * (node2->number_of_connections + 1) );
    }

    if(node2->nodes == NULL)
      return OUT_OF_MEMORY_ERROR;

    node2->nodes[node2->number_of_connections] = node1;
  }

  return SUCCESS;
}
