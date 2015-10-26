#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//============================
//TEST SUPPLYCOUNT() FUNCTION
//============================

int main (int argc, char** argv) {
  struct gameState s;
  int i;

  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, great_hall, tribute, smithy};

  printf ("\nsupplyCount()FUNCTION TEST\n\n");
  
  int r = initializeGame(2, k, 21, &s);

  assert (r == 0);
  
  for (i = 0; i < 27; i++)
  {
	  assert(s.supplyCount[i] == supplyCount(i, &s));
  }
  
  printf ("FUNCTION TEST RESULT... PASSED\n\n");

  return 0;
}