#include <stdlib.h>
#include <string.h>
#include "subjects_array.h"
#include "subject.h"
#include "errors.h"

struct subject_t **create_array(FILE *f, int *n)
{
    if (count_elements(f, n) != OK || *n == 0)
        return NULL;

    struct subject_t **sub_arr = malloc((*n) * sizeof(struct subject_t *));
    if (!sub_arr)
        return NULL;

    return sub_arr;
}

int count_elements(FILE *f, int *n)
{
    int rc = OK;
    struct subject_t *subject = NULL;
    while (subject_read(f, &subject) == OK)
    {
        ++(*n);
        free_subject(&subject);
    }
    if (!feof(f))
        rc = INPUT_ERROR;
    return rc;
}

int read_array(FILE *f, struct subject_t **sub_arr)
{
    int i = 0;
    int rc = OK;
    rewind(f);
    while (subject_read(f, &sub_arr[i]) == OK)
        ++i;
    if (!feof(f))
        rc = INPUT_ERROR;
    return rc;
}

void free_array(struct subject_t **sub_arr, int n)
{
    for (int i = 0; i < n; ++i)
        free_subject(&sub_arr[i]);
    free(sub_arr);
}

void print_array(struct subject_t **sub_arr, const int *n, const char *prefix)
{
    if (strcmp(prefix, "ALL") == 0)
        for (int i = 0; i < *n; ++i)
            print_subject(sub_arr[i]);
    else
        for (int i = 0; i < *n; ++i)
            if (strstr(sub_arr[i]->name, prefix) == sub_arr[i]->name)
                print_subject(sub_arr[i]);
}

int sort(struct subject_t **subjects_array, int n, int (*compare)(const void*, const void*))
{
    for (int i = 0; i < n - 1; ++i)
    {
        int min_ind = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (compare(subjects_array[j], subjects_array[min_ind]) < 0)
                min_ind = j;
        }
        struct subject_t *temp = create_subject(subjects_array[i]->name,
        subjects_array[i]->weight, subjects_array[i]->volume);
        if (!temp)
            return ALLOCATE_ERROR;

        sub_copy(subjects_array[i], subjects_array[min_ind]);
        sub_copy(subjects_array[min_ind], temp);

        free_subject(&temp);
    }
    return OK;
}

