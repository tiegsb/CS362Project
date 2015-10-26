/*****************************************************************************************
* Tests the council function:
*1. current player who plays council card receives 5 cards. His hand should have +3 cards now (after the current card is discarded.
*2. The number of buys should increase by 1.
*3. Other player's hand should increase by 1
 *****************************************************************************************/

#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

void testCouncil(int currentPlayer, struct gameState *G, int handPos){
  
    int player = currentPlayer;
    int hand = G->handCount[player];//get current handCount of player
    int buys = G->numBuys;//get number of Buys player has
    int otherHand = G->handCount[0];//get hand Count of other player's hand
    
    council(player, G, handPos);
    int newHand = G->handCount[player];//get new handcount
    int newbuys = G->numBuys;//get new numbuys
    int newOtherHand = G->handCount[0];//get other players new hand count

    int increase = newHand - hand;//how much the player's hand count has increase
    int buyIncrease = newbuys-buys;//how much the number of buys has increased
 
    if(newHand == hand+3)//tests if player's hand increased by 3 (4 new cards and 1 discarded)
        printf("Hand Count test passed \n");
    else
        printf("Hand Count test failed. The player's hand increased by %d not 3 \n\n" ,increase);
    
    if(newbuys == buys+1)//tests if player's hand increased by 3 (4 new cards and 1 discarded)
        printf("Numbuys test passed \n\n");
    else
        printf("Numbuys test failed. The player's number of buys increased by %d not 1 \n\n" ,buyIncrease);
    
    //check if other player hand increased
    if(newOtherHand == otherHand+1)//tests if player's hand increased by 3 (4 new cards and 1 discarded)
        printf("Other player's Hand Count test passed \n");
    else
        printf("Other player's Hand Count test failed. \n");

}

int main(int argc, char *argv[])
{
    printf ("Testing Council...\n");
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};
    int seed = 1000;
    initializeGame(2, k, seed, &G);
    int player = 1;
    int handPos = 0;
    drawCard(player, &G);//put cards in player's hand
    drawCard(player, &G);
    drawCard(player, &G);//put cards in player's hand
    drawCard(player, &G);
    testCouncil(player, &G, handPos);
    return 0;
}

    
