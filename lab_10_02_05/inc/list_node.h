#ifndef LIST_NODE_H
#define LIST_NODE_H

#define SIZE 4

typedef struct node node_t;

struct node
{
    char arr[SIZE];
    node_t *next;
};

node_t *create_node(char *arr);
node_t *add_node(node_t *new_node, node_t *head);
void free_node(node_t *node);
void print_node(node_t *node);

#endif // LIST_NODE_H
