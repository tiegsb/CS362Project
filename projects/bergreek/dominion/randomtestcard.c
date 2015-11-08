#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>
#include <stdlib.h>

void test_steward(struct gameState *G, int p, int handPos, int choice1, int choice2, int choice3)
{
	int handCount = G->handCount[p];
	int deckCount = G->deckCount[p];
	int discardCount = G->discardCount[p];
	int coins = G->coins;

	stewardEffect(G, p, handPos, choice1, choice2, choice3);

	if (choice1 == 1) {

		if (G->handCount[p] == handCount + 1) {
			//printf("PASS - Choice 1, Player %d has + 2 cards.\n", p);
		}
		else {
			printf("FAIL - Choice 1, Player %d has %d cards, expected %d.\n", p, G->handCount[p], handCount + 1);
		}
	}

	if (choice1 == 2) {

		if (G->coins == coins + 2)  {
			//printf("PASS - Choice 2, Player %d has + 2 coins.\n", p);
		}
		else {
			printf("FAIL - Choice 2, Player %d has %d coins, expected %d.\n", p, G->coins, coins + 2);
		}
	}

	if (choice1 == 0) {

		if (G->handCount[p] == handCount - 1) {
			//printf("PASS - Choice 3, Player %d has - 2 cards in hand.\n", p);
		}
		else
			printf("FAIL - Choice 3, Player %d has %d cards in hand, expected %d.\n", p, G->handCount[p], handCount - 1);

		if (G->discardCount[p] == discardCount) {
			//printf("PASS - Choice 3, Player %d added no cards to discard pile.\n", p);
		}
		else
			printf("FAIL - Choice 3, Player %d has %d cards in discard pile, expected %d.\n", p, G->discardCount[p], discardCount);

		if (G->deckCount[p] == deckCount) {
			//printf("PASS - Choice 3, Player %d added no cards to deck.\n", p);
		}
		else
			printf("FAIL - Choice 3, Player %d has %d cards in deck, expected %d.\n", p, G->deckCount[p], deckCount);
	}

	return;
}

int main ()
{
	int num_tests = 500;

	printf("RANDOM TESTING stewardEffect():\n");
	
	int i;
	for (i = 0; i < num_tests; i++)
	{
		int choice1;
		int choice2 = 0;
		int choice3 = 0;
		for (choice1 = 0; choice1 <= 2; choice1++)
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
			int handPos = 1;

			if (choice1 == 0) {
				choice2 = rand() % (G.handCount[p]);
				choice3 = rand() % (G.handCount[p]);
			}

			test_steward(&G, p, handPos, choice1, choice2, choice3);
		}
	}
	
	return 0;
}
