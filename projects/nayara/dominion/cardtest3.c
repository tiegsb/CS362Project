// int villageEffect(int player, int handPos, struct gameState *state);

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

int main() {
    int seed = 1000;
    int numPlayer = 2;
    int p, r, handCount;
    int k[10] = {adventurer, council_room, feast, gardens, mine
        , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;
    int dummyCard = adventurer;
    int testCard = village;
    
    
    printf ("TESTING villageEffect():\n");
    for (p = 0; p < numPlayer; p++)
    {   
        r = initializeGame(numPlayer, k, seed, &G);
        G.whoseTurn = p;
        G.coins = 5;
        G.discardCount[p]= 0;

        for (handCount = 1; handCount <= maxHandCount; handCount++)
        {
            int i;
            G.handCount[p] = handCount;
            G.numActions = 5;
            for(i = 0; i<handCount;i++)
            {
                G.hand[p][i] = dummyCard;
            }
            
            printf("Testing  %d\n", testCard);
            G.hand[p][0] = testCard;
            for(i = 0; i<handCount;i++)
            {
                printf("Pre Call [%d]: %d\n",i, G.hand[p][i]);
            }
#if (NOISY_TEST == 1)
            printf("***Test for player %d with %d  cards in hand\n",p,i);
#endif
            
#if (NOISY_TEST == 1)
            printf("Num buys. Expected %d, received %d\n",1,G.numBuys);
#endif
            assert(G.numBuys == 1);
#if (NOISY_TEST == 1)
            printf("Num actions. Expected %d, received %d\n",5,G.numActions);
#endif
            assert(G.numActions == 5);

#if (NOISY_TEST == 1)
            printf("Num coins. Expected %d, received %d\n",5,G.coins);
#endif
            assert(G.coins == 5);
#if (NOISY_TEST == 1)
            printf("Testing for village card. Expected %d, received %d\n",testCard, G.hand[p][0]);
#endif
            assert(G.hand[p][0] == testCard);
#if (NOISY_TEST == 1)
            printf("Hand count. Expected %d, received %d\n",handCount, G.handCount[p]);
#endif
            assert(G.handCount[p] == handCount);

#if (NOISY_TEST == 1)
            printf("*Calling village function.\n");
#endif

            villageEffect(p, 0, &G);

#if (NOISY_TEST == 1)
            printf("Num buys. Expected %d, received %d\n",1,G.numBuys);
#endif
            assert(G.numBuys == 1);
#if (NOISY_TEST == 1)
            printf("Num actions. Expected %d, received %d\n",7,G.numActions);
#endif
            assert(G.numActions == 7);
            
#if (NOISY_TEST == 1)
            printf("Num coins. Expected %d, received %d\n",5,G.coins);
#endif
            assert(G.coins == 5);
#if (NOISY_TEST == 1)
            printf("Testing for village card. Expected other than %d, received %d\n",testCard, G.hand[p][0]);
#endif
            assert(G.hand[p][0] != testCard);
#if (NOISY_TEST == 1)
            printf("Hand count. Expected %d, received %d\n",handCount, G.handCount[p]);
#endif
            assert(G.handCount[p] == handCount);


            
        }
    }
    
    printf("All tests passed!\n");
    
    return 0;
}