/* -----------------------------------------------------------------------
* Ben Tullis
* CS362
* Testing gainCard()
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
	int numSupplyCount;
	int numEnumCards = 27; 
	int playerDiscardPile;
	int playerDeckCount;
	int playerHandCount;

	printf("\nTESTING gainCard():\n");
	for (p = 0; p < numPlayer; p++)
	{
		memset(&G, 23, sizeof(struct gameState));   // clear the game state
		initializeGame(numPlayer, k, seed, &G);		// initialize a new game

		for (int j = 0; j < numEnumCards; j++)		// iterate over each card in turn
		{
			numSupplyCount = 101;					// set number of cards per card type
			G.supplyCount[j] = numSupplyCount;
			playerDiscardPile = G.discardCount[p];
			playerDeckCount = G.deckCount[p];
			playerHandCount = G.handCount[p];

			for (int k = 0; numSupplyCount > 3; k++)// iteration numSupplyCount number of times over each card
			{
#if (NOISY_TEST == 1)
				printf("BEFORE G.supplyCount[%d]: %d  numSupplyCount: %d\n",j, G.supplyCount[j], numSupplyCount);
#endif
				gainCard(j, &G, 0, p);				// sending 'discard' flag
				numSupplyCount--;					// decrement numSupplycount to match expectd return values
				playerDiscardPile++;				// increment playerDiscardPile to match expected return values
#if (NOISY_TEST == 1)
				printf("AFTER G.supplyCount[%d]: %d  numSupplyCount: %d\n", j, G.supplyCount[j], numSupplyCount);
#endif
				assert_msg(G.supplyCount[j] == numSupplyCount && G.discardCount[p] == playerDiscardPile) // check if the number s match up.
				{
					printf("ASSERTION G.supplyCount[j] == numSupplyCount && G.discardCount[p] == playerDiscardPile"
						"File: %s, Line: %d, Iteration: p = %d, card %d, discard number %d\n",
						__FILE__, __LINE__ - 2, p, j, k); //Failure Message
				}
#if (NOISY_TEST == 1)
				printf("BEFORE G.deckCount[%d]: %d  playerDeckCount: %d\n", j, G.deckCount[p], playerDeckCount);
#endif
				gainCard(j, &G, 1, p);				// sending 'add to deck' flag
				numSupplyCount--;					// decrement numSupplycount to match expectd return values
				playerDeckCount++;					// increment playerDeckCount to match expected return values
#if (NOISY_TEST == 1)
				printf("AFTER G.deckCount[%d]: %d  playerDeckCount: %d\n", j, G.deckCount[p], playerDeckCount);
#endif
				assert_msg(G.supplyCount[j] == numSupplyCount && G.deckCount[p] == playerDeckCount) // check if the number s match up.
				{
					printf("ASSERTION G.supplyCount[j] == numSupplyCount && G.deckCount[p] == playerDeckCount"
						"File: %s, Line: %d, Iteration: p = %d, card %d, discard number %d\n",
						__FILE__, __LINE__ - 2, p, j, k); //Failure Message
				}
#if (NOISY_TEST == 1)
				printf("BEFORE G.handCount[%d]: %d  playerHandCount: %d\n", j, G.handCount[p], playerHandCount);
#endif
				gainCard(j, &G, 2, p);				// sending 'add to hand' flag
				numSupplyCount--;					// decrement numSupplycount to match expectd return values
				playerHandCount++;					// increment playerHandCount to match expected return values
#if (NOISY_TEST == 1)
				printf("AFTER G.handCount[%d]: %d  playerHandCount: %d\n", j, G.handCount[p], playerHandCount);
#endif
				assert_msg(G.supplyCount[j] == numSupplyCount && G.handCount[p] == playerHandCount) // check if the number s match up.
				{
					printf("ASSERTION G.supplyCount[j] == numSupplyCount && G.handCount[p] == playerHandCount"
						"File: %s, Line: %d, Iteration: p = %d, card %d, discard number %d\n",
						__FILE__, __LINE__ - 2, p, j, k); //Failure Message
				}
			}
		}
	}

	printf("All tests passed!\n");

	return 0;
}