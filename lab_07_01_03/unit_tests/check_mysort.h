#ifndef CHECK_MYSORT_H
#define CHECK_MYSORT_H
#include <check.h>
#include <stdio.h>

void mysort(void *base, size_t num, size_t size, int (*compare)(const void *, const void *));
int comp_int(const void *a, const void *b);

int comp_double(const void *a, const void *b);
int comp_char(const void *a, const void *b);
Suite* mysort_suite(void);

#endif //CHECK_MYSORT_H
