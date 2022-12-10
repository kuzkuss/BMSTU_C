#ifndef LAB_04_02_01_H
#define LAB_04_02_01_H
#include <stdio.h>
#include <string.h>
#define STR_LEN 258
#define LEN_WORD 16
#define DELIMS " ,.!?;:-"
#define EMPTY_LINE 1
#define OVERFLOW_STR 2
#define OVERFLOW_WORD 3
#define STR_ERROR 4
#define WORDS_ERR 5

void print_words(char (*words)[LEN_WORD + 1], int *n_words);
void sorting(char (*words)[LEN_WORD + 1], int *n_words);
int split(char *s, char (*words)[LEN_WORD + 1], int *k);


#endif // LAB_04_02_01_H
