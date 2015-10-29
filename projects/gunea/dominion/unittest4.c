#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define CARD_COUNTING 0

int main()
{

	int seed = 2500;
	int players = 2;
	int result;
	int i = 0;
	int j, k;
	int whichCard;
	int failedtests = 0;
	int hand[10] = { adventurer, embargo, steward, cutpurse, outpost
		, mine, smithy, remodel, great_hall, feast };
	struct gameState testState;
	memset(&testState, 23, sizeof(struct gameState));
	//Initialize the game
	initializeGame(players, hand, seed, &testState);
	
	printf("Testing isGameOver(): \n");
	printf("-----------------------------------------\n");
	printf("Testing no province cards\n");
	printf("Number of province cards: %d\n", testState.supplyCount[province]);
	printf("Setting provinces to zero...\n");
	testState.supplyCount[province] = 0;
	printf("Now # of province cards: %d\n", testState.supplyCount[province]);
	
	result = isGameOver(&testState);
	printf("Result: %d\n", result);
	if (result > 0)
	{
		printf("PASS: No provinces left, game over\n");
	}
	else
	{
		printf("FAIL: Game not over");
		failedtests++;
	}


	printf("-----------------------------------------\n");
	printf("\n");
	printf("\n");
	printf("-----------------------------------------\n");
	testState.supplyCount[province] = 8;
	printf("Testing if all supply piles are not zero\n");
	//test when cards go to deck
	for (whichCard = curse; whichCard < treasure_map; whichCard++)
	{
		
		if (supplyCount(whichCard, &testState) <= 0)
			testState.supplyCount[whichCard] += 5;
		//printf("Amount of Card #%d: %d\n", whichCard, supplyCount(whichCard, &testState));
	}
	printf("Total # of empty piles: %d\n", i);
	printf("Calling isGameOver()\n");
	result = isGameOver(&testState);
	printf("Result: %d\n", result);
	if (result == 0)
	{
		printf("PASS: Game not over!\n");
	}
	else
	{
		printf("FAIL: Game over!\n");
		failedtests++;
	}
	
	printf("-----------------------------------------\n");
	printf("\n");
	printf("\n");
	printf("-----------------------------------------\n");
	i = 0;
	printf("Testing if one supply pile is zero\n");
	for (whichCard = curse; whichCard < treasure_map; whichCard++)
	{

		if (supplyCount(whichCard, &testState) <= 0)
			testState.supplyCount[whichCard] += 5;
		//printf("Amount of Card #%d: %d\n", whichCard, supplyCount(whichCard, &testState));
	}
	printf("Setting one card to zero\n");
	testState.supplyCount[embargo] = 0;
	i++;
	printf("Total # of empty piles: %d\n", i);
	printf("Calling isGameOver()\n");
	result = isGameOver(&testState);
	printf("Result: %d\n", result);
	if (result == 0)
	{
		printf("PASS: Game not over!\n");
	}
	else
	{
		printf("FAIL: Game over!\n");
		failedtests++;
	}

	printf("-----------------------------------------\n");
	printf("\n");
	printf("\n");
	printf("-----------------------------------------\n");
	i = 0;
	printf("Testing if two supply piles are zero\n");
	for (whichCard = curse; whichCard < treasure_map; whichCard++)
	{

		if (supplyCount(whichCard, &testState) <= 0)
			testState.supplyCount[whichCard] += 5;
		//printf("Amount of Card #%d: %d\n", whichCard, supplyCount(whichCard, &testState));
	}
	printf("Setting two cards to zero\n");
	testState.supplyCount[embargo] = 0;
	testState.supplyCount[smithy] = 0;
	i+=2;
	printf("Total # of empty piles: %d\n", i);
	printf("Calling isGameOver()\n");
	result = isGameOver(&testState);
	printf("Result: %d\n", result);
	if (result == 0)
	{
		printf("PASS: Game not over!\n");
	}
	else
	{
		printf("FAIL: Game over!\n");
		failedtests++;
	}

	printf("-----------------------------------------\n");
	printf("\n");
	printf("\n");
	printf("-----------------------------------------\n");
	i = 0;
	printf("Testing if three supply piles are zero\n");
	for (whichCard = curse; whichCard < treasure_map; whichCard++)
	{

		if (supplyCount(whichCard, &testState) <= 0)
			testState.supplyCount[whichCard] += 5;
		//printf("Amount of Card #%d: %d\n", whichCard, supplyCount(whichCard, &testState));
	}
	printf("Setting three cards to zero\n");
	testState.supplyCount[embargo] = 0;
	testState.supplyCount[smithy] = 0;
	testState.supplyCount[adventurer] = 0;
	i += 3;
	printf("Total # of empty piles: %d\n", i);
	printf("Calling isGameOver()\n");
	result = isGameOver(&testState);
	printf("Result: %d\n", result);
	if (result > 0)
	{
		printf("PASS: Game over!\n");
	}
	else
	{
		printf("FAIL: Game not over!\n");
		failedtests++;
	}
	printf("-----------------------------------------\n");
	printf("\n");
	printf("\n");
	printf("-----------------------------------------\n");
	i = 0;
	printf("Testing if more than three supply piles are zero\n");
	for (whichCard = curse; whichCard < treasure_map; whichCard++)
	{

		if (supplyCount(whichCard, &testState) <= 0)
			testState.supplyCount[whichCard] += 5;
		//printf("Amount of Card #%d: %d\n", whichCard, supplyCount(whichCard, &testState));
	}
	printf("Setting four cards to zero\n");
	testState.supplyCount[embargo] = 0;
	testState.supplyCount[smithy] = 0;
	testState.supplyCount[adventurer] = 0;
	testState.supplyCount[outpost] = 0;
	i += 4;
	printf("Total # of empty piles: %d\n", i);
	printf("Calling isGameOver()\n");
	result = isGameOver(&testState);
	printf("Result: %d\n", result);
	if (result > 0)
	{
		printf("PASS: Game over!\n");
	}
	else
	{
		printf("FAIL: Game not over!\n");
		failedtests++;
	}
	printf("-----------------------------------------\n");
	printf("\n");

	printf("Failed tests: %d\n", failedtests);
	printf("\n");
	return 0;
}