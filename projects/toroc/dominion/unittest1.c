/*
*	CS362 - Assignment 3 - unittest1.c
*	Unit Test #1: This program runs 6 tests to ensure the
*		updateCoins method 	in dominion is properly working.
*		The program checks the method against various hands:
*		hands with treasure cards as well as empty hands,
*		with bonuses and no bonuses, different hand counts aside
*		from just the 5 at each turn.
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
	int handCount;
	int k[10] = { adventurer, council_room, feast, gardens, mine,
		remodel, smithy, village, baron, great_hall };
	int gameSeed;
	int numPlayer;

	struct gameState Game;
	srand(time(NULL));
	int bonus = 0;
	numPlayer = 2;


	/*Hands to be tested*/
	int testHand1[8];	//hand with silver and gold, no bonus, handCount set to 8---Test1
	int testHand3[MAX_HAND] = { 0 };   //hand will be empty, no bonus ---Test 2
	int testHand6[MAX_HAND] = { 0 }; //empty hand, 7 bonus ---Test3
	int testHand4[8];	//hand will have 1 gold ---Test 4
	int testHand5[12];	//hand with gold and copper, 20 bonus, handCount set to 10---Test5
	int testHand2[8];  //hand with all gold, 2 bonus, and handCount set to 3---Test6
	

	/*Start Test 1*/
#if (NOISY_TEST==1)
	printf("Starting unittest1.c which checks the updateCoins() method \n");
	printf("\n Starting Test #1 with 1copper, 4silver, 3gold, no bonus, handCount of 8 \n");
#endif
	/*load hand with silver and gold*/
	testHand1[0] = copper;
	testHand1[1] = silver;
	testHand1[2] = silver;
	testHand1[3] = silver;
	testHand1[4] = silver;
	testHand1[5] = gold;
	testHand1[6] = gold;
	testHand1[7] = gold;

	/*Set handCount and Seed*/
	handCount = 8;
	gameSeed = rand() % 10000 + 1;

	/*clear the state of the game*/
	memset(&Game, 23, sizeof(struct gameState));

	/*initialize game*/
	initializeGame(numPlayer, k, gameSeed, &Game);

	/*load hand with testHand1 array*/
	memcpy(Game.hand[0], testHand1, sizeof(int) * handCount);

	/*set game's handCount to 8*/
	Game.handCount[0] = 8;

	updateCoins(0, &Game, bonus);

	/*Coins expected to be 18*/
	//assert(Game.coins == 18);


#if (NOISY_TEST==1)
	if (Game.coins == 18)
	{
		printf("\t Game coins=%d Expected=%d \n", Game.coins, 18);
		printf("Test #1 passed. \n");
	}
	else
	{
		printf("\t Game coins=%d Expected=%d \n", Game.coins, 18);
		printf("Test #1 FAILED! Bug present in updateCoins()...\n");
	}
	
#endif


	/*Start Test 2*/
#if (NOISY_TEST==1)
	printf("\n Starting Test #2 with empty hand no bonus \n");
#endif

	/*Set handCount and Seed*/
	handCount = 8;
	gameSeed = rand() % 10000 + 1;

	/*clear the state of the game*/
	memset(&Game, 23, sizeof(struct gameState));

	/*initialize game*/
	initializeGame(numPlayer, k, gameSeed, &Game);

	/*load hand with testHand3 array*/
	memcpy(Game.hand[0], testHand3, sizeof(int) * handCount);

	updateCoins(0, &Game, bonus);

	/*Coins expected to be 0*/
	//assert(Game.coins == 0);

#if (NOISY_TEST==1)
	if (Game.coins == 0)
	{
		printf("\t Game coins=%d Expected=%d \n", Game.coins, 0);
		printf("Test #2 passed.  \n");
	}
	else
	{
		printf("\t Game coins=%d Expected=%d \n", Game.coins, 0);
		printf("Test #2 FAILED! Bug present in updateCoins()... \n");
	}
	
#endif


	/*Start Test 3*/
#if (NOISY_TEST==1)
	printf("\n Starting Test #3 with empty hand, 7 bonus \n");
#endif

	bonus = 7;
	/*Set handCount and Seed*/
	handCount = 8;

	gameSeed = rand() % 10000 + 1;

	/*clear the state of the game*/
	memset(&Game, 23, sizeof(struct gameState));

	/*initialize game*/
	initializeGame(numPlayer, k, gameSeed, &Game);


	/*load hand with testHand6 array*/
	memcpy(Game.hand[0], testHand6, sizeof(int) * handCount);

	updateCoins(0, &Game, bonus);

	/*Coins expected to be 7*/
	//assert(Game.coins == 7);

#if (NOISY_TEST==1)
	if (Game.coins == 7)
	{
		printf("\t Game coins=%d Expected=%d \n", Game.coins, 7);
		printf("Test #3 passed. \n");
	}
	else
	{
		printf("\t Game coins=%d Expected=%d \n", Game.coins, 7);
		printf("Test #3 FAILED! Bug present in updateCoins()... \n");
	}

#endif



	/*Start Test 4*/
#if (NOISY_TEST==1)
	printf("\n Starting Test #4 with only 1 gold and no bonus \n");
#endif
	/*load hand with 1 gold*/
	testHand4[0] = gold;
	testHand4[1] = 0;
	testHand4[2] = 0;
	testHand4[3] = 0;
	testHand4[4] = 0;

	/*Clear bonus*/
	bonus = 0;
	/*Set handCount and Seed*/
	handCount = 8;

	gameSeed = rand() % 10000 + 1;

	/*clear the state of the game*/
	memset(&Game, 23, sizeof(struct gameState));

	/*initialize game*/
	initializeGame(numPlayer, k, gameSeed, &Game);

	/*load hand with testHand4 array*/
	memcpy(Game.hand[0], testHand4, sizeof(int) * handCount);

	updateCoins(0, &Game, bonus);

	/*Coins expected to be 3*/
	//assert(Game.coins == 3);

#if (NOISY_TEST==1)
	if (Game.coins == 3)
	{
		printf("\t Game coins=%d Expected=%d \n", Game.coins, 3);
		printf("Test #4 passed. \n");
	}
	else
	{
		printf("\t Game coins=%d Expected=%d \n", Game.coins, 3);
		printf("Test #4 FAILED! Bug present in updateCoins()... \n");
	}

#endif


	/*Start Test 5*/
#if (NOISY_TEST==1)

	printf("\n Starting Test #5 with 7copper, 1gold, 2silver, 15 bonus, hand count of 10 \n");
#endif
	/*load hand with silver and gold*/
	testHand5[0] = copper;
	testHand5[1] = copper;
	testHand5[2] = copper;
	testHand5[3] = copper;
	testHand5[4] = copper;
	testHand5[5] = copper;
	testHand5[6] = copper;
	testHand5[7] = gold;
	testHand5[8] = silver;
	testHand5[9] = silver;
	testHand5[10] = 0;

	/*Set Bonus*/
	bonus = 15;
	/*Set handCount and Seed*/
	handCount = 10;

	gameSeed = rand() % 10000 + 1;

	/*clear the state of the game*/
	memset(&Game, 23, sizeof(struct gameState));

	/*initialize game*/
	initializeGame(numPlayer, k, gameSeed, &Game);

	/*load hand with testHand5 array*/
	memcpy(Game.hand[0], testHand5, sizeof(int) * handCount);

	/*set handCount to 10*/
	Game.handCount[0] = 10;

	updateCoins(0, &Game, bonus);

	/*Coins expected to be 29*/
	//assert(Game.coins == 29);

#if (NOISY_TEST==1)
	if (Game.coins == 29)
	{
		printf("\t Game coins=%d Expected=%d \n", Game.coins, 29);
		printf("Test #5 passed. \n");
	}
	else
	{
		printf("\t Game coins=%d Expected=%d \n", Game.coins, 29);
		printf("Test #5 FAILED! Bug present in updateCoins()... \n");
	}
	
#endif

	/*Start Test 6*/
#if (NOISY_TEST==1)

	printf("\n Starting Test #6 with 8 gold, 0 bonus, hand count of 3 \n");
#endif
	/*load hand with silver and gold*/
	testHand2[0] = gold;
	testHand2[1] = gold;
	testHand2[2] = gold;
	testHand2[3] = gold;
	testHand2[4] = gold;
	testHand2[5] = gold;
	testHand2[6] = gold;
	testHand2[7] = gold;

	/*Set Bonus*/
	bonus = 0;
	/*Set handCount and Seed*/
	handCount = 10;

	gameSeed = rand() % 10000 + 1;

	/*clear the state of the game*/
	memset(&Game, 23, sizeof(struct gameState));

	/*initialize game*/
	initializeGame(numPlayer, k, gameSeed, &Game);

	/*load hand with testHand5 array*/
	memcpy(Game.hand[0], testHand2, sizeof(int) * handCount);

	/*set handCount to 3*/
	Game.handCount[0] = 3;

	updateCoins(0, &Game, bonus);

	/*Coins expected to be 9*/
	//assert(Game.coins == 9);

#if (NOISY_TEST==1)
	if (Game.coins == 9)
	{
		printf("\t Game coins=%d Expected=%d \n", Game.coins, 9);
		printf("Test #6 passed. \n");
	}
	else
	{
		printf("\t Game coins=%d Expected=%d \n", Game.coins, 9);
		printf("Test #6 FAILED! Bug present in updateCoins()... \n");
	}

#endif

	return 0;
}