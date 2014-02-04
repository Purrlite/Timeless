#include "node.h"

error_flag connect_nodes(node_s *node1, node_s *node2, node_connection_type type) {
  if(node1 == NULL || node2 == NULL)
    return BAD_FUNCTION_ARGUMENT;

  if((type & _1_TO_2) == true) {
    if(node1->connected_nodes == NULL) {
      node1->connected_nodes = malloc( sizeof(node_s *) );
    } else {
      node1->connected_nodes = realloc( node1->connected_nodes, sizeof(node_s *) * (node1->number_of_connections + 1) );
    }

    if(node1->connected_nodes == NULL)
      return OUT_OF_MEMORY_ERROR;

    node1->connected_nodes[node1->number_of_connections] = node2;

    node1->number_of_connections++;
  }

  if((type & _2_TO_1) == true) {
    if(node2->connected_nodes == NULL) {
      node2->connected_nodes = malloc( sizeof(node_s *) );
    } else {
      node2->connected_nodes = realloc( node2->connected_nodes,
                                       sizeof(node_s *) * (node2->number_of_connections + 1) );
    }

    if(node2->connected_nodes == NULL)
      return OUT_OF_MEMORY_ERROR;

    node2->connected_nodes[node2->number_of_connections] = node1;

    node2->number_of_connections++;
  }

  return SUCCESS;
}


error_flag unconnect_nodes(node_s *node1, node_s *node2, node_connection_type type) {
  if(node1 == NULL || node2 == NULL)
    return BAD_FUNCTION_ARGUMENT;

  if((type & _1_TO_2) == true) {
    if(node1->connected_nodes == NULL)
      return BAD_FUNCTION_ARGUMENT;

    if(node1->number_of_connections == 1) {
      free(node1->connected_nodes);
    }

    node1->number_of_connections--;
  }

  if((type & _2_TO_1) == true) {
    if(node2->connected_nodes == NULL)
      return BAD_FUNCTION_ARGUMENT;

    if(node2->number_of_connections == 1) {
      free(node2->connected_nodes);
    }

    node2->number_of_connections--;
  }

  return SUCCESS;
}


bool is_reachable(node_s *origin, node_s *destination) {


}
