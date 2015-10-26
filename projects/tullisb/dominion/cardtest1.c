/* -----------------------------------------------------------------------
* Ben Tullis
* CS362
* Testing council_roomFunction()
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
	int rCard;
	int numBuys;
	int iterations = 1000;

	printf("\nTESTING council_roomFunction():\n");
	for (int i = 0; i < iterations; i++)
	{
		memset(&G, 23, sizeof(struct gameState));   // clear the game state
		initializeGame(numPlayer, k, seed, &G);		// initialize a new game
		playerHandcount = G.handCount[p];			// get current player's handcount
		playerHandcount2 = G.handCount[p + 1];		// get player 2's handcount
		numBuys = G.numBuys;						// get players number of buys
		coins = G.coins;							// get coins
		rCard = rand() % 5;							// pick a random card from the hand

		council_roomFunction(&G, rCard, p);			// call council_roomFunction (handPos is not revelant) only that playerHandcount decreases by one
		playerHandcount += 3;						// increment playerHandcount by three to match against expected values (+4 then -1)
		playerHandcount2++;							// other player draws another card
		numBuys++;									// increment numBuys by one
#if (NOISY_TEST == 1)	
		printf("playerHandcount: %d G.handCount[p]: %d\n", playerHandcount, G.handCount[p]);
		printf("playerHandcount2: %d G.handCount[p]: %d\n", playerHandcount2, G.handCount[p+1]);
		printf("coins: %d G.coins: %d\n", coins, G.coins);
		printf("numBuys: %d G.numBuys: %d\n", numBuys, G.numBuys);
#endif
		assert(playerHandcount == G.handCount[p]);		// check if the we received the expected handcount
		assert(playerHandcount2 == G.handCount[p + 1]); // check that other player's cards have been incremented by one
		assert(coins == G.coins);						// check that coins have not been disturbed
		assert(numBuys = G.numBuys);					// check that numbuys has been incremented by one
	}
	printf("All tests passed!\n");
	return 0;
}