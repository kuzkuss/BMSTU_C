#include <stdio.h>
#define INPUT_ERROR 1

int scan_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        if (scanf("%d", &arr[i]) != 1)
            return INPUT_ERROR;
    return 0;
}
int search_sum_of_max_min(int *arr, int n)
{
    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
        else {
            if (arr[i] > max)
                max = arr[i];
        }
    }
    return min + max;
}

void processing_array(int *arr, int n)
{
    int sum = search_sum_of_max_min(arr, n);
    if (sum % 2 == 0)
    {
        for (int i = n; i > 0; i--)
            arr[i] = arr[i - 1];
        arr[0] = sum;
    }
    else
    {
        arr[n] = sum;
    }
}

void print_array(int *arr, int n)
{
    printf("Processed array: \n");
    for(int i = 0; i < n + 1; i++)
        printf("%d ", arr[i]);
}

int main(void)
{
    setbuf(stdout, NULL);
    int n;
    printf("Input amount of elements: \n");
    if (scanf("%d", &n) != 1)
    {
        printf("Input error.");
        return INPUT_ERROR;
    }
    if (n <= 0 || n > 10)
    {
        printf("Input error.");
        return INPUT_ERROR;
    }
    int arr[11];
    if (scan_array(arr, n) != 0)
    {
        printf("Input error.");
        return INPUT_ERROR;
    }
    processing_array(arr, n);
    print_array(arr, n);
    return 0;
}
