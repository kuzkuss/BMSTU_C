#ifndef LIST_H
#define LIST_H

#include "list_node.h"

node_t *read_string(void);
void free_list(node_t *head);
node_t *concatenation(node_t *left_string, node_t *right_string);
node_t *del_spaces(node_t *str);
int my_strstr(node_t *src_str, node_t *req_str);
void print_string(node_t *string);

#endif // LIST_H
