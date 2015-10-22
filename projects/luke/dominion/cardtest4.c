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
	int discardCount=G.discardCount[player1];

	//Test +2 card option
	stewardCard(1, G.handCount[player1]-1, G.handCount[player1]-2, player1, 0, &G);

	int newHandCount=G.handCount[player1];

	if(newHandCount == handCount+1) {
		printf("Hand Test passed\n");
	} else {
		printf("Hand Test failed\n");
	}

	//reset game and
	//Test +2 coins option

	//Clear the game state
	memset(&G, 23, sizeof(struct gameState));

	//initialize game
	initializeGame(numberPlayer, k, randomSeed, &G);

	handCount=G.handCount[player1];
	coinCount=G.coins;
	discardCount=G.discardCount[player1];

	stewardCard(2, G.handCount[player1]-1, G.handCount[player1]-2, player1, 0, &G);

	int newCoinCount = G.coins;

	if(newCoinCount == coinCount+2) {
		printf("Coin Test passed\n");
	} else {
		printf("Coin Test failed\n");
	}

	//reset game and
	//Test trash 2 cards option

	//Clear the game state
	memset(&G, 23, sizeof(struct gameState));

	//initialize game
	initializeGame(numberPlayer, k, randomSeed, &G);

	handCount=G.handCount[player1];
	coinCount=G.coins;
	discardCount=G.discardCount[player1];

	printf("DISCARDCNT BEFORE: %d\n", discardCount);

	int savedCard1=G.hand[player1][1];
	int savedCard2=G.hand[player1][2];

	//remove cards in handPos 1 and 2

	for(i=0; i<G.handCount[player1]; i++) {
		printf("CARD %d before Steward Card: %d\n", i, G.hand[player1][i]);
	}

	stewardCard(1, 1, 2, player1, 0, &G);


	int newDiscardCount=G.discardCount[player1];
	newHandCount=G.handCount[player1];

	printf("DISCARDCNT AFTER: %d\n", newDiscardCount);

	if(newDiscardCount == discardCount+3) {
		printf("Discard Test passed\n");
	} else {
		printf("Discard Test failed\n");
	}

	if(newHandCount == handCount-3) {
		printf("Discard hand Test passed\n");
	} else {
		printf("Discard hand Test failed\n");
	}

	for(i=0; i<G.handCount[player1]; i++) {
		printf("CARD %d after Steward Card: %d\n", i, G.hand[player1][i]);
	}

	if(G.hand[player1][1] != savedCard1 && G.hand[player1][2] != savedCard2) {
		printf("Remove the right cards... PASS\n");
	} else {
		printf("Removed the wrong cards... FAIL\n");
	}


	//NOTE DISCARD COUNT IS ALSO CALLED PLAYED CARDS. FIX THIS


}