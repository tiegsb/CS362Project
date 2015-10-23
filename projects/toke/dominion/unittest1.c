//#############################################
// Filename: unitest1.c
// Unit Test Objective: Tests the whoseTurn method
//                      in dominion.c
//#############################################

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

#define DEBUG 0
#define NOISY_TEST 1

void checkWhoseTurn(int expectedPlayer, struct gameState *state) {
  int currentPlayer;

  currentPlayer = whoseTurn (state);

  if (expectedPlayer != currentPlayer)
  {
    printf("Test Failed: Expected player was %d. Actual player was %d\n", expectedPlayer, currentPlayer);
  }
  else
  {
    printf("Test Passed: Expected player was %d. Actual player was %d\n", expectedPlayer, currentPlayer);
  }
  
  assert (expectedPlayer == currentPlayer);
}

int main () {

  int i;
  int k[10] = {adventurer, council_room, feast, gardens, mine,
               remodel, smithy, village, baron, great_hall
              };

  struct gameState G;

  printf ("Unit Testing: whoseTurn().\n");

  // Check that it is always the first player's turn at the
  // game start
  for (i = 2; i <= 4; ++i)
  {
    printf("Check whoseTurn() when starting a %d player game\n", i);
    memset(&G, 23, sizeof(struct gameState)); // Clear the game state
    initializeGame(2, k, 1, &G);
    checkWhoseTurn(0, &G);
  }

  // Check that whoseTurn() returns the correct player when the
  // game state is set
  printf("Check whoseTurn() returns the correct player when the game state is set\n");
  G.whoseTurn = 0;
  checkWhoseTurn(0, &G);

  G.whoseTurn = 1;
  checkWhoseTurn(1, &G);

  G.whoseTurn = 2;
  checkWhoseTurn(2, &G);

  G.whoseTurn = 3;
  checkWhoseTurn(3, &G);

  return 0;
}

