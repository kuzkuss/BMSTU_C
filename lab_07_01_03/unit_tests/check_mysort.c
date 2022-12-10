#include "check_mysort.h"

START_TEST(test_mysort_int_one_element)
{
    size_t n = 1;
    int arr[] = {63};
    int sorted_arr[] = {63};

    mysort(arr, n, sizeof(int), comp_int);

    for (int i = 0; i < n; ++i)
        ck_assert_int_eq(arr[i], sorted_arr[i]);
}
END_TEST


START_TEST(test_mysort_int_all_elements_diferent)
{
    size_t n = 9;
    int arr[] = {-4, 2, 0, 1, 11, -7, 8, 4, 10};
    int sorted_arr[] = {-7, -4, 0, 1, 2, 4, 8, 10, 11};

    mysort(arr, n, sizeof(int), comp_int);

    for (int i = 0; i < n; ++i)
        ck_assert_int_eq(arr[i], sorted_arr[i]);
}
END_TEST


START_TEST(test_mysort_int_several_equal_elements)
{
    size_t n = 7;
    int arr[] = {-2, 4, 3, 6, 1, 3, -7};
    int sorted_arr[] = {-7, -2, 1, 3, 3, 4, 6};

    mysort(arr, n, sizeof(int), comp_int);

    for (int i = 0; i < n; ++i)
        ck_assert_int_eq(arr[i], sorted_arr[i]);
}
END_TEST


START_TEST(test_mysort_int_negative_elements)
{
    size_t n = 6;
    int arr[] = {-8, -10, -6, -12, -20, -5};
    int sorted_arr[] = {-20, -12, -10, -8, -6, -5};

    mysort(arr, n, sizeof(int), comp_int);

    for (int i = 0; i < n; ++i)
        ck_assert_int_eq(arr[i], sorted_arr[i]);
}
END_TEST


START_TEST(test_mysort_int_positive_negative_elements)
{
    size_t n = 6;
    int arr[] = {3, -2, 6, 8, -1, 9};
    int sorted_arr[] = {-2, -1, 3, 6, 8, 9};

    mysort(arr, n, sizeof(int), comp_int);

    for (int i = 0; i < n; ++i)
        ck_assert_int_eq(arr[i], sorted_arr[i]);
}
END_TEST

START_TEST(test_mysort_int_positive_elements)
{
    size_t n = 7;
    int arr[] = {21, 23, 19, 35, 42, 18, 20};
    int sorted_arr[] = {18, 19, 20, 21, 23, 35, 42};

    mysort(arr, n, sizeof(int), comp_int);

    for (int i = 0; i < n; ++i)
        ck_assert_int_eq(arr[i], sorted_arr[i]);
}
END_TEST

START_TEST(test_mysort_double)
{
    size_t n = 7;
    double arr[] = {2.1, 2.3, 1.9, 3.5, 4.2, 1.8, 2.0};
    double sorted_arr[] = {1.8, 1.9, 2.0, 2.1, 2.3, 3.5, 4.2};

    mysort(arr, n, sizeof(double), comp_double);

    for (int i = 0; i < n; ++i)
        ck_assert_double_eq(arr[i], sorted_arr[i]);
}
END_TEST

START_TEST(test_mysort_char)
{
    size_t n = 7;
    char arr[] = {'f', 'a', 'g', 'b', 'd', 'h', 'e'};
    char sorted_arr[] = {'a', 'b', 'd', 'e', 'f', 'g', 'h'};

    mysort(arr, n, sizeof(char), comp_char);

    for (int i = 0; i < n; ++i)
        ck_assert_int_eq(arr[i], sorted_arr[i]);
}
END_TEST

Suite* mysort_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("mysort");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_mysort_int_one_element);
    tcase_add_test(tc_pos, test_mysort_int_all_elements_diferent);
    tcase_add_test(tc_pos, test_mysort_int_several_equal_elements);
    tcase_add_test(tc_pos, test_mysort_int_negative_elements);
    tcase_add_test(tc_pos, test_mysort_int_positive_negative_elements);
    tcase_add_test(tc_pos, test_mysort_int_positive_elements);
    tcase_add_test(tc_pos, test_mysort_double);
    tcase_add_test(tc_pos, test_mysort_char);

    suite_add_tcase(s, tc_pos);

    return s;
}

int comp_double(const void *a, const void *b)
{
    double diff = *(double *)a - *(double *)b;
    if (diff < 0.0)
        return -1;
    else if (diff > 0.0)
        return 1;
    else
        return 0;
}

int comp_char(const void *a, const void *b)
{
    return *(char *)a - *(char *)b;
}



