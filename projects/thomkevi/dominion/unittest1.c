/* -----------------------------------------------------------------------
 * Unit test for dominion-base discardCard function
 * Include the following lines in your makefile:
 *
 * unittest1: unittest1.c dominion.c rngs.c
 *      gcc -o unittest1 unittest1.c dominion.c rngs.c $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {

  int seed = 1000;
  int numPlayer = 2;
  int p, r, handCount, handPos, trashFlag;
  int k[10] = {adventurer, council_room, feast, gardens, mine
             , remodel, smithy, village, baron, great_hall};
  struct gameState G;
  int maxHandCount = 5;

  printf ("TESTING discardCard():\n");
  
  for (p = 0; p < numPlayer; p++)
  {
    for (handCount = 1; handCount <= maxHandCount; handCount++)
    {
      for (handPos = 1; handPos <= maxHandCount; handPos++)
      {   
        for (trashFlag = 0; trashFlag <= 1; trashFlag++)
        {
          memset(&G, 23, sizeof(struct gameState));   // clear the game state
          r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
          G.handCount[p] = handCount;
          
          discardCard(handPos, p, &G, trashFlag);
          
          printf("G.handCount[p] = %d, expected = %d for handPos = %d\n", G.handCount[p], handCount - 1, handPos);

          assert(G.handCount[p] == handCount - 1); // check if the handcount is correct
        }
      }
    }
  }

  printf("All tests passed!\n");

  return 0;

}