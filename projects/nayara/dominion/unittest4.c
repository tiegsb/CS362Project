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

// fullDeckCount

int main() {
    int i;
    int seed = 1000;
    int numPlayer = 2;

    int p, r;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int testCard = adventurer;

    printf("Testing fullDeckCount()\n");

    for (p = 0; p <numPlayer; p++)
    {
        r = initializeGame(numPlayer, k, seed, &G);
        G.deckCount[p] =  MAX_DECK;
        G.discardCount[p] = MAX_DECK;
        G.handCount[p] = MAX_HAND;
        
        for (i = 0; i<MAX_DECK; i++)
        {
            G.deck[p][i] = 13;
            G.discard[p][i] = 13;
            G.hand[p][i] = 13;
        }
#if (NOISY_TEST == 1)
        printf("***Test for player %d\n\n",p);
#endif
#if (NOISY_TEST == 1)
        printf("Testing card %d for player %d\n",testCard, p);
        printf("Expected: %d, Received: %d  \n",0, fullDeckCount(p, testCard,&G));
#endif
        assert(fullDeckCount(p,testCard , &G) == 0);

        G.deck[p][0] = testCard;
        G.discard[p][0] = testCard;
        G.hand[p][0] = testCard;
        
#if (NOISY_TEST == 1)
        printf("Testing card %d for player %d\n",testCard, p);
        printf("Expected: %d, Received: %d  \n",3, fullDeckCount(p, testCard,&G));
#endif
        assert(fullDeckCount(p,testCard , &G) == 3);

        for (i = 0; i<MAX_DECK; i++)
        {
            G.deck[p][i] = testCard;
            G.discard[p][i] = testCard;
            G.hand[p][i] = testCard;
        }
#if (NOISY_TEST == 1)
        printf("Testing card %d for player %d\n",testCard, p);
        printf("Expected: %d, Received: %d  \n",MAX_DECK + MAX_DECK + MAX_HAND, fullDeckCount(p, testCard,&G));
#endif
        
        assert(fullDeckCount(p,testCard , &G) == (MAX_DECK + MAX_DECK + MAX_HAND) );

        printf("\n");
    }
    

    printf("All tests passed!\n");

    return 0;
}