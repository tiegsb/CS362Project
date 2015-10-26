/*****************************************
Author: Larissa Hahn
unittest3.c - whoseTurn()
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
  newGame = initializeGame(2, k, 30, &g);

  //Tests
  printf("\n\nunittest3.c - Test for whoseTurn() function:\n\n");
  assert(newGame == 0);
  g.whoseTurn = 0;
  assert(whoseTurn(&g) == 0);
  g.whoseTurn = 1;
  assert(whoseTurn(&g) == 1);
  g.whoseTurn = 2;
  assert(whoseTurn(&g) == 2);
  g.whoseTurn = 3;
  assert(whoseTurn(&g) == 3);
  printf("Pass Test 1\n");
  memset(&g, 23, sizeof(struct gameState));
  newGame = initializeGame(2, k, 1000, &g);
  assert(whoseTurn(&g) == 0);
  printf("Pass Test 2\n");
  memset(&g, 23, sizeof(struct gameState));
  newGame = initializeGame(3, k, 1000, &g);
  assert(whoseTurn(&g) == 0);
  printf("Pass Test 3\n");
  memset(&g, 23, sizeof(struct gameState));
  newGame = initializeGame(4, k, 1000, &g);
  assert(whoseTurn(&g) == 0);
  printf("Pass Test 4\n");
  printf("\nPass all tests.\n");

  return 0;
}
