#ifndef CHECK_PROCESS_ARRAY_H
#define CHECK_PROCESS_ARRAY_H

#include <check.h>
#include <stdio.h>

#define OK 0
#define MALLOC_FAIL 4
#define INCORRECT_DATA 5
#define EMPTY_ARRAY 7
#define OVERFLOW_ARRAY 8

void mysort(void *base, size_t num, size_t size, int (*compare)(const void *, const void *));
int comp_int(const void *a, const void *b);

int comp_double(const void *a, const void *b);
int comp_char(const void *a, const void *b);
Suite* mysort_suite(void);

int key(const int *pb_src, const int *pe_src, int *pb_dst, int *pe_dst, int *dst_len);
Suite* key_suite(void);

int create_array(int **arr_b, int **arr_e, int n);

#endif // CHECK_PROCESS_ARRAY_H
