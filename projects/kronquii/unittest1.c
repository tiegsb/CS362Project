#include <limits.h>

#include "dominion.h"


void test_compare(const void* a, const void* b) {
    // Search the whole state space of integers to ensure that the function has
    // the expected return values
    for (int i = INT_MIN; i < INT_MAX; i++) {
        for (int j = i + 1; j =< INT_MAX; j++) {
            assert(compare(i, j) == 1);
        }
    }

    for (int i = INT_MIN; i < INT_MAX; i++) {
        for (int j = i + 1; j =< INT_MAX; j++) {
            assert(compare(j, i) == -1);
        }
    }

    for (int i = INT_MIN; i =< INT_MAX; i++) {
        assert(compare(i, i) == 0);
    }
}
