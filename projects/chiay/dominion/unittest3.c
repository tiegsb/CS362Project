/*******************************************************************
 Author: CHIA, YiXuan
 Title:  unittest3.c
 Desc:   Testing gainCard() function in dominion.c using unit test
 Course: CS362 Fall 2015
*******************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>

//Set TEST_MODE to 0 to remove printfs from output
#define TEST_MODE 1

int main() {
	int i, j, m, n;
	struct gameState test_state;

	int flag;

	int test_pos[6];

	int r_result[24];

	int gain_count[3];

	test_pos[0] = baron;
	test_pos[1] = smithy;
	test_pos[2] = silver;
	test_pos[3] = copper;
	test_pos[4] = adventurer;
	test_pos[5] = mine;

#if (TEST_MODE == 1)
	printf("START TESTING gainCard():\n");
#endif


	//Test supply pile empty
	flag = -1;

	for (i = 0; i < 6; i++){
		r_result[i] = gainCard(test_pos[i], &test_state, flag, 0);
	}

	//Test discard, flag = 0
	for (m = 0; m < 6; m++){
		test_state.supplyCount[test_pos[m]] = 1;
	}

	flag = 0;
	test_state.discardCount[0] = 0;
	j = 6;

	for (i = 0; i < 6; i++){
		r_result[j] = gainCard(test_pos[i], &test_state, flag, 0);
		j++;
	}

	gain_count[0] = test_state.discardCount[0];

	//Test add to deck, flag = 1
	for (m = 0; m < 6; m++){
		test_state.supplyCount[test_pos[m]] = 1;
	}

	flag = 1;
	test_state.deckCount[0] = 0;

	for (i = 0; i < 6; i++){
		r_result[j] = gainCard(test_pos[i], &test_state, flag, 0);
		j++;
	}

	gain_count[1] = test_state.deckCount[0];

	//Test add to hand, flag = 2
	for (m = 0; m < 6; m++){
		test_state.supplyCount[test_pos[m]] = 1;
	}

	flag = 2;
	test_state.handCount[0] = 0;

	for (i = 0; i < 6; i++){
		r_result[j] = gainCard(test_pos[i], &test_state, flag, 0);
		j++;
	}

	gain_count[2] = test_state.handCount[0];

#if (TEST_MODE == 1)
	for (n = 0; n < 24; n++){
		if (n >= 0 && n < 6){
			printf("Gain Card Test %d:\n", n + 1);
			printf("Return Value: %d, Expected Return Value: -1\t\t", r_result[n]);
			if (r_result[n] == -1){
				printf("Test #%d passed unit test!\n\n", n + 1);
			}
			else{
				printf("Test #%d failed unit test!\n\n", n + 1);
			}
		}
		else if (n >= 6 && n < 12){
			printf("Gain Card Test %d:\n", n + 1);
			printf("Gain: %d, Expected Gain: 6\t\t\t\t", gain_count[0]);
			if (gain_count[0] == 6){
				printf("Test #%d passed unit test!\n\n", n + 1);
			}
			else{
				printf("Test #%d failed unit test!\n\n", n + 1);
			}
		}
		else if (n >= 12 && n < 18){
			printf("Gain Card Test %d:\n", n + 1);
			printf("Gain: %d, Expected Gain: 6\t\t\t\t", gain_count[1]);
			if (gain_count[1] == 6){
				printf("Test #%d passed unit test!\n\n", n + 1);
			}
			else{
				printf("Test #%d failed unit test!\n\n", n + 1);
			}
		}
		else if (n >= 18 && n < 24){
			printf("Gain Card Test %d:\n", n + 1);
			printf("Gain: %d, Expected Gain: 6\t\t\t\t", gain_count[2]);
			if (gain_count[2] == 6){
				printf("Test #%d passed unit test!\n\n", n + 1);
			}
			else{
				printf("Test #%d failed unit test!\n\n", n + 1);
			}
		}
	}
#endif

	return 0;
}