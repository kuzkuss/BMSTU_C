#include <stdlib.h>

struct subject_t
{
    char *name;
    double weight;
    double volume;
};

#include "check_subjects_array.h"

START_TEST(test_create_array_empty_file)
{
    FILE *f = fopen("unit_tests/f_in7.txt", "r");
    ck_assert_ptr_nonnull(f);

    int n = 0;

    struct subject_t **arr = create_array(f, &n);

    ck_assert_ptr_null(arr);
    ck_assert_int_eq(n, 0);

    fclose(f);
}
END_TEST


START_TEST(test_create_array_correct_data)
{
    FILE *f = fopen("unit_tests/f_in8.txt", "r");
    ck_assert_ptr_nonnull(f);

    int n = 0;

    struct subject_t **arr = create_array(f, &n);

    ck_assert_ptr_nonnull(arr);
    ck_assert_int_eq(n, 3);

    free(arr);
    fclose(f);
}
END_TEST

Suite* create_array_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("create_array");

    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, test_create_array_empty_file);

    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_create_array_correct_data);

    suite_add_tcase(s, tc_pos);

    return s;
}

START_TEST(test_sort_all_different)
{
    struct subject_t subject1 = {NULL, 12.0, 20.0};
    subject1.name = strdup("pencil\n");
    struct subject_t subject2 = {NULL, 20.0, 30.0};
    subject2.name = strdup("book\n");
    struct subject_t subject3 = {NULL, 50.0, 100.0};
    subject3.name = strdup("box\n");
    struct subject_t *array[3] = {&subject1, &subject2, &subject3};
    int n = 3;
    sort(array, n, cmp_by_density);

    ck_assert_str_eq(array[0]->name, "box\n");
    ck_assert_double_eq_tol(array[0]->weight, 50.0, EPS);
    ck_assert_double_eq_tol(array[0]->volume, 100.0, EPS);

    ck_assert_str_eq(array[1]->name, "pencil\n");
    ck_assert_double_eq_tol(array[1]->weight, 12.0, EPS);
    ck_assert_double_eq_tol(array[1]->volume, 20.0, EPS);

    ck_assert_str_eq(array[2]->name, "book\n");
    ck_assert_double_eq_tol(array[2]->weight, 20.0, EPS);
    ck_assert_double_eq_tol(array[2]->volume, 30.0, EPS);

    free(subject1.name);
    free(subject2.name);
    free(subject3.name);
}
END_TEST

START_TEST(test_sort_one_record)
{
    struct subject_t subject1 = {NULL, 12.0, 20.0};
    subject1.name = strdup("pencil\n");

    struct subject_t *array[1] = {&subject1};
    int n = 1;
    sort(array, n, cmp_by_density);

    ck_assert_str_eq(array[0]->name, "pencil\n");
    ck_assert_double_eq_tol(array[0]->weight, 12.0, EPS);
    ck_assert_double_eq_tol(array[0]->volume, 20.0, EPS);

    free(subject1.name);
}
END_TEST

START_TEST(test_sort_several_equal_records)
{
    struct subject_t subject1 = {NULL, 20.0, 30.0};
    subject1.name = strdup("book\n");
    struct subject_t subject2 = {NULL, 20.0, 30.0};
    subject2.name = strdup("book\n");
    struct subject_t subject3 = {NULL, 50.0, 100.0};
    subject3.name = strdup("box\n");
    struct subject_t *array[3] = {&subject1, &subject2, &subject3};
    int n = 3;
    sort(array, n, cmp_by_density);

    ck_assert_str_eq(array[0]->name, "box\n");
    ck_assert_double_eq_tol(array[0]->weight, 50.0, EPS);
    ck_assert_double_eq_tol(array[0]->volume, 100.0, EPS);

    ck_assert_str_eq(array[1]->name, "book\n");
    ck_assert_double_eq_tol(array[1]->weight, 20.0, EPS);
    ck_assert_double_eq_tol(array[1]->volume, 30.0, EPS);

    ck_assert_str_eq(array[2]->name, "book\n");
    ck_assert_double_eq_tol(array[2]->weight, 20.0, EPS);
    ck_assert_double_eq_tol(array[2]->volume, 30.0, EPS);

    free(subject1.name);
    free(subject2.name);
    free(subject3.name);
}
END_TEST

Suite* sort_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("sort");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_sort_all_different);
    tcase_add_test(tc_pos, test_sort_one_record);
    tcase_add_test(tc_pos, test_sort_several_equal_records);

    suite_add_tcase(s, tc_pos);

    return s;
}

