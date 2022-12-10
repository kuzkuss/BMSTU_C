#ifndef CHECK_LIST_NODE_H
#define CHECK_LIST_NODE_H

#include <check.h>

#define SIZE 4

typedef struct node node_t;

struct node
{
    char arr[SIZE];
    node_t *next;
};

node_t *create_node(char *arr);
void free_node(node_t *node);
Suite* create_node_suite(void);

#endif // CHECK_LIST_NODE_H
