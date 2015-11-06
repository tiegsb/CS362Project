/* -----------------------------------------------------------------------
 * Author: Tony Huynh		CS 362		randomtestcard.c

 * This will test the Village Card WITH random testing
 
 * Include the following lines in your makefile:
 *
 * randomVillage: randomtestcard.c.c dominion.o rngs.o
 *      gcc -o randomVillage -g  randomtestcard.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */
// adding comment for commit
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>	// incorporate simple random testing
#include "rngs.h"

int main() {
	srand(time(NULL));
	int i, A;	// loop variable
    int seed = 1000;
    int numPlayer = 2;
    int r;	//, handCount;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    //int maxHandCount = 5;
	int currentPlayer = whoseTurn(&G);
	
	int currentCardNum;	// number of cards before village card is played.
	int currentActNum;	// number of actions before village card is played.
	int initDeckCount;	// initial number of deck count
	int expectedDkCnt;	// the expected deck count based on amount of village card drawn and played
	int actualDeckCnt;	// after test has been run, check the deck count
	
	/// CHANGE RANDOM ITERATION BELOW
	
	int randDraw = rand()%3 + 1;	// initialize the random number of times adventurer will draw
	//randDraw = 4;
	/// CHANGE RANDOM ITERATION ABOVE
	
    // initialize game state
	printf ("TESTING Village():\n");
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game	
	
	
	// prepare information before playing village
	currentCardNum = G.handCount[0];	// hand count of the current player
	currentActNum = 1;	// current number of actions

	// from some of the things I read on Piazza, I will test different elements of my program state
	// CHECK: deck count
	initDeckCount = G.deckCount[0];
	
	// calculate for expected after the random drawing.
	expectedDkCnt = initDeckCount - (2*randDraw);	// number of drawn village and it's draw effect
	
	// do the actual at end of loop (or within loop?)
	
	// RANDOM TESTING: have user either draw 1 to 3 cards
	// test Village
	// give a player the village card
	for(i = 0; i < randDraw; i++)
		gainCard(village, &G, 2, currentPlayer);
	
	A = 0;
	// go through hand to look for the village card
	for (i = 0; i < numHandCards(&G); i++) {
		
		if(handCard(i, &G) == village){
			playCard(i,-1,-1,-1,&G);	// play the village card when found
			A++;
			
			// testing drawn card
			if(G.handCount[0] == currentCardNum){	// not plus 1 because playing card makes us lose 1 card, then we draw one card
				printf("TEST RESULT #1.%d: PASSED- Village provided one card.\n", A);
			}
			else{
				printf("TEST RESULT #1.%d: FAILED- Village did not provide one card.\n", A);
				printf("\tExpected cardNum: %d\n\tActual cardNum: %d\n",currentCardNum,G.handCount[0]);
			}
				
			// testing number of actions
			if(G.numActions == currentActNum+1){	// plus one currentActNum is 1- we expect 2
				printf("TEST RESULT #2.%d: PASSED- Village provided two extra turns.\n", A);
			}
			else{
				printf("TEST RESULT #2.%d: FAILED- Village did not provide two extra turns.\n", A);
				printf("\tExpected actionNum: %d\n\tActual actionNum: %d\n",currentActNum+1,G.numActions);
			}
		
		}
	}
	
	// get actual deck count at end of test and compare to expected result
	actualDeckCnt = G.deckCount[0];
	if(expectedDkCnt == actualDeckCnt)
		printf("TEST RESULT- DECK COUNT: PASSED- Expected deck amount (%d) equals actual deck amount (%d)\n", expectedDkCnt, actualDeckCnt);
	else
		printf("TEST RESULT- DECK COUNT: FAILED- Expected deck amount (%d) different from actual deck amount (%d)\n", expectedDkCnt, actualDeckCnt);
	
	
    return 0;
}
