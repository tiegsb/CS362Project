#include <stdlib.h>
#include "notassert.h"
#include "dominion.h"

void test_kingdomCards() {
    int c0 = 0, c1 = 1, c2 = 2, c3 = 3, c4 = 4, c5 = 5, c6 = 6, c7 = 7, c8 = 8,
        c9 = 9;
    int *mem = kingdomCards(c0, c1, c2, c3, c4, c5, c6, c7, c8, c9);
    for (int i = 0; i < 10; i++) {
        assert(mem[i] == i);
    }
    free(mem);
}
