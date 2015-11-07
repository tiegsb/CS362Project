#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"
#include "interface.h"
#include <time.h>

int testGreatHall()
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
		numActions = 0;
	seed = rand() % 10000;
	printf("Testing Great Hall Card\n");
	printf("Initializing game with seed %d\n", seed);
	memset(&testState, 23, sizeof(struct gameState));
	//Initialize the game
	initializeGame(numPlayers, hand, seed, &testState);
	testState.whoseTurn = player;
	testState.hand[player][0] = great_hall;
	randNum = rand() % 6 + 1;
	testState.deckCount[player] = 50;
	handCount = testState.handCount[player];
	discardCount = testState.discardCount[player];
	numActions = testState.numActions;

	//call great hall function
		
	printf("------------------------------\n");
	printf("Playing Great Hall Card\n");
	greathallFunction(player, &testState, randNum);

	if (testState.numActions <= numActions)
	{
		failed_tests++;
		printf("FAIL: Number of actions not incremented\n");
	}
	if (testState.handCount[player] <= handCount)
	{
		failed_tests++;
		printf("FAIL: Card not added to hand\n");
	}

	if (testState.discardCount[player] <= discardCount)
	{
		failed_tests++;
		printf("FAIL: Card not discarded\n");
	}
	printf("------------------------------\n");
	printf("\n");

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
		failed_tests = testGreatHall();
		if (failed_tests > 0)
			failaccumulator += failed_tests;
		printf("Number of failed tests: %d\n", failed_tests);
		printf("--------------------------------------------\n");
	}
	printf("Total number of failed tests: %d\n", failaccumulator);
	printf("\n");
	return 0;
}