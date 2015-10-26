/*****************************************************************************************
* Tests the numHandCards function by ensuring the function returns the proper number when
* drawCard is called
 *****************************************************************************************/

#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>


void testNumHandCards(struct gameState *G, int currentplayer) {
    
    int tester = numHandCards(G);
    int cards = G->handCount[currentplayer];
    printf("handCard before drawCard %d\n", cards);
    drawCard(currentplayer, G);
    int newCards = G->handCount[currentplayer];
    printf("handCard after drawCard %d\n", newCards);
    if(newCards <= cards)
        printf("NumHandCards failed\n");
    else
        printf("NumHandCards passed\n");
    
    
    
    
}


int main(int argc, char *argv[])
{
    printf ("Testing numHandCards...\n");
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};
    int seed = 1000;
    initializeGame(2, k, seed, &G);
    int player = whoseTurn(&G);
    
    testNumHandCards(&G, player);
    return 0;
}

//int numHandCards(struct gameState *state) {
  //return state->handCount[ whoseTurn(state) ];
//}

    
