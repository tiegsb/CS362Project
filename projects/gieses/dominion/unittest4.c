#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define NOISY_TEST 0

//test gainCard function
int main(){
	int i;
	int numPlayers = 2;
	int p = 0;
	int seed = 1000;
	int k[10] = {adventurer, council_room, feast, gardens, mine
	           , remodel, smithy, village, baron, great_hall};
	struct gameState G;
	
	printf("Testing gainCard()\n");
	
	memset(&G, 23, sizeof(struct gameState));
	initializeGame(numPlayers, k, seed, &G);
	
	G.discardCount[p] = 7;
	G.deckCount[p] = 3;
	G.handCount[p] = 5;
	
	//check when the card chosen is empty
	G.supplyCount[0] = 0;
	#if (NOISY_TEST == 1)
	printf("Pre Discard: %d\n", G.discardCount[p]);
	printf("Pre Deck: %d\n", G.deckCount[p]);
	printf("Pre Hand: %d\n", G.handCount[p]);
	printf("Pre card count:%d\n", G.supplyCount[0]);
	#endif
	assert(gainCard(0, &G, 0, 0) == -1);
	assert(gainCard(0, &G, 1, 0) == -1);
	assert(gainCard(0, &G, 2, 0) == -1);
	#if (NOISY_TEST == 1)
	printf("Post Discard: %d\n", G.discardCount[p]);
	printf("Post Deck: %d\n", G.deckCount[p]);
	printf("Post Hand: %d\n", G.handCount[p]);
	printf("Post card count:%d\n", G.supplyCount[0]);
	#endif
	
	//reset
	G.deckCount[p] = 3;
	G.handCount[p] = 5;
	G.discardCount[p] = 7;
	
	//check discard when the card chosen is not empty
	G.supplyCount[0] = 6;
	#if (NOISY_TEST == 1)
	printf("Pre Discard: %d\n", G.discardCount[p]);
	printf("Pre Deck: %d\n", G.deckCount[p]);
	printf("Pre Hand: %d\n", G.handCount[p]);
	printf("Pre card count:%d\n", G.supplyCount[0]);
	#endif
	assert(gainCard(0, &G, 0, 0) == 0);
	#if (NOISY_TEST == 1)
	printf("Post Discard: %d\n", G.discardCount[p]);
	printf("Post Deck: %d\n", G.deckCount[p]);
	printf("Post Hand: %d\n", G.handCount[p]);
	printf("Post card count:%d\n", G.supplyCount[0]);
	#endif
	
	//check deck when the card chosen is not empty
	#if (NOISY_TEST == 1)
	printf("Pre Discard: %d\n", G.discardCount[p]);
	printf("Pre Deck: %d\n", G.deckCount[p]);
	printf("Pre Hand: %d\n", G.handCount[p]);
	printf("Pre card count:%d\n", G.supplyCount[0]);
	#endif
	assert(gainCard(0, &G, 1, 0) == 0);
	#if (NOISY_TEST == 1)
	printf("Post Discard: %d\n", G.discardCount[p]);
	printf("Post Deck: %d\n", G.deckCount[p]);
	printf("Post Hand: %d\n", G.handCount[p]);
	printf("Post card count:%d\n", G.supplyCount[0]);
	#endif
	
	//check hand when the card chosen is not empty
	#if (NOISY_TEST == 1)
	printf("Pre Discard: %d\n", G.discardCount[p]);
	printf("Pre Deck: %d\n", G.deckCount[p]);
	printf("Pre Hand: %d\n", G.handCount[p]);
	printf("Pre card count:%d\n", G.supplyCount[0]);
	#endif
	assert(gainCard(0, &G, 2, 0) == 0);
	#if (NOISY_TEST == 1)
	printf("Post Discard: %d\n", G.discardCount[p]);
	printf("Post Deck: %d\n", G.deckCount[p]);
	printf("Post Hand: %d\n", G.handCount[p]);
	printf("Post card count:%d\n", G.supplyCount[0]);
	#endif
	
	//check when the flag value is negative, should add to discard pile
	#if (NOISY_TEST == 1)
	printf("Pre Discard: %d\n", G.discardCount[p]);
	printf("Pre Deck: %d\n", G.deckCount[p]);
	printf("Pre Hand: %d\n", G.handCount[p]);
	printf("Pre card count:%d\n", G.supplyCount[0]);
	#endif
	assert(gainCard(0, &G, -10, 0) == 0);
	#if (NOISY_TEST == 1)
	printf("Post Discard: %d\n", G.discardCount[p]);
	printf("Post Deck: %d\n", G.deckCount[p]);
	printf("Post Hand: %d\n", G.handCount[p]);
	printf("Post card count:%d\n", G.supplyCount[0]);
	#endif
	
	//check when the flag value is over 2, should add to discard pile
	#if (NOISY_TEST == 1)
	printf("Pre Discard: %d\n", G.discardCount[p]);
	printf("Pre Deck: %d\n", G.deckCount[p]);
	printf("Pre Hand: %d\n", G.handCount[p]);
	printf("Pre card count:%d\n", G.supplyCount[0]);
	#endif
	assert(gainCard(0, &G, 10, 0) == 0);
	#if (NOISY_TEST == 1)
	printf("Post Discard: %d\n", G.discardCount[p]);
	printf("Post Deck: %d\n", G.deckCount[p]);
	printf("Post Hand: %d\n", G.handCount[p]);
	printf("Post card count:%d\n", G.supplyCount[0]);
	#endif
	
	//check piles when they are empty
	G.supplyCount[0] = 6;
	G.deckCount[p] = 0;
	G.handCount[p] = 0;
	G.discardCount[p] = 0;
	#if (NOISY_TEST == 1)
	printf("Pre Discard: %d\n", G.discardCount[p]);
	printf("Pre Deck: %d\n", G.deckCount[p]);
	printf("Pre Hand: %d\n", G.handCount[p]);
	printf("Pre card count:%d\n", G.supplyCount[0]);
	#endif
	assert(gainCard(0, &G, 0, 0) == 0);
	#if (NOISY_TEST == 1)
	printf("Post Discard: %d\n", G.discardCount[p]);
	printf("Post Deck: %d\n", G.deckCount[p]);
	printf("Post Hand: %d\n", G.handCount[p]);
	printf("Post card count:%d\n", G.supplyCount[0]);
	#endif
	
	#if (NOISY_TEST == 1)
	printf("Pre Discard: %d\n", G.discardCount[p]);
	printf("Pre Deck: %d\n", G.deckCount[p]);
	printf("Pre Hand: %d\n", G.handCount[p]);
	printf("Pre card count:%d\n", G.supplyCount[0]);
	#endif
	assert(gainCard(0, &G, 1, 0) == 0);
	#if (NOISY_TEST == 1)
	printf("Post Discard: %d\n", G.discardCount[p]);
	printf("Post Deck: %d\n", G.deckCount[p]);
	printf("Post Hand: %d\n", G.handCount[p]);
	printf("Post card count:%d\n", G.supplyCount[0]);
	#endif
	
	#if (NOISY_TEST == 1)
	printf("Pre Discard: %d\n", G.discardCount[p]);
	printf("Pre Deck: %d\n", G.deckCount[p]);
	printf("Pre Hand: %d\n", G.handCount[p]);
	printf("Pre card count:%d\n", G.supplyCount[0]);
	#endif
	assert(gainCard(0, &G, 2, 0) == 0);
	#if (NOISY_TEST == 1)
	printf("Post Discard: %d\n", G.discardCount[p]);
	printf("Post Deck: %d\n", G.deckCount[p]);
	printf("Post Hand: %d\n", G.handCount[p]);
	printf("Post card count:%d\n", G.supplyCount[0]);
	#endif
	
	printf("All tests passed!\n");
	
	return 0;
}