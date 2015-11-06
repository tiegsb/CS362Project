/* Author: Ashok Nayar
 * cs362, Fall 2015
 * Assignment 4: Random Testing
 * randomtestcard.c (Testing Council Card)
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1

int checkCouncil(int p, int handPos, struct gameState *post) {

    // Copy the game state to compare to
    // after calling the council function
    struct gameState pre;
    memcpy (&pre, post, sizeof(struct gameState));
    
    // Call council card
    councilEffect(p, handPos, post);

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
    // We check for 3 because the council card is discarded (-1)
    // But 4 cards are added (+4)
    if (pre.handCount[p]+3 != post->handCount[p])
    {
        printf("FAILURE: Hand count was not increased by 3: pre.handCount: %d, post.handCount: %d\n", pre.handCount[p], post->handCount[p]);
    }
    
    // Get the other player
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
//    int k[10] = {adventurer, council_room, feast, gardens, mine,
//	       remodel, smithy, village, baron, great_hall};

    // Create game state
    struct gameState G;
    for (n = 0; n < 2000; n++)
    {
        for (i = 0; i < sizeof(struct gameState); i++)
        {
            ((char*)&G)[i] = floor(Random() * 256);
        }
        // Get random player
        p = floor(Random() * 2);
        
        // Set random values for deck sizes
        G.deckCount[p] = floor(Random() * MAX_DECK);
        G.discardCount[p] = floor(Random() * MAX_DECK);
        G.handCount[p] = floor(Random() * MAX_HAND);
        

        // Set other player
        int other_player = 1;
        if (p == 1)
        {
            other_player = 0;
        }
        // Set deck sizes for other player
        G.deckCount[other_player] = floor(Random() * MAX_DECK);
        G.discardCount[other_player] = floor(Random() * MAX_DECK);
        G.handCount[other_player] = floor(Random() * MAX_HAND);
        
        // Provide random cards to the deck
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
        
        
        // Explicitly set the council card to a random
        // place in the current player's hand
        int council_pos = floor(Random() * G.handCount[p]);
        G.hand[p][council_pos] = council_room;
        
        // Set action count, buy count, and played card counts
        G.numActions = floor(Random() *10);
        G.numBuys = floor(Random() * 5);
        G.playedCardCount =  floor(Random() * MAX_DECK);
        
        // Add random cards to played card deck
        for (j = 0; j< G.playedCardCount; j++)
        {
            G.playedCards[j] = floor(Random() * 6);
        }

        // Set the number of players and whose turn it is
        G.numPlayers = p +1;
        G.whoseTurn = p;
        
        // Call the council card test function
        checkCouncil(p, council_pos, &G);

    }
    
    return 0;

}