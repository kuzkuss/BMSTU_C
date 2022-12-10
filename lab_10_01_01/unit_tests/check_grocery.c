#include "check_grocery.h"

START_TEST(test_grocery_read_negative_price)
{
    FILE *f = fopen("unit_tests/f_in1.txt", "r");
    ck_assert_ptr_nonnull(f);

    grocery_t *grocery = grocery_read(f);
    ck_assert_ptr_null(grocery);

    fclose(f);
}
END_TEST

START_TEST(test_grocery_read_negative_amount)
{
    FILE *f = fopen("unit_tests/f_in2.txt", "r");
    ck_assert_ptr_nonnull(f);

    grocery_t *grocery = grocery_read(f);
    ck_assert_ptr_null(grocery);

    fclose(f);
}
END_TEST

START_TEST(test_grocery_read_invalid_price)
{
    FILE *f = fopen("unit_tests/f_in3.txt", "r");
    ck_assert_ptr_nonnull(f);

    grocery_t *grocery = grocery_read(f);
    ck_assert_ptr_null(grocery);

    fclose(f);
}
END_TEST

START_TEST(test_grocery_read_invalid_amount)
{
    FILE *f = fopen("unit_tests/f_in4.txt", "r");
    ck_assert_ptr_nonnull(f);

    grocery_t *grocery = grocery_read(f);
    ck_assert_ptr_null(grocery);

    fclose(f);
}
END_TEST

START_TEST(test_grocery_read_empty_name)
{
    FILE *f = fopen("unit_tests/f_in5.txt", "r");
    ck_assert_ptr_nonnull(f);

    grocery_t *grocery = grocery_read(f);
    ck_assert_ptr_null(grocery);

    fclose(f);
}
END_TEST

START_TEST(test_grocery_read_correct_data)
{
    FILE *f = fopen("unit_tests/f_in6.txt", "r");
    ck_assert_ptr_nonnull(f);

    grocery_t *grocery = grocery_read(f);
    ck_assert_ptr_nonnull(grocery);

    ck_assert_str_eq(grocery->name, "bread");
    ck_assert_double_eq_tol(grocery->price, 50.0, EPS);
    ck_assert_int_eq(grocery->amount, 2);

    free_grocery(grocery);

    fclose(f);
}
END_TEST

Suite *grocery_read_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("grocery_read");

    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, test_grocery_read_negative_price);
    tcase_add_test(tc_neg, test_grocery_read_negative_amount);
    tcase_add_test(tc_neg, test_grocery_read_invalid_price);
    tcase_add_test(tc_neg, test_grocery_read_invalid_amount);
    tcase_add_test(tc_neg, test_grocery_read_empty_name);

    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_grocery_read_correct_data);

    suite_add_tcase(s, tc_pos);

    return s;
}
