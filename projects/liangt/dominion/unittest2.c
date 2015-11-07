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
  	printf("Testing isGameOver():\n");

  initializeGame(numPlayer, k, seed, &G);

  // The goal is to test whether either of the conditions for ending a game
  // will return true and return false otherwise

  // Test if starting game returns false

  if (NOISY_TEST)
    printf("Testing if starting game returns false\n");

  assert(isGameOver(&G) == 0);

  // Test if depleted province cards returns true

  if (NOISY_TEST)
    printf("Testing if depleted province cards returns true\n");

  G.supplyCount[province] = 0;

  assert(isGameOver(&G) != 0);

  // Test if 3 types of cards depleted returns true

  if (NOISY_TEST)
    printf("Testing if 3 depleted cards returns true\n");

  initializeGame(numPlayer, k, seed, &G); // So that previous test won't affect

  // Test 1 kingdom card, 1 treasure, and 1 victory card

  G.supplyCount[feast] = 0;
  G.supplyCount[silver] = 0;
  G.supplyCount[duchy] = 0;

  assert(isGameOver(&G) != 0);

  if (NOISY_TEST)
  	printf("All tests passed.\n");

	return 0;
}