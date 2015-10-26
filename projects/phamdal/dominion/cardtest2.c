/**********************************************************
 * Dalena Pham
 * CS 362 - Assignment 3
 * cardtest2.c
 * Card unit test for function adventurer_card()
 * *******************************************************/

#include "assert.h"
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
 	int i;
 	int fail1 = 0, fail2 =0, fail3 = 0;  
 	int seed = 1000; 
 	int tempHand[MAX_HAND]; 
	int numPlayer = 2; 
 	struct gameState* state = newGame(); 
 	int k[10] = {adventurer, council_room, feast, gardens, mine,
 				remodel, smithy, village, baron, great_hall}; 

 	initializeGame(numPlayer, k, seed, state); 

 	printf("TESTING adventurer_card()\n");
 	printf("Testing with deck of 8 cards\n"); 
 	printf("Cards: Curse, Feast, Silver, Outpost, Gold, Estate, Adventurer, and Silver\n");  

 	state->deckCount[0] = 8;
	state->deck[0][0] = silver; 
	state->deck[0][1] = adventurer; 
	state->deck[0][2] = duchy; 
	state->deck[0][3] = gold; 
	state->deck[0][4] = smithy; 
	state->deck[0][5] = silver; 
	state->deck[0][6] = feast; 
	state->deck[0][7] = curse;  


 	if(adventurer_card(0, state, 0, 0, 0, tempHand) != 0) {
 		printf("adventurer_card failed to run\n"); 
 		fail1 = 1; 
 	}
 
 	if(state->handCount[0] != 7) {
 		printf("adventurer_card did not draw correct number of cards\n"); 
 		fail1 = 1; 
 	}

 	if(state->hand[0][5] != silver && state->hand[0][6] != gold) {
 		printf("adventurer_card did not draw correct cards\n"); 
 		fail1 = 1; 
 	}

 	if(state->discardCount[0] != 3) {
 		printf("adventurer_card did not discard correct number of cards\n"); 
 		fail1 = 1; 
 	}

 	if(state->discard[0][0] != curse && state->discard[0][1] != feast && state->discard[0][2] != outpost) {
 		printf("adventurer_card did not discard correct cards\n"); 
 		fail1 = 1; 
 	}

	if(state->playedCards[0] != adventurer) {
		printf("adventurer_card was not placed in played pile\n"); 
		fail1 = 1; 

	}

	printf("Testing case where only 1 treasure card in deck\n"); 
 	state = newGame(); 
	initializeGame(numPlayer, k, seed, state); 
 	state->deck[0][4] = smithy; 
 	state->deck[0][3] = estate; 
 	state->deck[0][2] = duchy; 
 	state->deck[0][1] = adventurer; 
 	state->deck[0][0] = silver; 
	
	adventurer_card(0, state, 0, 0, 0, tempHand); 
 	if(state->handCount[0] != 6) {
 		printf("adventurer_card has drawn incorrect number of cards\n");
 		fail2 = 1; 
 	}

 	if(state->hand[0][5] != silver) {
 		printf("adventurer_card has drawn incorrect card\n");
 		fail2 = 1; 
 	}

	if(!fail2)
		printf("PASSED\n"); 

 	printf("\nTesting with empty deck but populated discard pile\n"); 
 	state = newGame(); 
	initializeGame(numPlayer, k, seed, state); 

	state->deckCount[0] = 0; 
	state->discardCount[0] = 6; 
	state->discard[0][0] = council_room; 
	state->discard[0][1] = gold; 
	state->discard[0][2] = village; 
	state->discard[0][3] = baron; 
	state->discard[0][4] = gold; 
	state->discard[0][5] = curse; 
	state->discard[0][6] = gold; 

	adventurer_card(0, state, 0, 0, 0, tempHand); 

	if(state->hand[0][5] != gold && state->hand[0][6] != gold) {
		printf("adventurer_card does shuffle discard pile back into deck as stated\n");
		fail3 = 1;  
	}

	if(!fail3)
		printf("PASSED\n"); 

	if(fail1 || fail2 || fail3) 
		printf("ADVENTURER_CARD: TESTING HAS FOUND ERRORS\n\n"); 
	else 
		printf("ALL TESTS PASSED\n\n"); 

	return 0; 
}
