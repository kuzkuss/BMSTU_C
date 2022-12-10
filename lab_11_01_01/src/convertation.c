#include <limits.h>

static char hex_translate_digit(unsigned short num);
static void hex_translate_num(unsigned short num, char *dst, int *i);

static char hex_translate_digit(unsigned short num)
{
    char digit = num % 16;
    if (digit >= 10)
    {
        digit = 'a' + digit % 10;
    }
    else
        digit += '0';
    return digit;
}

static void hex_translate_num(unsigned short num, char *dst, int *i)
{
    if (num >= 16)
    {
        hex_translate_num(num / 16, dst, i);
    }
    dst[(*i)++] = hex_translate_digit(num);
}

void convertation(unsigned short num, char *hex_num)
{
    int i = 0;
    hex_translate_num(num, hex_num, &i);
}
