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
    int i;

    memcpy (&pre, post, sizeof(struct gameState));
    printf("Got here\n");
    adventurerEffect(p, post);
    printf("Got here post\n");

    if(post->handCount[p] != pre.handCount[p] + 2)
    {
        
        printf("FAILURE: Hand count must be increased by exactly 2. Hand count pre: %d, Hand count post: %d\n", pre.handCount[p],post->handCount[p] );
    }

    for(i=0;i<post->discardCount[p];i++)
    {
        
        if (post->discard[p][i] == copper )
        {
            printf("FAILURE: Copper card found in discard pile\n");
        }
        else if (post->discard[p][i] == silver )
        {
            printf("FAILURE: Silver card found in discard pile\n");
        }

        else if (post->discard[p][i] == gold )
        {
            printf("FAILURE: Gold card found in discard pile\n");
        }

    }

    if (post->hand[p][post->handCount[p]-1] != silver && post->hand[p][post->handCount[p]-1] != gold && post->hand[p][post->handCount[p]-1] != copper  )
    {
        printf("FAILURE: Last card must be a copper, silver, or gold. Last card was: %d\n", post->hand[p][post->handCount[p]-1]);
    }
    if (post->hand[p][post->handCount[p]-2] != silver && post->hand[p][post->handCount[p]-2] != gold && post->hand[p][post->handCount[p]-2] != copper  )
    {
        printf("FAILURE: Last card must be a copper, silver, or gold. Last card was: %d\n", post->hand[p][post->handCount[p]-2]);
    }
    
    return 0;
}

int main()
{

    int i,j, n, p;
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
        G.playedCardCount = floor(Random() * MAX_DECK);
        for (j = 0; j< G.deckCount[p]; j++)
        {
            G.deck[p][j] = floor(Random() * 9);
        }

        for (j = 0; j< G.handCount[p]; j++)
        {
            G.hand[p][j] = floor(Random() * 9);
        }

        for (j = 0; j< G.discardCount[p]; j++)
        {
            G.discard[p][j] = floor(Random() * 2);
        }

        
        checkAdventurer(p, &G);
        
    }
    
    return 0;
    
}