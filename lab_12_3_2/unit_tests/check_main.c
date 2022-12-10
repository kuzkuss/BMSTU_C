#include <stdlib.h>
#include "check_lib_arr.h"

int main(void)
{
    int err = 0;
    Suite *s;
    SRunner *runner;

    s = fill_primes_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    err = srunner_ntests_failed(runner);
    srunner_free(runner);

    s = filter_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    err = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (err == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}


