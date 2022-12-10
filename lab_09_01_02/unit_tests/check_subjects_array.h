#ifndef CHECK_SUBJECTS_ARRAY_H
#define CHECK_SUBJECTS_ARRAY_H

#include <stdio.h>
#include <check.h>

#define EPS 1.0e-7

struct subject_t **create_array(FILE *f, int *n);
int count_elements(FILE *f, int *n);
int sort(struct subject_t **subjects_array, int n, int (*compare) (const void*, const void*));
int cmp_by_density(const void *l_sub, const void *r_sub);
Suite* create_array_suite(void);
Suite* sort_suite(void);

#endif //CHECK_SUBJECTS_ARRAY_H
