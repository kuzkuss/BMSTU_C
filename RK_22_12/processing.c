#include "rk2.h"

int processing(char s[])
{
    int i = 0;
    int len = 0;
    len = strlen(s);
    if ((s[0] < 'A') || (s[0] > 'Z'))
        return NO;
    else
    {
        if ((s[len - 2] != '.') && (s[len - 2] != '!') && (s[len - 2] != '?'))
            return NO;
        else
            for (i = 0; i < len - 1; i++)
                if ((s[i] == ' ') && (s[i + 1] == ' '))
                    return NO;
    }
    return YES;
}

int read_file(char f_name[])
{
	printf("Result:\n");
    FILE *f = fopen(f_name, "rb");
    char s[STR_LEN + 1];
    while (fread(s, sizeof(s), 1, f))
    {
        printf("%s - ", s);
        if (processing(s) == NO)
            printf("NO\n");
        else
            printf("YES\n");
    }
    fclose(f);
    return 0;
}