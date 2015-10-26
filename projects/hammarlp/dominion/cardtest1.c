#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

void testAdventurerCard(){
	struct gameState* state = malloc(sizeof(struct gameState));
	
	state->numPlayers = 2;
	state->whoseTurn = 0;

	//set player hands
	int playerHand[MAX_HAND] = {duchy, mine, gold};
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

	printf("Test 1. Player has enough treasure in their hand to go through\n");
	adventurerCard(state);

	//total cards in hand should be 5. 
	if( state->handCount[0] == 5 ){
		printf("Test passed. Correct final number cards in hand\n");
	} else {
		printf("Test failed. Wrong final number cards in hand\n");
	} 
	//printf("Hand count %d\n", state->handCount[0]);

	printf("Test 2. Player does not have enough cards, so needs to shuffle\n");
	
	//set player hands
	int playerHand2[MAX_HAND] = {duchy, gold};
	int playerDiscard2[MAX_DECK] = {gold};
	int playerDeck2[MAX_DECK] = {estate, silver, estate};
	
	//copy player hand into the game state
	memcpy(state->hand[0], playerHand2, sizeof(int)*MAX_HAND);
	memcpy(state->discard[0], playerDiscard2, sizeof(int)*MAX_DECK);
	memcpy(state->deck[0], playerDeck2, sizeof(int)*MAX_DECK);

	//update count
	state->handCount[0] = 2;
	state->discardCount[0] = 1;
	state->deckCount[0] = 3;	

	adventurerCard(state);

	//total cards in hand should be 5. 
	if( state->handCount[0] == 4 ){
		printf("Test passed. Correct final number cards in hand\n");
	} else {
		printf("Test failed. Wrong final number cards in hand\n");
	} 

	//printf("%d %d %d\n", state->handCount[0], state->discardCount[0], state->deckCount[0]);

	
}

int main(){
	printf("cardtest1 - Testing adventurer card\n");

	testAdventurerCard();

	return 0;
}
