#include <stdio.h>
#define INPUT_ERROR 1

void processing_number(int n, int *arr)
{
    while (n > 0)
    {
        arr[n % 10] += 1;
        n /= 10;
    }
}

void print_function(int *arr)
{
    for(int i = 0; i < 10; i++)
        if (arr[i] != 0)
            printf("Digit %d: %d times\n", i, arr[i]);
}

int main(void)
{
    setbuf(stdout, NULL);
    int n;
    printf("Input number: \n");
    if (scanf("%d", &n) != 1)
    {
        printf("Input error.");
        return INPUT_ERROR;
    }
    if (n <= 0)
    {
        printf("Input error.");
        return INPUT_ERROR;
    }
    int arr[10] = {0};
    processing_number(n, arr);
    print_function(arr);

    return 0;
}
