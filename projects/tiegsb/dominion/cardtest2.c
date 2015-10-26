/*
Brian Tiegs
CS 362 - Assignment 3
Test Smithy Card
Tests for correct smithy card usage between players
Tests for different card type effects
Tests for correct handCount, deckCount and discardCount
Tests if adventurer card is removed from hand
*/

#include "interface.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>


int main(){
	int i, j, k;
	char cardName[MAX_STRING_LENGTH];
	struct gameState state;
	int passCount = 0;
	int failCount = 0;
	int testCount = 0;

	printf("Starting tests for \"Smithy Card\"...\n\n");

	//loop through each card type
	for(i=0; i<27; i++) {
		cardNumToName(i, cardName);
		//set state, all players have same cards in decks
		state.numPlayers = MAX_PLAYERS;
		for(j=0; j<MAX_PLAYERS; j++){
			memset(&state, 0, sizeof(struct gameState));
			for(k=0; k<MAX_HAND; k++){
				state.hand[j][k] = i;
			}
			for(k=0; k<MAX_DECK; k++){
				state.deck[j][k] = i;
				state.discard[j][k] = i;
			}
			state.handCount[j] = 10;
			state.deckCount[j] = 10;
			state.discardCount[j] = 10;

			state.whoseTurn = j;
			state.numPlayers = MAX_PLAYERS;

			//add adventurer card to hand
			state.hand[j][0] = adventurer;

			cardEffect(smithy, 0, 0, 0, &state, 0 , 0);

			//no cards should be added to discard pile
			if(state.discardCount[j] == 10){
				printf("PASS - Discard pile unchanged with full hand of %s cards for player %d - Expected Result: discardCount: 10 - Actual Result: discardCount: %d\n", cardName, j+1, state.discardCount[j]);
				passCount++;
			}
			else{
				printf("FAIL - Discard pile changed with full hand of %s cards for player %d - Expected Result: discardCount: 10 - Actual Result: discardCount: %d\n", cardName, j+1, state.discardCount[j]);
				failCount++;
			}
			testCount++;

			//3 cards should be removed from deck
			if(state.deckCount[j] == 7){
				printf("PASS - Deck loses 3 cards with full hand of %s cards for player %d - Expected Result: deckCount: 7 - Actual Result: deckCount: %d\n", cardName, j+1, state.deckCount[j]);
				passCount++;
			}
			else{
				printf("FAIL - Deck did not lose 3 cards with full hand of %s cards for player %d - Expected Result: deckCount: 7 - Actual Result: deckCount: %d\n", cardName, j+1, state.deckCount[j]);
				failCount++;
			}
			testCount++;

			//3 cards should be added to hand and 1 should be removed
			if(state.handCount[j] == 12){
				printf("PASS - Hand gained 2 cards with full hand of %s cards for player %d - Expected Result: handCount: 12 - Actual Result: handCount: %d\n", cardName, j+1, state.handCount[j]);
				passCount++;
			}
			else{
				printf("FAIL - Hand did not gain 2 cards with full hand of %s cards for player %d - Expected Result: handCount: 12 - Actual Result: handCount: %d\n", cardName, j+1, state.handCount[j]);
				failCount++;
			}
			testCount++;

			//test if adventurer card was discarded
			//ignore test if decks are made up of adventurer cards
			if(i != adventurer){
				//adventurer card removed from hand
				if(state.hand[j][0] != adventurer){
					printf("PASS - Adventurer card removed from hand for player %d\n", j+1);
					passCount++;
				}
				else{
					printf("FAIL - Adventurer card was not removed from hand for player %d\n", j+1);
					failCount++;
				}
				testCount++;
			}
		}
	}

	//print summary
	printf("\nTesting complete for \"Smithy Card\"\n\n");
	printf("Summary:\n");
	printf("Tests run: %d\nTests passed: %d\nTests failed: %d\n\n", testCount, passCount, failCount);

	return 0;
}
