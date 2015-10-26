//card test for adventurer
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "dominion.c"
#include "rngs.c"

/*void adventurerF(struct gameState *state){
  int drawntreasure=0;
  int currentPlayer = whoseTurn(state);
  int cardDrawn;
  int temphand[MAX_HAND];// moved above the if statement
  int z = 0;// this is the counter for the temp hand

  while(drawntreasure<2){
    if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
      shuffle(currentPlayer, state);
    }
    drawCard(currentPlayer, state);
    cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
    if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
      drawntreasure++;
    else{
      temphand[z]=cardDrawn;
      state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
      z++;
    }   
  }
  while(z-1>=0){
    state->discard[currentPlayer][state->discardCount[currentPlayer]++]=state->hand[currentPlayer][z-1]; // discard all cards in play that have been drawn
    z=z-1;
  }
}*/
void quickSetup(struct gameState *game){
	int i;
	game->deckCount[1] = 2;
    for(i=0; i<2; i++){
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
int testAdventurer(){
	printf("Testing adventurer()\n");
    struct gameState* game = malloc(sizeof(struct gameState));
    int i;
    //test1 test if drawn treasure goes to hand
    quickSetup(game);
    
    adventurerF(game);
    if(game->handCount[1] != 2){
    	printf("Test 1:Should have 2 cards, only have %d\n", game->handCount[1]);
    }

    //test2 check that function discards cards that are not treasure
    quickSetup(game);
    for(i=2; i < 10; i++){
    	game->deck[1][i] = estate;
    }
    game->deckCount[1] = 10;
    adventurerF(game);
    if(game->discardCount[1] != 8){
    	printf("Test 2:Should be 8 cards in discard pile, instead there are %d\n", game->discardCount[1]);
    }
    if(game->handCount[1] != 2){
    	printf("Test 3:there should be 2 cards in hand, but there are %d\n", game->handCount[1]);
    }

    //test3 check that if no cards in deck, shuffles and continues.
    quickSetup(game);
    for(i=0; i < 10; i++){
    	if(i == 8 || i == 9){
    		game->discard[1][i] = copper;
    	}else{
    		game->discard[1][i] = estate;
    	}
    }
    game->discardCount[1] = 10;
    game->deckCount[1] = 0;
    adventurerF(game);

    if(game->handCount[1] != 2){
    	printf("Test 4:there should be 2 cards in hand, but there are %d\n", game->handCount[1]);
    }
}

int main(){
    testAdventurer();
    return 0;
}