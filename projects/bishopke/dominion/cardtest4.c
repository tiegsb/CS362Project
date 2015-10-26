// Keenan Bishop
// cardtest4.c
// village
//

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

//village
// draw 1 card
// +2 actions

void test_card_village(){
	int seed = 1000;
	int numPlayer = 2; //2 players
	int r; 
	//set kindom cards to a normalish set
	int k[10] = {adventurer, council_room, feast, gardens, mine,
			 remodel, village, village, baron, great_hall};
	struct gameState G;

	printf ("TESTING village card!\n");

	// initialize a new game for testing
	r = initializeGame(numPlayer, k, seed, &G);

	//make up hands (that include village)
	int hand_p1[MAX_HAND] = {copper, village, copper}; 
	int hand_p2[MAX_HAND] = {copper, village, copper};
	//discards 
	int discard_p1[MAX_DECK] = {copper, silver, gold}; 
	int discard_p2[MAX_DECK] = {copper, silver, gold};
	//decks
	int deck_p1[MAX_DECK] = {copper, silver, gold};
	int deck_p2[MAX_DECK] = {copper, silver, gold}; 
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

	//printf("boop!\n");

	//other variables
	int actions_p1 = G.numActions;

	//play card
	//cardEffect function:
	//int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
	// in our case, choice1,2,3 = 0
	// bonus = 0
	// handpos = 1 (2nd card in hand)
	
	// first set player turn to player 1
	G.whoseTurn = 0;
	// make sure actions is a usable amount
	G.numActions = 1;
	// first check return of 0 for success
	if(cardEffect(village, 0, 0, 0, &G, 1, 0)){
		printf("FAIL: cardEffect(village): function returned non-zero!\n");	
	}
	else{
		printf("PASS: cardEffect(village): function returned zero!\n");	
	}

	//next check for 1 card drawn (player 1)
	if(G.handCount[0] != 3){	
		printf("FAIL: cardEffect(village): player 1 gained 1 card!\n");	
	}
	else{
		printf("FAIL: cardEffect(village): player 1 did not gain 1 card!\n");	
	}

	//check for discarded card!
	if(G.discardCount[0] == 4){
		printf("PASS: cardEffect(village): player 1 discarded a card!\n");
	}
	else{
		printf("FAIL: cardEffect(village): player 1 discarded count != 4, = %d\n", G.discardCount[0]);
	}

	//check for 1 cards drawn from deck (player 1)
	if(G.deckCount[0] == 2){
		printf("PASS: cardEffect(village): player 1 deck gained 1 cards!\n");
	}
	else{
		printf("FAIL: cardEffect(village): player 1 deck isn't empty, contains %d cards\n", G.deckCount[0]);
	}

	//check for actions
	if(G.numActions == (actions_p1 + 2)){
		printf("PASS: cardEffect(village): player 1 gained 2 actions!\n");
	}
	else{
		printf("FAIL: cardEffect(village): player 1 didn't gain two actions, has %d actions\n", G.numActions);
	}

	//as specified in directions, we need to check the other player in case something weird happened!
	//check player 2's hand, discard, and deck count
	if(G.handCount[1] == 3 && G.discardCount[1] == 3 && G.deckCount[1] == 3){
		printf("PASS: cardEffect(village): player 2 cards not affected!\n");
	}
	else{
		printf("FAIL: cardEffect(village): player 2 cards were affected!\n");
	}



}

int main(){
	test_card_village();
	return 0;
}
