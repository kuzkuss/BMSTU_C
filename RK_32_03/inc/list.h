#ifndef LIST_H
#define LIST_H

#include "list_node.h"

node_t *read_list(FILE *f, int *rc);
void free_list(node_t *head);
void print_list(node_t *head);
node_t *form(node_t *head, const void *group);
void print_list_to_file(FILE *f, node_t *head);

#endif // LIST_H
