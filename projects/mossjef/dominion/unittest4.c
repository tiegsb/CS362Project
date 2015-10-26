/*
 * Filename: 	unittest4.c
 * Author:	Jeff Moss
 * Date:	10/21/15
 * Description:	Unit test for gainCard function in dominion.c 
 * 		Tests gainCard functionality as well as return values
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

void testgainCard();

int main() {
	testgainCard(); 
 	return 0;
}

void testgainCard() {
	struct gameState G;
	int fail = 0;  
	G.numPlayers = 2;
	int player = 0;	
	G.handCount[player] = 0;
	G.deckCount[player] = 0;
	G.discardCount[player] = 0;	
	
	printf("TESTING gainCard(): \n");
#if(NOISY_TEST == 1) 
	printf("Testing condition where no supply is available\n");
#endif
	int i;
	for (i = curse; i <= treasure_map; i++) {
		G.supplyCount[i] = 0;
	}

	//Check add to discard
	int gainRet = gainCard(smithy, &G, 0, player);
	if (gainRet == -1) {
		printf("gainCard(): PASS error expected when no supply available.\n");
	} else {

		printf("gainCard(): Fail no error when no supply available.\n");
		fail = 1;
	}

#if(NOISY_TEST == 1) 
	printf("Testing adding a card to a player's deck\n");
#endif

	//Need a supply of cards	
	for (i = curse; i <= treasure_map; i++) {
		G.supplyCount[i] = 10;
	}
	int smithySupply = 10;
	int smithyDeck = 0;

	gainRet = gainCard(smithy, &G, 1, player);
	//# of smithy cards should be 1 now
	smithyDeck++;
	smithySupply--;
	
	if (gainRet == 0) {
		printf("gainCard(): PASS return value correct (gaincard to deck).\n");
	} else {

		printf("gainCard(): Fail return value incorrect (gaincard to deck).\n");
		fail = 1;
	}

	//Test number of smithy cards for player 0 and deck position
	if (G.deck[player][0] == smithy) {
		printf("gainCard(): PASS, smithy detected in first position.\n");
	} else {
		printf("gainCard(): FAIL, smithy not detected in first position.\n");
		fail = 1;
	}
	
	if (G.deckCount[0] == smithyDeck) {
		printf("gainCard(): PASS, total deck count of 1.\n");
	} else {
		printf("gainCard(): FAIL, deck count != 1, expected 1.\n");
		fail = 1;
	}

	//Test number of smithy cards left, should be 9
	if (G.supplyCount[smithy] == smithySupply) {
		printf("gainCard(): PASS, smithy supply decreased to 9\n");
	} else {
		printf("gainCard(): FAIL, smithy supply not decreased. Expected 9, counted %d\n", G.supplyCount[smithy]);
		fail = 1;
	}

#if(NOISY_TEST == 1)
	printf("Testing gaincard to the player's hand\n");
#endif
	gainRet = gainCard(smithy, &G, 2, player);
	//# of smithy cards should be 1 now
	int smithyHand = 1;
	smithySupply--;
	
	if (gainRet == 0) {
		printf("gainCard(): PASS return value correct (gaincard to hand).\n");
	} else {

		printf("gainCard(): Fail return value incorrect (gaincard to hand).\n");
		fail = 1;
	}

	//Test number of smithy cards for player 0
	if (G.hand[player][G.handCount[player]-1] == smithy) {
		printf("gainCard(): PASS, smithy detected in correct position.\n");
	} else {
		printf("gainCard(): FAIL, smithy not detected in correct position.\n");
		fail = 1;
	}
	
	if (G.handCount[player] == smithyHand) {
		printf("gainCard(): PASS, total hand count correct\n");
	} else {
		printf("gainCard(): FAIL, hand count incorrect\n");
		fail = 1;
	}

	//Test number of smithy cards left, should be 9
	if (G.supplyCount[smithy] == smithySupply) {
		printf("gainCard(): PASS, smithy supply decreased correctly\n");
	} else {
		printf("gainCard(): FAIL, smithy supply not decreased. Counted %d\n", G.supplyCount[smithy]);
		fail = 1;
	}
#if(NOISY_TEST == 1)
	printf("Testing gaincard to discard pile\n");
#endif

	int adventurerSupply = 10;
	int adventurerDiscard = 0;

	gainRet = gainCard(adventurer, &G, 0, player);
	//# of adventurer cards should be 1 now
	adventurerDiscard++;
	adventurerSupply--;
	
	if (gainRet == 0) {
		printf("gainCard(): PASS return value correct (gaincard to discard).\n");
	} else {

		printf("gainCard(): Fail return value incorrect (gaincard to discard).\n");
		fail = 1;
	}

	//Test number of smithy cards for player 0 and positioning
	if (G.discard[player][G.discardCount[player]-1] == adventurer) {
		printf("gainCard(): PASS, smithy detected in first position.\n");
	} else {
		printf("gainCard(): FAIL, smithy not detected in first position.\n");
		fail = 1;
	}
	
	if (G.discardCount[0] == adventurerDiscard) {
		printf("gainCard(): PASS, total discard count of 1.\n");
	} else {
		printf("gainCard(): FAIL, deck discard count != 1, expected 1.\n");
		fail = 1;
	}

	//Test number of smithy cards left, should be 9
	if (G.supplyCount[adventurer] == adventurerSupply) {
		printf("gainCard(): PASS, adventurer supply decreased to 9\n");
	} else {
		printf("gainCard(): FAIL, adventurer supply not decreased. Expected 9, counted %d\n", G.supplyCount[adventurer]);
		fail = 1;
	}
	

	if(fail == 0) { 
		printf("gainCard(): OK - ALL TESTS PASSED\n\n");
	} else {
		printf("gainCard(): ISSUES - AT LEAST ONE TEST FAILED\n\n");
	}
}
