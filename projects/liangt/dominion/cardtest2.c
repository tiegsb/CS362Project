#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
  int i;
  int seed = 1000;
  int numPlayer = 2;
  int k[10] = {adventurer, council_room, feast, gardens, mine
             , remodel, smithy, village, baron, great_hall};
  struct gameState G;

  if (NOISY_TEST)
  	printf("Testing buggyAdventurer():\n");

  initializeGame(numPlayer, k, seed, &G);

  // Make hand all estate cards

  for (i = 0; i < 5; i++) {
    G.hand[0][i] = estate;
  }

  // Convert second card in player 0's hand to Adventurer

  G.hand[0][1] = adventurer;

  if (NOISY_TEST)
    printf("Test: all coppers in deck\n");

  for (i = 0; i < 5; i++) {
    G.deck[0][i] = copper;
  }

  buggyAdventurer(&G, 1);

  assert(G.hand[0][G.handCount[0]-1] == copper &&
    G.hand[0][G.handCount[0]-2] == copper);

  if (NOISY_TEST)
    printf("Test: all silvers in deck [failed]\n");

  initializeGame(numPlayer, k, seed, &G);
  for (i = 0; i < 5; i++) {
    G.hand[0][i] = estate;
  }
  for (i = 0; i < 5; i++) {
    G.deck[0][i] = silver;
  }
  G.hand[0][1] = adventurer;
  buggyAdventurer(&G, 1);

  // assert(G.hand[0][G.handCount[0]-1] == silver &&
  //   G.hand[0][G.handCount[0]-2] == silver);

  if (NOISY_TEST)
    printf("Test: all golds in deck\n");

  initializeGame(numPlayer, k, seed, &G);
  for (i = 0; i < 5; i++) {
    G.hand[0][i] = estate;
  }
  for (i = 0; i < 5; i++) {
    G.deck[0][i] = gold;
  }
  G.hand[0][1] = adventurer;
  buggyAdventurer(&G, 1);

  assert(G.hand[0][G.handCount[0]-1] == gold &&
    G.hand[0][G.handCount[0]-2] == gold);

  if (NOISY_TEST)
    printf("Test: only two treasure cards are drawn [failed]\n");

  // assert(
  //   G.hand[0][G.handCount[0]-3] != copper &&
  //   G.hand[0][G.handCount[0]-3] != silver &&
  //   G.hand[0][G.handCount[0]-3] != gold);

  // if (NOISY_TEST)
  // 	printf("All tests passed.\n");

	return 0;
}