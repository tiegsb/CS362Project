#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>

#define DEBUG 0
#define NOISY_TEST 1

int testVillage(struct gameState *game, int currentPlayer, int handPos) {
	SelectStream(3);
	PutSeed(3);

	int preHandCount = game->handCount[currentPlayer];
	int preActionCount= game->numActions;

	struct gameState pre;
	memcpy(&pre, game, sizeof(struct gameState));

	int card = village;
	int r = cardEffect(card, 0, 0, 0, game, handPos, 0);

	drawCard(currentPlayer, &pre);
	//updateCoins(currentPlayer, &pre,0);
	//+2 Actions
	pre.numActions = pre.numActions + 2;

	//discard played card from hand
	discardCard(handPos, currentPlayer, &pre, 0);

	assert(r==0);
	assert(pre.numActions== preActionCount+2);
	assert(pre.handCount[currentPlayer]== preHandCount);
	assert(memcmp(&pre, game, sizeof(struct gameState)) == 0);

	return 0;
}

int main() {
	struct gameState game;
	int player;
	int i;
	int n;
	int j;

	printf("Testing village.\n");
	printf("RANDOM TESTS.\n");

	SelectStream(3);
	PutSeed(3);

	for (n = 0; n < 5000; n++) {
		for (i = 0; i < sizeof(struct gameState); i++) {
			((char*) &game)[i] = floor(Random() * 256);
		}
		int numberOfPlayers = floor(Random() * 6);
		player = floor(Random() * numberOfPlayers);
		game.deckCount[player] = floor(Random() * MAX_DECK);
		for (j = 0; j < game.deckCount[player]; j++)
			game.deck[player][j] = floor(Random() * treasure_map + 1);
		game.discardCount[player] = floor(Random() * MAX_DECK);
		for (j = 0; j < game.discardCount[player]; j++)
			game.discard[player][j] = floor(Random() * treasure_map + 1);
		game.handCount[player] = floor(Random() * MAX_HAND);
		for (j = 0; j < game.handCount[player]; j++)
			game.hand[player][j] = floor(Random() * treasure_map + 1);
		game.playedCardCount = floor(Random() * MAX_DECK);
		int handPos = floor(Random() * game.handCount[player]);
		game.numActions = floor(Random()*4);
		game.whoseTurn = player;
		game.numPlayers = numberOfPlayers;
		testVillage(&game, player, handPos);
	}
	return 0;
}