#include "lab_04_02_01.h"

int split(char *s, char (*words)[LEN_WORD + 1], int *k)
{
    int n = strlen(s);
    int i, flag, y, len_word, z, q;
    for (i = 0; i < n; i++)
    {
        if (strchr(DELIMS, s[i]))
        {
            s[i] = '\0';
            if (s[i - 1] != '\0' && flag == 0)
            {
                q = i - 1;
                while (s[q] != '\0' && q != -1)
                    q--;
                z = i - q - 1;
                words[*k - 1][z] = '\0';
                if (strlen(words[*k - 1]) > LEN_WORD)
                    return OVERFLOW_WORD;
            }
        }
        else if (i == 0 || s[i - 1] == '\0')
        {
            flag = 0;
            for (int j = 0; j < *k; j++)
            {
                y = 0;
                len_word = strlen(words[j]);
                while ((s + i)[y] == words[j][y] && y < len_word)
                    y++;
                if (y == len_word && strchr(DELIMS, (s + i)[y]))
                    flag = 1;
            }
            if (flag == 0)
                strcpy(words[(*k)++], s + i);
        }
    }
    if (*k == 0)
        return WORDS_ERR;
    if (strlen(words[*k - 1]) > LEN_WORD)
        return OVERFLOW_WORD;
    return 0;
}