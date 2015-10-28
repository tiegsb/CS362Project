/*
 * Filename: 	randomtestadventurer.c
 * Author:	Jeff Moss
 * Date:	10/27/15
 * Description:	Random testing for adventurer card in the dominion card game
 * Class:	CS362 Fall 2015
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1

int checkAdventurer(int player, struct gameState *post) {
	struct gameState pre;
	
	//Copy gamestate to pre, before execution of function
	memcpy (&pre, post, sizeof(struct gameState));

 	int ret;
    	
  	ret = useAdventurer (player, post);

	//Check that function returns correctly
	assert (ret == 0);

	//Ensure that pre and post conditions are the same
	
	assert(memcmp(&pre, post, sizeof(struct gameState)) == 0);
}

int main () {

	int i, n, player, deckCount, discardCount, handCount;

	//Set kingdom cards
	int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

	struct gameState G;

	printf ("Testing Adventurer Card.\n");

	printf ("RANDOM TESTS.\n");

	//Use the provided random number generator
	SelectStream(2);
	PutSeed(4);

	for (n = 0; n < 2000; n++) {
		for (i = 0; i < sizeof(struct gameState); i++) {
			((char*)&G)[i] = floor(Random() * 256);
		}
		p = floor(Random() * 2);
		G.deckCount[p] = floor(Random() * MAX_DECK);
		G.discardCount[p] = floor(Random() * MAX_DECK);
		G.handCount[p] = floor(Random() * MAX_HAND);
		checkAdventurer(p, &G);
	}

	printf ("ALL TESTS OK\n");

  	return 0;
}
