#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"

void testUpdateCoins();

int main(int argc, char *argv[])
{
	testUpdateCoins();
    return 0;
}

void testUpdateCoins() {
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int bonus;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
           sea_hag, tribute, smithy};
    struct gameState G;
	int updateCoinsResult;
		
	initializeGame(numPlayer, k, seed, &G);

	//Test Copper Cards
	G.handCount[0] = 5; //Set hand count to 5
	G.hand[0][0] = copper;
	G.hand[0][1] = copper;
	G.hand[0][2] = copper;
	G.hand[0][3] = copper;
	G.hand[0][4] = copper;
	bonus = 2;
	updateCoinsResult = updateCoins(0, &G, bonus);
	assert(G.coins == 7);

	//Test Silver Cards
	G.handCount[0] = 5; //Set hand count to 5
	G.hand[0][0] = silver;
	G.hand[0][1] = silver;
	G.hand[0][2] = silver;
	G.hand[0][3] = silver;
	G.hand[0][4] = silver;
	bonus = 2;
	updateCoinsResult = updateCoins(0, &G, bonus);
	assert(G.coins == 12);

	//Test Gold Cards
	G.handCount[0] = 5; //Set hand count to 5
	G.hand[0][0] = gold;
	G.hand[0][1] = gold;
	G.hand[0][2] = gold;
	G.hand[0][3] = gold;
	G.hand[0][4] = gold;
	bonus = 2;
	updateCoinsResult = updateCoins(0, &G, bonus);
	assert(G.coins == 17);

    printf("All tests passed!\n");
}
