#include "lab_04_03_01.h"

int split(char *str, char (*words)[LEN_WORD + 1], int *i)
{
    char *p = strtok(str, DELIMS);
    while (p != NULL)
    {
        if (strlen(p) > LEN_WORD)
            return OVERFLOW_WORD;
        strcpy(words[*i], p);
        (*i)++;
        p = strtok(NULL, DELIMS);
    }
    if (*i == 0)
        return WORDS_ERR;
    return 0;
}
