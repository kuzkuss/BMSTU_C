#include "process.h"
#include "const.h"

void print_struct(struct_t product)
{
    printf("%s", product.name);
    printf("%s", product.manufacturer);
    printf("%u\n", product.price);
    printf("%u\n", product.amount);
}

int process(struct_t *products, int num, char *str)
{
    int len, k, y, count = 0;
    for (int i = 0; i < num; i++)
    {
        len = strlen(products[i].name);
        k = 0;
        y = strlen(str) - 1;
        for (int j = len - 2; j >= 0 && y >= 0; j--)
        {
            if (products[i].name[j] == str[y])
                k++;
            else
                break;
            y--;
        }
        if (k == strlen(str))
        {
            count++;
            print_struct(products[i]);
        }
    }
    if (count == 0)
        return PROCESS_ERROR;
    else
        return OK;
}
