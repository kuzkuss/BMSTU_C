#ifndef FILTER_H
#define FILTER_H

#define OK 0
#define MALLOC_FAIL 4
#define INCORRECT_DATA 5
#define EMPTY_ARRAY 7

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);

#endif // FILTER_H
