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
	int testHand1[5]; //handcount of 5 cards, one copper, no bonus
	int testHand2[5]; //handcount of 5 cards, one copper, two silver, no bonus
	int testHand3[7]; //handcount of 7 cards, two copper, two gold, no bonus


/******** First test ************/
#if (NOISY_TEST == 1)
	printf("Test #1, Handcount of 5 cards, one copper, no bonus\n");
#endif

	/*Set handcount*/
	handCount = 5;

	/*Set cards in hand*/
	testHand1[0] = 0;
	testHand1[1] = 0;
	testHand1[2] = 0;
	testHand1[3] = 0;
	testHand1[4] = copper;

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
	printf("Expected coins=%d Actual coins=%d \n", 1, G.coins);
	if(G.coins == 1){
		printf("Test #1 PASSED \n\n");
	} else {
		printf("Test #1 FAILED\n\n");
	}
#endif

/********** Second test ***********/
#if (NOISY_TEST == 1)
	printf("Test #2, Handcount of 5 cards, one copper, two silver, no bonus\n");
#endif

	/*Set handcount*/
	handCount = 5;

	/*Set cards in hand*/
	testHand2[0] = 0;
	testHand2[1] = 0;
	testHand2[2] = copper;
	testHand2[3] = silver;
	testHand2[4] = silver;

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

	/*Expected coins to be 5 (copper + silver + silver)*/


#if (NOISY_TEST == 1)
	printf("Expected coins=%d Actual coins=%d \n", 5, G.coins);
	
	if(G.coins == 5){
		printf("Test #2 PASSED \n\n");
	} else {
		printf("Test #2 FAILED\n\n");
	}	
#endif



/********** Third test **********/
#if (NOISY_TEST == 1)
	printf("Test #3, Handcount of 7 cards, two copper, two gold, no bonus\n");
#endif

	/*Set handcount*/
	handCount = 7;

	/*Set cards in hand*/
	testHand3[0] = 0;
	testHand3[1] = 0;
	testHand3[2] = 0;
	testHand3[3] = copper;
	testHand3[4] = copper;
    testHand3[5] = gold;
    testHand3[6] = gold;

	/*Bonus is 0*/
	bonus = 0;

	/*Clear the game state*/
	memset(&G, 23, sizeof(struct gameState));

	/*Initialize the game*/
	initializeGame(numPlayer, k, gameSeed, &G);

	/*Set number of cards in hand for player p*/
	G.handCount[p] = handCount;

	/*Set cards to testHand4*/
	memcpy(G.hand[p], testHand3, sizeof(int)*handCount);

	/*Update coins in hand*/
	updateCoins(p, &G, bonus);

	/*Expected coins to be 8 (copper + copper, + gold + gold)*/

#if (NOISY_TEST == 1)
	printf("Expected coins=%d Actual coins=%d \n", 8, G.coins);
	
	if(G.coins == 8){
		printf("Test #3 PASSED \n\n");
	} else {
		printf("Test #3 FAILED\n\n");
	}	
#endif

	return 0;
}
