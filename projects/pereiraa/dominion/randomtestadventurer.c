/*****************************************************************************************
* Tests the adven function by randomly choosing a current player of the 4 possibilities
*1. current player who plays adventure card should have its hand increased by two treasure cards
*2. The player's deck should decrease by at least 2 cards.
 *****************************************************************************************/

#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include<time.h>

void testAdven(int currentPlayer, struct gameState *G){
  
    int player = currentPlayer;
    int hand = G->handCount[player];   
    int i, card;
    int deckCount = G->deckCount[player];
        printf("Deck Count %d \n", deckCount);
    adven(player, G);
    int newHand = G->handCount[player];
    if(newHand==hand+2)//if 2 treasures added check to make sure they are treasures
        for(i =newHand-1; i<newHand-3; i++)
        {
            card =G->hand[player][i];
            if(card!=copper||card!=silver||card!=gold){
               printf("treasures not added\n");
               break;
            }
            else
                printf("treasure added test passed\n");
        }
    else
        printf("Two treasures not added. Test failed.\n");
    
    
    
    int newDeckCount =G->deckCount[player];
    printf("NewDeck Count %d \n", newDeckCount);
    if(newDeckCount<=deckCount-2)//deck should have been reduced by at least 2
        printf("Deck reduced properly, passed\n");
    else
        printf("Deck not reduced properly, failed\n");
    }

int main(int argc, char *argv[])
{
    printf ("Testing Adven...\n");
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};
    int seed = 1000;
    srand(time(NULL));
    initializeGame(4, k, seed, &G);
    int i;
    int player;
    for(i =0; i <50; i++) {
		player = rand()%4; //random player
		printf("\nTest %d with player %d\n", i, player);
    	testAdven(player, &G);
    }
    return 0;
}