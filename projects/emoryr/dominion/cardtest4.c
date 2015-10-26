
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"

#define NOISY_TEST 1

int deckCreate(struct gameState*);

int main() {
    int seed = 1000;
    int numPlayer = 4;
    int p, r, handCount, d;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;
    // arrays of all coppers, silvers, and golds
    srand(seed);
    int villageArray[maxHandCount];
    for (int i = 0; i < maxHandCount; i++) {
        villageArray[i] = village;

    }


    initializeGame(numPlayer, k, seed, &G);     //initialize a new game
    deckCreate(&G);
    printf ("TESTING village using village_play function:\n");
//for (int i = 0; i < 50000; i++) {
    for (p = 0; p < numPlayer; p++)
    {   
        for (handCount = 1; handCount <= maxHandCount; handCount++) {
            
            G.handCount[p] = handCount;                // set the number of cards on hand
            memcpy(G.hand[p], villageArray, sizeof(int) * handCount); // set all the cards to smithy

            int handCountPrev = G.handCount[p];
            int numActionsPrev = G.numActions;
            
            for (int pos = 0; pos < 5; pos++) {
            	if (G.hand[p][pos] == village) {
                	d = village_play(&G, p, pos);
                	break;
            	}
            	else {
                	continue;
            	}
            }

            
            
            //assert(d == 0);


#if (NOISY_TEST == 1)
        //printf("Testing numActions. Expected: %d Actual: %d \n", numActionsPrev + 2, G.numActions);
#endif
        //see bug 6 
        //assert(numActionsPrev + 2 == G.numActions);

#if (NOISY_TEST == 1)
     //   printf("Testing if player turn is correct. Expected: %d Actual: %d \n", p, G.whoseTurn);
#endif  

            assert(G.whoseTurn == p);

#if (NOISY_TEST == 1)
            printf("Testing handCount. Expected: %d Actual: %d\n", handCountPrev, G.handCount[p]);
#endif
        //see bug 7
            //assert(handCountPrev == G.handCount[p]);
            
#if (NOISY_TEST == 1)
            printf("Testing if village was discarded. Expected: 14 Actual: %d", G.playedCards[G.playedCardCount-1]);
#endif
        assert(G.playedCards[G.playedCardCount-1] == 14);
        
        printf("\n");
    }
        endTurn(&G);
    }
//}

    printf("All tests passed!\n");

    return 0;
}

int deckCreate (struct gameState *G) {
    enum CARD deck[] = {gold, silver, smithy, gold, village, village, village};
    for (int i = 0; i < G->numPlayers; i++) {
        memcpy(G->deck[i], &deck, sizeof deck);
        G->deckCount[i] = sizeof(deck) / sizeof(enum CARD);
    }
    return 0;
}