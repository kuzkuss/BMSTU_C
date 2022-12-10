#include "sort.h"
#include "create_read.h"

int put_number_by_pos(int pos, int num, FILE *f)
{
    fseek(f, pos * sizeof(int), SEEK_SET);
    if (fwrite(&num, sizeof(int), 1, f) != 1)
        return WROTE_ERROR;
    return OK;
}

int get_number_by_pos(int pos, int *num, FILE *f)
{
    fseek(f, pos * sizeof(int), SEEK_SET);
    if (fread(num, sizeof(int), 1, f) != 1)
            return READ_ERROR;
    return OK;
}

int sort(char *file_name)
{
    FILE *f;
    f = fopen(file_name, "rb+");
    if (f == NULL)
        return FILE_ERROR;
    int rc, num1, num2;
    size_t size;
    rc = file_size(f, &size);
    if (rc == OK)
        for (int i = 0; i < size / sizeof(int) - 1; i++)
            for (int j = 0; j < size / sizeof(int) - i - 1; j++)
            {
                if (get_number_by_pos(j, &num1, f) == READ_ERROR)
                    return READ_ERROR;
                if (get_number_by_pos(j + 1, &num2, f) == READ_ERROR)
                    return READ_ERROR;
                if (num1 > num2)
                {
                    if (put_number_by_pos(j, num2, f) == WROTE_ERROR)
                        return WROTE_ERROR;
                    if (put_number_by_pos(j + 1, num1, f) == WROTE_ERROR)
                        return WROTE_ERROR;
                }
            }
    else
        return SIZE_ERROR;
    fclose(f);
    return OK;
}
