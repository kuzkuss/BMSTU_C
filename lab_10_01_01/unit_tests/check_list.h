#ifndef CHECK_LIST_H
#define CHECK_LIST_H

#include <stdio.h>
#include <check.h>
#include "check_list_node.h"
#include "check_grocery.h"

node_t *read_list(FILE *f);
void free_list(node_t *head);
node_t *find(node_t *head, const void *data, int (*comparator)(const void *, const void *));
void insert(node_t **head, node_t *elem, node_t *before);
node_t *reverse(node_t *head);
node_t *sorted_merge(node_t **head_a, node_t **head_b, int (*comparator)(const void *, const void *));
node_t *sort(node_t *head, int (*comparator)(const void *, const void*));
grocery_t *grocery_create(const char *name, int amount, double price);
node_t *add(node_t *elem, node_t *head);

Suite *read_list_suite(void);
Suite *find_suite(void);
Suite *insert_suite(void);
Suite *reverse_suite(void);
Suite *sorted_merge_suite(void);
Suite *sort_suite(void);

#endif // CHECK_LIST_H
