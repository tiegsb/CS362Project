/*******************************************************************
 Author: CHIA, YiXuan
 Title:  unittest4.c
 Desc:   Testing isGameOver() function in dominion.c using unit test
 Course: CS362 Fall 2015
 *******************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>

//Set TEST_MODE to 0 to remove printfs from output
#define TEST_MODE 1

int main() {
	int i, j;
	int seed = 2000;
	int num_player = 2;
	int k[10] = { adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall };
	struct gameState test_state;

	int test_supply[6];

	int r_result[3] = { 0, 0, 0 };

	int r_expected[3] = { 0, 0, 0 };

	test_supply[0] = province;
	test_supply[1] = estate;
	test_supply[2] = smithy;
	test_supply[3] = gold;
	test_supply[4] = copper;
	test_supply[5] = curse;

#if (TEST_MODE == 1)
	printf("START TESTING isGameOver():\n");
#endif

	/*Test 1: Province exist in supply pile*/
	/*Clear game state*/
	memset(&test_state, 23, sizeof(struct gameState));
	/*Initialize game*/
	initializeGame(num_player, k, seed, &test_state);

	//Set custom cards to supply pile
	for (i = 0; i < 6; i++)
	{
		test_state.supplyCount[test_supply[i]] = 1;
	}

	r_result[0] = isGameOver(&test_state);

	r_expected[0] = 0;
	/*End Test 1*/

	/*Test 2: Few cards remaining in supply pile except province*/
	/*Clear game state*/
	memset(&test_state, 23, sizeof(struct gameState));
	/*Initialize game*/
	initializeGame(num_player, k, seed, &test_state);

	//Set custom cards to supply pile
	for (i = 0; i < 6; i++)
	{
		test_state.supplyCount[test_supply[i]] = 1;
	}

	//Remove province from supply pile
	test_state.supplyCount[province] = 0;

	r_result[1] = isGameOver(&test_state);

	r_expected[1] = 1;
	/*End Test 2*/

	/*Test 3: No card remaining in supply pile */
	/*Clear game state*/
	memset(&test_state, 23, sizeof(struct gameState));
	/*Initialize game*/
	initializeGame(num_player, k, seed, &test_state);

	for (i = 0; i < 25; i++)
	{
		test_state.supplyCount[i] = 0;
	}

	r_result[2] = isGameOver(&test_state);

	r_expected[2] = 1;
	/*End Test 2*/

#if (TEST_MODE == 1)
	/*Display Test Results: Test by return value*/
	for (j = 0; j < 3; j++)
	{
		printf("Game Over Test %d:\n", j + 1);
		printf("Return Value: %d, Expected Return Value: %d\t\t", r_result[j], r_expected[j]);
		if (r_expected[j] == r_result[j]){
			printf("Test #%d passed unit test!\n\n", j + 1);
		}
		else{
			printf("Test #%d failed unit test!\n\n", j + 1);
		}
	}
#endif

	return 0;
}
