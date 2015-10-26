/*
 * Title: unittest1.c
 * Author: Dustin Chase
 * Email: chased@oregonstate.edu
 * Date: 10/25/2015
 * Description: Testing function updateCoins()
 * Testing for: - The number of coins should be updated correctly
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
 
 void testUpdateCoins() {
	srand(time(NULL));
	/*parameters for initializing a game to use for testing*/
	
	int seed = 999; 
	int numPlayers = 4;
	int player = 0; //which player we are testing (could be 0, 1, 2, or 3)
	int cardCount = 5; 
	 
	struct gameState G; 
	
	int kingdom_cards[10] = {great_hall, baron, village, smithy, remodel, mine,
						  gardens, feast, council_room, adventurer};
						  
	initializeGame(numPlayers, kingdom_cards, seed, &G);
	int player_hand[cardCount]; 
	int i;
	int j;
	int k; 
	printf("\nTesting updateCoins()...\n");
	for (k = 0; k < 1000; k++) {
		int total = 0;  
		for (i = 0; i < cardCount; i++) {
			j = rand() % 27;
			if (j == 4)
				total += 1;
			else if (j == 5)
				total += 2; 
			else if (j == 6)
				total += 3;
			else
				total += 0; 
			player_hand[i] = j;  
		}
		
		int the_bonus = rand() % 2 == 0 ? 0 : 1; 
		total += the_bonus; 
		for (i = 0; i < cardCount; i++) {
			G.hand[player][i] = player_hand[i];
		}	
		G.handCount[player] = cardCount; 
		updateCoins(player, &G, the_bonus); 
		
		assert(G.coins == total);
	}
	printf("All tests pass!");
 }
 
 int main() {
	testUpdateCoins();
	return 0; 
 }