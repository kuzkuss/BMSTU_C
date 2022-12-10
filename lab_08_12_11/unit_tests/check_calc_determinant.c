#include "check_calc_determinant.h"

#define EPS 1.0e-7

#define N1 2
#define N2 3
#define N3 1

#define OK 0

START_TEST(test_calc_determinant_zero)
{
    double mtr[N1][N1] = {{2.0, 3.0}, {2.0, 3.0}};
    double *b[N1] = {mtr[0], mtr[1]};

    double res = 0.0;

    int rc = 0;

    double result = calc_determinant(b, N1, &rc);

    ck_assert_int_eq(rc, OK);
    ck_assert_double_eq_tol(result, res, EPS);
}
END_TEST


START_TEST(test_calc_determinant_positive)
{
    double mtr[N2][N2] = {{1.0, 1.0, 1.0}, {2.0, 2.0, -1.0}, {0.0, 1.0, 0.0}};
    double *b[N2] = {mtr[0], mtr[1], mtr[2]};

    double res = 3.0;

    int rc = 0;

    double result = calc_determinant(b, N2, &rc);

    ck_assert_int_eq(rc, OK);
    ck_assert_double_eq_tol(result, res, EPS);
}
END_TEST

START_TEST(test_calc_determinant_negative)
{
    double mtr[N2][N2] = {{2.0, 3.0, -1.0}, {3.0, 2.0, 1.0}, {-2.0, 0.0, 3.0}};
    double *b[N2] = {mtr[0], mtr[1], mtr[2]};

    double res = -25.0;

    int rc = 0;

    double result = calc_determinant(b, N2, &rc);

    ck_assert_int_eq(rc, OK);
    ck_assert_double_eq_tol(result, res, EPS);
}
END_TEST

START_TEST(test_calc_determinant_one_elem)
{
    double mtr[N3][N3] = {{2.0}};
    double *b[N3] = {mtr[0]};

    double res = 2.0;

    int rc = 0;

    double result = calc_determinant(b, N3, &rc);

    ck_assert_int_eq(rc, OK);
    ck_assert_double_eq_tol(result, res, EPS);
}
END_TEST

Suite* calc_determinant_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("calc_determinant");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_calc_determinant_zero);
    tcase_add_test(tc_pos, test_calc_determinant_positive);
    tcase_add_test(tc_pos, test_calc_determinant_negative);
    tcase_add_test(tc_pos, test_calc_determinant_one_elem);

    suite_add_tcase(s, tc_pos);

    return s;
}

