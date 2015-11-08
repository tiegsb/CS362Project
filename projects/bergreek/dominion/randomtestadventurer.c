#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>
#include <stdlib.h>

int get_treasure_total (struct gameState *G, int p)
{
	int treasure_total = 0;
	int coppers = 0;
	int silvers = 0;
	int golds = 0;

	int i;
	for (i = 0; i < G->handCount[p]; i++)
	{
		if (G->hand[p][i] == copper) {
			coppers++;
		}
		else if (G->hand[p][i] == silver) {
			silvers++;
		}
		else if (G->hand[p][i] == gold) {
			golds++;
		}
	}

	treasure_total = coppers + silvers + golds;

	return treasure_total;
}

void test_adventurer (struct gameState *G, int p)
{
	int hand[MAX_HAND];
	int handPos = 1;

	int handCount = G->handCount[p];
	int playedCardCount = G->playedCardCount;

	int treasure_before;
	int treasure_after;

	treasure_before = get_treasure_total(G, p);
	adventurerEffect(G, p, hand, handPos);
	treasure_after = get_treasure_total(G, p);

	if (treasure_after == treasure_before + 2) {
		//printf("PASS - Player %d has 2 more treasure cards.\n", p);
	}
	else
		printf("FAIL - Player %d has %d treasure cards now, expected %d.\n", p, treasure_after, treasure_before + 2);

	if (G->handCount[p] == handCount + 1) {
		//printf("PASS - Player %d has 2 more cards in hand.\n", p);
	}
	else
		printf("FAIL - Player %d has %d treasure cards in hand, expected %d.\n", p, G->handCount[p], handCount + 1);

	if (G->playedCardCount == playedCardCount + 1) {
		//printf("PASS - The adventurer card has been played.\n");
	}
	else
		printf("FAIL - The adventurer card has not been played.\n");

	return;
}

int main ()
{
	int num_tests = 500;

	printf("RANDOM TESTING adventurerEffect():\n");

	int i;
	for (i = 0; i < num_tests; i++)
	{

		int seed = rand();
		int p = rand() % 2;
		
		int k[10] = { adventurer, council_room, feast, gardens, mine,
			  		  remodel, smithy, village, baron, great_hall };
		
		struct gameState G;

		initializeGame(2, k, seed, &G);
		G.deckCount[p] = rand() % MAX_DECK;
		G.discardCount[p] = rand() % MAX_DECK;
		G.handCount[p] = rand() % MAX_HAND;

		test_adventurer(&G, p);
	}

	return 0;
}
