/*
*	CS362 - Assignment 3 - unittest3.c
*	Unit Test #3: This program runs 5 tests to ensure the
*		discardCard() method in dominion is properly working.
*		Test #1 ensure handcount is lowered with call to method, flag 0
*		Test #2 ensure playedCardCount is increased with call to method, flag 0
*		Test #3 ensure handCount is lowered when only 1 card in hand flag 1
*		Test #4 call discardCard with empty hand
*		Test #5 ensure handCount is lowered with call to method, flag 3
*
*	Author: Carol D. Toro
*	Date: 10/22/2015
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


#define NOISY_TEST 1

int main()
{
	/*initialize variables needed*/
	int	i, j, result, testHandCount, trashFlag, testPlayedCardCount, randLoop;
	int k[10] = { adventurer, council_room, feast, gardens, mine,
		remodel, smithy, village, baron, great_hall };
	int gameSeed;
	int numPlayer = 2;
	struct gameState Game;
	int p_0 = 0;
	int p_1 = 1;
	srand(time(NULL));
	

	/*Starting Test #1*/
#if (NOISY_TEST==1)
	printf("Starting unittest3.c which checks the discardCard() method \n");
	printf("\n Starting Test #1 - ensure handcount decreases with call to discardCard() \n");
#endif

	testHandCount = MAX_HAND;

	/*initialize gameSeed*/
	gameSeed = rand() % 1000 + 1;

	/*clear the game Game*/
	memset(&Game, 23, sizeof(struct gameState));

	/*initialize game*/
	initializeGame(numPlayer, k, gameSeed, &Game);


#if (NOISY_TEST == 1)
	printf("\t After initializing, handcount for p0 is %d \n", Game.handCount[p_0]);
	printf("\t After initializing, handcount for p1 is %d \n", Game.handCount[p_1]);
#endif

	/*Set P0's hand to gold and increment handCount*/
	for (i = 0; i < MAX_HAND; i++)
	{
		Game.hand[p_0][i] = gold;
		Game.handCount[p_0]++;
	}

#if (NOISY_TEST == 1)
	printf("\t P0's hand is loaded with gold, handCount is %d\n", Game.handCount[p_0]);
	printf("\t P1's left alone, handCount is %d\n", Game.handCount[p_1]);
#endif
	
	/*Set testHandCount to p0's handCount*/
	testHandCount = Game.handCount[p_0];

	/*set trashFlag for discarded hand*/
	trashFlag = 0;

	randLoop = rand() % MAX_HAND + 1;

	/*Call discardCard with flag 0 and loop thru*/
	for (j = 0; j < randLoop; j++)
	{

		//printf("Before loop, P0's handCount is %d \n", Game.handCount[p_0]);

		result = discardCard(j, p_0, &Game, trashFlag);

		//assert(result == 0);

		/*decrement testHandCount*/
		testHandCount--;

		/*print statements using for debugging*/
		//printf("After loop, P0's handCount is %d \n", Game.handCount[p_0]);
		//printf("testHandCount is %d\n", testHandCount);

		//assert(Game.handCount[p_0] == testHandCount);

		/*break out of loop if there's a bug*/
		if (Game.handCount[p_0] != testHandCount)
		{
#if (NOISY_TEST==1)
			printf("\t P0 handCount=%d Expected=%d \n", Game.handCount[p_0], testHandCount);
			printf("Test #1 FAILED! Bug present in discardCard()... \n");
#endif
			result = -1;
			break;
		}	
	}

	if (result != -1)
	{
#if (NOISY_TEST==1)
		printf("\t P0 handCount=%d Expected=%d \n", Game.handCount[p_0], testHandCount);
		printf("Test #1 passed. \n");
#endif
	}

	/*Starting Test #2*/
#if (NOISY_TEST==1)
	printf("\n Starting Test #2 - ensure playedCardCount increases with call to discardCard() \n");
#endif

	testHandCount = MAX_HAND;

	/*initialize gameSeed*/
	gameSeed = rand() % 1000 + 1;

	/*clear the game Game*/
	memset(&Game, 23, sizeof(struct gameState));

	/*initialize game*/
	initializeGame(numPlayer, k, gameSeed, &Game);


#if (NOISY_TEST == 1)
	printf("\t After initializing, playedCardCount for players is %d \n", Game.playedCardCount);
#endif

	/*Set P0's hand to gold and increment handCount*/
	for (i = 0; i < MAX_HAND; i++)
	{
		Game.hand[p_0][i] = gold;
		Game.handCount[p_0]++;
	}

#if (NOISY_TEST == 1)
	printf("\t P0's hand is loaded with gold, handCount is %d\n", Game.handCount[p_0]);
#endif

	/*Set testHandCount to p0's handCount*/
	testHandCount = Game.handCount[p_0];

	/*Set testPlayedCount to playCount*/
	testPlayedCardCount = Game.playedCardCount;

	/*set trashFlag for discarded hand*/
	trashFlag = 0;

	randLoop = rand() % MAX_HAND + 1;

	/*Call discardCard with flag 0 and loop thru*/
	for (j = 0; j < randLoop; j++)
	{
		//printf("Before loop, playedCardCount is %d \n", Game.playedCardCount);

		result = discardCard(j, p_0, &Game, trashFlag);

		//assert(result == 0);

		/*increment testPlayedCardCount*/
		testPlayedCardCount++;

		//printf("After loop, playedCardCount is %d \n", Game.playedCardCount);
		//printf("testPlayedCardCount is %d\n", testPlayedCardCount);

		//assert(Game.playedCardCount == testPlayedCardCount);

		/*break out of loop if there's a bug*/
		if (Game.playedCardCount != testPlayedCardCount)
		{
#if (NOISY_TEST == 1)
			printf("\t PlayedCardCount=%d Expected=%d \n", Game.playedCardCount, testPlayedCardCount);
			printf("Test #2 FAILED! Bug present in discardCard()... \n");
#endif
			result = -1;
			break;
		}
	}

	if (result != -1)
	{
#if (NOISY_TEST == 1)
		printf("\t PlayedCardCount=%d Expected=%d \n", Game.playedCardCount, testPlayedCardCount);
		printf("Test #2 passed. \n");
#endif
	}

	/*Start Test 3*/
#if (NOISY_TEST == 1)
	printf("\n Starting Test #3- Ensure handCount is lowered when only 1 card in hand  \n");
#endif

	testHandCount = MAX_HAND;

	/*initialize gameSeed*/
	gameSeed = rand() % 1000 + 1;

	/*clear the game Game*/
	memset(&Game, 23, sizeof(struct gameState));

	/*initialize game*/
	initializeGame(numPlayer, k, gameSeed, &Game);
	
	/*decrement P0's handcount to 1*/
	for (i = 0; i < 3; i++)
	{
		result = discardCard(j, p_0, &Game, 1);
	}

#if (NOISY_TEST == 1)
	printf("\t P0's handCount is %d before discardCard\n", Game.handCount[p_0]);
#endif

	/*Set testHandCount to p0's handCount*/
	testHandCount = Game.handCount[p_0];

	/*set trashFlag for discarded hand*/
	trashFlag = 3;

	randLoop = rand() % MAX_HAND + 1;

	/*Call discardCard twice */

	result = discardCard(1, p_0, &Game, trashFlag);
	testHandCount--;
	result = discardCard(1, p_0, &Game, trashFlag);
	testHandCount--;

	//assert(Game.handCount[p_0] == testHandCount);


	if (Game.handCount[p_0] != testHandCount)
	{
#if (NOISY_TEST == 1)
		printf("\t P0 handCount=%d Expected=%d \n", Game.handCount[p_0], testHandCount);
		printf("Test #3 FAILED! Bug present in discardCard()... \n");
#endif
	}
	else
	{
#if (NOISY_TEST == 1)
		printf("\t P0 handCount=%d Expected=%d \n", Game.handCount[p_0], testHandCount);
		printf("Test #3 passed. \n");
#endif
	}

	/*Start Test 4*/
#if (NOISY_TEST == 1)
	printf("\n Starting Test #4- calling discardCard with empty hand  \n");
#endif

	result = discardCard(0, p_0, &Game, trashFlag);
	testHandCount--;

	//assert(Game.handCount[p_0] == testHandCount);


	if (Game.handCount[p_0] != testHandCount)
	{
#if (NOISY_TEST == 1)
		printf("\t P0 handCount=%d Expected=%d \n", Game.handCount[p_0], testHandCount);
		printf("Test #3 FAILED! Bug present in discardCard()... \n");
#endif
	}
	else
	{
#if (NOISY_TEST == 1)
		printf("\t P0 handCount=%d Expected=%d \n", Game.handCount[p_0], testHandCount);
		printf("Test #4 passed. \n");
#endif
	}

	/*Starting Test #5*/
#if (NOISY_TEST==1)
	printf("\n Starting Test #5 - ensure handcount decreases with call to discardCard() and flag 3 \n");
#endif

	testHandCount = MAX_HAND;

	/*initialize gameSeed*/
	gameSeed = rand() % 1000 + 1;

	/*clear the game Game*/
	memset(&Game, 23, sizeof(struct gameState));

	/*initialize game*/
	initializeGame(numPlayer, k, gameSeed, &Game);


#if (NOISY_TEST == 1)
	printf("\t After initializing, handcount for p0 is %d \n", Game.handCount[p_0]);
	printf("\t After initializing, handcount for p1 is %d \n", Game.handCount[p_1]);
#endif

	/*Set P0's hand to gold and increment handCount*/
	for (i = 0; i < MAX_HAND; i++)
	{
		Game.hand[p_0][i] = gold;
		Game.handCount[p_0]++;
	}

#if (NOISY_TEST == 1)
	printf("\t P0's hand is loaded with gold, handCount is %d\n", Game.handCount[p_0]);
	printf("\t P1's left alone, handCount is %d\n", Game.handCount[p_1]);
#endif

	/*Set testHandCount to p0's handCount*/
	testHandCount = Game.handCount[p_0];

	/*set trashFlag for discarded hand*/
	trashFlag = 3;

	randLoop = rand() % MAX_HAND + 1;

	/*Call discardCard with flag 0 and loop thru*/
	for (j = 0; j < randLoop; j++)
	{

		//printf("Before loop, P0's handCount is %d \n", Game.handCount[p_0]);

		result = discardCard(j, p_0, &Game, trashFlag);

		//assert(result == 0);

		/*decrement testHandCount*/
		testHandCount--;

		/*print statements using for debugging*/
		//printf("After loop, P0's handCount is %d \n", Game.handCount[p_0]);
		//printf("testHandCount is %d\n", testHandCount);

		//assert(Game.handCount[p_0] == testHandCount);

		/*break out of loop if there's a bug*/
		if (Game.handCount[p_0] != testHandCount)
		{
#if (NOISY_TEST==1)
			printf("\t P0 handCount=%d Expected=%d \n", Game.handCount[p_0], testHandCount);
			printf("Test #5 FAILED! Bug present in discardCard()... \n");
#endif
			result = -1;
			break;
		}
	}

	if (result != -1)
	{
#if (NOISY_TEST==1)
		printf("\t P0 handCount=%d Expected=%d \n", Game.handCount[p_0], testHandCount);
		printf("Test #5 passed. \n");
#endif
	}



	return 0;
}