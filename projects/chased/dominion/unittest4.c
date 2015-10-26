/*
 * Title: unittest4.c
 * Author: Dustin Chase
 * Email: chased@oregonstate.edu
 * Date: 10/25/2015
 * Description: Testing isGameOver function
 * Testing for: - Game should end when there are no province cards left, or when 3 of the other cards are gone
 *              - Test when province cards supply == 0
 *              - Test when any three cards supply == 0
 *              - Test when 0 cards supply == 0
 *              - Test when 1 cards supply == 0
 */

 #include "dominion.h"
 #include "dominion_helpers.h"
 #include <string.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <assert.h>
 #include "rngs.h"
 #include "interface.h"
 #include <time.h>
 
 void testGameOver() {
	srand(time(NULL));
	/*parameters for initializing a game to use for testing*/
	int seed = 999; 
	int numPlayers = 4;
	
	/*loop counters*/
	int i; 
	int j; 
	
	struct gameState G; 
	
	int kingdom_cards[10] = {great_hall, baron, village, smithy, remodel, mine,
						  gardens, feast, council_room, adventurer};
						  
	/*the number of unique cards in the game */
	const int NUM_CARDS = 27;
	int test_results[NUM_CARDS];
	for (i = 0; i < NUM_CARDS; i++) {
		test_results[i] = 0; 		
	}
	
	int num_tests_failed = 0; 
	
	printf("\nTesting isGameOver...\n");
	
	for (i = 0; i < 2000; i++) {
		initializeGame(numPlayers, kingdom_cards, seed, &G);
		
		/*variables to hold manual counts of cards*/
		int num_province_cards = 10; 
	    int num_zero_cards = 0; 
		
		/*holds randomly generated supply of cards*/
		int next_supply;
				
		/*set up random supply count*/
		for (j = 0; j < NUM_CARDS; j++) {
			next_supply = rand() % 10; 
			if (next_supply == 0) {
				num_zero_cards++; 
			}
			G.supplyCount[j] = next_supply;	
		}
		
		num_province_cards = G.supplyCount[province];
		
		int result = isGameOver(&G);
		int game_over_manual = 0; 
		/*holds manual determination of game over condition*/
		if (num_province_cards == 0) {
			game_over_manual = 1; 
		}
		if (num_zero_cards >= 3){
			game_over_manual = 1; 
		}
		if (result != game_over_manual) {
			num_tests_failed++;
			for (j = 0; j < NUM_CARDS; j++) {
				if (G.supplyCount[j] == 0) {
					test_results[j]++;
				}
			}
		}
	}
	
	printf("\nThe number of tests that failed was %d\n", num_tests_failed);
	printf("\nThe frequency of cards causing errors was: \n");
	for (i = 0; i < NUM_CARDS; i++) {
		if (test_results[i] > 0) {
				printf("\nCard number %d showed in error results %d times.\n", i, test_results[i]);
		}
		
	}
	printf("\nTesting of isGameOver is complete!\n");
 }
 
 int main () {
	 testGameOver();
	 return 0;
 }
	