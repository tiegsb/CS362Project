/*
Name: Rhett Guyer
Class: CS 362
Date: 11/8/15

Goal: The goal of this program is to use a random test to test the "Adventure" card.
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int testAdven(int *hand, int player, int handcount, int handpos, int changeDeck, int count, int *testPassed, int *testFailed);
int cardNum();

int main (){
	
	srand(time(NULL));
	int i, j, count, advPlace, numCardsInHand, testPassed=0, testFailed=0, cardsInHand[11];
	int numOfRandTests=20;
	
	for (i=0; i<numOfRandTests;i++){
		count=0;
		advPlace=0;
		numCardsInHand = cardNum(); //set a random hand number between 1 and 11;
		for(j=0; j<numCardsInHand; j++){
			cardsInHand[j] = rand()%26; //select the cards to fill the hand at random
			if(cardsInHand[j] == 7){
				count++;
				advPlace = j;
			}
		}
		//if the hand does not have an adventure card then go back to the for loop.
		if(count == 0){
			i--;
			continue;
		}
		
		printf("Test %d:\n",i+1);
		testAdven(cardsInHand, 0, numCardsInHand, advPlace, rand()%3, count, &testPassed, &testFailed);
		printf("End Test %d\n\n",i+1);
	}
	
	printf("Failed tests = %d\n", testFailed);
	printf("Passed tests = %d\n\n", testPassed);
	
	return 0;
}

int testAdven(int *hand, int player, int handCount, int handpos, int changeDeck, int count, int *testPassed, int *testFailed){
	
	int i=0,endcount=0,failed=0;
	struct gameState state;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	initializeGame(2,k,1000,&state);
	
	memcpy(state.hand[player], hand, sizeof(int)*handCount);
	state.handCount[player] = handCount;
	int deckCount = state.deckCount[player];
	
	//Print before execution of adventurer card
	// printf("\t Deck Cards before are: ");
	// for(i=0; i<deckCount; i++){
		// printf("%d, ",state.deck[0][i]);
	// }
	// printf("\n");
	// printf("\t Hand Cards before are: ");
	// for(i=0; i<handCount; i++){
		// printf("%d, ",state.hand[0][i]);
	// }
	// printf("\n");

	//Use to add a mine card to the top of the deck to see if it is skipped
	if(changeDeck == 1){
		state.deck[player][state.deckCount[player]-1] = mine;
	}
	
	//Set the deck count to 0
	if(changeDeck == 2){
		state.deckCount[player]=0;
	}
	
	cardEffect(state.hand[player][handpos],0,0,0,&state,handpos,0);
	
	
	//Print after execution of adventurercard
	// printf("\tDeck Cards after are: ");
	// for(i=0; i<state.deckCount[player]; i++){
		// printf("%d, ",state.deck[0][i]);
	// }
	// printf("\n");
	// printf("\t Hand Cards after are: ");
	// for(i=0; i<state.handCount[0]; i++){
		// printf("%d, ",state.hand[0][i]);
	// }
	// printf("\n");
	// printf("Hand Count - %d\n", state.handCount[0]);
	
	//check that the deck was shuffled and the discarded cards have been added to the new deck.
	if(changeDeck == 2 && state.deckCount[player] == 0){
		printf("\tFAILED - The deck count was 0 going in to the test but was still 0 after the adventurer card executed.\n");
		failed=1;
	}
	
	//Check that the hand has been increased by two cards
	if(state.handCount[player] == handCount+2){
		printf("\tPASSED - The Hand Count has increased by 2.\n");
	}
	else{
		printf("\tFAILED - The Hand Count after the execution of the adventure card is not correct.\n");
		failed=1;
	}
	
	//Count the number of adventurer cards in the player's hand
	for(i=0; i<state.handCount[player]; i++){
		if(state.hand[player][i] == 7){
			endcount++;
		}
	}
	//compare the count of adventurer cards from the passed in hand to the count after execution of the adventurer card.
	if(count == endcount){
		printf("\tFAILED - The adventurer card should have been removed from the hand.\n");
		failed=1;
	}
	else{
		printf("\tPASSED - The adventurer card was removed from the hand.\n");
	}
	
	//Check that the correct number of treasure cards were added.
	endcount=0;
	for(i=0; i<state.handCount[player]; i++){
		if(state.deck[player][i] == 4){
			endcount++;
		}
	}
	if(endcount == 2){
		printf("\tFAILED - Not enough treasure cards were added to the hand.\n");
		failed=1;
	}
	else{
		printf("\tPASSED - The correct number of treasure cards were added.\n");
	}
	
	//Check that if a "mine" card was added to the deck then that card was skipped and not added to the hand.
	if(changeDeck == 1){
		if(deckCount-state.deckCount[0] > 2){
			printf("\tPASSED - The mine card was correctly skipped.\n");
		}
		else{
			printf("\tFAILED - The mine card was not skipped.\n");
			failed=1;
		}
	}
	
	//check that the deck was reduced by 2 cards in cases where the shuffle would not occur.
	if(changeDeck == 0 || changeDeck == 1){
		if(deckCount-state.deckCount[0] > 1){
			printf("\tPASSED - The deck was reduced by at least 2 cards.\n");
		}
		else{
			printf("\tFAILED - The deck was not reduced by at least 2 cards.\n");
			failed=1;
		}
	}
	
	//check that all cards in the hand are valid
	endcount=0;
	for(i=0; i<state.handCount[player]; i++){
		if(state.hand[player][i] < 0 || state.hand[player][i] > 26){
			endcount++;
		}
	}
	if(endcount > 0){
		printf("\tFAILED - An invaluid card was put in the hand.\n");
		failed=1;
	}
	else{
		printf("\tPASSED - All cards in the hand are valid.\n");
	}
	
	if(failed == 1){
		*testFailed = *testFailed+1;
	}
	else{
		*testPassed = *testPassed+1;
	}
	
	return 0;
}

int cardNum(){
	int cards = rand()%10+1;
return cards;
}