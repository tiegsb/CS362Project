#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main()
{
	int seed = 2500;
	int players = 2;
	int maxBonus = 20;
	int c, i, j, k;
	int failedtests = 0;
	int playedCount;
	int hand[10] = { adventurer, embargo, steward, cutpurse, outpost
		, mine, smithy, remodel, great_hall, feast };
	struct gameState testState;


	memset(&testState, 23, sizeof(struct gameState));
	//Initialize the game
	initializeGame(players, hand, seed, &testState);

	playedCount = testState.playedCardCount;

	for (i = 0; i < players; i++)
	{	
		printf("------------------------------\n");
		printf("Player %d | Cards in hand: %d\n", i, numHandCards(&testState));
		printf("Number of played cards: %d\n", playedCount);
		for (c = 0; c < testState.handCount[i]; c++)
		{
			if (&testState.hand[i][c] == smithy) {
				printf("smithy found\n");
				k = 1;
			}
		}
		if (k != 1)
		{
			testState.hand[i][1] = smithy;
		}
		for (c = 0; c < testState.handCount[i]; c++)
		{
			if (&testState.hand[i][c] == smithy) {
				printf("smithy found\n");
				//k = 1;
			}
		}
		printf("Playing Smithy Card\n");
		smithyFunction(i, &testState, 1, j);
		k = testState.playedCardCount;
		printf("Cards in hand: %d\n", i, numHandCards(&testState));
		printf("Number of played cards: %d\n", playedCount);
		printf("------------------------------\n");
		printf("\n");
	}
	return 0;
}