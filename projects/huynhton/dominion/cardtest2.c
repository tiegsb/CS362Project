/* -----------------------------------------------------------------------
 * Author: Tony Huynh		CS 362		cardtest1.c

 * This will test the Adventurer Card
 
 * Include the following lines in your makefile:
 *
 * testAdventurer: cardtest2.c dominion.o rngs.o
 *      gcc -o testAdventurer -g  cardtest2.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */ 	

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {	
	int i, j, A;	// loop variables
    int seed = 1000;
    int numPlayer = 2;
    int r;	//, handCount;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    //int maxHandCount = 5;
	int currentPlayer = whoseTurn(&G);
	
	int currentCardNum;	// number of cards before the adventurer card is played.

    // initialize game state
	printf ("TESTING adventurer():\n");
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

	// test Adventurer
	// give a player the adventurer card
	gainCard(adventurer, &G, 2, currentPlayer);
	
	currentCardNum = G.handCount[0];
	// go through hand to look for the adventurer card
	for (i = 0; i < numHandCards(&G); i++) {
		
		if(handCard(i, &G) == adventurer){
			playCard(i,-1,-1,-1,&G);	// play the adventurer card when found
			
			if(G.handCount[0] == currentCardNum+1){
				printf("TEST RESULT: PASSED- Adventurer provided two cards.\n");
				printf("\tExpected cardNum: %d\n\tActual cardNum: %d\n",currentCardNum+1,G.handCount[0]);
			}
			else{
				printf("TEST RESULT: FAILED- Adventurer did not provide two cards.\n");
				printf("\tExpected cardNum: %d\n\tActual cardNum: %d\n",currentCardNum+1,G.handCount[0]);
				
			}
			
			//printf("Hooray!\n");
		}
	}	
	
    return 0;
}