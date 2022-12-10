#ifndef GROCERY_H
#define GROCERY_H

#define _GNU_SOURCE

#include <stdio.h>

typedef struct
{
    char *name;
    int amount;
    double price;
} grocery_t;

grocery_t *grocery_create(const char *name, int amount, double price);
grocery_t *grocery_read(FILE *f);
void free_grocery(grocery_t *grocery);
void print_grocery(FILE *f, grocery_t *grocery);

#endif //GROCERY_H
