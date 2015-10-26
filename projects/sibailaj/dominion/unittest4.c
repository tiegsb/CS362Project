#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"

void testScore();

int main(int argc, char *argv[])
{
	testScore();
    return 0;
}

void testScore() {
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int bonus;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
           sea_hag, tribute, smithy};
    struct gameState G;
	int fullDeckCountScore;
		
	initializeGame(numPlayer, k, seed, &G);

	//Test Score
	G.handCount[0] = 3;
	G.hand[0][0] = province; //6 points
	G.hand[0][1] = duchy; //3 points
	G.hand[0][2] = estate; //1 point
	G.discardCount[0] = 3;
	G.discard[0][0] = great_hall; //1 point
	G.discard[0][1] = gardens; //fullDeckCount(player, 0, state) / 10 
	G.discard[0][2] = curse; //-1 point
	G.deck[0][0] = duchy; //3 points
	G.deck[0][1] = estate; //1 point
	G.deck[0][2] = great_hall; //1 point

	fullDeckCountScore = fullDeckCount(0, 0, &G)/10;

	assert(scoreFor(0, &G) == (6 + 3 + 1 + 1 - 1 + 3 + 1 + 1 + fullDeckCountScore));

    printf("All tests passed!\n");
}