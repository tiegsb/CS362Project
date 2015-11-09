/*************************************************************************************************
Author: CHIA, YiXuan
Title:  randomtestcard.c
Desc:   Testing village switch case under cardEffect() function in dominion.c using random test
Course: CS362 Fall 2015
*************************************************************************************************/

#include "interface.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

//Set TEST_MODE to 0 to remove printfs from output
#define TEST_MODE 1

int main() {

	//Set random seed
	srand(time(NULL));

	int i, j, pass = 0, fail = 0, check_card = 0;
	int seed = 2000;
	int num_player = 2, num_test, pre_handCount, post_handCount
		, pre_action, post_action, pre_discard, post_discard;
	int k[10] = { adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall };

	int t[3] = { copper, silver, gold };
	struct gameState test_state;

	char name[15];

#if (TEST_MODE == 1)
	printf("START TESTING village cardEffect:\n");
#endif

	/*Randomize number of test for running at least 2000 times*/
	num_test = rand() % 10000 + 2000;

	for (i = 0; i < num_test; i++){

		/*Clear game state*/
		memset(&test_state, 23, sizeof(struct gameState));
		/*Initialize game*/
		initializeGame(num_player, k, seed, &test_state);

		/*Set up player's hand, deck, and discard*/
		test_state.handCount[0] = rand() % 3 + 1;
		test_state.deckCount[0] = rand() % MAX_DECK + 2;
		test_state.discardCount[0] = rand() % 5 + 1;

		/*Set player's hand holding village card + treasure cards*/
		test_state.hand[0][0] = village;

		for (j = 1; j < test_state.handCount[0]; j++){
			test_state.hand[0][j] = t[rand() % 3];
		}

		for (j = 0; j < test_state.deckCount[0]; j++){
			test_state.deck[0][j] = rand() % 5;
		}

		for (j = 0; j < test_state.discardCount[0]; j++){
			test_state.discard[0][j] = t[rand() % 3];
		}

		/*Shuffle cards*/
		shuffle(0, &test_state);

		/*Display data before play village card*/
		printf("\nVillage Card Effect Test %d:\n", i + 1);
		printf("Before Card Effect:\n");
		printf("Card in hand: ");
		/*Change card number to name*/
		for (j = 0; j < test_state.handCount[0]; j++){
			cardNumToName(test_state.hand[0][j], name);
			printf("\t%s", name);
		}
		printf("\nNumber of Cards:   %d\n", test_state.handCount[0]);
		printf("Number of Actions:   %d\n", test_state.numActions);
		printf("Number of Discard:   %d\n\n", test_state.discardCount[0]);

		/*Get data before discard*/
		pre_handCount = test_state.handCount[0];
		pre_action = test_state.numActions;
		pre_discard = test_state.discardCount[0];

		/*Call cardEffect function for village case to play card*/
		cardEffect(village, 0, 0, 0, &test_state, 0, 0);

		/*Display data after play village card*/
		printf("After Card Effect:\n");
		printf("Card in Hand: ");
		/*Change card number to name*/
		for (j = 0; j < test_state.handCount[0]; j++){
			cardNumToName(test_state.hand[0][j], name);
			printf("\t%s", name);
		}
		printf("\nNumber of Cards:   %d, Expected Number of Cards:   %d\n", test_state.handCount[0], pre_handCount);
		printf("Number of Actions:   %d, Expected Number of Action:   %d\n", test_state.numActions, pre_action + 2);
		printf("Number of Discard:   %d, Expected Number of Discard:   %d\n\n", test_state.discardCount[0], pre_discard + 1);

		/*Get data after discard*/
		post_handCount = test_state.handCount[0]; 
		post_action = test_state.numActions;
		post_discard = test_state.discardCount[0];

		/*Display tests results*/
		if (post_handCount - pre_handCount == 0 && post_action - pre_action == 2 && post_discard - pre_discard == 1)
		{
			printf("(Test #%d passed random test!)\n\n", i + 1);
			pass++;
		}
		else
		{
			printf("(Test #%d failed unit test!)\n\n", i + 1);
			fail++;
		}
		/*End Random Test*/
	}

	printf("\nTotal of Test Passed: %d\t\t Total of Test failed: %d\n", pass, fail);

	return 0;
}