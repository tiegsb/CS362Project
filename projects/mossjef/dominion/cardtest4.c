/*
 * Filename: 	cardtest4.c
 * Author:	Jeff Moss
 * Date:	10/24/15
 * Description:	Unit test for great_hall card function for dominion card game
 * 		Tests great_hall card functionality as well as return values
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

void testuseGreat_hall();

int main() {
	testuseGreat_hall(); 
 	return 0;
}

void testuseGreat_hall () {
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
		
	G.handCount[0] = 0;
	G.discardCount[0] = 0;
	
	//Set player 2	
	int extP2handCount = G.handCount[1] = 0;
	int extP2discardCount = G.discardCount[1] = 0;
	for(i = 0; i < 5; i++) {
		//Give each player 1 5 cards coppers only
		G.hand[0][i] = copper;	
	}

	//Give player 2 only silvers
	for(i=0; i < 5; i++) {
		//Give player 2 5 silvers
		G.hand[1][i] = silver;
	}

	//set embargo tokens to 0 for all supply piles
	for (i = 0; i <= treasure_map; i++)
	{
	G.embargoTokens[i] = 0;
	}

  	//initialize first player's turn
	G.outpostPlayed = 0;
  	G.phase = 0;
  	int extnumActions = G.numActions = 1;
  	int extnumBuys = G.numBuys = 1;
  	G.playedCardCount = 0;
  	G.whoseTurn = 0;
  	
	//Initialize external values to compare with tested function
	int extHandCount = G.handCount[player];
	int extDiscardCount = G.discardCount[player];
	
	
	printf("Testing useGreat_hall():\n");	
#if(NOISY_TEST == 1)
	printf("Testing return value and that a card is drawn\n");
#endif
	int Great_hallRet;
	Great_hallRet = useGreat_hall(0, 0, &G);

	//Test return value	
	if (Great_hallRet == 0) {
		printf("useGreat_hall(): PASS return value correct\n");
	} else {
		printf("useGreat_hall(): FAIL return value incorrect\n");
		fail = 1;
	}

	//Add one card to extHandCount
	extHandCount += 1;

	//Add one action as required for great_hall
	extnumActions++;

	//Discard great_hall from extHandCount and add to discard count
	extDiscardCount++;
	extHandCount--;

	//Ensure handcounts match
	if(extHandCount == G.handCount[player]) {
		printf("useGreat_hall(): PASS handCount correct\n");
	} else {
		printf("useGreat_hall(): FAIL handcount incorrect. Expected %d, counted %d\n", extHandCount, G.handCount[player]);
		fail = 1;
	}

	//Ensure discardcounts match
	if(extDiscardCount == G.discardCount[player]) {
		printf("useGreat_hall(): PASS discardCount correct\n");
	} else {
		printf("useGreat_hall(): FAIL discardCount incorrect. Expected %d, counted %d\n", extDiscardCount, G.discardCount[player]);
		fail = 1;
	}
#if(NOISY_TEST == 1)
	printf("Testing that no cards are pulled from anywhere other than player's deck.\n");
#endif

	//Ensure no cards are pulled from the other player's hand
	for (i = 0; i < G.handCount[player]; i++) {
		if(G.hand[player][i] == copper) {
			printf("useGreat_hall(): PASS, only copper cards detected in player's hand\n");
		} else {
			printf("useGreat_hall(): FAIL, cards pulled from location other than player's deck.\n");
			fail = 1;
		}
	}

#if(NOISY_TEST == 1)
	printf("Testing that player 2 is not adversly affected\n");
#endif

	//Ensure Player 2 is not affected
	
	if(extP2discardCount == G.discardCount[1]) {
		printf("useGreat_hall(): PASS discardCount correct for second player\n");
	} else {
		printf("useGreat_hall(): FAIL discardCount incorrect for second player. Expected %d, counted %d\n", extDiscardCount, G.discardCount[player]);
		fail = 1;
	}

	if(extP2handCount == G.handCount[1]) {
		printf("useGreat_hall(): PASS Player 2 handCount correct\n");
	} else {
		printf("useGreat_hall(): FAIL Player 2 handcount incorrect. Expected %d, counted %d\n", extHandCount, G.handCount[player]);
		fail = 1;
	}

#if(NOISY_TEST == 1)
	printf("Testing that the game state is correct.\n");
#endif

	//Ensure the game state is not changed
	if (extnumActions == G.numActions) {
		printf("useGreat_hall(): PASS, number of actions are incremented correctly.\n");
	} else {
		printf("useGreat_hall(): FAIL, number of actions not incremented correctly.\n");
		fail = 1;
	}

	if (extnumBuys == G.numBuys) {
		printf("useGreat_hall(): PASS, number of buys are not affected.\n");
	} else {
		printf("useGreat_hall(): FAIL, number of buys incorrect.\n");
		fail = 1;
	}

	if(fail == 0) {
		printf("useGreat_hall(): OK - ALL TESTS PASSED\n\n");
	} else {
		printf("useGreat_hall(): ISSUES - AT LEAST ONE TEST FAILED\n\n");
	}

}
