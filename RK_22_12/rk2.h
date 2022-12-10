#ifndef RK2_H
#define RK2_H
#include <stdio.h>
#include <string.h>
#define STR_LEN 256
#define YES 1
#define NO 0
#define STR_ERR 2
#define NO_FILE 3
#define NUMBER_ERROR 4

int processing(char s[]);
int read_file(char f_name[]);
int create_file(char f_name[]);

#endif // RK2_H
