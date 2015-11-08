#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"
#include "interface.h"
#include <time.h>

int testAdventurer()
{
	srand(time(NULL)); //Set the seed for the random tester
	int seed = 2500;
	int numPlayers = 2;
	int player = 0;
	int j = 0,
		k = 0;
	int handCount = 0;
	int discardCount = 0;
	int hand[10] = { adventurer, embargo, steward, cutpurse, outpost
		, mine, smithy, remodel, great_hall, feast };
	struct gameState testState;
	int randNum = 0;
	int failed_tests = 0,
		treasuresDrawn = 0,
		oldTreasures = 0,
		newTreasures = 0;
	seed = rand() % 10000;
	printf("Initializing game with seed %d\n", seed);
	memset(&testState, 23, sizeof(struct gameState));
	//Initialize the game
	initializeGame(numPlayers, hand, seed, &testState);
	testState.whoseTurn = player;
	testState.hand[player][0] = adventurer;
	

			randNum = rand() % 27;
			testState.deck[player][j] = randNum;
			printf("Player %d's deck at position %d: %d\n", player, j, testState.deck[player][j]);

		testState.deckCount[player] = 50;
		handCount = testState.handCount[player];
		discardCount = testState.discardCount[player];
		//call adventurer function
		printf("Calling Adventurer function\n");
		adventurerFunction(3, player, &testState, 1, 0, j, k);
		
		printf("Number of cards in hand: %d\n", testState.handCount[player]);
		if (testState.handCount[player] <= handCount)
		{
			printf("FAIL: Card not added to hand\n");
			failed_tests++;
		}

		//Add up the number of treasures in the hand
		for ( k = 0; k < testState.handCount[player]; k++)
		{
			if (testState.hand[player][j] == copper || testState.hand[player][j] == silver || testState.hand[player][j] == gold)
				treasuresDrawn++;
		}

		printf("Printing the player's hand: \n");
		for (j = 0; j < testState.handCount[player]; j++)
			printf("%d, ", testState.hand[player][j]);

		if (treasuresDrawn > 0) {
			if (newTreasures <= oldTreasures)
				printf("FAIL: Treasures not drawn correctly");
		}
	
		printf("\n");
		if (&testState.discardCount[player] <= discardCount) {
			printf("FAIL: Adventurer card not discarded\n");
			failed_tests++;
		}
	return failed_tests;


}

int main()
{
	int failed_tests;
	int failaccumulator;
	int i;
	for ( i = 0; i < 100; i++)
	{
		printf("\n---------RANDOM TEST ITERATION : %d---------\n", (i+1));
		failed_tests = testAdventurer();
		if (failed_tests > 0)
			failaccumulator += failed_tests;
		printf("Number of failed tests: %d\n", failed_tests);
		printf("--------------------------------------------\n");
	}
	printf("Total number of failed tests: %d\n", failaccumulator);
	printf("\n");
	return 0;
}