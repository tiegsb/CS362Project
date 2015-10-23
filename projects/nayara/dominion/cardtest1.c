// int smithyEffect(int player, int handPos, struct gameState *state);


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
    int dummyCard = adventurer;
    int testCard = smithy;
    struct gameState G;
    int maxHandCount = 5;
    
    printf ("TESTING smithyEffect():\n");
    for (p = 0; p < numPlayer; p++)
    {
        r = initializeGame(numPlayer, k, seed, &G);
        printf("deckcount Pre Player %d : %d\n",p, G.deckCount[p]);
        G.whoseTurn = p;
        G.coins = 5;

        // initialize player's hand to all dummy cards
        for (handCount = 1; handCount <= maxHandCount; handCount++)
        {
            G.handCount[p] = handCount;
            int i;
            for(i = 0; i<handCount;i++)
            {
                G.hand[p][i] = dummyCard;
            }
            G.hand[p][0] = testCard;
            G.deckCount[p] = 10;
#if (NOISY_TEST == 1)
            printf("***Test for player %d with %d cards in hand\n",p,handCount);
#endif

#if (NOISY_TEST == 1)
            printf("Played card Count. Expected %d, received %d\n",G.playedCardCount,handCount-1);
#endif
            assert(G.playedCardCount == handCount -1);
#if (NOISY_TEST == 1)
            printf("Deck Count. Expected %d, received %d\n",10,G.deckCount[p]);
#endif
            assert(G.deckCount[p] == 10);
#if (NOISY_TEST == 1)
            printf("Num buys. Expected %d, received %d\n",1,G.numBuys);
#endif
            assert(G.numBuys == 1);
#if (NOISY_TEST == 1)
            printf("Num coins. Expected %d, received %d\n",5,G.coins);
#endif
            assert(G.coins == 5);
#if (NOISY_TEST == 1)
            printf("Testing for smithy card. Expected %d, received %d\n",testCard, G.hand[p][0]);
#endif
            assert(G.hand[p][0] == testCard);
#if (NOISY_TEST == 1)
            printf("Hand count. Expected %d, received %d\n",handCount, G.handCount[p]);
#endif
            assert(G.handCount[p] == handCount);
#if (NOISY_TEST == 1)
            printf("Calling smithy Function\n");
#endif
            smithyEffect(p, 0, &G);
            
#if (NOISY_TEST == 1)
            printf("Num coins. Expected %d, received %d\n",5,G.coins);
#endif
            assert(G.coins == 5);
#if (NOISY_TEST == 1)
            printf("Testing for smithy card. Expected %d, received %d\n",testCard, G.hand[p][0]);
#endif
            assert(G.hand[p][0] != testCard);
#if (NOISY_TEST == 1)
            printf("Hand count. Expected %d, received %d\n",handCount+2,G.handCount[p]);
#endif
            assert(G.handCount[p] == handCount + 2);
#if (NOISY_TEST == 1)
            printf("Deck Count. Expected %d, received %d\n",7,G.deckCount[p]);
#endif
            assert(G.deckCount[p] == 7);
#if (NOISY_TEST == 1)
            printf("Played card Count. Expected %d, received %d\n",G.playedCardCount,handCount);
#endif
            assert(G.playedCardCount == handCount);

            printf("Finished test for player %d with %d cards in hand\n\n", p, handCount);
            
        }
        

        // Add one smithy card, call function
        // check to see if smithy card is set to -1
        // check to see if 3 cards are added
    }
    
    printf("All tests passed!\n");
    
    return 0;
}