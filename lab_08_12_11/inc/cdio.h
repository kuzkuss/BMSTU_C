#ifndef CDIO_H
#define CDIO_H
#include <stdio.h>

double **create_matrix(int rows, int columns);
void delete_matrix(double **matrix, int n);
int read_dimension(FILE *f, int *n, int *m);
double **input_matrix(char *filename, int *n, int *m, int *rc);
int output_matrix(char *filename, double **matrix, int n, int m);

#endif // CDIO_H
