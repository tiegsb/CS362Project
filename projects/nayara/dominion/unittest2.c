/* Author: Ashok Nayar
 * cs362, Fall 2015
 * Assignment 3: Unit Testing
 * unittest2.c (Testing supplyCount())
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
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int r;

    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;

    int testCards[5] = {adventurer, council_room, feast, gardens, mine};


    printf ("TESTING supplyCount(%d):\n", adventurer);

    // Loop over each player
    int p;
    for (p=0; p< numPlayer; p++)
    {
        r = initializeGame(numPlayer, k, seed, &G); // Initialize game state
        
#if (NOISY_TEST == 1)
        printf("***Test for player %d\n",p);
#endif
        
        G.whoseTurn = p; // Set the turn to current player
#if (NOISY_TEST == 1)
        printf("Testing initial supply counts for player %d\n",p);
#endif

        // Make sure supply counts match the default size
        //for each of the test cards in the testCard array
#if (NOISY_TEST == 1)
        printf("Testing for card: %d\n",testCards[0]);
#endif
        assert(supplyCount(testCards[0], &G) == 10);
#if (NOISY_TEST == 1)
        printf("Testing for card: %d\n",testCards[1]);
#endif
      
        assert(supplyCount(testCards[1], &G) == 10);
#if (NOISY_TEST == 1)
        printf("Testing for card: %d\n",testCards[2]);
#endif

        assert(supplyCount(testCards[2], &G) == 10);
#if (NOISY_TEST == 1)
        printf("Testing for card: %d\n",testCards[3]);
#endif

        assert(supplyCount(testCards[3], &G) == 8);
#if (NOISY_TEST == 1)
        printf("Testing for card: %d\n",testCards[4]);
#endif

        assert(supplyCount(testCards[4], &G) == 10);

        
        // Set the supplies of each card to different values
        for (i = 0; i < 10; i++)
        {
            G.supplyCount[testCards[0]] = i;
            G.supplyCount[testCards[1]] = i;
            G.supplyCount[testCards[2]] = i;
            G.supplyCount[testCards[3]] = i;
            G.supplyCount[testCards[4]] = i;
            
            
            // Check to see if the values match the value given
            // by the supplyCount function
#if (NOISY_TEST == 1)
            printf("Testing for card: %d and a supply count of %d\n",testCards[0], i);
#endif
            assert(supplyCount(testCards[0], &G) == i);
#if (NOISY_TEST == 1)
            printf("Testing for card: %d and a supply count of %d\n",testCards[1], i);
#endif

            assert(supplyCount(testCards[1], &G) == i);
#if (NOISY_TEST == 1)
            printf("Testing for card: %d and a supply count of %d\n",testCards[2], i);
#endif

            assert(supplyCount(testCards[2], &G) == i);
#if (NOISY_TEST == 1)
            printf("Testing for card: %d and a supply count of %d\n",testCards[3], i);
#endif

            assert(supplyCount(testCards[3], &G) == i);
#if (NOISY_TEST == 1)
            printf("Testing for card: %d and a supply count of %d\n",testCards[4], i);
#endif

            assert(supplyCount(testCards[4], &G) == i);
            
        }
        

    }
    printf("All tests passed!\n");
    return 0;
}