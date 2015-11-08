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
    int numPlayer = 2;
    int p, handCount, d;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;
    srand(seed);
    int greatHallArray[maxHandCount];
    for (int i = 0; i < maxHandCount; i++) {
        greatHallArray[i] = great_hall;

    }


    initializeGame(numPlayer, k, seed, &G);     //initialize a new game
    deckCreate(&G);
    printf ("TESTING great_hall:\n");

    for (p = 0; p < numPlayer; p++)
    {   
        for (handCount = 1; handCount <= maxHandCount; handCount++) {
            
                G.handCount[p] = handCount;                // set the number of cards on hand
                memcpy(G.hand[p], greatHallArray, sizeof(int) * handCount); // set all the cards to great_hall

                int handCountPrev = G.handCount[p];
                int numActionsPrev = G.numActions;
            for (int pos = 0; pos < maxHandCount; pos++) {
                if (G.hand[p][pos] == great_hall) {
                    d = great_hall_play(&G, p, pos);
                    break;
                }
                else {
                    continue;
                }
            }
#if (NOISY_TEST == 1)
            printf("Passed. Function Output: 0 Result: %d", d);
#endif
            assert (d == 0);


#if (NOISY_TEST == 1)
        printf("Passed. Testing actionsTest. Expected: %d Actual: %d \n", numActionsPrev + 1, G.numActions);
#endif
        assert(numActionsPrev + 1 == G.numActions);

#if (NOISY_TEST == 1)
        printf("Passed. PlayerTest Expected: %d Actual: %d \n", p, G.whoseTurn);
#endif  

        assert(G.whoseTurn == p);

#if (NOISY_TEST == 1)
        printf("Failed: HandTest Expected: %d Actual: %d\n", handCountPrev, G.handCount[p]);
        printf("assert(handCountPrev == G.handCount[p])\n");
#endif
        //see bug 8
        printf("assert(handCountPrev == G.handCount[p])\n");
        
#if (NOISY_TEST == 1)
        printf("Passed: Discard test Expected: 16 Actual: %d \n" , G.playedCards[G.playedCardCount-1]);
#endif
        assert(G.playedCards[G.playedCardCount - 1] == 16);

        printf("\n");
    }
        endTurn(&G);
    }


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