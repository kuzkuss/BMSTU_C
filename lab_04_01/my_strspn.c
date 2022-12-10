#include <stdio.h>
#ifndef LAB_04_01_H
#define LAB_04_01_H

size_t my_strspn(const char *str1, const char *str2)
{
    size_t i;
    for (i = 0; str1[i] != '\0'; i++)
    {
        int flag = 0;
        for (int j = 0; str2[j] != '\0'; j++)
            if (str1[i] == str2[j])
                flag = 1;
        if (flag == 0)
            return i;
    }
    return i;
}

#endif
