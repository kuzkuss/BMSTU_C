#include "create_read.h"

int file_size(FILE *f, size_t *size)
{
    if (fseek(f, 0, SEEK_END))
        return ERROR;
    *size = ftell(f);
    if ((*size <= 0) || ((*size) % sizeof(int) != 0))
        return SIZE_ERROR;
    if (fseek(f, 0, SEEK_SET))
        return ERROR;
    return OK;
}

int create_file(char *file_name, int num_el)
{
    FILE *f;
    f = fopen(file_name, "wb");
    if (f == NULL)
        return FILE_ERROR;
    int num;
    srand(time(NULL));
    for (int i = 0; i < num_el; i++)
    {
        num = rand() % 100;
        if (fwrite(&num, sizeof(int), 1, f) != 1)
            return WROTE_ERROR;
    }
    fclose(f);
    return OK;
}

int print_data(char *file_name)
{
    FILE *f;
    f = fopen(file_name, "rb");
    if (f == NULL)
        return FILE_ERROR;
    int rc, num;
    size_t size;
    rc = file_size(f, &size);
    if (rc == OK)
        while (fread(&num, sizeof(int), 1, f) == 1)
            printf("%d ", num);
    else
    {
        fclose(f);
        return SIZE_ERROR;
    }
    fclose(f);
    return OK;
}
