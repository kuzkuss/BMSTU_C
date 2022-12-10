#ifndef CHECK_GROCERY_H
#define CHECK_GROCERY_H

#include <check.h>
#include <stdio.h>

#define EPS 1.0e-7

typedef struct
{
    char *name;
    int amount;
    double price;
} grocery_t;

grocery_t *grocery_read(FILE *f);
void free_grocery(grocery_t *grocery);

Suite *grocery_read_suite(void);

#endif // CHECK_GROCERY_H
