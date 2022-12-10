#include <stdio.h>
#define INPUT_ERROR 1

void processing_matrix(int (*matrix)[10], int row, int col)
{
    int flag = 0, av;
    for (int i = 0; i < row / 2; i++)
    {
        for (int j = flag; j < col - flag; j++)
        {
            av = matrix[i][j];
            matrix[i][j] = matrix[row - 1 - i][j];
            matrix[row - 1 - i][j] = av;
        }
        flag++;
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
    if (row <= 0 || row > 10 || col <= 0 || col > 10 || row != col)
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
    processing_matrix(matrix, row, col);
    print_matrix(matrix, row, col);
    return 0;
}
