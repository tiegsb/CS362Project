/* -----------------------------------------------------------------------
* Ben Tullis
* CS362
* Testing adventurerFunction()
* -----------------------------------------------------------------------
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 0


void testAdventurerFunction(struct gameState state) {
	int p = 0;
	int playerHandcount;
	int playerHandcount2;
	int coins;
	int numBuys;

	playerHandcount = state.handCount[p];			// get current variables for comparision
	playerHandcount2 = state.handCount[p + 1];		
	numBuys = state.numBuys;						
	coins = state.coins;							
	adventurerFunction(&state, p);					// call adventurerFunction (handPos is not revelant) only that playerHandcount decreases by one
	playerHandcount += 3;							// increment playerHandcount by three to reflect expected value
	coins += 2;										// increment coins to reflect expected value

#if (NOISY_TEST == 1)	
	printf("playerHancount: %d; state.hangCount[p]: %d\n", playerHandcount, state.handCount[p]);
#endif
	// check if the we received the expected handcount
	assert(playerHandcount == state.handCount[p] && "FAILURE: playerHancount is not equal to state.handCount[p]");
#if (NOISY_TEST == 1)	
	printf("playerHandcount2: %d; state.hangCount[p+1]: %d\n", playerHandcount2, state.handCount[p + 1]);
#endif
	// check that other player's cards have not been incremented
	assert(playerHandcount2 == state.handCount[p + 1] && "FAILURE: playerHandcount2 is not equal to state.handCount[p + 1]");
#if (NOISY_TEST == 1)	
	printf("coins: %d; state.coins: %d\n", coins, state.coins);
#endif
	// check that coins have been properly updated
	assert(coins == state.coins && "FAILURE: coins is not equal to state.coins");
#if (NOISY_TEST == 1)	
	printf("numBuys: %d; state.numBuys: %d\n", numBuys, state.numBuys);
#endif
	// check that numbuys remains unchanged
	assert(numBuys == state.numBuys && "FAILURE: numBuys is not equal to state.numBuys:");
}


int main() {
	srand(time(NULL));
	int numPlayer = 2;
	int p = 0;
	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
	struct gameState G;

	printf("\nTESTING adventurerFunction():\n");
	for (int i = 0; i < 2000; i++)
	{
		memset(&G, 23, sizeof(struct gameState));			// create randomized gamestate
		initializeGame(numPlayer, k, rand() % 1000, &G);
		G.handCount[p] = 5;								
		G.handCount[p + 1] = G.handCount[p];			
		for (int n = 0; n < 5; n++) {					
			G.hand[p][n] = copper;
			G.hand[p + 1][n] = copper;}
		G.numBuys = rand() % 10;						
		G.coins = rand() % 1000;						

		testAdventurerFunction(G);							// call testAdventurerFunction
	}
	printf("All tests passed!\n");
	return 0;
}