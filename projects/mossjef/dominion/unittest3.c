/*
 * Filename: 	unittest3.c
 * Author:	Jeff Moss
 * Date:	10/21/15
 * Description:	Unit test for isGameOver function in dominion.c 
 * 		Tests isGameOver functionality as well as return values
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

void testisGameOver();

int main() {
	testisGameOver(); 
 	return 0;
}

void testisGameOver() {
	struct gameState G;
	int fail = 0;  
	G.numPlayers = 2;
	
	printf("TESTING isGameOver(): \n");
	
	//Initialize supply of cards
	
	//Set curse cards
	G.supplyCount[curse] = 10;	
	G.supplyCount[estate] = 8;	
	G.supplyCount[duchy] = 8;	
	G.supplyCount[province] = 8;	
	G.supplyCount[copper] = 100;	
	G.supplyCount[silver] = 40;
	G.supplyCount[gold] = 30;	

	//Set kingdom cards; first 10 get 10
	//Last 10 are not in the deck
	int i;
	for (i = adventurer; i <= great_hall; i++) {
		//Set all supply counts to 10
		G.supplyCount[i] = 10;
	} 
	for (i = minion; i <= treasure_map; i++) {
		//Set all supply counts to -1 (not in game)
		G.supplyCount[i] = -1;
	}

	//Game is initialized, test for proper return.
#if(NOISY_TEST == 1)
	printf("Testing return value for a new game\n");
#endif

	int gameOver = isGameOver(&G);
	if(gameOver == 0) {
		printf("isGameOver(): PASS return value for initialized game\n");
	} else {
		printf("isGameOver(): FAIL return value initialized game\n");
		fail = 1;
	}

	//Test state where province cards are empty
#if(NOISY_TEST == 1)
	printf("Testing condition where province supply is empty\n");
#endif
	G.supplyCount[province] = 0;

	gameOver = isGameOver(&G);
	if(gameOver == 1) {
		printf("isGameOver(): PASS empty province\n");
	} else {
		printf("isGameOver(): FAIL empty province\n");
		fail = 1;
	}

#if(NOISY_TEST == 1)
	printf("Testing condition where three supply piles are out\n");
#endif
	//Test state where exactly three piles are out.
	G.supplyCount[province] = 10;
	G.supplyCount[adventurer] = 0;
	G.supplyCount[great_hall] = 0;
	G.supplyCount[feast] = 0;	

	gameOver = isGameOver(&G);
	if(gameOver == 1) {
		printf("isGameOver(): PASS 3 empty supply piles\n");
	} else {
		printf("isGameOver(): FAIL 3 empty supply piles\n");
		fail = 1;
	}
	
#if(NOISY_TEST == 1)
	printf("Testing condition where more than three supply piles are out\n");
#endif
	G.supplyCount[baron] = 0;
	gameOver = isGameOver(&G);
	if(gameOver == 1) {
		printf("isGameOver(): PASS > 3 empty supply piles\n");
	} else {
		printf("isGameOver(): FAIL > 3 empty supply piles\n");
		fail = 1;
	}
	if(fail == 0) {
		printf("isGameOver(): OK - ALL TESTS PASSED\n\n");
	} else {
		printf("isGameOver(): ISSUES - AT LEAST ONE TEST FAILED\n\n");
	}	
}
