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
    printf("Testing shuffle():\n");

  initializeGame(numPlayer, k, seed, &G);

  // The goal is to test if the shuffled deck is different from the original
  // The starting deck should be sufficient for this test
  // It shouldn't matter what player it is

  if (NOISY_TEST)
    printf("Testing if shuffled deck is different from pre-shuffled deck:\n");

  // Memorize the starting deck

  if (NOISY_TEST)
    printf("Staring Deck:\n");

  int i;
  int starting_deck[MAX_DECK];
  for (i = 0; i < 10; i++) {
    starting_deck[i] = G.deck[1][i];
    if (NOISY_TEST)
      printf("%d ", G.deck[1][i]);
  }

  shuffle(1, &G);

  // Check if newly shuffled deck is different from starting

  if (NOISY_TEST)
      printf("\nShuffled Deck:\n");

  int is_shuffled = 0;

  for (i = 0; i < 10; i++) {
    if (NOISY_TEST)
      printf("%d ", G.deck[1][i]);
    if (starting_deck[i] != G.deck[1][i]) {
      is_shuffled = 1;
    }
  }

  assert(is_shuffled == 1);

  // If shuffle() returns -1 if deckCount is less than 1

  if (NOISY_TEST)
    printf("\nCheck if shuffle() returns -1 if deck is empty\n");

  G.deckCount[1] = 0;

  assert(shuffle(1, &G) == -1);

  if (NOISY_TEST)
    printf("All tests passed.\n");

  return 0;
}