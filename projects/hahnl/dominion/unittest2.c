/*****************************************
Author: Larissa Hahn
unittest2.c - isGameOver()
*****************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <string.h>
#include "rngs.h"
#include <assert.h>
#define NOISY_TEST 0

int main (int argc, char** argv) {
  //Initialize variables
  struct gameState g;
  int newGame;

  int k[10] = {
    smithy,
    adventurer,
    village,
    great_hall,
    council_room,
    gardens,
    feast,
    mine,
    embargo,
    tribute
  };

  //Initalize game
  memset(&g, 23, sizeof(struct gameState));
  newGame = initializeGame(2, k, 1000, &g);

  //Tests
  printf("\n\nunittest2.c - Test for isGameOver() function:\n\n");
  assert(newGame == 0);
  assert(isGameOver(&g) == 0);
  g.supplyCount[1] = 0;
  g.supplyCount[2] = 0;
  g.supplyCount[3] = 0; // Ends game
  assert(isGameOver(&g) == 1);
  printf("\nPass Test 1\n");
  memset(&g, 23, sizeof(struct gameState));
  newGame = initializeGame(2, k, 1000, &g);
  g.supplyCount[province] = 0; // Ends game
  assert(isGameOver(&g) == 1);
  printf("\nPass Test 2\n");
  printf("\nAll tests passed.\n\n");

  return 0;
}
