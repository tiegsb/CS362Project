/*****************************************************************************
 Author: CHIA, YiXuan
 Title:  cardtest2.c
 Desc:   Testing cardEffect_adventurer() function in dominion.c using unit test
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

	char name[15];

#if (TEST_MODE == 1)
	printf("START TESTING cardEffect_adventurer():\n");
#endif

	test_hand[0] = silver;
	test_hand[1] = adventurer;
	test_hand[2] = gold;
	test_hand[3] = copper;
	test_hand[4] = copper;

	/*Test 1: pre-hand contains 5 cards, post-hand expected 6 cards after discard adventurer*/
	/*Clear game state*/
	memset(&test_state, 23, sizeof(struct gameState));
	/*Initialize game*/
	initializeGame(num_player, k, seed, &test_state);
	/*Fill hand with cards*/
	memcpy(test_state.hand[0], test_hand, sizeof(int)* hand_count);

	printf("Adventure Card Effect Test 1:\n");
	printf("Before Card Effect:\n");
	printf("Card in hand: ");
	/*Change card number to name*/
	for (i = 0; i < test_state.handCount[0]; i++){
		cardNumToName(test_state.hand[0][i], name);
		printf("\t%s", name);
	}
	printf("\nNumber of Cards:   %d\n", test_state.handCount[0]);
	printf("Number of Discard:   %d\n\n", test_state.discardCount[0]);

	cardEffect_adventurer(0, &test_state);

	printf("Ater Card Effect:\n");
	printf("Card in Hand: ");
	/*Change card number to name*/
	for (i = 0; i < test_state.handCount[0]; i++){
		cardNumToName(test_state.hand[0][i], name);
		printf("\t%s", name);
	}
	printf("\nNumber of Cards:   %d, Expected Number of Cards:   6\n", test_state.handCount[0]);
	printf("Number of Discard:   %d\n\n", test_state.discardCount[0]);

	if (test_state.handCount[0] == 6)
	{
		printf("(Test #1 passed unit test!)\n\n");
	}
	else
	{
		printf("(Test #1 failed unit test!)\n\n");
	}
	/*End Test 1*/

	/*Test 2: force to shuffle when deck count is 0*/
	/*Clear game state*/
	memset(&test_state, 23, sizeof(struct gameState));
	/*Initialize game*/
	initializeGame(num_player, k, seed, &test_state);
	/*Fill hand with cards*/
	memcpy(test_state.hand[0], test_hand, sizeof(int)* hand_count);

	test_state.deckCount[0] = 0;

	printf("Adventure Card Effect Test 2:\n");
	printf("Before Card Effect:\n");
	printf("Card in hand: ");
	/*Change card number to name*/
	for (i = 0; i < test_state.handCount[0]; i++){
		cardNumToName(test_state.hand[0][i], name);
		printf("\t%s", name);
	}
	printf("\nNumber of Cards:   %d\n", test_state.handCount[0]);
	printf("Number of Discard:   %d\n\n", test_state.discardCount[0]);

	cardEffect_adventurer(0, &test_state);

	printf("Ater Card Effect:\n");
	printf("Card in Hand: ");
	/*Change card number to name*/
	for (i = 0; i < test_state.handCount[0]; i++){
		cardNumToName(test_state.hand[0][i], name);
		printf("\t%s", name);
	}
	printf("\nNumber of Cards:   %d, Expected Number of Cards:   6\n", test_state.handCount[0]);
	printf("Number of Discard:   %d\n\n", test_state.discardCount[0]);

	if (test_state.handCount[0] == 6)
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