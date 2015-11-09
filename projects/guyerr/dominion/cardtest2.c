/*
Name: Rhett Guyer
Class: CS 362
Date: 10/25/15

Goal: The goal of this program is to test the "Adventure" card.
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int testAdven(int *hand, int player, int handcount, int handpos, int changeDeck);

int main (){
	
	srand(time(NULL));
	int i, cardsInHand;
	numOfRandTests=20;
	
	for (i=0; i<20;i++){
		cardsInHand = cardNum();
	}
	
//	printf("Test 1:\n");
	int hand1[5] = {smithy,mine,adventurer,tribute,gold};
	for(i=0; i<5; i++){
		printf("%d\n",hand1[i]);
	}
	
	
	
	
	//	testAdven(hand1, 0, 5, 2, 1);
	
//	printf("Test 2:\n");
//	int hand2[5] = {adventurer,smithy,village,tribute,gold};
//	testAdven(hand2, 0, 5, 0, 0);	

//	printf("Test 3:\n");
//	int hand3[5] = {mine,village,smithy,tribute,gold};
//	testAdven(hand3, 0, 5, 2, 2);

	return 0;
}

int testAdven(int *hand, int player, int handCount, int handpos, int changeDeck){
	
	int i=0;
	struct gameState state;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	initializeGame(2,k,1000,&state);
	
	memcpy(state.hand[player], hand, sizeof(int)*handCount);
	state.handCount[player] = handCount;
	
	int deckCount = state.deckCount[player];

	//Use to add a mine card to the top of the deck to see if it is skipped
	if(changeDeck == 1){
		state.deck[player][state.deckCount[player]-1] = mine;
	}
	
	//Set the deck count to 0
	if(changeDeck == 2){
		state.deckCount[player]=0;
	}
	
	cardEffect(state.hand[player][handpos],0,0,0,&state,handpos,0);
	
	int count=0;
	
	for(i=0; i<handCount; i++){
		if(state.deck[player][i] == 7){
			count++;
		}
	}
	if(count>0){
		printf("\tTEST FAILED - The adventurer card should have been removed from the hand.\n");
	}
	else{
		printf("\tTEST PASSED - The adventurer card was removed from the hand.\n");
	}
	count=0;
	for(i=0; i<state.handCount[player]; i++){
		if(state.deck[player][i] == 4){
			count++;
		}
	}
	if(count == 2){
		printf("\tTEST FAILED - Not enough treasure cards were added to the hand.\n");
	}
	if(changeDeck == 1){
		if(deckCount-state.deckCount[0] > 2){
			printf("\tTEST PASSED - The mine card was correctly skipped.\n");
		}
		else{
			printf("\tTEST FAILED - The mine card was not skipped.\n");
		}
	}
	if(changeDeck == 0){
		if(deckCount-state.deckCount[0] > 1){
			printf("\tTEST PASSED - The deck was reduced by at least 2 cards.\n");
		}
		else{
			printf("\tTEST FAILED - The deck was not reduced by at least 2 cards.\n");
		}
	}
	count=0;
	for(i=0; i<state.handCount[player]; i++){
		if(state.deck[player][i] == -1){
			count++;
		}
	}
	if(count>0){
		printf("\tTEST FAILED - A card in the hand was replaced by a -1.\n");
	}
	else{
		printf("\tTEST PASSED - All cards were replaced with valid cards.\n");
	}

	return 0;
}

int cardNum(){
	int cards = rand()%10+1;
return cards;
}