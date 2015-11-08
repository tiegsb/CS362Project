/* -----------------------------------------------------------------------
 * Author: Tony Huynh		CS 362		unittest1.c

 * This test will if the player has gained a card (testGainCard)
 
 * Include the following lines in your makefile:
 *
 * testGainCard: unittest1.c dominion.o rngs.o
 *      gcc -o testGainCard -g  unittest1.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 0

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
    // making variable for before gainCard
    int beforeGainCard;
	int currentPlayer = whoseTurn(&G);

    printf ("TESTING gainCard():\n");
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
	for (p = 0; p < numPlayer; p++)
    {
		beforeGainCard = 0;	// set beforeGainCard to zero before test
        for (handCount = 1; handCount <= maxHandCount; handCount++)
        {
                //printf("Last card in hand: %d\n", handCard(handCount, &G));            
				gainCard(gold, &G, 2, currentPlayer);		// add a test gold card to the current player's hand
                G.handCount[p] = handCount;                 // set the number of cards on hand after gaining card
				//printf("Before gain num: %d\tActual card num: %d\n",beforeGainCard,G.handCount[p]);
				//assert(beforeGainCard == G.handCount[p]-1);	// check to see if beforeGainCard is the same as current hand minus 1
				if(beforeGainCard == G.handCount[p]-1){
					flagInt = 0;
				}
				beforeGainCard = G.handCount[p];	// update the new beforeGainCard

        }
    }
	
	if(flagInt == 1){ 
		printf("TEST RESULT: FAILED- gainCard did not provide a card.\n");
	}
	else {
		printf("TEST RESULT: PASSED- gainCard successful\n");
	}
	
    return 0;
}