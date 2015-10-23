//Test discardCard() function

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

	printf("PROVINCE COUNT %d\n", G.supplyCount[province]);

	while(G.supplyCount[province]>0) {

			if(isGameOver(&G) == 0) {
				printf("GOOD");
			} else {
				printf("ERROR!");
			}

		G.supplyCount[province]--;
	}

	if(isGameOver(&G) == 1) {
		printf("GOOD");
		testSuccessCount++;
	}


	//check supply piles

	//Clear the game state
	memset(&G, 23, sizeof(struct gameState));

	//initialize game
	initializeGame(numberPlayer, k, randomSeed, &G);


	//Test 1 (one supply pile down)
	printf("Test 1 (one supply pile down)");
	G.supplyCount[0] = 0;

	if(isGameOver(&G) == 0) {
		printf("GOOD");
		testSuccessCount++;
	}


	//Test 2 (two supply pile down)
	printf("Test 2 (two supply pile down)");
	G.supplyCount[1] = 0;

	if(isGameOver(&G) == 0) {
		printf("GOOD");
		testSuccessCount++;
	}


	//Test 3 (three supply pile down and the game should be over)
	printf("Test 3 (three supply pile down and the game should be over");
	G.supplyCount[2] = 0;

	if(isGameOver(&G) == 1) {
		printf("GOOD");
		testSuccessCount++;
	}

	if(testSuccessCount == 4) {
		printf("ALL TESTS PASS");
	} else {
		printf("NOT ALL TESTS PASS");
	}







}