#include <stdio.h>
#ifndef LAB_04_01_H
#define LAB_04_01_H

char *my_strrchr(const char *str, int ch)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    while (i != 0 && str[i] != ch)
        i--;
    return (str[i] == ch) ? (char *) str + i : NULL;
}

#endif
