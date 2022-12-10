#include <stdio.h>
#include <stdlib.h>
#define INPUT_ERROR 1
#define SUM_DIGITS_ERROR 2

int sum_digits(int number)
{
    int sum = 0;
    while (number > 0)
    {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

void shift_array(int *array, int len)
{
    for (int j = 0; j < 3; j++)
    {
        int cur_el = array[0];
        for (int i = 0; i < len - 1; i++)
            array[i] = array[i + 1];
        array[len - 1] = cur_el;
    }
}

int processing_matrix(int (*matrix)[10], int row, int col, int *array)
{
    int k = 0;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (sum_digits(abs(matrix[i][j])) > 10)
            {
                array[k] = matrix[i][j];
                k++;
            }
    if (k == 0)
        return SUM_DIGITS_ERROR;
    shift_array(array, k);
    return 0;
}

void new_matrix(int (*matrix)[10], int row, int col, int *array)
{
    int k = 0;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (sum_digits(abs(matrix[i][j])) > 10)
            {
                matrix[i][j] = array[k];
                k++;
            }
}

int scan_matrix(int (*matrix)[10], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (scanf("%d", &matrix[i][j]) != 1)
                return INPUT_ERROR;
        }
    }
    return 0;
}

void print_matrix(int (*matrix)[10], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

int main(void)
{
    int row, col;
    if (scanf("%d%d", &row, &col) != 2)
    {
        printf("Input error.\n");
        return INPUT_ERROR;
    }
    if (row <= 0 || row > 10 || col <= 0 || col > 10)
    {
        printf("Input error.\n");
        return INPUT_ERROR;
    }
    int matrix[10][10];
    if (scan_matrix(matrix, row, col))
    {
        printf("Input error.");
        return INPUT_ERROR;
    }
    int array[100];
    if (processing_matrix(matrix, row, col, array))
    {
        printf("Sum of digits of all elements is less than 10.");
        return SUM_DIGITS_ERROR;
    }
    new_matrix(matrix, row, col, array);
    print_matrix(matrix, row, col);
    return 0;
}
