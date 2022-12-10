#include "rk2.h"

int create_file(char f_name[])
{
    int n, i;
    char s[STR_LEN + 1];
    FILE *f;
    printf("Enter the number of sentences:\n");
    scanf("%d", &n);
	if (n <= 0)
		return NUMBER_ERROR;
    getchar();
    f = fopen(f_name, "wb");
    if (f == NULL)
        return NO_FILE;

    for (i = 0; i < n; i++)
    {
        printf("Enter sentence:\n");
        if (!fgets(s, sizeof(s), stdin))
            return STR_ERR;
		if (s[0] == '\n')
			return STR_ERR;
        fwrite(&s, sizeof(s), 1 ,f);
    }
    fclose(f);
    return 0;
}
