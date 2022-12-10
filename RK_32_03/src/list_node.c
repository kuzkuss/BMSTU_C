#include <stdlib.h>
#include "list_node.h"

node_t *create_node(student_t *student)
{
    node_t *new_node = malloc(sizeof(node_t));
    if (!new_node)
        return NULL;
    new_node->student = student;
    new_node->next = NULL;
    return new_node;
}

void free_node(node_t *node)
{
    free_student(node->student);
    free(node);
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
