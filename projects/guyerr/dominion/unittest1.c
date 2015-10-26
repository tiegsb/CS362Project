/*
Name: Rhett Guyer
Class: CS 362
Date: 10/25/15

Goal: The goal of this program is to test the "drawCard" function.
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int testDrawCard (int player, struct gameState *state);

int main (){
	struct gameState state;
	struct gameState alteredState;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	initializeGame(2,k,1000,&state);
	printf("Test 1:\n");
	testDrawCard(0, &state);
	printf("Test 2:\n");
	testDrawCard (1, &state);
	printf("Test 3:\n");
	testDrawCard (2, &state);

	//test that it shuffles
	printf("Test 4:\n");
	initializeGame(2,k,1000,&alteredState);
	alteredState.deckCount[0] = 0;
	alteredState.discardCount[0] = 3;
	alteredState.discard[0][0] = copper;
	alteredState.discard[0][1] = silver;
	alteredState.discard[0][2] = gold;
	testDrawCard(0,&alteredState);
	
	return 0;
}

int testDrawCard(int player, struct gameState *state){
	
	int other;
	if(player == 0){
		other = 1;
	}
	else{
		other = 0;
	}

	//Set variables coiming in so we can compare
	int playerDeckCount = state->deckCount[player];
	int playerDiscardCount =state->discardCount[player];
	int playerHandCount = state->handCount[player];
	int otherDeckCount = state->deckCount[other];
	int otherDiscardCount =state->discardCount[other];
	int otherHandCount = state->handCount[other];

	//Set result of drawCard equal to drawResult
	int drawResult = drawCard(player, state);
	
	if((player == 0 || player == 1)&& playerDeckCount>0){
		if(state->deckCount[player] == playerDeckCount-1 && state->handCount[player] == playerHandCount+1){
			printf("\tTEST PASSED - Drawcard correctly reduced the player deck from %d to %d and added increased the players hand count from %d to %d.\n", playerDeckCount, state->deckCount[player], playerHandCount, state->handCount[player]);
			if(state->hand[player][playerHandCount] == state->deck[player][playerDeckCount]){
				printf("\tTEST PASSED - The card pulled was at the top of the deck.\n");
			}
			else{
				printf("\tTEST FAILED - The card pulled was not the same card that was on the top of the deck.\n");
			}
		}
		else{
			if(state->deckCount[player] != playerDeckCount-1){
				printf("\tTEST FAILED - Drawcard did not corectly reduce the number of cards in the deck by 1.\n");
			}
			if(state->handCount[player] != playerHandCount+1){
				printf("\tTEST FAILED - Drawcard did not corectly increase the number of cards in the players hand by 1.\n");
			}
		}
	}
	else if ((player == 0 || player == 1)&& playerDeckCount <= 0 && playerDiscardCount>0){
		if(state->deckCount[player] == playerDiscardCount-1){
			printf("\tTEST PASSED - A call to shuffle the discard pile was called and executed correctly. The deck was then reduced by one.\n");
			if(state->handCount[player] == playerHandCount+1){
				printf("\tAfter the shuffle, the hand count was correctly increased by 1.\n");
			}
			else{
				printf("\tTEST FAILED - After the shuffle, the hand count was not correctly increased by 1.\n");
			}
		}
	}
	else{
		if(drawResult == -1){
			printf("\tTEST PASSED - Drawcard correctly returned -1 when a player number not in the initialized game was used.\n");
		}
		else{
			printf("\tTEST FAILED - Drawcard did not return a -1 when a player number not in the initialized game was used.\n");
		}
	}
	if(	otherDeckCount == state->deckCount[other] && otherDiscardCount == state->discardCount[other] && otherHandCount == state->handCount[other]){
		printf("\tTEST PASSED - No changes were made to the other player's hand.\n");
	}
	else{
		if(otherDeckCount == state->deckCount[other]){
			printf("\tTEST FAILED - The other player's deck count was altered.\n");
		}
		if(otherDiscardCount == state->discardCount[other]){
			printf("\tTEST FAILED - The other player's discard count was altered.\n");
		}
		if(otherHandCount == state->handCount[other]){
			printf("\tTEST FAILED - The other player's hand count was altered.\n");
		}
	}
	
	return 0;
	
}
