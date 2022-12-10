#include <stdio.h>
#include <string.h>
#include "input_output.h"

int read_array(FILE *f_in, int *amount, struct subjects *subjects_array)
{
    while (!feof(f_in))
    {
        if (*amount >= 15)
            return ARRAY_OVERFLOW;
        if (!fgets(subjects_array[*amount].name, SIZE_NAME + 1, f_in))
            return INPUT_ERROR;
        size_t len = strlen(subjects_array[*amount].name);
        if (subjects_array[*amount].name[len - 1] == '\n')
        {
            subjects_array[*amount].name[len - 1] = '\0';
            --len;
        }
        if (len == 0)
            return EMPTY_STRING;
        if (fscanf(f_in, "%lf", &subjects_array[*amount].weight) != 1 || subjects_array[*amount].weight <= 0)
            return INPUT_ERROR;
        if (fscanf(f_in, "%lf", &subjects_array[*amount].volume) != 1 || subjects_array[*amount].volume <= 0)
            return INPUT_ERROR;
        ++(*amount);
        if (fgetc(f_in) == EOF)
            break;
    }
    return STABLE_WORK;
}

void print_array(const struct subjects *subjects_array, const int *n, const char *prefix)
{
    if (strcmp(prefix, "ALL") == 0)
        for (int i = 0; i < *n; ++i)
        {
            printf("%s\n", subjects_array[i].name);
            printf("%lf\n", subjects_array[i].weight);
            printf("%lf\n", subjects_array[i].volume);
        }
    else
        for (int i = 0; i < *n; ++i)
            if (strstr(subjects_array[i].name, prefix) == subjects_array[i].name)
            {
                printf("%s\n", subjects_array[i].name);
                printf("%lf\n", subjects_array[i].weight);
                printf("%lf\n", subjects_array[i].volume);
            }
}

