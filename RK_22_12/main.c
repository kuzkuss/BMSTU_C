#include "rk2.h"

int main(void)
{
    setbuf(stdout, NULL);
	char file_name[] = "input.bin";
    if (create_file(file_name) != 0)
    {
        printf("Input error.\n");
        return STR_ERR;
    }

    if (read_file(file_name) != 0)
    {
        printf("No file.\n");
        return NO_FILE;
    }
    return 0;
}