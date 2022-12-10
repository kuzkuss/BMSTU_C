#include <stdarg.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

#include "convertation.h"

#define LEN_HEX_NUM 5

int my_snprintf(char *restrict s, size_t n, const char *restrict format, ...)
{
    va_list vl;
    va_start(vl, format);

    int i = 0;
    for (; *format; format++)
    {
        if (i == (int) n - 1)
            s[i] = '\0';

        if (*format == '%')
        {
            format++;
            if (*format == 's')
            {
                char *str = va_arg(vl, char *);
                for (; *str; str++, i++)
                {
                    if (i < (int) n - 1)
                        s[i] = *str;
                    else if (i == (int) n - 1)
                        s[i] = '\0';
                }
            }
            else if (*format == 'h' && *(format + 1) && *(format + 1) == 'x')
            {
                format++;
                int int_number = va_arg(vl, int);
                char hex_number[LEN_HEX_NUM] = { 0 };
                convertation(int_number, hex_number);
                for (int j = 0; hex_number[j]; j++, i++)
                {
                    if (i < (int) n - 1)
                        s[i] = hex_number[j];
                    else if (i == (int) n - 1)
                        s[i] = '\0';
                }
            }
        }
        else if (i < (int) n - 1)
        {
            s[i] = *format;
            i++;
        }
        else
            i++;
    }
    if (i <= (int) n - 1)
        s[i] = '\0';
    va_end(vl);
    return i;
}
