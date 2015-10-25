//Test steward card


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

	printf("Test steward card:\n");

	srand(time(NULL));
	int numberPlayer = 2;
	int player1 = 0;
	int randomSeed = rand() % 1000 + 1;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
				 remodel, smithy, village, baron, great_hall};
	struct gameState G;
	int i;

	//Clear the game state
	memset(&G, 23, sizeof(struct gameState));

	//initialize game
	initializeGame(numberPlayer, k, randomSeed, &G);

	int handCount=G.handCount[player1];
	int coinCount=G.coins;

	//Test +2 card option

	printf("****************************************************\n");

	printf("Test that +2 card option picked is successful\n");

	printf("****************************************************\n");

	stewardCard(1, G.handCount[player1]-1, G.handCount[player1]-2, player1, 0, &G);

	int newHandCount=G.handCount[player1];

	if(newHandCount == handCount+1) {
		printf("TEST PASSED\n");
	} else {
		printf("TEST FAILED\n");
	}

	//reset game and
	//Test +2 coins option

	printf("****************************************************\n");

	printf("Test that +2 coins option picked is successful\n");

	printf("****************************************************\n");

	//Clear the game state
	memset(&G, 23, sizeof(struct gameState));

	//initialize game
	initializeGame(numberPlayer, k, randomSeed, &G);

	handCount=G.handCount[player1];
	coinCount=G.coins;

	stewardCard(2, G.handCount[player1]-1, G.handCount[player1]-2, player1, 0, &G);

	int newCoinCount = G.coins;

	if(newCoinCount == coinCount+2) {
		printf("TEST PASSED\n");
	} else {
		printf("TEST FAILED\n");
	}

	//reset game and
	//Test trash 2 cards option

	printf("***********************************************************\n");

	printf("Test that the trash 2 cards option picked is successful\n");

	printf("***********************************************************\n");

	//Clear the game state
	memset(&G, 23, sizeof(struct gameState));

	//initialize game
	initializeGame(numberPlayer, k, randomSeed, &G);

	handCount=G.handCount[player1];
	coinCount=G.coins;

	printf("Original hand count: %d\n", handCount);

	int lastCard=G.hand[player1][G.handCount[player1]-1];
	int secondToLastCard=G.hand[player1][G.handCount[player1]-2];

	//remove cards in handPos 1 and 2

	printf("Remove cards in handPos 1 and 2...\n");

	for(i=0; i<G.handCount[player1]; i++) {
		printf("Card at handPos %d before Steward Card: %d\n", i, G.hand[player1][i]);
	}

	stewardCard(3, 1, 2, player1, 0, &G);


	int newCardPos1=G.hand[player1][0];
	int newCardPos2=G.hand[player1][1];
	newHandCount=G.handCount[player1];

	printf("NEW HAND COUNT: %d\n", newHandCount);

	if(newHandCount == handCount-3) {
		printf("TEST 1: Remove correct number of cards PASS\n");
	} else {
		printf("TEST 1: Remove correct number of cards FAIL\n");
	}


	for(i=0; i<G.handCount[player1]; i++) {
		printf("Card at handPos %d after Steward Card: %d\n", i, G.hand[player1][i]);
	}

	// if(G.hand[player1][1] != savedCard1 && G.hand[player1][2] != savedCard2) {
	// 	printf("TEST 1: Remove the right cards... PASS\n");
	// } else {
	// 	printf("TEST 1: Removed the wrong cards... FAIL\n");
	// }

	if(secondToLastCard == newCardPos1 && lastCard == newCardPos2) {
		printf("TEST 2: Remove the right cards... PASS\n");
	} else {
		printf("TEST 2: Removed the wrong cards... FAIL\n");
	}



	return 0;

}