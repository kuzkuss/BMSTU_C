#include <stdio.h>
#include <string.h>

#define SIZE_NAME 25
#define SIZE_ARRAY 15
#define INPUT_ERROR 4
#define EMPTY_STRING 5
#define ARRAY_OVERFLOW 6
#define STABLE_WORK 0

struct subjects
{
    char name[SIZE_NAME + 1];
    double weight;
    double volume;
};

int read_array(FILE *f_in, int *amount, struct subjects *subjects_array)
{
    while (!feof(f_in))
    {
        if (*amount >= 15)
            return ARRAY_OVERFLOW;
        if (!fgets(subjects_array[*amount].name, SIZE_NAME + 1, f_in))
            return INPUT_ERROR;
        size_t len = strlen(subjects_array[*amount].name);
        if (subjects_array[*amount].name[len - 1] == '\n')
        {
            subjects_array[*amount].name[len - 1] = '\0';
            --len;
        }
        if (len == 0)
            return EMPTY_STRING;
        if (fscanf(f_in, "%lf", &subjects_array[*amount].weight) != 1 || subjects_array[*amount].weight <= 0)
            return INPUT_ERROR;
        if (fscanf(f_in, "%lf", &subjects_array[*amount].volume) != 1 || subjects_array[*amount].volume <= 0)
            return INPUT_ERROR;
        ++(*amount);
        if (fgetc(f_in) == EOF)
            break;
    }
    return STABLE_WORK;
}

void test_read_array(void)
{
    int err_cnt = 0;

    struct subjects subjects_array[SIZE_ARRAY];
    int n = 0;

    FILE *f_in1;
    f_in1 = fopen("f_in1.txt", "r");
    FILE *f_in2;
    f_in2 = fopen("f_in2.txt", "r");
    FILE *f_in3;
    f_in3 = fopen("f_in3.txt", "r");
    FILE *f_in4;
    f_in4 = fopen("f_in4.txt", "r");
    FILE *f_in5;
    f_in5 = fopen("f_in5.txt", "r");
    FILE *f_in6;
    f_in6 = fopen("f_in6.txt", "r");
    FILE *f_in7;
    f_in7 = fopen("f_in7.txt", "r");
    FILE *f_in8;
    f_in8 = fopen("f_in8.txt", "r");

    //Incorrect input

    if (read_array(f_in1, &n, subjects_array) != ARRAY_OVERFLOW)
        err_cnt++;
    n = 0;

    if (read_array(f_in2, &n, subjects_array) != INPUT_ERROR)
        err_cnt++;
    n = 0;

    if (read_array(f_in3, &n, subjects_array) != EMPTY_STRING)
        err_cnt++;
    n = 0;

    if (read_array(f_in4, &n, subjects_array) != INPUT_ERROR)
        err_cnt++;
    n = 0;

    if (read_array(f_in5, &n, subjects_array) != INPUT_ERROR)
        err_cnt++;
    n = 0;

    if (read_array(f_in6, &n, subjects_array) != INPUT_ERROR)
        err_cnt++;
    n = 0;

    if (read_array(f_in7, &n, subjects_array) != INPUT_ERROR)
        err_cnt++;
    n = 0;

    //Correct input

    if (read_array(f_in8, &n, subjects_array) != STABLE_WORK || n != 3)
        err_cnt++;

    fclose(f_in1);
    fclose(f_in2);
    fclose(f_in3);
    fclose(f_in4);
    fclose(f_in5);
    fclose(f_in6);
    fclose(f_in7);
    fclose(f_in8);

    printf("%s: %s\n", __func__, err_cnt ? "FAILED" : "OK");
}

int main(void)
{
    test_read_array();

    return 0;
}
