#include <stdio.h>
#include <string.h>
#include "lab_04_01.h"

int main(void)
{
    setbuf(stdout, NULL);
    const char *str1[6];
    const char *str2[6];
    puts("strspn:");
    //Поиск длины части строки 1, состоящей из символов строки 2

    //В строке 2 нет символов из строки 1
    str1[0] = "Hello, world!";
    str2[0] = "abc";

    //В строке 2 есть несколько символов из строки 1, первого символа нет
    str1[1] = "Hello, world!";
    str2[1] = "wd";

    //В строке 2 есть несколько символов из строки 1, первый символ есть
    str1[2] = "Hello, world!";
    str2[2] = "elH";

    //В строке 2 есть все символы строки 1
    str1[3] = "Hello, world!";
    str2[3] = "Helo, wrd!";

    //Строка 1 пустая
    str1[4] = "";
    str2[4] = "Helo, wrd!";

    //Строка 2 пустая
    str1[5] = "Hello, world!";
    str2[5] = "";

    for (int i = 0; i < 6; i++)
    {
        printf("String 1 = %s\n", str1[i]);
        printf("String 2 = %s\n", str2[i]);
        printf("Result of function my_strspn: %zu\n", my_strspn(str1[i], str2[i]));
        printf("Result of function strspn: %zu\n", strspn(str1[i], str2[i]));
    }

    puts("\nstrrchr:");
    //Поиск последнего вхождения символа в строку
    const char *str3[5];
    int ch[6];

    //В строке нет заданного символа
    str3[0] = "0128976";
    ch[0] = '5';

    //В строке символ встречается 1 раз
    str3[1] = "0128976";
    ch[1] = '1';

    //В строке символ встречается несколько раз
    str3[2] = "01a28a97a6";
    ch[2] = 'a';

    //В строке символ стоит на последнем месте
    str3[3] = "0128975";
    ch[3] = '5';

    //Строка пустая
    str3[4] = "";
    ch[4] = '5';

    for (int i = 0; i < 5; i++)
    {
        printf("String = %s\n", str3[i]);
        printf("Character = %c\n", ch[i]);
        printf("Result of function my_strrchr: %s\n", my_strrchr(str3[i], ch[i]));
        printf("Result of function strrchr: %s\n", strrchr(str3[i], ch[i]));
    }

    return 0;
}
