#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "grocery.h"
#include "list_node.h"

#define EPS 1e-7

node_t *create_node(void *data)
{
    node_t *new_node = malloc(sizeof(node_t));
    if (!new_node)
        return NULL;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void free_node(node_t *node)
{
    free_grocery(node->data);
    free(node);
}

node_t *add(node_t *elem, node_t *head)
{
    elem->next = head;
    return elem;
}

int compare_name(const void *l_data, const void *r_data)
{
    const grocery_t *l_grocery = l_data;
    const grocery_t *r_grocery = r_data;
    return strcmp(l_grocery->name, r_grocery->name);
}

int compare_price(const void *l_data, const void *r_data)
{
    const grocery_t *l_grocery = l_data;
    const grocery_t *r_grocery = r_data;
    int res = 0;
    if (fabs(l_grocery->price - r_grocery->price) < EPS)
        res = 0;
    else if (l_grocery->price < r_grocery->price)
        res = -1;
    else if (l_grocery->price > r_grocery->price)
        res = 1;
    return res;
}
