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
  	printf("Testing scoreFor():\n");

  initializeGame(numPlayer, k, seed, &G);

  if (NOISY_TEST)
    printf("Test: Starting deck + hand has score of 3 from estate cards [failed]\n");

  // assert(scoreFor(0, &G) == 3);

  // LOOKING AT THE CODE, IT'S CLEAR THAT THE DECK SCORE CALCULATION HAS AN ERROR:
  // It uses discardCount instead of deckCount. Further tests will take that
  // into account

  int i;

  G.discardCount[0] = 5; // So that deck, hand, discard counts are all equal

  if (NOISY_TEST)
    printf("Test: If discardCount == deckCount and all cards are estate\n");

  for (i = 0; i < 5; i++) {
    G.hand[0][i] = estate;
    G.discard[0][i] = estate;
    G.deck[0][i] = estate;
  }

  assert(scoreFor(0, &G) == 3*5*1);

  if (NOISY_TEST)
    printf("Test: If discardCount == deckCount and all cards are duchy [failed]\n");

  for (i = 0; i < 5; i++) {
    G.hand[0][i] = duchy;
    G.discard[0][i] = duchy;
    G.deck[0][i] = duchy;
  }

  // assert(scoreFor(0, &G) == 3*5*5);

  if (NOISY_TEST)
    printf("Test: If discardCount == deckCount and all cards are province [failed]\n");

  for (i = 0; i < 5; i++) {
    G.hand[0][i] = province;
    G.discard[0][i] = province;
    G.deck[0][i] = province;
  }

  // assert(scoreFor(0, &G) == 3*5*8);

  // if (NOISY_TEST)
  // 	printf("All tests passed.\n");

	return 0;
}