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
    //printf("Copper is %d, silver is %d, gold is %d\n", copper, silver, gold);
    if(post->handCount[p] != pre.handCount[p] + 2)
    {
        printf("Hand count pre: %d, Hand count post: %d\n", pre.handCount[p],post->handCount[p] );
    }
    
    // post - pre: start index
    // post should have no copper, silver, or gold
    // last two hand cards should be copper, silver, or gold.
    if(post->discardCount[p] == pre.discardCount[p])
    {
        //printf("Discard count pre: %d, discard count post: %d\n", pre.discardCount[p],post->discardCount[p] );
    }
    int i;

    for(i=0;i<post->discardCount[p];i++)
    {
        
        if (post->discard[p][i] == copper )
        {
            //printf("Copper: %d\n", post->discard[p][i]);
        }
        else if (post->discard[p][i] == silver )
        {
            printf("Silver: %d\n", post->discard[p][i]);
        }

        else if (post->discard[p][i] == gold )
        {
            printf("Gold: %d\n", post->discard[p][i]);
        }

    }
    for(i=0;i<post->handCount[p];i++)
    {
        printf("Card[%d][%d]: %d\n", p,i, post->hand[p][i]);
    }
    printf("\n");
    return 0;
}

int main()
{

    int i, j, n, p;
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
        for (j = 0; j< G.deckCount[p]; j++)
        {
            G.deck[p][j] = floor(Random() * 9);
            //printf("Deck is: %d\n", G.deck[p][j]);
        }
        for (j = 0; j< G.handCount[p]; j++)
        {
            G.hand[p][j] = floor(Random() * 9);
            //printf("Hand is: %d\n", G.hand[p][j]);
        }

        //printf("Hand count: %d\n", G.deckCount[p]);
        //printf("Discard count: %d\n", G.deckCount[p]);
        //printf("Deck count: %d\n", G.deckCount[p]);
        checkAdventurer(p, &G);
        
    }
    
    return 0;
    
}