/* -----------------------------------------------------------------------
 * Author: Tony Huynh		CS 362		unittest4.c

 * This test will test the validity of card costs (getCost)
 
 * Include the following lines in your makefile:
 *
 * testGetCost: unittest4.c dominion.o rngs.o
 *      gcc -o testGetCost -g  unittest4.c dominion.o rngs.o $(CFLAGS)
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
	printf ("TESTING getCost():\n");
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

	
	// first test: keep it simple.
	expected_score_1 = 0 + 2 + 5 + 4 + 4 + 4;	// test first and last three cards on list
	score_1_actual = getCost(0) + getCost(1) + getCost(2) + getCost(24) + getCost(25) + getCost(26);
	
	//assert(expected_score_1 == score_1_actual);	// expected and actual score should be equal
	if(expected_score_1 == score_1_actual){
		printf("TEST RESULT #1: PASSED- cost of cards is correct.\n");
		printf("\tFirst cost test:  Calculated: %d\tActual: %d\n",expected_score_1, score_1_actual);
		flagInt1 = 0;
	}
	
	// second test: make random testing
	A = rand()%20;					// make loop counterSwitch
	for (i = 0; i < A; i++){
		j = rand()%15;
		/*
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
		}*/
		switch( j)
			{
			case 0:
				expected_score_2 += 0;
				score_2_actual += getCost(0);
				break;
			case 1:
				expected_score_2 += 2;
				score_2_actual += getCost(1);
				break;
			case 2:
				expected_score_2 += 5;
				score_2_actual += getCost(2);
				break;
			case 3:
				expected_score_2 += 8;
				score_2_actual += getCost(3);
				break;
			case 4:
				expected_score_2 += 0;
				score_2_actual += getCost(4);
				break;
			case 5:
				expected_score_2 += 3;
				score_2_actual += getCost(5);
				break;
			case 6:
				expected_score_2 += 6;
				score_2_actual += getCost(6);
				break;
			case 7:
				expected_score_2 += 6;
				score_2_actual += getCost(7);
				break;
			case 8:
				expected_score_2 += 5;
				score_2_actual += getCost(8);
				break;
			case 9:
				expected_score_2 += 4;
				score_2_actual += getCost(9);
				break;
			case 10:
				expected_score_2 += 4;
				score_2_actual += getCost(10);
				break;
			case 11:
				expected_score_2 += 5;
				score_2_actual += getCost(11);
				break;
			case 12:
				expected_score_2 += 4;
				score_2_actual += getCost(12);
				break;
			case 13:
				expected_score_2 += 4;
				score_2_actual += getCost(13);
				break;
			case 14:
				expected_score_2 += 3;
				score_2_actual += getCost(14);
				break;
			}
	}
	
	//assert(expected_score_2 == score_2_actual);	// expected and actual score should be equal
	if(expected_score_2 == score_2_actual){
		printf("TEST RESULT #2: PASSED- Cost remained correct from random test.\n");
		printf("Second cost test:  Calculated: %d\tActual: %d\n",expected_score_2, score_2_actual);
		flagInt2 = 0;
	}
	
	
   if( flagInt1 == 1) {
		printf("TEST RESULT #1: FAILED- Cost of card did not add up correctly.\n");
		printf("\tFirst cost test:  Calculated: %d\tActual: %d\n",expected_score_1, score_1_actual);
   }
   if( flagInt2 == 1) {
		printf("TEST RESULT #2: FAILED- Random adding caused error in adding up card costs.\n");
		printf("\tSecond cost test:  Calculated: %d\tActual: %d\n",expected_score_2, score_2_actual);
   }
	
	
    return 0;
}