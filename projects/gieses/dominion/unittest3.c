#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define NOISY_TEST 0

//test isGameOver function
int main(){
	int i;
	int numPlayers = 2;
	int seed = 1000;
	int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
	struct gameState G;
	
	printf("Testing isGameOver()\n");
	
	//check if all supplies full
	memset(&G, 23, sizeof(struct gameState));
	initializeGame(numPlayers, k, seed, &G);
	for (i = 0; i < treasure_map + 1; i++){
		G.supplyCount[i] = 3;
	}
	//game should not be over
	assert(isGameOver(&G) == 0);
	#if (NOISY_TEST == 1)
	printf("Passed!\n");
	#endif
	
	//check if province is 0, but there are other piles of cards are left
	memset(&G, 23, sizeof(struct gameState));
	initializeGame(numPlayers, k, seed, &G);
	G.supplyCount[3] = 0;
	//game should be over
	assert(isGameOver(&G) == 1);
	#if (NOISY_TEST == 1)
	printf("Passed!\n");
	#endif
	
	//check if province is not zero, and 1 supply empty
	memset(&G, 23, sizeof(struct gameState));
	initializeGame(numPlayers, k, seed, &G);
	G.supplyCount[3] = 3;
	//game should not be over
	assert(isGameOver(&G) == 0);
	#if (NOISY_TEST == 1)
	printf("Passed!\n");
	#endif
	
	//check if province is not zero, and 2 supplies empty
	memset(&G, 23, sizeof(struct gameState));
	initializeGame(numPlayers, k, seed, &G);
	G.supplyCount[3] = 3;
	//game should not be over
	assert(isGameOver(&G) == 0);
	#if (NOISY_TEST == 1)
	printf("Passed!\n");
	#endif
	
	//check if province is not 0, but all supplies are empty
	memset(&G, 23, sizeof(struct gameState));
	initializeGame(numPlayers, k, seed, &G);
	for (i = 0; i < treasure_map + 1; i++){
		G.supplyCount[i] = 0;
	}
	G.supplyCount[3] = 3;
	//game should be over
	assert(isGameOver(&G) == 1);
	#if (NOISY_TEST == 1)
	printf("Passed!\n");
	#endif
	
	//check if all supplies are empty
	memset(&G, 23, sizeof(struct gameState));
	initializeGame(numPlayers, k, seed, &G);
	for (i = 0; i < treasure_map + 1; i++){
		G.supplyCount[i] = 0;
	}
	//game should be over
	assert(isGameOver(&G) == 1);
	#if (NOISY_TEST == 1)
	printf("Passed!\n");
	#endif
	
	printf("All tests passed!\n");
	
	return 0;
}