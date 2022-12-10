#ifndef CHECK_SUBJECT_H
#define CHECK_SUBJECT_H

#include <stdio.h>
#include <check.h>

#define EPS 1.0e-7

#define INPUT_ERROR 3
#define EMPTY_STRING 4
#define OK 0

struct subject_t
{
    char *name;
    double weight;
    double volume;
};

void free_subject(struct subject_t **psubject);
int subject_read(FILE *f, struct subject_t **psub);
int cmp_by_density(const void *l_sub, const void *r_sub);
int sub_copy(struct subject_t *sub_dst, const struct subject_t *sub_src);
Suite* subject_read_suite(void);
Suite* cmp_by_density_suite(void);
Suite* sub_copy_suite(void);

#endif //CHECK_SUBJECT_H
