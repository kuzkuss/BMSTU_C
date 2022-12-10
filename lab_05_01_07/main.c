#include "process.h"

int main(void)
{
    int count = 0;
    int rc = 0;
    rc = process(stdin, &count);
    if (rc != 0)
    {
        fprintf(stdout, "Incorrect input\n");
        return INCORRECT_INPUT;
    }
    fprintf(stdout, "%d", count);
    return 0;
}
