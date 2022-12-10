#ifndef INPUT_OUTPUT_STAT_H
#define INPUT_OUTPUT_STAT_H

#include <stdio.h>

int input_array(FILE *f_in, int **arr_beg, int **arr_end);
int output_array(const char *filename, int *arr_beg, const int *arr_end);

#endif // INPUT_OUTPUT_STAT_H
