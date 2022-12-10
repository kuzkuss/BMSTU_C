#include "check_addition.h"

#define EPS     1.0e-7

#define N1 3
#define M1 3

#define N2 2
#define M2 3

START_TEST(test_addition_non_negative)
{
    double mtr1[N1][M1] = {{11.0, 8.0, 7.0}, {2.0, 0.0, 1.0}, {3.0, 5.0, 6.0}};
    double *b1[N1] = {mtr1[0], mtr1[1], mtr1[2]};

    double mtr2[N1][M1] = {{0.0, 2.0, 9.0}, {4.0, 1.0, 3.0}, {7.0, 7.0, 7.0}};
    double *b2[N1] = {mtr2[0], mtr2[1], mtr2[2]};

    double res[N1][M1] = {{11.0, 10.0, 16.0}, {6.0, 1.0, 4.0}, {10.0, 12.0, 13.0}};

    double **result = addition(b1, b2, N1, M1);

    ck_assert_ptr_nonnull(result);
    for (int i = 0; i < N1; ++i)
        for (int j = 0; j < M1; ++j)
            ck_assert_double_eq_tol(result[i][j], res[i][j], EPS);
    delete_matrix(result, N1);
}
END_TEST


START_TEST(test_addition_non_positive)
{
    double mtr1[N2][M2] = {{-1.0, -2.0, -3.0}, {0.0, -4.0, -5.0}};
    double *b1[N2] = {mtr1[0], mtr1[1]};

    double mtr2[N2][M2] = {{-7.0, -8.0, -9.0}, {-2.0, 0.0, -1.0}};
    double *b2[N2] = {mtr2[0], mtr2[1]};

    double res[N2][M2] = {{-8.0, -10.0, -12.0}, {-2.0, -4.0, -6.0}};

    double **result = addition(b1, b2, N2, M2);

    ck_assert_ptr_nonnull(result);
    for (int i = 0; i < N2; ++i)
        for (int j = 0; j < M2; ++j)
            ck_assert_double_eq_tol(result[i][j], res[i][j], EPS);
    delete_matrix(result, N2);
}
END_TEST

START_TEST(test_addition_positive_negative)
{
    double mtr1[N1][M1] = {{1.0, 2.0, -3.0}, {-2.0, 4.0, 5.0}, {-7.0, 1.0, -1.0}};
    double *b1[N1] = {mtr1[0], mtr1[1], mtr1[2]};

    double mtr2[N1][M1] = {{-1.0, 2.0, 3.0}, {-4.0, -5.0, 6.0}, {7.0, 8.0, -9.0}};
    double *b2[N1] = {mtr2[0], mtr2[1], mtr2[2]};

    double res[N1][M1] = {{0.0, 4.0, 0.0}, {-6.0, -1.0, 11.0}, {0.0, 9.0, -10.0}};

    double **result = addition(b1, b2, N1, M1);

    ck_assert_ptr_nonnull(result);
    for (int i = 0; i < N1; ++i)
        for (int j = 0; j < M1; ++j)
            ck_assert_double_eq_tol(result[i][j], res[i][j], EPS);
    delete_matrix(result, N1);
}
END_TEST

Suite* addition_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("addition");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_addition_non_negative);
    tcase_add_test(tc_pos, test_addition_non_positive);
    tcase_add_test(tc_pos, test_addition_positive_negative);

    suite_add_tcase(s, tc_pos);

    return s;
}


