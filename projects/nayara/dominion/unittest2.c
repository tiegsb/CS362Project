/* -----------------------------------------------------------------------
 * Demonstration of how to write unit tests for dominion-base
 * Include the following lines in your makefile:
 *
 * testUpdateCoins: testUpdateCoins.c dominion.o rngs.o
 *      gcc -o testUpdateCoins -g  testUpdateCoins.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1


// int supplyCount(int card, struct gameState *state);

int main() {
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int maxBonus = 10;
    int p, r, handCount;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;

    int testCards[5] = {adventurer, council_room, feast, gardens, mine};


    printf ("TESTING supplyCount():\n");

    r = initializeGame(numPlayer, k, seed, &G);
    
    assert(supplyCount(7, &G) == 10);
    assert(supplyCount(8, &G) == 10);
    assert(supplyCount(9, &G) == 10);
    assert(supplyCount(10, &G) == 8);
    assert(supplyCount(11, &G) == 10);
    
    for (i = 0; i < 10; i++)
    {
        G.supplyCount[7] = i;
        G.supplyCount[8] = i;
        G.supplyCount[9] = i;
        G.supplyCount[10] = i;
        G.supplyCount[11] = i;
        assert(supplyCount(7, &G) == i);
        assert(supplyCount(8, &G) == i);
        assert(supplyCount(9, &G) == i);
        assert(supplyCount(10, &G) == i);
        assert(supplyCount(11, &G) == i);
        
    }
    
    printf("All tests passed!");
    return 0;
}