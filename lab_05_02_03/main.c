#include "average.h"
#include "rule_check.h"

int main(int argc, char **argv)
{
    FILE *f;

    if (argc != 2)
    {
        fprintf(stdout, "Incorrect arguments.\n");
        return INCORRECT_NUMBER_ARGS;
    }

    f = fopen(argv[1], "r");
    if (f == NULL)
    {
        fprintf(stdout, "Error file.\n");
        return ERR_FILE;
    }
    float sr;
    int k = 0;

    if (process1(f, &sr, &k) == INCORRECT_DATA)
    {
        printf("Incorrect data.\n");
        fclose(f);
        return INCORRECT_DATA;
    }
    if (process2(f, sr, &k) == NO)
        printf("0");
    else
        printf("1");

    fclose(f);

    return 0;
}
