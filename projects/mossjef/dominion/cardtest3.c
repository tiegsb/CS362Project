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
	//Set p1 to copper for simplicity and p2 to silver
		
	G.deckCount[player] = 0;
	G.deckCount[1] = 0;
	for (i = 0; i < 10; i++) {
			G.deck[player][i] = copper;
			G.deckCount[player]++; 
	}
	
	for (i = 0; i < 10; i++) {
			G.deck[1][i] = silver;
			G.deckCount[1]++; 
	}

	//Set the player hands with cards
	G.handCount[player] = 0;
	G.discardCount[player] = 0;
	G.handCount[1] = 0;
	G.discardCount[1] = 0;
		
	for(i = 0; i < 5; i++) {
		//Give player 0 5 cards coppers only
		G.hand[player][i] = copper;
		G.handCount[player]++;	
	}

	for(i = 0; i < 5; i++) {
		//Give player 1 5 cards silver only
		G.hand[1][i] = silver;
		G.handCount[1]++;	
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
  	int extNumBuys = G.numBuys = 1;
  	G.playedCardCount = 0;
  	G.whoseTurn = 0;
  	
	//Initialize external values to compare with tested function
	int extHandCount = G.handCount[player];
	int extDiscardCount = G.discardCount[player];
	int extHand[10];
	int extNumActions = G.numActions;
	int extP2discardCount = G.discardCount[1];
	int extP2handCount = G.handCount[1];

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

	//Ensure that number of buys are not affected
	if(extNumBuys == G.numBuys) {
		printf("useVillage(): PASS, number of buys not affected.\n");
	} else {
		printf("useVillage(): FAIL, number of buys expected %d, got %d.\n", extNumBuys, G.numBuys);
		fail = 1;
	}

#if(NOISY_TEST == 1)
	printf("Testing that Player 2 is not affected.\n");
#endif

	//Test that player 2 hand and discard files are not affected
	
	if(extP2discardCount == G.discardCount[1]) {
		printf("useVillage(): PASS Player 2 discardCount correct\n");
	} else {
		printf("useVillage(): FAIL Player 2 discardCount incorrect. Expected %d, counted %d\n", extP2discardCount, G.discardCount[1]);
		fail = 1;
	}
	
	//Test that player 2 hand is not changed
	if(extP2handCount == G.handCount[1]) {
		printf("useVillage(): PASS Player 2 handCount correct\n");
	} else {
		printf("useVillage(): FAIL Player 2 handCount incorrect. Expected %d, counted %d\n", extP2handCount, G.handCount[1]);
		fail = 1;
	}

	if(fail == 0) {
		printf("useVillage(): OK - ALL TESTS PASSED\n\n");
	} else {
		printf("useVillage(): ISSUES - AT LEAST ONE TEST FAILED\n\n");
	}

}
