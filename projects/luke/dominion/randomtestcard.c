//random test for the villageCard()


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

	printf("---------------------------------------\n");
	printf("Random Testing for villageCard()...\n");
	printf("---------------------------------------\n");

	srand(time(NULL));
	int randomSeed = rand();
	SelectStream(3);
	PutSeed(randomSeed);
	struct gameState G;

	int i = 0;
	int y = 0;
	int players;
	int handPos = 0;
	int testFail = 0;

	for (i = 0; i < 2000; i++) {

		for(y = 0; y < sizeof(struct gameState); y++) {
			((char*)&G)[i] = floor(Random() * 256);
		}

		//set up the game with suitable values
		players = floor(Random() * MAX_PLAYERS);

		//set up the deck counts to valid number for runnable game
		G.deckCount[players] = floor(Random() * MAX_DECK);
		G.discardCount[players] = floor(Random() * MAX_DECK);
		G.handCount[players] = floor(Random() * MAX_HAND);
		G.playedCardCount = floor(Random() * MAX_DECK);


		//set up the cards to valid state
		for (y = 0; y < G.handCount[players]; y++) {
	    	G.hand[players][y] = floor(Random() * 5);
	    }

	    for (y = 0; y < G.discardCount[players]; y++) {
	        G.discard[players][y] = floor(Random() * 5);
	    }

	    for (y = 0; y < G.deckCount[players]; y++) {
	    	G.deck[players][y] = floor(Random() * 5);
	    }

	    struct gameState post = G;
	    struct gameState pre;

	    //set up pre gamestate

	    memcpy(&pre, &post, sizeof(struct gameState));

	    //run game on post gamestate

	    villageCard(players, handPos, &post);

	    //simulate +1 Card
	    drawCard(players, &pre);

	    //simulate +2 Actions
	    pre.numActions = pre.numActions + 2;

	    //discard played card from hand
	    discardCard(handPos, players, &pre, 0);

	    //printf("Test %d of 2000 in progress: ", i);

	    if(memcmp(&pre, &post, sizeof(struct gameState)) != 0) {
	    	//printf("FAIL\n");
	    	testFail = testFail + 1;
	    } 
	    // else {
	    // 	printf("PASS\n");
	    // } 

    }

    if(testFail == 0) {
		printf("\n");
		printf("ALL TESTS PASS\n");
	} else {
		printf("\n");
		printf("RANDOM TEST FAILED\n");
		printf("%d/2000 TESTS HAVE FAILED\n", testFail);
	}

	return 0;

}