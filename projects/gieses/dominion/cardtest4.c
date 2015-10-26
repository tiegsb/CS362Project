#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define NOISY_TEST 0

//test village function
int main(){
	int i;
	int numPlayers = 2;
	int p = 0;
	int seed = 1000;
	int k[10] = {adventurer, council_room, feast, gardens, mine
	           , remodel, smithy, village, baron, great_hall};
	struct gameState G;
	
	printf("Testing village card()\n");
	
	memset(&G, 23, sizeof(struct gameState));
	initializeGame(numPlayers, k, seed, &G);
	
	G.discardCount[p] = 5;
	G.handCount[p] = 5;
	G.hand[p][0] = smithy;
	G.hand[p][1] = great_hall;
	G.hand[p][2] = adventurer;
	G.hand[p][3] = village;
	G.hand[p][4] = silver;
	
	int preHand = G.handCount[p];
	int preDiscard = G.discardCount[p];
	int preActions = G.numActions;
	
	#if (NOISY_TEST == 1)
	printf("Pre player hand count: %d\n", preHand);
	printf("Pre player discard count: %d\n", preDiscard);
	printf("Pre player action count: %d\n", preActions);
	#endif
	
	villageCard(&G, 3);
	
	#if (NOISY_TEST == 1)
	printf("Post player hand count: %d\n", G.handCount[p]);
	printf("Post player discard count: %d\n", G.discardCount[p]);
	printf("Post player action count: %d\n", G.numActions);
	#endif
	
	if(preHand < G.handCount[p]){
		#if (NOISY_TEST == 1)
		printf("Test passed!\n");
		#endif
	}else{
		#if (NOISY_TEST == 1)
		printf("Test failed!\n");
		#endif
	}
	
	if(preDiscard < G.discardCount[p]){
		#if (NOISY_TEST == 1)
		printf("Test passed!\n");
		#endif
	}else{
		#if (NOISY_TEST == 1)
		printf("Test failed!\n");
		#endif
	}
	
	if(preActions < G.numActions){
		#if (NOISY_TEST == 1)
		printf("Test passed!\n");
		#endif
	}else{
		#if (NOISY_TEST == 1)
		printf("Test failed!\n");
		#endif
	}
	
	return 0;
}