#ifndef SORT_H
#define SORT_H

#define SIZE_NAME 25

struct subjects
{
    char name[SIZE_NAME + 1];
    double weight;
    double volume;
};

void sort(struct subjects *, const int *);

#endif // SORT_H
