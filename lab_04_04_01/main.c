#include "search_float.h"

int main(void)
{
    char str[STR_LEN];
    if (!fgets(str, STR_LEN, stdin))
    {
        printf("String error.\n");
        return STR_ERR;
    }
    if (strchr(str, 0) == str + STR_LEN - 1 && str[STR_LEN - 2] != '\n')
        return OVERFLOW_STR;
    int str_len = strlen(str);
    if (str[str_len - 1] == '\n')
        str[str_len - 1] = '\0';
    int flag, i = 0;
    while (isspace(str[i]))
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (isdigit(str[i + 1]))
        {
            flag = 0;
            if (search_float(str, i + 1, flag) == TRUE)
            {
                printf("YES");
                return 0;
            }
        }
        else if (str[i + 1] == '.')
        {
            flag = 1;
            if (search_float(str, i + 1, flag) == TRUE)
            {
                printf("YES");
                return 0;
            }
        }
    }
    else if (isdigit(str[i]))
    {
        flag = 0;
        if (search_float(str, i, flag) == TRUE)
        {
            printf("YES");
            return 0;
        }
    }
    else if (str[i] == '.')
    {
        flag = 1;
        if (search_float(str, i, flag) == TRUE)
        {
            printf("YES");
            return 0;
        }
    }
    printf("NO");
    return 0;
}
