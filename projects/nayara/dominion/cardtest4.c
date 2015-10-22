//int councilEffect(int player, int handPos, struct gameState *state);


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
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int p, r, handCount;
    int k[10] = {adventurer, council_room, feast, gardens, mine
        , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;
    // arrays of all coppers, silvers, and golds
    int dummyCard = adventurer;
    int testCard = council_room;
    
    
    printf("Testing councilEffect()\n");
    
    for (p = 0; p < numPlayer; p++)
    {
        r = initializeGame(numPlayer, k, seed, &G);
        G.whoseTurn = p;
        G.coins = 5;
        G.discardCount[p]= 0;
        G.numActions = 5;
        G.deckCount[p] = MAX_DECK;
        for (i=0; i< MAX_DECK; i++)
        {
            G.deck[p][i] = dummyCard;
        }

        for (handCount = 1; handCount <= maxHandCount; handCount++)
        {
            int i;
            G.handCount[p] = handCount;
            
            if (p ==0)
            {
                G.handCount[1] = 0;
            }
            else
            {
                G.handCount[0] = 0;
            }
            
            for(i = 0; i<handCount;i++)
            {
                G.hand[p][i] = dummyCard;
            }
            

            G.hand[p][0] = testCard;
#if (NOISY_TEST == 1)
            printf("***Test for player %d with %d  cards in hand\n",p,i);
#endif
            
#if (NOISY_TEST == 1)
            printf("Num buys. Expected %d, received %d\n",1,G.numBuys);
#endif
            //assert(G.numBuys == 1);
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
            if (p == 0)
            {
                printf("Hand count for player %d: Expected %d, received %d\n",p,handCount, G.handCount[p] );
                printf("Hand count for player %d: Expected %d, received %d\n",1,0, G.handCount[1] );
            }
            else
            {
                printf("Hand count for player %d: Expected %d, received %d\n",p,handCount, G.handCount[p] );
                printf("Hand count for player %d: Expected %d, received %d\n",0,0, G.handCount[0] );
            }
#endif
            if (p ==0 )
            {
                assert(G.handCount[p] == handCount);
                assert(G.handCount[1] == 0);
            }
            else
            {
                assert(G.handCount[p] == handCount);
                assert(G.handCount[0] == 0);
            }
            
#if (NOISY_TEST == 1)
            printf("*Calling council function.\n");
#endif
            councilEffect(p, 0, &G);
      
#if (NOISY_TEST == 1)
            printf("Num buys. Expected %d, received %d\n",2,G.numBuys);
#endif
            assert(G.numBuys == 2);
#if (NOISY_TEST == 1)
            printf("Num actions. Expected %d, received %d\n",5,G.numActions);
#endif
            assert(G.numActions == 5);
            
#if (NOISY_TEST == 1)
            printf("Num coins. Expected %d, received %d\n",5,G.coins);
#endif
            assert(G.coins == 5);
#if (NOISY_TEST == 1)
            printf("Testing for replaced village card. Expected %d, received %d\n",testCard, G.hand[p][0]);
#endif
            assert(G.hand[p][0] != testCard);
#if (NOISY_TEST == 1)
            printf("Hand count. Expected %d, received %d\n",handCount, G.handCount[p]);
#endif
            assert(G.handCount[p] == handCount);
#if (NOISY_TEST == 1)
            if (p == 0)
            {
                printf("Hand count for player %d: Expected %d, received %d\n",p,handCount, G.handCount[p] );
                printf("Hand count for player %d: Expected %d, received %d\n",1,0, G.handCount[1] );
            }
            else
            {
                printf("Hand count for player %d: Expected %d, received %d\n",p,handCount, G.handCount[p] );
                printf("Hand count for player %d: Expected %d, received %d\n",0,0, G.handCount[0] );
            }
#endif
            if (p ==0 )
            {
                assert(G.handCount[p] == handCount);
                assert(G.handCount[1] == 0);
            }
            else
            {
                assert(G.handCount[p] == handCount);
                assert(G.handCount[0] == 0);
            }
            printf("\n");
            
            
        }
    }

    
    printf("All tests passed!\n");
    
    return 0;
}