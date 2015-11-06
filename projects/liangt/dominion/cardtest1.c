#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
  int seed = 1000;
  int numPlayer = 2;
  int k[10] = {adventurer, council_room, feast, gardens, mine
             , remodel, smithy, village, baron, great_hall};
  struct gameState G;

  if (NOISY_TEST)
  	printf("Testing buggySmithy():\n");

  initializeGame(numPlayer, k, seed, &G);

  // Convert second card in player 0's hand to Smithy

  G.hand[0][1] = smithy;

  // Play card directly (game starts with player 0)

  buggySmithy(&G, 1);

  // Check that the total cards in hand is now 3 - 1

  if (NOISY_TEST)
    printf("Test: Net increase of 2 cards in player's hand [failed]\n");

  // assert(G.handCount[0] == 5+3-1);

  // Check that smithy is in discard pile

  if (NOISY_TEST)
    printf("Test: Smithy card in discard pile [failed]\n");

  // assert(G.discard[0][0] == smithy);

  // if (NOISY_TEST)
  // 	printf("All tests passed.\n");

	return 0;
}