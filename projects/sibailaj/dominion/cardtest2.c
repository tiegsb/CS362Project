#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"

void testSmithy();

int main(int argc, char *argv[])
{
	testSmithy();
    return 0;
}

void testSmithy() {
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
	int originalHandCount;

	initializeGame(numPlayer, k, seed, &G);
	originalDeckCount = G.deckCount[0];
	originalHandCount = G.handCount[0];

	smithyFunct(0, 0, &G);
	//Verify 3 Cards are Drawn
	assert(G.deckCount[0] == originalDeckCount - 3);
	assert(G.handCount[0] == originalHandCount + 3);


    printf("All tests passed!\n");
}


