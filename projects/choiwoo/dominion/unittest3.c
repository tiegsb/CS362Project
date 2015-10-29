//Woo Choi
//unitest3.c
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

//gainCard() function test
//int gainCard(int supplyPos, struct gameState *state, int toFlag, int player)

int main(){

	int i;
    int seed = 1000;
    int numPlayer = 2;
    int r;	
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
	int currentPlayer = whoseTurn(&G);
	int currentCardNum;	

    // initialize game state
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

	//Begin testing
	printf("******************\n");
	printf("unittest3.c\n");
	printf("gainCard() Test:\n");
	printf("  Testing flag set to 2:\n");

	// gain smithy card for testing gainCard()
	// Setting flag to 2  (adds to hand)
	gainCard(smithy, &G, 2, currentPlayer);	
	currentCardNum = G.handCount[0];
	
	// go through hand to look for the smithy card
	// numbHandCards: How many cards current player has in hand 
	for (i = 0; i < numHandCards(&G); i++) {
		// handCard: enum value of indexed card in player's hand
		if(handCard(i, &G) == smithy){
			// See if gainCard worked correctly.
			printf("    Expected card count: %d\n  Actual card count: %d\n",currentCardNum,G.handCount[0]);		
			printf("    gainCard() worked\n");		
		}
	}

	// test flag set to 1 ( should gain card into deck)
	int currentDeckCount;
	currentDeckCount = G.deckCount[0];
	printf("  Testing flag set to 1:\n");
	printf("    deck count before gainCard() = %d\n", currentDeckCount);
	gainCard(smithy, &G, 1, currentPlayer);
	printf("    deck count after 1 card drawn = %d\n", G.deckCount[0]);
	
	
	printf("gainCard() Test is now over\n\n");
	return 0;
}