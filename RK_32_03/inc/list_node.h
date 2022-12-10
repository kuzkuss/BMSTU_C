#ifndef LIST_NODE_H
#define LIST_NODE_H

#include "student.h"

typedef struct node node_t;

struct node
{
    student_t *student;
    node_t *next;
};

node_t *create_node(student_t *student);
void free_node(node_t *node);
node_t *add_node(node_t *elem, node_t *head);

#endif // LIST_NODE_H
