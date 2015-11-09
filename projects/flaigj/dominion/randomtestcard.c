/*
 * Author: Jason Flaig
 * asrandomtestcard.c
 * Date: 11/7/2015
 * Modified: 11/8/2015
 * Purpose: Use random number of cards in hand to determine whether cutpurse succeeds 
 *  in adding 2 coins for player and testing whether played and discards are correct
 */

#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>
#include <time.h>

/* Checks current gamestate to old gamestate when verifying tests */
int cutpurseTest(struct gameState *post, int player)
{
	int failCount = 0;
	int copperTest = 1;
	int discardTest = 1;
	int discardPlayedCardTest = 1;
	int coinTest = 1;
	int preCopperCount[4] = {0, 0, 0, 0};		// counts for each players copper
	int postCopperCount[4] = {0, 0, 0, 0};
	struct gameState pre;
	int temphand[MAX_HAND];
	memcpy(&pre, post, sizeof(struct gameState));
	int handPos = -1;
	int myPlayers[] = {0, 1, 2, 3};		// initialized positions, uneeded each val is -1

	int i;
	// find hand position of cutpurse
	for (i = 0; i < post->handCount[player]; i++)
	{
		if (post->hand[player][i] == cutpurse)
			handPos = i;
	}

	cardEffect(cutpurse, 0, 0, 0, post, handPos, 0);

	/* Check all oponents of player to determine if player had a copper card 
	was it removed */
	// provide exclusion for current player
	// check pre gamestate of all players against post gamestate
	// check for difference of 1 in copper
	int p;
	for (p = 0; p < 4; p++)
	{
		if (p != player)		// exclusion of current player
		{
			for (i = 0; i < pre.handCount[p]; i++)
			{
				if (pre.hand[p][i] == copper)
				{
					myPlayers[p] = -1;		// if copper in hand include player for fail checking
					preCopperCount[p]++;
				}
			}

			for (i = 0; i < post->handCount[p]; i++)
			{
				if (post->hand[p][i] == copper)
					postCopperCount[p]++;
			}
		}	
	}
	
	for (p = 0; p < 4; p++)
	{
		if (p != player)		// exclusion of current player
		{
			if (p != myPlayers[p])		// exclude other players in test if never had coppers
			{
				if ((preCopperCount[p] - postCopperCount[p]) != 1)
				{
					copperTest = 0;
					failCount++;
				}

				/*if ((post->discardCount[p] - pre.discardCount[p]) == 0)
				{
					discardTest = 0;
					failCount++;
				}*/
			}
		}
	}

	// if coin difference 2 then 2 coins added  
	if ((post->coins - pre.coins) != 2)
	{
		coinTest = 0;
		failCount++;
	}

	/*if ((post->discardCount[player] - pre.discardCount[player]) == 0)
	{
		discardPlayedCardTest = 0;
		failCount++;
	}*/

	if (failCount > 0)
	{
		if (copperTest == 0)
		{
			printf("Coppers removed test failed.\n");
		}

		if (discardTest == 0)
		{
			printf("Player discard of coppers test failed.\n");
		}
		
		if (discardPlayedCardTest == 0)
		{
			printf("Player discard played card failed.\n");
		}

		if (coinTest == 0)
		{
			printf("2 coins added to player hand failed.\n");
		}

		printf("Before Cutpurse: player = %d, hand = %d, deck = %d, discard = %d\n",
			player, pre.handCount[player], pre.deckCount[player],
			pre.discardCount[player]);

		printf("After Cutpurse: player = %d, hand = %d, deck = %d, discard = %d\n",
			player, post->handCount[player], post->deckCount[player],
			post->discardCount[player]);
	}

	return failCount;
}

/* Driver of cutpurseTest */
int main()
{
	int numFailedTests = 0;
	int numOfTests = 2000;		// base number of tests
	int myCount = 0;

   	printf("Random Test of Cutpurse.\n\n");

   	int i;
   	for (i = 0; i < numOfTests; i++)
   	{
	   	int k[10] = {adventurer, council_room, feast, gardens, mine
	      , remodel, smithy, village, baron, great_hall};
	   	struct gameState G;
	   	   		int player;
   		player = floor(Random() * 4);		// chose random player

   		initializeGame(4, k, rand(), &G); 	// initialize a new game
	   	
	   	/* 1 in 4 chance give 0 cards for high probability of testing shuffle */ 
	   	int makeInt = floor(Random() * 4);
	   	if (makeInt == 0)
	   	{
	   		G.deckCount[player] = 0;
	   		myCount++;
	   	}
	   	
	   	else
	   	{
	   		makeInt = floor(Random() * MAX_DECK);		// make random deckCount
	   		G.deckCount[player] = makeInt;
	   	}

	   	makeInt = floor(Random() * 5);					
	   	G.discardCount[player] = makeInt;
	   	
	   	makeInt = floor(Random() * MAX_HAND);
	   	G.handCount[player] = makeInt;

	   	// put cutpurse in hand
	   	makeInt = floor(Random() * G.handCount[player]);
	   	G.hand[player][makeInt] = cutpurse;

	   	numFailedTests += cutpurseTest(&G, player);
	   	memset(&G, 23, sizeof(struct gameState));  // clear the game state
   	}

   		printf("Ran %d tests and %d failed.\n", 4 * numOfTests, numFailedTests);

   		return 0;
}