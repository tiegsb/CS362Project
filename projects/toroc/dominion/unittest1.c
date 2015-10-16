/*
*	CS362 - Assignment 3
*	Unit Test #1: This program ensures the updateCoins method
*		in dominion is working properly.
*	Author: Carol D. Toro
*	Date: 10/15/2015
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

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int checkUpdateCoins(int player, struct gameState *state, int bonus);
int main()
{
	int i, p, bonus, handCount;
	int k[10] = { adventurer, council_room, feast, gardens, mine,
		remodel, smithy, village, baron, great_hall };
	int gameSeed;
	int numPlayer;
	struct gameState G;
	int value;
	srand(time(NULL));

	numPlayer = 2;

	/*generate random coins for player's hand*/
	int treasureCard;

	/*Random Hands*/
	int randHand1[MAX_HAND];
	int randHand2[MAX_HAND];
	int randHand3[MAX_HAND];
	int randHand4[MAX_HAND];

	for (i = 0; i < MAX_HAND; i++)
	{
		treasureCard = rand() % 3;
		if (treasureCard == 0)
		{
			randHand1[i] = copper;
			randHand2[i] = gold;

			randHand3[i] = silver;
			randHand4[i] = copper;
		}
		else if (treasureCard == 1)
		{
			randHand1[i] = silver;
			randHand2[i] = silver;

			randHand3[i] = gold;
			randHand4[i] = gold;

		}
		else if (treasureCard == 2)
		{
			randHand1[i] = gold;
			randHand2[i] = copper;
			randHand3[i] = copper;
			randHand4[i] = copper;
		}
	}


	/*keep track of how much the coins are*/
	int b;
	int cardNum;

	cardNum = rand() % MAX_HAND;
	handCount = rand() % cardNum;

	for (b = 0; b < handCount; b++)
	{
		for (p = 0; p < numPlayer; p++)
		{
			bonus = rand() % 9;
			gameSeed = rand() % 10000;
#if (NOISY_TEST==1)
			printf("Round %d : Test player %d with treasure card(s) and %d bonus.\n", b+1, p, bonus);
#endif
			memset(&G, 23, sizeof(struct gameState));   // clear the game state
			/*initialize game and randomly load hand*/
			initializeGame(numPlayer, k, gameSeed, &G);

			int setHand;
			setHand = rand() % 4;


			if (setHand == 0)
			{
				/*Set all cards to randHand1*/
				memcpy(G.hand[p], randHand1, sizeof(int) * handCount);
#if (NOISY_TEST==1)
				printf("\t Setting hand to randhand1 \n");
#endif
			}
			else if (setHand == 1)
			{
				memcpy(G.hand[p], randHand2, sizeof(int) * handCount);
#if (NOISY_TEST==1)
				printf("\t Setting hand to randhand2 \n");
#endif
			}
			else if (setHand == 2)
			{
				memcpy(G.hand[p], randHand3, sizeof(int)* handCount);
#if (NOISY_TEST==1)
				printf("\t Setting hand to randhand3 \n");
#endif
			}
			else if (setHand == 3)
			{
				memcpy(G.hand[p], randHand4, sizeof(int)* handCount);
#if (NOISY_TEST==1)
				printf("\t Setting hand to randhand4 \n");
#endif
			}

			updateCoins(p, &G, bonus);
			value = checkUpdateCoins(p, &G, bonus);
#if (NOISY_TEST==1)
			printf("\t G.coins = %d, Expected = %d\n", G.coins, value);
#endif
			assert(G.coins == value);
		}
	}
	return 0;

}

int checkUpdateCoins(int player, struct gameState *state, int bonus)
{
	int i;
	int coinValue = 0;
	int copperCount = 0;
	int silverCount = 0;
	int goldCount = 0;


	for (i = 0; i < state->handCount[player]; i++)
	{
		if (state->hand[player][i] == copper)
		{
			coinValue += 1;
			copperCount += 1;
		}
		else if (state->hand[player][i] == silver)
		{
			coinValue += 2;
			silverCount += 1;
		}
		else if (state->hand[player][i] == gold)
		{
			coinValue += 3;
			goldCount += 1;
		}
	}

	//add bonus
	coinValue += bonus;
#if (NOISY_TEST==1)
	printf("\t Test player %d had %d copper cards\n", player, copperCount);
	printf("\t Test player %d had %d silver cards\n", player, silverCount);
	printf("\t Test player %d had %d gold cards\n", player, goldCount);
#endif
	return coinValue;
}
