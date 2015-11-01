#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1

int checkCouncil(int p, int handPos, struct gameState *post) {

    struct gameState pre;
    memcpy (&pre, post, sizeof(struct gameState));
    //printf("PRE: numBuys was not increased by one: pre.numBuys: %d, post.numBuys: %d\n", pre.numBuys, post->numBuys);
    
    int r = councilEffect(p, handPos, post);

    // Check if card in hand is discarded
    if (pre.hand[p][handPos] == post->hand[p][handPos])
    {
        printf("FAILURE: council card was not discarded: pre.hand[%d][%d]: %d, post.hand[%d][%d]: %d\n",p,handPos, pre.hand[p][handPos], p, handPos, post->hand[p][handPos]);
    }
    // Check if number of buys is increased by 1
    if (pre.numBuys +1 != post->numBuys)
    {
        printf("Whose turn: %d, %d\n", pre.whoseTurn, post->whoseTurn);
        printf("FAILURE: numBuys was not increased by one: pre.numBuys: %d, post.numBuys: %d\n", pre.numBuys, post->numBuys);
    }
    
    // Check if current hand count increases by 4
    if (pre.handCount[p]+4 != post->handCount[p])
    {
        printf("FAILURE: Hand count was not increased by 4: pre.handCount: %d, post.handCount: %d\n", pre.handCount[p], post->handCount[p]);
    }
    int other_player = 0;
    if (p == 0)
    {
        other_player = 1;
    }
    
    // Check if the hand count of others has increased by 1
    if (pre.handCount[other_player]+1 != post->handCount[other_player])
    {
        printf("FAILURE: Other player hand count was not increased by 1: pre.handCount: %d, post.handCount: %d\n", pre.handCount[other_player], post->handCount[other_player]);
    
    }
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
        
        //printf("NUMBUYS: %d\n", G.numBuys);
        int other_player = 1;
        
        
        if (p == 1)
        {
            other_player = 0;
        }
        G.deckCount[other_player] = floor(Random() * MAX_DECK);
        G.discardCount[other_player] = floor(Random() * MAX_DECK);
        G.handCount[other_player] = floor(Random() * MAX_HAND);
        
        for (j = 0; j< G.deckCount[p]; j++)
        {
            G.deck[p][j] = floor(Random() * 6);
        }
        for (j = 0; j< G.handCount[p]; j++)
        {
            G.hand[p][j] = floor(Random() * 6);
        }

        for (j = 0; j< G.deckCount[other_player]; j++)
        {
            G.deck[other_player][j] = floor(Random() * 6);
        }
        for (j = 0; j< G.handCount[other_player]; j++)
        {
            G.hand[other_player][j] = floor(Random() * 6);
        }
        
        
        
        int council_pos = floor(Random() * G.handCount[p]);
        G.hand[p][council_pos] = council_room;
        G.numActions = floor(Random() *10);
        G.numBuys = floor(Random() * 5);
        G.playedCardCount =  floor(Random() * MAX_DECK);
        for (j = 0; j< G.playedCardCount; j++)
        {
            G.playedCards[j] =floor(Random() * 6);
        }

        G.numPlayers = p +1;
        G.whoseTurn = p;
        checkCouncil(p, council_pos, &G);

    }
    
    return 0;

}