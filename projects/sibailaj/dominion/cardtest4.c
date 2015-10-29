#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"

void testSteward();

int main(int argc, char *argv[])
{
	testSteward();
    return 0;
}

void testSteward() {
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int bonus;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
           sea_hag, tribute, smithy};
    struct gameState G;
	int z = 0;
	int originalCoinCount;
	int originalHandCount;
	int originalDeckCount;
	int originalDiscardCount;

	initializeGame(numPlayer, k, seed, &G);
	originalHandCount = G.handCount[0];
	originalDeckCount = G.deckCount[0];
	originalCoinCount = G.coins;
	originalDiscardCount = G.discardCount[0];

	//Choice 1
	stewardFunct(1, 0, &G, 0, 0, 0);
	assert(G.deckCount[0] == originalDeckCount - 2);
	assert(G.handCount[0] == originalHandCount + 2);

	//Choice 2
	stewardFunct(0, 0, &G, 1, 0, 0);
	assert(G.coins == originalCoinCount + 2);

	//Choice 3
	stewardFunct(0, 0, &G, 0, 0, 1);
	assert(G.discardCount[0] == originalDiscardCount + 2);

    printf("All tests passed!\n");
}


