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
	int numPlayer = 2;
	struct gameState G;
	int handCount;
	int discardCount;
	int actions;
	int handPos;

	printf("TESTING villageEffect():\n");
	for (p = 0; p < numPlayer; p++)
	{
		printf("Test player %d.\n", p);
		r = initializeGame(numPlayer, k, seed, &G);
		handCount = G.handCount[p];
		discardCount = G.discardCount[p];
		actions = G.numActions;
		handPos = G.handCount[p];

		villageEffect(&G, p, handPos);

		printf("hand count = %d, expected = %d\n", G.handCount[p], handCount);
		assert(G.handCount[p] == handCount);
		printf("discard count = %d, expected = %d\n", G.discardCount[p], discardCount + 1);
		//assert(G.discardCount[p] == discardCount + 1);
		printf("actions = %d, expected = %d\n", G.numActions, actions + 2);
		assert(G.numActions == actions + 2);
		printf("played card count = %d, expected = %d\n", G.playedCardCount, 1);
		assert(G.playedCardCount == 1);
	}

	printf("All tests passed.\n");
	return 0;
}
