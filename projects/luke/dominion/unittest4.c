//Test isGameOver() function

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>


int main() {

	printf("Test isGameOver() function:\n");

	srand(time(NULL));
	int numberPlayer = 2;
	int randomSeed = rand() % 1000 + 1;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
				 remodel, smithy, village, baron, great_hall};
	struct gameState G;
	int testSuccessCount=0;

	//Clear the game state
	memset(&G, 23, sizeof(struct gameState));

	//initialize game
	initializeGame(numberPlayer, k, randomSeed, &G);

	//printf("PROVINCE COUNT %d\n", G.supplyCount[province]);

	//Test case when province deck still exists
	printf("****************************************************\n");
	printf("Test case where province deck isn't empty:\n");
	printf("****************************************************\n");

	while(G.supplyCount[province]>0) {

			if(isGameOver(&G) == 0) {
				printf("TEST PASS\n");
			} else {
				printf("TEST FAILED\n");
			}

		G.supplyCount[province]--;
	}
	printf("****************************************************\n");
	printf("Test case where province deck is now empty:\n");
	printf("****************************************************\n");

	if(isGameOver(&G) == 1) {
		printf("TEST PASSED: GAME ENDED\n");
		testSuccessCount++;
	} else {
		printf("TEST FAILED: GAME IS STILL RUNNING\n");
	}


	//check supply piles

	//Clear the game state
	memset(&G, 23, sizeof(struct gameState));

	//initialize game
	initializeGame(numberPlayer, k, randomSeed, &G);

	printf("****************************************************\n");

	printf("Test decreasing supply piles\n");

	printf("****************************************************\n");

	//Test 1 (one supply pile down)
	printf("Test 1 (one supply pile down)\n");
	G.supplyCount[0] = 0;

	if(isGameOver(&G) == 0) {
		printf("TEST PASSED\n");
		testSuccessCount++;
	} else {
		printf("TEST FAILED: GAME ENDED\n");
	}


	//Test 2 (two supply pile down)
	printf("Test 2 (two supply pile down)\n");
	G.supplyCount[1] = 0;

	if(isGameOver(&G) == 0) {
		printf("TEST PASSED\n");
		testSuccessCount++;
	} else {
		printf("TEST FAILED: GAME ENDED\n");
	}


	//Test 3 (three supply pile down and the game should be over)
	printf("Test 3 (three supply pile down and the game should be over\n");
	G.supplyCount[2] = 0;

	if(isGameOver(&G) == 1) {
		printf("TEST PASSED: GAME ENDED SUCCESSFULLY\n");
		testSuccessCount++;
	}
	printf("****************************************************\n");
	printf("Overall test result:\n");
	printf("****************************************************\n");

	if(testSuccessCount == 4) {
		printf("ALL TESTS PASS\n");
	} else {
		printf("NOT ALL TESTS PASS\n");
	}

	
	return 0;


}