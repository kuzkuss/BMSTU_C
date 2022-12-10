#include "lab_04_03_01.h"

void processing_word(char *word)
{
    int len = strlen(word), i, j, k;
    for (i = 0; i < len; i++)
        for (j = 0; j < i; j++)
            if (word[i] == word[j])
            {
                for (k = i; k < len; k++)
                    word[k] = word[k + 1];
                len--;
                i--;
            }
}
