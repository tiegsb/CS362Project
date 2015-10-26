/* Author: Ashok Nayar
 * cs362, Fall 2015
 * Assignment 3: Unit Testing
 * unittest3.c (Testing numHandCards())
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {

    int seed = 1000;
    int numPlayer = 2;
    int p, r, handCount;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;

    printf ("TESTING numHandCards():\n");
    
    // Loop over each player
    for (p = 0; p < numPlayer; p++)
    {
#if (NOISY_TEST == 1)
        printf("***Test for player %d\n",p);
#endif
        // Test different size hand amounts
        for (handCount = 1; handCount <=maxHandCount; handCount++)
        {
            memset(&G, 23, sizeof(struct gameState));   // clear the game state
            r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
            G.whoseTurn = p;
            G.handCount[p] = handCount; // explicitly set hand sizes
            
            // Make sure the value of the numHandCard function
            // matches the explicitly set values.
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