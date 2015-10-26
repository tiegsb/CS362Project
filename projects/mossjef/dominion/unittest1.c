/*
 * Filename: 	unittest1.c
 * Author:	Jeff Moss
 * Date:	10/13/15
 * Description:	Unit test for shuffle function for dominion card game
 * 		Tests shuffle functionality as well as return values
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

int compare(const void* a, const void* b);
void testShuffle();

int main() {
	testShuffle(); 
 	return 0;
}

void testShuffle () {
	struct gameState G;
	  
	//Set supply count
	G.numPlayers = 2;
	int player = 0;
	  
	//set up random number generator
	SelectStream(1);
	PutSeed((long)2);
	  
	G.deckCount[0] = 5;
	G.deck[0][0] = estate;
	G.deck[0][1] = duchy;
	G.deck[0][2] = province;
	G.deck[0][3] = adventurer;
	G.deck[0][4] = smithy;

	int begDeck[5];

	printf("TESTING shuffle() for 5 iterations: \n");
	int fail = 0;
	int i;
	int retVal;
	//This area will test the shuffle functionality
	int j;

	for (j = 0; j < 5; j++) {

		  for (i = 0; i < 5; i++) {
			begDeck[i] = G.deck[0][i];
		  }
#if (NOISY_TEST == 1)
		  printf("Beginning order: %d, %d, %d, %d, %d\n", G.deck[0][0], G.deck[0][1], G.deck[0][2], G.deck[0][3], G.deck[0][4]);
#endif

		  retVal = shuffle(player, &G);
		  
		  //assert the return value is 0 (no error);
		  assert(retVal == 0);

		  if (retVal == 0) {
			printf("shuffle(): PASS when return value 0\n");
		  } else {
			printf("shuffle(): FAIL when return value 1 (expected 0)\n");
			fail = 1;
		  }
		  
#if (NOISY_TEST == 1)
		  printf("Ending order: %d, %d, %d, %d, %d\n", G.deck[0][0], G.deck[0][1], G.deck[0][2], G.deck[0][3], G.deck[0][4]);
#endif

		  for (i = 0; i < 5; i++) {
			if(begDeck[i] == G.deck[0][i]) {
				if (i == 4) {
					printf("shuffle(): FAIL after going through five cards\n");
					fail = 1;
				} 
			}  
			else {
				printf("shuffle(): PASS shuffle has occured at %d position!\n", i);
				break;
			}
		   }
	}

	//This area will test invalid inputs
	G.deckCount[0] = 0;

	retVal = shuffle(player, &G);
	
	//assert return value is -1
	assert(retVal == -1);
	
	if (retVal == -1) {
		printf("shuffle(): PASS when return value is -1 on invalid input\n");
	} else {
		printf("shuffle(): FAIL on improper return value on invalid input\n");
		fail = 1;
	}

	if(fail == 0) {
		printf("shuffle(): OK - ALL TESTS PASSED\n\n");
	} else {
		printf("shuffle(): ISSUES - AT LEAST ONE TEST FAILED\n\n");
	}

}
