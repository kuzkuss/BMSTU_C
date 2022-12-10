#include "check_lib_arr.h"

START_TEST(test_fill_primes_one_element)
{
    int arr[1] = { 0 };
    int n = 1;
    fill_primes(arr, n);

    ck_assert_int_eq(arr[0], 2);
}
END_TEST


START_TEST(test_fill_primes_many_elements)
{
    int arr[5] = { 0 };
    int n = 5;
    fill_primes(arr, n);

    int primes[5] = {2, 3, 5, 7, 11};

    for (int i = 0; i < n; ++i)
        ck_assert_int_eq(arr[i], primes[i]);
}
END_TEST

Suite* fill_primes_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("fill_primes");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_fill_primes_one_element);
    tcase_add_test(tc_pos, test_fill_primes_many_elements);

    suite_add_tcase(s, tc_pos);

    return s;
}

START_TEST(test_filter_one_even)
{
    int n = 5;
    int arr[] = {2, 3, 5, 7, 11};
    int expected_arr[] = {2, 0, 3, 5, 7, 11};

    int dst[6] = { 0 };
    int n_dst = 6;

    int value = 0;

    int rc = filter(arr, n, dst, &n_dst, value);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(n_dst, 6);

    for (int i = 0; i < n_dst; ++i)
        ck_assert_int_eq(dst[i], expected_arr[i]);
}
END_TEST


START_TEST(test_filter_several_even)
{
    int n = 5;
    int arr[5] = {2, 4, 5, 8, 11};
    int expected_arr[] = {2, 0, 4, 0, 5, 8, 0, 11};

    int dst[8] = { 0 };
    int n_dst = 8;

    int value = 0;

    int rc = filter(arr, n, dst, &n_dst, value);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(n_dst, 8);

    for (int i = 0; i < n_dst; ++i)
        ck_assert_int_eq(dst[i], expected_arr[i]);
}
END_TEST


START_TEST(test_filter_all_even)
{
    int n = 5;
    int arr[5] = {2, 4, 6, 8, 10};
    int expected_arr[10] = {2, 0, 4, 0, 6, 0, 8, 0, 10, 0};

    int dst[10] = { 0 };
    int n_dst = 10;

    int value = 0;

    int rc = filter(arr, n, dst, &n_dst, value);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(n_dst, 10);

    for (int i = 0; i < n_dst; ++i)
        ck_assert_int_eq(dst[i], expected_arr[i]);
}
END_TEST

START_TEST(test_filter_no_even)
{
    int n = 5;
    int arr[5] = {1, 3, 5, 7, 9};
    int expected_arr[5] = {1, 3, 5, 7, 9};

    int dst[5] = { 0 };
    int n_dst = 5;

    int value = 0;

    int rc = filter(arr, n, dst, &n_dst, value);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(n_dst, 5);

    for (int i = 0; i < n_dst; ++i)
        ck_assert_int_eq(dst[i], expected_arr[i]);
}
END_TEST

START_TEST(test_filter_all_zeros)
{
    int n = 5;
    int arr[5] = {0, 0, 0, 0, 0};
    int expected_arr[10] = {0, -1, 0, -1, 0, -1, 0, -1, 0, -1};

    int dst[10] = { 0 };
    int n_dst = 10;

    int value = -1;

    int rc = filter(arr, n, dst, &n_dst, value);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(n_dst, 10);

    for (int i = 0; i < n_dst; ++i)
        ck_assert_int_eq(dst[i], expected_arr[i]);
}
END_TEST

START_TEST(test_filter_dst_len_more_than_required_len)
{
    int n = 5;
    int arr[5] = {2, 4, 5, 8, 11};
    int expected_arr[8] = {2, 0, 4, 0, 5, 8, 0, 11};

    int dst[15] = { 0 };
    int n_dst = 15;

    int value = 0;

    int rc = filter(arr, n, dst, &n_dst, value);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(n_dst, 8);

    for (int i = 0; i < n_dst; ++i)
        ck_assert_int_eq(dst[i], expected_arr[i]);
}
END_TEST

START_TEST(test_filter_dst_len_less_than_required_len)
{
    int n = 5;
    int arr[5] = {2, 4, 5, 8, 11};

    int n_dst = 0;

    int value = 0;

    int rc = filter(arr, n, NULL, &n_dst, value);
    ck_assert_int_eq(rc, OVERFLOW_ARRAY);
    ck_assert_int_eq(n_dst, 8);
}
END_TEST

Suite* filter_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("filter");

    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, test_filter_dst_len_less_than_required_len);

    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_filter_one_even);
    tcase_add_test(tc_pos, test_filter_several_even);
    tcase_add_test(tc_pos, test_filter_all_even);
    tcase_add_test(tc_pos, test_filter_no_even);
    tcase_add_test(tc_pos, test_filter_all_zeros);
    tcase_add_test(tc_pos, test_filter_dst_len_more_than_required_len);

    suite_add_tcase(s, tc_pos);

    return s;
}





