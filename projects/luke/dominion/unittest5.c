//Test buyCard() function

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

	//Clear the game state
	memset(&G, 23, sizeof(struct gameState));

	//initialize game
	initializeGame(numberPlayer, k, randomSeed, &G);

	//TEST 1 Test when numBuys runs out.
	//Make sure adventurer is always greater than numBuys
	G.numBuys=12;
	G.coins=500;
	G.supplyCount[adventurer]=G.numBuys+1;

	while(G.numBuys > 0) {


		if(buyCard(adventurer, &G) == 0) {
			printf("GOOD");
		} else {
			printf("ERROR");
			break;
		};

	}

	if(buyCard(adventurer, &G) == -1) {
			printf("GOOD");
	} else {
			printf("ERROR");
	};

	//Clear the game state
	memset(&G, 23, sizeof(struct gameState));

	//initialize game
	initializeGame(numberPlayer, k, randomSeed, &G);

	//TEST 2 Test when chosen card type runs out.
	//Make sure adventurer is always greater than numBuys
	G.numBuys=12;
	G.coins=500;
	G.supplyCount[adventurer]=10;

	while(G.supplyCount[adventurer] > 0) {

		if(buyCard(adventurer, &G) == 0) {
			printf("GOOD");
		} else {
			printf("ERROR");
			break;
		};

	}

	if(buyCard(adventurer, &G) == -1) {
			printf("GOOD");
	} else {
			printf("ERROR");
	};

	//Clear the game state
	memset(&G, 23, sizeof(struct gameState));

	//initialize game
	initializeGame(numberPlayer, k, randomSeed, &G);

	//TEST 3 Test when coins run out.
	//Make sure adventurer is always greater than numBuys
	G.numBuys=12;
	G.coins=50;
	G.supplyCount[adventurer]=G.numBuys+1;

	while(G.coins > 0) {

		if(buyCard(adventurer, &G) == 0) {
			printf("GOOD");
		} else {
			printf("ERROR");
			break;
		};

	}

	if(buyCard(adventurer, &G) == -1) {
			printf("GOOD");
	} else {
			printf("ERROR");

	};




}