#ifndef SUBJECTS_H
#define SUBJECTS_H

#define EPS 1.0e-7

#include <stdio.h>

struct subject_t
{
    char *name;
    double weight;
    double volume;
};

struct subject_t *create_subject(const char *name, double weight, double volume);
int sub_copy(struct subject_t *sub_dst, const struct subject_t *sub_src);
void free_subject(struct subject_t **psubject);
int subject_read(FILE *f, struct subject_t **psub);
void print_subject(const struct subject_t *psubject);
int cmp_by_density(const void *l, const void *r);

#endif  // SUBJECTS_H
