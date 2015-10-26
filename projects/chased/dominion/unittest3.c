/*
 * Title: unittest3.c
 * Author: Dustin Chase
 * Email: chased@oregonstate.edu
 * Date: 10/25/2015
 * Description: Testing function buyCard()
 * Testing for: - if there are no buys left, the function should not allow the buy to happen
 *				- if there are none of the particular card left, the function should not allow the buy to happen
 *				- if the player does not have enough of the coins left, the function should not allow the buy to happen
 *				- if the player has enough coins and the card supply is sufficient, the card should be "gained", which in the Dominion rules means
 *				  taking a card from somewhere (usually the Supply) and placing it in your discard pile. The card would have to instruct you to place it somewhere else
 */

 #include "dominion.h"
 #include "dominion_helpers.h"
 #include <string.h>
 #include <stdio.h>
 #include "rngs.h"
 #include "interface.h"
 
 void testBuyCard() {
	/*parameters for initializing a game to use for testing*/
	int seed = 999; 
	int numPlayers = 2;
	int player = 1; //which player we are testing (could be 0 or 1)
	int cardCount = 5; 
	 
	int kingdom_cards[10] = {great_hall, baron, village, smithy, remodel, mine,
						  gardens, feast, council_room, adventurer};
						  
	int player_hand[cardCount];
	player_hand[0] = smithy;
	player_hand[1] = gold;
	player_hand[2] = village;
	player_hand[3] = silver;
	player_hand[4] = copper; 
	
	struct gameState G; 
	printf("\nTesting buyCard():\n");
	 
	initializeGame(numPlayers, kingdom_cards, seed, &G);
	
	/*test error conditions*/
	G.numBuys = -1;
	G.supplyCount[1] = 100;
	G.coins = 100;	
	int result = buyCard(1, &G);
	if (result < 0) {
		printf("\nTest with no buys left passed!\n");
	}
	else {
		printf("\nTest with no buys left failed!\n"); 
	}
	
	G.numBuys = 10; 
	G.supplyCount[1] = 100;
	G.coins = 100; 
	result = buyCard(1, &G);
	if (result == 0) {
		printf("\nTest with buys left passed!\n");
	}
	else {
		printf("\nTest with buys left failed!\n"); 
	}
	
	G.supplyCount[1] = 0; 
	result = buyCard(1, &G);
	if (result < 0) {
		printf("\nTest with not enough supply left passed!\n");
	}
	else {
		printf("\nTest with not enough supply left failed!\n");
	}
	
	G.supplyCount[1] = 100; 
	result = buyCard(1, &G);
	if (result == 0) {
		printf("\nTest with enough supply left passed!\n");
	}
	else {
		printf("\nTest with enough supply left failed!\n");
	}
	
	//reset game state to normal state before continuing to test
	initializeGame(numPlayers, kingdom_cards, seed, &G);
	
	struct gameState save; 
	memcpy(&save, &G, sizeof(struct gameState));
	
	/*test that game state is updated correctly*/
	buyCard(1, &G); 
	if (save.coins - getCost(1) == G.coins)  {
		printf("\nBuy card number of coins left passed!\n");
	}
	else {
		printf("\nBuy card with number of coins left failed!\n");
	}

	if (--save.numBuys == G.numBuys)  {
		printf("\nBuy card number of buys left passed!\n");
	}
	else {
		printf("\nBuy card with number of buys left failed!\n");
	}
	
	if (--save.supplyCount[1] == G.supplyCount[1]) {
		printf("\nSupply passed!\n");
	}
	else {
		printf("\nSupply failed!\n");
	}
	
	if (++save.discardCount[0] == G.discardCount[0]) {
		printf("\nDiscard passed!\n");
	}
	else {
		printf("\nDiscard failed\n");
	}
	
 } 
 int main() {
	 testBuyCard();
	 return 0; 
 }