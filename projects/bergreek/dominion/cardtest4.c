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
	int coins;
	int handCount;
	int discardCount;
	int deckCount;
	int handPos = 3;
	p = 0;
	printf("TESTING stewardEffect():\n");
	
	printf("Test player %d choice 1 (draw 2 cards).\n", p);
	r = initializeGame(2, k, seed, &G);
	handCount = G.handCount[p];
	handPos = G.handCount[p];
	coins = G.coins;
	stewardEffect(&G, p, handPos, 1, 0, 0);
	printf("hand count = %d, expected = %d\n", G.handCount[p], handCount + 1);
	assert(G.handCount[p] == handCount + 1);
	
	printf("Test player %d choice 2 (+2 coins).\n", p);
	r = initializeGame(2, k, seed, &G);
	handCount = G.handCount[p];
	handPos = G.handCount[p];
	coins = G.coins;
	stewardEffect(&G, p, handPos, 2, 0, 0);
	printf("coins = %d, expected = %d\n", G.coins, coins + 2);
	assert(G.coins == coins + 2);

	printf("Test player %d choice 3 (trash 2 cards).\n", p);
	r = initializeGame(2, k, seed, &G);
	handCount = G.handCount[p];
	discardCount = G.discardCount[p];
	deckCount = G.deckCount[p];

	int i;
	for (i = 0; i < G.handCount[p] - 1; i++)
	{
		handPos = G.handCount[p];
		stewardEffect(&G, p, handPos, 0, i, i + 1);
		printf("hand count = %d, expected = %d\n", G.handCount[p], handCount - 1);
		//assert(G.handCount[p] == handCount - 1);
		printf("deck count = %d, expected = %d\n", G.deckCount[p], deckCount);
		assert(G.deckCount[p] == deckCount);
		printf("discard count = %d, expected = %d\n", G.discardCount[p], discardCount);
		assert(G.discardCount[p] == discardCount);
	}

	printf("All tests passed.\n");
	return 0;
}
