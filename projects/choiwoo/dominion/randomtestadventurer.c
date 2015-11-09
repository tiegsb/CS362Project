//Woo Choi
//randomtestadventurer.c
//Random Adventurer Test

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <time.h>
#include <stdlib.h>

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
	int numTestRun = 2000;  //number of tests run. Change to change the # of runs
	srand(time(NULL));
	int i, j;
    int seed = 1000;
    int numPlayer = 2;
    int r;	
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
	int currentPlayer = whoseTurn(&G);
	int currentCardNum;	// number of cards before the adventurer card is played.
	int numFailedTest = 0; // failed test runs
	int numSuccessfulTest = 0; // successful test runs
	int playCount =0;  // used to play adventurer once per test run
	int refreshGame =3; // used to refresh game
	//Begin Adventurer testing
	printf("******************\n");
	printf("randomtestadventurer.c\n");
	printf("Adventurer Random Card Test:\n");	
	printf("Number of test runs: %d\n", numTestRun);


	// initialize game state
	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
	
	// loooooooooop
	for (j = 0; j < numTestRun; j++) {
		// to only test 1 adventurer card per test run
		playCount = 0;
		
		// fresh new game every 3 runs
		if (refreshGame ==3) {
			// initialize game state
			memset(&G, 23, sizeof(struct gameState));   // clear the game state
			r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
			refreshGame = 0;
		}
		
		// gain adventurer for currentPlayer and add to hand
		// giving random factor here to see how it reacts to different number of cards in hand
		if ( rand() % 2 == 1) {
			gainCard(adventurer, &G, 2, currentPlayer);		
			refreshGame++;
		} else {
			refreshGame++;
		}
		// go through hand to look for the adventurer card
		// numbHandCards: How many cards current player has in hand 
		for (i = 0; i < numHandCards(&G); i++) {

			// handCard: enum value of indexed card in player's hand
			if(handCard(i, &G) == adventurer && playCount == 0){
				playCount = 1;				
				//give the random factor to play adventurer card
				//realized this wasn't necessary
				//if ( rand() % 2 == 1) {
					// Play card with index handPos from current player's hand
					currentCardNum = G.handCount[0];
					printf("**Playing adventurer card: \n");
					playCard(i,-1,-1,-1,&G);	
					printf("  Expected card count: %d\n  Actual card count: %d\n",currentCardNum+2,G.handCount[0]);
					if (currentCardNum+1 != G.handCount[0]) {
						printf("  Expected and Actual card count do not match!!***\n");				
						numFailedTest++;
					} else {
						printf("  Adventurer card worked as intended!\n");
						numSuccessfulTest++;
					}
				//}
			}
		}	
	}
	printf("Adventurer Card Test is now over\n\n");
	printf("Number of successful runs: %d\n", numSuccessfulTest);
	printf("Number of failed runs: %d\n", numFailedTest);
	printf("Number of times adventurer was not used: %d\n\n", numTestRun - numSuccessfulTest - numFailedTest);
	return 0;
}