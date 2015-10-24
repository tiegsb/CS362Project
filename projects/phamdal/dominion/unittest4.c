/**********************************************************
 * Dalena Pham
 * CS 362 - Assignment 3
 * unittest4.c
 * Unit test for function endTurn()
 * *******************************************************/

#include "assert.h"
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>

void checkEndTurn(struct gameState* state, int newPlayer, int oldPlayer) {
 	if(endTurn(state) != 0)
 		printf("endTurn returns incorrect value\n");  
 	if(state->whoseTurn != newPlayer)
 		printf("endTurn: incorrect current player\n");  
 	if(state->handCount[newPlayer] != 5)
 		printf("endTurn: new player has not received new hand\n");  
 	if(state->discardCount[oldPlayer] == 0)
 		printf("endTurn: old player did not discard hand\n"); 
 	if(state->hand[oldPlayer][0] != -1)
 		printf("endTurn: old player has an illegal hand\n");  
 	if(state->handCount[oldPlayer] != 0)
 		printf("endTurn: old player has incorrect handCount value\n");  
 	if(state->outpostPlayed != 0)
 		printf("endTurn: outpostPlayed incorrect value\n"); 
  	if(state->phase != 0)
  		printf("endTurn: incorrect phase\n"); 
   	if(state->numActions != 1)
   		printf("endTurn: numActions has not been reset\n"); 
  	if(state->numBuys != 1)
  		printf("endTurn: numBuys has not been reset\n"); 
  	if(state->playedCardCount != 0)
  		printf("endTurn: playedCardCount has not been reset\n"); 
}


int main() {
	 int i; 
 	int seed = 1000; 
 	int numPlayer = 3; 
 	struct gameState* state = newGame(); 
 	int k[10] = {adventurer, council_room, feast, gardens, mine,
 				remodel, smithy, village, baron, great_hall}; 

 	initializeGame(numPlayer, k, seed, state); 

 	printf("TESTING endTurn()\n Testing game of 3 players\n");

 	printf("Begin endTurn() Test on Player 1\n"); 
 	checkEndTurn(state, 1, 0); 

 	printf("Begin endTurn() Test on Player 2\n"); 
 	checkEndTurn(state, 2, 1); 

 	printf("Begin endTurn() Test on Player 3\n"); 
 	checkEndTurn(state, 0, 2); 

	printf("\n"); 

	return 0; 
}
