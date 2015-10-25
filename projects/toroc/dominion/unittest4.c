/*
*	CS362 - Assignment 3 - unittest4.c
*	Unit Test #4: This program ensures the playCard() method
*		in dominion is working properly by running 4 tests.
*		Test #1 player tries to play a card during play phase, 
*		Test #2 player tries to play a card during buy phase,
*		Test #3 player tries to play a gold during play phase.
*		Test #4 player tries to play a card after the buy phase,
*	Author: Carol D. Toro
*	Date: 10/16/2015
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main()
{
	/*initialize variables needed*/
	int	i, numCards;
	int k[10] = { adventurer, council_room, feast, gardens, mine,
		remodel, smithy, village, baron, great_hall };
	int gameSeed;
	int numPlayer = 2;
	struct gameState Game;
	int result;
	int cardType;
	srand(time(NULL));

	/*initialize array of smithy and gold filled hands*/
	int smithyGoldHand[MAX_HAND];
	for (i = 0; i <= MAX_HAND; i++)
	{
		if (i == 0)
			smithyGoldHand[i] = smithy;

		else if (i % 2 == 0)
		{
			smithyGoldHand[i] = smithy;
		}
		else
			smithyGoldHand[i] = gold;
	}

	/*Starting Test #1*/
#if (NOISY_TEST==1)
	printf("Starting unittest4.c which checks playCard() method \n");
	printf("\n Starting Test #1 - player plays a card during play phase \n");
#endif
	/*initialize gameSeed*/
	gameSeed = rand() % 1000 + 1;

	/*clear the game state*/
	memset(&Game, 23, sizeof(struct gameState));

	/*initialize game*/
	initializeGame(numPlayer, k, gameSeed, &Game);

	/*load player 0's hand with smithy and gold*/
	memcpy(Game.hand[0], smithyGoldHand, sizeof(int) * MAX_HAND);

	/*get the number of cards in player's hand*/
	numCards = numHandCards(&Game);

	cardType = handCard(0, &Game);

	/*Smithy will be played*/
	assert(cardType == 13);

	result = playCard(0, 1, 2, 3, &Game);

	//assert(result == 0);

#if (NOISY_TEST==1)
	if (result == 0)
	{
		printf("\t Game state = %d, Expected state = %d\n", result, 0);
		printf("Test #1 passed. \n");
	}
	else
	{
		printf("\t Game state = %d, Expected state = %d\n", result, 0);
		printf("Test #1 FAILED! Bug present in playCard()... \n");
	}
	
#endif


	/*Starting Test #2*/
#if (NOISY_TEST==1)
	printf("\n Starting Test #2 - player tries to play a card during buy phase \n");
#endif

	/*Attemp to play a card during the buy phase*/
	result = playCard(0, 1, 2, 3, &Game);

	//assert(result == -1);
#if (NOISY_TEST==1)
	if (result == -1)
	{
		printf("\t Result from method = %d, Expected result from method = %d\n", result, -1);
		printf("Test #2 passed. \n");
	}
	else
	{
		printf("\t Result from method = %d, Expected result from method = %d\n", result, -1);
		printf("Test #2 FAILED! Bug present in playCard()... \n");
	}
	
#endif

	/*Starting Test #3*/
#if (NOISY_TEST==1)
	printf("\n Starting Test #3 - player tries to play a gold during play phase \n");
#endif

	/*Buy gold*/
	result = buyCard(gold, &Game);

	/*End turn*/
	endTurn(&Game);

	/*load player 1's hand with smithy and gold*/
	memcpy(Game.hand[1], smithyGoldHand, sizeof(int) * MAX_HAND);

	/*get the number of cards in player's hand*/
	numCards = numHandCards(&Game);

	/*Get the player's first card*/
	cardType = handCard(0, &Game);

	/*Attemp to play a gold during the play phase*/
	result = playCard(1, 1, 2, 3, &Game);

	//assert(result == -1);

#if (NOISY_TEST==1)
	if (result == -1)
	{
		printf("\t Result from method = %d, Expected result from method = %d\n", result, -1);
		printf("Test #3 passed. \n");
	}
	else
	{
		printf("\t Result from method = %d, Expected result from method = %d\n", result, -1);
		printf("Test #3 FAILED! Bug present in playCard()... \n");
	}
#endif

	/*player plays card in hand*/
	result = playCard(0, 1, 2, 3, &Game);

	/*player buys card*/
	result = buyCard(village, &Game);

	/*Starting Test #4*/
#if (NOISY_TEST==1)
	printf("\n Starting Test #4 - player tries to play a card after buy phase \n");
#endif

	/*player plays card in hand*/
	result = playCard(0, 1, 2, 3, &Game);

	//assert(result == -1);

#if (NOISY_TEST==1)
	if (result == -1)
	{
		printf("\t Result from method = %d, Expected result from method = %d\n", result, -1);
		printf("Test #4 passed. \n");
	}
	else
	{
		printf("\t Result from method = %d, Expected result from method = %d\n", result, -1);
		printf("Test #4 FAILED! Bug present in playCard()... \n");
	}
	
#endif

	/*End turn*/
	endTurn(&Game);


	return 0;
}
