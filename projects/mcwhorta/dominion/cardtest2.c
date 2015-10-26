#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>

#define DEBUG 0
#define NOISY_TEST 1

int testGreat_Hall(int handPos, int player, struct gameState *state)
{
	struct gameState pre;
	int currentPlayer = player;
	memcpy(&pre, state, sizeof(struct gameState));
	int card = great_hall;

	SelectStream(2);
	PutSeed(3);

	int result = cardEffect(card, 0, 0, 0, &pre, handPos, 0);
	drawCard(currentPlayer, state);
	//+1 Actions
	state->numActions++;

	//discard card from hand
	discardCard(handPos, currentPlayer, state, 0);
	assert(result==0);
	assert(memcmp(&pre, state, sizeof(struct gameState)) == 0);
	return 0;
}

int main()
{
	struct gameState game;
	int player;
	int i;
	int n;

	printf("Testing great_hall card.\n");
	printf("RANDOM TESTS.\n");

	SelectStream(2);
	PutSeed(3);

	for (n = 0; n < 2000; n++)
	{
		for (i = 0; i < sizeof(struct gameState); i++)
		{
			((char*) &game)[i] = floor(Random() * 256);
		}
		int numberOfPlayers = floor(Random() * 6);
		player = floor(Random() * numberOfPlayers);

		game.deckCount[player] = floor(Random() * MAX_DECK);
		game.discardCount[player] = floor(Random() * MAX_DECK);
		game.handCount[player] = floor(Random() * MAX_HAND);
		game.playedCardCount = floor(Random() * MAX_DECK);
		int handPos = floor(Random() * game.handCount[player]);
		game.numActions = 0;
		game.whoseTurn = player;
		game.numPlayers = numberOfPlayers;
		testGreat_Hall(handPos, player, &game);
	}

	printf("ALL TESTS OK\n");
	return 0;
}
