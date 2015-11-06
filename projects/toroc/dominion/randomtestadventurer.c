/*
*	CS362 - Assignment 4       randomtestadventurer.c
*	Random Test Adventurer: This program ensures the updateCoins method
*		in dominion is working properly.
*	Author: Carol D. Toro
*	Date: 10/27/2015
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
int treasureCountDeck(int player, struct gameState *state);
int treasureCountDiscard(int player, struct gameState *state);
int randTest1();
// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1
int main ()
{

	srand(time(NULL));

	randTest1();
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
int getTreasureCount(int player, struct gameState *state)
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
int treasureCountDeck(int player, struct gameState *state)
{
	int i, treasureCount = 0;

	/*calculate count of treasures*/
	for (i = 0; i < state->deckCount[player]; i++)
	{
		if (state->deck[player][i] == copper || state->deck[player][i] == silver || state->deck[player][i] == gold)
		{
			treasureCount += 1;
		}

	}

	return treasureCount;
}

int treasureCountDiscard(int player, struct gameState *state)
{
	int i, treasureCount = 0;

	/*calculate count of treasures*/
	for (i = 0; i < state->discardCount[player]; i++)
	{
		if (state->discard[player][i] == copper || state->discard[player][i] == silver || state->discard[player][i] == gold)
		{
			treasureCount += 1;
		}
	}
	return treasureCount;
}

int randTest1()
{
	int	i, round;

	int k[10] = { adventurer, council_room, feast, gardens, mine,
		remodel, smithy, village, baron, great_hall };
	int gameSeed, preTestHandCount, preTestDeckCount, preTestDiscardCount, posTestHandCount, posTestDeckCount, posTestDiscardCount;
	int numPlayer = 4;
	struct gameState Game;
	int preTestCoinValue, posTestCoinValue, preTestCoinCount, posTestCoinCount, deckTreasureCount, discardTreasureCount;
	int preTestActions, preTestBuys, posTestActions, posTestBuys;
	int	errorCoinValue = 0,
		errorHand = 0,
		errorDeck = 0,
		errorCoinCount = 0,
		errorDiscard = 0,
		errorActions = 0,
		errorBuys = 0,
		error1Treasure = 0;
	
	/*Starting Test #1*/
#if (NOISY_TEST==1)
	printf("\n Starting Random Test #1 on Adventurer \n");
	printf("\t Test ensures player receives appropriate treasure cards, \n");
	printf("\t player receives correct value of treasure cards, \n");
	printf("\t handCount increases for player, cards are drawm from player's deck, \n");
	printf("\t and cards are discarded to the player's discard deck. \n");
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
		initializeGame(numPlayer, k, gameSeed, &Game);

		/*Get random player for test*/
		int testPlayer = rand() % numPlayer;

		/*Get & assign random counts for hand, deck, and discard*/
		Game.handCount[testPlayer] = rand() % MAX_HAND + 1;
		Game.deckCount[testPlayer] = rand() % MAX_DECK + 1;
		Game.discardCount[testPlayer] = rand() % MAX_DECK + 1;

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
		/*Assign random cards to discard based on discardCount*/
		for (i = 0; i < Game.discardCount[testPlayer]; i++)
		{
			Game.discard[testPlayer][i] = rand() % 27;
		}

		int randNum = rand() % 5;

		/*randomly shuffle the cards*/
		if (randNum == 3)
		{
			shuffle(testPlayer, &Game);
		}

		/*Make the first two card in hand an adventurer*/
		Game.hand[testPlayer][0] = adventurer;
		Game.hand[testPlayer][1] = adventurer;

		/*Get count of hand, deck, discard before ADVENTURER*/
		preTestHandCount = Game.handCount[testPlayer];
		preTestDeckCount = Game.deckCount[testPlayer];
		preTestDiscardCount = Game.discardCount[testPlayer];

		/*Get value of current treasures in players hand*/
		preTestCoinValue = getTreasureValue(testPlayer, &Game);

		/*Get the count of treasures in player's hand*/
		preTestCoinCount = getTreasureCount(testPlayer, &Game);

		/*Get the count of treasures in player's deck*/
		deckTreasureCount = treasureCountDeck(testPlayer, &Game);
		
		/*Get the count of treasures in player's discard*/
		discardTreasureCount = treasureCountDiscard(testPlayer, &Game);

		/*Get count of actions and buys before ADVENTURER*/
		preTestActions = Game.numActions;
		preTestBuys = Game.numBuys;

		/*had to hardcode this so that it would draw cards from correct player's deck*/
		Game.whoseTurn = testPlayer;

		updateCoins(testPlayer, &Game, 0);

		/*Play the adventurer card*/
		playCard(0, 1, 2, 3, &Game);

		updateCoins(testPlayer, &Game, 0);
		/*Get value of treasures after ADVENTURER*/
		posTestCoinValue = getTreasureValue(testPlayer, &Game);

		/*Get the count of treasures in player's hand after ADVENTURER*/
		posTestCoinCount = getTreasureCount(testPlayer, &Game);

		/*Get values of hand, deck, and discard count after ADVENTURER*/
		posTestHandCount = Game.handCount[testPlayer];
		posTestDeckCount = Game.deckCount[testPlayer];
		posTestDiscardCount = Game.discardCount[testPlayer];

		/*Get count of actions and buys after ADVENTURER*/
		posTestActions = Game.numActions;
		posTestBuys = Game.numBuys;

		/*user could only draw one treasure*/
		if (deckTreasureCount + discardTreasureCount < 2)
		{
			//printf("Player only had one treasure in their deck and discard piles \n");

			//printf("treasures in deck: %d treasures in discard: %d \n", deckTreasureCount, discardTreasureCount);
			error1Treasure++;

			if (deckTreasureCount == 1)
			{
				if (preTestCoinCount + 1 != posTestCoinCount)
				{
					errorCoinCount++;
				}
				if (preTestCoinValue + 1 > posTestCoinValue)
				{
					errorCoinValue++;
				}
			}
			
			if (discardTreasureCount == 1)
			{
				if (preTestCoinCount + 1 != posTestCoinCount)
				{
					errorCoinCount++;
				}
				if (preTestCoinValue + 1 > posTestCoinValue)
				{
					errorCoinValue++;
				}
			}

			///*Keep count of errors when coin count does not increase by 2*/
			//if (preTestCoinCount + 1 != posTestCoinCount)
			//{
			//	/*printf("Round # : %d \n", round);
			//	printf("Error with coin count after Adventurer occurred. \n");
			//	printf("\t Current coin count: %d \t Expected coin count: %d \n", posTestCoinCount, preTestCoinCount + 1);
			//	printf("\t pre coin count %d \t post coin count %d \n", preTestCoinCount, posTestCoinCount);*/
			//	errorCoinCount++;

			//}
			///*Keep count of errors when coin value doesn't increase by at least 2*/
			//if (preTestCoinValue + 1 > posTestCoinValue)
			//{
			//	/*printf("Round # : %d \n", round);
			//	printf("Error in the value of treasure cards received \n");
			//	printf("\t Current coin value: %d \t Expected coin value to be greater or equal to: %d \n", posTestCoinValue, preTestCoinCount + 1);
			//	printf("\t pre coin value %d \t post coin value %d \n", preTestCoinValue, posTestCoinValue);*/
			//	errorCoinValue++;
			//}

			///*keep count of error when hand count is not increased by 2*/
			//if (preTestHandCount + 1 != posTestHandCount)
			//{
			//	/*printf("Round # : %d \n", round);
			//	printf("Error in the player's handcount \n");
			//	printf("\t Current hand count: %d \t Expected hand count: %d \n", posTestHandCount, preTestHandCount + 1);
			//	printf("\t pre hand value %d \t post hand value %d \n", preTestHandCount, posTestHandCount);*/
			//	errorHand++;
			//}
		}
		else
		{
			/*Keep count of errors when coin count does not increase by 2*/
			if (preTestCoinCount + 2 != posTestCoinCount)
			{
				/*printf("Round # : %d \n", round);
				printf("Error with coin count after Adventurer occurred. \n");
				printf("\t Current coin count: %d \t Expected coin count: %d \n", posTestCoinCount, preTestCoinCount + 2);
				printf("\t pre coin count %d \t post coin count %d \n", preTestCoinCount, posTestCoinCount);*/
				errorCoinCount++;

			}
			/*Keep count of errors when coin value doesn't increase by at least 2*/
			if (preTestCoinValue + 2 > posTestCoinValue)
			{
				//printf("Round # : %d \n", round);
				//printf("Error in the value of treasure cards received \n");
				//printf("\t Current coin value: %d \t Expected coin value to be greater or equal to: %d \n", posTestCoinValue, preTestCoinCount + 2);
				//printf("\t pre coin value %d \t post coin value %d \n", preTestCoinValue, posTestCoinValue);
				errorCoinValue++;
			}

			/*keep count of error when hand count is not increased by 2*/
			if (preTestHandCount + 2 != posTestHandCount)
			{
				//printf("Round # : %d \n", round);
				/*printf("Error in the player's handcount \n");
				printf("\t Current hand count: %d \t Expected hand count: %d \n", posTestHandCount, preTestHandCount + 2);
				printf("\t pre hand value %d \t post hand value %d \n", preTestHandCount, posTestHandCount);*/
				errorHand++;
			}


			/*keep count of errors when cards drawn are not drawn from player's deck*/
			if ((preTestDiscardCount - posTestDiscardCount ==2) && (preTestDeckCount != posTestDeckCount))
			{
				//printf("Round # : %d \n", round);
				/*printf("\t Error player's deck remain unchanged \n");
				printf("\t pre deck value %d \t post deck value %d \n", preTestDeckCount, posTestDeckCount);*/
				errorDeck++;
			}

			/*Keep count of errors when cards are not discarded to the player's discard deck*/
			if ((preTestDeckCount - posTestDeckCount == 2) && preTestDiscardCount != posTestDiscardCount)
			{
				//printf("Round # : %d \n", round);
				/*printf("\t Error player's discard remain unchanged \n");
				printf("\t pre discard value %d \t post discard value %d \n", preTestDiscardCount, posTestDiscardCount);*/
				errorDiscard++;
			}

			/*Keep count of errors when actions doesn't go down to 0*/
			if (posTestActions != 0)
			{
				/*printf("Round # : %d \n", round);
				printf("Error with action count after Adventurer occurred. \n");
				printf("\t Current action count: %d \t Expected action count: %d \n", posTestActions, preTestActions - 1);*/
				errorActions++;
			}

			/*Keep count of errors when buys doesn't stay at 1*/
			if (posTestBuys != 1)
			{
				/*printf("Round # : %d \n", round);
				printf("Error with Buys count after Adventurer occurred. \n");
				printf("\t Current buy count: %d \t Expected buy count: %d \n", posTestBuys, preTestBuys);*/
				errorBuys++;
			}
		}
		
	}

	/*Print out test #1 results*/
	printf("Random Test #1 completed for adventurerCard() implementation. \n");
	printf("Test Results for %d rounds: \n", numRounds);
	printf(" # of times player only had 1 treasure in deck+discard was %d \n", error1Treasure);
	printf(" Errors with coin count after Adventurer was %d \n", errorCoinCount);
	printf(" Errors with coin value after Adventurer was %d \n", errorCoinValue);
	printf(" Errors with hand count after Adventurer was %d \n", errorHand);
	printf(" Errors with player's deck after Adventurer was %d \n", errorDeck);
	printf(" Errors with player's discard deck was %d \n", errorDiscard);
	printf(" Errors with Action count after Adventurer was %d \n", errorActions);
	printf(" Errors with Buy value after Adventurer was %d \n", errorBuys);

	return 0;
	
}


	
	
