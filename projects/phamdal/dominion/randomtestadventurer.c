/* Dalena Pham
 * CS 362 - Assignment 4
 * Random Tests for Adventurer card */
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>


#define MAX_TESTS 1000
#define BOUNDARY_HAND 10
#define BOUNDARY_DECK 10
// These are already defined in dominion.h
//#define MAX_DECK 500
//#define MAX_HAND 500

void runTests(int handLimit, int deckLimit) {
	// Varibles to help set up game
 	int i, j, numPlayers, seed, curPlayer, handCount, deckCount, discardCount, deckTreasures, card;  
 	// Counters to measure test successes/failures; 
 	int handCountfailure = 0, handCountpass = 0; 
 	int deckCountfailure = 0, deckCountpass = 0; 
 	int playedPileFailure = 0, playedPilePass = 0; 
 	int cardDrawnFailure = 0, cardDrawnPass = 0, cardDrawnTest = 0; 

	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	    sea_hag, tribute, smithy};
	struct gameState *state = NULL; 

	for(i = 0; i < MAX_TESTS; i++) {
		// Reset Conditions 
		state = newGame(); 
		deckTreasures = 0;
		seed = rand();  

		// Number of players in between 2 - 4
		numPlayers = (rand() % 3) + 2; 
		curPlayer = rand() % numPlayers; 
 		initializeGame(numPlayers, k, seed, state);
 		state->whoseTurn = curPlayer; 

 		// Randomized hand + deck + discard
 		handCount = (rand() % (handLimit + 1) + 1 ); 
 		state->handCount[curPlayer] = handCount; 
 		deckCount = (rand() % (deckLimit + 1) + 1 ); 
 		state->deckCount[curPlayer] = deckCount; 
 	 	discardCount = (rand() % (deckLimit + 1) + 1); 
 		state->discardCount[curPlayer] = discardCount; 

 		// Fill up hands and discard
	   for (j = 0; j < handCount; j++) {
		   state->hand[curPlayer][j] = rand() % 27;
	   }

	   for (j = 0; j < discardCount; j++) {
	   		state->discard[curPlayer][j] = rand() % 27; 
	   }

		// Fill up deck + count the number of treasure cards in each deck
	   for (j = 0; j < deckCount; j++) {
	   		card = rand() % 27; 
		 	state->deck[curPlayer][j] = card;
		 	if(card == gold || card == silver || card == copper)
		 		deckTreasures++; 
	   }

		// Place Adventurer in hand 
		state->hand[curPlayer][0] = adventurer; 

		// Run adventurer_card
		cardEffect(adventurer, 0, 0, 0, state, 0, 0);  
		
		// Condition 1: Deck has 2  or more treasure cards
		if(deckTreasures >= 2) {

			if(state->handCount[curPlayer] != handCount + 1)
				handCountfailure++; 
			else
				handCountpass++;
			
			if(state->deckCount[curPlayer] == 0)
				deckCountfailure++; 
			else
				deckCountpass++;
			
			if(state->playedCardCount != 1)
				playedPileFailure++; 
			else
				playedPilePass++;

			cardDrawnTest++; 
			if(state->hand[curPlayer][handCount - 1] != copper || state->hand[curPlayer][handCount - 1] != silver || state->hand[curPlayer][handCount - 1] != gold
				|| state->hand[curPlayer][handCount - 2] != copper || state->hand[curPlayer][handCount - 2] != silver || state->hand[curPlayer][handCount - 2] != gold )
				cardDrawnFailure++; 
			else 
				cardDrawnPass++; 

		// Condition 2: Deck has only 1 treasure card
		} else if (deckTreasures == 1) {
			if(state->handCount[curPlayer] != handCount)
				handCountfailure++; 
			else 
				handCountpass++; 

			if(state->deckCount[curPlayer] == 0)
				deckCountfailure++; 
			else 
				deckCountpass++;
             
			if(state->playedCardCount != 1)
				playedPileFailure++; 
			else
				playedPilePass++;

			cardDrawnTest++; 
			if(state->hand[curPlayer][handCount - 1] != copper || state->hand[curPlayer][handCount - 1] != silver || state->hand[curPlayer][handCount - 1] != gold)
				cardDrawnFailure++; 
			else
				cardDrawnPass++;

		// Condition 3: Deck has no treasure cards
		} else { 
			if(state->handCount[curPlayer] != handCount - 1)
				handCountfailure++; 
			else 
				handCountpass++; 

			if(state->deckCount[curPlayer] == 0)
				deckCountfailure++; 
			else
				deckCountpass++;

			if(state->playedCardCount != 1)
				playedPileFailure++; 
			else
				playedPilePass++; 	
		}  
	}

	printf("\nHandCount Failures: %d/1000\t HandCount Passes: %d/1000\n", handCountfailure, handCountpass); 
	printf("DeckCount Failures: %d/1000\t DeckCount Passes: %d/1000\n", deckCountfailure, deckCountpass);
	printf("PlayedCardCount Failures: %d/1000\t PlayedCardCount Passes: %d/1000\n", playedPileFailure, playedPilePass);  	
	printf("Resulting Cards Failures: %d/%d\t Resulting Cards Passes: %d/%d\n", cardDrawnFailure, cardDrawnTest, cardDrawnPass, cardDrawnTest); 
} 

int main() {
 
	srand(time(NULL)); 
	printf("Random Adventurer Card Tests------------------------ \n"); 
	runTests(MAX_HAND, MAX_DECK); 

	// TESTS RESULT IN SEG FAULT SEE RANDOMHISTORY FOR MORE
	//printf("Random Adventurer - Boundaries Enforced------------- \n"); 
	//runTests(BOUNDARY_HAND, BOUNDARY_DECK); 

	return 0; 
}
 
