//Woo Choi
//cardtest2.c
//Adventurer Test

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

/*Testing Adventurer
int adventurerRefactor(int currentPlayer, struct gameState *state)
{
	//copied paste from original cardEffect

	  int temphand[MAX_HAND];// moved above the if statement
	  int drawntreasure=10;
	  int cardDrawn=0;
	  int z = 0;// this is the counter for the temp hand

	
	// Actual implementation
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
		state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
		z=z-1;
    }
      return 0;	
}

From refactor.c :
1. Adventurer:
	drawntreasure's initial value changed from 0 to 10.
	the first while loop will not run
*/

int main(){

	int i;
    int seed = 1000;
    int numPlayer = 2;
    int r;	
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
	int currentPlayer = whoseTurn(&G);
	int currentCardNum;	// number of cards before the adventurer card is played.

    // initialize game state
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

	//Begin Adventurer testing
	printf("******************\n");
	printf("cardtest2.c\n");
	printf("Adventurer Card Test:\n");

	// gain adventurer for currentPlayer and add to hand
	gainCard(adventurer, &G, 2, currentPlayer);	
	currentCardNum = G.handCount[0];
	
	// go through hand to look for the adventurer card
	// numbHandCards: How many cards current player has in hand 
	for (i = 0; i < numHandCards(&G); i++) {
		// handCard: enum value of indexed card in player's hand
		if(handCard(i, &G) == adventurer){
			// Play card with index handPos from current player's hand
			playCard(i,-1,-1,-1,&G);	
			// + 1 because discardCard was not used (so adventurer wasn't accounted for)
			printf("  Expected card count: %d\n  Actual card count: %d\n",currentCardNum+1,G.handCount[0]);		
		}
	}	
	
	printf("Adventurer Card Test is now over\n\n");
	return 0;
}