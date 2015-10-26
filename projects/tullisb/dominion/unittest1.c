/* -----------------------------------------------------------------------
* Ben Tullis
* CS362
* Testing supplyCount()
* -----------------------------------------------------------------------
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define assert_msg(x) for ( ; !(x) ; assert(x) )
 // set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 0
int main() {

	int seed = 1000;
	int numPlayer = 2;
	int p;
	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
	struct gameState G;
	int maxCardCount;
	int cardCount;
	int numEnumCards = 27; 

	printf("\nTESTING supplyCount():\n");
	for (p = 0; p < numPlayer; p++)
	{
		for (int i = 0; i < numEnumCards; i++)
		{
			for (maxCardCount = 5000; maxCardCount >= 0; maxCardCount--)
			{
				memset(&G, 23, sizeof(struct gameState));   // clear the game state
				initializeGame(numPlayer, k, seed, &G);		// initialize a new game
				G.supplyCount[i] = maxCardCount;			// settings card count
				cardCount = supplyCount(i, &G);				// retrieve supplyCount via supplyCount();
#if (NOISY_TEST == 1)
				printf("cardCount = %d\n", cardCount);
				printf("iteration= %d\n", i);
#endif
				assert_msg(G.supplyCount[i] == cardCount)	// check if correct number of cards is/are returned
				{
					printf("ASSERTION 'G.supplyCount[%d] == test' FAILED:"
						"File: %s, Line: %d, Iteration: p: %d, maxCardCount = %d", i,
						__FILE__, __LINE__ - 2, p, maxCardCount); //Failure Message
				}
			}
		}
	}

	printf("All tests passed!\n");

	return 0;
}