#include "student.h"
#include "errors.h"
#include <stdlib.h>
#include <string.h>

student_t *student_create(char *surname, int year, char *group)
{
    student_t *student = malloc(sizeof(student_t));
    if (student)
    {
        student->info = calloc(SIZE_ARR, sizeof(double *));
        if (!student->info)
        {
            free(student);
            return NULL;
        }
        student->info[0] = strdup(surname);
        if (!student->info[0])
        {
            free(student);
            free(student->info);
            return NULL;
        }
        student->info[1] = strdup(group);
        if (!student->info[1])
        {
            free(student);
            free(student->info);
            free(student->info[0]);
            return NULL;
        }
        student->year = year;
    }
    return student;
}

student_t *student_read(FILE *f, int *rc)
{
    char surname[SIZE_SURNAME + 2];
    char group[SIZE_GROUP + 2];
    int year = 0;

    if (!fgets(surname, SIZE_SURNAME + 2, f))
    {
        if (ftell(f) == 0)
            *rc = EMPTY_FILE;
        else
            *rc = INPUT_ERROR;
        return NULL;
    }

    size_t len = strlen(surname);
    if (surname[len - 1] == '\n')
    {
        surname[len - 1] = '\0';
        --len;
    }

    if (len == 0)
    {
        *rc = EMPTY_STRING;
        return NULL;
    }

    else if (len > SIZE_SURNAME)
    {
        *rc = OVERFLOW_STR;
        return NULL;
    }

    if (fscanf(f, "%d", &year) != 1 || year <= 0)
    {
        *rc = INPUT_ERROR;
        return NULL;
    }

    fgetc(f);

    if (!fgets(group, SIZE_GROUP + 2, f))
    {
        *rc = INPUT_ERROR;
        return NULL;
    }

    len = strlen(group);
    if (group[len - 1] == '\n')
    {
        group[len - 1] = '\0';
        --len;
    }

    if (len == 0)
    {
        *rc = EMPTY_STRING;
        return NULL;
    }

    else if (len > SIZE_GROUP)
    {
        *rc = OVERFLOW_STR;
        return NULL;
    }

    student_t *student = student_create(surname, year, group);
    return student;
}

void free_student(student_t *student)
{
    free(student->info[0]);
    free(student->info[1]);
    free(student->info);
    free(student);
}

void print_student(student_t *student)
{
    printf("%s\n%d\n%s\n", student->info[0], student->year, student->info[1]);
}

void print_student_to_file(FILE *f, student_t *student)
{
    fprintf(f, "%s\n%d\n%s\n", student->info[0], student->year, student->info[1]);
}

