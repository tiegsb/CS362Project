//Test the village card
//Will test to see that the card gives +1 card and +2 actions

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>

int main() {

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

	//before village card call

	int actions=G.numActions;
	int handCount=G.handCount[player1];
	int newActionCnt;
	int newHandCount;

	villageCard(player1, 0, &G);

	newActionCnt=G.numActions;
	newHandCount=G.handCount[player1];

	if(newActionCnt == (actions+2)) {
		printf("TEST 1 PASSED.\n");
	} else {
		printf("TEST 1 FAILED.\n");
	}

	printf("newhandcnt: %d\n", newHandCount);
	printf("handcnt: %d\n", handCount);

	if(newHandCount == handCount) {
		printf("TEST 2 PASSED.\n");
	} else {
		printf("TEST 2 FAILED.\n");
	}

}