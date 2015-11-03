/*
 * Title: randomtestadventurer.c
 * Author: Dustin Chase
 * Email: chased@oregonstate.edu
 * Date: 11/8/2015
 * Description: Testing adventurer card 
 *              - does player have 2 treasure cards in hand? 
 *              - is adventurer card in played pile? 
 *              - is adventurer card removed from hand? 
 *             
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
 
 void testAdventurer() {
	srand(time(NULL));
	/*parameters for initializing a game to use for testing*/
	int seed = 999; 
	int numPlayers = 4;
	int player = 0; //which player we are testing (could be 0, 1, 2, or 3)
	
	/*loop counters*/
	int i; 
	int j; 
	
	/*error counters*/ 
	int treasure_count_error = 0; 
	int hand_count_error = 0; 
	struct gameState G;
	int copper_count = 0; 
	int silver_count = 0; 
	int gold_count = 0; 
	
	int kingdom_cards[10] = {great_hall, baron, village, smithy, remodel, mine,
						  gardens, feast, council_room, adventurer};
						  
	printf("\nStarting to test Adventurer card...\n");
	for (i = 0; i < 10; i++) {
		initializeGame(numPlayers, kingdom_cards, seed, &G);
		G.whoseTurn = player;
		G.handCount[player] = 1;
		G.hand[player][0] = adventurer;
		/*Generate random deck. First 20 cards will be treasure cards */ 
		int random_deck[50]; 
		int random; 
		for (j = 0; j < 20; j++) {
			random = (rand() % (7 - 4)) + 4;
			random_deck[j] = random; 
		}
		
		for (  ; j < 50; j++) {
			random = rand() % 27;
			random_deck[j] = random; 
		}
		
		for (j = 0; j < 50; j++) {
			G.deck[player][j] = random_deck[j];
		}
		G.deckCount[player] = 50; 
		
		playAdventurer(&G);
		
		/*check total cards in hand*/ 
		if (G.handCount[player] != 2) {
			hand_count_error++;
		}
		
		/*check treasure count in hand*/ 
		int treasure_count = 0; 
		for (j = 0; j < G.handCount[player]; j++) {
			if (G.hand[player][j] == copper || G.hand[player][j] == silver || G.hand[player][j] == gold) {
				treasure_count++; 
			}
		}
		
		/*check which treasure cards were picked up*/ 
		for (j = 0; j < G.handCount[player]; j++) {
			if (G.hand[player][j] == copper) {
				copper_count++; 
			}
			if (G.hand[player][j] == silver) {
				silver_count++; 
			}
			if (G.hand[player][j] == gold) {
				gold_count++; 
			}
		}
		if (treasure_count != 2) {
			printf("\nThe treasure count is: %d\n", treasure_count);
			for (j = 0; j < G.handCount[player]; j++) {
				printf("\nCard %d is %d.\n", j, G.hand[player][j]);
			}
			treasure_count_error++; 
		}
		if (G.hand[player][0] == adventurer) {
			printf("\nAdventurer card was not discarded - FAIL.\n");
		}
		
		
    }
	printf("\nNow printing testing errors...\n"); 
	printf("\nThe number of treasure count errors was: %d\n", treasure_count_error);
	printf("\nThe number of hand count errors was: %d\n", hand_count_error);
	
	printf("\nNow printing counts of cards picked up:\n");
	printf("\nThe count of copper cards picked up is: %d\n", copper_count);
	printf("\nThe count of silver cards picked up is: %d\n", silver_count);
	printf("\nThe count of gold cards picked is: %d\n", gold_count);

 }
 
 int main() {
	 testAdventurer();
	 return 0; 
 }