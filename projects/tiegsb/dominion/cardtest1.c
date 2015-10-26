/*
Brian Tiegs
CS 362 - Assignment 3
Test Adventurer Card
Tests for recognition of all treasure card types
Tests correct adventure card usage bewteen different players
Tests for correct handCount, deckCount and discardCount
Tests if no treasure cards are in deck or discard pile
	-Causes segmentation fault therefore code is commented out
*/

#include "interface.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>


int main(){
	int h, i, j;
	int card;
	char cardName[MAX_STRING_LENGTH];
	struct gameState state;
	int passCount = 0;
	int failCount = 0;
	int testCount = 0;

	printf("Starting tests for \"Adventurer Card\"...\n\n");

	//test different treasure cards
	for(h=0; h<3; h++){
		memset(&state, 0, sizeof(struct gameState));
		if(h == 0)
			card = copper;
		if(h == 1)
			card = silver;
		if(h == 2)
			card = gold;
		cardNumToName(card, cardName);

		//set state, all players have treasure cards in deck
		state.numPlayers = MAX_PLAYERS;
		for(i=0; i<MAX_PLAYERS; i++){
			for(j=0; j<MAX_HAND; j++){
				state.hand[i][j] = card;
			}
			for(j=0; j<MAX_DECK; j++){
				state.deck[i][j] = card;
				state.discard[i][j] = card;
			}
			state.handCount[i] = 10;
			state.deckCount[i] = 10;
			state.discardCount[i] = 10;
		}

		//test basic functionality for each player
		for(i=0; i<MAX_PLAYERS; i++){
			state.whoseTurn = i;
			cardEffect(adventurer, 0, 0, 0, &state, 0 , 0);

			//no cards should be discarded since all cards are treasures
			if(state.discardCount[i] == 10){
				printf("PASS - Discard pile unchanged with full hand of %s cards for player %d - Expected Result: discardCount: 10 - Actual Result: discardCount: %d\n", cardName, i+1, state.discardCount[i]);
				passCount++;
			}
			else{
				printf("FAIL - Discard pile changed with full hand of %s cards for player %d - Expected Result: discardCount: 10 - Actual Result: discardCount: %d\n", cardName, i+1, state.discardCount[i]);
				failCount++;
			}
			testCount++;

			//2 cards should be removed from deck
			if(state.deckCount[i] == 8){
				printf("PASS - Deck loses 2 cards with full hand of %s cards for player %d - Expected Result: deckCount: 8 - Actual Result: deckCount: %d\n", cardName, i+1, state.deckCount[i]);
				passCount++;
			}
			else{
				printf("FAIL - Deck did not lose 2 cards with full hand of %s cards for player %d - Expected Result: deckCount: 8 - Actual Result: deckCount: %d\n", cardName, i+1, state.deckCount[i]);
				failCount++;
			}
			testCount++;

			//2 cards should be added to hand
			if(state.handCount[i] == 12){
				printf("PASS - Hand gained 2 cards with full hand of %s cards for player %d - Expected Result: handCount: 12 - Actual Result: handCount: %d\n", cardName, i+1, state.handCount[i]);
				passCount++;
			}
			else{
				printf("FAIL - Hand did not gain 2 cards with full hand of %s cards for player %d - Expected Result: handCount: 12 - Actual Result: handCount: %d\n", cardName, i+1, state.handCount[i]);
				failCount++;
			}
			testCount++;
		}
	}

	//test non treasure cards are discarded properly
	memset(&state, 0, sizeof(struct gameState));

	//set state, all players have gold cards in deck
	//reset state
	state.numPlayers = MAX_PLAYERS;
	for(i=0; i<MAX_PLAYERS; i++){
		for(j=0; j<MAX_HAND; j++){
			state.hand[i][j] = gold;
		}
		for(j=0; j<MAX_DECK; j++){
			state.deck[i][j] = gold;
			state.discard[i][j] = gold;
		}
		state.handCount[i] = 10;
		state.deckCount[i] = 10;
		state.discardCount[i] = 10;
	}

	i = state.whoseTurn = 0;

	//set top 2 cards of deck to be non-treasure cards
	state.deck[i][state.deckCount[i]-1] = adventurer;
	state.deck[i][state.deckCount[i]-2] = adventurer;

	cardEffect(adventurer, 0, 0, 0, &state, 0 , 0);

	//2 cards should be discarded since top 2 cards of discard deck are non-treasures
	if(state.discardCount[i] == 12){
		printf("PASS - Discard pile gained 2 cards - Expected Result: discardCount: 12 - Actual Result: discardCount: %d\n", state.discardCount[i]);
		passCount++;
	}
	else{
		printf("FAIL - Discard pile did not gain 2 cards - Expected Result: discardCount: 12 - Actual Result: discardCount: %d\n", state.discardCount[i]);
		failCount++;
	}
	testCount++;

	//4 cards should be removed from deck
	if(state.deckCount[i] == 6){
		printf("PASS - Deck loses 4 cards - Expected Result: deckCount: 6 - Actual Result: deckCount: %d\n", state.deckCount[i]);
		passCount++;
	}
	else{
		printf("FAIL - Deck did not lose 4 cards - Expected Result: deckCount: 6 - Actual Result: deckCount: %d\n", state.deckCount[i]);
		failCount++;
	}
	testCount++;

	//2 cards should be added to hand
	if(state.handCount[i] == 12){
		printf("PASS - Hand gained 2 cards - Expected Result: handCount: 12 - Actual Result: handCount: %d\n", state.handCount[i]);
		passCount++;
	}
	else{
		printf("FAIL - Hand did not gain 2 cards - Expected Result: handCount: 12 - Actual Result: handCount: %d\n", state.handCount[i]);
		failCount++;
	}
	testCount++;

/*
	//testing when no treasure cards are present it deck
	//CRITICAL FAILURE - segmentation fault

	//reset state
	memset(&state, 0, sizeof(struct gameState));

	//set state, all players have adventurer cards in deck (no treasure cards)
	state.numPlayers = MAX_PLAYERS;
	for(i=0; i<MAX_PLAYERS; i++){
		for(j=0; j<MAX_HAND; j++){
			state.hand[i][j] = adventurer;
		}
		for(j=0; j<MAX_DECK; j++){
			state.deck[i][j] = adventurer;
			state.discard[i][j] = adventurer;
		}
		state.handCount[i] = 10;
		state.deckCount[i] = 10;
		state.discardCount[i] = 10;
	}

	state.whoseTurn = 0;
	//When no treasure cards are present a segmentation dump occurs
	cardEffect(adventurer, 0, 0, 0, &state, 0 , 0);
*/

	//print summary
	printf("\nTesting complete for \"Adventurer Card\"\n\n");
	printf("Summary:\n");
	printf("Tests run: %d\nTests passed: %d\nTests failed: %d\n\n", testCount, passCount, failCount);

	return 0;
}
