#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"

void testAdventurer();

int main(int argc, char *argv[])
{
	testAdventurer();
    return 0;
}

void testAdventurer() {
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int bonus;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
           sea_hag, tribute, smithy};
    struct gameState G;
	int drawntreasure = 0;
	int cardDrawn = 0;
	int temphand[MAX_HAND];
	int z = 0;
	int originalDeckCount;
	int originalDiscardCount;

	initializeGame(numPlayer, k, seed, &G);

	//Verify Copper
	for (i = 0; i < MAX_HAND; i++) {
		G.deck[0][i] = copper;
    }
	
	originalDeckCount = G.deckCount[0];
	originalDiscardCount = G.discardCount[0];

	adventurerFunct(drawntreasure, &G, 0, cardDrawn, temphand, z);
	assert(G.deckCount[0] == originalDeckCount - 2);
	assert(G.discardCount[0] == originalDiscardCount);

	//Verify Silver
	for (i = 0; i < MAX_HAND; i++) {
		G.deck[0][i] = silver;
    }
	
	originalDeckCount = G.deckCount[0];
	originalDiscardCount = G.discardCount[0];

	adventurerFunct(drawntreasure, &G, 0, cardDrawn, temphand, z);
	assert(G.deckCount[0] == originalDeckCount - 2);
	assert(G.discardCount[0] == originalDiscardCount);

	//Verify Gold
	for (i = 0; i < MAX_HAND; i++) {
		G.deck[0][i] = gold;
    }
	
	originalDeckCount = G.deckCount[0];
	originalDiscardCount = G.discardCount[0];

	adventurerFunct(drawntreasure, &G, 0, cardDrawn, temphand, z);
	assert(G.deckCount[0] == originalDeckCount - 2);
	assert(G.discardCount[0] == originalDiscardCount);

    printf("All tests passed!\n");
}
