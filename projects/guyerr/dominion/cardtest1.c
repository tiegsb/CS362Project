/*
Name: Rhett Guyer
Class: CS 362
Date: 10/25/15

Goal: The goal of this program is to test the "Smithy" card.
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int testSmithy(int *hand, int player, int handcount, int handpos);

int main (){
	
	printf("Test 1:\n");
	int hand1[5] = {smithy,mine,village,tribute,gold};
	testSmithy(hand1, 0, 5, 0);
	
	printf("Test 2:\n");
	int hand2[5] = {mine,smithy,village,tribute,gold};
	testSmithy(hand2, 0, 5, 1);	

	printf("Test 3:\n");
	int hand3[5] = {mine,village,smithy,tribute,gold};
	testSmithy(hand3, 0, 5, 2);

	printf("Test 4:\n");
	int hand4[5] = {mine,village,tribute,smithy,gold};
	testSmithy(hand4, 0, 5, 3);

	printf("Test 5:\n");
	int hand5[5] = {mine,village,tribute,gold,smithy};
	testSmithy(hand5, 0, 5, 4);

	return 0;
}

int testSmithy(int *hand, int player, int handCount, int handpos){

	struct gameState state;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	initializeGame(2,k,1000,&state);
	
	memcpy(state.hand[player], hand, sizeof(int)*handCount);
	state.handCount[player] = handCount;
	
	cardEffect(state.hand[player][handpos],0,0,0,&state,handpos,0);
	
	if(state.handCount[player] == handCount+2){
		printf("\tTEST PASSED - HandCount was increased by 2.\n");
	}
	else{
		printf("\tTEST FAILED - HandCount was not increased by 2.\n");
	}
	
	if(state.hand[0][handpos] == 13){
		printf("\tTEST FAILED - Smithy card was not removed.\n");
	}
	else{
		printf("\tTEST PASSED - Smithy card was removed.\n");
	}
	return 0;
}