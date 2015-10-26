/*
 * Title: cardtest1.c
 * Author: Dustin Chase
 * Email: chased@oregonstate.edu
 * Date: 10/25/2015
 * Description: Testing remodel card
 * Testing for: - selected card should be placed in the trash
 *              - a card should be gained which costs up to two more than the card that was trashed
 *				- Note that the condition about the relative card costs is tested in cardeffect so it 
 *				  does not need to be tested here. 
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
 
 void testRemodel() {
	 printf("\nTesting remodel card...\n");
	 srand(time(NULL));
	/*parameters for initializing a game to use for testing*/
	int seed = 999; 
	int numPlayers = 4;
	int player; //which player we are testing (could be 0, 1, 2, or 3)
	int remodel_position;
	int trash_position; 
	int gain_choice; 
	/*loop counters*/
	int i; 
	int j; 
	int errors = 0; 
	
	struct gameState G; 
	struct gameState save; 
	int kingdom_cards[10] = {great_hall, baron, village, smithy, remodel, mine,
						  gardens, feast, council_room, adventurer};
	for (i = 0; i < 3000; i++) {
		initializeGame(numPlayers, kingdom_cards, seed, &G);
		
		remodel_position = rand() % 10; 
		player = rand() % 4; 
		
		trash_position = rand() % 10; 
		gain_choice = rand() % 27; 
		while (remodel_position == trash_position) {
			trash_position = rand() % 10; 
		}
		
		/*ensure there is at least 1 remodel card in the player's hand*/
		G.hand[player][remodel_position] = remodel;
		
		/*update player's turn to the player we have randomly seleted*/
		G.whoseTurn = player; 
		
		memcpy(&save, &G, sizeof(struct gameState));
		
		//function signature: playRemodel(struct gameState, int choice1, int choice2, int handPos);
		playRemodel(&G, trash_position, gain_choice, remodel_position);
		
		/*Check if remodel card has been removed from hand*/
		if (G.hand[player][remodel_position] == remodel) {
			printf("\nRemodel card was not removed!\n");
		}
		
		/*Check if card that was selected to gain is now in played*/
		int test = 0; 
		for (j = 0; j < G.playedCardCount; j++) {
			if (G.playedCards[j] == gain_choice) {
				test = 1; 
				break; 
			}
		}
		if (test == 0) {
			errors++; 
		}
		
		/*Check if remodel card is in played pile*/ 
		test = 0; 
		for (j = 0; j < G.playedCardCount; j++) {
			if (G.playedCards[j] == remodel) {
				test = 1; 
				break; 
			}
		}
		if (test == 0) {
			errors++; 
		}
		errors = 0; 
		
	}
	
	printf("\nNumbers of errors found is %d\n", errors); 
	printf("\nTesting remodel card complete!\n");
	 
 }
 
 int main () {
	 
	 testRemodel();
	 return 0; 
 }
 