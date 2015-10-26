//card test for council_room
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "dominion.c"
#include "rngs.c"


/*void feastF(struct gameState *state, int choice1){
  int temphand[MAX_HAND];// moved above the if statement
  int currentPlayer = whoseTurn(state);
  int i;
  int x;
  //gain card with cost up to 5
  //Backup hand
  for (i = 0; i <= state->handCount[currentPlayer]; i++){
    temphand[i] = state->hand[currentPlayer][i];//Backup card
    state->hand[currentPlayer][i] = 0;//Set to nothing
  }
  //Backup hand

  //Update Coins for Buy
  updateCoins(currentPlayer, state, 5);
  x = 1;//Condition to loop on
  while( x == 1) {//Buy one card
    if (supplyCount(choice1, state) <= 0){
      if (DEBUG)
        printf("None of that card left, sorry!\n");

      if (DEBUG){
        printf("Cards Left: %d\n", supplyCount(choice1, state));
      }
    }
    else if (state->coins < getCost(choice1)){
      printf("That card is too expensive!\n");

      if (DEBUG){
        printf("Coins: %d < %d\n", state->coins, getCost(choice1));
      }
    }
    else{
      if (DEBUG){
        printf("Deck Count: %d\n", state->handCount[currentPlayer] + state->deckCount[currentPlayer] + state->discardCount[currentPlayer]);
      }

      gainCard(choice1, state, 0, currentPlayer);//Gain the card
      x = 0;//No more buying cards

      if (DEBUG){
        printf("Deck Count: %d\n", state->handCount[currentPlayer] + state->deckCount[currentPlayer] + state->discardCount[currentPlayer]);
      }
    }
  } 
  //Reset Hand
  for (i = 0; i <= state->handCount[currentPlayer]; i++){
    state->hand[currentPlayer][i] = temphand[i];
    temphand[i] = -1;
  }
  //Reset Hand           
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

void testFeast(){
	struct gameState* game = malloc(sizeof(struct gameState));
    int i;
    printf("Testing FeastF()\n");

    //buy card with no supply
    /*quickSetup(game);
    game->supplyCount[1] = 0;
    feastF(game, estate);
    if(game->discardCount[1] != 10){
    	printf("Test 1: card was added to discard pile with no supply\n");
    }*/
    printf("No end of loop for testing gain card with no supply, and card too expensive\n");
    //buy card with enough supply & correct price
    quickSetup(game);
    feastF(game, 1);
    if(game->discardCount[1] != 1){
    	printf("Test 2: card was not added to discard pile\n");
    }
    //buy card too expensive
    quickSetup(game);
    //feastF(game, 3); //commented due to endless loop
}

int main(){
	testFeast();
	return 0;
}