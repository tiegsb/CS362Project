/*
Name: Rhett Guyer
Class: CS 362
Date: 10/25/15

Goal: The goal of this program is to test the "Village" card.
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int testVil(int *hand, int player, int handcount, int handpos, int changeDeck);

int main (){
	
	printf("Test 1:\n");
	int hand1[5] = {smithy,mine,village,tribute,gold};
	testVil(hand1, 0, 5, 2, 1);
	
	printf("Test 2:\n");
	int hand2[5] = {adventurer,smithy,village,tribute,gold};
	testVil(hand2, 0, 5, 2, 0);	

	printf("Test 3:\n");
	int hand3[5] = {mine,village,smithy,tribute,gold};
	testVil(hand3, 0, 5, 1, 2);

	return 0;
}

int testVil(int *hand, int player, int handCount, int handpos, int changeDeck){
	
	//int i=0;
	struct gameState state;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	initializeGame(2,k,1000,&state);
	
	memcpy(state.hand[player], hand, sizeof(int)*handCount);
	state.handCount[player] = handCount;
	
	if(changeDeck == 1){
		state.numActions = 20;
	}
	
	int actions = state.numActions;
	int playerHandCount = state.handCount[player];
	int coins = state.coins = 0;

	
	cardEffect(state.hand[player][handpos],0,0,0,&state,handpos,0);

	if(actions == state.numActions-2){
		printf("\tTEST PASSED - The number of actions has increased by 2.\n");		
	}
	else{
		printf("\tTEST FAILED - The number of actions was not increased by 2.\n");
	}
	
	if(coins == state.coins){
		printf("\tTEST PASSED - The number of coins has remained the same.\n");	
	}
	else{
		printf("\tTEST FAILED - The village card altered the number of coins.\n");
	}
	
	if(playerHandCount == state.handCount[player] && state.hand[player][handpos]!=14){
		printf("\tTEST PASSED - The hand count is the same and the village card has been replaced by another card.\n");		
	}
	else{
		printf("\tTEST FAILED - The hand count is different or the village card is still in the hand.\n");
	}

	
	
	// for(i=0; i<state.handCount[player]; i++){
		// printf("Card # %d is %d\n",i,state.hand[player][i]);
	// }

	// printf("Actions = %d\n",state.numActions);	
	
	return 0;
}