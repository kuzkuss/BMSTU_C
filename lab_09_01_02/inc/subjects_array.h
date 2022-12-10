#ifndef SUBJECTS_ARRAY_H
#define SUBJECTS_ARRAY_H

#include <stdio.h>

struct subject_t **create_array(FILE *f, int *n);
int count_elements(FILE *f, int *n);
int read_array(FILE *f, struct subject_t **sub_arr);
void free_array(struct subject_t **sub_arr, int n);
void print_array(struct subject_t **sub_arr, const int *n, const char *prefix);
int sort(struct subject_t **subjects_array, int n, int (*compare)(const void*, const void*));

#endif  // SUBJECTS_ARRAY_H
