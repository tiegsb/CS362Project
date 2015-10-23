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
    int r;

    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;

    int testCards[5] = {adventurer, council_room, feast, gardens, mine};


    printf ("TESTING supplyCount(%d):\n", adventurer);

    int p;
    for (p=0; p< numPlayer; p++)
    {
        r = initializeGame(numPlayer, k, seed, &G);
        
#if (NOISY_TEST == 1)
        printf("***Test for player %d\n",p);
#endif
        
        G.whoseTurn = p;
#if (NOISY_TEST == 1)
        printf("Testing initial supply counts for player %d\n",p);
#endif

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

        
        for (i = 0; i < 10; i++)
        {
            G.supplyCount[testCards[0]] = i;
            G.supplyCount[testCards[1]] = i;
            G.supplyCount[testCards[2]] = i;
            G.supplyCount[testCards[3]] = i;
            G.supplyCount[testCards[4]] = i;
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