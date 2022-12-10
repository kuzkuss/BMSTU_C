#include "check_addition.h"
#include "check_multiplication.h"
#include "check_calc_determinant.h"
#include <stdlib.h>
#include <check.h>

int main(void)
{
    int err = 0;
    Suite *s;
    SRunner *runner;

    s = addition_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    err = srunner_ntests_failed(runner);
    srunner_free(runner);

    s = multiplication_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    err = srunner_ntests_failed(runner);
    srunner_free(runner);

    s = calc_determinant_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    err = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (err == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}


