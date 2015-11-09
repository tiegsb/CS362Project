#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>

//set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main(){
	srand(time(NULL));
	int gameSeed = rand() % 1000 + 1;
	int p = 0; //player 1
	int numPlayer = 2;
	int handCount = 5;
	int status;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
				 remodel, smithy, village, baron, great_hall};

	int testHand[5] = {copper, copper, silver, silver, gold};

	struct gameState G;

	/*Clear the game state*/
	memset(&G, 23, sizeof(struct gameState));

	/*Initialize the game*/
	initializeGame(numPlayer, k, gameSeed, &G);

	/*Set cards to testHand*/
	memcpy(G.hand[p], testHand, sizeof(int)*handCount);


	/******** Test 1 ********/
#if (NOISY_TEST == 1)
	printf("Test #1, Province supply empty\n");
#endif

	G.supplyCount[province] = 0;
	status = isGameOver(&G);

#if (NOISY_TEST == 1)
	printf( "Expected game state=%d, Actual game state=%d \n", 1, isGameOver(&G));
	
	if(status == 1){
		printf( "Test #1 PASSED, Game is over\n\n");
	} else {
		printf( "Test #1 FAILED\n\n");
	}
#endif

	/******** Test 2 ********/
#if (NOISY_TEST == 1)
	printf("Test #2, One supply pile empty\n");
#endif

	G.supplyCount[copper] = 0;
	status = isGameOver(&G);

#if (NOISY_TEST == 1)
	printf( "Expected game state=%d, Actual game state=%d \n", 0, isGameOver(&G));
	if(status == 1) {
		printf( "Test #2 PASSED, Game continues\n\n");
	} else {
		printf( "Test #2 FAILED\n\n");
	}
#endif

	return 0;
}