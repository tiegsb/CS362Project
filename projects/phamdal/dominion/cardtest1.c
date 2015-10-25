/**********************************************************
 * Dalena Pham
 * CS 362 - Assignment 3
 * cardtest1.c
 * Card unit test for function smithy_card()
 * *******************************************************/

#include "assert.h"
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>

 int main() {
 	int i, result;
 	int fail = 0;  
 	int seed = 1000; 
 	int numPlayer = 2; 
 	struct gameState* state = newGame(); 
 	int k[10] = {adventurer, council_room, feast, gardens, mine,
 				remodel, smithy, village, baron, great_hall}; 

 	initializeGame(numPlayer, k, seed, state); 

 	printf("TESTING smithy_card()\n"); 

 	state->hand[0][0] = smithy; 

 	if (smithy_card(0, state, 0) != 0) {
 		printf("smithy_card failture to run\n"); 
 		fail = 1; 
 	}

 	if(state->handCount[0] != 7) {
 		printf("smithy_card discard/draw error\n"); 
 		fail = 1; 
 	}

 	if(state->deckCount[0] != 2) {
 		printf("smithy_card does not draw from deck\n"); 
 		fail = 1; 
 	}

 	if(state->playedCards[state->playedCardCount] != smithy) {
 		printf("smith_card does not place card in playedCard pile\n"); 
 		fail = 1; 
 	}

 	if(state->playedCardCount != 1) {
 		printf("smithy_card does not incremented playedCardCount\n"); 
 		fail = 1; 
 	}

 	if(fail)
 		printf("SMITHY_CARD: TESTS FOUND FAILURES\n\n"); 
 	else 
 		printf("ALL TESTS PASSED\n\n"); 

 	return 0; 
} 
