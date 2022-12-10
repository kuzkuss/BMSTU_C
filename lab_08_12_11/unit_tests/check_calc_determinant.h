#ifndef CHECK_CALC_DETERMINANT_H
#define CHECK_CALC_DETERMINANT_H

#include <check.h>

double calc_determinant(double **matrix, int n, int *rc);
void fill_new_matrix(double **matrix, double **new_matrix, int n, int del_col);
Suite* calc_determinant_suite(void);

#endif // CHECK_CALC_DETERMINANT_H
