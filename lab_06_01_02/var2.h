#ifndef VAR2_H
#define VAR2_H

#define FILE_ERROR 1
#define KEY_ERROR 2
#define SIZE_NAME 25
#define SIZE_ARRAY 15
#define EMPTY_FILE 3
#define INPUT_ERROR 4
#define EMPTY_STRING 5
#define ARRAY_OVERFLOW 6
#define STABLE_WORK 0

struct subjects
{
    char name[SIZE_NAME + 1];
    double weight;
    double volume;
};

int read_array(FILE *, int *, struct subjects *);
void print_array(const struct subjects *, const int *, const char *);
void sort(struct subjects *, const int *);

#endif // VAR2_H
