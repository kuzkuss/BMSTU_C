#include "check_filter.h"
#include "check_mysort.h"
#include <stdlib.h>

int main(void)
{
    int err = 0;
    Suite *s;
    SRunner *runner;

    s = key_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    err = srunner_ntests_failed(runner);
    srunner_free(runner);

    s = mysort_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    err = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (err == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}


