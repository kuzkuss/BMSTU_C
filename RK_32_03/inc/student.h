#ifndef STUDENT_H
#define STUDENT_H

#define SIZE_SURNAME 30
#define SIZE_GROUP 10
#define SIZE_ARR 2

#include <stdio.h>

typedef struct
{
    char **info;
    int year;
} student_t;

student_t *student_create(char *surname, int year, char *group);
student_t *student_read(FILE *f, int *rc);
void free_student(student_t *student);
void print_student(student_t *student);
void print_student_to_file(FILE *f, student_t *student);

#endif // STUDENT_H
