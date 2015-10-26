/*
Name: Rhett Guyer
Class: CS 362
Date: 10/25/15

Goal: The goal of this program is to test the "updateCoins" function.
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int checkCoins(int *hand, struct gameState *state,int handCount, int bonus, int correct);

int main (){
	struct gameState state;
	int hand1[5] = {copper,copper,copper,copper,copper};
	int hand2[5] = {silver,silver,silver,silver,silver};
	int hand3[5] = {gold,gold,gold,gold,gold};
	int hand4[4] = {copper,copper,gold,silver};
	int hand5[1] = {copper};
	int hand6[0] = {};
	int hand7[10] = {copper,silver,silver,copper,gold,silver,gold,gold,copper,copper};
	int hand8[5] = {baron,mine,province,province,curse};
	int hand9[7] = {embargo,gold,remodel,salvager,copper,silver,gold};
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	initializeGame(2,k,1000,&state);

	checkCoins(hand1, &state,5,0,5);
	checkCoins(hand2, &state,5,0,10);
	checkCoins(hand3, &state,5,0,15);
	checkCoins(hand4, &state,4,0,7);
	checkCoins(hand5, &state,1,0,1);
	checkCoins(hand6, &state,0,0,0);
	checkCoins(hand7, &state,10,0,19);
	checkCoins(hand8, &state,5,0,0);
	checkCoins(hand9, &state,7,0,9);
	checkCoins(hand3, &state,5,-3,12);
	checkCoins(hand4, &state,4,2,9);
	
	return 0;
}

int checkCoins(int *hand, struct gameState *state, int handCount, int bonus, int correct){
	
	int i=0;
	state->handCount[0]=handCount;
	
	for(i=0; i<handCount; i++){
		state->hand[0][i] = hand[i];
	}
	
	updateCoins(0, state, bonus);
	
	if(state->coins == correct){
		printf("TEST PASSED - The correct coin cound of %d was returned.\n",state->coins);
	}
	else{
		printf("TEST FAILED - The updateCoins function returned %d but the correct answer was %d.\n",state->coins, correct);
	}
	
	memset(state->hand[0],0,100);
	
	state->coins=0;
	
	return 0;
}
