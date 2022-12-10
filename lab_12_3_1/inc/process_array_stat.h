#ifndef PROCESS_ARRAY_STAT_H
#define PROCESS_ARRAY_STAT_H

#include <stddef.h>

int key(const int *pb_src, const int *pe_src, int *pb_dst, int *pe_dst, int *dst_len);
void mysort(void *base, size_t num, size_t size, int (*compare)(const void *, const void *));
int comp_int(const void *a, const void *b);

#endif // PROCESS_ARRAY_STAT_H
