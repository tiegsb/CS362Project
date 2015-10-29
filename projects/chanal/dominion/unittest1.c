/***********************************************************************
* Author : Allan Chan
* ONID: chanal
* Class: CS362
* Filename: unittest1.c
*
* Description:
*    Unit Test 1 that runs tests on the updateCoins method in dominion.
*	 Tests various combinations of cards in hand.
*
************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>


//set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
	srand(time(NULL));
	int gameSeed = rand() % 1000 + 1;
	int p = 0; //player 1
	int numPlayer = 2;
	int bonus;
	int handCount;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
				 remodel, smithy, village, baron, great_hall};
	struct gameState G;
	int testHand1[5]; //handcount of 5 cards, no coins, no bonus
	int testHand2[5]; //handcount of 5 cards, one copper, one silver, one gold, no bonus
	int testHand3[7]; //handcount of 7 cards, one copper, two silver, 4 bonus
	int testHand4[7]; //handcount of 7 cards, two silver, two gold, no bonus
	int testHand5[7]; //handcount of 7 cards, no coins, 2 bonus

/******** First test ************/
#if (NOISY_TEST == 1)
	printf("Test #1, Handcount 5, no coins, no bonus\n");
#endif

	/*Set handcount*/
	handCount = 5;

	/*Set cards in hand*/
	testHand1[0] = 0;
	testHand1[1] = 0;
	testHand1[2] = 0;
	testHand1[3] = 0;
	testHand1[4] = 0;

	/*Bonus is 0*/
	bonus = 0;

	/*Clear the game state*/
	memset(&G, 23, sizeof(struct gameState));

	/*Initialize the game*/
	initializeGame(numPlayer, k, gameSeed, &G);

	/*Set number of cards in hand for player p*/
	G.handCount[p] = handCount;

	/*Set cards to testHand1*/
	memcpy(G.hand[p], testHand1, sizeof(int)*handCount);

	updateCoins(p, &G, bonus);

	/*Expected coins to be 0*/

#if (NOISY_TEST == 1)
	printf("Expected coins=%d Actual coins=%d \n", 0, G.coins);
	if(G.coins == 0){
		printf("Test #1 PASSED \n\n");
	} else {
		printf("Test #1 FAILED\n\n");
	}
#endif

/********** Second test ***********/
#if (NOISY_TEST == 1)
	printf("Test #2, Handcount of 5 cards, one copper, one silver, one gold, no bonus\n");
#endif

	/*Set handcount*/
	handCount = 5;

	/*Set cards in hand*/
	testHand2[0] = 0;
	testHand2[1] = 0;
	testHand2[2] = copper;
	testHand2[3] = silver;
	testHand2[4] = gold;

	/*Bonus is 0*/
	bonus = 0;

	/*Clear the game state*/
	memset(&G, 23, sizeof(struct gameState));

	/*Initialize the game*/
	initializeGame(numPlayer, k, gameSeed, &G);

	/*Set number of cards in hand for player p*/
	G.handCount[p] = handCount;

	/*Set cards to testHand2*/
	memcpy(G.hand[p], testHand2, sizeof(int)*handCount);

	/*Update coins in hand*/
	updateCoins(p, &G, bonus);

	/*Expected coins to be 6 (copper + silver + gold)*/


#if (NOISY_TEST == 1)
	printf("Expected coins=%d Actual coins=%d \n", 6, G.coins);
	
	if(G.coins == 6){
		printf("Test #2 PASSED \n\n");
	} else {
		printf("Test #2 FAILED\n\n");
	}	
#endif


/******** Third test *************/
#if (NOISY_TEST == 1)
	printf("Test #3, Handcount of 7 cards, one copper, two silver, 4 bonus\n");
#endif

	/*Set handcount*/
	handCount = 7;

	/*Set cards in hand*/
	testHand3[0] = 0;
	testHand3[1] = 0;
	testHand3[2] = copper;
	testHand3[3] = silver;
	testHand3[4] = silver;
    testHand3[5] = 0;
    testHand3[6] = 0;

	/*Bonus is 4*/
	bonus = 4;

	/*Clear the game state*/
	memset(&G, 23, sizeof(struct gameState));

	/*Initialize the game*/
	initializeGame(numPlayer, k, gameSeed, &G);

	/*Set number of cards in hand for player p*/
	G.handCount[p] = handCount;

	/*Set cards to testHand3*/
	memcpy(G.hand[p], testHand3, sizeof(int)*handCount);

	/*Update coins in hand*/
	updateCoins(p, &G, bonus);

	/*Expected coins to be 9 (copper + silver + silver + 4 bonus)*/

#if (NOISY_TEST == 1)
	printf("Expected coins=%d Actual coins=%d \n", 9, G.coins);
	
	if(G.coins == 9){
		printf("Test #3 PASSED \n\n");
	} else {
		printf("Test #3 FAILED\n\n");
	}	
#endif
  

/********** Fourth test **********/
#if (NOISY_TEST == 1)
	printf("Test #4, handcount of 7 cards, two silver, two gold, no bonus\n");
#endif

	/*Set handcount*/
	handCount = 7;

	/*Set cards in hand*/
	testHand4[0] = 0;
	testHand4[1] = 0;
	testHand4[2] = 0;
	testHand4[3] = silver;
	testHand4[4] = silver;
    testHand4[5] = gold;
    testHand4[6] = gold;

	/*Bonus is 0*/
	bonus = 0;

	/*Clear the game state*/
	memset(&G, 23, sizeof(struct gameState));

	/*Initialize the game*/
	initializeGame(numPlayer, k, gameSeed, &G);

	/*Set number of cards in hand for player p*/
	G.handCount[p] = handCount;

	/*Set cards to testHand4*/
	memcpy(G.hand[p], testHand4, sizeof(int)*handCount);

	/*Update coins in hand*/
	updateCoins(p, &G, bonus);

	/*Expected coins to be 10 (silver + silver, + gold + gold)*/

#if (NOISY_TEST == 1)
	printf("Expected coins=%d Actual coins=%d \n", 10, G.coins);
	
	if(G.coins == 10){
		printf("Test #4 PASSED \n\n");
	} else {
		printf("Test #4 FAILED\n\n");
	}	
#endif

/********** Fifth test **********/
#if (NOISY_TEST == 1)
	printf("Test #5, handcount of 7 cards, no coins, 2 bonus\n");
#endif

	/*Set handcount*/
	handCount = 7;

	/*Set cards in hand*/
	testHand5[0] = 0;
	testHand5[1] = 0;
	testHand5[2] = 0;
	testHand5[3] = 0;
	testHand5[4] = 0;
    testHand5[5] = 0;
    testHand5[6] = 0;

	/*Bonus is 2*/
	bonus = 2;

	/*Clear the game state*/
	memset(&G, 23, sizeof(struct gameState));

	/*Initialize the game*/
	initializeGame(numPlayer, k, gameSeed, &G);

	/*Set number of cards in hand for player p*/
	G.handCount[p] = handCount;

	/*Set cards to testHand5*/
	memcpy(G.hand[p], testHand5, sizeof(int)*handCount);

	/*Update coins in hand*/
	updateCoins(p, &G, bonus);

	/*Expected coins to be 2 (2 bonus)*/

#if (NOISY_TEST == 1)
	printf("Expected coins=%d Actual coins=%d \n", 2, G.coins);
	if(G.coins == 2){
		printf("Test #5 PASSED \n\n");
	} else {
		printf("Test #5 FAILED\n\n");
	}	
#endif

	return 0;
}
