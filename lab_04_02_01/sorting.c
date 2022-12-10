#include "lab_04_02_01.h"

void sorting(char (*words)[LEN_WORD + 1], int *n_words)
{
    char cur[LEN_WORD + 1];
    for (int i = 0; i < *n_words - 1; i++)
        for (int j = 0; j < *n_words - 1 - i; j++)
            if (strcmp(words[j], words[j + 1]) > 0)
            {
                strcpy(cur, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], cur);
            }
}
