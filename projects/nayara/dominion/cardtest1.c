/* Author: Ashok Nayar
 * cs362, Fall 2015
 * Assignment 3: Unit Testing
 * cardtest1.c (Testing smithy card function)
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
        // Intialize game and set current player's turn and coin size to 5
        r = initializeGame(numPlayer, k, seed, &G);
        printf("deckcount Pre Player %d : %d\n",p, G.deckCount[p]);
        G.whoseTurn = p;
        G.coins = 5;

        // initialize player's hand to all dummy cards
        for (handCount = 1; handCount <= maxHandCount; handCount++)
        {
            G.handCount[p] = handCount;
            int i;
            // Make the hand out of dummy cards
            for(i = 0; i<handCount;i++)
            {
                G.hand[p][i] = dummyCard;
            }
            // Add a smithy card to the hand
            G.hand[p][0] = testCard;
            G.deckCount[p] = 10; // Make the deck out of 10
            
            // These tests just ensure that our values before calling the function are correct
            // They test for number of buys, coin coint, hand count, etc
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
            smithyEffect(p, 0, &G); // Call the smithy function
            
            // Compare the results of the smithy function to what is expected
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

    }
    
    printf("All tests passed!\n");
    
    return 0;
}