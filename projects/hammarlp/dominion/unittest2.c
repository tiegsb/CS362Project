#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int testUpdateCoins(){
	struct gameState* state = malloc(sizeof(struct gameState));
	
	state->numPlayers = 2;
      	
	//settings predetermined cards to hand
	int playerHand[MAX_HAND] = {copper, mine, gold};
	memcpy(state->hand[0], playerHand, sizeof(int)*MAX_HAND);
	state->handCount[0] = 3;
	state->discardCount[0] = 0;

	state->coins = 0;

	//update coins when have 1 copper and 1 gold and 1 bonus (total of 5)
	updateCoins(0, state, 1);

	if(state->coins == 5)
		printf("Test passed. Total is 5. \n");
	else
		printf("Test failed. Total is not 5. \n");
	
	//printf("total %d\n", state->coins);

	return 0;
	

}

int main(){
	printf("unittest2 - Testing updateCoins\n");

	testUpdateCoins();

	//printf("---------------\n\n");

	return 0;
}
