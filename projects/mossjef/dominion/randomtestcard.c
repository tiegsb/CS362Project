/*
 * Filename: 	randomtestcard.c
 * Author:	Jeff Moss
 * Date:	11/1/15
 * Description:	Random testing for great_hall card in the dominion card game
 * Class:	CS362 Fall 2015
 */

#include <math.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1

void checkGreat_hall(int handPos, int player, struct gameState *post, int *fail) {
	struct gameState pre;
	
	//Copy gamestate to pre, before execution of function
	memcpy (&pre, post, sizeof(struct gameState));

 	int ret;
    	
  	ret = useGreat_hall(handPos, player, post);

	//Check that function returns correctly
	assert (ret == 0);

	//Ensure that pre and post conditions are the same

#if(NOISY_TEST == 1)
	printf("Testing that the gamestate doesn't change if it's not supposed to.\n");
#endif

	//Ensuring gamestate doesn't change if it's not supposed to
	assert(pre.numPlayers == post->numPlayers);
	assert(pre.outpostPlayed == post->outpostPlayed);
	int i;
	for(i = 0; i < treasure_map+1; i++) {
		assert(pre.supplyCount[i] == post->supplyCount[i]);
	}
	assert(pre.outpostTurn == post->outpostTurn);
	assert(pre.whoseTurn == post->whoseTurn);
	assert(pre.phase == post->phase);
	assert(pre.coins == post->coins);
	assert(pre.numBuys == post->numBuys);
	assert(pre.playedCardCount+1 == post->playedCardCount);

#if(NOISY_TEST == 1)
	printf("Checking that other players are not affected.\n");
#endif
	
	int j;
	//Ensure other player's hands are not affected
	for(i=0; i < post->numPlayers; i++) {
		if(i != player) {
			//Check hand count for each other player
			assert(pre.handCount[i] == post->handCount[i]);
			//Check deckCount for each other player
			assert(pre.deckCount[i] == post->deckCount[i]);
			//Check discardCount for each other player
			assert(pre.discardCount[i] == post->discardCount[i]);
	
			for(j=0; j < post->handCount[i]; j++) {
				//Hands shouldn't change for other players
				assert(pre.hand[i][j] == post->hand[i][j]);
				//Discard piles shouldn't change for other players
				assert(pre.discard[i][j] == post->discard[i][j]);
				//Deck shouldn't change for other players
				assert(pre.deck[i][j] == post->deck[i][j]);
			}		
		}
	}
#if(NOISY_TEST == 1)
	printf("Checking that the state of the player with the great_hall card changes appropriately.\n");
#endif

	//Now check the state of the player with the adventurer card
	
	//An additional card must be added to the hand
	//assert(pre.handCount[player]+1 == post->handCount[player]);
	//This assert failed, the following if statement verifies
	if (pre.handCount[player]+1 != post->handCount[player]) {
		printf("FAIL: Handcount. Expected %d, got %d\n", pre.handCount[player]+1, post->handCount[player]);
		*fail = 1;
	}

	//Check that number actions are increased by one
	//assert(pre.numActions+1 == post->numActions);
	//This assert failed, the following if statement verifies
	if(pre.numActions+1 != post->numActions) {
		printf("FAIL: NumActions. Expected %d, got %d\n", pre.numActions+1, post->numActions);
		*fail = 1;
	}

	//Check that discard count is changed appropriately
	//assert(pre.discardCount[player]+1 == post->discardCount[player]); 
	//This assert failed, the following if statement verifies
	if(pre.discardCount[player]+1 != post->discardCount[player]) {
		printf("FAIL: discardCount. Expected %d, got %d\n", pre.discardCount[player]+1, post->discardCount[player]);
		*fail = 1;
	}
}

int main () {

	int i, n, player;
	int fail = 0;

	//Set kingdom cards
	int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

	struct gameState G;

	printf ("Testing Adventurer Card.\n");

	printf ("RANDOM TESTS.\n");

	//Use the provided random number generator
	SelectStream(2);
	PutSeed(2);

	int initStatus;
	int numPlayers;
	int handPos; 

	for (n = 0; n < 2000; n++) {
		for (i = 0; i < sizeof(struct gameState); i++) {
			((char*)&G)[i] = floor(Random() * 256);
		}
		//choose random number of players between 2 and 4
		numPlayers = floor(Random() * (MAX_PLAYERS-2)) + 2;
		
#if(NOISY_TEST == 1)
		printf("Random test %d\n", n);
#endif

		handPos = 0;
		player = floor(Random() * numPlayers);
		initStatus = initializeGame(numPlayers, k, 1, &G); 
		checkGreat_hall(handPos, player, &G, &fail);

	}

	if (fail == 0) {
		printf ("\nALL TESTS OK\n");
	} else {
		printf ("\nAT LEAST ONE TEST FAILED\n");
	}
  	return 0;
}
