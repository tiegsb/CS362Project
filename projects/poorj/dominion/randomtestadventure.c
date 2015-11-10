#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

/*Adventurer random card tests*/
int randomTestAdventurer(){
	int i, j;
	int numPlayers = 2;
	int player = 0;
	int seed = 1000;
	int k[10] = {adventurer, council_room, feast, gardens, mine
			   , remodel, smithy, copper, gold, silver};
	int badHand = 0;
	int badDiscard = 0;
	int badPlayed = 0;
	int randomNum;
	int numTreasure;
	
	/*creates new game*/
	struct gameState state;
	
	/*seeds random*/
	srand(time(NULL));
	
	
	memset(&state, 23, sizeof(struct gameState));
	
	for(i = 0; i < 500; i++){
		int handNum;
		int discardNum;
		initializeGame(numPlayers, k, seed, &state);
		
		/*treasure count is 0*/
		numTreasure = 0;
		
		/*get random number of cards, 1-10*/
		state.handCount[player] = rand() % 11 + 1;
		printf("Cards in hand: %d\n", state.handCount[player]);
		
		/*put adventurer card in hand*/
		state.hand[player][0] = 7;

		/*get random number of discarded cards, 1-10*/
		state.discardCount[player] = rand() % 11;
		printf("Cards in discard pile: %d\n", state.discardCount[player]);

		/*save number of cards in hand and discard pile*/
		handNum = state.handCount[player];
		discardNum = state.discardCount[player];
		
		/*put cards into player's hand*/
		for (j = 1; j < state.handCount[player]; j++){
			randomNum = rand() % 10;
			state.hand[player][i] = k[randomNum];
			printf("Hand card: %d\nkingdom card: %d\n", 
					state.hand[player][i], k[randomNum]);
		}
		
		/*put cards into discard pile*/
		for (j = 0; j < state.discardCount[player]; j++){
			randomNum = rand() % 10;
			state.discard[player][i] = k[randomNum];
			printf("Discard card: %d\nkingdom card: %d\n", 
					state.discard[player][i], k[randomNum]);
		}
	
		printf("Starting hand count: %d\n", state.handCount[player]);
		printf("Starting discard count: %d\n", state.discardCount[player]);
		
		adventurerCard(&state);

		printf("After play hand count: %d\n", state.handCount[player]);
		printf("After play discard count: %d\n", state.discardCount[player]);

		/*check last card added to hand*/
		if(state.hand[player][state.handCount[player] - 1] == copper || 
			state.hand[player][state.handCount[player] - 1] == silver || 
			state.hand[player][state.handCount[player] - 1] == gold)
		{
			numTreasure++;
		}
		else{
			printf("Card not in last position.\n");
		}
		
		/*check second to last card added to hand*/
		if(state.hand[player][state.handCount[player] - 2] == copper || 
			state.hand[player][state.handCount[player] - 2] == silver || 
			state.hand[player][state.handCount[player] - 2] == gold)
		{
			numTreasure++;
		}
		else{
			printf("Card not in 2nd to last position.\n");
		}
		
		/*check if hand has only up to two additional cards*/
		if(handNum <= state.handCount[player] + 2){	
			printf("Hand has acceptable number of cards.\n");
		}
		else{
			printf("Hand has too many cards.\n");
			badHand++;
		}
		
		/*check if discard pile got at least two additional cards*/
		if(discardNum >= state.discardCount[player] - 2){
			printf("Discard pile has acceptable card number.\n");
		}
		else{
			printf("Discard pile has too few cards.\n");
			badDiscard++;
		}
		
		/*check the number of treasure cards*/
		if(numTreasure >= 0 && numTreasure <= 2){
			printf("Treasure count is acceptable.\n");
		}
		else{
			printf("Treasure count unacceptable.\n");
		}
	}
	
	printf("Bad cards out of 500: %d\nBad discards out of 500: %d\n
			Bad plays out of 500: %d\n", badHand, badDiscard, badPlayed);
	return 0;
}

int main(){
	randomTestAdventurer();
	return 0;
}