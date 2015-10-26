#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"

void testGreatHall();

int main(int argc, char *argv[])
{
	testGreatHall();
    return 0;
}

void testGreatHall() {
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
	int originalActionCount;
	int originalHandCount;
	int originalScore;
	int originalDeckCount;

	initializeGame(numPlayer, k, seed, &G);
	originalActionCount = G.numActions;
	originalHandCount = G.handCount[0];
	originalScore = scoreFor(0, &G);
	originalDeckCount = G.deckCount[0];

	greathallFunct(0, &G, 0);

	//Verify 1 Victory Point
	assert(scoreFor(0, &G) == originalScore + 1);

	//Verify 1 Card is drawn
	assert(G.deckCount[0] == originalDeckCount - 1);
	assert(G.handCount[0] == originalHandCount + 1);

	//Verify 1 Additional Action
	assert(G.numActions == originalActionCount + 1);

    printf("All tests passed!\n");
}


