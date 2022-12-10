#include "lab_04_03_01.h"

void form_newstr(char (*words)[LEN_WORD + 1], int *n_words, char *new_str)
{
    for (int i = *n_words - 2; i > 0; i--)
        if (strcmp(words[i], words[*n_words - 1]) != 0)
        {
            processing_word(words[i]);
            strcat(new_str, words[i]);
            strcat(new_str, " ");
        }
    if (strcmp(words[0], words[*n_words - 1]) != 0)
    {
        processing_word(words[0]);
        strcat(new_str, words[0]);
    }
}
