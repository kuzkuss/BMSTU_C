#ifndef SEARCH_FLOAT_H
#define SEARCH_FLOAT_H
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define STR_LEN 258
#define STR_ERR 1
#define OVERFLOW_STR 2
#define FALSE 0
#define TRUE 1

int search_float(char *str, int i, int flag);
int check_after_e(char *str, int i);

#endif // SEARCH_FLOAT_H
