/* -----------------------------------------------------------------------
* Ben Tullis
* CS362
* Testing outpostFunction()
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
	int outpostPlayed;
	int rCard;
	int iterations = 1000;

	printf("\nTESTING outpostFunction():\n");
	for (int i = 0; i < iterations; i++)
	{
		memset(&G, 23, sizeof(struct gameState));   // clear the game state
		initializeGame(numPlayer, k, seed, &G);		// initialize a new game
		playerHandcount = G.handCount[p];			// get current player's handcount
		playerHandcount2 = G.handCount[p + 1];		// get player 2's handcount
		coins = G.coins;							// get coins
		outpostPlayed = G.outpostPlayed;			// get outpostPlayed
		rCard = rand() % 5;							// pick a random card from the hand

		outpostFunction(&G, rCard, p);				// call outpost function (handPos is not revelant) only that playerHandcount decreases by one
		playerHandcount--;							// decrement playerHandcount to match against expected values
		outpostPlayed++;							// increment outpostPlayed to match against expected values 
#if (NOISY_TEST == 1)
		printf("playerHandcount: %d G.handCount[p]: %d\n", playerHandcount, G.handCount[p]);
		printf("playerHandcount2: %d G.handCount[p + 1]: %d\n", playerHandcount2, G.handCount[p + 1]);
		printf("coins: %d G.coins: %d\n", coins, G.coins);
		printf("outpostPlayed: %d G.outpostPlayed: %d\n", outpostPlayed, G.outpostPlayed);

#endif
		assert(playerHandcount == G.handCount[p]);		// check if the we received the expected handcount
		assert(playerHandcount2 == G.handCount[p + 1]); // check that other player's cards are not disturbed
		assert(coins == G.coins);						// check that coins have not been disturbed
		assert(outpostPlayed == G.outpostPlayed);		// check that outpost Played is appropriately changed
	}
	printf("All tests passed!\n");
	return 0;
}