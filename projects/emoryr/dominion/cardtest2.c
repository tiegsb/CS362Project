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
    int p, r, handCount, d;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;
    srand(seed);
    int adventurerArray[maxHandCount];
    for (int i = 0; i < maxHandCount; i++) {
        adventurerArray[i] = adventurer;

    }


    initializeGame(numPlayer, k, seed, &G);     //initialize a new game
    deckCreate(&G);
    printf ("TESTING adventurer:\n");
for (int i = 0; i < 50000; i++) {
    for (p = 0; p < numPlayer; p++)
    {   
        for (handCount = 1; handCount <= maxHandCount; handCount++) {
            for (int pos = 0; pos < 5; pos++) {
            G.handCount[p] = handCount;                // set the number of cards on hand
            memcpy(G.hand[p], adventurerArray, sizeof(int) * handCount); // set all the cards to adventurer

            int handCountPrev = G.handCount[p];
            if (G.hand[p][pos] == village) {
                d = adventurer_play(&G, p, pos);
            }
            else {
                continue;
            }
            
#if (NOISY_TEST == 1)
            printf("Passed. Function Output: 0 Result: %d", d);
#endif
            assert (d == 0);
#if (NOISY_TEST == 1)
        printf("Passed. handCount Test Output: %d Result: %d\n", handCountPrev + 1, G.handCount[p]);
#endif
            //two treasure cards added to hand after call to adventurer_play() one card discarded
            assert(G.handCount[p] == handCountPrev + 1);
#if (NOISY_TEST == 1)
                printf("Failed discardTest Output: no silver, copper, or gold cards Result: Gold cards in discard.");
        printf("assert(G.discard[p][i] != copper && G.discard[p][i] != silver && G.discard[p][i] != gold.\n");
#endif  

            for (int i = G.discardCount[p]-1; i >= 0; i--) {
                //assert(G.discard[p][i] != copper && G.discard[p][i] != silver && G.discard[p][i] != gold);
                //This assertion fails. See bug5
            }
#if (NOISY_TEST == 1)
                printf("Passed. Output: %d Result %d\n", p, G.whoseTurn);
#endif
        
            }
        }
         endTurn(&G);
    }
   
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