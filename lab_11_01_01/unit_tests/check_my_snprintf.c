#include <stdio.h>
#include <limits.h>

#include "check_my_snprintf.h"

#define SIZE 30

START_TEST(test_my_snprintf_NULL_buf_size_0_no_specifier)
{
    char *expected_str = NULL;
    char *my_str = NULL;
    int expected_res = snprintf(expected_str, 0, "akjdvb");
    int my_res = my_snprintf(my_str, 0, "akjdvb");
    ck_assert_int_eq(expected_res, my_res);
    ck_assert_ptr_null(expected_str);
    ck_assert_ptr_null(my_str);
}
END_TEST

START_TEST(test_my_snprintf_NULL_buf_size_0_with_specifier)
{
    char *expected_str = NULL;
    char *my_str = NULL;
    int expected_res = snprintf(expected_str, 0, "akj%sdvb", "hello");
    int my_res = my_snprintf(my_str, 0, "akj%sdvb", "hello");
    ck_assert_int_eq(expected_res, my_res);
    ck_assert_ptr_null(expected_str);
    ck_assert_ptr_null(my_str);
}
END_TEST

START_TEST(test_my_snprintf_specifier_s_size_0)
{
    char expected_str[SIZE] ={ 0 };
    char my_str[SIZE] ={ 0 };
    int expected_res = snprintf(expected_str, 0, "%s", "hello");
    int my_res = my_snprintf(my_str, 0, "%s", "hello");
    ck_assert_int_eq(expected_res, my_res);
    ck_assert_str_eq(expected_str, my_str);
}
END_TEST

START_TEST(test_my_snprintf_specifier_s_correct_one)
{
    char expected_str[SIZE] ={ 0 };
    char my_str[SIZE] ={ 0 };
    int expected_res = snprintf(expected_str, sizeof(expected_str), "Jdhvb %s, dvb", "hello");
    int my_res = my_snprintf(my_str, sizeof(my_str), "Jdhvb %s, dvb", "hello");
    ck_assert_int_eq(expected_res, my_res);
    ck_assert_str_eq(expected_str, my_str);
}
END_TEST

START_TEST(test_my_snprintf_specifier_s_correct_many)
{
    char expected_str[SIZE] ={ 0 };
    char my_str[SIZE] ={ 0 };
    int expected_res = snprintf(expected_str, sizeof(expected_str), "%sJ%sdhvb %s, dvb", "hello", "hello", "hello");
    int my_res = my_snprintf(my_str, sizeof(my_str), "%sJ%sdhvb %s, dvb", "hello", "hello", "hello");
    ck_assert_int_eq(expected_res, my_res);
    ck_assert_str_eq(expected_str, my_str);
}
END_TEST

START_TEST(test_my_snprintf_only_specifier_s)
{
    char expected_str[SIZE] ={ 0 };
    char my_str[SIZE] ={ 0 };
    int expected_res = snprintf(expected_str, sizeof(expected_str), "%s", "hello");
    int my_res = my_snprintf(my_str, sizeof(my_str), "%s", "hello");
    ck_assert_int_eq(expected_res, my_res);
    ck_assert_str_eq(expected_str, my_str);
}
END_TEST

START_TEST(test_my_snprintf_specifier_s_empty_string)
{
    char expected_str[SIZE] ={ 0 };
    char my_str[SIZE] ={ 0 };
    int expected_res = snprintf(expected_str, sizeof(expected_str), "abc%s", "");
    int my_res = my_snprintf(my_str, sizeof(my_str), "abc%s", "");
    ck_assert_int_eq(expected_res, my_res);
    ck_assert_str_eq(expected_str, my_str);
}
END_TEST

START_TEST(test_my_snprintf_specifier_s_rewriting)
{
        char expected_str[SIZE] = "aldkfvf";
        char my_str[SIZE] = "aldkfvf";
        int expected_res = snprintf(expected_str, sizeof(expected_str), "%s", "ttttt");
        int my_res = my_snprintf(my_str, sizeof(my_str), "%s", "ttttt");
        ck_assert_int_eq(expected_res, my_res);
        ck_assert_str_eq(expected_str, my_str);
}
END_TEST

START_TEST(test_my_snprintf_specifier_s_going_beyond_size)
{
    char expected_str[SIZE] ={ 0 };
    char my_str[SIZE] ={ 0 };
    int expected_res = snprintf(expected_str, sizeof(expected_str), "Jdhvb wgpqux kayc bapw nv, %s", "hello");
    int my_res = my_snprintf(my_str, sizeof(my_str), "Jdhvb wgpqux kayc bapw nv, %s", "hello");
    ck_assert_int_eq(expected_res, my_res);
    ck_assert_str_eq(expected_str, my_str);
}
END_TEST

START_TEST(test_my_snprintf_specifier_s_size_eq_n)
{
    char expected_str[SIZE] ={ 0 };
    char my_str[SIZE] ={ 0 };
    int expected_res = snprintf(expected_str, sizeof(expected_str), "Jdhvb wqux kayc bapw nv, %s", "hello");
    int my_res = my_snprintf(my_str, sizeof(my_str), "Jdhvb wqux kayc bapw nv, %s", "hello");
    ck_assert_int_eq(expected_res, my_res);
    ck_assert_str_eq(expected_str, my_str);
}
END_TEST

START_TEST(test_my_snprintf_specifier_hx_many)
{
    char expected_str[SIZE] = { 0 };
    char my_str[SIZE] = { 0 };
    int expected_res = snprintf(expected_str, sizeof(expected_str), "%hxJdhvb %hx, dvb%hx", 1000, -1, 5111);
    int my_res = my_snprintf(my_str, sizeof(my_str), "%hxJdhvb %hx, dvb%hx", 1000, -1, 5111);
    ck_assert_str_eq(expected_str, my_str);
    ck_assert_int_eq(expected_res, my_res);
}
END_TEST

START_TEST(test_my_snprintf_specifier_hx_only)
{
    char expected_str[SIZE] = { 0 };
    char my_str[SIZE] = { 0 };
    int expected_res = snprintf(expected_str, sizeof(expected_str), "%hx", 9876);
    int my_res = my_snprintf(my_str, sizeof(my_str), "%hx", 9876);
    ck_assert_str_eq(expected_str, my_str);
    ck_assert_int_eq(expected_res, my_res);
}
END_TEST

START_TEST(test_my_snprintf_specifier_hx_max_ushrt)
{
    char expected_str[SIZE] = { 0 };
    char my_str[SIZE] = { 0 };
    int expected_res = snprintf(expected_str, sizeof(expected_str), "Jdhvb %hx, dvb", USHRT_MAX);
    int my_res = my_snprintf(my_str, sizeof(my_str), "Jdhvb %hx, dvb", USHRT_MAX);
    ck_assert_str_eq(expected_str, my_str);
    ck_assert_int_eq(expected_res, my_res);
}
END_TEST

START_TEST(test_my_snprintf_specifier_hx_min_ushrt)
{
    char expected_str[SIZE] = { 0 };
    char my_str[SIZE] = { 0 };
    int expected_res = snprintf(expected_str, sizeof(expected_str), "Jdhvb %hx, dvb", 0);
    int my_res = my_snprintf(my_str, sizeof(my_str), "Jdhvb %hx, dvb", 0);
    ck_assert_str_eq(expected_str, my_str);
    ck_assert_int_eq(expected_res, my_res);
}
END_TEST

START_TEST(test_my_snprintf_specifier_hx_less_than_min_ushrt)
{
    char expected_str[SIZE] = { 0 };
    char my_str[SIZE] = { 0 };
    int expected_res = snprintf(expected_str, sizeof(expected_str), "Jdhvb %hx, dvb", -10000);
    int my_res = my_snprintf(my_str, sizeof(my_str), "Jdhvb %hx, dvb", -10000);
    ck_assert_int_eq(expected_res, my_res);
    ck_assert_str_eq(expected_str, my_str);
}
END_TEST

START_TEST(test_my_snprintf_specifier_hx_more_than_max_ushrt)
{
    char expected_str[SIZE] = { 0 };
    char my_str[SIZE] = { 0 };
    int expected_res = snprintf(expected_str, sizeof(expected_str), "Jdhvb %hx, dvb", 100000000);
    int my_res = my_snprintf(my_str, sizeof(my_str), "Jdhvb %hx, dvb", 100000000);
    ck_assert_int_eq(expected_res, my_res);
    ck_assert_str_eq(expected_str, my_str);
}
END_TEST

START_TEST(test_my_snprintf_specifier_hx_numerical_conversion)
{
    char expected_str[SIZE] = { 0 };
    char my_str[SIZE] = { 0 };
    int expected_res = snprintf(expected_str, sizeof(expected_str), "Jdhvb %hx, dvb", 121);
    int my_res = my_snprintf(my_str, sizeof(my_str), "Jdhvb %hx, dvb", 121);
    ck_assert_int_eq(expected_res, my_res);
    ck_assert_str_eq(expected_str, my_str);
}
END_TEST

START_TEST(test_my_snprintf_specifier_hx_letter_conversion)
{
    char expected_str[SIZE] = { 0 };
    char my_str[SIZE] = { 0 };
    int expected_res = snprintf(expected_str, sizeof(expected_str), "Jdhvb %hx, dvb", 186);
    int my_res = my_snprintf(my_str, sizeof(my_str), "Jdhvb %hx, dvb", 186);
    ck_assert_int_eq(expected_res, my_res);
    ck_assert_str_eq(expected_str, my_str);
}
END_TEST

START_TEST(test_my_snprintf_specifier_hx_letter_and_numerical_conversion)
{
    char expected_str[SIZE] = { 0 };
    char my_str[SIZE] = { 0 };
    int expected_res = snprintf(expected_str, sizeof(expected_str), "Jdhvb %hx, dvb", 44);
    int my_res = my_snprintf(my_str, sizeof(my_str), "Jdhvb %hx, dvb", 44);
    ck_assert_int_eq(expected_res, my_res);
    ck_assert_str_eq(expected_str, my_str);
}
END_TEST

START_TEST(test_my_snprintf_specifier_hx_negative_number)
{
    char expected_str[SIZE] = { 0 };
    char my_str[SIZE] = { 0 };
    int expected_res = snprintf(expected_str, sizeof(expected_str), "Jdhvb %hx, dvb", -8);
    int my_res = my_snprintf(my_str, sizeof(my_str), "Jdhvb %hx, dvb", -8);
    ck_assert_int_eq(expected_res, my_res);
    ck_assert_str_eq(expected_str, my_str);
}
END_TEST

START_TEST(test_my_snprintf_specifier_hx_hex_number)
{
    char expected_str[SIZE] = { 0 };
    char my_str[SIZE] = { 0 };
    int expected_res = snprintf(expected_str, sizeof(expected_str), "Jdhvb %hx, dvb", 0xc5);
    int my_res = my_snprintf(my_str, sizeof(my_str), "Jdhvb %hx, dvb", 0xc5);
    ck_assert_int_eq(expected_res, my_res);
    ck_assert_str_eq(expected_str, my_str);
}
END_TEST

START_TEST(test_my_snprintf_specifier_hx_going_beyond_size)
{
    char expected_str[SIZE] = { 0 };
    char my_str[SIZE] = { 0 };
    int expected_res = snprintf(expected_str, sizeof(expected_str), "Jdhvb wgpzqqux ayc bapw nv, %hx", 1000);
    int my_res = my_snprintf(my_str, sizeof(my_str), "Jdhvb wgpzqqux ayc bapw nv, %hx", 1000);
    ck_assert_int_eq(expected_res, my_res);
    ck_assert_str_eq(expected_str, my_str);
}
END_TEST

START_TEST(test_my_snprintf_specifier_hx_n_more_than_size)
{
    char expected_str[SIZE] = { 0 };
    char my_str[SIZE] = { 0 };
    int expected_res = snprintf(expected_str, sizeof(expected_str) + 10, "Jdhvb wgpzx kayc bapw nv, %hx", 200);
    int my_res = my_snprintf(my_str, sizeof(my_str) + 10, "Jdhvb wgpzx kayc bapw nv, %hx", 200);
    ck_assert_int_eq(expected_res, my_res);
    ck_assert_str_eq(expected_str, my_str);
}
END_TEST

START_TEST(test_my_snprintf_specifier_hx_size_eq_n)
{
    char expected_str[SIZE] = { 0 };
    char my_str[SIZE] = { 0 };
    int expected_res = snprintf(expected_str, sizeof(expected_str), "Jdhvb wppqux kayc bapw nv, %hx", 200);
    int my_res = my_snprintf(my_str, sizeof(my_str), "Jdhvb wppqux kayc bapw nv, %hx", 200);
    ck_assert_int_eq(expected_res, my_res);
    ck_assert_str_eq(expected_str, my_str);
}
END_TEST

Suite* my_snprintf_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("my_snprintf");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_my_snprintf_NULL_buf_size_0_no_specifier);
    tcase_add_test(tc_pos, test_my_snprintf_NULL_buf_size_0_with_specifier);
    tcase_add_test(tc_pos, test_my_snprintf_specifier_s_size_0);
    tcase_add_test(tc_pos, test_my_snprintf_specifier_s_correct_one);
    tcase_add_test(tc_pos, test_my_snprintf_specifier_s_correct_many);
    tcase_add_test(tc_pos, test_my_snprintf_only_specifier_s);
    tcase_add_test(tc_pos, test_my_snprintf_specifier_s_empty_string);
    tcase_add_test(tc_pos, test_my_snprintf_specifier_s_rewriting);
    tcase_add_test(tc_pos, test_my_snprintf_specifier_s_going_beyond_size);
    tcase_add_test(tc_pos, test_my_snprintf_specifier_s_size_eq_n);

    tcase_add_test(tc_pos, test_my_snprintf_specifier_hx_many);
    tcase_add_test(tc_pos, test_my_snprintf_specifier_hx_only);
    tcase_add_test(tc_pos, test_my_snprintf_specifier_hx_max_ushrt);
    tcase_add_test(tc_pos, test_my_snprintf_specifier_hx_min_ushrt);
    tcase_add_test(tc_pos, test_my_snprintf_specifier_hx_less_than_min_ushrt);
    tcase_add_test(tc_pos, test_my_snprintf_specifier_hx_more_than_max_ushrt);
    tcase_add_test(tc_pos, test_my_snprintf_specifier_hx_numerical_conversion);
    tcase_add_test(tc_pos, test_my_snprintf_specifier_hx_letter_conversion);
    tcase_add_test(tc_pos, test_my_snprintf_specifier_hx_letter_and_numerical_conversion);
    tcase_add_test(tc_pos, test_my_snprintf_specifier_hx_negative_number);
    tcase_add_test(tc_pos, test_my_snprintf_specifier_hx_hex_number);
    tcase_add_test(tc_pos, test_my_snprintf_specifier_hx_going_beyond_size);
    tcase_add_test(tc_pos, test_my_snprintf_specifier_hx_n_more_than_size);
    tcase_add_test(tc_pos, test_my_snprintf_specifier_hx_size_eq_n);

    suite_add_tcase(s, tc_pos);

    return s;
}


