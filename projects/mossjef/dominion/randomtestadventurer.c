/*
 * Filename: 	randomtestadventurer.c
 * Author:	Jeff Moss
 * Date:	10/27/15
 * Description:	Random testing for adventurer card in the dominion card game
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

void checkAdventurer(int player, struct gameState *post, int fail) {
	struct gameState pre;
	
	//Copy gamestate to pre, before execution of function
	memcpy (&pre, post, sizeof(struct gameState));

 	int ret;
    	
  	ret = useAdventurer(player, post);

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
	assert(pre.numActions == post->numActions);
	assert(pre.coins == post->coins);
	assert(pre.numBuys == post->numBuys);
	assert(pre.playedCardCount == post->playedCardCount);

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
	printf("Checking that the state of the player with the adventurer card changes appropriately.\n");
#endif

	//Now check the state of the player with the adventurer card
	
	//Two more cards must be entered into the hand
	assert(pre.handCount[player]+2 == post->handCount[player]);

	//Check that the two cards added are treasure cards
	for(i = pre.handCount[player]-1; i < post->handCount[player]; i++) {
		assert(i != curse || i != estate || i != duchy || i != province ||
		i != copper || i != silver || i != gold);
	}

	//Need a way to check that deck count is correct	
	//For a given player their cards are either in the deck, discard or hand
	//We've already tested two additional cards will go to the hand
	
	int deckChange = 2 + post->discardCount[player] - pre.discardCount[player];
	int postdeckcount = pre.deckCount[player] - deckChange;	
	assert(post->deckCount[player] == postdeckcount);
	//This assert failed
	if(post->deckCount[player] != (pre.deckCount[player] - deckChange)) { 
		printf("Assert failed, postDeckCount change does not match postDicardCount and postHandCount change.\n");
		fail = 1;
	}

}

int main () {

	int i, n, player, fail = 0;

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

	for (n = 0; n < 2000; n++) {
		for (i = 0; i < sizeof(struct gameState); i++) {
			((char*)&G)[i] = floor(Random() * 256);
		}
		//choose random number of players between 2 and 4
		numPlayers = floor(Random() * (MAX_PLAYERS-2)) + 2;
		
		player = floor(Random() * numPlayers);
		initStatus = initializeGame(numPlayers, k, 1, &G); 
		checkAdventurer(player, &G, fail);
#if(NOISY_TEST == 1)
		printf("Random test %d\n", n);
#endif
	}

	if (fail == 0) {
		printf ("ALL TESTS OK\n");
	} else {
		printf ("AT LEAST ONE TEST FAILED\n");
	}
  	return 0;
}
