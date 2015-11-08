/*****************************************************************************************
* Tests the smith function:
* 1. current player who plays smithy card receives 3 cards. His hand should have +2 cards now (add 3 discard 1).
* 2. deck should decrease by 3 cards
* 3. Other player's hand is not effected by current player playing smithy card.

 *
 * Include the following lines in your makefile:
 *
 * randomtestcard: randomtestcard.c dominion.o rngs.o
 *      gcc -o randomtestcard -g  randomtestcard.c dominion.o rngs.o $(CFLAGS)
 *****************************************************************************************/

#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

void testSmithy(int currentPlayer, struct gameState *G, int handPos){
  
    int player = currentPlayer;
    int hand = G->handCount[player];//get current handCount of player
    int deckCount = G->deckCount[player];//get current deckCount of player
   // printf("deckcCount %d\n", deckCount);
    
    int otherHand = G->handCount[0];//get handCount of other player's hand
    smith(player, G, handPos);//call smithy function
   
    int newHand = G->handCount[player];//get new handCount after smith played
    int newOtherHand = G->handCount[0];//get new handCount of other player's hand
    int newDeckCount = G->deckCount[player];//get current deckCount of player
   //  printf("newdeckcCount %d\n", newDeckCount);

    int increase = newHand - hand;//determine how much the players hand has increased
 
    if(newHand == hand+2)//tests if player's hand increased by 2 (3 new cards and 1 discarded)
        printf("\nHand Count test passed \n");
    else
        printf("\nHand Count test failed. The player's hand increased by %d not 2 \n" ,increase);
    
    int deckDecrease = deckCount - newDeckCount;//determine how much the players hand has increased
    
    if(newDeckCount == deckCount-3)//tests if player's deck decreased by 3
        printf("\nDeck Count test passed \n");
    else
        printf("\nDeck Count test failed. The player's deck decreased by %d not 3 \n" ,deckDecrease);
    
            
    if(newOtherHand > otherHand)//tests if other player's hand changed
        printf("Other player's Hand Count test failed \n");
    else if(newOtherHand<otherHand)
        printf("Other player's Hand Cont test failed\n");
    else
        printf("Other player's Hand Count test passed. \n\n");
}

int main(int argc, char *argv[])
{
    printf ("Testing Smithy...\n");
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};
    int seed = 1000;
    srand(time(NULL));
    initializeGame(4, k, seed, &G);
    int i;
    int player;
    int handPos;
    int handCards;
    drawCard(player, &G);//put cards in player's hand
    drawCard(player, &G);
    
    for(i =0; i <10; i++) {
		player = rand()%4; //random player
		handCards = numHandCards(&G);
		handPos = rand()%handCards;
		printf("\nTest %d with player %d and handPos %d\n", i, player, handPos);
    	testSmithy(player, &G, handPos);
    }
    
    return 0;
}

    




