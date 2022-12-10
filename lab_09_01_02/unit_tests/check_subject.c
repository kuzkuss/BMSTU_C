#include <stdlib.h>
#include "check_subject.h"

START_TEST(test_subject_read_negative_weight)
{
    FILE *f = fopen("unit_tests/f_in1.txt", "r");
    ck_assert_ptr_nonnull(f);

    struct subject_t *subject = NULL;

    int rc = subject_read(f, &subject);

    ck_assert_ptr_null(subject);
    ck_assert_int_eq(rc, INPUT_ERROR);
    fclose(f);
}
END_TEST


START_TEST(test_subject_read_negative_volume)
{
    FILE *f = fopen("unit_tests/f_in2.txt", "r");
    ck_assert_ptr_nonnull(f);

    struct subject_t *subject = NULL;

    int rc = subject_read(f, &subject);

    ck_assert_ptr_null(subject);
    ck_assert_int_eq(rc, INPUT_ERROR);
    fclose(f);
}
END_TEST

START_TEST(test_subject_read_incorrect_weight)
{
    FILE *f = fopen("unit_tests/f_in3.txt", "r");
    ck_assert_ptr_nonnull(f);

    struct subject_t *subject = NULL;

    int rc = subject_read(f, &subject);

    ck_assert_ptr_null(subject);
    ck_assert_int_eq(rc, INPUT_ERROR);
    fclose(f);
}
END_TEST


START_TEST(test_subject_read_incorrect_volume)
{
    FILE *f = fopen("unit_tests/f_in4.txt", "r");
    ck_assert_ptr_nonnull(f);

    struct subject_t *subject = NULL;

    int rc = subject_read(f, &subject);

    ck_assert_ptr_null(subject);
    ck_assert_int_eq(rc, INPUT_ERROR);
    fclose(f);
}
END_TEST

START_TEST(test_subject_read_empty_string)
{
    FILE *f = fopen("unit_tests/f_in5.txt", "r");
    ck_assert_ptr_nonnull(f);

    struct subject_t *subject = NULL;

    int rc = subject_read(f, &subject);

    ck_assert_ptr_null(subject);
    ck_assert_int_eq(rc, EMPTY_STRING);
    fclose(f);
}
END_TEST

START_TEST(test_subject_read_correct_record)
{
    FILE *f = fopen("unit_tests/f_in6.txt", "r");
    ck_assert_ptr_nonnull(f);

    struct subject_t *received_subject = NULL;

    struct subject_t expected_subject = {"pencil\n", 12.0, 20.0};

    int rc = subject_read(f, &received_subject);

    ck_assert_ptr_nonnull(received_subject);
    ck_assert_int_eq(rc, OK);
    ck_assert_str_eq(expected_subject.name, received_subject->name);
    ck_assert_double_eq_tol(expected_subject.weight, received_subject->weight, EPS);
    ck_assert_double_eq_tol(expected_subject.volume, received_subject->volume, EPS);
    free_subject(&received_subject);
    fclose(f);
}
END_TEST

Suite* subject_read_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("subject_read");

    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, test_subject_read_negative_weight);
    tcase_add_test(tc_neg, test_subject_read_negative_volume);
    tcase_add_test(tc_neg, test_subject_read_incorrect_weight);
    tcase_add_test(tc_neg, test_subject_read_incorrect_volume);
    tcase_add_test(tc_neg, test_subject_read_empty_string);

    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_subject_read_correct_record);

    suite_add_tcase(s, tc_pos);

    return s;
}

START_TEST(test_cmp_by_density_left_less_than_right)
{
    struct subject_t left_subject = {"pencil\n", 10.0, 20.0};
    struct subject_t right_subject = {"book\n", 12.0, 20.0};

    int res = cmp_by_density(&left_subject, &right_subject);

    ck_assert_int_lt(res, 0);
}
END_TEST

START_TEST(test_cmp_by_density_left_more_than_right)
{
    struct subject_t left_subject = {"pencil\n", 15.0, 20.0};
    struct subject_t right_subject = {"book\n", 12.0, 20.0};

    int res = cmp_by_density(&left_subject, &right_subject);

    ck_assert_int_lt(0, res);
}
END_TEST

START_TEST(test_cmp_by_density_left_equals_right)
{
    struct subject_t left_subject = {"pencil\n", 12.0, 20.0};
    struct subject_t right_subject = {"book\n", 12.0, 20.0};

    int res = cmp_by_density(&left_subject, &right_subject);

    ck_assert_int_eq(res, 0);
}
END_TEST

Suite* cmp_by_density_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("cmp_by_density");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_cmp_by_density_left_less_than_right);
    tcase_add_test(tc_pos, test_cmp_by_density_left_more_than_right);
    tcase_add_test(tc_pos, test_cmp_by_density_left_equals_right);

    suite_add_tcase(s, tc_pos);

    return s;
}

START_TEST(test_sub_copy_correct_data)
{
    struct subject_t dst_subject = {NULL, 0.0, 0.0};
    struct subject_t src_subject = {"book\n", 12.0, 20.0};

    int rc = sub_copy(&dst_subject, &src_subject);
    ck_assert_ptr_nonnull(dst_subject.name);
    ck_assert_str_eq(dst_subject.name, src_subject.name);
    ck_assert_double_eq_tol(dst_subject.weight, src_subject.weight, EPS);
    ck_assert_double_eq_tol(dst_subject.volume, src_subject.volume, EPS);
    ck_assert_int_eq(rc, OK);

    free(dst_subject.name);
}
END_TEST

Suite* sub_copy_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("sub_copy");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_sub_copy_correct_data);

    suite_add_tcase(s, tc_pos);

    return s;
}

