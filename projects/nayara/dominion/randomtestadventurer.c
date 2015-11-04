/* Author: Ashok Nayar
 * cs362, Fall 2015
 * Assignment 4: Random Testing
 * randomtestadventurer.c (Testing Adventurer Card)
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1

int checkAdventurer(int p, struct gameState *post) {
    
    // Create a game state that holds the data before
    // the function is called
    struct gameState pre;
    int i;

    // Copy the data of the game state
    memcpy (&pre, post, sizeof(struct gameState));

    // Call the adventurer function
    adventurerEffect(p, post);

    // Check to see if the hand increased by two and only two
    if(post->handCount[p] != pre.handCount[p] + 2)
    {
        
        printf("FAILURE: Hand count must be increased by exactly 2. Hand count pre: %d, Hand count post: %d\n", pre.handCount[p],post->handCount[p] );
    }

    // Check to see if any coin cards have been discarded.
    // Coin cards should NOT be in the discard pile
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

    // The last two cards should be coin cards
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
        // Set up a game state
        for (i = 0; i < sizeof(struct gameState); i++)
        {
            ((char*)&G)[i] = floor(Random() * 256);
        }
        // Pick a random player between 0 and 1
        p = floor(Random() * 2);
        // Pick random size counts for deck, discard deck, and player's hand
        G.deckCount[p] = floor(Random() * MAX_DECK);
        G.discardCount[p] = floor(Random() * MAX_DECK);
        G.handCount[p] = floor(Random() * MAX_HAND);
        G.playedCardCount = floor(Random() * MAX_DECK);
        
        // Fill the deck with random cards
        for (j = 0; j< G.deckCount[p]; j++)
        {
            G.deck[p][j] = floor(Random() * 9);
        }
        
        // Fill hand with random cards
        for (j = 0; j< G.handCount[p]; j++)
        {
            G.hand[p][j] = floor(Random() * 9);
        }

        // Fill discard with random cards (we don't include the
        // coin cards for testing purposes
        for (j = 0; j< G.discardCount[p]; j++)
        {
            G.discard[p][j] = floor(Random() * 3);
        }

        // Call the testing function
        checkAdventurer(p, &G);
        
    }
    
    return 0;
    
}