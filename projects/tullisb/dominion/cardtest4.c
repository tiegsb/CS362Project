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

int main() {
	srand(time(NULL));
	int seed = 1000;
	int numPlayer = 2;
	int p = 0;
	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
	struct gameState G;
	int playerHandcount;
	int playerHandcount2;
	int coins;
	int numBuys;
	int iterations = 1000;

	printf("\nTESTING adventurerFunction():\n");
	for (int i = 0; i < iterations; i++)
	{
		memset(&G, 23, sizeof(struct gameState));   // clear the game state
		initializeGame(numPlayer, k, seed, &G);		// initialize a new game
		playerHandcount = G.handCount[p];			// get current player's handcount
		playerHandcount2 = G.handCount[p + 1];		// get player 2's handcount
		numBuys = G.numBuys;
		coins = G.coins;							// get coins

		for (int i = 0; i < 5; i++)					// set all cards in my hand to gold to ensure that drawns cards will be treasure cards
		{
			G.hand[p][i] = copper;			
		}

		adventurerFunction(&G, p);					// call adventurerFunction (handPos is not revelant) only that playerHandcount decreases by one
		playerHandcount += 2;						// increment playerHandcount by three to match against expected values (+4 then -1)
		coins += 2;									// increment coins to reflect the increaseof two copper
#if (NOISY_TEST == 1)	
		printf("playerHandcount: %d G.handCount[p]: %d\n", playerHandcount, G.handCount[p]);
#endif
		assert(playerHandcount == G.handCount[p]);		// check if the we received the expected handcount
		assert(playerHandcount2 == G.handCount[p + 1]); // check that other player's cards have not been incremented
		assert(coins == G.coins);						// check that coins have been properly updated
		assert(numBuys = G.numBuys);					// check that numbuys remains unchanged
	}
	printf("All tests passed!\n");
	return 0;
}