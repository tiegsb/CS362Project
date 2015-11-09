/*
Name: Rhett Guyer
Class: CS 362
Date: 11/8/15

Goal: The goal of this program is to use a random test to test the "Smithy" card.
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int testSmithy(int *hand, int player, int handcount, int handpos, int *testPassed, int *testFailed);
int cardNum();

int main (){
	
	srand(time(NULL));
	int i, j, count, smithyPlace, numCardsInHand, testPassed=0, testFailed=0, cardsInHand[11];
	int numOfRandTests=20;
	
	for (i=0; i<numOfRandTests;i++){
		count=0;
		smithyPlace=0;
		numCardsInHand = cardNum(); //set a random hand number between 1 and 11;
		for(j=0; j<numCardsInHand; j++){
			cardsInHand[j] = rand()%26; //select the cards to fill the hand at random
			if(cardsInHand[j] == 13){
				count++;
				smithyPlace = j;
			}
		}
		//if the hand does not have an Smithy card then go back to the for loop.
		if(count == 0){
			i--;
			continue;
		}
		
		printf("Test %d:\n",i+1);
		testSmithy(cardsInHand, 0, numCardsInHand, smithyPlace, &testPassed, &testFailed);
		printf("End Test %d\n\n",i+1);
	}

	printf("Failed tests = %d\n", testFailed);
	printf("Passed tests = %d\n\n", testPassed);
	
	return 0;
}

int testSmithy(int *hand, int player, int handCount, int handpos, int *testPassed, int *testFailed){

	int failed=0, deckCount;
	struct gameState state;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	initializeGame(2,k,1000,&state);
	
	memcpy(state.hand[player], hand, sizeof(int)*handCount);
	state.handCount[player] = handCount;
	
	deckCount = state.deckCount[player];
	
	cardEffect(state.hand[player][handpos],0,0,0,&state,handpos,0);
	
	//Check that the hand count after the execution of Smithy is 2 greater than the starting hand count.
	if(state.handCount[player] == handCount+2){
		printf("\tPASSED - HandCount was increased by 2.\n");
	}
	else{
		printf("\tFAILED - HandCount was not increased by 2.\n");
		failed = 1;
	}
	
	//Check that the hand position of the Smithy card played has been removed.
	if(state.hand[0][handpos] == 13){
		printf("\tFAILED - Smithy card was not removed.\n");
		failed = 1;
	}
	else{
		printf("\tPASSED - Smithy card was removed.\n");
	}
	
	//Check that the number of cards in the deck has decreased by 3.
	if(deckCount == state.deckCount[player]+3){
		printf("\tPASSED - Three cards were removed from the deck.\n");		
	}
	else{
		printf("\tFAILED - Exactly 3 cards were not removed from the deck.\n");
		failed=1;
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