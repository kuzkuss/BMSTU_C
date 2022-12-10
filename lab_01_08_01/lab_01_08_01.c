#include <stdio.h>

int print_result(unsigned int res)
{
    int current_bit;
    printf("Result: ");
    for (int i = 31; i >= 0; i--)
    {
        current_bit = res >> i & 1;
        printf("%d", current_bit);
    }
    return 0;
}

int main(void)
{
    int byte1, byte2, byte3, byte4, rc, byte5, byte6, byte7, byte8;
    unsigned int result;
    rc = scanf("%d%d%d%d", &byte1, &byte2, &byte3, &byte4);
    if (rc != 4)
    {
        printf("Error: Input error\n");
        return 1;
    }
    if (byte1 < 0 || byte1 > 255 || byte2 < 0 || byte2 > 255 || byte3 < 0 || byte3 > 255)
    {
        printf("Error: Invalid byte value entered");
        return 2;
    }
    result = byte1;
    result = (result << 8) + byte2;
    result = (result << 8) + byte3;
    result = (result << 8) + byte4;
    print_result(result);
    byte5 = result >> 24;
    byte6 = (result << 8) >> 24;
    byte7 = (result << 16) >> 24;
    byte8 = (result << 24) >> 24;
    printf(" %d %d %d %d", byte5, byte6, byte7, byte8);
    return 0;
}
