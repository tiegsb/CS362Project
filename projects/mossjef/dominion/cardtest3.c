/*
 * Filename: 	cardtest3.c
 * Author:	Jeff Moss
 * Date:	10/24/15
 * Description:	Unit test for village card function for dominion card game
 * 		Tests village card functionality as well as return values
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

void testuseVillage();

int main() {
	testuseVillage(); 
 	return 0;
}

void testuseVillage() {
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
	//Set all to copper for simplicity
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
	int extHand[10];
	int extNumActions = G.numActions;

	//Initialize the external values for the player's hand
	for (i = 0; i < extHandCount; i++) {
		extHand[i] = G.hand[0][i];
	}
	
	printf("Testing useVillage():\n");	
#if(NOISY_TEST == 1)
	printf("Testing that the return value is correct and a card is drawn\n");
#endif
	int villageRet;
	villageRet = useVillage(0, player, &G);

	//Test return value	
	if (villageRet == 0) {
		printf("useVillage(): PASS return value correct\n");
	} else {
		printf("useVillage(): FAIL return value incorrect\n");
		fail = 1;
	}

	//Add 1 card to ext hand count for the drawn card 
	extHandCount++;

	//Discard from extHandCount and add to discard count
	extDiscardCount++;
	extHandCount--; //discard the village from the hand


#if(NOISY_TEST == 1)
	printf("Testing hand counts\n");
#endif

	//Ensure handcounts match
	if(extHandCount == G.handCount[player]) {
		printf("useVillage(): PASS handCount correct\n");
	} else {
		printf("useVillage(): FAIL handcount incorrect. Expected %d, counted %d\n", extHandCount, G.handCount[player]);
		fail = 1;
	}
#if(NOISY_TEST == 1)
	printf("Testing discard counts\n");
#endif

	//Ensure discardcounts match
	if(extDiscardCount == G.discardCount[player]) {
		printf("useVillage(): PASS discardCount correct\n");
	} else {
		printf("useVillage(): FAIL discardCount incorrect. Expected %d, counted %d\n", extDiscardCount, G.discardCount[player]);
		fail = 1;
	}

	//Ensure that actions match
	//External action should be increased by two.
	extNumActions+=2;
#if(NOISY_TEST == 1) 
	printf("Testing that actions are incremented correctly\n");
#endif

	if(extNumActions == G.numActions) {
		printf("useVillage(): PASS number of actions incremented correctly\n");
	} else {
		printf("useVillage(): FAIL number of actions expected %d, got %d\n", extNumActions, G.numActions);
		fail = 1;
	}
	if(fail == 0) {
		printf("useVillage(): OK - ALL TESTS PASSED\n\n");
	} else {
		printf("useVillage(): ISSUES - AT LEAST ONE TEST FAILED\n\n");
	}

}
