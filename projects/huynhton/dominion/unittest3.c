/* -----------------------------------------------------------------------
 * Author: Tony Huynh		CS 362		unittest3.c

 * This test will test the accuracy of scores (testScoreFor)
 
 * Include the following lines in your makefile:
 *
 * testScoreFor: unittest3.c dominion.o rngs.o
 *      gcc -o testScoreFor -g  unittest3.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include<time.h>	// incorporate simple random testing
#include "rngs.h"


int main() {
    srand(time(NULL));
	
	int i, j, A;	// loop variables
	int flagInt1 = 1, flagInt2 = 1;
    int seed = 1000;
    int numPlayer = 2;
    int r;	//, handCount;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    //int maxHandCount = 5;
	int currentPlayer = whoseTurn(&G);
	
	// create variables for this test
	int expected_score_1;				// create variables for testing expected score
	int expected_score_2 = 0;			// create variables for testing expected score
	int score_1_actual, score_2_actual;	// create variables for actual score

    // initialize game state
	printf ("TESTING ScoreFor():\n");
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

	// first test: keep it simple.
	gainCard(estate, &G, 2, currentPlayer);
	gainCard(duchy, &G, 2, currentPlayer);
	gainCard(province, &G, 2, currentPlayer);	
	
	expected_score_1 = 1 + 3 + 6 + 1;	// copper + silver + gold. There is also an extra score from initialization
	score_1_actual = scoreFor(currentPlayer, &G); // get score from first player
	
	//assert(expected_score_1 == score_1_actual);	// expected and actual score should be equal
	if(expected_score_1 == score_1_actual){
		printf("TEST RESULT #1: PASSED- ScoreFor scored correctly.\n");
		printf("\tPlayer 1:  Expected: %d\tActual: %d\n",expected_score_1, score_1_actual);
		flagInt1 = 0;
	}
	
	// second test: make random testing
	currentPlayer +=1;				// update to new player
	A = rand()%10;					// make loop counterSwitch
	for (i = 0; i < A; i++){
		j = rand()%3;
		
		if(j == 0){					// estate condition
			gainCard(estate, &G, 2, currentPlayer);
			expected_score_2 += 1;
		}
		else if(j == 1){			// duchy condition
			gainCard(duchy, &G, 2, currentPlayer);
			expected_score_2 += 3;
		}
		else if(j ==2){				// province condition
			gainCard(province, &G, 2, currentPlayer);
			expected_score_2 += 6;
		}
		
	}
	score_2_actual = scoreFor(currentPlayer, &G);
		
	//assert(expected_score_2 == score_2_actual);	// expected and actual score should be equal
	if(expected_score_1 == score_1_actual){
		printf("TEST RESULT #2: PASSED- ScoreFor scored correctly.\n");
		printf("\tPlayer 2:  Expected: %d\tActual: %d\n",expected_score_2, score_2_actual);
		flagInt2 = 0;
	}

    if( flagInt1 == 1) {
		printf("TEST RESULT #1: FAILED- ScoreFor did not score accurately.\n");
		printf("\tPlayer 1:  Expected: %d\tActual: %d\n",expected_score_1, score_1_actual);
	}
	if( flagInt2 == 1) {
		printf("TEST RESULT #2: FAILED- ScoreFor did not score accurately in random situation.\n");
		printf("\tPlayer 2:  Expected: %d\tActual: %d\n",expected_score_2, score_2_actual);
	}
	
    return 0;
}