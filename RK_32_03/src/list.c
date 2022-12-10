#include <stdio.h>
#include <string.h>
#include "errors.h"
#include "list.h"

node_t *read_list(FILE *f, int *rc)
{
    student_t *student = student_read(f, rc);
    if (!student)
        return NULL;

    node_t *list = create_node(student);
    if (list)
    {
        node_t *cur = NULL;
        student = student_read(f, rc);
        while (student)
        {
            cur = create_node(student);
            if (!cur)
            {
                free_student(student);
                break;
            }
            list = add_node(cur, list);
            student = student_read(f, rc);
        }
    }
    if (!feof(f))
    {
        free_list(list);
        return NULL;
    }
    else
        *rc = OK;
    return list;
}

void free_list(node_t *head)
{
    node_t *next = NULL;
    while (head)
    {
        next = head->next;
        free_node(head);
        head = next;
    }
}

void print_list(node_t *head)
{
    while (head)
    {
        print_student(head->student);
        head = head->next;
    }
}

void print_list_to_file(FILE *f, node_t *head)
{
    while (head)
    {
        print_student_to_file(f, head->student);
        head = head->next;
    }
}

node_t *form(node_t *head, const void *group)
{
    node_t *new_list = NULL;
    while (head)
    {
        if (strcmp(group, head->student->info[1]) == 0)
        {
            student_t *new_student = student_create(head->student->info[0], head->student->year, head->student->info[1]);
            if (!new_student)
            {
                free_list(new_list);
                return NULL;
            }
            node_t *new_node = create_node(new_student);
            if (!new_node)
            {
                free_student(new_student);
                free_list(new_list);
                return NULL;
            }
            new_list = add_node(new_node, new_list);
        }
        head = head->next;
    }
    return new_list;
}
