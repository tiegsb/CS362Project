#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int r; 
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, adventurer, village, baron, great_hall};
	struct gameState s;

	printf ("\n\nAdventurer Card Test\n\n");

	r = initializeGame(2, k, 21, &s);

	int hand_p1[MAX_HAND] = {copper, adventurer, copper}; 
	int hand_p2[MAX_HAND] = {copper, adventurer, copper};
	int discard_p1[MAX_DECK] = {copper, silver, gold}; 
	int discard_p2[MAX_DECK] = {copper, silver, gold};
	int deck_p1[MAX_DECK] = {copper, silver, gold};
	int deck_p2[MAX_DECK] = {copper, silver, gold}; 
	int deck_empty[MAX_DECK] = {};
	
	//Set Up Player Hands
	s.handCount[0] = 3;
	s.discardCount[0] = 3;
	s.deckCount[0] = 3;
	s.handCount[1] = 3;
	s.discardCount[1] = 3;
	s.deckCount[1] = 3;
	
	//Set up Sample Decks
	memcpy(s.hand[0], hand_p1, sizeof(int)*MAX_HAND);
	memcpy(s.discard[0], discard_p1, sizeof(int)*MAX_DECK);
	memcpy(s.deck[0], deck_p1, sizeof(int)*MAX_DECK);
	memcpy(s.hand[1], hand_p2, sizeof(int)*MAX_HAND);
	memcpy(s.discard[1], discard_p2, sizeof(int)*MAX_DECK);
	memcpy(s.deck[1], deck_p2, sizeof(int)*MAX_DECK);
	
	s.whoseTurn = 0;
	
	cardEffect(adventurer, 0, 0, 0, &s, 1, 0);

	printf("Player 1 handCount is correct... ");
	if(s.handCount[0] == 5){	
		printf("Success!\n");	
	}else{
		printf("Failed!\n");	
	}

	printf("Player 1 properly discards card... ");
	if(s.discardCount[0] == 4){
		printf("Success!\n");
	}else{
		printf("Failed!\n");
	}

	printf("Player 1 deck resized... ");
	if(s.deckCount[0] == 2){
		printf("Success!\n");
	}else{
		printf("Failed!\n");
	}

	printf("Player 2 cards unaffected... ");
	if(s.handCount[1] == 3 && s.discardCount[1] == 3 && s.deckCount[1] == 3){
		printf("Success!\n");
	}else{
		printf("Failed!\n");
	}
	
	printf("\nAdventurer Card Test Completed!\n\n");
}