#include "grocery.h"
#include <stdlib.h>
#include <string.h>

grocery_t *grocery_create(const char *name, int amount, double price)
{
    grocery_t *grocery = malloc(sizeof(grocery_t));
    if (grocery)
    {
        grocery->name = strdup(name);
        if (!grocery->name)
        {
            free(grocery);
            return NULL;
        }
        grocery->amount = amount;
        grocery->price = price;
    }
    return grocery;
}

grocery_t *grocery_read(FILE *f)
{
    char *name = NULL;
    int amount = 0;
    double price = 0.0;
    size_t n = 0;
    int rc = getline(&name, &n, f);
    if (rc > 0)
    {
        while (name[rc - 1] == '\r' || name[rc - 1] == '\n')
        {
            name[rc - 1] = '\0';
            if (--rc == 0)
                break;
        }
        if (rc > 0 && fscanf(f, "%d\n", &amount) == 1 && amount > 0)
            if (fscanf(f, "%lf\n", &price) == 1 && price > 0)
            {
                grocery_t *grocery = grocery_create(name, amount, price);
                free(name);
                return grocery;
            }
    }
    free(name);
    return NULL;
}

void free_grocery(grocery_t *grocery)
{
    free(grocery->name);
    free(grocery);
}

void print_grocery(FILE *f, grocery_t *grocery)
{
    fprintf(f, "%s\n%d\n%lf\n", grocery->name, grocery->amount, grocery->price);
}

