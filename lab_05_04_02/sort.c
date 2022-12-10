#include "sort.h"
#include "const.h"

int read_struct(struct_t *products, char *input_file, int *i)
{
    FILE *f;
    f = fopen(input_file, "r");
    if (f == NULL)
        return FILE_ERROR;
    while (!feof(f))
    {
        if (!fgets(products[*i].name, LEN_NAME + 1, f))
            break;
        if (!fgets(products[*i].manufacturer, LEN_MANUFACTURER + 1, f))
            break;
        if (fscanf(f, "%u", &products[*i].price) != 1)
        {
            fclose(f);
            return INCORRECT_DATA;
        }
        if (fscanf(f, "%u", &products[*i].amount) != 1)
        {
            fclose(f);
            return INCORRECT_DATA;
        }
        fgetc(f);
        (*i)++;
    }
    if (!feof(f))
    {
        fclose(f);
        return READ_ERROR;
    }
    fclose(f);
    return OK;
}

int sort(struct_t *products, char *output_file, int num)
{
    FILE *f;
    f = fopen(output_file, "w");

    if (f == NULL)
        return FILE_ERROR;
    struct_t ad_struct;

    for (int i = 0; i < num - 1; i++)
        for (int j = 0; j < num - i - 1; j++)
        {
            if (products[j].price < products[j + 1].price)
            {
                ad_struct = products[j];
                products[j] = products[j + 1];
                products[j + 1] = ad_struct;
            }
            else if (products[j].price == products[j + 1].price)
                if (products[j].amount < products[j + 1].amount)
                {
                    ad_struct = products[j];
                    products[j] = products[j + 1];
                    products[j + 1] = ad_struct;
                }
        }
    for (int i = 0; i < num; i++)
    {
        fprintf(f, "%s", products[i].name);
        fprintf(f, "%s", products[i].manufacturer);
        fprintf(f, "%u\n", products[i].price);
        fprintf(f, "%u\n", products[i].amount);
    }
    fclose(f);
    return OK;
}

