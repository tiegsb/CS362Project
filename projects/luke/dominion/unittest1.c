//This unit test will test the updateCoins() function with different combination of cards
//in hand.

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>

void testCoinFunction(int hand[], int bonus, int handCount, int expectedResult);

int main() {

	printf("Test updateCoins() function:\n");

	int hand1[5];
	int hand2[6];
	int hand3[7];
	int hand4[8];
	int hand5[9];

	//setup hands

	//firsthand will have no coins
	hand1[0] = 0;
	hand1[1] = 0;
	hand1[2] = 0;
	hand1[3] = 0;
	hand1[4] = 0;
	//result should be 0

	//second hand will have 6 cards including one silver, one copper coin
	hand2[0] = 0;
	hand2[1] = silver;
	hand2[2] = 0;
	hand2[3] = 0;
	hand2[4] = copper;
	hand2[5] = 0;
	//result should be 3

	//second hand will have 7 cards including 1 silver, 1 copper, and 1 gold coins
	hand3[0] = silver;
	hand3[1] = 0;
	hand3[2] = 0;
	hand3[3] = copper;
	hand3[4] = 0;
	hand3[5] = 0;
	hand3[6] = gold;
	//result should be 6

	//second hand will have 8 cards including 2 silver, 1 copper, and 2 gold coins
	//+ 2 bonus
	hand4[0] = gold;
	hand4[1] = silver;
	hand4[2] = 0;
	hand4[3] = 0;
	hand4[4] = silver;
	hand4[5] = 0;
	hand4[6] = gold;
	hand4[7] = copper;
	//result should be 13

	//second hand will have 9 cards containing 3 silver, 3 copper, and 3 gold coins
	//+2 bonus
	hand5[0] = silver;
	hand5[1] = copper;
	hand5[2] = gold;
	hand5[3] = silver;
	hand5[4] = copper;
	hand5[5] = gold;
	hand5[6] = copper;
	hand5[7] = gold;
	hand5[8] = silver;
	//result should be 20

	//Pass in hands and run tests in testCoinFunction(hand[], bonus, handCount, expectedResult)
	printf("Test 1 starting:\n");
	testCoinFunction(hand1, 0, 5, 0);

	printf("Test 2 starting:\n");
	testCoinFunction(hand2, 0, 6, 3);

	printf("Test 3 starting:\n");
	testCoinFunction(hand3, 0, 7, 6);

	printf("Test 4 starting:\n");
	testCoinFunction(hand4, 2, 8, 13);

	printf("Test 5 starting:\n");
	testCoinFunction(hand5, 2, 9, 20);

		
	return 0;

}

void testCoinFunction(int hand[], int bonus, int handCount, int expectedResult) {
	
	srand(time(NULL));
	int numberPlayer = 2;
	int player1 = 0;
	int randomSeed = rand() % 1000 + 1;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
				 remodel, smithy, village, baron, great_hall};
	struct gameState G;

	//Clear the game state
	memset(&G, 23, sizeof(struct gameState));

	//initialize game
	initializeGame(numberPlayer, k, randomSeed, &G);

	//Set hand count in gamestate to our handCount
	G.handCount[player1] = handCount;

	//set gamestate cards to passed in hand
	memcpy(G.hand[player1], hand, sizeof(int)*handCount);

	updateCoins(player1, &G, bonus);

	//check coins in gamestate vs expected coins


	if(G.coins == expectedResult) {
		printf("TEST PASSED:\n");
		printf("Player's Coins: %d\n", G.coins);
		printf("Expected Result of Coins: %d\n", expectedResult);
	} else {
		printf("TEST FAILED:\n");
		printf("Player's Coins: %d\n", G.coins);
		printf("Expected Result of Coins: %d\n", expectedResult);
	}


}