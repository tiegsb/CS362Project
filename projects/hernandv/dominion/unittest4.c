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

int main() {
	srand(time(NULL));
	int gameSeed = rand() % 1000 + 1;
	int p = 0; //player 1
	int numPlayer = 2;
	int handCount = 5;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
				 remodel, smithy, village, baron, great_hall};

	/*Load hand with cards*/
	int testHand1[5] = {adventurer, province, feast, copper, gold};
	int preHandCount, postHandCount, preDiscardCount, postDiscardCount, preDeckCount, postDeckCount = 0;

	struct gameState G;

	/*Clear the game state*/
	memset(&G, 23, sizeof(struct gameState));

	/*Initialize the game*/
	initializeGame(numPlayer, k, gameSeed, &G);

	/*Set cards to testHand1, player 1 = [p]*/
	memcpy(G.hand[p], testHand1, sizeof(int)*handCount);
	G.handCount[p] = handCount;



#if(NOISY_TEST == 1) 
	printf("Testing drawCard() for Player 0 with empty deck and non-empty discard pile\n");
#endif

	/*Clear the game state*/
	memset(&G, 23, sizeof(struct gameState));

	/*Initialize the game*/
	initializeGame(numPlayer, k, gameSeed, &G);

	G.handCount[p] = handCount;
	G.deckCount[p] = 0; //Empty deck pile
	G.discardCount[p] = 0; //Non-empty discard pile

	preHandCount = G.handCount[p];	//Hand count of player before draw
	preDeckCount = G.deckCount[p];	//Deck count of player before draw
	preDiscardCount = G.discardCount[p];	//Discard pile count of player before draw

	drawCard(p, &G);	

	postHandCount = G.handCount[p];	//Hand count of player after draw
	postDeckCount = G.deckCount[p];	//Deck count of player after draw
	postDiscardCount = G.discardCount[p];	//Discard pile count of player after draw

#if(NOISY_TEST == 1)
	/*Check whether the discard pile is shuffled with deck pile*/
	if(postDeckCount + 1 == preDiscardCount || postDeckCount == preDiscardCount){
		printf( "Test PASSED, discard pile shuffled with deck\n");
	} else {
		printf( "Test FAILED, discard pile NOT shuffled with deck\n");
	}

	/*Check post hand count with pre hand count*/
	if(postHandCount == preHandCount + 1){
		printf( "Test PASSED, card added to player's hand after draw\n");
	} else {
		printf( "Test FAILED, card NOT added to player's hand after draw\n");
	}

	/*Check if discard pile is empty*/
	if(preDeckCount == postDiscardCount){
		printf( "Test PASSED, discard pile was empty\n");
	} else {
		printf( "Test FAILED, discard pile was NOT empty\n");
	}

	/*Check deck count*/
	if(postDeckCount == preDiscardCount - 1){
		printf( "Test PASSED, deck decremented after draw\n");
	} else {
		printf( "Test FAILED, deck NOT decremented after draw\n");
	}

	/*Check deck count*/
	if(postDeckCount > 0){
		printf( "Test PASSED, deck was NOT empty\n\n");
	} else {
		printf( "Test FAILED, card drawn from empty deck\n\n");
	}
#endif

	return 0;
}