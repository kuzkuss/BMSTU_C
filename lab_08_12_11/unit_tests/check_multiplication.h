#ifndef CHECK_MULTIPLICATION_H
#define CHECK_MULTIPLICATION_H

#include <check.h>

double **multiplication(double **mtr1, double **mtr2, int n1, int m1, int m2);
void delete_matrix(double **matrix, int n);
Suite* multiplication_suite(void);

#endif // CHECK_MULTIPLICATION_H
