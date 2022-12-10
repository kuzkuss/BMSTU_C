#ifndef CHECK_MY_SNPRINTF_H
#define CHECK_MY_SNPRINTF_H

#include <check.h>

int my_snprintf(char *restrict s, size_t n, const char *restrict format, ...);
Suite* my_snprintf_suite(void);

#endif // CHECK_MY_SNPRINTF_H
