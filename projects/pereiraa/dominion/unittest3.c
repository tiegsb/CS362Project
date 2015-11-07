/*****************************************************************************************
* Tests the fullDeckCount function by ensuring the function returns the proper number when
* changes to the cards are made
 *****************************************************************************************/

#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>


void testFullDeck(int player, int card, struct gameState *G) {
    
    int count1 = fullDeckCount(player, card, G);
    drawCard(player, G);
    int count2 = fullDeckCount(player, card, G);
    if(count1==count2)
        printf("Draw check passed\n");
    else
        printf("Draw check failed\n");
    discardCard(1,player,G,1);//with trash flag set
    int count3=fullDeckCount(player,card,G);
    if(count2==count3)
        printf("Trash check failed\n");
    else
        printf("Trash check passed\n");
    
    discardCard(2,player,G,0);
    int count4 = fullDeckCount(player, card, G);
    if(count3==count4)
        printf("Discard check passed\n");
    else
        printf("Discard check failed\n");
  
    
    
    
    
}


int main(int argc, char *argv[])
{
    printf ("Testing fullDeckCount...\n");
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};
    int seed = 1000;
    initializeGame(2, k, seed, &G);
    int player = whoseTurn(&G);
    int card =4;
    
    testFullDeck(player,card,&G);
    return 0;
}

//int numHandCards(struct gameState *state) {
  //return state->handCount[ whoseTurn(state) ];
//}

    

