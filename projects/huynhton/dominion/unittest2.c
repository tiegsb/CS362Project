/* -----------------------------------------------------------------------
 * Author: Tony Huynh		CS 362		unittest2.c

 * This test will if the player has discarded a card (testDiscardCard)
 
 * Include the following lines in your makefile:
 *
 * testDiscardCard: unittest2.c dominion.o rngs.o
 *      gcc -o testDiscardCard -g  unittest2.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int main() {
    //int i;
	int flagInt = 1;	// for printing message
    int seed = 1000;
    int numPlayer = 2;
    //int maxBonus = 10;
    int p, r, handCount;
    //int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;
    // making variable for before discardCard
    int beforeLoseCard;
	int currentPlayer = whoseTurn(&G);
	int counterSwitch = 0;

    printf ("TESTING discardCard():\n");
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
	for (p = 0; p < numPlayer; p++)
    {
        for (handCount = 1; handCount <= maxHandCount; handCount++)
        {
				// update the current player
				if(p == 1 && counterSwitch == 0){
					currentPlayer += 1;
					counterSwitch++; 	
				}
				
				// actual test for discard
                G.handCount[p] = handCount;                 // set the number of cards on hand 
				beforeLoseCard = G.handCount[p];
                discardCard(0, currentPlayer, &G, 1);
				//printf("Before discard num: %d\tActual card num: %d\n",beforeLoseCard,G.handCount[p]);
				//assert(beforeLoseCard-1 == G.handCount[p]);	// check to see if beforeLoseCard can match with current hand
				if(beforeLoseCard-1 == G.handCount[p]){
					flagInt = 0;
				}
        }
	
    }
					

    if( flagInt == 1 ) {
		printf("TEST RESULT: FAILED- discardCard did not pass.\n");	
	}
	else {
		printf("TEST RESULT: PASSED- discardCard successful\n");
	}
	
	
    return 0;
}