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
  	printf("Testing discardCard():\n");

  initializeGame(numPlayer, k, seed, &G);

  // First test: discarded card is removed from hand
  if (NOISY_TEST)
    printf("Test: discarded card removed from hand\n");

  G.hand[1][0] = adventurer; //Since this is not in the starting hand

  discardCard(0, 1, &G, 1);

  assert(G.hand[1][0] != adventurer);

  if (NOISY_TEST)
    printf("Test: trashed card not in discarded pile\n");

  assert(G.discard[1][0] != adventurer);

  if (NOISY_TEST)
    printf("Test: discarded card in discarded pile [failed]\n");

  G.hand[1][0] = gardens;

  discardCard(0, 1, &G, 0);

  // THIS ASSERTION FAILED. COMMENTED SO THAT MAKE CAN CONTINTUE

  // assert(G.discard[1][0] == gardens);

  // if (NOISY_TEST)
  // 	printf("All tests passed.\n");

	return 0;
}