/**********************************************************
 * Dalena Pham
 * CS 362 - Assignment 3
 * unittest3.c
 * Unit test for function buyCard()
 * *******************************************************/

#include "assert.h"
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

	int i; 
	int seed = 1000; 
	int numPlayer = 2; 
	struct gameState* state = newGame(); 
	int k[10] = {adventurer, council_room, feast, gardens, mine,
 			remodel, smithy, village, baron, great_hall}; 

	initializeGame(numPlayer, k, seed, state); 

	printf("TESTING buyCard()\n");

	printf("TEST: When NumBuys is 0\n");
	state->numBuys = 0; 
	if(buyCard(estate, state) != -1)
		printf("buyCard return value incorrect\n"); 

	state = newGame(); 
	initializeGame(numPlayer, k, seed, state); 

	printf("TEST: When NumBuys is 1 but not enough coins\n");
	state->coins = 0; 
	if(buyCard(estate, state) != -1) 
		printf("buyCard return value incorrect\n");  

	state = newGame(); 
	initializeGame(numPlayer, k, seed, state);

	printf("TEST: When SupplyCount for card is 0\n"); 
	state->supplyCount[estate] = 0; 
	state-> coins = 3; 
	if(buyCard(estate, state) != -1) 
		printf("buyCard return value incorrect\n"); 

	state = newGame(); 
	initializeGame(numPlayer, k, seed, state);

	printf("TEST: Buying an Silver Card\n"); 
	state->coins = 3; 
	if(buyCard(silver, state) != 0)
		printf("buyCard return value incorrect\n"); 
	if(state->coins != 0)
		printf("buyCard coin deduction incorrect\n");  
	if(state->numBuys != 0)
		printf("buyCard numBuys deduction incorrect\n");  
	if(state->discardCount[0] != 1)
		printf("buyCard discardCount value incorrect\n");  
	if(state->supplyCount[silver] != 39)
		printf("buyCard supplyCount of silver incorrect\n"); 
	if(state->discard[0][0] != silver)
		printf("buyCard, purchased card not put into discard\n"); 

	printf("\n"); 

	return 0; 
}
