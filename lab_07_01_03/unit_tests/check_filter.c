#include <stdlib.h>
#include "check_filter.h"

START_TEST(test_key_bad_pb_src_ptr)
{
    int n = 5;
    int arr[] = {6, -7, 2, 4, 3};

    int *new_beg = NULL;
    int *new_end = NULL;

    int rc;

    rc = key(NULL, arr + n, &new_beg, &new_end);

    ck_assert_int_eq(rc, INCORRECT_DATA);
}
END_TEST


START_TEST(test_key_bad_pe_src_ptr)
{
    int arr[] = {6, -7, 2, 4, 3};

    int *new_beg = NULL;
    int *new_end = NULL;

    int rc;

    rc = key(arr, NULL, &new_beg, &new_end);

    ck_assert_int_eq(rc, INCORRECT_DATA);
}
END_TEST


START_TEST(test_key_empty_array)
{
    int n = 5;
    int arr[] = {-6, 7, 2, 4, 3};

    int *new_beg = NULL;
    int *new_end = NULL;

    int rc;

    rc = key(arr, arr + n, &new_beg, &new_end);

    ck_assert_int_eq(rc, EMPTY_ARRAY);
}
END_TEST


START_TEST(test_key_no_negative)
{
    int n = 8;
    int arr[] = {21, 12, 3, 15, 23, 6, 19, 8};

    int *new_beg = NULL;
    int *new_end = NULL;

    int rc;

    rc = key(arr, arr + n, &new_beg, &new_end);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(n, new_end - new_beg);
    ck_assert_ptr_nonnull(new_beg);
    for (int i = 0; i < n; ++i)
        ck_assert_int_eq(arr[i], *(new_beg + i));
    free(new_beg);
}
END_TEST


START_TEST(test_key_one_negative)
{
    int n = 7;
    int arr[] = {2, 4, 1, 5, -1, 3, 2};
    int new_n = 4;

    int *new_beg = NULL;
    int *new_end = NULL;

    int rc;

    rc = key(arr, arr + n, &new_beg, &new_end);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(new_n, new_end - new_beg);
    ck_assert_ptr_nonnull(new_beg);
    for (int i = 0; i < new_n; ++i)
        ck_assert_int_eq(arr[i], *(new_beg + i));
    free(new_beg);
}
END_TEST

START_TEST(test_key_several_negative)
{
    int n = 10;
    int arr[] = {12, 6, 7, -2, -4, 3, 5, 9, -7, 8};
    int new_n = 8;

    int *new_beg = NULL;
    int *new_end = NULL;

    int rc;

    rc = key(arr, arr + n, &new_beg, &new_end);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(new_n, new_end - new_beg);
    ck_assert_ptr_nonnull(new_beg);
    for (int i = 0; i < new_n; ++i)
        ck_assert_int_eq(arr[i], *(new_beg + i));
    free(new_beg);
}
END_TEST

START_TEST(test_key_one_last_negative)
{
    int n = 7;
    int arr[] = {8, 5, 2, 7, 4, 6, -1};
    int new_n = 6;

    int *new_beg = NULL;
    int *new_end = NULL;

    int rc;

    rc = key(arr, arr + n, &new_beg, &new_end);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(new_n, new_end - new_beg);
    ck_assert_ptr_nonnull(new_beg);
    for (int i = 0; i < new_n; ++i)
        ck_assert_int_eq(arr[i], *(new_beg + i));
    free(new_beg);
}
END_TEST


Suite* key_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("key");

    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, test_key_bad_pb_src_ptr);
    tcase_add_test(tc_neg, test_key_bad_pe_src_ptr);
    tcase_add_test(tc_neg, test_key_empty_array);

    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_key_no_negative);
    tcase_add_test(tc_pos, test_key_one_negative);
    tcase_add_test(tc_pos, test_key_several_negative);
    tcase_add_test(tc_pos, test_key_one_last_negative);

    suite_add_tcase(s, tc_pos);

    return s;
}

