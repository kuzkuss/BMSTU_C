#include <stdio.h>
#define INPUT_ERROR 1

int array_symmetry(int *array, int col)
{
    int count = 0;
    for (int j = 0; j < col / 2; j++)
    {
        if (array[j] == array[col - j - 1])
            count += 1;
    }
    if (count == col / 2)
        return 0;
    return 1;
}

int processing_array(int (*matrix)[10], int row, int col, int *new_arr)
{
    for (int i = 0; i < row; i++)
    {
        if (array_symmetry(matrix[i], col) == 0)
            new_arr[i] = 1;
        else
            new_arr[i] = 0;
    }
    return 0;
}

int scan_array(int (*matrix)[10], int row, int col)
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

void print_array(int *new_arr, int row)
{
    for (int i = 0; i < row; i++)
        printf("%d ", new_arr[i]);
}

int main(void)
{
    int row, col;
    if (scanf("%d %d", &row, &col) != 2)
    {
        printf("Input error.");
        return INPUT_ERROR;
    }
    if (row <= 0 || row > 10 || col <= 0 || col > 10)
    {
        printf("Input error.");
        return INPUT_ERROR;
    }
    int matrix[10][10];
    if (scan_array(matrix, row, col) != 0)
    {
        printf("Input error.");
        return INPUT_ERROR;
    }
    int new_arr[10];
    processing_array(matrix, row, col, new_arr);
    print_array(new_arr, row);
    return 0;
}
