#include <stdlib.h>
#include "check_list.h"

int comp_int(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

START_TEST(test_read_list_one_element)
{
    FILE *f = fopen("unit_tests/f_in7.txt", "r");
    ck_assert_ptr_nonnull(f);

    node_t *list = read_list(f);
    ck_assert_ptr_nonnull(list);

    free_list(list);
    fclose(f);
}
END_TEST

START_TEST(test_read_list_many_elements)
{
    FILE *f = fopen("unit_tests/f_in8.txt", "r");
    ck_assert_ptr_nonnull(f);

    node_t *list = read_list(f);
    ck_assert_ptr_nonnull(list);

    free_list(list);
    fclose(f);
}
END_TEST

Suite *read_list_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("read_list");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_read_list_one_element);
    tcase_add_test(tc_pos, test_read_list_many_elements);

    suite_add_tcase(s, tc_pos);

    return s;
}

START_TEST(test_find_empty_list)
{
    node_t *list = NULL;
    grocery_t grocery = {"porridge", 2, 50};
    grocery_t *data = &grocery;

    node_t *found_node = find(list, data, compare_name);
    ck_assert_ptr_null(found_node);
}
END_TEST

START_TEST(test_find_no_sought_element)
{
    FILE *f = fopen("unit_tests/f_in8.txt", "r");
    ck_assert_ptr_nonnull(f);

    node_t *list = read_list(f);
    ck_assert_ptr_nonnull(list);

    grocery_t grocery = {"sgnstgb", 2, 50};
    grocery_t *data = &grocery;

    node_t *found_node = find(list, data, compare_name);
    ck_assert_ptr_null(found_node);

    free_list(list);

    fclose(f);
}
END_TEST

START_TEST(test_find_one_sought_element)
{
    FILE *f = fopen("unit_tests/f_in8.txt", "r");
    ck_assert_ptr_nonnull(f);

    node_t *list = read_list(f);
    ck_assert_ptr_nonnull(list);

    grocery_t grocery = {"porridge", 2, 50};
    grocery_t *expected_data = &grocery;

    node_t *found_node = find(list, expected_data, compare_name);
    ck_assert_ptr_nonnull(found_node);

    grocery_t *received_data = found_node->data;

    ck_assert_str_eq(received_data->name, expected_data->name);

    free_list(list);

    fclose(f);
}
END_TEST

START_TEST(test_find_many_sought_element)
{
    FILE *f = fopen("unit_tests/f_in8.txt", "r");
    ck_assert_ptr_nonnull(f);

    node_t *list = read_list(f);
    ck_assert_ptr_nonnull(list);

    grocery_t grocery = {"bread", 2, 50};
    grocery_t *expected_data = &grocery;

    node_t *found_node = find(list, expected_data, compare_name);
    ck_assert_ptr_nonnull(found_node);

    grocery_t *received_data = found_node->data;

    ck_assert_str_eq(received_data->name, expected_data->name);

    free_list(list);

    fclose(f);
}
END_TEST

Suite *find_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("find");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_find_empty_list);
    tcase_add_test(tc_pos, test_find_no_sought_element);
    tcase_add_test(tc_pos, test_find_one_sought_element);
    tcase_add_test(tc_pos, test_find_many_sought_element);

    suite_add_tcase(s, tc_pos);

    return s;
}

START_TEST(test_insert_null_head)
{
    node_t *list = NULL;
    grocery_t grocery = {"milk", 2, 50};
    grocery_t *data = &grocery;

    node_t *node = create_node(data);
    ck_assert_ptr_nonnull(node);

    node_t *before = NULL;

    insert(&list, node, before);
    ck_assert_ptr_null(list);

    free(node);
}
END_TEST

START_TEST(test_insert_null_element)
{
    FILE *f = fopen("unit_tests/f_in8.txt", "r");
    ck_assert_ptr_nonnull(f);

    node_t *list = read_list(f);
    ck_assert_ptr_nonnull(list);

    node_t *before = NULL;

    insert(&list, NULL, before);
    ck_assert_ptr_nonnull(list);

    free_list(list);

    fclose(f);
}
END_TEST

START_TEST(test_insert_null_before)
{
    FILE *f = fopen("unit_tests/f_in8.txt", "r");
    ck_assert_ptr_nonnull(f);

    node_t *list = read_list(f);
    ck_assert_ptr_nonnull(list);

    grocery_t grocery = {"milk", 2, 50};
    grocery_t *data = &grocery;

    node_t *node = create_node(data);
    ck_assert_ptr_nonnull(node);

    insert(&list, node, NULL);
    ck_assert_ptr_nonnull(list);

    free_list(list);
    free(node);

    fclose(f);
}
END_TEST

START_TEST(test_insert_no_before_in_list)
{
    FILE *f = fopen("unit_tests/f_in8.txt", "r");
    ck_assert_ptr_nonnull(f);

    node_t *list = read_list(f);
    ck_assert_ptr_nonnull(list);

    grocery_t grocery = {"milk", 2, 50};
    grocery_t *data = &grocery;

    node_t *node = create_node(data);
    ck_assert_ptr_nonnull(node);

    node_t *before = node;

    insert(&list, node, before);
    ck_assert_ptr_nonnull(list);

    free_list(list);
    free(node);

    fclose(f);
}
END_TEST

START_TEST(test_insert_at_the_beginning)
{
    FILE *f = fopen("unit_tests/f_in8.txt", "r");
    ck_assert_ptr_nonnull(f);

    node_t *list = read_list(f);
    ck_assert_ptr_nonnull(list);

    grocery_t grocery = {"milk", 2, 50};
    grocery_t *data = grocery_create(grocery.name, grocery.amount, grocery.price);
    ck_assert_ptr_nonnull(data);

    node_t *node = create_node(data);
    ck_assert_ptr_nonnull(node);

    node_t *before = list;

    insert(&list, node, before);
    ck_assert_ptr_nonnull(list);

    free_list(list);

    fclose(f);
}
END_TEST

START_TEST(test_insert_at_the_end)
{
    FILE *f = fopen("unit_tests/f_in8.txt", "r");
    ck_assert_ptr_nonnull(f);

    node_t *list = read_list(f);
    ck_assert_ptr_nonnull(list);

    grocery_t grocery = {"milk", 2, 50};
    grocery_t *data = grocery_create(grocery.name, grocery.amount, grocery.price);
    ck_assert_ptr_nonnull(data);

    node_t *node = create_node(data);
    ck_assert_ptr_nonnull(node);

    node_t *before = list;
    while (before->next)
        before = before->next;

    insert(&list, node, before);
    ck_assert_ptr_nonnull(list);

    free_list(list);

    fclose(f);
}
END_TEST

START_TEST(test_insert_in_the_middle)
{
    FILE *f = fopen("unit_tests/f_in8.txt", "r");
    ck_assert_ptr_nonnull(f);

    node_t *list = read_list(f);
    ck_assert_ptr_nonnull(list);

    grocery_t grocery = {"milk", 2, 50};
    grocery_t *data = grocery_create(grocery.name, grocery.amount, grocery.price);
    ck_assert_ptr_nonnull(data);

    node_t *node = create_node(data);
    ck_assert_ptr_nonnull(node);

    node_t *before = list;
    before = before->next;

    insert(&list, node, before);
    ck_assert_ptr_nonnull(list);

    free_list(list);

    fclose(f);
}
END_TEST

Suite *insert_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("insert");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_insert_null_head);
    tcase_add_test(tc_pos, test_insert_null_element);
    tcase_add_test(tc_pos, test_insert_null_before);
    tcase_add_test(tc_pos, test_insert_no_before_in_list);
    tcase_add_test(tc_pos, test_insert_at_the_beginning);
    tcase_add_test(tc_pos, test_insert_at_the_end);
    tcase_add_test(tc_pos, test_insert_in_the_middle);

    suite_add_tcase(s, tc_pos);

    return s;
}

START_TEST(test_reverse_empty_list)
{
    node_t *list = NULL;

    list = reverse(list);
    ck_assert_ptr_null(list);
}
END_TEST

START_TEST(test_reverse_one_element)
{
    FILE *f = fopen("unit_tests/f_in7.txt", "r");
    ck_assert_ptr_nonnull(f);

    node_t *list = read_list(f);
    ck_assert_ptr_nonnull(list);

    list = reverse(list);
    ck_assert_ptr_nonnull(list);

    ck_assert_ptr_null(list->next);

    free_list(list);

    fclose(f);
}
END_TEST

START_TEST(test_reverse_many_elements)
{
    FILE *f = fopen("unit_tests/f_in8.txt", "r");
    ck_assert_ptr_nonnull(f);

    node_t *list = read_list(f);
    ck_assert_ptr_nonnull(list);

    list = reverse(list);
    ck_assert_ptr_nonnull(list);

    ck_assert_ptr_nonnull(list->next);

    free_list(list);

    fclose(f);
}
END_TEST

Suite *reverse_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("reverse");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_reverse_empty_list);
    tcase_add_test(tc_pos, test_reverse_one_element);
    tcase_add_test(tc_pos, test_reverse_many_elements);

    suite_add_tcase(s, tc_pos);

    return s;
}

START_TEST(test_sorted_merge_empty_first_list)
{
    node_t *first_list = NULL;

    int arr[5] = {5, 4, 3, 2, 1};

    node_t *second_list = create_node(&arr[0]);
    ck_assert_ptr_nonnull(second_list);

    node_t *new_node = create_node(&arr[1]);
    ck_assert_ptr_nonnull(new_node);
    second_list = add(new_node, second_list);
    ck_assert_ptr_nonnull(second_list);

    new_node = create_node(&arr[2]);
    ck_assert_ptr_nonnull(new_node);
    second_list = add(new_node, second_list);
    ck_assert_ptr_nonnull(second_list);

    new_node = create_node(&arr[3]);
    ck_assert_ptr_nonnull(new_node);
    second_list = add(new_node, second_list);
    ck_assert_ptr_nonnull(second_list);

    new_node = create_node(&arr[4]);
    ck_assert_ptr_nonnull(new_node);
    second_list = add(new_node, second_list);
    ck_assert_ptr_nonnull(second_list);

    node_t *result = sorted_merge(&first_list, &second_list, comp_int);
    ck_assert_ptr_nonnull(result);

    node_t *next = NULL;
    for (int i = 0; i < 5; ++i)
    {
        next = result->next;
        ck_assert_int_eq(arr[4 - i], *(int *)result->data);
        free(result);
        result = next;
    }
    ck_assert_ptr_null(result);
}
END_TEST

START_TEST(test_sorted_merge_empty_second_list)
{
    node_t *second_list = NULL;

    int arr[5] = {5, 4, 3, 2, 1};

    node_t *first_list = create_node(&arr[0]);
    ck_assert_ptr_nonnull(first_list);

    node_t *new_node = create_node(&arr[1]);
    ck_assert_ptr_nonnull(new_node);
    first_list = add(new_node, first_list);
    ck_assert_ptr_nonnull(first_list);

    new_node = create_node(&arr[2]);
    ck_assert_ptr_nonnull(new_node);
    first_list = add(new_node, first_list);
    ck_assert_ptr_nonnull(first_list);

    new_node = create_node(&arr[3]);
    ck_assert_ptr_nonnull(new_node);
    first_list = add(new_node, first_list);
    ck_assert_ptr_nonnull(first_list);

    new_node = create_node(&arr[4]);
    ck_assert_ptr_nonnull(new_node);
    first_list = add(new_node, first_list);
    ck_assert_ptr_nonnull(first_list);

    node_t *result = sorted_merge(&first_list, &second_list, comp_int);
    ck_assert_ptr_nonnull(result);

    node_t *next = NULL;
    for (int i = 0; i < 5; ++i)
    {
        next = result->next;
        ck_assert_int_eq(arr[4 - i], *(int *)result->data);
        free(result);
        result = next;
    }
    ck_assert_ptr_null(result);
}
END_TEST

START_TEST(test_sorted_merge_empty_both_lists)
{
    node_t *first_list = NULL;
    node_t *second_list = NULL;

    node_t *result = sorted_merge(&first_list, &second_list, comp_int);
    ck_assert_ptr_null(result);
}
END_TEST

START_TEST(test_sorted_merge_elements_of_first_list_less_than_second)
{
    int arr1[5] = {5, 4, 3, 2, 1};
    int arr2[5] = {10, 9, 8, 7, 6};
    int res[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    node_t *first_list = create_node(&arr1[0]);
    ck_assert_ptr_nonnull(first_list);

    node_t *new_node = create_node(&arr1[1]);
    ck_assert_ptr_nonnull(new_node);
    first_list = add(new_node, first_list);
    ck_assert_ptr_nonnull(first_list);

    new_node = create_node(&arr1[2]);
    ck_assert_ptr_nonnull(new_node);
    first_list = add(new_node, first_list);
    ck_assert_ptr_nonnull(first_list);

    new_node = create_node(&arr1[3]);
    ck_assert_ptr_nonnull(new_node);
    first_list = add(new_node, first_list);
    ck_assert_ptr_nonnull(first_list);

    new_node = create_node(&arr1[4]);
    ck_assert_ptr_nonnull(new_node);
    first_list = add(new_node, first_list);
    ck_assert_ptr_nonnull(first_list);


    node_t *second_list = create_node(&arr2[0]);
    ck_assert_ptr_nonnull(second_list);

    new_node = create_node(&arr2[1]);
    ck_assert_ptr_nonnull(new_node);
    second_list = add(new_node, second_list);
    ck_assert_ptr_nonnull(second_list);

    new_node = create_node(&arr2[2]);
    ck_assert_ptr_nonnull(new_node);
    second_list = add(new_node, second_list);
    ck_assert_ptr_nonnull(second_list);

    new_node = create_node(&arr2[3]);
    ck_assert_ptr_nonnull(new_node);
    second_list = add(new_node, second_list);
    ck_assert_ptr_nonnull(second_list);

    new_node = create_node(&arr2[4]);
    ck_assert_ptr_nonnull(new_node);
    second_list = add(new_node, second_list);
    ck_assert_ptr_nonnull(second_list);

    node_t *result = sorted_merge(&first_list, &second_list, comp_int);
    ck_assert_ptr_nonnull(result);

    node_t *next = NULL;
    for (int i = 0; i < 10; ++i)
    {
        next = result->next;
        ck_assert_int_eq(res[i], *(int *)result->data);
        free(result);
        result = next;
    }
    ck_assert_ptr_null(result);
}
END_TEST

START_TEST(test_sorted_merge_elements_of_second_list_less_than_first)
{
    int arr1[5] = {5, 4, 3, 2, 1};
    int arr2[5] = {10, 9, 8, 7, 6};
    int res[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    node_t *first_list = create_node(&arr2[0]);
    ck_assert_ptr_nonnull(first_list);

    node_t *new_node = create_node(&arr2[1]);
    ck_assert_ptr_nonnull(new_node);
    first_list = add(new_node, first_list);
    ck_assert_ptr_nonnull(first_list);

    new_node = create_node(&arr2[2]);
    ck_assert_ptr_nonnull(new_node);
    first_list = add(new_node, first_list);
    ck_assert_ptr_nonnull(first_list);

    new_node = create_node(&arr2[3]);
    ck_assert_ptr_nonnull(new_node);
    first_list = add(new_node, first_list);
    ck_assert_ptr_nonnull(first_list);

    new_node = create_node(&arr2[4]);
    ck_assert_ptr_nonnull(new_node);
    first_list = add(new_node, first_list);
    ck_assert_ptr_nonnull(first_list);


    node_t *second_list = create_node(&arr1[0]);
    ck_assert_ptr_nonnull(second_list);

    new_node = create_node(&arr1[1]);
    ck_assert_ptr_nonnull(new_node);
    second_list = add(new_node, second_list);
    ck_assert_ptr_nonnull(second_list);

    new_node = create_node(&arr1[2]);
    ck_assert_ptr_nonnull(new_node);
    second_list = add(new_node, second_list);
    ck_assert_ptr_nonnull(second_list);

    new_node = create_node(&arr1[3]);
    ck_assert_ptr_nonnull(new_node);
    second_list = add(new_node, second_list);
    ck_assert_ptr_nonnull(second_list);

    new_node = create_node(&arr1[4]);
    ck_assert_ptr_nonnull(new_node);
    second_list = add(new_node, second_list);
    ck_assert_ptr_nonnull(second_list);

    node_t *result = sorted_merge(&first_list, &second_list, comp_int);
    ck_assert_ptr_nonnull(result);

    node_t *next = NULL;
    for (int i = 0; i < 10; ++i)
    {
        next = result->next;
        ck_assert_int_eq(res[i], *(int *)result->data);
        free(result);
        result = next;
    }
    ck_assert_ptr_null(result);
}
END_TEST

START_TEST(test_sorted_merge_similar_elements_in_both_lists)
{
    int arr1[5] = {8, 2, 2, 2, 1};
    int arr2[5] = {10, 10, 5, 4, 3};
    int res[10] = {1, 2, 2, 2, 3, 4, 5, 8, 10, 10};

    node_t *first_list = create_node(&arr1[0]);
    ck_assert_ptr_nonnull(first_list);

    node_t *new_node = create_node(&arr1[1]);
    ck_assert_ptr_nonnull(new_node);
    first_list = add(new_node, first_list);
    ck_assert_ptr_nonnull(first_list);

    new_node = create_node(&arr1[2]);
    ck_assert_ptr_nonnull(new_node);
    first_list = add(new_node, first_list);
    ck_assert_ptr_nonnull(first_list);

    new_node = create_node(&arr1[3]);
    ck_assert_ptr_nonnull(new_node);
    first_list = add(new_node, first_list);
    ck_assert_ptr_nonnull(first_list);

    new_node = create_node(&arr1[4]);
    ck_assert_ptr_nonnull(new_node);
    first_list = add(new_node, first_list);
    ck_assert_ptr_nonnull(first_list);


    node_t *second_list = create_node(&arr2[0]);
    ck_assert_ptr_nonnull(second_list);

    new_node = create_node(&arr2[1]);
    ck_assert_ptr_nonnull(new_node);
    second_list = add(new_node, second_list);
    ck_assert_ptr_nonnull(second_list);

    new_node = create_node(&arr2[2]);
    ck_assert_ptr_nonnull(new_node);
    second_list = add(new_node, second_list);
    ck_assert_ptr_nonnull(second_list);

    new_node = create_node(&arr2[3]);
    ck_assert_ptr_nonnull(new_node);
    second_list = add(new_node, second_list);
    ck_assert_ptr_nonnull(second_list);

    new_node = create_node(&arr2[4]);
    ck_assert_ptr_nonnull(new_node);
    second_list = add(new_node, second_list);
    ck_assert_ptr_nonnull(second_list);

    node_t *result = sorted_merge(&first_list, &second_list, comp_int);
    ck_assert_ptr_nonnull(result);

    node_t *next = NULL;
    for (int i = 0; i < 10; ++i)
    {
        next = result->next;
        ck_assert_int_eq(res[i], *(int *)result->data);
        free(result);
        result = next;
    }
    ck_assert_ptr_null(result);
}
END_TEST

START_TEST(test_sorted_merge_different_elements)
{
    int arr1[5] = {9, 8, 6, 2, 1};
    int arr2[5] = {10, 7, 5, 4, 3};
    int res[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    node_t *first_list = create_node(&arr1[0]);
    ck_assert_ptr_nonnull(first_list);

    node_t *new_node = create_node(&arr1[1]);
    ck_assert_ptr_nonnull(new_node);
    first_list = add(new_node, first_list);
    ck_assert_ptr_nonnull(first_list);

    new_node = create_node(&arr1[2]);
    ck_assert_ptr_nonnull(new_node);
    first_list = add(new_node, first_list);
    ck_assert_ptr_nonnull(first_list);

    new_node = create_node(&arr1[3]);
    ck_assert_ptr_nonnull(new_node);
    first_list = add(new_node, first_list);
    ck_assert_ptr_nonnull(first_list);

    new_node = create_node(&arr1[4]);
    ck_assert_ptr_nonnull(new_node);
    first_list = add(new_node, first_list);
    ck_assert_ptr_nonnull(first_list);


    node_t *second_list = create_node(&arr2[0]);
    ck_assert_ptr_nonnull(second_list);

    new_node = create_node(&arr2[1]);
    ck_assert_ptr_nonnull(new_node);
    second_list = add(new_node, second_list);
    ck_assert_ptr_nonnull(second_list);

    new_node = create_node(&arr2[2]);
    ck_assert_ptr_nonnull(new_node);
    second_list = add(new_node, second_list);
    ck_assert_ptr_nonnull(second_list);

    new_node = create_node(&arr2[3]);
    ck_assert_ptr_nonnull(new_node);
    second_list = add(new_node, second_list);
    ck_assert_ptr_nonnull(second_list);

    new_node = create_node(&arr2[4]);
    ck_assert_ptr_nonnull(new_node);
    second_list = add(new_node, second_list);
    ck_assert_ptr_nonnull(second_list);

    node_t *result = sorted_merge(&first_list, &second_list, comp_int);
    ck_assert_ptr_nonnull(result);

    node_t *next = NULL;
    for (int i = 0; i < 10; ++i)
    {
        next = result->next;
        ck_assert_int_eq(res[i], *(int *)result->data);
        free(result);
        result = next;
    }
    ck_assert_ptr_null(result);
}
END_TEST

Suite *sorted_merge_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("sorted_merge");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_sorted_merge_empty_first_list);
    tcase_add_test(tc_pos, test_sorted_merge_empty_second_list);
    tcase_add_test(tc_pos, test_sorted_merge_empty_both_lists);
    tcase_add_test(tc_pos, test_sorted_merge_elements_of_first_list_less_than_second);
    tcase_add_test(tc_pos, test_sorted_merge_elements_of_second_list_less_than_first);
    tcase_add_test(tc_pos, test_sorted_merge_similar_elements_in_both_lists);
    tcase_add_test(tc_pos, test_sorted_merge_different_elements);

    suite_add_tcase(s, tc_pos);

    return s;
}


START_TEST(test_sort_empty_list)
{
    node_t *list = NULL;

    list = sort(list, compare_price);
    ck_assert_ptr_null(list);
}
END_TEST

START_TEST(test_sort_one_element)
{
    FILE *f = fopen("unit_tests/f_in7.txt", "r");
    ck_assert_ptr_nonnull(f);

    node_t *list = read_list(f);
    ck_assert_ptr_nonnull(list);

    list = sort(list, compare_price);
    ck_assert_ptr_nonnull(list);

    ck_assert_ptr_null(list->next);

    free_list(list);

    fclose(f);
}
END_TEST

START_TEST(test_sort_several_similar_elements)
{
    FILE *f = fopen("unit_tests/f_in8.txt", "r");
    ck_assert_ptr_nonnull(f);

    node_t *list = read_list(f);
    ck_assert_ptr_nonnull(list);

    list = sort(list, compare_price);
    ck_assert_ptr_nonnull(list);

    ck_assert_ptr_nonnull(list->next);

    free_list(list);

    fclose(f);
}
END_TEST

START_TEST(test_sort_many_defferent_elements)
{
    FILE *f = fopen("unit_tests/f_in9.txt", "r");
    ck_assert_ptr_nonnull(f);

    node_t *list = read_list(f);
    ck_assert_ptr_nonnull(list);

    list = sort(list, compare_price);
    ck_assert_ptr_nonnull(list);

    ck_assert_ptr_nonnull(list->next);

    free_list(list);

    fclose(f);
}
END_TEST

Suite *sort_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("sort");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_sort_empty_list);
    tcase_add_test(tc_pos, test_sort_one_element);
    tcase_add_test(tc_pos, test_sort_several_similar_elements);
    tcase_add_test(tc_pos, test_sort_many_defferent_elements);

    suite_add_tcase(s, tc_pos);

    return s;
}
