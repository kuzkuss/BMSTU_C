#ifndef LIST_NODE_H
#define LIST_NODE_H

typedef struct node node_t;

struct node
{
    void *data;
    node_t *next;
};

node_t *create_node(void *data);
void free_node(node_t *node);
node_t *add(node_t *elem, node_t *head);
int compare_name(const void *l_data, const void *r_data);
int compare_price(const void *l_data, const void *r_data);

#endif // LIST_NODE_H
