#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

void testVillageCard(){
	struct gameState* state = malloc(sizeof(struct gameState));
	
	state->numPlayers = 2;

	//set player hands
	int playerHand[MAX_HAND] = {duchy, village, gold};
	int playerDiscard[MAX_DECK] = {curse, province};
	int playerDeck[MAX_DECK] = {silver, great_hall, copper, estate, gold};
	
	//copy player hand into the game state
	memcpy(state->hand[0], playerHand, sizeof(int)*MAX_HAND);
	memcpy(state->discard[0], playerDiscard, sizeof(int)*MAX_DECK);
	memcpy(state->deck[0], playerDeck, sizeof(int)*MAX_DECK);

	//update count
	state->handCount[0] = 3;
	state->discardCount[0] = 2;
	state->deckCount[0] = 5;

	state->numActions = 2;

	villageCard(state, 1);

	//total cards in hand should be 3. Initial 3 and draw 1 and discard 1
	if( state->handCount[0] == 3 ){
		printf("Test passed. Correct final number cards in hand\n");
	} else {
		printf("Test failed. Wrong final number cards in hand\n");
	} 
	//printf("hand count %d\n", state->handCount[0]);

	//Number of actions should be 4. Initial of 2 and card adds 2
	if( state->numActions == 4 ){
		printf("Test passed. Correct number of actions\n");
	} else {
		printf("Test failed. Wrong number of actions\n");
	}
	//printf("num actions %d\n", state->numActions);


}

int main(){
	printf("cardtest4 - Testing village card\n");

	testVillageCard();

	//printf(" test passed\n");

	return 0;
}
