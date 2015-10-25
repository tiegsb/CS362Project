#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int p, r;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int discardCount;
    int deckCount;
    int handCount;
    int supplyCount;
    int card;

    printf ("TESTING gainCard():\n");
    for (p = 0; p < numPlayer; p++)
    {
        for (i = 0; i < 10; i++)
        {
            printf("Test player %d with card %d.\n", p, k[i]);
            r = initializeGame(numPlayer, k, seed, &G);   
            discardCount = G.discardCount[p];
            deckCount = G.deckCount[p];
            handCount = G.handCount[p];  
            supplyCount = G.supplyCount[k[i]];       
            
            // Add to discard
            gainCard(k[i], &G, 0, p);
            printf("discard pile = %d, expected = %d\n", G.discardCount[p], discardCount + 1);
            assert(G.discardCount[p] == discardCount + 1); 
            card = G.discard[p][discardCount + 1];
            printf("supply count = %d, expected = %d\n", G.supplyCount[k[i]], supplyCount - 1);
            assert(G.supplyCount[k[i]] == supplyCount - 1);

            // Add to deck
            supplyCount = G.supplyCount[k[i]];  
            gainCard(k[i], &G, 1, p);
            printf("deck count = %d, expected = %d\n", G.deckCount[p], deckCount + 1);
            assert(G.deckCount[p] == deckCount + 1); 
            card = G.deck[p][deckCount + 1];
            printf("supply count = %d, expected = %d\n", G.supplyCount[k[i]], supplyCount - 1);
            assert(G.supplyCount[k[i]] == supplyCount - 1);

            // Add to hand
            supplyCount = G.supplyCount[k[i]];  
            gainCard(k[i], &G, 2, p);
            printf("hand count = %d, expected = %d\n", G.handCount[p], handCount + 1);
            assert(G.handCount[p] == handCount + 1); 
            card = G.hand[p][handCount + 1];
            printf("supply count = %d, expected = %d\n", G.supplyCount[k[i]], supplyCount - 1);
            assert(G.supplyCount[k[i]] == supplyCount - 1);
        }
    }

    printf("All tests passed!\n");

    return 0;
}