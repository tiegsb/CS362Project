/*****************************************************************************
 Author: CHIA, YiXuan
 Title:  cardtest3.c
 Desc:   Testing cardEffect_council_room() function in dominion.c using unit test
 Course: CS362 Fall 2015
*****************************************************************************/

#include "interface.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>

//Set TEST_MODE to 0 to remove printfs from output
#define TEST_MODE 1

int main() {
	int i;
	int seed = 2000;
	int num_player = 2;
	int k[10] = { adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall };
	struct gameState test_state;

	int hand_count = 5;

	int test_hand[MAX_HAND];
	int test_hand2[MAX_HAND];

	char name[15];

#if (TEST_MODE == 1)
	printf("START TESTING cardEffect_council_room():\n");
#endif

	test_hand[0] = silver;
	test_hand[1] = council_room;
	test_hand[2] = gold;
	test_hand[3] = copper;
	test_hand[4] = copper;

	test_hand2[0] = copper;
	test_hand2[1] = copper;
	test_hand2[2] = copper;
	test_hand2[3] = council_room;
	test_hand2[4] = copper;

	/*Test 1: Player gain 4 cards and 1 buy*/
	/*Clear game state*/
	memset(&test_state, 23, sizeof(struct gameState));
	/*Initialize game*/
	initializeGame(num_player, k, seed, &test_state);
	/*Fill hand with cards*/
	memcpy(test_state.hand[0], test_hand, sizeof(int)* hand_count);
	memcpy(test_state.hand[1], test_hand2, sizeof(int)* hand_count);

	printf("Council Room Card Effect Test 1:\n");
	printf("Before Card Effect:\n\n");
	//Show cards in player 1's hand 
	printf("Card in player 1's hand: ");
	
	/*Change card number to name*/
	for (i = 0; i < test_state.handCount[0]; i++){
		cardNumToName(test_state.hand[0][i], name);
		printf("\t%s", name);
	}
	printf("\nNumber of Cards:   %d\n", test_state.handCount[0]);
	printf("Number of Buys:   %d\n", test_state.numBuys);
	printf("Number of Discard:   %d\n\n", test_state.discardCount[0]);

	//Show cards in player 2's hand
	printf("Card in player 2's hand: ");
	
	/*Change card number to name*/
	for (i = 0; i < test_state.handCount[1]; i++){
		cardNumToName(test_state.hand[1][i], name);
		printf("\t%s", name);
	}
	printf("\nNumber of Cards:   %d\n\n", test_state.handCount[1]);

	//Call function cardEffect_council_room()
	cardEffect_council_room(1, 0, &test_state);

	printf("Ater Card Effect:\n\n");
	printf("Card in player 1's hand: ");

	/*Change card number to name*/
	for (i = 0; i < test_state.handCount[0]; i++){
		cardNumToName(test_state.hand[0][i], name);
		printf("\t%s", name);
	}
	printf("\nNumber of Cards:   %d, Expected Number of Cards:   9\n", test_state.handCount[0]);
	printf("Number of Buys:   %d, Expected Number of Buys:   2\n", test_state.numBuys);
	printf("Number of Discard:   %d\n\n", test_state.discardCount[0]);

	printf("Card in player 2's hand: ");

	/*Change card number to name*/
	for (i = 0; i < test_state.handCount[1]; i++){
		cardNumToName(test_state.hand[1][i], name);
		printf("\t%s", name);
	}
	printf("\nNumber of Cards:   %d\n\n", test_state.handCount[1]);

	if (test_state.handCount[0] == 9 && test_state.numBuys == 2 && test_state.discardCount[0] == 1)
	{
		printf("(Test #1 passed unit test!)\n\n");
	}
	else
	{
		printf("(Test #1 failed unit test!)\n\n");
	}
	/*End Test 1*/

	return 0;
}