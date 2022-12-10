#include <stdio.h>
#include <string.h>
#include "sort.h"

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

