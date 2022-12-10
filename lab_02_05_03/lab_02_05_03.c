#include <stdio.h>
#define INPUT_ERROR 1
#define NUMBER_OF_ELEMENTS_ERROR 2
#define ONE_NUMBER_ERROR 3

int scan_array(int *pb, int *pe)
{
    char tmp;
    for (int *pa = pb; pa < pe; pa++)
    {
        if (scanf("%d", pa) != 1)
        {
            printf("Input error.\n");
            return INPUT_ERROR;
        }
    }
    if (scanf("%c", &tmp) != EOF)
    {
        printf("Number of array elements exceeded.\n");
        return INPUT_ERROR;
    }
    return 0;
}

int processing_array(const int *pb, int *pe)
{
    int min = *pb * *(pb + 1);
    for (const int *pa = pb; pa < pe - 1; pa++)
    {
        if (*pa * *(pa + 1) < min)
            min = *pa * *(pa + 1);
    }
    return min;
}

int main(void)
{
    int array[10], n;
    if (scanf("%d", &n) != 1)
    {
        printf("Input error.\n");
        return INPUT_ERROR;
    }
    if (n <= 0 || n > 10)
    {
        printf("Incorrect entry of the number of elements.\n");
        return NUMBER_OF_ELEMENTS_ERROR;
    }
    if (n == 1)
    {
        printf("Only one number is entered.\n");
        return ONE_NUMBER_ERROR;
    }
    if (scan_array(array, array + n) != 0)
        return INPUT_ERROR;

    printf("%d", processing_array(array, array + n));
    return 0;
}
