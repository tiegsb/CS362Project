/**********************************************************
 * Dalena Pham
 * CS 362 - Assignment 3
 * unittest2.c
 * Unit test for function drawCard()
 * *******************************************************/

#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>


void helper(int hand, int deck, int handpos, struct gameState* state) {
  if(drawCard(0, state) != 0)
    printf("drawCard failed to run\n");  
  if(state->handCount[0] != hand)
    printf("Incorrect number of cards in hand\n"); 
  if(state->deckCount[0] != deck)
    printf("Incorrect number of cards in deck\n"); 
  if(state->hand[0][handpos] != state->deck[0][4])
    printf("Incorrect card drawn\n");  
}

 int main() {
	int i;
 	int seed = 1000; 
 	int numPlayer = 2; 
 	struct gameState* state = newGame(); 
 	int k[10] = {adventurer, council_room, feast, gardens, mine,
 				remodel, smithy, village, baron, great_hall}; 

 	initializeGame(numPlayer, k, seed, state); 

 	printf("TESTING drawCard()\n"); 
 	printf("TEST: Draw a card to a hand of 6 cards\n"); 
	helper(6, 4, 5, state); 

 	state = newGame(); 
 	initializeGame(numPlayer, k, seed, state); 

 	printf("TEST: Draw card to empty hand\n"); 
 	state->handCount[0] = 0; 
 	helper(1, 4, 0, state); 

 	state = newGame(); 
 	initializeGame(numPlayer, k, seed, state); 

 	printf("TEST: Draw card from empty deck but not empty discard pile\n"); 
 	// Place cards into discard pile - CODE ADAPTED FROM DOMINION.C FILE
 	//Discard hand
	for (i = 0; i < state->handCount[0]; i++){
    		state->discard[0][state->discardCount[0]++] = state->hand[0][i];//Discard
    		state->hand[0][i] = -1;//Set card to -1
  	}

  	state->handCount[0] = 0;//Reset hand count
  	state->deckCount[0] = 0; 

 	 helper(1, 4, 0, state); 
  	if(state->discard[0][0] != -1)
   		 printf("FAIL: discard pile altered in unexpected way\n");  
  	if(state->discardCount[0] != 0)
    		printf("FAIL: incorrect discardCount"); 

  	state = newGame(); 
 	initializeGame(numPlayer, k, seed, state); 

 	printf("TEST: Draw card from completely empty deck - no cards\n"); 
 	state->deckCount[0] = 0; 
  	if(drawCard(0, state) != -1)
    		printf("FAIL: Incorrect return value");  
 	
	printf("\n"); 

 	return 0; 
 }
