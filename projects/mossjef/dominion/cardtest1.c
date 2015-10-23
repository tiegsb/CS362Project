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
 
	//Set hand count to 3, deck and discard to 0
	G.numPlayers = 2;
	G.deckCount[player] = 0;
	G.discardCount[player] = 0;
	G.handCount[player] = 3;
	G.hand[player][0] = smithy;
	G.hand[player][1] = gold;
	G.hand[player][2] = adventurer;

	//Set local variables to match
	int extDeckCount = 0;
	int extDiscardCount = 0;
	int extHandCount = 3;
	int extHand[3] = {smithy, gold, adventurer};
	
	//Initialize deck
	int i;
	for (i = adventurer; i < treasure_map; i++) {
		G.deck[player][i] = i;
		G.deckCount[player] = G.deckCount[player] + 1;
		extDeckCount++;
	}
	printf("Testing useSmithy():\n");	
#if(NOISY_TEST == 1)
	printf("Testing that 3 more cards are drawn");
#endif
	int smithyRet;
	smithyRet = useSmithy(0, 0, &G);
/*	
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
		printf("useSmithy(): FAIL handcount incorrect\n");
		fail = 1;
	}

	//Ensure handcounts match
	if(extDiscardCount == G.discardCount[player]) {
		printf("useSmithy(): PASS discardCount correct\n");
	} else {
		printf("useSmithy(): FAIL discardCount incorrect\n");
		fail = 1;
	}

	if(fail == 0) {
		printf("useSmithy(): OK - ALL TESTS PASSED\n\n");
	} else {
		printf("useSmithy(): ISSUES - AT LEAST ONE TEST FAILED\n\n");
	}
*/
}
