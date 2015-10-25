/* Author: Ashok Nayar
 * cs362, Fall 2015
 * Assignment 3: Unit Testing
 * unittest1.c (Testing handCard)
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

    printf ("TESTING handCard():\n");
    int testCards[5] = {adventurer, council_room, feast, gardens, mine};
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
    
    // Loop over each player
    for (p=0; p<numPlayer; p++)
    {
        G.whoseTurn = p;
        // Create different sized hand counts
        for (handCount = 1; handCount <=maxHandCount; handCount++)
        {
            G.handCount[p] = handCount;
            
            // Add a test card to the hand
            int i;
            for(i = 0; i<handCount;i++)
            {
                G.hand[p][i] = testCards[i];
                
            }
#if (NOISY_TEST == 1)
            printf("***Test for player %d with %d cards in hand\n",p,handCount);
#endif

            // For each position in the hand, call the handCard function
            // and make sure it matches the test card
            for (i = 0; i<handCount; i++)
            {
#if (NOISY_TEST == 1)
                printf("Checking at hand position %d\n",i);
#endif

                assert(handCard(i, &G) == testCards[i]);

            }
            printf("\n");
        }
    }


    
    printf("All tests passed!\n");

    return 0;
}