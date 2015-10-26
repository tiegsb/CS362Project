/*
Name: Rhett Guyer
Class: CS 362
Date: 10/25/15

Goal: The goal of this program is to test the "Council Room" card.
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int testCR(int *hand, int player, int handcount, int handpos, int changeDeck);

int main (){
	
	printf("Test 1:\n");
	int hand1[5] = {smithy,mine,village,tribute,council_room};
	testCR(hand1, 0, 5, 4, 1);
	
	printf("Test 2:\n");
	int hand2[5] = {council_room,smithy,village,tribute,gold};
	testCR(hand2, 0, 5, 0, 0);	

	printf("Test 3:\n");
	int hand3[5] = {mine,village,council_room,tribute,gold};
	testCR(hand3, 0, 5, 2, 2);

	return 0;
}

int testCR(int *hand, int player, int handCount, int handpos, int changeDeck){
	
	int other = 0;
	int i=0;
	if(player == 0){
		other = 1;
	}
	else{
		other = 0;
	}
	
	//int i=0;
	struct gameState state;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	initializeGame(2,k,1000,&state);
	
	memcpy(state.hand[player], hand, sizeof(int)*handCount);
	state.handCount[player] = handCount;
	
	if(changeDeck == 1){
		state.numActions = 20;
	}
	
	int playerHandCount = state.handCount[player];
	int otherHandCount = state.handCount[other];
	int playerDeckCount = state.deckCount[player];
	int otherDeckCount = state.deckCount[other];
	int coins = state.coins;
	int actions = state.numActions;
	int buys = state.numBuys;
	
	cardEffect(state.hand[player][handpos],0,0,0,&state,handpos,0);
	
	int count=0;
	
	for(i=0; i<handCount; i++){
		if(state.deck[player][i] == 8){
			count++;
		}
	}
	if(count>0){
		printf("\tTEST FAILED - The council_room card should have been removed from the hand.\n");
	}
	else{
		printf("\tTEST PASSED - The council_room card was removed from the hand.\n");
	}
	if(state.handCount[player] == playerHandCount+3){
		printf("\tTEST PASSED - The hand count for player %d was increased by 3.\n",player+1);
	}
	else{
		printf("\tTEST FAILED - The hand count for player %d is incorrect.\n",player+1);
	}
	if(state.handCount[other] == otherHandCount+1){
		printf("\tTEST PASSED - The hand count for player %d was increased by 1.\n",other+1);
	}
	else{
		printf("\tTEST FAILED - The hand count for player %d is incorrect.\n",other+1);		
	}
	if(state.deckCount[player] == playerDeckCount-4){
		printf("\tTEST PASSED - The deck count for player %d was reduced by 4.\n",player+1);
	}
	else{
		printf("\tTEST FAILED - The deck count for player %d is incorrect.\n",player+1);
	}
	if(state.deckCount[other] == otherDeckCount-1){
		printf("\tTEST PASSED - The deck count for player %d was reduced by 1.\n",other+1);
	}
	else{
		printf("\tTEST FAILED - The deck count for player %d is incorrect.\n",other+1);		
	}	
	if(buys == state.numBuys-1){
		printf("\tTEST PASSED - One buy was added for player %d.\n",player+1);
	}
	else{
		printf("\tTEST FAILED - The addition of one buy for player %d was not done.\n", player+1);
	}
	if(coins != state.coins){
		printf("\tTEST FAILED - The coins variable was changed.\n");
	}
	if(actions != state.numActions){
		printf("\tTEST FAILED - The actions variable was changed.\n");
	}
	
	return 0;
	
	
}
	
	
	
	