//Woo Choi
//randomtestcards.c
//Random Smithy Test

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <time.h>
#include <stdlib.h>

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
	srand(time(NULL));
	int numTestRun = 2000; // number of tests run. CHANGE it for your liking
	int i, j;
    int seed = 1000;
    int numPlayer = 2;
    int r;	
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
	int currentPlayer = whoseTurn(&G);
	int currentCardNum;	// number of cards before the smithy card is played.
	
	int numFailedTest = 0; // failed test runs
	int numSuccessfulTest = 0; // successful test runs
	int playCount =0; // used to play smithy once per test run
	int refreshGame =3; // used to refresh game
	//Begin smithy testing
	printf("******************\n");
	printf("randomtestcard.c\n");
	printf("Smithy Random Card Test:\n");
	printf("Number of test runs: %d\n", numTestRun);
	
	// initialize game state

	
	// loooooop
	for (j = 0; j < numTestRun; j++) {
		playCount = 0;
		
		if (refreshGame == 3) {
			memset(&G, 23, sizeof(struct gameState));   // clear the game state
			r = initializeGame(numPlayer, k, seed, &G); // initialize a new game	
			refreshGame = 0;
		}
		// gain smithy for currentPlayer and add to hand
		if ( rand() % 2 == 1) {
			gainCard(smithy, &G, 2, currentPlayer);
			refreshGame++;
		} else {
			refreshGame++;
		}
		// go through hand to look for the smithy card
		// numbHandCards: How many cards current player has in hand 
		for (i = 0; i < numHandCards(&G); i++) {
			// handCard: enum value of indexed card in player's hand
			if(handCard(i, &G) == smithy && playCount == 0){
				playCount = 1;
				// Play card with index handPos from current player's hand
				currentCardNum = G.handCount[0];		
				printf("**Playing smithy card\n");
				playCard(i,-1,-1,-1,&G);	
				printf("  Expected card count: %d\n  Actual card count: %d\n",currentCardNum+2,G.handCount[0]);	
				if (currentCardNum+2 != G.handCount[0]) {
					printf("  Expected and Actual card count do not match!!***\n");
					numFailedTest++;
				} else {
					printf("  Smithy card worked as intended!\n");
					numSuccessfulTest++;
				}
	
			}
		}	
	}
	printf("Smithy Card Test is now over\n\n");
	printf("Number of successful runs: %d\n", numSuccessfulTest);
	printf("Number of failed runs: %d\n", numFailedTest);
	printf("Number of times smithy was not used: %d\n\n", numTestRun - numSuccessfulTest - numFailedTest);
	return 0;
}