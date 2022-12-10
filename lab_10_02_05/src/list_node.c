#include <stdio.h>
#include <stdlib.h>
#include "list_node.h"

node_t *create_node(char *arr)
{
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node)
    {
        for (int i = 0; i < SIZE; ++i)
        {
            new_node->arr[i] = arr[i];
            if (!new_node->arr[i])
                break;
        }
        new_node->next = NULL;
    }
    return new_node;
}

node_t *add_node(node_t *new_node, node_t *head)
{
    if (!head)
        return new_node;
    node_t *cur = head;
    while (cur->next)
        cur = cur->next;
    cur->next = new_node;
    return head;
}

void free_node(node_t *node)
{
    free(node);
}

void print_node(node_t *node)
{
    for (int i = 0; i < SIZE && node->arr[i]; ++i)
        printf("%c", node->arr[i]);
}
