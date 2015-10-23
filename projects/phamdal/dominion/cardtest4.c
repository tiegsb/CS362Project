/**********************************************************
 * Dalena Pham
 * CS 362 - Assignment 3
 * cardtest4.c
 * Card unit test for function sea_hag
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

 	printf("TESTING sea hag switch case in cardeffect()\n Game of 3 players\n"); 
 	state->hand[0][0] = sea_hag; 

 	state->deck[1][9] = silver; 
 	state->deck[2][9] = gold; 

 	if(cardEffect(sea_hag, 0, 0, 0, state, 0, 0) != 0) {
 		printf("sea_hag returns wrong value\n"); 
 		fail = 1; 
 	}

 	if(state->playedCards[0] != sea_hag) {
 		printf("sea_hag was not placed in played pile\n"); 
 		fail = 1; 
 	}

 	if(state->handCount[0] != 3) {
 		printf("Incorrect number of cards in Player 1 hand\n"); 
 		fail = 1; 
 	}

 	if(state->deckCount[0] != 5) {
 		printf("Player 1 deck was altered in unexpected way\n"); 
 		fail = 1; 
 	}

 	if(state->deck[0][4] == curse) {
 		printf("Player 1 has curse card, this is incorrect\n"); 
 		fail = 1; 
 	}

 	if(state->discardCount[0] != 0) {
 		printf("Player 1 should not have a discard pile\n"); 
 		fail = 1;
 	}

 	if(state->deckCount[1] != 10 || state->deckCount[2] != 10) {
 		printf("Player 2/3 decks altered in unexpected way\n"); 
 		fail = 1; 
 	}

 	if(state->deck[1][9] != curse || state->deck[2][9] != curse) {
 		printf("Player 2/3 did not obtain the curse card at top of deck\n"); 
		fail = 1; 
 	}

 	if(state->discard[1][0] != silver || state->discard[2][0] != gold) {
 		printf("Wrong top of deck cards were discarded\n"); 
		fail = 1; 
 	}

 	if(fail)
 		printf("SEA_HAG TESTING HAS FOUND ERRORS\n\n"); 
 	else 
 		printf("ALL TESTS PASS\n\n"); 

 	return 0; 
 }
