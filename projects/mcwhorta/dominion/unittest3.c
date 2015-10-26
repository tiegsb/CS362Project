#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>

#define DEBUG 0
#define NOISY_TEST 1

int testUpdateCoins(int player, struct gameState *post) {
	int bonus = 3;
	int i;
	int r;
	struct gameState pre;
	memcpy(&pre, post, sizeof(struct gameState));

	r = updateCoins(player, post, bonus);
	pre.coins = 0;
	for (i = 0; i < pre.handCount[player]; i++) {
		if (pre.hand[player][i] == copper) {
			pre.coins += 1;
		} else if (pre.hand[player][i] == silver) {
			pre.coins += 2;
		} else if (pre.hand[player][i] == gold) {
			pre.coins += 3;
		}
	}

	//add bonus
	pre.coins += bonus;
	assert(r==0);
	assert(memcmp(&pre, post, sizeof(struct gameState)) == 0);
	return 0;
}

int main() {
	struct gameState game;
	int player;
	int i;
	int n;
	printf("Testing updateCoins().\n");
	printf("RANDOM TESTS.\n");

	SelectStream(2);
	PutSeed(-3);

	for (n = 0; n < 3000; n++) {
		for (i = 0; i < sizeof(struct gameState); i++) {
			((char*) &game)[i] = floor(Random() * 256);
		}
		player = floor(Random() * 2);
		game.deckCount[player] = floor(Random() * MAX_DECK);
		for (i = 0; i < game.deckCount[player]; i++)
			game.deck[player][i] = floor(Random() * (treasure_map + 1));
		game.discardCount[player] = floor(Random() * MAX_DECK);
		for (i = 0; i < game.discardCount[player]; i++)
			game.discard[player][i] = floor(Random() * (treasure_map + 1));
		game.handCount[player] = floor(Random() * MAX_HAND);
		for (i = 0; i < game.handCount[player]; i++)
			game.hand[player][i] = floor(Random() * (treasure_map + 1));

		testUpdateCoins(player, &game);
	}

	printf("ALL TESTS OK\n\n");
	return 0;
}
