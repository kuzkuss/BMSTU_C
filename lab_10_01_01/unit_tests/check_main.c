#include <stdlib.h>
#include "check_grocery.h"
#include "check_list.h"

int main(void)
{
    setbuf(stdout, NULL);
    int err = 0;
    Suite *s;
    SRunner *runner;

    s = grocery_read_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    err = srunner_ntests_failed(runner);
    srunner_free(runner);

    s = create_node_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    err = srunner_ntests_failed(runner);
    srunner_free(runner);

    s = compare_name_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    err = srunner_ntests_failed(runner);
    srunner_free(runner);

    s = compare_price_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    err = srunner_ntests_failed(runner);
    srunner_free(runner);

    s = read_list_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    err = srunner_ntests_failed(runner);
    srunner_free(runner);

    s = find_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    err = srunner_ntests_failed(runner);
    srunner_free(runner);

    s = insert_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    err = srunner_ntests_failed(runner);
    srunner_free(runner);

    s = reverse_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    err = srunner_ntests_failed(runner);
    srunner_free(runner);

    s = sorted_merge_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    err = srunner_ntests_failed(runner);
    srunner_free(runner);

    s = sort_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    err = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (err == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}


