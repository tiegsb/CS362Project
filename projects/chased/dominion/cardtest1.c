/*
 * Title: cardtest1.c
 * Author: Dustin Chase
 * Email: chased@oregonstate.edu
 * Date: 10/25/2015
 * Description: Testing smithy card
 * Testing for: - current player should have 3 additional cards in hand after playing smithy card
 *              - current player should have no change in discard pile           
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
 
 void testSmithyCard() {
	srand(time(NULL));
	/*parameters for initializing a game to use for testing*/
	int seed = 999; 
	int numPlayers = 4;
	int player; //which player we are testing (could be 0, 1, 2, or 3)
	int cardCount = 5;
	int smithy_position; 
	/*loop counters*/
	int i; 
	int j; 
	
	/*error counts*/
	int error_counts[3];
	for (j = 0; j < 3; j++) {
		error_counts[j] = 0; 
	}
	
	struct gameState G; 
	struct gameState save; 
	
	int kingdom_cards[10] = {great_hall, baron, village, smithy, remodel, mine,
						  gardens, feast, council_room, adventurer};
						  
	printf("\nStarting to test Smithy card...\n");
	for (i = 0; i < 3000; i++) {
		initializeGame(numPlayers, kingdom_cards, seed, &G);
		
		/*randomly select a player and randomly select a position for the smithy card*/
		player = rand() % 4;
		smithy_position = rand() % 10; 
		
		/*ensure there is at least 1 smithy card in the player's hand*/
		G.hand[player][smithy_position] = smithy;
		
		/*update player's turn to the player we have randomly seleted*/
		G.whoseTurn = player; 
		
		memcpy(&save, &G, sizeof(struct gameState));
		
		playSmithy(&G, smithy_position);
		
		if (save.handCount[player] + 2 != G.handCount[player]) {
			error_counts[0]++;
		}
		if (save.discardCount[player] != G.discardCount[player]) {
			error_counts[1]++; 
		}
		
		int smithy_in_hand = 0; 
		for (j = 0; j < 10; j++) {
			if (G.hand[player][j] == smithy ) {
				smithy_in_hand = 1;
			}
		}
		if (smithy_in_hand) {
			error_counts[2]++; 
		}
		
	}
	printf("\nError type 0 is hand count incorrect.\n"); 
	printf("\nError type 1 is discard count incorrect.\n"); 
	printf("\nError type 2 is smithy is in hand but shouldn't be.\n");  
	
	for (j = 0; j < 3; j++) {
		printf("\nError count %d is: %d\n", j, error_counts[j]);
	}
	printf("\nTesting of smithy card complete.\n");
 }
 
 int main() {
	testSmithyCard(); 
	return 0;  
 }