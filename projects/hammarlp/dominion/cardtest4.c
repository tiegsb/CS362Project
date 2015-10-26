#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

void testEmbargoCard(){
	struct gameState* state = malloc(sizeof(struct gameState));
	
	state->numPlayers = 2;

	//set player hands
	int playerHand[MAX_HAND] = {duchy, embargo, gold};
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

	state->embargoTokens[0] = 2;

	state->coins = 3;
	state->supplyCount[0] = 1;

	embargoCard(state, 1, 0);

	//Check if coin total is correct. should be 5. Initial 3 and + 2
	if( state->coins == 5 ){
		printf("Test passed. Correct number of coins\n");
	} else {
		printf("Test failed. Wrong number of coins\n");
	} 

	//total cards in hand should be 2. Initial 3 and and discard 1
	if( state->handCount[0] == 2 ){
		printf("Test passed. Correct final number cards in hand\n");
	} else {
		printf("Test failed. Wrong final number cards in hand\n");
	} 

	//total embargo tokens should be 3. Initial 2 and add 1
	if( state->embargoTokens[0] == 3 ){
		printf("Test passed. Correct final number of tokens\n");
	} else {
		printf("Test failed. Wrong final number of tokens\n");
	} 

}

int main(){
	printf("cardtest4 - Testing embargo card\n");

	testEmbargoCard();

	//printf(" test passed\n");

	return 0;
}
