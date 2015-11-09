#include <limits.h>
#include "notassert.h"

#include "dominion.h"


void test_compare() {
    int max = INT_MAX;
    int min = INT_MIN;
    int hmax = max/2;
    int hmin = min/2;
    assert(compare(&max, &min) == 1);
    assert(compare(&hmax, &hmin) == 1);
    assert(compare(&min, &max) == -1);
    assert(compare(&hmin, &hmax) == -1);
    assert(compare(&min, &min) == 0);
    assert(compare(&max, &max) == 0);
}
