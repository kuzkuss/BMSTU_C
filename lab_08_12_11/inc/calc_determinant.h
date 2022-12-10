#ifndef CALC_DETERMINANT_H
#define CALC_DETERMINANT_H

double calc_determinant(double **matrix, int n, int *rc);
void fill_new_matrix(double **matrix, double **new_matrix, int n, int del_col);

#endif // CALC_DETERMINANT_H
