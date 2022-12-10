#include <stdio.h>
#include "list.h"
#include "grocery.h"

static node_t *search_prev(node_t *head, node_t *node);

node_t *read_list(FILE *f)
{
    grocery_t *grocery = grocery_read(f);
    if (!grocery)
        return NULL;
    node_t *list = create_node(grocery);
    if (list)
    {
        node_t *cur = NULL;
        grocery = grocery_read(f);
        while (grocery)
        {
            cur = create_node(grocery);
            if (!cur)
            {
                free_grocery(grocery);
                break;
            }
            list = add(cur, list);
            grocery = grocery_read(f);
        }
    }
    if (!feof(f))
    {
        free_list(list);
        return NULL;
    }
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

node_t *find(node_t *head, const void *data, int (*comparator)(const void *, const void *))
{
    while (head)
    {
        if (comparator(head->data, data) == 0)
            return head;
        head = head->next;
    }
    return NULL;
}

static node_t *search_prev(node_t *head, node_t *node)
{
    node_t *cur = head;
    while (cur && cur->next != node)
        cur = cur->next;
    return cur;
}

void insert(node_t **head, node_t *elem, node_t *before)
{
    if (!elem || !before || !(*head))
        return;
    if (*head == before)
    {
        elem->next = *head;
        *head = elem;
    }
    else
    {
        node_t *prev = search_prev(*head, before);
        if (prev)
        {
            elem->next = before;
            prev->next = elem;
        }
    }
}

node_t *reverse(node_t *head)
{
    if (!head)
        return NULL;
    node_t *prev = NULL;
    node_t *cur = head;
    node_t *next = head->next;
    while (next)
    {
        cur->next = prev;
        prev = cur;
        cur = next;
        next = next->next;
    }
    cur->next = prev;
    return cur;
}

int count_elements(node_t *head)
{
    int counter = 0;
    while (head)
    {
        counter++;
        head = head->next;
    }
    return counter;
}

void front_back_split(node_t *head, node_t **back)
{
    int amount = count_elements(head);
    *back = head;
    for (int i = 0; i < amount / 2 + amount % 2; ++i)
    {
        head = *back;
        *back = (*back)->next;
    }
    if (head)
        head->next = NULL;
}

node_t *sorted_merge(node_t **head_a, node_t **head_b, int (*comparator)(const void *, const void *))
{
    node_t *new_list = NULL;
    if (!(*head_a) && *head_b)
    {
        new_list = *head_b;
        *head_b = NULL;
        return new_list;
    }
    else if (!(*head_b) && *head_a)
    {
        new_list = *head_a;
        *head_a = NULL;
        return new_list;
    }
    else if (!(*head_b) && !(*head_a))
        return NULL;

    if (comparator((*head_a)->data, (*head_b)->data) < 0)
    {
        new_list = *head_a;
        if ((*head_a)->next && comparator((*head_a)->data, (*head_a)->next->data) > 0)
            return NULL;
        *head_a = (*head_a)->next;
    }
    else
    {
        new_list = *head_b;
        if ((*head_b)->next && comparator((*head_b)->data, (*head_b)->next->data) > 0)
            return NULL;
        *head_b = (*head_b)->next;
    }
    node_t *cur = new_list;
    while (*head_a && *head_b)
    {
        if (comparator((*head_a)->data, (*head_b)->data) < 0)
        {
            cur->next = *head_a;
            if ((*head_a)->next && comparator((*head_a)->data, (*head_a)->next->data) > 0)
                return NULL;
            *head_a = (*head_a)->next;
        }
        else
        {
            cur->next = *head_b;
            if ((*head_b)->next && comparator((*head_b)->data, (*head_b)->next->data) > 0)
                return NULL;
            *head_b = (*head_b)->next;
        }
        cur = cur->next;
    }
    if (*head_a)
    {
        cur->next = *head_a;
        while ((*head_a)->next)
        {
            if (comparator((*head_a)->data, (*head_a)->next->data) > 0)
                return NULL;
            *head_a = (*head_a)->next;
        }
        *head_a = NULL;
    }
    else if (*head_b)
    {
        cur->next = *head_b;
        while ((*head_b)->next)
        {
            if (comparator((*head_b)->data, (*head_b)->next->data) > 0)
                return NULL;
            *head_b = (*head_b)->next;
        }
        *head_b = NULL;
    }
    return new_list;
}

node_t *sort(node_t *head, int (*comparator)(const void *, const void*))
{
    if (!head || !head->next)
        return head;
    node_t *right_head = NULL;
    node_t *new_list = NULL;
    front_back_split(head, &right_head);
    head = sort(head, comparator);
    right_head = sort(right_head, comparator);
    new_list = sorted_merge(&head, &right_head, comparator);
    return new_list;
}

void print_list(FILE *f, node_t *head)
{
    while (head)
    {
        print_grocery(f, head->data);
        head = head->next;
    }
}
