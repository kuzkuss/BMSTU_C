#include <stdio.h>
#include <ctype.h>
#include "list.h"

static node_t *shift(node_t *string, int i);

node_t *read_string(void)
{
    char arr[SIZE];
    node_t *list = NULL;
    int i = 0;
    arr[i] = getchar();
    if (arr[i] == EOF)
        return NULL;
    while (arr[i] != '\n' && arr[i] != '\r' && arr[i] != EOF)
    {
        if (++i == SIZE)
        {
            node_t *new_node = create_node(arr);
            if (!new_node)
            {
                free_list(list);
                return NULL;
            }
            list = add_node(new_node, list);
            i = 0;
        }
        arr[i] = getchar();
    }
    arr[i] = '\0';
    node_t *new_node = create_node(arr);
    if (new_node)
        list = add_node(new_node, list);
    else
    {
        free_list(list);
        list = NULL;
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

node_t *concatenation(node_t *left_string, node_t *right_string)
{
    node_t *result = left_string;
    while (left_string->next)
        left_string = left_string->next;
    left_string->next = right_string;
    int i = 0;
    while (left_string->arr[i])
        i++;
    int j = 0;
    while (right_string->arr[j])
    {
        left_string->arr[i] = right_string->arr[j];
        if (++i == SIZE)
        {
            left_string = left_string->next;
            i = 0;
        }
        if (++j == SIZE)
        {
            if (!right_string->next)
                j--;
            else
            {
                right_string = right_string->next;
                j = 0;
            }
        }
    }
    left_string->arr[i] = right_string->arr[j];
    if (left_string != right_string)
    {
        free_node(left_string->next);
        left_string->next = NULL;
    }
    return result;
}

static node_t *shift(node_t *string, int i)
{
    node_t *head = string;
    while (string->arr[i])
    {
        if (i + 1 == SIZE)
            string->arr[i] = string->next->arr[0];
        else
            string->arr[i] = string->arr[i + 1];
        if (++i == SIZE)
        {
            string = string->next;
            i = 0;
        }
    }
    if (i == SIZE - 1)
    {
        free_node(string->next);
        string->next = NULL;
    }
    return head;
}

node_t *del_spaces(node_t *string)
{
    int i = 0;
    node_t *head = string;
    while (string->arr[i])
    {
        if (isspace(string->arr[i]))
        {
            if (++i == SIZE)
            {
                string = string->next;
                i = 0;
            }
            while (isspace(string->arr[i]))
                shift(string, i);
        }

        if (++i == SIZE)
        {
            string = string->next;
            i = 0;
        }
    }
    return head;
}

int my_strstr(node_t *src_str, node_t *req_str)
{
    int pos = 0;
    int i = 0;
    int j = 0;
    while (src_str->arr[i])
    {
        node_t *cur = req_str;
        j = 0;
        if (src_str->arr[i] == req_str->arr[j])
        {
            int new_i = i;
            node_t *new_src_str = src_str;
            while (new_src_str->arr[new_i] == cur->arr[j])
            {
                if (!cur->arr[j])
                    return pos;
                if (++new_i == SIZE)
                {
                    new_src_str = new_src_str->next;
                    new_i = 0;
                }
                if (++j == SIZE)
                {
                    cur = cur->next;
                    j = 0;
                }
            }
            if (!cur->arr[j])
                return pos;
        }
        if (++i == SIZE)
        {
            src_str = src_str->next;
            i = 0;
        }
        pos++;
    }
    pos = -1;
    return pos;
}

void print_string(node_t *string)
{
    while (string)
    {
        print_node(string);
        string = string->next;
    }
}

