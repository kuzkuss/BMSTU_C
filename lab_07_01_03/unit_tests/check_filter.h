#ifndef CHECK_FILTER_H
#define CHECK_FILTER_H
#include <check.h>

#define OK 0
#define MALLOC_FAIL 4
#define INCORRECT_DATA 5
#define EMPTY_ARRAY 7

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);
Suite* key_suite(void);

#endif //CHECK_FILTER_H
