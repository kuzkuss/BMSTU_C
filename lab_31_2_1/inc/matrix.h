#ifndef MATRIX_H
#define MATRIX_H

typedef struct Matrix
{
    int **prows;
    int *elements;
    size_t rows;
    size_t columns;
} Matrix;

int create_matrix_from_file(const char* path_file, Matrix **matrix);
void free_matrix(Matrix* matrix);
void print_matrix(const Matrix *matrix);

#endif // MATRIX_H
