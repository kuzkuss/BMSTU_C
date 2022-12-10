#ifndef CDIO_H
#define CDIO_H

#include <stdio.h>
#define OK 0
#define FILE_ERR 1
#define INPUT_ERROR 3
#define MALLOC_FAIL 4

void delete_array(int **arr_b, int **arr_e);
int create_array(int **arr_b, int **arr_e, int n);
int input_array(FILE *f_in, int **arr_beg, int **arr_end);
int output_array(const char *filename, int *arr_beg, const int *arr_end);

#endif // CDIO_H
