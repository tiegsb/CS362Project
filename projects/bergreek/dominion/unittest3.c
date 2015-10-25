#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {
    int i, j;
    int seed = 1000;
    int p, r;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxDeckCount = 10;
    int deckCount;
    int discardCount;
    int handCount;
    int coppers[MAX_HAND];
    for (i = 0; i < MAX_HAND; i++)
    {
        coppers[i] = copper;
    }

    printf ("TESTING drawCard():\n");
    for (p = 0; p < 2; p++)
    {
        for (j = 0; j < maxDeckCount; j++)
        {
            printf("Test player %d.\n", p);
            r = initializeGame(2, k, seed, &G);  
            deckCount = 10 - j; 
            discardCount = j;
            G.deckCount[p] = deckCount;
            G.discardCount[p] = j;
            handCount = G.handCount[p];

            memcpy(G.deck[p], coppers, sizeof(int) * deckCount);
            memcpy(G.discard[p], coppers, sizeof(int) * discardCount);
            
            drawCard(p, &G);
            printf("hand count = %d, expected = %d\n", G.handCount[p], handCount + 1);
            assert(G.handCount[p] == handCount + 1);
            printf("deck count = %d, expected = %d\n", G.deckCount[p], (deckCount - 1));
            assert(G.deckCount[p] == deckCount - 1);
            printf("discard count = %d, expected = %d\n", G.discardCount[p], discardCount);
            assert(G.discardCount[p] == discardCount);
        }
    }

    printf("All tests passed!\n");

    return 0;
}