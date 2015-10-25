/***************************************************************************************
 Author: CHIA, YiXuan
 Title:  cardtest4.c
 Desc:   Testing great_hall case under cardEffect function in dominion.c using unit test
 Course: CS362 Fall 2015
***************************************************************************************/

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
	printf("START TESTING great_hall case under cardEffect():\n");
#endif

	test_hand[0] = silver;
	test_hand[1] = great_hall;
	test_hand[2] = gold;
	test_hand[3] = copper;
	test_hand[4] = copper;

	/*Test 1: Player gain 1 cards and 1 action, then discard great_hall*/
	/*Clear game state*/
	memset(&test_state, 23, sizeof(struct gameState));
	/*Initialize game*/
	initializeGame(num_player, k, seed, &test_state);
	/*Fill hand with cards*/
	memcpy(test_state.hand[0], test_hand, sizeof(int)* hand_count);

	printf("Great Hall Card Effect Test 1:\n");
	printf("Before Card Effect:\n\n");
	//Show cards in player 1's hand 
	printf("Card in player 1's hand: ");

	/*Change card number to name*/
	for (i = 0; i < test_state.handCount[0]; i++){
		cardNumToName(test_state.hand[0][i], name);
		printf("\t%s", name);
	}
	printf("\nNumber of Cards:   %d\n", test_state.handCount[0]);
	printf("Number of Actions:   %d\n", test_state.numActions);

	//Call function cardEffect()
	cardEffect(great_hall, 0, 0, 0, &test_state, 1, 0);

	printf("Ater Card Effect:\n\n");
	printf("Card in player 1's hand: ");

	/*Change card number to name*/
	for (i = 0; i < test_state.handCount[0]; i++){
		cardNumToName(test_state.hand[0][i], name);
		printf("\t%s", name);
	}
	printf("\nNumber of Cards:   %d, Expected Number of Cards:   5\n", test_state.handCount[0]);
	printf("Number of Actions:   %d\n\n", test_state.numActions);

	if (test_state.handCount[0] == 5 && test_state.numActions == 2)
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