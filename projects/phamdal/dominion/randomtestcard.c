/* Dalena Pham
 * CS 362 - Assignment 4
 * Random Tests for Sea Hag card */
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TESTS 1000

 int main() {
   	srand(time(NULL)); 

 	int i, j, m, curPlayer = 0, handCount, deckCount, card, numPlayers, seed; 

 	// Variables to keep keep track of player status
 	int deckCount0, deckCount1, deckCount2, deckCount3;
 	int card1, card2, card3;
  	int counter, failure;   

 	// Variables to record testing results
 	int playedPileFailure = 0, playedPilePass = 0; 
 	int topDeckFailure = 0, topDeckPass = 0; 
  	int deckCountFailure = 0, deckCountPass = 0; 
 	int oppDeckCountFailure = 0, oppDeckCountPass = 0;
 	int handCountFailure = 0, handCountPass = 0;  
 	int topCardFailure = 0, topCardPass = 0; 
 
 	int k[10] = {sea_hag, council_room, feast, gardens, mine,
 				remodel, smithy, village, baron, great_hall}; 
 	struct gameState *state = NULL; 


	printf("Random Sea Hag Card Tests------------------------ \n"); 

	 
 	for(i = 0; i < MAX_TESTS; i++) {
 		// Reset Conditions
		seed = rand(); 
		state = newGame(); 
			
		// Number of players in between 2 - 4
		numPlayers = (rand() % 3) + 2;  
 		initializeGame(numPlayers, k, seed, state);
 		state->whoseTurn = curPlayer;

 		// Create and fill up current player's hand
 		handCount = (rand() % (MAX_HAND + 1) + 1); 
 		state->handCount[curPlayer] = handCount;
 
	    for (j = 0; j < handCount; j++) {
		   state->hand[curPlayer][j] = rand() % 27;
		} 
	
		// Create and fill up decks
 		for(m = 0; m < numPlayers; m++) {
	 		deckCount = (rand() % (MAX_DECK + 1));
	 		state->deckCount[m] = deckCount; 

			// Fill up deck, avoid curse card
		   for (j = 0; j < deckCount; j++) {
		   		card = rand() % 27 + 1; 
			 	state->deck[m][j] = card;
		    }

		    // Take note of deckCounts and top Cards
	 		switch(m) {
	 			case 0 :
	 				deckCount0 = deckCount;
	 				break;   
	 			case 1:
	 				deckCount1 = deckCount; 
	 				card1 = state->deck[m][deckCount - 1]; 
	 				break; 
	 			case 2: 
	 				deckCount2 = deckCount;
	 				card2 = state->deck[m][deckCount - 1]; 
	 				break;  
	 			case 3:
	 				deckCount3 = deckCount; 
	 				card3 = state->deck[m][deckCount - 1]; 
					break; 
	 		} 
		
 		}

		// Place sea_hag in hand 
		state->hand[curPlayer][0] = sea_hag; 

		// Call Sea Hag
		cardEffect(sea_hag, 0, 0, 0, state, 0, 0);


		// Current player's handCount should be one less (discard Sea Hag)
		if(state->handCount[curPlayer] != handCount - 1)
			handCountFailure++; 
		else
			handCountPass++;  

		// Current player's deckCount should be the same
		if(state->deckCount[curPlayer] != (deckCount0))
			deckCountFailure++; 
		else
			deckCountPass++; 

		// Sea Hag should be placed in played card pile
		if(state->playedCardCount != 1)
			playedPileFailure++; 
		else
			playedPilePass++;
 
		// Check that the opponent's top decks all have a curse card on top
		counter = 1; 
		failure = 0;
		while(counter < numPlayers && failure == 0) {
			if (state->deck[counter][state->deckCount[counter] - 1]  != 0)  {
				topDeckFailure++;
				failure = 1;  
			}
			counter++; 
		}
		if(failure == 0)
			topDeckPass++; 

		// Check that opponents decks are unchanged (discard a card, add a curse card)
		failure = 0; 
		counter = 1; 
		while(counter < numPlayers && failure == 0) {
			switch(counter) {
				case 1:
					if(state->deckCount[counter] != deckCount1) {
						oppDeckCountFailure++; 
						failure = 1; 
					} 
					break; 
				case 2: 
					if(state->deckCount[counter] != deckCount2) {
						oppDeckCountFailure; 
						failure = 1;
					}
					break; 
				case 3: 
					if(state->deckCount[counter] != deckCount3) {
						oppDeckCountFailure++; 
						failure = 1; 
					}					
			}
			
			counter++; 
		}

		if(failure == 0)
			oppDeckCountPass++; 

		// Make sure opponent's previous top card is now in discard
		failure = 0; 
		counter = 1; 
		while (counter < numPlayers && failure == 0) {
			switch(counter){
				case 1: 
					if(card1 != state->deck[counter][state->deckCount[counter] - 1]) {
						topCardFailure++; 
						failure = 1; 
					}
					break; 
				case 2: 
					if(card2 != state->deck[counter][state->deckCount[counter] - 1]) {
						topCardFailure++; 
						failure = 1; 
					}		
					break; 
				case 3:
					if(card3 != state->deck[counter][state->deckCount[counter] - 1]) {
						topCardFailure++; 
						failure = 1; 
					}		
					break; 							
			}
			counter++; 
		}

		if(failure == 0)
			topCardPass++; 
	}

	
	printf("\nPlayed Pile Failures: %d/1000\t Played Pile Passes: %d/1000\n", playedPileFailure, playedPilePass); 
	printf("Top Deck Failures: %d/1000\t Top Deck Passes: %d/1000\n", topDeckFailure, topDeckPass);
	printf("Deck Count Failures: %d/1000\t Deck Count Count Passes: %d/1000\n", deckCountFailure, deckCountPass);  	
	printf("HandCount Failures: %d/1000\t HandCount Passes: %d/1000\n", handCountFailure, handCountPass);
	printf("Opp. Deck Count Failures: %d/1000\t Opp. Deck Count Passes: %d/1000\n", oppDeckCountFailure, oppDeckCountPass);   	
	printf("Top Card Failures: %d/1000\t Top CardPasses: %d/1000\n", topCardFailure, topCardPass);

 	return 0; 
 }
