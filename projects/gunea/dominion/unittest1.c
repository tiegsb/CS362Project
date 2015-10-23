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
	int p, r;
	int hand[10] = { adventurer, embargo, steward, cutpurse, outpost
		, mine, smithy, remodel, great_hall, feast };
	struct gameState testState;
	int maxHandCount = 5;
	// arrays of all coppers, silvers, and golds
	int coppers[MAX_HAND];
	int silvers[MAX_HAND];
	int golds[MAX_HAND];
	for (int c = 0; c < MAX_HAND; c++)
	{
		coppers[c] = copper;
		silvers[c] = silver;
		golds[c] = gold;
	}
	printf("Testing updateCoins(): \n");

	printf("-----------------------------------------\n");
	printf("Testing with a hand full of the same treasure cards\n");
	for (int i = 0; i < players; i++)
	{
		for (int j = 0; j < maxHandCount; j++)
		{
			for (int k = 0; k < maxBonus; k++)
			{
				printf("Player: %d | Treasures in hand: %d | Bonus: %d\n", i, j, k);

				//Initialize the game
				initializeGame(players, hand, seed, &testState);

				//set the hand count
				testState.handCount[i] = j;

				printf("Testing coppers\n");
				//set all cards to coppers
				memcpy(testState.handCount[i], coppers, (sizeof(int)*j));

				//call the function
				updateCoins(i, &testState, k);

				//Print results
				if (testState.coins == (j * 1 + k))
					printf("PASS: ");
				else
					printf("FAIL: ");
				printf("Expected = %d | Actual = %d\n", j * 1 + k, testState.coins);


				printf("Testing silvers\n");
				//set all cards to silvers
				memcpy(testState.handCount[i], silvers, (sizeof(int)*j));

				//call the function
				updateCoins(i, &testState, k);

				//Print results
				if (testState.coins == (j * 2 + k))
					printf("PASS: ");
				else
					printf("FAIL: ");
				printf("Expected = %d | Actual = %d\n", j * 2 + k, testState.coins);

				printf("Testing golds\n");
				//set all cards to golds
				memcpy(testState.handCount[i], golds, (sizeof(int)*j));

				//call the function
				updateCoins(i, &testState, k);

				//Print results
				if (testState.coins == (j * 3 + k))
					printf("PASS: ");
				else
					printf("FAIL: ");
				printf("Expected = %d | Actual = %d\n", j * 3 + k, testState.coins);
			}
		}
	}

	printf("-----------------------------------------\n");
	printf("\n");










	return 0;
}