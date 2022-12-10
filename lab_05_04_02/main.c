#include "sort.h"
#include "process.h"
#include "const.h"

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);
    struct_t products[100] = { 0 };
    if (argc != 4)
        return ERROR;
    else if (strcmp(argv[1], "st") == 0)
    {
        int num = 0;
        int rc = read_struct(products, argv[2], &num);
        if (num == 0)
            return INCORRECT_DATA;
        if (rc == INCORRECT_DATA)
            return INCORRECT_DATA;
        else if (rc == FILE_ERROR)
            return FILE_ERROR;
        else if (rc == READ_ERROR)
            return READ_ERROR;
        rc = sort(products, argv[3], num);
        if (rc == FILE_ERROR)
            return FILE_ERROR;
        return OK;
    }
    else if (strcmp(argv[1], "ft") == 0)
    {
        int num = 0;
        int rc = read_struct(products, argv[2], &num);
        if (num == 0)
            return INCORRECT_DATA;
        if (rc == INCORRECT_DATA)
            return INCORRECT_DATA;
        else if (rc == FILE_ERROR)
            return FILE_ERROR;
        else if (rc == READ_ERROR)
            return READ_ERROR;
        rc = process(products, num, argv[3]);
        if (rc == PROCESS_ERROR)
            return PROCESS_ERROR;
        return OK;
    }
    else
        return ERROR;
}
