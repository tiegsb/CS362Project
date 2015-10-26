/* -----------------------------------------------------------------------
 * Unit test for dominion-base whoseTurn function
 * Include the following lines in your makefile:
 *
 * unittest4: unittest4.c dominion.c
 *      gcc -o unittest4 unittest4.c dominion.c rngs.c $(CFLAGS)
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
  int minPlayer = 2;
  int p, r, numPlayer;
  int k[10] = {adventurer, council_room, feast, gardens, mine
             , remodel, smithy, village, baron, great_hall};
  struct gameState G;

  printf ("TESTING whoseTurn():\n");
  
  for (numPlayer = minPlayer; numPlayer <= MAX_PLAYERS; numPlayer++)
  {
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
    
    for (p = 0; p < numPlayer; p++)
    {
      r = whoseTurn(&G);
      printf("whoseTurn = %d, expected = %d\n", r, p);
      assert(r == p); // check if whoseTurn is correct
      
      endTurn(&G);
      r = whoseTurn(&G);
      printf("whoseTurn = %d, expected = %d\n", r, (p + 1) % numPlayer);
      assert(r == (p + 1) % numPlayer); // check if whoseTurn is correct      
    }
  }

  printf("All tests passed!\n");

  return 0;

}