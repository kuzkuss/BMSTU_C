#include <stdlib.h>
#include "check_list_node.h"
#include "check_grocery.h"

START_TEST(test_create_node_NULL_data)
{
    grocery_t *expected_data = NULL;

    node_t *node = create_node(expected_data);
    ck_assert_ptr_nonnull(node);

    grocery_t *received_data = node->data;
    ck_assert_ptr_null(received_data);

    free(node);
}
END_TEST

START_TEST(test_create_node_correct_data)
{
    grocery_t grocery = {"bread", 2, 50};
    grocery_t *expected_data = &grocery;

    node_t *node = create_node(expected_data);
    ck_assert_ptr_nonnull(node);

    grocery_t *received_data = node->data;
    ck_assert_str_eq(received_data->name, expected_data->name);
    ck_assert_double_eq_tol(received_data->price, expected_data->price, EPS);
    ck_assert_int_eq(received_data->amount, expected_data->amount);

    free(node);
}
END_TEST

Suite *create_node_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("create_node");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_create_node_NULL_data);
    tcase_add_test(tc_pos, test_create_node_correct_data);

    suite_add_tcase(s, tc_pos);

    return s;
}

START_TEST(test_compare_name_left_less_than_right)
{
    grocery_t left_grocery = {"bread", 2, 50.0};
    grocery_t right_grocery = {"milk", 1, 70.0};

    int res = compare_name(&left_grocery, &right_grocery);

    ck_assert_int_lt(res, 0);
}
END_TEST

START_TEST(test_compare_name_left_more_than_right)
{
    grocery_t left_grocery = {"milk", 2, 50.0};
    grocery_t right_grocery = {"bread", 1, 70.0};

    int res = compare_name(&left_grocery, &right_grocery);

    ck_assert_int_lt(0, res);
}
END_TEST

START_TEST(test_compare_name_left_equals_right)
{
    grocery_t left_grocery = {"bread", 2, 50.0};
    grocery_t right_grocery = {"bread", 1, 70.0};

    int res = compare_name(&left_grocery, &right_grocery);

    ck_assert_int_eq(res, 0);
}
END_TEST

Suite *compare_name_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("compare_name");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_compare_name_left_less_than_right);
    tcase_add_test(tc_pos, test_compare_name_left_more_than_right);
    tcase_add_test(tc_pos, test_compare_name_left_equals_right);

    suite_add_tcase(s, tc_pos);

    return s;
}

START_TEST(test_compare_price_left_less_than_right)
{
    grocery_t left_grocery = {"bread", 2, 50.0};
    grocery_t right_grocery = {"milk", 1, 70.0};

    int res = compare_price(&left_grocery, &right_grocery);

    ck_assert_int_lt(res, 0);
}
END_TEST

START_TEST(test_compare_price_left_more_than_right)
{
    grocery_t left_grocery = {"milk", 2, 70.0};
    grocery_t right_grocery = {"bread", 1, 50.0};

    int res = compare_price(&left_grocery, &right_grocery);

    ck_assert_int_lt(0, res);
}
END_TEST

START_TEST(test_compare_price_left_equals_right)
{
    grocery_t left_grocery = {"bread", 2, 50.0};
    grocery_t right_grocery = {"milk", 1, 50.0};

    int res = compare_price(&left_grocery, &right_grocery);

    ck_assert_int_eq(res, 0);
}
END_TEST

Suite *compare_price_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("compare_price");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_compare_price_left_less_than_right);
    tcase_add_test(tc_pos, test_compare_price_left_more_than_right);
    tcase_add_test(tc_pos, test_compare_price_left_equals_right);

    suite_add_tcase(s, tc_pos);

    return s;
}
