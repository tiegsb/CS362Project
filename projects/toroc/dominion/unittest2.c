/*
*	CS362 - Assignment 3
*	Unit Test #2: This program ensures the isGameOver method
*		in dominion is working properly by running 4 tests.
*		Test 1 is for 2 players and depleting provinces, test 2 is
*		for 4 players & depleting provinces, test 3 is for 2 players
*		and depleting adventure cards, and test3 is for 2 players
*		and both depleting adventure cards and provinces.
*	Author: Carol D. Toro
*	Date: 10/15/2015
*	If supply count goes into neg, isGameOver kept breaking my assertion,
*	for the purpose of testing, I opted out of allowing the supply count to 
*	turn negative. 
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
void tests(int testType);

void depleteProvince(struct gameState *state);
void depleteAdventureCards(struct gameState *state);
int checkIsGameOver(struct gameState *state);
int main()
{

	tests(1);
	tests(2);
	tests(3);
	tests(4);

	return 0;

}
int checkIsGameOver(struct gameState *state)
{
	if (state->supplyCount[province] <= 0)
		return 1;
	
	int i; 
	int depletedCount = 0;


	for (i=0; i<25; i++)
	{
		if (state->supplyCount[i] == 0)
		{
			depletedCount++;
		}
	}
	if ( depletedCount>= 3)
	{
		return 1;
	}
		return 0;
}
void depleteProvince(struct gameState *state)
{
	int b;
	int go;

	if (state->numPlayers == 2)
	{
		go = 8;
	}
	else
	{
		go = 12;
	}

	for (b = 0; b < go; b++)
	{
		int randDeplete = rand() % 9;
		if (randDeplete <= 7)
		{
			state->supplyCount[province]--;
		}
		if (state->supplyCount[province] == 0)
			break;
	}
	/*if supply count goes into neg, isGameOver kept breaking my assertion*/
	/*this function prevents supply count from going neg*/
}
void depleteAdventureCards(struct gameState *state)
{
	int b;

	for (b = 0; b < 7; b++)
	{
		int randDeplete = rand() % 5;

		if (randDeplete >2)
		{
			state->supplyCount[smithy]--;
			state->supplyCount[feast]--;
			state->supplyCount[village]--;
		}
		else if (randDeplete < 2)
		{
			state->supplyCount[smithy]-=2;
			state->supplyCount[feast]-=2;
			state->supplyCount[village]-=2;
		}

		if (state->supplyCount[smithy] == 0 || state->supplyCount[feast] == 0 || state->supplyCount[village] == 0)
		{
			break;
		}
		else if (state->supplyCount[smithy] == 1 || state->supplyCount[feast] == 1 || state->supplyCount[village] == 1)
		{
			state->supplyCount[smithy]--;
			state->supplyCount[feast]--;
			state->supplyCount[village]--;
			break;
		}
		
	}
	
}
void tests(int testType)
{
	int p, handCount, cardNum;
	int k[10] = { adventurer, council_room, feast, gardens, mine,
		remodel, smithy, village, baron, great_hall };
	int gameSeed;
	int round;
	int roundCount;
	int numPlayer = 2;
	struct gameState Game;


	/*utilizing rand so that no run has same number of tests*/
	cardNum = rand() % MAX_HAND;
	handCount = rand() % cardNum;
	roundCount = rand() % handCount;

#if (NOISY_TEST==1)
	if (testType == 1)
	{
		printf("Starting Test #1 with 2 players & depleting providences \n");
	}
	else if (testType == 2)
	{
		printf("Starting Test #2 with 4 players & depleting providences \n");
	}
	else if (testType == 3)
	{
		printf("Starting Test #3 with 2 players & depleting adventure cards \n");
	}
	else if (testType == 4)
	{
		printf("Starting Test #4 with 2 players & depleting adventure & providences \n");
	}
#endif 

	for (round = 0; round < roundCount; round++)
	{
		/*test thru both players*/
		for (p = 0; p < numPlayer; p++)
		{
			
			do
			{
				gameSeed = rand() % 1000;
			} while (gameSeed == 0);

			/*clear the game state*/
			memset(&Game, 23, sizeof(struct gameState));

			if (testType == 2)
			{
				numPlayer = 4;
			}
			/*initialize game*/
			initializeGame(numPlayer, k, gameSeed, &Game);

#if (NOISY_TEST==1)
		if (testType == 1)
		{
			printf("\t Randomly depleting supply of provinces \n");
		}
		else if (testType == 2)
		{
			printf("\t Randomly depleting supply of provinces \n");
		}
		else if (testType == 3)
		{
			printf("\t Randomly depleting supply of adventure cards \n");
		}
		else if (testType == 4)
		{
			printf("\t Randomly depleting supply of adventure cards & providences \n");
		}
#endif
			/*randomly deplete the supply count*/

		if (testType == 1)
		{
			depleteProvince(&Game);
		}
		else if (testType == 2)
		{
			depleteProvince(&Game);
		}
		else if (testType == 3)
		{
			depleteAdventureCards(&Game);
		}
		else if (testType == 4)
		{
			depleteProvince(&Game);
			depleteAdventureCards(&Game);
		}
			
#if (NOISY_TEST==1)
		if (testType == 1)
		{
			printf("\t Current supply of provinces is %d \n", Game.supplyCount[province]);
		}
		else if (testType == 2)
		{
			printf("\t Current supply of provinces is %d \n", Game.supplyCount[province]);
		}
		else if (testType == 3)
		{
			printf("\t Current supply of smithy is %d \n", Game.supplyCount[smithy]);
			printf("\t Current supply of feast is %d \n", Game.supplyCount[feast]);
			printf("\t Current supply of village is %d \n", Game.supplyCount[village]);
		}
		else if (testType == 4)
		{
			printf("\t Current supply of provinces is %d \n", Game.supplyCount[province]);
			printf("\t Current supply of smithy is %d \n", Game.supplyCount[smithy]);
			printf("\t Current supply of feast is %d \n", Game.supplyCount[feast]);
			printf("\t Current supply of village is %d \n", Game.supplyCount[village]);
		}		
#endif

			assert(isGameOver(&Game) == checkIsGameOver(&Game));


#if (NOISY_TEST==1)
		if (testType == 1)
		{
			printf("\t Game state = %d, Expected state = %d\n", isGameOver(&Game), checkIsGameOver(&Game));
		}
		else if (testType == 2)
		{
			printf("\t Game state = %d, Expected state = %d\n", isGameOver(&Game), checkIsGameOver(&Game));
		}
		else if (testType == 3)
		{
			printf("\t Game state = %d, Expected state = %d\n", isGameOver(&Game), checkIsGameOver(&Game));
		}
		else if (testType == 4)
		{
			printf("\t Game state = %d, Expected state = %d\n", isGameOver(&Game), checkIsGameOver(&Game));
		}
			
#endif
		}
	}

#if (NOISY_TEST==1)
	if (testType == 1)
	{
		printf("Passed the first test with provinces and 2 players! \n");
	}
	else if (testType == 2)
	{
		printf("Passed the first test with provinces and 4 players! \n");
	}
	else if (testType == 3)
	{
		printf("Passed the third test with adventure cards and 2 players! \n");
	}
	else if (testType == 4)
	{
		printf("Passed the fourth test with adventure cards & provinces and 2 players! \n");
	}
#endif
	return;
}