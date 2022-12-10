#include <limits.h>

#include "check_convertation.h"

#define LEN_HEX_NUM 5

START_TEST(test_convertation_letter_digit)
{
    char hex_number[LEN_HEX_NUM] = { 0 };
    convertation(165, hex_number);
    ck_assert_str_eq(hex_number, "a5");
}
END_TEST

START_TEST(test_convertation_digit_letter)
{
    char hex_number[LEN_HEX_NUM] = { 0 };
    convertation(127, hex_number);
    ck_assert_str_eq(hex_number, "7f");
}
END_TEST

START_TEST(test_convertation_letter_letter)
{
    char hex_number[LEN_HEX_NUM] = { 0 };
    convertation(223, hex_number);
    ck_assert_str_eq(hex_number, "df");
}
END_TEST

START_TEST(test_convertation_digit_digit)
{
    char hex_number[LEN_HEX_NUM] = { 0 };
    convertation(118, hex_number);
    ck_assert_str_eq(hex_number, "76");
}
END_TEST

START_TEST(test_convertation_single_digit)
{
    char hex_number[LEN_HEX_NUM] = { 0 };
    convertation(3, hex_number);
    ck_assert_str_eq(hex_number, "3");
}
END_TEST

START_TEST(test_convertation_negative_number)
{
    char hex_number[LEN_HEX_NUM] = { 0 };
    convertation(-100, hex_number);
    ck_assert_str_eq(hex_number, "ff9c");
}
END_TEST

START_TEST(test_convertation_max_ushrt)
{
    char hex_number[LEN_HEX_NUM] = { 0 };
    convertation(USHRT_MAX, hex_number);
    ck_assert_str_eq(hex_number, "ffff");
}
END_TEST

START_TEST(test_convertation_more_than_max_ushrt)
{
    char hex_number[LEN_HEX_NUM] = { 0 };
    convertation((unsigned short) 100000, hex_number);
    ck_assert_str_eq(hex_number, "86a0");
}
END_TEST

START_TEST(test_convertation_min_ushrt)
{
    char hex_number[LEN_HEX_NUM] = { 0 };
    convertation(0, hex_number);
    ck_assert_str_eq(hex_number, "0");
}
END_TEST

START_TEST(test_convertation_less_than_min_ushrt)
{
    char hex_number[LEN_HEX_NUM] = { 0 };
    convertation(-500, hex_number);
    ck_assert_str_eq(hex_number, "fe0c");
}
END_TEST

START_TEST(test_convertation_zero)
{
    char hex_number[LEN_HEX_NUM] = { 0 };
    convertation(0, hex_number);
    ck_assert_str_eq(hex_number, "0");
}
END_TEST

Suite* convertation_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("convertation");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_convertation_letter_digit);
    tcase_add_test(tc_pos, test_convertation_digit_letter);
    tcase_add_test(tc_pos, test_convertation_letter_letter);
    tcase_add_test(tc_pos, test_convertation_digit_digit);
    tcase_add_test(tc_pos, test_convertation_single_digit);
    tcase_add_test(tc_pos, test_convertation_negative_number);
    tcase_add_test(tc_pos, test_convertation_max_ushrt);
    tcase_add_test(tc_pos, test_convertation_more_than_max_ushrt);
    tcase_add_test(tc_pos, test_convertation_min_ushrt);
    tcase_add_test(tc_pos, test_convertation_less_than_min_ushrt);
    tcase_add_test(tc_pos, test_convertation_zero);

    suite_add_tcase(s, tc_pos);

    return s;
}


