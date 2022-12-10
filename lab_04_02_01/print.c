#include "lab_04_02_01.h"

void print_words(char (*words)[LEN_WORD + 1], int *n_words)
{
    for (int i = 0; i < *n_words - 1; i++)
        printf("%s ", words[i]);
    printf("%s", words[*n_words - 1]);
}