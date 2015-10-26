/*
 * Title: cardtest3.c
 * Author: Dustin Chase
 * Email: chased@oregonstate.edu
 * Date: 10/25/2015
 * Description: Testing council card
 * Testing for: - 
 *              - 
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
 
 void testCouncilRoom() {
	 srand(time(NULL));
	/*parameters for initializing a game to use for testing*/
	int seed = 999; 
	int numPlayers = 4;
	int player; //which player we are testing (could be 0, 1, 2, or 3)
	int cardCount = 5;
	int council_position; 
	/*loop counters*/
	int i; 
	int j; 
	
	/*variables to save errors (if any)*/
	int player_hand_errors = 0; 
	int player_buy_errors = 0; 
	int opponent_hand_error = 0;  
	
	/*gamestate and place to save original gamestate*/ 
	struct gameState G; 
	
	int kingdom_cards[10] = {great_hall, baron, village, smithy, remodel, mine,
						  gardens, feast, council_room, adventurer};
	 
	printf("\nStarting to test council card...\n");
	for (i = 0; i < 4; i++) {
		initializeGame(numPlayers, kingdom_cards, seed, &G);
		
		/*randomly select a player and randomly select a position for the council card*/
		player = 3;
		council_position = rand() % 10; 
		
		G.whoseTurn = player; 
		
	    G.numBuys = 0; 
		G.handCount[0] = 0;
		G.handCount[1] = 0;
		G.handCount[2] = 0;
		G.handCount[3] = 1; 
		G.numBuys = 0; 
		G.hand[player][council_position] = council_room; 
		
		playCouncilRoom(&G, council_position);
		
		if (G.handCount[player] != 4) {
			player_hand_errors++; 
		}
		if (G.numBuys != 1) {
			player_buy_errors++; 
		}
		if (G.handCount[0] != 1 && G.handCount[1] != 1 && G.handCount[2] != 1) {
			opponent_hand_error++; 
		}
	}
	printf("\nThe number of errors found is: \n");
	printf("\nPlayer hand errors: %d\n", player_hand_errors);
	printf("\nPlayer buy errors: %d\n", player_buy_errors);
	printf("\nopponent_hand_errors : %d\n", opponent_hand_error);
	
	printf("\nTesting of Council Room complete!\n");
 }
 
 
 int main() {
	 
	testCouncilRoom(); 
	return 0; 
 }