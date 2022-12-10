#ifndef LIST_H
#define LIST_H

#include "list_node.h"

node_t *read_list(FILE *f);
void free_list(node_t *head);
node_t *find(node_t *head, const void *data, int (*comparator)(const void *, const void *));
void insert(node_t **head, node_t *elem, node_t *before);
node_t *reverse(node_t *head);
int count_elements(node_t *head);
void front_back_split(node_t *head, node_t **back);
node_t *sorted_merge(node_t **head_a, node_t **head_b, int (*comparator)(const void *, const void *));
node_t *sort(node_t *head, int (*comparator)(const void *, const void*));
void print_list(FILE *f, node_t *head);

#endif //LIST_H
