#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "dominion.h"

#include "cardtest1.c"
#include "cardtest2.c"
#include "cardtest3.c"
#include "cardtest4.c"

#include "unittest1.c"
#include "unittest2.c"
#include "unittest3.c"
#include "unittest4.c"

int run_tests(bool exit_failure);

void (*tests[])() = {testSmithyEffect, testAdventurerEffect, testVillageEffect, testCouncilRoomEffect, test_compare, test_shuffle, test_updateCoins, test_kingdomCards, NULL};
size_t test_no = 0;

void trap_assertion_failure(int signal) {
    test_no++;
    run_tests(true);
}

int main () {
    signal(SIGABRT, trap_assertion_failure);
    run_tests(false);
}

int run_tests(bool exit_failure) {
    while (tests[test_no] != NULL) {
        printf("Running test %zu\n", test_no);
        tests[test_no]();
        test_no++;
    }
    if (exit_failure) {
        // This causes make to fail and not to proceed to generating gcov data.
        //exit(EXIT_FAILURE);
        exit(EXIT_SUCCESS);
    } else {
        exit(EXIT_SUCCESS);
    }
}
