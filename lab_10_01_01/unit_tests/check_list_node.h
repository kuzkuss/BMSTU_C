#ifndef CHECK_LIST_NODE_H
#define CHECK_LIST_NODE_H

#include <check.h>

#define EPS 1.0e-7

typedef struct node node_t;

struct node
{
    void *data;
    node_t *next;
};

node_t *create_node(void *data);
int compare_name(const void *l_data, const void *r_data);
int compare_price(const void *l_data, const void *r_data);
void free_node(node_t *node);

Suite *create_node_suite(void);
Suite *compare_name_suite(void);
Suite *compare_price_suite(void);

#endif // CHECK_LIST_NODE_H
