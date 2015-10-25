/*****************************************************************************
 Author: CHIA, YiXuan
 Title:  cardtest1.c
 Desc:   Testing cardEffect_smithy() function in dominion.c using unit test
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
	printf("START TESTING cardEffect_smithy():\n");
#endif
	
	test_hand[0] = silver;
	test_hand[1] = smithy;
	test_hand[2] = gold;
	test_hand[3] = copper;
	test_hand[4] = copper;

	test_hand2[0] = adventurer;
	test_hand2[1] = copper;
	test_hand2[2] = gold;
	test_hand2[3] = smithy;
	test_hand2[4] = gardens;

	/*Test 1: pre-hand contains 5 cards, post-hand expected 7 cards after discard smithy*/
	/*Clear game state*/
	memset(&test_state, 23, sizeof(struct gameState));
	/*Initialize game*/
	initializeGame(num_player, k, seed, &test_state);
	/*Fill hand with cards*/
	memcpy(test_state.hand[0], test_hand, sizeof(int)* hand_count);

	printf("Smithy Card Effect Test 1:\n");
	printf("Before Discard:\n");
	printf("Card in hand: ");
	/*Change card number to name*/
	for (i = 0; i < test_state.handCount[0]; i++){
		cardNumToName(test_state.hand[0][i], name);
		printf("\t%s", name);
	}
	printf("\nNumber of Cards:   %d\n\n", test_state.handCount[0]);

	cardEffect_smithy(1, 0, &test_state);
	
	printf("Ater Discard:\n");
	printf("Card in Hand: ");
	/*Change card number to name*/
	for (i = 0; i < test_state.handCount[0]; i++){
		cardNumToName(test_state.hand[0][i], name);
		printf("\t%s", name);
	}
	printf("\nNumber of Cards:   %d, Expected Number of Cards:   7\n", test_state.handCount[0]);

	if (test_state.handCount[0] == 7)
	{
		printf("(Test #1 passed unit test!)\n\n");
	}
	else
	{
		printf("(Test #1 failed unit test!)\n\n");
	}
	/*End Test 1*/

	/*Test 2: pre-hand contains 5 cards, post-hand expected 7 cards after discard smithy*/
	/*Clear game state*/
	memset(&test_state, 23, sizeof(struct gameState));
	/*Initialize game*/
	initializeGame(num_player, k, seed, &test_state);
	/*Fill hand with cards*/
	memcpy(test_state.hand[0], test_hand2, sizeof(int)* hand_count);

	printf("Smithy Card Effect Test 2:\n");
	printf("Before Discard:\n");
	printf("Card in hand: ");
	/*Change card number to name*/
	for (i = 0; i < test_state.handCount[0]; i++){
		cardNumToName(test_state.hand[0][i], name);
		printf("\t%s", name);
	}
	printf("\nNumber of cards:   %d\n\n", test_state.handCount[0]);

	cardEffect_smithy(3, 0, &test_state);

	printf("Ater Discard:\n");
	printf("Card in hand: ");
	/*Change card number to name*/
	for (i = 0; i < test_state.handCount[0]; i++){
		cardNumToName(test_state.hand[0][i], name);
		printf("\t%s", name);
	}
	printf("\nNumber of Cards:   %d, Expected Number of Cards:   7\n", test_state.handCount[0]);

	if (test_state.handCount[0] == 7)
	{
		printf("(Test #2 passed unit test!)\n\n");
	}
	else
	{
		printf("(Test #2 failed unit test!)\n\n");
	}
	/*End Test 2*/
	return 0;
}
