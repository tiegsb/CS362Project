#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//===========================
//TEST isGameOver() FUNCTION
//===========================

int main (int argc, char** argv) {
  struct gameState s;
  int temp;

  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, great_hall, tribute, smithy};

  printf ("\n\nisGameOver() FUNCTION TEST\n\n");

  int c = initializeGame(2, k, 21, &s);

  assert (c == 0);
  
  assert(isGameOver(&s) == 0);
  temp = s.supplyCount[province];
  s.supplyCount[province] = 0;
  assert(isGameOver(&s) == 1);
  s.supplyCount[province] = temp;
  s.supplyCount[1] = 0;
  s.supplyCount[2] = 0;
  s.supplyCount[3] = 0;
  assert(isGameOver(&s) == 1);
  printf ("FUNCTION TEST RESULT... PASS\n\n");

  return 0;
}