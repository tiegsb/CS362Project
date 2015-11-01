#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1

int checkAdventurer(int p, struct gameState *post) {

    struct gameState pre;
    memcpy (&pre, post, sizeof(struct gameState));
    
    int r = adventurerEffect(p, post);
    
    return 0;
}

int main()
{
    int n, i, p;
    int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};
    
    struct gameState G;
    for (n = 0; n < 2000; n++)
    {
        for (i = 0; i < sizeof(struct gameState); i++)
        {
            ((char*)&G)[i] = floor(Random() * 256);
        }
        p = floor(Random() * 2);
        G.deckCount[p] = floor(Random() * MAX_DECK);
        G.discardCount[p] = floor(Random() * MAX_DECK);
        G.handCount[p] = floor(Random() * MAX_HAND);
        printf("Hand count: %d\n", G.deckCount[p]);
        printf("Discard count: %d\n", G.deckCount[p]);
        printf("Deck count: %d\n", G.deckCount[p]);
        //checkAdventurer(p, &G);
        
    }
    
    return 0;

}