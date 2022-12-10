#include "search_float.h"

int check_after_e(char *str, int i)
{
    i++;
    if (str[i] == '+' || str[i] == '-')
    {
        i++;
        if (isdigit(str[i]))
        {
            while (isdigit(str[i]))
                i++;
            if (isspace(str[i]) || str[i] == '\0')
            {
                while (isspace(str[i]))
                    i++;
                if (str[i] == '\0')
                    return TRUE;
                else
                    return FALSE;
            }
        }
        else
            return FALSE;
    }
    else if (isdigit(str[i]))
    {
        while (isdigit(str[i]))
            i++;
        if (isspace(str[i]) || str[i] == '\0')
        {
            while (isspace(str[i]))
                i++;
            if (str[i] == '\0')
                return TRUE;
            else
                return FALSE;
        }
    }
    return FALSE;
}
