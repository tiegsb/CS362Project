/*
Brian Tiegs
CS 362 - Assignment 3
Test Treasure Map Card
Tests return values if only 1 treasure map is in player's hand
Tests return values when 2 treasure maps are in player's hand at different positions
Tests 4 gold cards are added to player's deck
Tests if both treasure maps are trashed after use
Tests if gold cards are added when there is less than 4 in supply
*/

#include "interface.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>


int main(){
	int i;
	int player = 0;
	int handPos, index, counter;
	struct gameState state;
	int passCount = 0;
	int failCount = 0;
	int testCount = 0;

	printf("Starting tests for \"Treasure Map Card\"...\n\n");

	//set state
	memset(&state, 0, sizeof(struct gameState));
	state.whoseTurn = player;
	state.numPlayers = MAX_PLAYERS;
	//only 1 treasure map in hand, should return -1
	//try different hand positions
	for(handPos=0; handPos<10; handPos++){
		state.handCount[player] = 10;
		//clear hand
		for(i=0; i<state.handCount[player]; i++){
			state.hand[player][i] = 0;
		}
		//add treasure map card to hand
		state.hand[player][handPos] = treasure_map;

		//only 1 treasure map in hand, should return -1
		if(cardEffect(treasure_map, 0, 0, 0, &state, handPos, 0) == -1){
			printf("PASS - Treasure map returns -1 when only 1 treasure map is in player's hand at position %d/9\n", handPos);
			passCount++;
		}
		else{
			printf("FAIL - Treasure map does not returns -1 when only 1 treasure map is in player's hand at position %d/9\n", handPos);
			failCount++;
		}
		testCount++;
	}

	//2 treasure maps in hand, should discard both cards and gain 4 gold cards
	//try different hand positions
	for(handPos=0; handPos<9; handPos++){
		for(index=handPos+1; index<10; index++){
			//set state
			memset(&state, 0, sizeof(struct gameState));
			state.whoseTurn = player;
			state.numPlayers = MAX_PLAYERS;
			//clear hand
			state.handCount[player] = 10;
			for(i=0; i<state.handCount[player]; i++){
				state.hand[player][i] = 0;
			}
			//add gold cards to supply
			state.supplyCount[gold] = 4;
			//add treasure map cards to hand
			state.hand[player][handPos] = treasure_map;
			state.hand[player][index] = treasure_map;

			//2 treasure maps in hand, should return 1
			if(cardEffect(treasure_map, 0, 0, 0, &state, handPos, 0) == 1){
				printf("PASS - Treasure map returns 1 when 2 treasure maps are present in player's hand at positions %d and %d\n", handPos, index);
				passCount++;
			}
			else{
				printf("FAIL - Treasure map returns 1 when 2 treasure maps are present in player's hand at positions %d and %d\n", handPos, index);
				failCount++;
			}
			testCount++;

			//test if 4 gold cards have been placed in player's deck
			if(state.deck[player][0] == gold && state.deck[player][1] == gold && state.deck[player][2] == gold && state.deck[player][3] == gold && state.deckCount[player] == 4 && state.supplyCount[gold] == 0){
				printf("PASS - 4 gold cards are added to deck when 2 treasure maps are present in player's hand at positions %d and %d\n", handPos, index);
				passCount++;
			}
			else{
				printf("FAIL - 4 gold cards are not added to deck when 2 treasure maps are present in player's hand at positions %d and %d\n", handPos, index);
				failCount++;
			}
			testCount++;

			//test if both treasure maps have been trashed
			counter = 0;
			for(i=0; i<state.handCount[player]; i++){
				if(state.hand[player][i] == treasure_map){
					counter++;
				}
			}
			if(counter == 0 && state.discardCount[player] == 0){
				printf("PASS - Treasure maps were trashed in player's hand at positions %d and %d\n", handPos, index);
				passCount++;
			}
			else{
				printf("FAIL - Treasure maps were not trashed in player's hand at positions %d and %d\n", handPos, index);
				failCount++;
			}
			testCount++;
		}
	}

	//2 treasure maps in hand and only 2 gold cards in supply, should discard both cards and gain remaining 2 gold cards
	//set state
	memset(&state, 0, sizeof(struct gameState));
	state.whoseTurn = player;
	state.numPlayers = MAX_PLAYERS;
	//clear hand
	state.handCount[player] = 10;
	for(i=0; i<state.handCount[player]; i++){
		state.hand[player][i] = 0;
	}
	//add gold cards to supply
	state.supplyCount[gold] = 2;
	//add treasure map cards to hand
	handPos = 1;
	index = 5;
	state.hand[player][handPos] = treasure_map;
	state.hand[player][index] = treasure_map;

	cardEffect(treasure_map, 0, 0, 0, &state, handPos, 0);

	//test if 2 gold cards have been placed in player's deck
	if(state.deck[player][0] == gold && state.deck[player][1] == gold && state.deckCount[player] == 2 && state.supplyCount[gold] == 0){
		printf("PASS - 2 gold cards are added to deck when 2 treasure maps are present in player's hand and only 2 gold cards are left in supply\n");
		passCount++;
	}
	else{
		printf("FAIL - 2 gold cards are not added to deck when 2 treasure maps are present in player's hand and only 2 gold cards are left in supply\n");
		failCount++;
	}
	testCount++;

	//print summary
	printf("\nTesting complete for \"Treasure Map Card\"\n\n");
	printf("Summary:\n");
	printf("Tests run: %d\nTests passed: %d\nTests failed: %d\n\n", testCount, passCount, failCount);

	return 0;
}
