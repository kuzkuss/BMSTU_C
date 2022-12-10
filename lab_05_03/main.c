/*
 * Целочисленный тип int
 * Алгоритм сортировки: сортировка пузырьком
 * "Направление" упорядочивания: сортировка по возрастанию
*/

#include <string.h>
#include "create_read.h"
#include "sort.h"

int main(int argc, char **argv)
{
    if ((argc != 3) && (argc != 4))
    {
        //printf("Incorrect arguments.");
        return INCORRECT_ARG;
    }
    if (strcmp(argv[1], "c") == 0)
    {
        if (argc != 4)
        {
            //printf("Incorrect arguments.");
            return INCORRECT_ARG;
        }
        int rc;
        int num_el;
        num_el = atoi(argv[2]);
        if (num_el <= 0)
        {
            //printf("Incorrect amount of numbers");
            return AMOUNT_ERR;
        }
        rc = create_file(argv[3], num_el);
        if (rc == FILE_ERROR)
        {
            //printf("File error");
            return FILE_ERROR;
        }
        if (rc == WROTE_ERROR)
        {
            //printf("Wrote error");
            return WROTE_ERROR;
        }
        return OK;
    }
    else if (strcmp(argv[1], "p") == 0)
    {
        if (argc != 3)
        {
            //printf("Incorrect arguments.");
            return INCORRECT_ARG;
        }
        int rc;
        rc = print_data(argv[2]);
        if (rc == FILE_ERROR)
        {
            //printf("File error");
            return FILE_ERROR;
        }
        else if (rc == SIZE_ERROR)
        {
            //printf("Size error");
            return SIZE_ERROR;
        }
        return OK;
    }
    else if (strcmp(argv[1], "s") == 0)
    {
        if (argc != 3)
        {
            //printf("Incorrect arguments.");
            return INCORRECT_ARG;
        }
        int rc;
        rc = sort(argv[2]);
        if (rc == FILE_ERROR)
        {
            //printf("File error");
            return FILE_ERROR;
        }
        else if (rc == SIZE_ERROR)
        {
            //printf("Size error");
            return SIZE_ERROR;
        }
        else if (rc == WROTE_ERROR)
        {
            //printf("Wrote error");
            return WROTE_ERROR;
        }
        else if (rc == READ_ERROR)
        {
            //printf("Read error");
            return READ_ERROR;
        }
        return OK;
    }
    else
        return KEY_ERROR;
}

