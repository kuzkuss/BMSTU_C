#ifndef CHECK_LIST_H
#define CHECK_LIST_H

#include "check_list_node.h"

#define SIZE_RES 23

void free_list(node_t *head);
node_t *concatenation(node_t *left_string, node_t *right_string);
node_t *del_spaces(node_t *string);
int my_strstr(node_t *src_str, node_t *req_str);
node_t *add_node(node_t *new_node, node_t *head);

Suite* concatenation_suite(void);
Suite* del_spaces_suite(void);
Suite* my_strstr_suite(void);

#endif // CHECK_LIST_H
