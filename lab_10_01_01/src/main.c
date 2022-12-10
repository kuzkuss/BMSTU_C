#include <stdio.h>
#include <string.h>
#include "errors.h"
#include "list.h"
#include "grocery.h"

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);
    if (argc != 4)
        return KEY_ERROR;
    if (strcmp(argv[3], "descending") != 0 && strcmp(argv[3], "ascending") != 0)
        return INCORRECT_ARG;
    FILE *f_in = fopen(argv[1], "r");
    if (!f_in)
        return FILE_ERROR;
    int rc = INPUT_ERROR;
    node_t *list = read_list(f_in);
    if (list)
    {
        grocery_t *required_grocery = grocery_create("porridge", 1, 70);
        if (required_grocery)
        {
            grocery_t *additional_grocery = grocery_create("milk", 2, 60);
            if (additional_grocery)
            {
                node_t *additional_node = create_node(additional_grocery);
                if (additional_node)
                {
                    node_t *required_node = find(list, required_grocery, compare_name);
                    if (required_node)
                        insert(&list, additional_node, required_node);
                    rc = OK;
                }
                else
                    free_grocery(additional_grocery);
            }
            free_grocery(required_grocery);
        }
    }
    if (!list)
        return EMPTY_FILE;
    list = sort(list, compare_price);
    if (strcmp(argv[3], "descending") == 0)
        list = reverse(list);
    FILE *f_out = fopen(argv[2], "w");
    if (f_out)
    {
        print_list(f_out, list);
        fclose(f_out);
    }
    else
        rc = FILE_ERROR;
    free_list(list);
    fclose(f_in);
    return rc;
}
