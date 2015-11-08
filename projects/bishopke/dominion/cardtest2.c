// Keenan Bishop
// cardtest2.c
// adventurer (required)

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void test_card_adventurer(){
	int seed = 1000;
	int numPlayer = 2; //2 players
	int r; 
	//set kindom cards to a normalish set
	int k[10] = {adventurer, council_room, feast, gardens, mine,
			 remodel, adventurer, village, baron, great_hall};
	struct gameState G;

	printf ("TESTING adventurer card!:\n");

	// initialize a new game for testing
	r = initializeGame(numPlayer, k, seed, &G);

	//make up hands (that include )
	int hand_p1[MAX_HAND] = {copper, adventurer, copper}; 
	int hand_p2[MAX_HAND] = {copper, adventurer, copper};
	//discards 
	int discard_p1[MAX_DECK] = {copper, silver, gold}; 
	int discard_p2[MAX_DECK] = {copper, silver, gold};
	//decks
	// need empty to check adventurer's shuffle function
	int deck_p1[MAX_DECK] = {copper, silver, gold};
	int deck_p2[MAX_DECK] = {copper, silver, gold}; 
	//int deck_empty[MAX_DECK] = {};
	//copy hands to gamestate
	G.handCount[0] = 3;
	G.discardCount[0] = 3;
	G.deckCount[0] = 3;
	//player 2
	G.handCount[1] = 3;
	G.discardCount[1] = 3;
	G.deckCount[1] = 3;
	// use memcopy to insert sample decks into gamestate
	memcpy(G.hand[0], hand_p1, sizeof(int)*MAX_HAND);
	memcpy(G.discard[0], discard_p1, sizeof(int)*MAX_DECK);
	memcpy(G.deck[0], deck_p1, sizeof(int)*MAX_DECK);
	//player 2
	memcpy(G.hand[1], hand_p2, sizeof(int)*MAX_HAND);
	memcpy(G.discard[1], discard_p2, sizeof(int)*MAX_DECK);
	memcpy(G.deck[1], deck_p2, sizeof(int)*MAX_DECK);

	//play card
	//cardEffect function:
	//int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
	// in our case, choice1,2,3 = 0
	// bonus = 0
	// handpos = 1 (2nd card in hand)
	
	// first set player to player 1
	G.whoseTurn = 0;
	// first check return of 0 for success
	if(cardEffect(adventurer, 0, 0, 0, &G, 1, 0)){
		printf("FAIL: cardEffect(adventurer): function returned non-zero!\n");	
	}
	else{
		printf("PASS: cardEffect(adventurer): function returned zero!\n");	
	}

	//next check for 2 treasure cards gained (player 1)
	if(G.handCount[0] == 5){	
		printf("PASS: cardEffect(adventurer): player 1 gained 2 treasure cards!\n");	
	}
	else{
		printf("FAIL: cardEffect(adventurer): player 1 did not gain 1 card! hand count = %d\n", G.handCount[0]);	
	}

	//check for discarded card!
	if(G.discardCount[0] == 4){
		printf("PASS: cardEffect(adventurer): player 1 discarded a card!\n");
	}
	else{
		printf("FAIL: cardEffect(adventurer): player 1 discarded count != 4, = %d\n", G.discardCount[0]);
	}

	//check for cards drawn from deck (player 1)
	if(G.deckCount[0] == 2){
		printf("PASS: cardEffect(adventurer): player 1 deck lost 1 cards!\n");
	}
	else{
		printf("FAIL: cardEffect(adventurer): player 1 deck didn't lose 1 card, contains %d cards\n", G.deckCount[0]);
	}

	//as specified in directions, we need to check the other player in case something weird happened!
	//check player 2's hand, discard, and deck count
	if(G.handCount[1] == 3 && G.discardCount[1] == 3 && G.deckCount[1] == 3){
		printf("PASS: cardEffect(adventurer): player 2 cards not affected!\n");
	}
	else{
		printf("FAIL: cardEffect(adventurer): player 2 cards were affected!\n");
	}



}

int main(){
	test_card_adventurer();
	return 0;
}
