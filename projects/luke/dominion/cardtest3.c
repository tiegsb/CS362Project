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

	printf("Test village card:\n");

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

	printf("************************************************************\n");

	printf("Test case: Make sure the right amount of actions are added:\n");

	printf("************************************************************\n");

	if(newActionCnt == (actions+2)) {
		printf("TEST PASSED.\n");
	} else {
		printf("TEST FAILED.\n");
	}

	// printf("newhandcnt: %d\n", newHandCount);
	// printf("handcnt: %d\n", handCount);

	printf("**************************************************************************\n");

	printf("Test case: Make sure an extra card is in hand after playing village card (old hand and new hand should be equal):\n");

	printf("**************************************************************************\n");

	if(newHandCount == handCount) {
		printf("TEST PASSED.\n");
	} else {
		printf("TEST FAILED:\n");
	    printf("Old hand count: %d\n", handCount);
	    printf("New hand count: %d\n", newHandCount);

	}

	
	return 0;

}