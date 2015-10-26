//Woo Choi
//cardtest1.c
//Smithy Test

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

/*Testing smithy

int smithyRefactor(int currentPlayer, int handPos, struct gameState *state)
{
	int i=0;
    //+3 Cards
    for (i = 1; i < 3; i++)
	{
	  drawCard(currentPlayer, state);
	}
	
	//discard card from hand
    discardCard(handPos, currentPlayer, state, 0);
    return 0;
}

Comment from refactor.c
2. Smithy:
	in for loop, initial i's value is now 1 instead of 0
	player will only get +2 cards
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
	int currentCardNum;	// number of cards before the smithy card is played.

    // initialize game state
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

	//Begin smithy testing
	printf("******************\n");
	printf("cardtest1.c\n");
	printf("Smithy Card Test:\n");

	// gain smithy for currentPlayer and add to hand
	gainCard(smithy, &G, 2, currentPlayer);	
	currentCardNum = G.handCount[0];
	
	// go through hand to look for the smithy card
	// numbHandCards: How many cards current player has in hand 
	for (i = 0; i < numHandCards(&G); i++) {
		// handCard: enum value of indexed card in player's hand
		if(handCard(i, &G) == smithy){
			// Play card with index handPos from current player's hand
			playCard(i,-1,-1,-1,&G);	
			// + 2 because discardCard was not used (so smithy wasn't accounted for)
			printf("  Expected card count: %d\n  Actual card count: %d\n",currentCardNum+2,G.handCount[0]);		
		}
	}	
	
	printf("Smithy Card Test is now over\n\n");
	return 0;
}