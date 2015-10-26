/* -----------------------------------------------------------------------
 * Author: Tony Huynh		CS 362		cardtest1.c

 * This will test the Village Card
 
 * Include the following lines in your makefile:
 *
 * testVillage: cardtest3.c dominion.o rngs.o
 *      gcc -o testVillage -g  cardtest3.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {	
	int i;	// loop variable
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

    // initialize game state
	printf ("TESTING Village():\n");
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
	
	// test Village
	// give a player the village card
	gainCard(village, &G, 2, currentPlayer);
	
	// prepare information before playing village
	currentCardNum = G.handCount[0];
	currentActNum = 1;
	
	// go through hand to look for the village card
	for (i = 0; i < numHandCards(&G); i++) {
		
		if(handCard(i, &G) == village){
			playCard(i,-1,-1,-1,&G);	// play the village card when found
			
			// testing drawn card
			if(G.handCount[0] == currentCardNum){	// not plus 1 because playing card makes us lose 1 card, then we draw one card
				printf("TEST RESULT #1: PASSED- Village provided one card.\n");
			}
			else{
				printf("TEST RESULT #1: FAILED- Village did not provide one card.\n");
				printf("\tExpected cardNum: %d\n\tActual cardNum: %d\n",currentCardNum,G.handCount[0]);
			}
				
			// testing number of actions
			if(G.numActions == currentActNum+1){	// plus one currentActNum is 1- we expect 2
				printf("TEST RESULT #2: PASSED- Village provided two extra turns.\n");
			}
			else{
				printf("TEST RESULT #2: FAILED- Village did not provide two extra turns.\n");
				printf("\tExpected actionNum: %d\n\tActual actionNum: %d\n",currentActNum+1,G.numActions);
			}
		
		}
	}
	
	
    return 0;
}