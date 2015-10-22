//test the gainCard function by adding to discard pile, player's hand and to the deck.
//make sure the supply count decreases by one.

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>

int main() {

	srand(time(NULL));
	int numberPlayer = 2;
	int player1 = 0;
	int randomSeed = rand() % 1000 + 1;
	int handCount;
	int deckCount;
	int discardCount;
	int checkSupply;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
				 remodel, smithy, village, baron, great_hall};
	struct gameState G;

	//Clear the game state
	memset(&G, 23, sizeof(struct gameState));

	//initialize game
	initializeGame(numberPlayer, k, randomSeed, &G);

	//Set gamestate supply count to 10
	G.supplyCount[0] = 10;

	//Test player's hand count
	printf("Test player's hand count\n");
	handCount = G.handCount[player1];

	gainCard(0, &G, 2, player1);

	assert(G.handCount[player1] == (handCount + 1));

	printf("TEST PASSED:\n");
	printf("Hand Count before gainCard: %d\n", handCount);
	printf("Hand Count after gainCard: %d\n", G.handCount[player1]);

	//Test deck count
	printf("Test player's deck count\n");
	deckCount = G.deckCount[player1];

	gainCard(0, &G, 1, player1);

	assert(G.deckCount[player1] == (deckCount + 1));

	printf("TEST PASSED:\n");
	printf("Deck Count before gainCard: %d\n", deckCount);
	printf("Deck Count after gainCard: %d\n", G.deckCount[player1]);


	//Test discard pile count
	printf("Test player's discard count");
	discardCount = G.discardCount[player1];

	gainCard(0, &G, 3, player1);

	assert(G.discardCount[player1] == (discardCount + 1));

	printf("TEST PASSED:\n");
	printf("Discard Count before gainCard: %d\n", discardCount);
	printf("Discard Count after gainCard: %d\n", G.discardCount[player1]);

	//Test supply count
	printf("Test supply count\n");
	assert(G.supplyCount[0] == 7);

	//Test that the supply count reaches 0, correct action occurs.
	G.supplyCount[0] = 0;

	checkSupply = gainCard(0, &G, 2, player1);

	assert(checkSupply == -1);


}

