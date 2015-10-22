//test adventurer card

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
	int k[10] = {adventurer, council_room, feast, gardens, mine,
				 remodel, smithy, village, baron, great_hall};
	struct gameState G;

	//expect a 'healthy card' to reveal cards from deck until 2 Treasure cards are hit.
	//then put those card in your hand and discard the other revealed cards.

	//1) Test that 2 cards (1 card gained in hand because of this one played)
	// are accumulated in hand and all other cards are discarded.

	




}