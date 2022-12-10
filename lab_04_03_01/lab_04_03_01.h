#ifndef LAB_04_03_01_H
#define LAB_04_03_01_H
#include <stdio.h>
#include <string.h>
#define STR_LEN 256
#define LEN_WORD 16
#define DELIMS " ,.!?;:-"
#define EMPTY_LINE 1
#define OVERFLOW_STR 2
#define OVERFLOW_WORD 3
#define STR_ERROR 4
#define WORDS_ERR 5
#define EMPTY_NEW_STR 6

void processing_word(char *word);
void form_newstr(char (*words)[LEN_WORD + 1], int *n_words, char *new_str);
int split(char *s, char (*words)[LEN_WORD + 1], int *k);

#endif // LAB_04_03_01_H
