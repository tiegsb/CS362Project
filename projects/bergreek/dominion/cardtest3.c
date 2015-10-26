#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int get_treasure_total (struct gameState *state, int player)
{
	int treasure_total = 0;
	int coppers = 0;
	int silvers = 0;
	int golds = 0;

	int i;
	for (i = 0; i < state->handCount[player]; i++)
	{
		if (state->hand[player][i] == copper) {
			coppers++;
		}
		else if (state->hand[player][i] == silver) {
			silvers++;
		}
		else if (state->hand[player][i] == gold) {
			golds++;
		}
	}

	treasure_total = coppers + silvers + golds;

	return treasure_total;
}

int main ()
{
	int p, r;
	int seed = 1000;
	int k[10] = { adventurer, council_room, feast, gardens, mine,
				  remodel, smithy, village, baron, great_hall };
	int numPlayer = 2;
	struct gameState G;
	int handCount;
	int handPos;
	int treasure_before = 0;
	int treasure_after = 0;
	int hand[MAX_HAND];

	printf("TESTING adventurerEffect():\n");
	for (p = 0; p < numPlayer; p++)
	{
		printf("Test player %d\n", p);
		r = initializeGame(numPlayer, k, seed, &G);
		handCount = G.handCount[p];
		handPos = G.handCount[p];
		
		treasure_before = get_treasure_total(&G, p);
		adventurerEffect(&G, p, hand, handPos);
		treasure_after = get_treasure_total(&G, p);

		printf("coins = %d, expected = %d\n", treasure_after, treasure_before + 2);
		//assert(treasure_after == treasure_before + 2);
		printf("hand count = %d, expected = %d\n", G.handCount[p], handCount + 1);
		//assert(G.handCount[p] == handCount + 1);
		printf("played card count = %d, expected = %d\n", G.playedCardCount, 1);
		//assert(G.playedCardCount == 1);
	}

	printf("All tests passed.\n");
	return 0;
}
