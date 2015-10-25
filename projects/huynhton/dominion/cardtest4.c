/* -----------------------------------------------------------------------
 * Author: Tony Huynh		CS 362		cardtest1.c

 * This will test the council_room card --> we expect this to pass
 
 * Include the following lines in your makefile:
 *
 * testCouncilRoom: cardtest4.c dominion.o rngs.o
 *      gcc -o testCouncilRoom -g  cardtest4.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {	
	int i;	// loop variables
    int seed = 1000;
    int numPlayer = 2;
    int r;	//, handCount;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    //int maxHandCount = 5;
	int currentPlayer = whoseTurn(&G);
	
	int currentCardNum;	// number of cards before the council_room card is played.
	int currentBuyNum;	// number of buys before council_room card is played.
	int otherPCardNum;	// number of other player's card. In this test, there is only one other player.
    // initialize game state
	printf ("TESTING Council_Room():\n");
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

	// test Council_Room
	// give a player the council_room card
	gainCard(council_room, &G, 2, currentPlayer);
	
	currentCardNum = G.handCount[0];
	currentBuyNum = G.numBuys;
	otherPCardNum = G.handCount[1];
	// go through hand to look for the council_room card
	for (i = 0; i < numHandCards(&G); i++) {
		
		if(handCard(i, &G) == council_room){
			playCard(i,-1,-1,-1,&G);	// play the smithy card when found
			
			// TEST #1: check number of card in player's hand
			if(G.handCount[0] == currentCardNum+3){
				printf("TEST RESULT #1: PASSED- CouncilR provided four cards.\n");
				printf("\tExpected cardNum: %d\n\tActual cardNum: %d\n",currentCardNum+3,G.handCount[0]);
			}
			else{
				printf("TEST RESULT #1: FAILED- CouncilR did not provide three cards.\n");
				printf("\tExpected cardNum: %d\n\tActual cardNum: %d\n",currentCardNum+3,G.handCount[0]);
			}
			
			// TEST #2: check user's buys number
			if(currentBuyNum+1 == G.numBuys){
				printf("TEST RESULT #2: PASSED- CouncilR provided four cards.\n");
				printf("\tExpected buys: %d\n\tActual buys: %d\n",currentBuyNum+1,G.numBuys); // +1 because user has not bought anything. We gave user the card for testing.
			}
			else{
				printf("TEST RESULT #2: FAILED- CouncilR did not provide three cards.\n");
				printf("\tExpected buys: %d\n\tActual buys: %d\n",currentBuyNum,G.numBuys);
			}
			
			// TEST #3: check other player's cardNum
			if(G.handCount[1] == otherPCardNum+1){
				printf("TEST RESULT #3: PASSED- CouncilR provided one card for other player.\n");
				printf("\tExpected cardNum: %d\n\tActual cardNum: %d\n",otherPCardNum+1,G.handCount[1]);
			}
			else{
				printf("TEST RESULT #3: FAILED- CouncilR did not provide one card for other player.\n");
				printf("\tExpected cardNum: %d\n\tActual cardNum: %d\n",otherPCardNum+1,G.handCount[1]);
			}
			//printf("Hooray!\n");
		}
	}	
	
    return 0;
}