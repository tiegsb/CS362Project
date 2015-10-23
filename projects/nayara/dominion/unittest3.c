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


//int handCount(struct gameState *state);


int main() {

    int seed = 1000;
    int numPlayer = 2;
    int p, r, handCount;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;

    printf ("TESTING numHandCards():\n");
    for (p = 0; p < numPlayer; p++)
    {
#if (NOISY_TEST == 1)
        printf("***Test for player %d\n",p);
#endif
        for (handCount = 1; handCount <=maxHandCount; handCount++)
        {
            memset(&G, 23, sizeof(struct gameState));   // clear the game state
            r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
            G.whoseTurn = p;
            G.handCount[p] = handCount;
#if (NOISY_TEST == 1)
            printf("Testing hand count of %d for player %d\n",handCount, p);
#endif
            assert(numHandCards(&G) == handCount);
        }
        printf("\n");
    }
    printf("All tests passed!\n");

    return 0;
}