/*
Name: Rhett Guyer
Class: CS 362
Date: 10/25/15

Goal: The goal of this program is to test the "Shuffle" function.
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int checkShuff(int *hand, int player, struct gameState *state, int handCount);

int main (){
	struct gameState state;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	initializeGame(2,k,1000,&state);
	int hand1[5] = {copper,silver,mine,copper,gold};
	int hand2[5] = {curse,copper,silver,baron,silver};
	int hand3[5] = {gold,curse,gold,curse,gold};
	int hand4[4] = {copper,copper,gold,silver};
	int hand5[10] = {copper,silver,silver,copper,gold,silver,gold,gold,copper,copper};
	int hand6[5] = {baron,mine,province,province,curse};
	
	printf("Test 1:\n");
	checkShuff(hand1, 0, &state, 5);
	printf("Test 2:\n");
	checkShuff(hand2, 0, &state, 5);
	printf("Test 3:\n");
	checkShuff(hand3, 0, &state, 5);
	printf("Test 4:\n");
	checkShuff(hand4, 0, &state, 4);
	printf("Test 5:\n");
	checkShuff(hand5, 0, &state, 10);
	printf("Test 6:\n");
	checkShuff(hand6, 0, &state, 5);
	
	
	return 0;
}

int checkShuff(int *hand, int player, struct gameState *state, int handCount){
	
	memcpy(state->deck[0], hand, sizeof(int)*handCount);
	state->handCount[0] = handCount;
	
	shuffle(player, state);
	
	int i=0;
	int error=0;

	for(i=0; i<handCount;i++){
		printf("\tCard %d in pre shuffle hand was %d and is %d after the shuffle.\n", i, hand[i], state->deck[player][i]);
		if(hand[i] == state->deck[player][i]){
			error += 1;
		}
	}
	
	if(error == handCount){
		printf("TEST FAILED - Shuffle did not change the order of the cards in the deck.");
	}
	else{
		printf("\tTEST PASSED\n");
	}
	
	return 0;
}