#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.c"
#include "rngs.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>


#define MAX_TEST_ITER 15000
#define numPlayers 4


int testSmithy() {
	int iterCount = 0;
	int player = 0;
	int handPos;

	int handErrorCount = 0;
	int discardErrorCount = 0;

	struct gameState G;
	struct gameState oldG;

	int k[10] = {adventurer, council_room, feast, gardens, mine,
				remodel, smithy, village, baron, great_hall};

	printf("-------RANDOM TESTING SMITHY CARD-------\n");

	while (iterCount != MAX_TEST_ITER) {
		int ogHandCount = 0;
		int newHandCount = 0;

		int ogDiscCount = 0;
		int newDiscCount = 0;

		player = rand()%4; //player can be 0 through 3, max_players is 4
		int seed = rand();

		// clear the game state
		memset(&G, 0, sizeof(struct gameState));
		memset(&oldG, 0, sizeof(struct gameState));

		// initialize a new game
		initializeGame(numPlayers, k, seed, &G);

		//set up randomly for current player
		G.deckCount[player] = rand() % MAX_DECK; //deckCount set up randomly
		G.handCount[player] = rand() % MAX_HAND; //set the handCount up randomly
		G.discardCount[player] = rand() % MAX_DECK; //discardCount set up randomly

		for(handPos = 0; handPos < G.handCount[player]; handPos++) {
			G.hand[player][handPos] = rand()%27; //set up the player hand randomly
			G.discard[player][handPos] = rand()%27; //set up the discard pile randomly, 27 because there are 27 cards
			G.deck[player][handPos] = rand()%27; //set up deck randomly, 27 because there are 27 cards
		}

		memcpy(&oldG, &G, sizeof(struct gameState)); //copy the gamestate for comparison
		
		//Call the Smithy function
		smithyCard(player, &G, 0); 

		//HAND COUNTING--------------------------------------------------------------------------------
		ogHandCount = oldG.handCount[player];
		newHandCount = G.handCount[player];

		//DISCARD COUNTING-----------------------------------------------------------------------------
		ogDiscCount = oldG.discardCount[player];
		newDiscCount = G.discardCount[player];

		//Smithy adds three cards to the hand
		if (newHandCount != ogHandCount + 2) { 
			handErrorCount++;
		}

		if (newDiscCount != ogDiscCount + 1) {
			discardErrorCount++;
		}
		
		if (iterCount < MAX_TEST_ITER) {
			printf("Testing iteration: %d, Old Hand Count = %d, New Hand Count = %d\n", iterCount, ogHandCount, newHandCount);
			printf("Old Discard Count = %d, New Discard Count = %d\n", ogDiscCount, newDiscCount);
			printf("\n");
		}
		iterCount++;
	}

	//printf("Total hand count error cases in 15k iterations: %d\n", handErrorCount);
	printf("\nTotal hand count error cases for Smithy card: %d of %d tests", handErrorCount, iterCount);
	//printf("Total discard count error cases in 15k iterations: %d\n", discardErrorCount);
	printf("\nTotal discard count error cases for Smithy card: %d of %d tests", discardErrorCount, iterCount);	
	printf("\n");
	printf("Random tests for Smithy Card complete!\n");

	return 0;
}

int main(int argc, char *argv[]) {
	srand(time(NULL));
	testSmithy();
	return 0;
}

