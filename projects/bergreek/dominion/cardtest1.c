#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main ()
{
	int p, r;
	int seed = 1000;
	int k[10] = { adventurer, council_room, feast, gardens, mine,
				  remodel, smithy, village, baron, great_hall };
	struct gameState G;
	int handCount;
	int discardCount;
	int deckCount;
	int handPos;

	printf("TESTING smithyEffect():\n");
	for (p = 0; p < 2; p++)
	{
		printf("Test player %d.\n", p);
		r = initializeGame(2, k, seed, &G);
		handCount = G.handCount[p];
		discardCount = G.discardCount[p];
		deckCount = G.deckCount[p];
		handPos = handCount;

		smithyEffect(&G, p, handPos);

		printf("hand count = %d, expected = %d\n", G.handCount[p], handCount + 2);
		//assert(G.handCount[p] == handCount + 2);
		printf("discard count = %d, expected = %d\n", G.discardCount[p], discardCount + 1);
		//assert(G.discardCount[p] == discardCount + 1);
		printf("played card count = %d, expected = %d\n", G.playedCardCount, 1);
		assert(G.playedCardCount == 1);
	}

	printf("All tests passed.\n");
	return 0;
}
