/*
 * Author: Jason Flaig
 * randomtestadventurer.c
 * Date: 11/6/2015
 * Modified: 11/8/2015
 * Purpose: Use random number of cards in hand to determine whether adventurer succeeds 
 *  in providing two treasure cards and if shuffling happens when cards in hand <= 1
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

/* Checks current gamestate to old gamestate to check if shuffling happened and counts treasure cards */
int checkAdventurer(struct gameState *post, int player)
{
	int failCount = 0;
	int treasureTest = 1;
	int shuffleTest = 1;
	int drawntreasurePre = 0;
	int drawntreasurePost = 0;
	struct gameState pre;
	int temphand[MAX_HAND];
	memcpy(&pre, post, sizeof(struct gameState));

	adventurerCard(player, post, 0, 0, temphand, 0);

	/* Cases where shuffling must happen, 0 or 1 cards in deck */
	if (pre.deckCount[player] < 2)
	{
		if (post->deckCount[player] == pre.deckCount[player])
		{
			shuffleTest = 0;
			failCount++;
		}
	}

	/* Check if drawn treasure was 2 */
	// cycle through cards in pre hand and count treasures
	// cycle through cards in post hand and count treasures
	// if difference 2 then drawn treasure success
	int i;
	for (i = 0; i < pre.handCount[player]; i++)
	{
		if (pre.hand[player][i] == gold ||
			pre.hand[player][i] == silver ||
			pre.hand[player][i] == copper)
				drawntreasurePre++;
	}

	for (i = 0; i < post->handCount[player]; i++)
	{
		if (post->hand[player][i] == gold ||
			post->hand[player][i] == silver ||
			post->hand[player][i] == copper)
				drawntreasurePost++;
	}

	if ((drawntreasurePost - drawntreasurePre) != 2)
	{
		treasureTest = 0;
		failCount++;
	}

	if (failCount > 0)
	{
		if (treasureTest == 0)
		{
			printf("Treasure test failed.\n");
		}

		if (shuffleTest == 0)
		{
			printf("Shuffle test failed.\n");
		}

		printf("Before Adventurer: player = %d, hand = %d, deck = %d, discard = %d\n",
			player, pre.handCount[player], pre.deckCount[player],
			pre.discardCount[player]);

		printf("After Adventurer: player = %d, hand = %d, deck = %d, discard = %d\n",
			player, post->handCount[player], post->deckCount[player],
			post->discardCount[player]);
	}

	return failCount;
}

/* Driver of checkAdventurer */
int main()
{
	int numFailedTests = 0;
	int numOfTests = 2000;
	int myCount = 0;

   	printf("Random Test of Adventurer.\n\n");

   	int i;
   	for (i = 0; i < numOfTests; i++)
   	{
	   	int k[10] = {adventurer, council_room, feast, gardens, mine
	      , remodel, smithy, village, baron, great_hall};
	   	struct gameState G;
	   	   		int player;
   		player = floor(Random() * 2);
   		//printf("r = %d\n", player);
   		initializeGame(2, k, rand(), &G); 	// initialize a new game
	   	
	   	/* 1 in 4 chance give 0 cards for high probability of testing shuffle */ 
	   	int makeInt = floor(Random() * 4);
	   	if (makeInt == 0)
	   	{
	   		G.deckCount[player] = 0;
	   		myCount++;
	   	}
	   	
	   	else
	   	{
	   		makeInt = floor(Random() * MAX_DECK);
	   		G.deckCount[player] = makeInt;
	   	}

	   	makeInt = floor(Random() * 5);
	   	G.discardCount[player] = makeInt;
	   	makeInt = floor(Random() * MAX_HAND);
	   	G.handCount[player] = makeInt;
	   	numFailedTests += checkAdventurer(&G, player);
	   	memset(&G, 23, sizeof(struct gameState));  // clear the game state
   	}

   		printf("Ran %d tests and %d failed.\n", 2 * numOfTests, numFailedTests);

   		return 0;
}