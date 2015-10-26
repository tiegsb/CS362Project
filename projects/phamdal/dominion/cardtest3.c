/**********************************************************
 * Dalena Pham
 * CS 362 - Assignment 3
 * cardtest3.c
 * Card unit test for function council_room_card()
 * *******************************************************/

#include "assert.h"
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	 int i; 
 	int fail = 0;  
 	int seed = 1000; 
 	int numPlayer = 3; 
 	struct gameState* state = newGame(); 
 	int k[10] = {adventurer, council_room, feast, gardens, mine,
 				remodel, smithy, village, baron, great_hall}; 

 	initializeGame(numPlayer, k, seed, state); 
	state->hand[0][0] = council_room; 

 	printf("TESTING council_room_card()\nGame of 3 players\n"); 

 	if(council_room_card(0, state, 0) != 0) {
 		printf("coucil_room_card has not returned successfully\n"); 
 		fail = 1; 
 	}

 	if(state->handCount[0] != 9) {
 		printf("council_room_card draws inccorrect number of cards\n"); 
 		fail = 1; 
 	}

 	if(state->deckCount[0] != 1) {
 		printf("council_room_card deckCount failure\n"); 
 		fail = 1; 
 	}

 	if(state->numBuys != 2) {
 		printf("council_room_card does not add correct number of buys\n"); 
 		fail = 1; 
 	}

 	if(state->handCount[1] != 6 || state->handCount[2] != 6) {
 		printf("council_room_card does not draw 1 card to each other player\n"); 
 		fail = 1; 
 	}

 	if(state->deckCount[1] != 4 || state->deckCount[2] != 4) {
 		printf("council_room_card deckCount failure in opponent decks\n"); 
 		fail = 1; 
 	}

 	if(state->playedCards[0] != council_room) {
 		printf("council_room_card was not placed in placed card pile\n"); 
 		fail = 1;
 	}

	if(fail)
		printf("COUNCIL_ROOM_CARD: TESTING HAS FOUND ERRORS\n\n");
	else
		printf("ALL TESTS PASSED\n\n"); 
	return 0; 
}
