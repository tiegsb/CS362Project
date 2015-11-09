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
	
	
	//Use to add a mine card to the top of the deck to see if it is skipped
	if(changeDeck == 1){
		state.deck[player][state.deckCount[player]-1] = mine;
	}
	
	//Set the deck count to 0
	if(changeDeck == 2){
		state.deckCount[player]=0;
	}
	
	cardEffect(state.hand[player][handpos],0,0,0,&state,handpos,0);
	
	
	//check that the deck was shuffled and the discarded cards have been added to the new deck.
	if(changeDeck == 2 && state.deckCount[player] == 0){
		printf("\tFAILED - The deck count was 0 before and after adventure card played.\n");
		failed=1;
	}
	
	//Check that the hand has been increased by two cards
	if(state.handCount[player] == handCount+2){
		printf("\tPASS - The hand count +2.\n");
	}
	else{
		printf("\tFAIL - Post adventure the hand count is wrong.\n");
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
		printf("\tFAIL - Advneture card not removed.\n");
		failed=1;
	}
	else{
		printf("\tPASS - Adventurer card removed.\n");
	}
	
	//Check that the correct number of treasure cards were added.
	endcount=0;
	for(i=0; i<state.handCount[player]; i++){
		if(state.deck[player][i] == 4){
			endcount++;
		}
	}
	if(endcount == 2){
		printf("\tFAIL - wrong number treasure cards added.\n");
		failed=1;
	}
	else{
		printf("\tPASS - correct number of treasure cards added.\n");
	}
	
	//Check that if a "mine" card was added to the deck then that card was skipped and not added to the hand.
	if(changeDeck == 1){
		if(deckCount-state.deckCount[0] > 2){
			printf("\tPASS - The mine card was stepped over.\n");
		}
		else{
			printf("\tFAIL - The mine card was not stepped over.\n");
			failed=1;
		}
	}
	
	//check that the deck was reduced by 2 cards in cases where the shuffle would not occur.
	if(changeDeck == 0 || changeDeck == 1){
		if(deckCount-state.deckCount[0] > 1){
			printf("\tPASS - Deck >= deck -2\n");
		}
		else{
			printf("\tFAIL - Deck !>= deck -2\n");
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
		printf("\tFAIL - hand has invlaid card.\n");
		failed=1;
	}
	else{
		printf("\tPASS - hand is valid.\n");
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
