//card test for council_room
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "dominion.c"
#include "rngs.c"

/*void council_roomF(struct gameState *state, int handPos){
  int currentPlayer = whoseTurn(state);
  int i;
  //+4 Cards
  for (i = 0; i < 4; i++){
    drawCard(currentPlayer, state);
  }
      
  //+1 Buy
  state->numBuys++;
      
  //Each other player draws a card
  for (i = 0; i < state->numPlayers; i++){
    if ( i == currentPlayer ){
        drawCard(i+1, state);
    }
  }
      
  //put played card in played card pile
  discardCard(handPos, currentPlayer, state, 1);  
}*/

void quickSetup(struct gameState *game){
	int i;
	game->deckCount[1] = 10;
    for(i=0; i<10; i++){
    	game->deck[1][i] = copper;
    }
    game->numPlayers = 1;
    game->whoseTurn = 1;
    for(i=0; i<treasure_map + 1; i++){
        game->supplyCount[i] = 12;
        game->embargoTokens[i] = 0;
    }
    game->discardCount[1] = 0; //setting player 1 discard pile to empty
    game->outpostPlayed = 0;	//outpost stuff
    game->outpostTurn = -1;		//outpost stuff
    game->phase = 0;		
    game->numActions = 1;		//standard
    game->coins = 0;			//standard
    game->numBuys = 1;			//standard
    //game->hand[1][1] = ;
    game->handCount[1] = 0;		//set hand size to 0
}

void testCouncilRoom(){
	struct gameState* game = malloc(sizeof(struct gameState));
    int i;
    printf("Testing council_RoomF\n");
    //test 1 check that 4 cards are drawn and buy increases 1
    quickSetup(game);
    game->deck[1][0] = council_room;
    council_roomF(game, 0);
    if(game->numBuys != 2){
    	printf("Test 1: number of buys should be 2, instead it is %d\n", game->numBuys);
    }
    if(game->deckCount[1] != 6){
    	printf("Test 2: number of cards in hand should be 6, instead it is %d\n", game->deckCount[1]);
    }
}

int main(){
	testCouncilRoom();
	return 0;
}