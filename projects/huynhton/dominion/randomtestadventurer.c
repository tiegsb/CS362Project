/* -----------------------------------------------------------------------
 * Author: Tony Huynh		CS 362		randomtestadventure.c

 * This will test the Adventurer Card
 
 * Include the following lines in your makefile:
 *
 * randomAdventurer: randomtestadventurer.c dominion.o rngs.o
 *      gcc -o randomAdventurer -g  randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */ 	
// adding  comment for commit
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>	// incorporate simple random testing
#include "rngs.h"

int main() {
	srand(time(NULL));	
	int i, j, A;	// loop variables
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
	
	// keeping random test simple with a max of three cards. We can change this to get a higher value
	int randDraw = rand()%3 + 1;	// initialize the random number of times adventurer will draw

	/// CHANGE RANDOM ITERATION ABOVE
	
    // initialize game state
	printf ("TESTING adventurer():\n");
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

	// CHECK: deck count
	// get initial deck count, calculate expected, then get actual at the end
	initDeckCount = G.deckCount[0];
	
	// calculate the expected deck count
	
	
	// test Adventurer
	// give a player the adventurer card
	for(i = 0; i < randDraw; i++)
		gainCard(adventurer, &G, 2, currentPlayer);
	
	currentCardNum = G.handCount[0];
	// go through hand to look for the adventurer card
	A=0;
	for (i = 0; i < numHandCards(&G); i++) {
		// CHECK: treasure cards, rather than just gaining two cards
		//printf("DiscardCount: %d\n", G.discardCount[0]);
		if(handCard(i, &G) == adventurer){
			playCard(i,-1,-1,-1,&G);	// play the adventurer card when found
			A++;
			if(G.handCount[0] == currentCardNum+1){
				printf("TEST RESULT #%d: PASSED- Adventurer provided two cards.\n", A);
				printf("\tExpected cardNum: %d\n\tActual cardNum: %d\n",currentCardNum+1,G.handCount[0]);
			}
			else{
				printf("TEST RESULT #%d: FAILED- Adventurer did not provide two cards.\n", A);
				printf("\tExpected cardNum: %d\n\tActual cardNum: %d\n",currentCardNum+1,G.handCount[0]);
				
			}
		}
	}	
	
	//gainCard(estate, &G, 2, currentPlayer);	// testing if the check below works. uncommenting gainCard leads to fail. (good)
	
	// CHECK: last two card in hands- are they treasures?
	if(handCard(numHandCards(&G)-1, &G) < 7 && handCard(numHandCards(&G)-1, &G) > 3 && handCard(numHandCards(&G)-2, &G) < 7 && handCard(numHandCards(&G)-2, &G) > 3){
					printf("TEST RESULT: PASSED- last two card in hand are treasures.\n");
	}
	else{
		printf("TEST RESULT: FAILED- at least one of last two card in hand are NOT treasures.\n");
	}
	
    return 0;
}


























