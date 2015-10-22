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

// handcard

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

    printf ("TESTING handCount():\n");
    int testCards[5] = {adventurer, council_room, feast, gardens, mine};
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
    
    for (p=0; p<numPlayer; p++)
    {
        G.whoseTurn = p;
        for (handCount = 1; handCount <=maxHandCount; handCount++)
        {
            G.handCount[p] = handCount;
            
            int i;
            for(i = 0; i<handCount;i++)
            {
                G.hand[p][i] = testCards[i];
                
            }
        }
    }
    for (p=0; p<numPlayer; p++)
    {
        G.whoseTurn = p;
        assert(handCard(0, &G) == 7);
        assert(handCard(1, &G) == 8);
        assert(handCard(2, &G) == 9);
        assert(handCard(3, &G) == 10);
        assert(handCard(4, &G) == 11);
    }


    
    printf("All tests passed!\n");

    return 0;
}