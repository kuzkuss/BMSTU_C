#include <stdio.h>
#include <string.h>

#define SIZE_NAME 25

struct subjects
{
    char name[SIZE_NAME + 1];
    double weight;
    double volume;
};

void sort(struct subjects *subjects_array, const int *n)
{
    for (int i = 0; i < *n - 1; ++i)
    {
        double min = subjects_array[i].weight / subjects_array[i].volume;
        int min_ind = i;
        for (int j = i + 1; j < *n; ++j)
        {
            double cur_min = subjects_array[j].weight / subjects_array[j].volume;
            if (cur_min < min)
            {
                min_ind = j;
                min = cur_min;
            }
        }
        struct subjects temp;
        temp = subjects_array[i];
        subjects_array[i] = subjects_array[min_ind];
        subjects_array[min_ind] = temp;
    }
}

void test_sort(void)
{
    int err_cnt = 0;

    //Correct input

    struct subjects subjects_array1[] = { { "pencil", 15, 20 }, { "book", 20, 30 }, { "box", 30, 50 } };
    int n1 = 3;

    struct subjects subjects_array2[] = { { "pencil", 15, 20 } };
    int n2 = 1;

    struct subjects subjects_array3[] = { { "pencil", 15, 20 }, { "pencil", 15, 20 }, { "box", 30, 50 } };
    int n3 = 3;

    sort(subjects_array1, &n1);
    sort(subjects_array2, &n2);
    sort(subjects_array3, &n3);

    for (int i = 0; i < n1 - 1; ++i)
    {
        if (subjects_array1[i].weight / subjects_array1[i].volume >
            subjects_array1[i + 1].weight / subjects_array1[i + 1].volume)
            ++err_cnt;
    }

    for (int i = 0; i < n2 - 1; ++i)
    {
        if (subjects_array2[i].weight / subjects_array2[i].volume >
            subjects_array2[i + 1].weight / subjects_array2[i + 1].volume)
            ++err_cnt;
    }

    for (int i = 0; i < n3 - 1; ++i)
    {
        if (subjects_array3[i].weight / subjects_array3[i].volume >
            subjects_array3[i + 1].weight / subjects_array3[i + 1].volume)
            ++err_cnt;
    }

    printf("%s: %s\n", __func__, err_cnt ? "FAILED" : "OK");
}


int main(void)
{
    test_sort();

    return 0;
}


