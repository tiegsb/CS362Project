//Card Test for Smithy

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "dominion.c"
#include "rngs.c"

/*void smithyF(struct gameState *state, int handPos){
  int currentPlayer = whoseTurn(state);
  int i;
  //+3 Cards
  for (i = 0; i < 3; i++)
  {
    drawCard(currentPlayer, state);
  }
  //discard card from hand
  discardCard(handPos, currentPlayer, state, 1);
}*/

int testSmithy(){
	printf("Testing Smithy()\n");
    struct gameState* game = malloc(sizeof(struct gameState));
    int i;
    game->deckCount[1] = 5;
    for(i=0; i<5; i++){
    	game->deck[1][i] = copper;
    }
    game->handCount[1] = 1;
    game->numPlayers = 1;
    game->whoseTurn = 1;
    for(i=0; i<treasure_map + 1; i++){
        game->supplyCount[i] = 12;
        game->embargoTokens[i] = 0;
    }
    game->discardCount[1] = 0; //setting player 1 discard pile to empty
    game->outpostPlayed = 0;
    game->outpostTurn = -1;
    game->phase = 0;
    game->numActions = 1;
    game->coins = 0;
    game->numBuys = 1;
    game->hand[1][1] = smithy;
    game->handCount[1] = 1;
    
    smithyF(game, 0);
    if(game->handCount[1] != 3){
    	printf("Should have 3 cards, only have %d\n", game->handCount[1]);
    }
    /*if(game->numActions != 0){
    	printf("Actions should be at 0, but is at %d\n", game->numActions);
    } This is done in a different function */
    if(game->discardCount[1] != 1){
    	printf("Card was trashed not discarded\n");
    }
}

int main(){
    testSmithy();
    return 0;
}

//create fake gameState
//crate fake hand for player
//add smithy card
//play smithy card
//check for -1 action
//check for +2 cards in hand
//check smithy was removed from hand
//check for same # in discard

