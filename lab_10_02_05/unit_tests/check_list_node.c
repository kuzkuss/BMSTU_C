#include "check_list_node.h"

START_TEST(test_create_node_full_array)
{
    char arr[SIZE] = {'a', 'b', 'c', 'd'};
    node_t *new_node = create_node(arr);
    ck_assert_ptr_nonnull(new_node);
    for (int i = 0; i < SIZE && arr[i]; ++i)
        ck_assert_int_eq(arr[i], new_node->arr[i]);
    free_node(new_node);
}
END_TEST

START_TEST(test_create_node_not_full_array)
{
    char arr[SIZE];
    arr[0] = 'a';
    arr[1] = '\0';
    node_t *new_node = create_node(arr);
    ck_assert_ptr_nonnull(new_node);
    for (int i = 0; i < SIZE && arr[i]; ++i)
        ck_assert_int_eq(arr[i], new_node->arr[i]);
    free_node(new_node);
}
END_TEST

Suite* create_node_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("create_node");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_create_node_full_array);
    tcase_add_test(tc_pos, test_create_node_not_full_array);

    suite_add_tcase(s, tc_pos);

    return s;
}


