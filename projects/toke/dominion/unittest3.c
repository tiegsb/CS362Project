//#############################################
// Filename: unittest3.c
// Unit Test Objective: Tests the isGameOver method
//                      in dominion.c
//#############################################

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

#define DEBUG 0
#define NOISY_TEST 1

void checkIsGameOver(int expectedGameOverResult, struct gameState *state) {
  int result;

  result = isGameOver (state);

  if (expectedGameOverResult != result)
  {
    printf("Test Failed: Expected game over result was %d. Actual result was %d.\n", expectedGameOverResult, result);
  }
  else
  {
    printf("Test Passed: Expected game over result was %d. Actual result was %d.\n", expectedGameOverResult, result);
  }
}

void resetSupply(struct gameState *state);
void fillAllSupply(struct gameState *state);

int main () {

  int i;
  struct gameState G;

  printf ("Unit Testing: isGameOver().\n");

  // Supply is all set to -1. Game should not be over.
  printf("Testing...Setting all supply to -1 amount.\n");
  memset(&G, 23, sizeof(struct gameState)); // Clear the game state
  resetSupply(&G);
  checkIsGameOver(0, &G);
  
  // Supply is all set to -1. Game should not be over.
  printf("Testing...Setting all supply to 1 amount.\n");
  memset(&G, 23, sizeof(struct gameState)); // Clear the game state
  fillAllSupply(&G);
  checkIsGameOver(0, &G);

  // Tests setting the province card supply to zero
  printf("Testing...Setting the province card supply to zero.\n");
  memset(&G, 23, sizeof(struct gameState)); // Clear the game state
  resetSupply(&G);
  G.supplyCount[province] = 0;
  checkIsGameOver(1, &G);

  // Tests setting three zeros in a row for all supply array positions
  int firstPosition, secondPosition, thirdPosition;
  for (i = 0; i < 27; ++i)
  {
    firstPosition = i;
    secondPosition = i + 1;
    thirdPosition = i + 2;

    // Reached the end of the supply array
    if (thirdPosition > 26)
    {
      break;
    }

    printf("Testing...Empty supply in supply array positions: %d, %d, %d\n", firstPosition, secondPosition, thirdPosition);
    memset(&G, 23, sizeof(struct gameState)); // Clear the game state
    fillAllSupply(&G); // Fill all the supply positions
    G.supplyCount[firstPosition] = 0;
    G.supplyCount[secondPosition] = 0;
    G.supplyCount[thirdPosition] = 0;
    checkIsGameOver(1, &G);
  }

  return 0;
}

void resetSupply(struct gameState *state) {
  int i;
  for (i = 0; i < 27; ++i)
  {
    state->supplyCount[i] = -1;
  }
}

void fillAllSupply(struct gameState *state) {
  int i;
  for (i = 0; i < 27; ++i)
  {
    state->supplyCount[i] = 1;
  }
}

