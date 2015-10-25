/*
 * Filename: 	cardtest1.c
 * Author:	Jeff Moss
 * Date:	10/21/15
 * Description:	Unit test for smithy card function for dominion card game
 * 		Tests smithy card functionality as well as return values
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>
#include <stdlib.h>

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

void testuseSmithy();

int main() {
	testuseSmithy(); 
 	return 0;
}

void testuseSmithy () {
	struct gameState G;
	int fail = 0;
 	int player = 0;
 
	//Set hand count to 5, initialize cards
	G.numPlayers = 2;

	//Initialize game to use smithy
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	G.supplyCount[estate] = 8;
	G.supplyCount[duchy] = 8;
	G.supplyCount[province] = 8;
	G.supplyCount[copper] = 46;
	G.supplyCount[silver] = 40;
	G.supplyCount[gold] = 30;
	
	int i, j;

	//Set number of kingdom cards
	for (i= adventurer; i <= treasure_map; i++) {
		for (j=0; j < 10; j++) {
			if(k[j] == i) {
				//Make supply of 10 for chosen cards
				G.supplyCount[i] = 10;
			} else {
				G.supplyCount[i] = -1;
			}	
		}
	}
	//Set the player decks for 2 players
	int numPlayers = 2;
	for (i = 0; i < numPlayers; i++) {
		G.deckCount[i] = 0;
		for (j = 0; j < 10; j++) {
			G.deck[i][j] = copper;
			G.deckCount[i]++;	
		}
	}
	
	//Set the player hands with cards
	for (i = 0; i < numPlayers; i++) {
		G.handCount[i] = 0;
		G.discardCount[i] = 0;
		
		for(j = 0; j < 5; j++) {
			//Give each player 5 cards coppers only
			G.hand[i][j] = copper;	
		}
	}

	//set embargo tokens to 0 for all supply piles
	for (i = 0; i <= treasure_map; i++)
	{
	G.embargoTokens[i] = 0;
	}

  	//initialize first player's turn
	G.outpostPlayed = 0;
  	G.phase = 0;
  	G.numActions = 1;
  	G.numBuys = 1;
  	G.playedCardCount = 0;
  	G.whoseTurn = 0;
  	
	//Initialize external values to compare with tested function
	int extHandCount = G.handCount[player];
	int extDiscardCount = G.discardCount[player];
	
	
	printf("Testing useSmithy():\n");	
#if(NOISY_TEST == 1)
	printf("Testing that 3 more cards are drawn\n");
#endif
	int smithyRet;
	smithyRet = useSmithy(0, 0, &G);

	//Test return value	
	if (smithyRet == 0) {
		printf("useSmithy(): PASS return value correct\n");
	} else {
		printf("useSmithy(): FAIL return value incorrect\n");
		fail = 1;
	}

	//Add three cards to extHandCount
	extHandCount += 3;
	//Discard smithy from extHandCount and add to discard count
	extDiscardCount++;
	extHandCount--;

	//Ensure handcounts match
	if(extHandCount == G.handCount[player]) {
		printf("useSmithy(): PASS handCount correct\n");
	} else {
		printf("useSmithy(): FAIL handcount incorrect. Expected %d, counted %d\n", extHandCount, G.handCount[player]);
		fail = 1;
	}

	//Ensure discardcounts match
	if(extDiscardCount == G.discardCount[player]) {
		printf("useSmithy(): PASS discardCount correct\n");
	} else {
		printf("useSmithy(): FAIL discardCount incorrect. Expected %d, counted %d\n", extDiscardCount, G.discardCount[player]);
		fail = 1;
	}

	if(fail == 0) {
		printf("useSmithy(): OK - ALL TESTS PASSED\n\n");
	} else {
		printf("useSmithy(): ISSUES - AT LEAST ONE TEST FAILED\n\n");
	}

}
