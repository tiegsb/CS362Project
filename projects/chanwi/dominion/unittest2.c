/* Unit Test 2 - updateCoins()

*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"

void updateCoinsTest()
{
	int seed = 1000;
	int numPlayer = 2;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState G;
	int handCount = 5;
	int cardsInHand[handCount];
	int bonus;
	int player = 0;

	printf ("UNIT TESTS for updateCoins()\n");
	
	initializeGame(numPlayer, k, seed, &G);
	G.handCount[player] = handCount;
	
	printf ("Hand: Copper, Silver, Gold, village, gardens & Bonus: 0\n");
	cardsInHand[0] = copper;
    cardsInHand[1] = silver;
	cardsInHand[2] = gold;
	cardsInHand[3] = village;
	cardsInHand[4] = gardens;
	bonus = 0;
	
	memcpy(G.hand[player], cardsInHand, sizeof(int) * handCount);
	updateCoins(player, &G, bonus);
	
	if (G.coins == 6){
		printf ("PASSED - Coin Total equals 6\n");
	} else {
		printf ("FAILED - Coin Total equals %d\n", G.coins);
	}
	
	printf ("Hand: Copper, Silver, adventurer, village, gardens & Bonus: 1\n");
	cardsInHand[0] = copper;
    cardsInHand[1] = silver;
	cardsInHand[2] = adventurer;
	cardsInHand[3] = village;
	cardsInHand[4] = gardens;
	bonus = 1;
	
	memcpy(G.hand[player], cardsInHand, sizeof(int) * handCount);
	updateCoins(player, &G, bonus);
	
	if (G.coins == 4){
		printf ("PASSED - Coin Total equals 4\n");
	} else {
		printf ("FAILED - Coin Total equals %d\n", G.coins);
	}	
	
	printf ("Hand: adventurer, council_room, mine, village, gardens & Bonus: 3\n");
	cardsInHand[0] = adventurer;
    cardsInHand[1] = council_room;
	cardsInHand[2] = mine;
	cardsInHand[3] = village;
	cardsInHand[4] = gardens;
	bonus = 3;
	
	memcpy(G.hand[player], cardsInHand, sizeof(int) * handCount);
	updateCoins(player, &G, bonus);
	
	if (G.coins == 3){
		printf ("PASSED - Coin Total equals 3\n");
	} else {
		printf ("FAILED - Coin Total equals %d\n", G.coins);
	}
	
	printf ("Hand: adventurer, council_room, mine, village, gardens & Bonus: 0\n");
	cardsInHand[0] = adventurer;
    cardsInHand[1] = council_room;
	cardsInHand[2] = mine;
	cardsInHand[3] = village;
	cardsInHand[4] = gardens;
	bonus = 0;
	
	memcpy(G.hand[player], cardsInHand, sizeof(int) * handCount);
	updateCoins(player, &G, bonus);
	
	if (G.coins == 0){
		printf ("PASSED - Coin Total equals 0\n");
	} else {
		printf ("FAILED - Coin Total equals %d\n", G.coins);
	}
}

int main(){
	updateCoinsTest();
	return 0;
}