/*
Brian Tiegs
CS 362 - Assignment 3
Test function gainCard()
Tests different flags
Tests for different card type effects
Tests for correct addition to player's decks
Tests for removal of card from supply pile
Tests for failure of gainCard when the needed card is not in the supply pile
*/

#include "interface.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>


int main(){
	int i, j;
	int flag;
	int player = 0;
	char cardName[MAX_STRING_LENGTH];
	struct gameState state;
	int passCount = 0;
	int failCount = 0;
	int testCount = 0;

	printf("Starting tests for \"gainCard\"...\n\n");

	//loop through each card type
	for(i=0; i<27; i++){
		cardNumToName(i, cardName);
		//check each flag
		for(flag=0; flag<3; flag++){
			//reset state
			memset(&state, 0, sizeof(struct gameState));
			//reset supply count for all cards
			for(j=0; j<27; j++){
				state.supplyCount[i]=1;
			}

			gainCard(i, &state, flag, player);

			//card should be added to discard pile
			if(flag == 0){
				if(state.discardCount[player] == 1 && state.discard[player][0] == i){
					printf("PASS - %s card added to discard pile with flag set to %d - Expected Result: discardCount: 1 - Actual Result: discardCount: %d\n", cardName, flag, state.discardCount[player]);
					passCount++;
				}
				else{
					printf("FAIL - %s card not added to discard pile with flag set to %d - Expected Result: discardCount: 1 - Actual Result: discardCount: %d\n", cardName, flag, state.discardCount[player]);
					failCount++;
				}
				testCount++;

				//all other decks should be unchanged
				if(state.deckCount[player] == 0 && state.handCount[player] == 0){
					printf("PASS - All other decks are unaltered with flag set to %d - Expected Result: deckCount: 0 handCount: 0 - Actual Result: deckCount: %d handCount:%d\n", flag, state.deckCount[player], state.handCount[player]);
					passCount++;
				}
				else{
					printf("FAIL - Other decks have been altered with flag set to %d - Expected Result: deckCount: 0 handCount: 0 - Actual Result: deckCount: %d handCount:%d\n", flag, state.deckCount[player], state.handCount[player]);
					failCount++;
				}
				testCount++;
			}

			//card should be added to deck
			if(flag == 1){
				if(state.deckCount[player] == 1 && state.deck[player][0] == i){
					printf("PASS - %s card added to deck with flag set to %d - Expected Result: deckCount: 1 - Actual Result: deckCount: %d\n", cardName, flag, state.deckCount[player]);
					passCount++;
				}
				else{
					printf("FAIL - %s card not added to deck with flag set to %d - Expected Result: deckCount: 1 - Actual Result: deckCount: %d\n", cardName, flag, state.deckCount[player]);
					failCount++;
				}
				testCount++;

				//all other decks should be unchanged
				if(state.discardCount[player] == 0 && state.handCount[player] == 0){
					printf("PASS - All other decks are unaltered with flag set to %d - Expected Result: discardCount: 0 handCount: 0 - Actual Result: discardCount: %d handCount:%d\n", flag, state.discardCount[player], state.handCount[player]);
					passCount++;
				}
				else{
					printf("FAIL - Other decks have been altered with flag set to %d - Expected Result: discardCount: 0 handCount: 0 - Actual Result: discardCount: %d handCount:%d\n", flag, state.discardCount[player], state.handCount[player]);
					failCount++;
				}
				testCount++;
			}

			//card should be added to the hand
			if(flag == 2){
				if(state.handCount[player] == 1 && state.hand[player][0] == i){
					printf("PASS - %s card added to hand with flag set to %d - Expected Result: handCount: 1 - Actual Result: handCount: %d\n", cardName, flag, state.handCount[player]);
					passCount++;
				}
				else{
					printf("FAIL - %s card not added to hand with flag set to %d - Expected Result: handCount: 1 - Actual Result: handCount: %d\n", cardName, flag, state.handCount[player]);
					failCount++;
				}
				testCount++;

				//all other decks should be unchanged
				if(state.deckCount[player] == 0 && state.discardCount[player] == 0){
					printf("PASS - All other decks are unaltered with flag set to %d - Expected Result: deckCount: 0 discardCount: 0 - Actual Result: deckCount: %d discardCount:%d\n", flag, state.deckCount[player], state.discardCount[player]);
					passCount++;
				}
				else{
					printf("FAIL - Other decks have been altered with flag set to %d - Expected Result: deckCount: 0 discardCount: 0 - Actual Result: deckCount: %d discardCount:%d\n", flag, state.deckCount[player], state.discardCount[player]);
					failCount++;
				}
				testCount++;
			}

			//check that the card is removed from the supply pile
			if(state.supplyCount[i] == 0){
				printf("PASS - %s card removed from supply pile - Expected Result: supplyCount: 0 - Actual Result: supplyCount: %d\n", cardName, state.supplyCount[i]);
				passCount++;
			}
			else{
				printf("FAIL - %s card not removed from supply pile - Expected Result: supplyCount: 0 - Actual Result: supplyCount: %d\n", cardName, state.supplyCount[i]);
				failCount++;
			}
			testCount++;
		}

		//check that function returns -1 if no cards are in supply pile;
		if(gainCard(i, &state, flag, player) == -1){
			printf("PASS - gainCard returns -1 when there are no %s cards in supply pile\n", cardName);
			passCount++;
		}
		else{
			printf("PASS - gainCard does not return -1 when there are no %s cards in supply pile\n", cardName);
			failCount++;
		}
		testCount++;
	}

	//print summary
	printf("\nTesting complete for \"gainCard\"\n\n");
	printf("Summary:\n");
	printf("Tests run: %d\nTests passed: %d\nTests failed: %d\n\n", testCount, passCount, failCount);

	return 0;
}
