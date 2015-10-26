/***********************************************************************
* Author : Allan Chan
* ONID: chanal
* Class: CS362
* Filename: unittest2.c
*
* Description:
*   Unit Test 2 that tests the isGameOver() function.
*	Testing different game over situations where supply pile is 
*	empty and three piles are empty.
*	
*
************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>

//set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main(){
	srand(time(NULL));
	int gameSeed = rand() % 1000 + 1;
	int p = 0; //player 1
	int numPlayer = 2;
	int handCount = 5;
	int status;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
				 remodel, smithy, village, baron, great_hall};

	int testHand[5] = {copper, copper, silver, silver, gold};

	struct gameState G;

	/*Clear the game state*/
	memset(&G, 23, sizeof(struct gameState));

	/*Initialize the game*/
	initializeGame(numPlayer, k, gameSeed, &G);

	/*Set cards to testHand*/
	memcpy(G.hand[p], testHand, sizeof(int)*handCount);


	/******** Test 1 ********/
#if (NOISY_TEST == 1)
	printf("Test #1, Province supply = 0\n");
#endif

	G.supplyCount[province] = 0;
	status = isGameOver(&G);

#if (NOISY_TEST == 1)
	printf( "Expected game state=%d, Actual game state=%d \n", 1, isGameOver(&G));
	
	if(status == 1){
		printf( "Test #1 PASSED, Game is over\n\n");
	} else {
		printf( "Test #1 FAILED\n\n");
	}
#endif


	/******** Test 2 ********/
#if (NOISY_TEST == 1)
	printf("Test #2, Province supply = 1\n");
#endif

	G.supplyCount[province] = 1;
	status = isGameOver(&G);

#if (NOISY_TEST == 1)
	printf( "Expected game state=%d, Actual game state=%d \n", 0, isGameOver(&G));
	if(status == 0){
		printf( "Test #2 PASSED, Game continues\n\n");
	} else {
		printf( "Test #2 FAILED\n\n");
	}
#endif


	/******** Test 3 ********/
#if (NOISY_TEST == 1)
	printf("Test #3, Three supply piles empty\n");
#endif

	G.supplyCount[silver] = 0;
	G.supplyCount[adventurer] = 0;
	G.supplyCount[duchy] = 0;
	status = isGameOver(&G);

#if (NOISY_TEST == 1)
	printf( "Expected game state=%d, Actual game state=%d \n", 1, isGameOver(&G));
	if(status == 1) {
		printf( "Test #3 PASSED, Game is over\n\n");
	} else {
		printf( "Test #3 FAILED\n\n");
	}
#endif



	/******** Test 4 ********/
#if (NOISY_TEST == 1)
	printf("Test #4, Two supply piles empty\n");
#endif

	G.supplyCount[silver] = 0;
	G.supplyCount[adventurer] = 0;
	G.supplyCount[duchy] = 5;

	status = isGameOver(&G);

#if (NOISY_TEST == 1)
	printf( "Expected game state=%d, Actual game state=%d \n", 0, isGameOver(&G));
	if(status == 0) {
		printf( "Test #4 PASSED, Game continues\n\n");
	} else {
		printf( "Test #4 FAILED\n\n");
	}
#endif

	return 0;
}