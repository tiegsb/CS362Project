#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define NOISY_TEST 0

//can't use asserts on this function as buyCard has some errors

//test buyCard
int main(){
	int i;
	int numPlayers = 2;
	int p = 0;
	int seed = 1000;
	int k[10] = {adventurer, council_room, feast, gardens, mine
	           , remodel, smithy, village, baron, great_hall};
	struct gameState G;
	
	printf("Testing buyCard()\n");
	
	memset(&G, 23, sizeof(struct gameState));
	initializeGame(numPlayers, k, seed, &G);
	
	//testing when player has enough buys/money and there are enough cards
	G.coins = 7;
	G.numBuys = 3; 
	G.supplyCount[1] = 2;
	G.discardCount[p] = 5;
	G.deckCount[p] = 5;
	G.handCount[p] = 5;
	
	#if (NOISY_TEST == 1)
	printf("Pre Buy: %d\n", G.numBuys);
	printf("Pre Coins: %d\n", G.coins);
	printf("Pre Discard: %d\n", G.discardCount[p]);
	printf("Pre Deck: %d\n", G.deckCount[p]);
	printf("Pre card count:%d\n", G.supplyCount[1]);
	printf("Pre player hand count:%d\n", G.handCount[0]);
	#endif
	buyCard(1, &G);
	#if (NOISY_TEST == 1)
	printf("Post Buy: %d\n", G.numBuys);
	printf("Post Coins: %d\n", G.coins);
	printf("Post Discard: %d\n", G.discardCount[p]);
	printf("Post Deck: %d\n", G.deckCount[p]);
	printf("Post card count:%d\n", G.supplyCount[1]);
	printf("Post player hand count:%d\n", G.handCount[0]);
	#endif
	
	//testing when player doesn't have money
	G.coins = 0;
	G.numBuys = 3; 
	G.supplyCount[1] = 2;
	G.discardCount[p] = 5;
	G.deckCount[p] = 5;
	G.handCount[p] = 5;
	
	#if (NOISY_TEST == 1)
	printf("Pre Buy: %d\n", G.numBuys);
	printf("Pre Coins: %d\n", G.coins);
	printf("Pre Discard: %d\n", G.discardCount[p]);
	printf("Pre Deck: %d\n", G.deckCount[p]);
	printf("Pre card count:%d\n", G.supplyCount[1]);
	printf("Pre player hand count:%d\n", G.handCount[0]);
	#endif
	buyCard(1, &G);
	#if (NOISY_TEST == 1)
	printf("Post Buy: %d\n", G.numBuys);
	printf("Post Coins: %d\n", G.coins);
	printf("Post Discard: %d\n", G.discardCount[p]);
	printf("Post Deck: %d\n", G.deckCount[p]);
	printf("Post card count:%d\n", G.supplyCount[1]);
	printf("Post player hand count:%d\n", G.handCount[0]);
	#endif

	//testing when player can't buy anymore
	G.coins = 10;
	G.numBuys = 0; 
	G.supplyCount[1] = 2;
	G.discardCount[p] = 5;
	G.deckCount[p] = 5;
	G.handCount[p] = 5;
	
	#if (NOISY_TEST == 1)
	printf("Pre Buy: %d\n", G.numBuys);
	printf("Pre Coins: %d\n", G.coins);
	printf("Pre Discard: %d\n", G.discardCount[p]);
	printf("Pre Deck: %d\n", G.deckCount[p]);
	printf("Pre card count:%d\n", G.supplyCount[1]);
	printf("Pre player hand count:%d\n", G.handCount[0]);
	#endif
	buyCard(1, &G);
	#if (NOISY_TEST == 1)
	printf("Post Buy: %d\n", G.numBuys);
	printf("Post Coins: %d\n", G.coins);
	printf("Post Discard: %d\n", G.discardCount[p]);
	printf("Post Deck: %d\n", G.deckCount[p]);
	printf("Post card count:%d\n", G.supplyCount[1]);
	printf("Post player hand count:%d\n", G.handCount[0]);
	#endif
	
	//testing when there are no cards left
	G.coins = 3;
	G.numBuys = 3; 
	G.supplyCount[1] = 0;
	G.discardCount[p] = 5;
	G.deckCount[p] = 5;
	G.handCount[p] = 5;
	
	#if (NOISY_TEST == 1)
	printf("Pre Buy: %d\n", G.numBuys);
	printf("Pre Coins: %d\n", G.coins);
	printf("Pre Discard: %d\n", G.discardCount[p]);
	printf("Pre Deck: %d\n", G.deckCount[p]);
	printf("Pre card count:%d\n", G.supplyCount[1]);
	printf("Pre player hand count:%d\n", G.handCount[0]);
	#endif
	buyCard(1, &G);
	#if (NOISY_TEST == 1)
	printf("Post Buy: %d\n", G.numBuys);
	printf("Post Coins: %d\n", G.coins);
	printf("Post Discard: %d\n", G.discardCount[p]);
	printf("Post Deck: %d\n", G.deckCount[p]);
	printf("Post card count:%d\n", G.supplyCount[1]);
	printf("Post player hand count:%d\n", G.handCount[0]);
	#endif
	
    printf("All tests passed!\n");

    return 0;
}