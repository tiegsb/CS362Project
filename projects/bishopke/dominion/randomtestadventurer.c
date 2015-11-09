//assignment 4 adventurer random card test
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
	int fail = 0;	
	int pass = 0;

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


	printf ("RANDOM TESTING ADVENTURER CARD, %d iterations!:\n", TESTS);
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
		
		for(j = 0; j < G.deckCount[G.whoseTurn]; j++){
			G.deck[G.whoseTurn][j] = rand()%27;
			//increment treasures count
			if(G.deck[G.whoseTurn][j] == copper ||
			   G.deck[G.whoseTurn][j] == silver ||
			   G.deck[G.whoseTurn][j] == gold){
				numTreasures++;
			}
		}
		//count treasures in hand
		for(j = 0; j < G.handCount[G.whoseTurn]; j++){
			//G.deck[G.whoseTurn][j] = rand()%27;
			//increment treasures count
			if(G.hand[G.whoseTurn][j] == copper ||
			   G.hand[G.whoseTurn][j] == silver ||
			   G.hand[G.whoseTurn][j] == gold){
				checkTreasures_before++;
			}
		}
	
		//printf("numTreasures = %d\n", numTreasures);
		// random game state is set up, test card effect here
		
		// first give adventurer card to current player
		G.hand[G.whoseTurn][0] = adventurer;
	
		//record hand count in temp variable
		int cardcount = G.handCount[G.whoseTurn];
		// apply card effect (hand position 0)
		cardEffect(adventurer, 0, 0, 0, &G, 0, 0);

		//check for effects!
		
		//effect: 
		//Reveal cards from your deck until you reveal 2 Treasure cards. 
		//Put those Treasure cards in your hand and discard the other revealed cards.	


		//check for effect depending on number of treasures
		// 2+ treasures
		if(numTreasures > 1){
			//recalculate treasures!
			for(j = 0; j < G.handCount[G.whoseTurn]; j++){
				//G.deck[G.whoseTurn][j] = rand()%27;
				//increment treasures count
				if(G.hand[G.whoseTurn][j] == copper ||
				   G.hand[G.whoseTurn][j] == silver ||
				   G.hand[G.whoseTurn][j] == gold){
					checkTreasures_after++;
				}
			}
			if(checkTreasures_after - checkTreasures_before == 2){
				pass++;
			}
			else{
				fail++;
				//printf("got %d treasures after adventurer, expected %d\n", checkTreasures_after, checkTreasures_before+2);
			}
		}
		// 1 treasure
		else if (numTreasures == 1){
			if (G.handCount[G.whoseTurn] != cardcount){
				fail++;
				//printf("handcount: expected %d, got %d\n", cardcount, G.handCount[G.whoseTurn]);
			}
			else{
				pass++;
			}
		}
		// no treasure
		else{
			if (G.handCount[G.whoseTurn] != cardcount - 1){
				fail++;
				//printf("handcount: expected %d, got %d\n", cardcount-1, G.handCount[G.whoseTurn]);
			}
			else{
				pass++;
			}
		}


	}


	printf("RAND_ADVENTURER: PASS = %d\tFAIL = %d\tTOTAL POSSIBLE = %d\n", pass, fail, TESTS);
}

int main(){
	srand(time(NULL));
	random_test_card_adventurer();
	return 0;
}
