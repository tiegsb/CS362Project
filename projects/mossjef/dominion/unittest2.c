/*
 * Filename: 	unittest2.c
 * Author:	Jeff Moss
 * Date:	10/20/15
 * Description:	Unit test for fullDeckCount function for dominion card game
 * 		Tests fullDeckCount functionality as well as return values
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

void testfullDeckCount();

int main() {
	testfullDeckCount(); 
 	return 0;
}

void testfullDeckCount () {
	struct gameState G;
	int fail = 0;	  
	G.numPlayers = 2;
	int player = 0;
	  
	//Set 10 cards in deck
	//Have some duplicates  
	G.deckCount[0] = 10;
	G.deck[0][0] = estate;
	G.deck[0][1] = duchy;
	G.deck[0][2] = province;
	G.deck[0][3] = adventurer;
	G.deck[0][4] = smithy;
	G.deck[0][5] = smithy;
	G.deck[0][6] = smithy;
	G.deck[0][7] = adventurer;
	G.deck[0][8] = estate;
	G.deck[0][9] = embargo;

	printf("TESTING fullDeckCount(): \n");
#if(NOISY_TEST == 1)
	printf("Testing with no player hand or discard\n");
#endif
	int estCount = fullDeckCount(player, estate, &G);
	//Check estate count, should be 2
	if(estCount == 2) {
		printf("fullDeckCount(): PASS estate card expected 2, counted %d\n", estCount);
	} else {
		printf("fullDeckCount(): FAIL estate card expected 2, counted %d\n", estCount);
		fail = 1;
	}

	int councilCount = fullDeckCount(player, council_room, &G);

	//Check council_room count, should be 0
	if(councilCount == 0) {
		printf("fullDeckCount(): PASS council_room card expected 0, counted %d\n", councilCount);
	} else {
		printf("fullDeckCount(): FAIL council_room card expected 0, counted %d\n", councilCount);
		fail = 1;
	}

#if(NOISY_TEST == 1)
	printf("Testing with addition to player hand\n");
#endif
	//Add a couple of cards in the hand, check count
	G.hand[0][0] = estate;
	G.hand[0][1] = council_room;
	G.handCount[0] = 2;

	estCount = fullDeckCount(player, estate, &G);

	//Check estate count, should be 3
	if(estCount == 3) {
		printf("fullDeckCount(): PASS estate card expected 3, counted %d\n", estCount);
	} else {
		printf("fullDeckCount(): FAIL estate card expected 3, counted %d\n", estCount);
		fail = 1;
	}

	councilCount = fullDeckCount(player, council_room, &G);

	//Check council_room count, should be 1
	if(councilCount == 1) {
		printf("fullDeckCount(): PASS council_room card expected 1, counted %d\n", councilCount);
	} else {
		printf("fullDeckCount(): FAIL council_room card expected 1, counted %d\n", councilCount);
		fail = 1;
	}

	

#if(NOISY_TEST == 1)
	printf("Testing with addition to player discard\n");
#endif

	G.discardCount[player] = 2;
	G.discard[player][0] = smithy;
	G.discard[player][1] = council_room;

	councilCount = fullDeckCount(player, council_room, &G);

	//Check council_room count, should be 2
	if(councilCount == 2) {
		printf("fullDeckCount(): PASS council_room card expected 2, counted %d\n", councilCount);
	} else {
		printf("fullDeckCount(): FAIL council_room card expected 2, counted %d\n", councilCount);
		fail = 1;
	}

	int smithyCount = fullDeckCount(player, smithy, &G);
	//Check smithy count, should be 4
	if(smithyCount == 4) {
		printf("fullDeckCount(): PASS smithy card expected 4, counted %d\n", smithyCount);
	} else {
		printf("fullDeckCount(): FAIL smithy card expected 4, counted %d\n", smithyCount);	
		fail = 1;
	}

	if(fail == 0) {
		printf("fullDeckCount(): OK - ALL TESTS PASSED\n\n");	
	} else {
		printf("fullDeckCount(): ISSUES - AT LEAST ONE TEST FAILED \n\n");
	}
}
