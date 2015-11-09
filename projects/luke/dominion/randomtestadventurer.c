//random test for the adventurerCard()

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
	printf("Random Testing for adventurerCard()...\n");
	printf("---------------------------------------\n");

	srand(time(NULL));
	int randomSeed = rand();
	SelectStream(3);
	PutSeed(randomSeed);
	struct gameState G;

	int i = 0;
	int y = 0;
	int z = 0;
	int cardDrawn = 0;
	int drawnTreasure = 0;
	int players;
	int testFail = 0;



	for (i = 0; i < 2000; i++) {

		for(y = 0; y < sizeof(struct gameState); y++) {
			((char*)&G)[i] = floor(Random() * 256);
		}

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

	    int temphand[MAX_HAND];

	    struct gameState post = G;
	    struct gameState pre;

	    //set up pre gamestate

	    memcpy(&pre, &post, sizeof(struct gameState));

	    //run game on post gamestate

	    adventurerCard(temphand, z, cardDrawn, players, drawnTreasure, &post);

	    //replicate what the adventurer card would do

	    while(drawnTreasure < 2) {
	    	if(pre.deckCount[players] < 1) {
	    		shuffle(players, &pre);
	    	}

	    	drawCard(players, &pre);

	    	cardDrawn = pre.hand[players][pre.handCount[players] - 1];

	    	if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold) {
	    		drawnTreasure++;
	    	} else {
	    		temphand[z]=cardDrawn;
	    		pre.handCount[players]--;
	    		z++;
	    	}

	    }
	    while(z-1 >= 0) {
	    	pre.discard[players][pre.discardCount[players]++] = temphand[z-1];
	    	z=z-1;
	    }


	    //printf("Test %d of 2000 in progress: ", i);

	    if(memcmp(&pre, &post, sizeof(struct gameState)) != 0) {
	    	//printf("FAIL\n");
	    	testFail = testFail+1;
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