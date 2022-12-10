#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

#define SIZE_NAME 25
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

#endif // INPUT_OUTPUT_H
