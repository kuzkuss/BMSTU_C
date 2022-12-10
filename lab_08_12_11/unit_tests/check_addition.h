#ifndef CHECK_ADDITION_H
#define CHECK_ADDITION_H
#include <check.h>

double **addition(double **mtr1, double **mtr2, int n, int m);
void delete_matrix(double **matrix, int n);
Suite* addition_suite(void);

#endif // CHECK_ADDITION_H
