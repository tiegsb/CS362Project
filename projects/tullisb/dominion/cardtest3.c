/* -----------------------------------------------------------------------
* Ben Tullis
* CS362
* Testing smithyFunction()
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

	int seed = 1000;
	int numPlayer = 2;
	int p = 0;
	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
	struct gameState G;
	int playerHandcount;
	int playerHandcount2;
	int coins;
	int curseNum;
	int outpostPlayed;
	int iterations = 1000;

	printf("\nTESTING smithyFunction():\n");

	for (int i = 0; i < iterations; i++)
	{
		memset(&G, 23, sizeof(struct gameState));   // clear the game state
		initializeGame(numPlayer, k, seed, &G);		// initialize a new game
		playerHandcount = G.handCount[p];			// get current player's handcount
		playerHandcount2 = G.handCount[p + 1];		// get player 2's handcount
		coins = G.coins;							// get coins
		curseNum = G.hand[p + 1][curse];			// get player 2's number of curse cards
		outpostPlayed = G.outpostPlayed;			// get outpostPlayed

		smithyFunction(p, &G, 1);					// call smithy function
		playerHandcount += 3;						// increment playerHandcount to match against expected values
#if (NOISY_TEST == 1)
		printf("playerHandcount: %d G.handCount[p]: %d\n", playerHandcount, G.handCount[p]);
		printf("playerHandcount2: %d G.handCount[p]: %d\n", playerHandcount2, G.handCount[p + 1]);
		printf("coins: %d G.coins: %d\n", coins, G.coins);
		printf("curseNum: %d  G.hand[p + 1][curseNum]: %d\n", curseNum, G.hand[p + 1][curseNum]);
		printf("outpostPlayed: %d G.outpostPlayed: %d\n", outpostPlayed, G.outpostPlayed);
#endif
		assert(playerHandcount == G.handCount[p]);		// check if the we received the expected handcount
		assert(playerHandcount2 == G.handCount[p + 1]); // check that other player's cards are not disturbed
		assert(coins == G.coins);						// check that coins have not been disturbed
		assert(curseNum == G.hand[p + 1][curseNum]);	// check that no curse cards were distributed two second player
		assert(outpostPlayed == G.outpostPlayed);		// check that outpost played remains unchanged
	}

	printf("All tests passed!\n");
	return 0;
}