//Assignment 4 random test card
//villager
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//variable for number of tests run
#define TESTS 100000


void random_test_card_adventurer(){


	//make holders for failures and passes
	int fail_a = 0;	
	int pass_a = 0;
	int fail_c = 0;	
	int pass_c = 0;

	int i = 0;
	int j = 0;

	int k[10] = {adventurer, council_room, feast, gardens, mine,
		 remodel, adventurer, village, baron, great_hall};

	//holder variables
	//since we need to check adventurer, keep track of number of treasures
	int numTreasures;
	int checkTreasures_before = 0;
	int checkTreasures_after = 0;
	//number of players
	int numPlayers = 0;
	//random seed, reset every test
	int seed = rand();	
	// this holds return value of initializeGame()
	int r;
	//game state holder
	//struct gameState G;


	printf ("RANDOM TESTING VILLAGE CARD, %d iterations!:\n", TESTS);
	//start for loop for amount of tests	
	for(i = 0; i < TESTS; i++){
		//make random seed
		seed = rand();
		//make players random
		numPlayers = (rand()%3)+2; //1-3 players
		//initialize game
		
		struct gameState G;
		r = initializeGame(numPlayers, k, seed, &G);
		//reset treasure counter
		numTreasures = 0;
		checkTreasures_before = 0;
		checkTreasures_after = 0;
		//set current player	
		G.whoseTurn = rand()%numPlayers;
		//fill current player's hand with random cards
		//use 27 as modulus for card type
		
		//hand count (can these all be zero?)
		G.handCount[G.whoseTurn] = (rand() % MAX_HAND);
		//discard count
		G.discardCount[G.whoseTurn] = (rand() % MAX_DECK);
		//deck count
		G.deckCount[G.whoseTurn] = (rand() % MAX_DECK);
		//played card count
		G.playedCardCount = 0;	

		// now put random cards into this player's sets

		//hand
		for(j = 0; j < G.handCount[G.whoseTurn]; j++){
			G.hand[G.whoseTurn][j] = rand()%27;
		}
		//discard
		for(j = 0; j < G.discardCount[G.whoseTurn]; j++){
			G.discard[G.whoseTurn][j] = rand()%27;
		}
		//deck
		//since adventurer uses treasure cards to limit its effect
		//we should count it here for later checking.
		
		// first give adventurer card to current player
		G.hand[G.whoseTurn][0] = village;
	
		//record hand count in temp variable
		//int cardcount = G.handCount[G.whoseTurn];
		int deck_count = G.deckCount[G.whoseTurn];
		//record other stuff to check
		//actions
		int actions = G.numActions;
		
		// apply card effect (hand position 0)
		cardEffect(village, 0, 0, 0, &G, 0, 0);

		//check for effects!
		
		//effect: 
		//+1 action
		if(G.numActions != actions + 2){
			fail_a++;
		}
		else{
			pass_a++;
		}
		//+2 cards
		if(G.deckCount[G.whoseTurn] != deck_count +1){
			fail_c++;
		}
		else{
			pass_c++;
		}

	}


	printf("RAND_VILLAGE: PASS_actions = %d\tFAIL_actions = %d\n\t\tPASS_cards = %d\tFAIL_cards = %d\n\t\tTOTAL POSSIBLE = %d\n", pass_a, fail_a, pass_c, fail_c, TESTS*2);
}

int main(){
	srand(time(NULL));
	random_test_card_adventurer();
	return 0;
}
