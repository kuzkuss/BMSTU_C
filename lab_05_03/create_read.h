#ifndef CREATE_READ_H
#define CREATE_READ_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define INCORRECT_ARG 1
#define FILE_ERROR 2
#define WROTE_ERROR 3
#define AMOUNT_ERR 4
#define ERROR 5
#define SIZE_ERROR 6
#define OK 0

int file_size(FILE *f, size_t *size);
int create_file(char *file_name, int num_el);
int print_data(char *file_name);

#endif // CREATE_READ_H
