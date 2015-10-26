/*
Brian Tiegs
CS 362 - Assignment 3
Test Council Room Card
Tests for correct council room card usage between players
Tests for different card type effects
Tests for correct handCount, deckCount and discardCount
Tests if council room card is removed from hand
Tests if other players drew a card
*/

#include "interface.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>


int main(){
	int i, j, k, l;
	char cardName[MAX_STRING_LENGTH];
	struct gameState state;
	int passCount = 0;
	int failCount = 0;
	int testCount = 0;

	printf("Starting tests for \"Council Room Card\"...\n\n");

	//loop through each card type
	for(i=0; i<27; i++) {
		cardNumToName(i, cardName);
		for(j=0; j<MAX_PLAYERS; j++){
			//reset state
			memset(&state, 0, sizeof(struct gameState));
			//set state, all players have same cards in decks
			for(k=0; k<MAX_PLAYERS; k++){
				for(l=0; l<MAX_HAND; l++){
					state.hand[k][l] = i;
				}
				for(l=0; l<MAX_DECK; l++){
					state.deck[k][l] = i;
					state.discard[k][l] = i;
				}
				state.handCount[k] = 10;
				state.deckCount[k] = 10;
				state.discardCount[k] = 10;
			}
			state.numPlayers = MAX_PLAYERS;
			state.whoseTurn = j;

			//add council room card to hand
			state.hand[j][0] = council_room;

			cardEffect(council_room, 0, 0, 0, &state, 0 , 0);

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

			//4 cards should be removed from deck
			if(state.deckCount[j] == 6){
				printf("PASS - Deck loses 4 cards with full hand of %s cards for player %d - Expected Result: deckCount: 6 - Actual Result: deckCount: %d\n", cardName, j+1, state.deckCount[j]);
				passCount++;
			}
			else{
				printf("FAIL - Deck did not lose 4 cards with full hand of %s cards for player %d - Expected Result: deckCount: 6 - Actual Result: deckCount: %d\n", cardName, j+1, state.deckCount[j]);
				failCount++;
			}
			testCount++;

			//4 cards should be added to hand and 1 should be removed
			if(state.handCount[j] == 13){
				printf("PASS - Hand gained 3 cards with full hand of %s cards for player %d - Expected Result: handCount: 13 - Actual Result: handCount: %d\n", cardName, j+1, state.handCount[j]);
				passCount++;
			}
			else{
				printf("FAIL - Hand did not gain 3 cards with full hand of %s cards for player %d - Expected Result: handCount: 13 - Actual Result: handCount: %d\n", cardName, j+1, state.handCount[j]);
				failCount++;
			}
			testCount++;

			//test if council room card was discarded
			//ignore test if decks are made up of council room cards
			if(i != council_room){
				//council room card removed from hand
				if(state.hand[j][0] != council_room){
					printf("PASS - Council room card removed from hand for player %d\n", j+1);
					passCount++;
				}
				else{
					printf("FAIL - Council room card was not removed from hand for player %d\n", j+1);
					failCount++;
				}
				testCount++;
			}

			//check that all other players drew a card
			//loop through other players
			for(k=0; k<MAX_PLAYERS; k++){
				if(j != k){
					//1 card should be removed from other player's deck
					if(state.deckCount[k] == 9){
						printf("PASS - Player %d loses 1 card from deck when player %d uses council room card - Expected Result: deckCount: 9 - Actual Result: deckCount: %d\n", k+1, j+1, state.deckCount[k]);
						passCount++;
					}
					else{
						printf("FAIL - Player %d does not lose 1 card from deck when player %d uses council room card - Expected Result: deckCount: 9 - Actual Result: deckCount: %d\n", k+1, j+1, state.deckCount[k]);
						failCount++;
					}
					testCount++;

					//1 card added to other player's hand
					if(state.handCount[k] == 11){
						printf("PASS - Player %d gains 1 card in hand when player %d uses council room card - Expected Result: handCount: 11 - Actual Result: handCount: %d\n", k+1, j+1, state.handCount[k]);
						passCount++;
					}
					else{
						printf("FAIL - Player %d does not gain 1 card in hand when player %d uses council room card - Expected Result: handCount: 11 - Actual Result: handCount: %d\n", k+1, j+1, state.handCount[k]);
						failCount++;
					}
					testCount++;
				}
			}
		}
	}

	//print summary
	printf("\nTesting complete for \"Council Room Card\"\n\n");
	printf("Summary:\n");
	printf("Tests run: %d\nTests passed: %d\nTests failed: %d\n\n", testCount, passCount, failCount);

	return 0;
}
