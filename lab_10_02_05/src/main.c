#include <stdio.h>
#include <string.h>
#include "list.h"
#include "errors.h"

int main(void)
{
    char action[SIZE + 2] = { 0 };
    if (!fgets(action, SIZE + 2, stdin))
        return INPUT_ERROR;
    int len = strlen(action);
    if (action[len - 1] == '\n')
    {
        action[len - 1] = '\0';
        len--;
    }
    if (len > SIZE - 1)
        return INPUT_ERROR;
    node_t *src_str = read_string();
    if (!src_str)
        return INPUT_ERROR;
    int rc = INCORRECT_ACTION;
    if (strcmp(action, "out") == 0)
    {
        rc = OK;
        print_string(src_str);
    }
    else if (strcmp(action, "sps") == 0)
    {
        src_str = del_spaces(src_str);
        if (src_str)
        {
            print_string(src_str);
            rc = OK;
        }
    }
    else if (strcmp(action, "cat") == 0)
    {
        node_t *second_str = read_string();
        if (second_str)
        {
            node_t *result = concatenation(src_str, second_str);
            if (result)
            {
                print_string(result);
                rc = OK;
            }
        }
    }
    else if (strcmp(action, "pos") == 0)
    {
        node_t *required_str = read_string();
        if (required_str)
        {
            int pos = my_strstr(src_str, required_str);
            printf("%d", pos);
            rc = OK;
            free_list(required_str);
        }
    }
    free_list(src_str);
    return rc;
}
