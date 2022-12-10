#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#define FILE_ERROR 2
#define WROTE_ERROR 3
#define ERROR 5
#define SIZE_ERROR 6
#define READ_ERROR 7
#define KEY_ERROR 8
#define OK 0

int put_number_by_pos(int pos, int num, FILE *f);
int get_number_by_pos(int pos, int *num, FILE *f);
int sort(char *file_name);

#endif // SORT_H

