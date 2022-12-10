#include "search_float.h"

int search_float(char *str, int i, int flag)
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
    else if (str[i] == '.')
    {
        i++;
        if (isdigit(str[i]) && flag == 1)
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
            else if ((str[i] == 'e' || str[i] == 'E'))
            {
                if (check_after_e(str, i) == TRUE)
                    return TRUE;
                else
                    return FALSE;
            }
            else
                return FALSE;
        }
        if ((isspace(str[i]) || str[i] == '\0') && flag == 0)
        {
            while (isspace(str[i]))
                i++;
            if (str[i] == '\0')
                return TRUE;
            else
                return FALSE;
        }
        else if (isdigit(str[i]) && flag == 0)
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
            else if ((str[i] == 'e' || str[i] == 'E'))
            {
                if (check_after_e(str, i) == TRUE)
                    return TRUE;
                else
                    return FALSE;
            }
            else
                return FALSE;
        }
        else if ((str[i] == 'e' || str[i] == 'E') && flag == 0)
        {
            if (check_after_e(str, i) == TRUE)
                return TRUE;
            else
                return FALSE;
        }
    }
    else if ((str[i] == 'e' || str[i] == 'E') && flag == 0)
    {
        if (check_after_e(str, i) == TRUE)
            return TRUE;
        else
            return FALSE;
    }
    return FALSE;
}
