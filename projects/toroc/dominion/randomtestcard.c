/*
*	CS362 - Assignment 4       randomtestcard.c
*	Random Test Card: This program runs a random iteration
*		of random tests against the implementation of the Steward
*		card. 
*	Author: Carol D. Toro
*	Date: 10/30/2015
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

int getTreasureValue(int player, struct gameState *state);
int getTreasureCounts(int player, struct gameState *state);
// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1
int main ()
{

	srand(time(NULL));

	int	i, round, result;

	int k[10] = { adventurer, council_room, feast, gardens, mine,
		remodel, smithy, village, baron, great_hall };
	int gameSeed, preTestHandCount, preTestDeckCount, preTestDiscardCount, posTestHandCount, posTestDeckCount, posTestDiscardCount;
	int numPlayer = 4, testChoice1, testChoice2, testChoice3;
	struct gameState Game;
	int preTestCoinValue, preTestCoinCount; 
	int preTestActions, preTestBuys, posTestActions, posTestBuys;
	int	errorCoinGain = 0,
		errorCardGain = 0,
		errorCardDiscard = 0,
		errorStewardDiscard = 0,
		errorActions = 0,
		errorBuys = 0,
		errorHandCount = 0;


	/*Starting Test #2*/
#if (NOISY_TEST==1)
	printf("\n Starting Random Test #2 on Steward \n \n");
	printf("\t This random test looks for the following errors: \n");
	printf("\t errors with coin gained after Steward, \n");
	printf("\t errors with cards discarded after Steward, \n");
	printf("\t errors with Steward discard, \n");
	printf("\t errors with hand count after Steward, \n");
	printf("\t errors with action count, \n");
	printf("\t and errors with buy count after Steward. \n \n");
#endif


	/*Get random number of round each time test is run*/
	int numRounds = rand() % 20000 + 8000;
	for (round = 0; round < numRounds; round++)
	{
		/*initialize gameSeed*/
		gameSeed = rand() % 1000 + 1;

		/*Clear the game states*/
		memset(&Game, 0, sizeof(struct gameState));

		/*Initialize game*/
		result = initializeGame(numPlayer, k, gameSeed, &Game);

		/*Get random player for test*/
		int testPlayer = rand() % numPlayer;

		/*Get & assign random counts for hand, deck, and discard*/
		Game.handCount[testPlayer] = rand() % 470 + 30;
		Game.deckCount[testPlayer] = rand() % 470 + 30;
		

		/*Assign random cards to hand based on handCount*/
		for (i = 0; i < Game.handCount[testPlayer]; i++)
		{
			Game.hand[testPlayer][i] = rand() % 27;
		}

		/*Assign random cards to deck based on deckCount*/
		for (i = 0; i < Game.deckCount[testPlayer]; i++)
		{
			Game.deck[testPlayer][i] = rand() % 27;
		}
		
		int randNum = rand() % 5;

		/*randomly shuffle the cards*/
		if (randNum == 3)
		{
			result = shuffle(testPlayer, &Game);
		}

		/*Make the first card in hand an adventurer*/
		Game.hand[testPlayer][0] = steward;

		/*Get count of hand, deck, discard before ADVENTURER*/
		preTestHandCount = Game.handCount[testPlayer];
		preTestDeckCount = Game.deckCount[testPlayer];
		preTestDiscardCount = Game.discardCount[testPlayer];

		/*Get value of current treasures in players hand*/
		preTestCoinValue = getTreasureValue(testPlayer, &Game);

		/*Get the count of treasures in player's hand*/
		preTestCoinCount = getTreasureCounts(testPlayer, &Game);


		/*Get count of actions and buys before ADVENTURER*/
		preTestActions = Game.numActions;
		preTestBuys = Game.numBuys;

		/*had to hardcode this so that it would draw cards from correct player's deck*/
		Game.whoseTurn = testPlayer;

		result = updateCoins(testPlayer, &Game, 0);

		int preTestHand[MAX_HAND] = { 0 };
		int preTestDeck[MAX_DECK] = { 0 };

		/*Copy hand before Steward*/
		for (i = 0; i < preTestHandCount; i++)
		{
			preTestHand[i] = Game.hand[testPlayer][i];
		}

		/*Copy deck before Steward*/
		for (i = 0; i < preTestDeckCount; i++)
		{
			preTestDeck[i] = Game.deck[testPlayer][i];
		}

		/*Assign random choices*/
		testChoice1 = rand() % 5 +1;
		testChoice2 = rand() % 27 +1;
		testChoice3 = rand() % 27 +1;

		while(testChoice2 == testChoice3)
		{
			testChoice3 = rand() % 27 + 1;
		}

		/*Play the adventurer card*/
		result = playCard(0, testChoice1, testChoice2, testChoice3, &Game);

		updateCoins(testPlayer, &Game, 0);
		


		/*Get values of hand, deck, and discard count */
		posTestHandCount = Game.handCount[testPlayer];
		posTestDeckCount = Game.deckCount[testPlayer];
		posTestDiscardCount = Game.discardCount[testPlayer];

		/*Get count of actions and buys after ADVENTURER*/
		posTestActions = Game.numActions;
		posTestBuys = Game.numBuys;


		if (testChoice1 == 1)
		{
			/*player should gain two cards*/
			if (preTestHandCount + 2-1 != posTestHandCount)
			{
				errorCardGain++;
			}

			/*ensure played card gets discarded*/
			if (Game.hand[testPlayer][0] != preTestHand[preTestHandCount - 1] && Game.hand[testPlayer][0] != preTestDeck[preTestDeckCount - 1] && Game.hand[testPlayer][0] != preTestDeck[preTestDeckCount - 2])
			{
				errorStewardDiscard++;
				//printf("Steward error in round#: \n ", round);
			}
		}
		else if (testChoice1 == 2)
		{
			/*player gains 2 coins*/
			if (Game.coins != preTestCoinValue+2)
			{
				errorCoinGain++;
				//printf("Round#:%d  Current coins: %d   Expected coins: %d \n", round, Game.coins, preTestCoinValue + 2);
			}
			/*ensure played card gets discarded*/
			if (Game.hand[testPlayer][0] != preTestHand[preTestHandCount - 1])
			{
				errorStewardDiscard++;
				//printf("Steward error in round#: \n ", round);
			}
		}
		else
		{
			/*choice 2 and 3 are discarded*/		
			if (Game.hand[testPlayer][testChoice2] != preTestHand[preTestHandCount - 1] && Game.hand[testPlayer][testChoice2] != -1)
			{
				errorCardDiscard++;
				/*printf("Wrond card was discarded.\n");
				printf("Card discard expected: %s ", cardNames[preTestHand[testChoice2]]);
				printf("to be replaced with %s \n", cardNames[preTestHand[preTestHandCount - 1]]);*/
			}

			if (Game.hand[testPlayer][testChoice3] != preTestHand[preTestHandCount - 2] && Game.hand[testPlayer][testChoice3] != -1)
			{
				errorCardDiscard++;
				/*printf("Wrond card was discarded.\n");
				printf("Card discard expected: %s ", cardNames[preTestHand[testChoice3]]);
				printf("to be replaced with %s \n", cardNames[preTestHand[preTestHandCount - 2]]);*/
			}

			if (preTestHandCount - 3 != posTestHandCount)
			{
				errorHandCount++;
			}

			/*player's card gets discarded as well*/
			if (Game.hand[testPlayer][0] != preTestHand[preTestHandCount - 3] && Game.hand[testPlayer][0] != preTestHand[preTestHandCount - 2] && Game.hand[testPlayer][0] != preTestHand[preTestHandCount - 1])
			{
				errorStewardDiscard++;
				//printf("Steward error in round#: \n ", round);
			}
		}
		

		if (Game.numActions != 0)
		{
			errorActions++;
		}

		if (Game.numBuys != 1)
		{
			errorBuys++;
		}
	}

	/*Print out test #2 results*/
	printf("Random Test #1 completed for steward card implementation. \n");
	printf("Test Results for %d rounds: \n", numRounds);
	printf(" Errors with card gain  after Steward was %d \n", errorCardGain);
	printf(" Errors with coin gain after Steward was %d \n", errorCoinGain);
	printf(" Errors with cards discarded after Steward was %d \n", errorCardDiscard);
	printf(" Errors with Steward discard was %d \n", errorStewardDiscard);
	printf(" Errors with hand count after Steward was %d \n", errorHandCount);
	printf(" Errors with actions after Steward was %d \n", errorActions);
	printf(" Errors with buys after Steward was %d \n", errorBuys);


	return 0;
	
}

int getTreasureValue(int player, struct gameState *state)
{
	int i, treasureValue = 0;

	/*calculate values of treasures*/
	for (i = 0; i < state->handCount[player]; i++)
	{		
		if (state->hand[player][i] == copper)
		{
			treasureValue += 1;
		}
	else if (state->hand[player][i] == silver)
		{
			treasureValue += 2;
		}
		else if (state->hand[player][i] == gold)
		{
			treasureValue += 3;
		}
	}

	return treasureValue;

}
int getTreasureCounts(int player, struct gameState *state)
{
	int i, treasureCount = 0;

	/*calculate count of treasures*/
	for (i = 0; i < state->handCount[player]; i++)
	{
		if (state->hand[player][i] == copper || state->hand[player][i] == silver || state->hand[player][i] == gold)
		{
			treasureCount += 1;
		}
		
	}

	return treasureCount;
}