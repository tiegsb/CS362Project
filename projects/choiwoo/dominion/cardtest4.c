//Woo Choi
//cardtest4.c
//Village Test

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

/*Testing village

int villageRefactor(int currentPlayer, int handPos, struct gameState *state)
{
    //+1 Card
    drawCard(currentPlayer, state);
			
    //+2 Actions
    state->numActions = 2;
			
    //discard played card from hand
    discardCard(handPos, currentPlayer, state, 0);
    return 0;
}

Comment from refactor.c
4. village:
	instead of +2 actions, # of actions just becomes 2
	    from
			state->numActions = state->numActions = 2;
		to
			state->numActions = 2;
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
	int currentCardNum;	// number of cards before the village card is played.

    // initialize game state
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

	//Begin village testing
	printf("******************\n");
	printf("cardtest4.c\n");
	printf("village Card Test:\n");
	printf("  numActions count BEFORE village: %d\n", G.numActions);
	// gain village for currentPlayer 
	gainCard(village, &G, 2, currentPlayer);	
	currentCardNum = G.handCount[0];
	
	// go through hand to look for the village card
	// numbHandCards: How many cards current player has in hand 
	for (i = 0; i < numHandCards(&G); i++) {
		// handCard: enum value of indexed card in player's hand
		if(handCard(i, &G) == village){
			// Play card with index handPos from current player's hand
			playCard(i,-1,-1,-1,&G);	
			printf("  Expected card count: %d\n  Actual card count: %d\n",currentCardNum,G.handCount[0]);		
			// Test for action count
			printf("  numActions count AFTER village: %d\n", G.numActions);
			printf("  difference between numActions should = 2\n");
			
		}
	}	
	
	printf("village Card Test is now over\n\n");
	return 0;
}