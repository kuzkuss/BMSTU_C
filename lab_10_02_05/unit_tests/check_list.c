#include "check_list.h"

START_TEST(test_concatenation_first_line_empty)
{
    char arr1[SIZE] = {'\0'};
    node_t *first_str = create_node(arr1);
    ck_assert_ptr_nonnull(first_str);
    char arr2[SIZE] = {'a', 'b', 'c', '\0'};
    node_t *second_str = create_node(arr2);
    ck_assert_ptr_nonnull(second_str);

    node_t *result = concatenation(first_str, second_str);

    ck_assert_ptr_nonnull(result);

    for (int i = 0; i < SIZE; ++i)
        ck_assert_int_eq(result->arr[i], arr2[i]);

    ck_assert_ptr_null(result->next);

    free_list(first_str);
}
END_TEST

START_TEST(test_concatenation_second_line_empty)
{
    char arr1[SIZE] = {'a', 'b', 'c', '\0'};
    node_t *first_str = create_node(arr1);
    char arr2[SIZE] = {'\0'};
    node_t *second_str = create_node(arr2);

    node_t *result = concatenation(first_str, second_str);

    ck_assert_ptr_nonnull(result);

    for (int i = 0; i < SIZE; ++i)
        ck_assert_int_eq(result->arr[i], first_str->arr[i]);

    ck_assert_ptr_null(result->next);

    free_list(first_str);
}
END_TEST

START_TEST(test_concatenation_all_arrays_are_full)
{
    char arr1[SIZE] = {'a', 'b', 'c', 'd'};
    char arr2[SIZE] = {'e', 'f', 'g', 'h'};
    char arr3[SIZE] = {'i', 'j', 'k', '\0'};

    node_t *first_str = create_node(arr1);
    ck_assert_ptr_nonnull(first_str);

    node_t *new_node = create_node(arr2);
    ck_assert_ptr_nonnull(new_node);
    first_str = add_node(new_node, first_str);
    ck_assert_ptr_nonnull(first_str);

    new_node = create_node(arr3);
    ck_assert_ptr_nonnull(new_node);
    first_str = add_node(new_node, first_str);
    ck_assert_ptr_nonnull(first_str);

    node_t *second_str = create_node(arr1);
    ck_assert_ptr_nonnull(second_str);

    new_node = create_node(arr2);
    ck_assert_ptr_nonnull(new_node);
    second_str = add_node(new_node, second_str);
    ck_assert_ptr_nonnull(second_str);

    new_node = create_node(arr3);
    ck_assert_ptr_nonnull(new_node);
    second_str = add_node(new_node, second_str);
    ck_assert_ptr_nonnull(second_str);

    node_t *result = concatenation(first_str, second_str);

    ck_assert_ptr_nonnull(result);

    char res[SIZE_RES] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', '\0'};

    for (int j = 0; j < 6; ++j)
    {
        for (int i = 0; i < SIZE && result->arr[i]; ++i)
            ck_assert_int_eq(result->arr[i], res[j * SIZE + i]);
        result = result->next;
    }

    ck_assert_ptr_null(result);

    free_list(first_str);
}
END_TEST

START_TEST(test_concatenation_last_array_is_half_full)
{
    char arr1[SIZE] = {'a', 'b', 'c', 'd'};
    char arr2[SIZE] = {'e', 'f', 'g', 'h'};
    char arr3[SIZE] = {'i', '\0'};

    node_t *first_str = create_node(arr1);
    ck_assert_ptr_nonnull(first_str);

    node_t *new_node = create_node(arr2);
    ck_assert_ptr_nonnull(new_node);
    first_str = add_node(new_node, first_str);
    ck_assert_ptr_nonnull(first_str);

    new_node = create_node(arr3);
    ck_assert_ptr_nonnull(new_node);
    first_str = add_node(new_node, first_str);
    ck_assert_ptr_nonnull(first_str);

    node_t *second_str = create_node(arr1);
    ck_assert_ptr_nonnull(second_str);

    new_node = create_node(arr2);
    ck_assert_ptr_nonnull(new_node);
    second_str = add_node(new_node, second_str);
    ck_assert_ptr_nonnull(second_str);

    new_node = create_node(arr3);
    ck_assert_ptr_nonnull(new_node);
    second_str = add_node(new_node, second_str);
    ck_assert_ptr_nonnull(second_str);

    node_t *result = concatenation(first_str, second_str);

    ck_assert_ptr_nonnull(result);

    char res[SIZE_RES - 4] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', '\0'};

    for (int j = 0; j < 5; ++j)
    {
        for (int i = 0; i < SIZE && result->arr[i]; ++i)
            ck_assert_int_eq(result->arr[i], res[j * SIZE + i]);
        result = result->next;
    }

    ck_assert_ptr_null(result);

    free_list(first_str);

}
END_TEST

Suite* concatenation_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("concatenation");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_concatenation_first_line_empty);
    tcase_add_test(tc_pos, test_concatenation_second_line_empty);
    tcase_add_test(tc_pos, test_concatenation_all_arrays_are_full);
    tcase_add_test(tc_pos, test_concatenation_last_array_is_half_full);

    suite_add_tcase(s, tc_pos);

    return s;
}

START_TEST(test_del_spaces_no_spaces)
{
    char arr1[SIZE] = {'a', 'b', 'c', 'd'};
    char arr2[SIZE] = {'e', 'f', 'g', 'h'};
    char arr3[SIZE] = {'i', 'j', 'k', '\0'};

    node_t *string = create_node(arr1);
    ck_assert_ptr_nonnull(string);

    node_t *new_node = create_node(arr2);
    ck_assert_ptr_nonnull(new_node);
    string = add_node(new_node, string);
    ck_assert_ptr_nonnull(string);

    new_node = create_node(arr3);
    ck_assert_ptr_nonnull(new_node);
    string = add_node(new_node, string);
    ck_assert_ptr_nonnull(string);


    node_t *result = del_spaces(string);

    ck_assert_ptr_nonnull(result);

    char res[12] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', '\0'};

    for (int j = 0; j < 3; ++j)
    {
        for (int i = 0; i < SIZE; ++i)
            ck_assert_int_eq(result->arr[i], res[j * SIZE + i]);
        result = result->next;
    }

    ck_assert_ptr_null(result);

    free_list(string);
}
END_TEST

START_TEST(test_del_spaces_no_double_spaces)
{
    char arr1[SIZE] = {'a', 'b', ' ', 'd'};
    char arr2[SIZE] = {'e', 'f', ' ', 'h'};
    char arr3[SIZE] = {'i', ' ', 'k', '\0'};

    node_t *string = create_node(arr1);
    ck_assert_ptr_nonnull(string);

    node_t *new_node = create_node(arr2);
    ck_assert_ptr_nonnull(new_node);
    string = add_node(new_node, string);
    ck_assert_ptr_nonnull(string);

    new_node = create_node(arr3);
    ck_assert_ptr_nonnull(new_node);
    string = add_node(new_node, string);
    ck_assert_ptr_nonnull(string);


    node_t *result = del_spaces(string);

    ck_assert_ptr_nonnull(result);

    char res[12] = {'a', 'b', ' ', 'd', 'e', 'f', ' ', 'h', 'i', ' ', 'k', '\0'};

    for (int j = 0; j < 3; ++j)
    {
        for (int i = 0; i < SIZE; ++i)
            ck_assert_int_eq(result->arr[i], res[j * SIZE + i]);
        result = result->next;
    }

    ck_assert_ptr_null(result);

    free_list(string);
}
END_TEST

START_TEST(test_del_spaces_once_multiple_spaces)
{
    char arr1[SIZE] = {'a', ' ', ' ', ' '};
    char arr2[SIZE] = {'e', 'f', 'g', 'h'};
    char arr3[SIZE] = {'i', 'j', 'k', '\0'};

    node_t *string = create_node(arr1);
    ck_assert_ptr_nonnull(string);

    node_t *new_node = create_node(arr2);
    ck_assert_ptr_nonnull(new_node);
    string = add_node(new_node, string);
    ck_assert_ptr_nonnull(string);

    new_node = create_node(arr3);
    ck_assert_ptr_nonnull(new_node);
    string = add_node(new_node, string);
    ck_assert_ptr_nonnull(string);


    node_t *result = del_spaces(string);

    ck_assert_ptr_nonnull(result);

    char res[10] = {'a', ' ', 'e', 'f', 'g', 'h', 'i', 'j', 'k', '\0'};

    for (int j = 0; j < 3; ++j)
    {
        for (int i = 0; i < SIZE && result->arr[i]; ++i)
            ck_assert_int_eq(result->arr[i], res[j * SIZE + i]);
        result = result->next;
    }

    ck_assert_ptr_null(result);

    free_list(string);
}
END_TEST

START_TEST(test_del_spaces_many_spaces_at_the_beginning)
{
    char arr1[SIZE] = {' ', ' ', ' ', ' '};
    char arr2[SIZE] = {'e', 'f', 'g', 'h'};
    char arr3[SIZE] = {'i', 'j', 'k', '\0'};

    node_t *string = create_node(arr1);
    ck_assert_ptr_nonnull(string);

    node_t *new_node = create_node(arr2);
    ck_assert_ptr_nonnull(new_node);
    string = add_node(new_node, string);
    ck_assert_ptr_nonnull(string);

    new_node = create_node(arr3);
    ck_assert_ptr_nonnull(new_node);
    string = add_node(new_node, string);
    ck_assert_ptr_nonnull(string);


    node_t *result = del_spaces(string);

    ck_assert_ptr_nonnull(result);

    char res[9] = {' ', 'e', 'f', 'g', 'h', 'i', 'j', 'k', '\0'};

    for (int j = 0; j < 3; ++j)
    {
        for (int i = 0; i < SIZE && result->arr[i]; ++i)
            ck_assert_int_eq(result->arr[i], res[j * SIZE + i]);
        result = result->next;
    }

    ck_assert_ptr_null(result);

    free_list(string);
}
END_TEST

START_TEST(test_del_spaces_many_spaces_at_the_end)
{
    char arr1[SIZE] = {'a', 'b', 'c', 'd'};
    char arr2[SIZE] = {'e', 'f', 'g', 'h'};
    char arr3[SIZE] = {' ', ' ', ' ', '\0'};

    node_t *string = create_node(arr1);
    ck_assert_ptr_nonnull(string);

    node_t *new_node = create_node(arr2);
    ck_assert_ptr_nonnull(new_node);
    string = add_node(new_node, string);
    ck_assert_ptr_nonnull(string);

    new_node = create_node(arr3);
    ck_assert_ptr_nonnull(new_node);
    string = add_node(new_node, string);
    ck_assert_ptr_nonnull(string);


    node_t *result = del_spaces(string);

    ck_assert_ptr_nonnull(result);

    char res[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', ' ', '\0'};

    for (int j = 0; j < 3; ++j)
    {
        for (int i = 0; i < SIZE && result->arr[i]; ++i)
            ck_assert_int_eq(result->arr[i], res[j * SIZE + i]);
        result = result->next;
    }

    ck_assert_ptr_null(result);

    free_list(string);
}
END_TEST

START_TEST(test_del_spaces_all_spaces_are_doubled)
{
    char arr1[SIZE] = {'a', 'b', ' ', ' '};
    char arr2[SIZE] = {'e', ' ', ' ', 'h'};
    char arr3[SIZE] = {'i', ' ', ' ', '\0'};

    node_t *string = create_node(arr1);
    ck_assert_ptr_nonnull(string);

    node_t *new_node = create_node(arr2);
    ck_assert_ptr_nonnull(new_node);
    string = add_node(new_node, string);
    ck_assert_ptr_nonnull(string);

    new_node = create_node(arr3);
    ck_assert_ptr_nonnull(new_node);
    string = add_node(new_node, string);
    ck_assert_ptr_nonnull(string);


    node_t *result = del_spaces(string);

    ck_assert_ptr_nonnull(result);

    char res[9] = {'a', 'b', ' ', 'e', ' ', 'h', 'i', ' ', '\0'};

    for (int j = 0; j < 3; ++j)
    {
        for (int i = 0; i < SIZE && result->arr[i]; ++i)
            ck_assert_int_eq(result->arr[i], res[j * SIZE + i]);
        result = result->next;
    }

    ck_assert_ptr_null(result);

    free_list(string);
}
END_TEST

START_TEST(test_del_spaces_empty_string)
{
    char arr[SIZE] = {'\0'};

    node_t *string = create_node(arr);
    ck_assert_ptr_nonnull(string);

    node_t *result = del_spaces(string);

    ck_assert_ptr_nonnull(result);

    ck_assert_int_eq(result->arr[0], arr[0]);

    ck_assert_ptr_null(result->next);

    free_list(string);
}
END_TEST

Suite* del_spaces_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("del_spaces");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_del_spaces_no_spaces);
    tcase_add_test(tc_pos, test_del_spaces_no_double_spaces);
    tcase_add_test(tc_pos, test_del_spaces_once_multiple_spaces);
    tcase_add_test(tc_pos, test_del_spaces_many_spaces_at_the_beginning);
    tcase_add_test(tc_pos, test_del_spaces_many_spaces_at_the_end);
    tcase_add_test(tc_pos, test_del_spaces_all_spaces_are_doubled);
    tcase_add_test(tc_pos, test_del_spaces_empty_string);

    suite_add_tcase(s, tc_pos);

    return s;
}

START_TEST(test_my_strstr_empty_source_string)
{
    char arr1[SIZE] = {'\0'};
    node_t *src_str = create_node(arr1);
    ck_assert_ptr_nonnull(src_str);
    char arr2[SIZE] = {'a', 'b', 'c', '\0'};
    node_t *req_str = create_node(arr2);
    ck_assert_ptr_nonnull(req_str);

    int pos = my_strstr(src_str, req_str);

    ck_assert_int_eq(pos, -1);

    free_list(src_str);
    free_list(req_str);
}
END_TEST

START_TEST(test_my_strstr_empty_substring)
{
    char arr1[SIZE] = {'a', 'b', 'c', '\0'};
    node_t *src_str = create_node(arr1);
    ck_assert_ptr_nonnull(src_str);
    char arr2[SIZE] = {'\0'};
    node_t *req_str = create_node(arr2);
    ck_assert_ptr_nonnull(req_str);

    int pos = my_strstr(src_str, req_str);

    ck_assert_int_eq(pos, -1);

    free_list(src_str);
    free_list(req_str);
}
END_TEST

START_TEST(test_my_strstr_no_substring)
{
    char arr1[SIZE] = {'a', 'b', 'c', '\0'};
    node_t *src_str = create_node(arr1);
    ck_assert_ptr_nonnull(src_str);
    char arr2[SIZE] = {'d', '\0'};
    node_t *req_str = create_node(arr2);
    ck_assert_ptr_nonnull(req_str);

    int pos = my_strstr(src_str, req_str);

    ck_assert_int_eq(pos, -1);

    free_list(src_str);
    free_list(req_str);
}
END_TEST

START_TEST(test_my_strstr_substring_at_the_beginning_of_string)
{
    char arr1[SIZE] = {'a', 'b', 'c', '\0'};
    node_t *src_str = create_node(arr1);
    ck_assert_ptr_nonnull(src_str);
    char arr2[SIZE] = {'a', 'b', '\0'};
    node_t *req_str = create_node(arr2);
    ck_assert_ptr_nonnull(req_str);

    int pos = my_strstr(src_str, req_str);

    ck_assert_int_eq(pos, 0);

    free_list(src_str);
    free_list(req_str);
}
END_TEST

START_TEST(test_my_strstr_substring_at_the_end_of_string)
{
    char arr1[SIZE] = {'a', 'b', 'c', '\0'};
    node_t *src_str = create_node(arr1);
    ck_assert_ptr_nonnull(src_str);
    char arr2[SIZE] = {'b', 'c', '\0'};
    node_t *req_str = create_node(arr2);
    ck_assert_ptr_nonnull(req_str);

    int pos = my_strstr(src_str, req_str);

    ck_assert_int_eq(pos, 1);

    free_list(src_str);
    free_list(req_str);
}
END_TEST

START_TEST(test_my_strstr_many_substrings_in_string)
{
    char arr1[SIZE] = {'a', 'b', 'c', 'a'};
    char arr2[SIZE] = {'b', 'c', 'a', 'b'};
    char arr3[SIZE] = {'c', '\0'};
    node_t *src_str = create_node(arr1);
    ck_assert_ptr_nonnull(src_str);

    node_t *new_node = create_node(arr2);
    ck_assert_ptr_nonnull(new_node);
    src_str = add_node(new_node, src_str);
    ck_assert_ptr_nonnull(src_str);

    new_node = create_node(arr3);
    ck_assert_ptr_nonnull(new_node);
    src_str = add_node(new_node, src_str);
    ck_assert_ptr_nonnull(src_str);

    char arr4[SIZE] = {'a', 'b', 'c', '\0'};
    node_t *req_str = create_node(arr4);
    ck_assert_ptr_nonnull(req_str);

    int pos = my_strstr(src_str, req_str);

    ck_assert_int_eq(pos, 0);

    free_list(src_str);
    free_list(req_str);
}
END_TEST

START_TEST(test_my_strstr_part_of_substring_in_string)
{
    char arr1[SIZE] = {'m', 'a', 's', 'm'};
    char arr2[SIZE] = {'a', 's', 'h', 'm'};
    char arr3[SIZE] = {'a', 's', 'h', 'a'};
    char arr4[SIZE] = {'s', '\0'};
    node_t *src_str = create_node(arr1);
    ck_assert_ptr_nonnull(src_str);

    node_t *new_node = create_node(arr2);
    ck_assert_ptr_nonnull(new_node);
    src_str = add_node(new_node, src_str);
    ck_assert_ptr_nonnull(src_str);

    new_node = create_node(arr3);
    ck_assert_ptr_nonnull(new_node);
    src_str = add_node(new_node, src_str);
    ck_assert_ptr_nonnull(src_str);

    new_node = create_node(arr4);
    ck_assert_ptr_nonnull(new_node);
    src_str = add_node(new_node, src_str);
    ck_assert_ptr_nonnull(src_str);

    char arr5[SIZE] = {'m', 'a', 's', 'h'};
    char arr6[SIZE] = {'a', 's', '\0'};
    node_t *req_str = create_node(arr5);
    ck_assert_ptr_nonnull(req_str);

    new_node = create_node(arr6);
    ck_assert_ptr_nonnull(new_node);
    req_str = add_node(new_node, req_str);
    ck_assert_ptr_nonnull(req_str);

    int pos = my_strstr(src_str, req_str);

    ck_assert_int_eq(pos, 7);

    free_list(src_str);
    free_list(req_str);
}
END_TEST

Suite* my_strstr_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("my_strstr");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_my_strstr_empty_source_string);
    tcase_add_test(tc_pos, test_my_strstr_empty_substring);
    tcase_add_test(tc_pos, test_my_strstr_no_substring);
    tcase_add_test(tc_pos, test_my_strstr_substring_at_the_beginning_of_string);
    tcase_add_test(tc_pos, test_my_strstr_substring_at_the_end_of_string);
    tcase_add_test(tc_pos, test_my_strstr_many_substrings_in_string);
    tcase_add_test(tc_pos, test_my_strstr_part_of_substring_in_string);

    suite_add_tcase(s, tc_pos);

    return s;
}


