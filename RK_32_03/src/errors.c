#include <stdio.h>
#include "errors.h"

void print_errors(int err)
{
    if (err == KEY_ERROR)
        puts("Key error");
    else if (err == INCORRECT_ARG)
        puts("Incorrect argument");
    else if (err == FILE_ERROR)
        puts("File doesn't exist");
    else if (err == EMPTY_LIST)
        puts("Empty form list");
    else if (err == INPUT_ERROR)
        puts("Input error");
    else if (err == EMPTY_STRING)
        puts("Empty string");
    else if (err == OVERFLOW_STR)
        puts("Overflow string");
    else if (err == EMPTY_FILE)
        puts("Empty file");
}
