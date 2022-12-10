#ifndef CONST_H
#define CONST_H

#include <stdio.h>
#include <string.h>
#define LEN_NAME 30
#define LEN_MANUFACTURER 15
#define FILE_ERROR 1
#define INCORRECT_DATA 2
#define READ_ERROR 3
#define PROCESS_ERROR 4
#define ERROR 53
#define OK 0

typedef struct
{
    char name[LEN_NAME + 1];
    char manufacturer[LEN_MANUFACTURER + 1];
    unsigned int price;
    unsigned int amount;
} struct_t;

#endif // CONST_H
