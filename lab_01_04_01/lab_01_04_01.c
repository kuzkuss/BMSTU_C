#include <stdio.h>
int main(void)
{
    int number_flat, number_entrance, number_floor;
    scanf ("%d", &number_flat);
    number_entrance = (number_flat - 1) / 36 + 1;
    number_floor = (number_flat - 1) / 4 % 9 + 1;
    printf("Entrance number: %d\n", number_entrance);
    printf("Floor number: %d\n", number_floor);
    return 0;
}
