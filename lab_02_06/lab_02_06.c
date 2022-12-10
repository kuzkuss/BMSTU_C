#include <stdio.h>
#include <inttypes.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#define INPUT_ERROR 1

int process_1(int *array, int n)
{
    int min = array[0] * array[1];
    for (int i = 1; i < n - 1; i++)
    {
        if (array[i] * array[i + 1] < min)
            min = array[i] * array[i + 1];
    }
    return min;
}

int process_2(int *array, int n)
{
    int min = *array * *(array + 1);
    for (int i = 1; i < n - 1; i++)
    {
        if (*(array + i) * *(array + i + 1) < min)
            min = *(array + i) * *(array + i + 1);
    }
    return min;
}

int process_3(const int *pb, int *pe)
{
    int min = *pb * *(pb + 1);
    for (const int *pa = pb + 1; pa < pe - 1; pa++)
    {
        if (*pa * *(pa + 1) < min)
            min = *pa * *(pa + 1);
    }
    return min;
}

void forming_array(int *pb, int *pe)
{
    srand(time(NULL));
    for (int *pa = pb; pa < pe; pa++)
        *pa = rand() % 100;
}

void array_copy(int *b, int *a, int n)
{
    for (int i = 0; i < n; i++)
        b[i] = a[i];
}

void time_function(int *b, int nb, int repeats)
{
    int sum = 0;
    for (int i = 1; i < repeats; i++)
    {
        struct timeval tv_start, tv_stop;
        int64_t elapsed_time;
        gettimeofday(&tv_start, NULL);
        process_1(b, nb);
        gettimeofday(&tv_stop, NULL);
        elapsed_time = (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +
                (tv_stop.tv_usec - tv_start.tv_usec);
        sum += elapsed_time;
        // время в микросекундах
        //printf("%" PRId64 " us\n", elapsed_time);
    }
    float time = sum / nb;
    printf("%f\n", time);

    sum = 0;
    for (int i = 1; i < repeats; i++)
    {
        struct timeval tv_start, tv_stop;
        int64_t elapsed_time;
        gettimeofday(&tv_start, NULL);
        process_2(b, nb);
        gettimeofday(&tv_stop, NULL);
        elapsed_time = (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +
                (tv_stop.tv_usec - tv_start.tv_usec);
        sum += elapsed_time;
        // время в микросекундах
        //printf("%" PRId64 " us\n", elapsed_time);
    }
    time = sum / nb;
    printf("%f\n", time);

    sum = 0;
    for (int i = 1; i < repeats; i++)
    {
        struct timeval tv_start, tv_stop;
        int64_t elapsed_time;
        gettimeofday(&tv_start, NULL);
        process_3(b, b + nb);
        gettimeofday(&tv_stop, NULL);
        elapsed_time = (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +
                (tv_stop.tv_usec - tv_start.tv_usec);
        sum += elapsed_time;
        // время в микросекундах
        //printf("%" PRId64 " us\n", elapsed_time);
    }
    time = sum / nb;
    printf("%f\n", time);
}

int main(void)
{
    setbuf(stdout, NULL);
    int na, repeats;
    printf("Введите размер массива: \n");
    if (scanf("%d", &na) != 1)
    {
        printf("Input error.\n");
        return INPUT_ERROR;
    }
    printf("Введите количество повторов: \n");

    if (scanf("%d", &repeats) != 1)
    {
        printf("Input error.\n");
        return INPUT_ERROR;
    }

    int a[na];

    forming_array(a, a + na);

    const int nb = na;
    int b[nb];

    array_copy(b, a, na);

    time_function(b, nb, repeats);

    return 0;
}
