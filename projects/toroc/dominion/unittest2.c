/*
*	CS362 - Assignment 3 unittest2.c
*	Unit Test #2: This program ensures the isGameOver() method
*		in dominion is working properly by running 7 tests.
*		Test # 1 is for 2 players and 8 provinces are bought,
*		Test #2 is for 2 players and 7 provinces are bought,
*		Test #3 is for 4 players, and 12 provinces are bought
*		Test #4 is for 4 players, and 11 provinces are bought
*		Test #5 is for 2 players, with 3 adventure cards all bought
*		Test #6 is for 4 players, with 3 adventure cards all bought
*		Test #7 is for 2 players, trying to buy 9 provinces.
*	Author: Carol D. Toro
*	Date: 10/15/2015
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
	int	i;
	int k[10] = { adventurer, council_room, feast, gardens, mine,
		remodel, smithy, village, baron, great_hall };
	int gameSeed;
	int numPlayer = 2;
	struct gameState Game;
	int result;


	/*initialize array of gold filled hands*/
	int goldHand[MAX_HAND];
	for (i = 0; i < MAX_HAND; i++)
	{
		goldHand[i] = gold;
	}

	/*Starting Test #1*/
#if (NOISY_TEST==1)
	printf("Starting unittest2.c which checks the isGameOver() method \n");
	printf("\n Starting Test #1 - 2 players buy 8 provinces \n");
#endif
	/*initialize gameSeed*/
	gameSeed = rand() % 1000 + 1;

	/*clear the game state*/
	memset(&Game, 23, sizeof(struct gameState));

	/*initialize game*/
	initializeGame(numPlayer, k, gameSeed, &Game);

	/*load both hands with goldHand array*/
	memcpy(Game.hand[0], goldHand, sizeof(int) * MAX_HAND);

	/*Call updateCoins to ensure goldHand worked*/
	updateCoins(0, &Game, 0);

	/*increase the number of buys to 8*/
	Game.numBuys = 8;

	for (i = 0; i < 8; i++)
	{
		/*Call Buy Card to buy 1 province*/
		result = buyCard(province, &Game);
		/*Set coins to 8*/
		Game.coins = 8;
	}

#if (NOISY_TEST==1)
	printf("Supply of province is %d \n", Game.supplyCount[province]);
#endif

	//assert(isGameOver(&Game) == 1);

#if (NOISY_TEST==1)
	if (isGameOver(&Game) == 1)
	{
		printf("\t Game state = %d, Expected state = %d\n", isGameOver(&Game), 1);
		printf("Test #1 passed. \n");
	}
	else
	{
		printf("\t Game state = %d, Expected state = %d\n", isGameOver(&Game), 1);
		printf("Test #1 FAILED! Bug present in isGameOver()... \n");
	}
	
#endif


	/*Starting Test #2*/
#if (NOISY_TEST==1)
	printf("\n Starting Test #2 - 2 players buy 7 provinces \n");
#endif
	/*initialize gameSeed*/
	gameSeed = rand() % 1000 + 1;

	/*clear the game state*/
	memset(&Game, 23, sizeof(struct gameState));

	/*initialize game*/
	initializeGame(numPlayer, k, gameSeed, &Game);

	/*load both hands with goldHand array*/
	memcpy(Game.hand[0], goldHand, sizeof(int) * MAX_HAND);

	/*Call updateCoins to ensure goldHand worked*/
	updateCoins(0, &Game, 0);

	/*increase the number of buys to 8*/
	Game.numBuys = 8;

	for (i = 0; i < 7; i++)
	{
		/*Call Buy Card to buy 1 province*/
		result = buyCard(province, &Game);
		/*Set coins to 8*/
		Game.coins = 8;
	}



#if (NOISY_TEST==1)
	printf("Supply of province is %d \n", supplyCount(province, &Game));
#endif

	//assert(isGameOver(&Game) == 0);

#if (NOISY_TEST==1)
	if (isGameOver(&Game) == 0)
	{
		printf("\t Game state = %d, Expected state = %d\n", isGameOver(&Game), 0);
		printf("Test #2 passed. \n");
	}
	else
	{
		printf("\t Game state = %d, Expected state = %d\n", isGameOver(&Game), 0);
		printf("Test #2 FAILED! Bug present in isGameOver()... \n");
	}
	
#endif


	/*Starting Test #3*/
#if (NOISY_TEST==1)
	printf("\n Starting Test #3 - 4 players buy 12 provinces \n");
#endif

	/*reset # players */
	numPlayer = 4;

	/*initialize gameSeed*/
	gameSeed = rand() % 1000 + 1;

	/*clear the game state*/
	memset(&Game, 23, sizeof(struct gameState));

	/*initialize game*/
	initializeGame(numPlayer, k, gameSeed, &Game);

	/*load both hands with goldHand array*/
	memcpy(Game.hand[0], goldHand, sizeof(int) * MAX_HAND);

	/*Call updateCoins to ensure goldHand worked*/
	updateCoins(0, &Game, 0);

	/*increase the number of buys to 12*/
	Game.numBuys = 12;

	for (i = 0; i < 12; i++)
	{
		/*Call Buy Card to buy 1 province*/
		result = buyCard(province, &Game);
		/*Set coins to 8*/
		Game.coins = 8;
	}

#if (NOISY_TEST==1)
	printf("Supply of province is %d \n", supplyCount(province, &Game));
#endif

	//assert(isGameOver(&Game) == 1);

#if (NOISY_TEST==1)
	if (isGameOver(&Game) == 1)
	{
		printf("\t Game state = %d, Expected state = %d\n", isGameOver(&Game), 1);
		printf("Test #3 passed. \n");
	}
	else
	{
		printf("\t Game state = %d, Expected state = %d\n", isGameOver(&Game), 1);
		printf("Test #3 FAILED! Bug present in isGameOver()... \n");
	}
	
#endif


	/*Starting Test #4*/
#if (NOISY_TEST==1)
	printf("\n Starting Test #4 - 4 players buy 11 provinces \n");
#endif

	/*reset # players */
	numPlayer = 4;

	/*initialize gameSeed*/
	gameSeed = rand() % 1000 + 1;

	/*clear the game state*/
	memset(&Game, 23, sizeof(struct gameState));

	/*initialize game*/
	initializeGame(numPlayer, k, gameSeed, &Game);

	/*load both hands with goldHand array*/
	memcpy(Game.hand[0], goldHand, sizeof(int) * MAX_HAND);

	/*Call updateCoins to ensure goldHand worked*/
	updateCoins(0, &Game, 0);

	/*increase the number of buys to 12*/
	Game.numBuys = 12;

	for (i = 0; i < 11; i++)
	{
		/*Call Buy Card to buy 1 province*/
		result = buyCard(province, &Game);
		/*Set coins to 8*/
		Game.coins = 8;
	}

#if (NOISY_TEST==1)
	printf("Supply of province is %d \n", supplyCount(province, &Game));
#endif

	//assert(isGameOver(&Game) == 0);

#if (NOISY_TEST==1)
	if (isGameOver(&Game) == 0)
	{
		printf("\t Game state = %d, Expected state = %d\n", isGameOver(&Game), 0);
		printf("Test #4 passed. \n");
	}
	else
	{
		printf("\t Game state = %d, Expected state = %d\n", isGameOver(&Game), 0);
		printf("Test #4 FAILED! Bug present in isGameOver()... \n");
	}
	
#endif

	/*Starting Test #5*/
#if (NOISY_TEST==1)
	printf("\n Starting Test #5 - 2 players buy all of 3 adventure cards: smithy, feast, village  \n");
#endif

	/*reset # players */
	numPlayer = 2;

	/*initialize gameSeed*/
	gameSeed = rand() % 1000 + 1;

	/*clear the game state*/
	memset(&Game, 23, sizeof(struct gameState));

	/*initialize game*/
	initializeGame(numPlayer, k, gameSeed, &Game);

	/*load both hands with goldHand array*/
	memcpy(Game.hand[0], goldHand, sizeof(int) * MAX_HAND);

	/*Call updateCoins to ensure goldHand worked*/
	updateCoins(0, &Game, 0);

	/*increase the number of buys to 12*/
	Game.numBuys = 30;

	/*Call Buy Card to buy 10 smithy*/
	for (i = 0; i < 10; i++)
	{
		result = buyCard(smithy, &Game);
		/*Set coins to 8*/
		Game.coins = 8;
	}

	/*Call Buy Card to buy 10 feast */
	for (i = 0; i < 10; i++)
	{
		result = buyCard(feast, &Game);
		/*Set coins to 8*/
		Game.coins = 8;
	}

	/*Call Buy Card to buy 10 smithy*/
	for (i = 0; i < 10; i++)
	{
		result = buyCard(village, &Game);
		/*Set coins to 8*/
		Game.coins = 8;
	}



#if (NOISY_TEST==1)
	printf("Supply of smithy is %d \n", supplyCount(smithy, &Game));
	printf("Supply of feast is %d \n", supplyCount(feast, &Game));
	printf("Supply of village is %d \n", supplyCount(village, &Game));
#endif

	//assert(isGameOver(&Game) == 1);

#if (NOISY_TEST==1)
	if (isGameOver(&Game) == 1)
	{
		printf("\t Game state = %d, Expected state = %d\n", isGameOver(&Game), 1);
		printf("Test #5 passed. \n");
	}
	else
	{
		printf("\t Game state = %d, Expected state = %d\n", isGameOver(&Game), 1);
		printf("Test #5 FAILED! Bug present in isGameOver()... \n");
	}
	
#endif


	/*Starting Test #6*/
#if (NOISY_TEST==1)
	printf("\n Starting Test #6 - 4 players buy all of 3 adventure cards: smithy, feast, village  \n");
#endif

	/*reset # players */
	numPlayer = 4;

	/*initialize gameSeed*/
	gameSeed = rand() % 1000 + 1;

	/*clear the game state*/
	memset(&Game, 23, sizeof(struct gameState));

	/*initialize game*/
	initializeGame(numPlayer, k, gameSeed, &Game);

	/*load both hands with goldHand array*/
	memcpy(Game.hand[0], goldHand, sizeof(int) * MAX_HAND);

	/*Call updateCoins to ensure goldHand worked*/
	updateCoins(0, &Game, 0);

	/*increase the number of buys to 12*/
	Game.numBuys = 30;

	/*Call Buy Card to buy 10 smithy*/
	for (i = 0; i < 10; i++)
	{
		result = buyCard(smithy, &Game);
		/*Set coins to 8*/
		Game.coins = 8;
	}

	/*Call Buy Card to buy 10 feast */
	for (i = 0; i < 10; i++)
	{
		result = buyCard(feast, &Game);
		/*Set coins to 8*/
		Game.coins = 8;
	}

	/*Call Buy Card to buy 10 smithy*/
	for (i = 0; i < 10; i++)
	{
		result = buyCard(village, &Game);
		/*Set coins to 8*/
		Game.coins = 8;
	}



#if (NOISY_TEST==1)
	printf("Supply of smithy is %d \n", supplyCount(smithy, &Game));
	printf("Supply of feast is %d \n", supplyCount(feast, &Game));
	printf("Supply of village is %d \n", supplyCount(village, &Game));
#endif

	//assert(isGameOver(&Game) == 1);

#if (NOISY_TEST==1)
	if (isGameOver(&Game) == 1)
	{
		printf("\t Game state = %d, Expected state = %d\n", isGameOver(&Game), 1);
		printf("Test #6 passed. \n");
	}
	else
	{
		printf("\t Game state = %d, Expected state = %d\n", isGameOver(&Game), 1);
		printf("Test #6 FAILED! Bug present in isGameOver()... \n");
	}
	
#endif

	/*Starting Test #7*/
#if (NOISY_TEST==1)
	printf("\n Starting Test #7 - 2 players try to buy 9 provinces \n");
#endif
	/*reset # of players*/
	numPlayer = 2;

	/*initialize gameSeed*/
	gameSeed = rand() % 1000 + 1;

	/*clear the game state*/
	memset(&Game, 23, sizeof(struct gameState));

	/*initialize game*/
	initializeGame(numPlayer, k, gameSeed, &Game);

	/*load both hands with goldHand array*/
	memcpy(Game.hand[0], goldHand, sizeof(int) * MAX_HAND);

	/*Call updateCoins to ensure goldHand worked*/
	updateCoins(0, &Game, 0);

	/*increase the number of buys to 8*/
	Game.numBuys = 9;

	for (i = 0; i < 9; i++)
	{
		/*Call Buy Card to buy 1 province*/
		result = buyCard(province, &Game);
		/*Set coins to 8*/
		Game.coins = 8;
	}

#if (NOISY_TEST==1)
	printf("Supply of province is %d \n", supplyCount(province, &Game));
#endif

	//assert(isGameOver(&Game) == 1);

#if (NOISY_TEST==1)
	if (isGameOver(&Game) == 1)
	{
		printf("\t Game state = %d, Expected state = %d\n", isGameOver(&Game), 1);
		printf("Test #7 passed. \n");
	}
	else
	{
		printf("\t Game state = %d, Expected state = %d\n", isGameOver(&Game), 1);
		printf("Test #7 FAILED! Bug present in isGameOver()... \n");
	}

#endif

	return 0;

}
