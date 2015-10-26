#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define NOISY_TEST 0

//test adventurer function
int main(){
	int i;
	int numPlayers = 2;
	int p = 0;
	int seed = 1000;
	int k[10] = {adventurer, council_room, feast, gardens, mine
	           , remodel, smithy, village, baron, great_hall};
	struct gameState G;
	
	printf("Testing adventurerCard()\n");
	
	memset(&G, 23, sizeof(struct gameState));
	initializeGame(numPlayers, k, seed, &G);
	
	G.discardCount[p] = 5;
	G.handCount[p] = 5;
	G.hand[p][0] = smithy;
	G.hand[p][1] = great_hall;
	G.hand[p][2] = adventurer;
	G.hand[p][3] = gold;
	G.hand[p][4] = silver;
	
	G.deck[p][0] = smithy;
	G.deck[p][1] = gold;
	G.deck[p][2] = estate;
	G.deck[p][3] = silver;
	G.deck[p][4] = adventurer;
	
	#if (NOISY_TEST == 1)
	printf("Pre player hand count: %d\n", G.handCount[p]);
	printf("Pre player discard count: %d\n", G.discardCount[p]);
	printf("Pre deck count: %d\n", G.deckCount[p]);
	#endif
	
	adventurerCard(&G);
	
	#if (NOISY_TEST == 1)
	printf("Post player hand count: %d\n", G.handCount[p]);
	printf("Post player discard count: %d\n", G.discardCount[p]);
	printf("Post deck count: %d\n", G.deckCount[p]);
	#endif
	
	if(G.hand[p][G.handCount[p - 1]] == silver){
		#if (NOISY_TEST == 1)
		printf("Test passed!\n");
		#endif
	}else{
		#if (NOISY_TEST == 1)
		printf("Test failed!\n");
		#endif
	}
	if(G.hand[p][G.handCount[p - 2]] == gold){
		#if (NOISY_TEST == 1)
		printf("Test passed!\n");
		#endif
	}else{
		#if (NOISY_TEST == 1)
		printf("Test failed!\n");
		#endif
	}

	
	printf("All tests passed!\n");
	
	return 0;
}