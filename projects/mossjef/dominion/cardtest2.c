/*
 * Filename: 	cardtest2.c
 * Author:	Jeff Moss
 * Date:	10/24/15
 * Description:	Unit test for adventurer card function for dominion card game
 * 		Tests adventurer card functionality as well as return values
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

void testuseAdventurer();

int main() {
	testuseAdventurer(); 
 	return 0;
}

void testuseAdventurer () {
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
	
	G.deckCount[player] = 0;
	G.deckCount[1] = 0;
	
	for (j = 0; j < 5; j++) {
		G.deck[player][j] = mine;
		G.deckCount[player]++;	
	}
	for (j = 5; j < 10; j++) {
		G.deck[player][j] = silver;
		G.deckCount[player]++; 
	}

	//Make second player cards different to differentiate	
	for (j = 0; j < 5; j++) {
		G.deck[1][j] = steward;
		G.deckCount[1]++;	
	}
	for (j = 5; j < 10; j++) {
		G.deck[1][j] = estate;
		G.deckCount[1]++; 
	}
	//Set the player hands with cards
	//Adventurer should not stop until two treasure cards are drawn.
	
	//Player 0
	G.handCount[0] = 0;
	G.discardCount[0] = 0;
		
	//Player 1
	G.handCount[1] = 0;
	G.discardCount[1] = 0;

	for(j = 0; j < 5; j++) {
		//Give player 0 5 cards coppers only
		G.hand[0][j] = copper;	
	}
	

	for(j = 0; j < 5; j++) {
		//Give player 1 5 cards gold only
		G.hand[1][j] = gold;	
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
	int extHand[10];
	int extP2handCount = G.handCount[1];
	int extP2discardCount = G.discardCount[1];
	int extnumBuys = G.numBuys;
	int extnumActions = G.numActions;

	//Initialize the external values for the player's hand
	for (i = 0; i < extHandCount; i++) {
		extHand[i] = G.hand[0][i];
	}
	
	printf("Testing useAdventurer():\n");	
#if(NOISY_TEST == 1)
	printf("Testing that the hand draw logic is correct\n");
#endif
	int adventurerRet;
	adventurerRet = useAdventurer(player, &G);

	//Test return value	
	if (adventurerRet == 0) {
		printf("useAdventurer(): PASS return value correct\n");
	} else {
		printf("useAdventurer(): FAIL return value incorrect\n");
		fail = 1;
	}

	//Add 5 action cards and 2 treasure cards to extHandCount
	extHandCount += 7;

	//Discard adventurer from extHandCount and add to discard count
	extDiscardCount++;

	//Discard all 5 action cards from extHandCount
	extHandCount-=5;
	extDiscardCount+=5;

#if(NOISY_TEST == 1)
	printf("Testing hand counts\n");
#endif

	//Ensure handcounts match
	if(extHandCount == G.handCount[player]) {
		printf("useAdventurer(): PASS handCount correct\n");
	} else {
		printf("useAdventurer(): FAIL handcount incorrect. Expected %d, counted %d\n", extHandCount, G.handCount[player]);
		fail = 1;
	}
#if(NOISY_TEST == 1)
	printf("Testing discard counts\n");
#endif

	//Ensure discardcounts match
	if(extDiscardCount == G.discardCount[player]) {
		printf("useAdventurer(): PASS discardCount correct\n");
	} else {
		printf("useAdventurer(): FAIL discardCount incorrect. Expected %d, counted %d\n", extDiscardCount, G.discardCount[player]);
		fail = 1;
	}

#if(NOISY_TEST == 1)
	printf("Testing that the hands match exactly\n");
#endif
	
	//Player's hand should be two silvers
	extHand[0] = silver;
	extHand[1] = silver;

	//Ensure hands match

	for (i = 0; i < extHandCount; i++) {
		if (G.hand[0][i] == extHand[i]) {
			printf("useAdventurer: PASS card %d. Expected %d, Got %d\n", i, extHand[i], G.hand[player][i]);
		} else {
			printf("useAdventurer: FAIL card %d. Expected %d, Got %d\n", i, extHand[i], G.hand[player][i]);
		}
	}

#if(NOISY_TEST == 1)
	printf("Testing that Player 2 is not affected.\n");
#endif
	//Test that player 2 is not affected
	if (extP2handCount == G.handCount[1]) {
		printf("useAdventurer: PASS, player 2 hand count unaffected.\n");
	} else {
		printf("useAdventurer: FAIL, player 2 hand count expected %d, got %d.\n", extP2handCount, G.handCount[1]);
		fail = 1;
	}

	if (extP2discardCount == G.discardCount[1]) {
		printf("useAdventurer: PASS, player 2 discard count unaffected.\n");
	} else {
		printf("useAdventurer: FAIL, player 2 discard count expected %d, got %d.\n", extP2discardCount, G.discardCount[1]);
		fail = 1;
	}

#if(NOISY_TEST == 1)
	printf("Testing that the game state is not affected.\n");
#endif
	//Test that the game state is not affected.
	if (extnumBuys == G.numBuys) {
		printf("useAdventurer(): PASS, number of buys not affected.\n");
	} else {
		printf("useAdventurer(): FAIL, number of buys expected %d, got %d.\n", extnumBuys, G.numBuys);
		fail = 1;
	}

	if (extnumActions == G.numActions) {
		printf("useAdventurer(): PASS, number of actions not affected.\n");
	} else {
		printf("useAdventurer(): FAIL, number of actions expected %d, got %d.\n", extnumActions, G.numActions);
		fail = 1;
	}
	
	if(fail == 0) {
		printf("useAdventurer(): OK - ALL TESTS PASSED\n\n");
	} else {
		printf("useAdventurer(): ISSUES - AT LEAST ONE TEST FAILED\n\n");
	}

}
