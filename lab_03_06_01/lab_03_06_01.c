#include <stdio.h>
#define INPUT_ERROR 1

void formation_matrix(int (*matrix)[10], int n)
{
    int num = 1;
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = i; j < n - i; j++)
        {
            matrix[i][j] = num;
            num++;
        }
        for (int j = i + 1; j < n - i; j++)
        {
            matrix[j][n - i - 1] = num;
            num++;
        }
        for (int j = n - i - 2; j >= i; j--)
        {
            matrix[n - 1 - i][j] = num;
            num++;
        }
        for (int j = n - i - 2; j >= i + 1; j--)
        {
            matrix[j][i] = num;
            num++;
        }
    }
    if (n % 2 == 1)
    {
        int k = n / 2;
        matrix[k][k] = n * n;
    }
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
    formation_matrix(matrix, row);
    print_matrix(matrix, row, col);
    return 0;
}
