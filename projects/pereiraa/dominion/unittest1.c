/*****************************************************************************************
* Tests the drawCard function by ensuring the player's hand is increased by one card while
* their deck is decreased by 1 card.
*****************************************************************************************/

#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

void testDrawCard(struct gameState *G) {
  
    
    int player = 1;
    int hand = G->handCount[player];
    int deck = G->deckCount[player];
    
    drawCard(player, G);
    int newHand = G->handCount[player];
    int newDeck = G->deckCount[player];
    if(newHand == hand+1)
        printf("Hand Count test passed \n");
    if(newDeck == deck -1)
        printf("Deck Count test passed \n");
}

int main(int argc, char *argv[])
{
    printf ("Testing drawCard...\n");
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};
    int seed = 1000;
    initializeGame(2, k, seed, &G);
    testDrawCard(&G);
    return 0;
}

    
