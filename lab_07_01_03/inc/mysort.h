#ifndef MYSORT_H
#define MYSORT_H

#include <stdio.h>

void mysort(void *base, size_t num, size_t size, int (*compare)(const void *, const void *));
int comp_int(const void *a, const void *b);

#endif // MYSORT_H
