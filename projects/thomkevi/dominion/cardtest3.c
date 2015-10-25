/* -----------------------------------------------------------------------
 * Unit test for dominion-base playSmithy function
 * Include the following lines in your makefile:
 *
 * cardtest3: cardtest3.c dominion.c rngs.c
 *      gcc -o cardtest3 cardtest3.c dominion.c rngs.c $(CFLAGS)
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
  int p, r, handCount, initHandCount, initPlayedCount;
  int k[10] = {adventurer, council_room, feast, gardens, mine
             , remodel, smithy, village, baron, great_hall};
  struct gameState G;
  int maxHandCount = 5;

  printf ("TESTING playSmithy():\n");
  
  p = 0; // set player 0
  
  memset(&G, 23, sizeof(struct gameState));   // clear the game state
  r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
  r = gainCard(smithy, &G, 2, p); // add smithy to player 0s hand


  initPlayedCount = G.playedCardCount;
  initHandCount = G.handCount[p];

  r = playSmithy(&G, 0, initHandCount - 1);
  
  //+1 played card count
  printf("G.playedCardCount = %d, expected = %d\n", G.playedCardCount, initPlayedCount + 1);
  assert(G.playedCardCount == initPlayedCount + 1); // check if the played card count is correct

  // +3 cards - Discard Smithy = Net +2
  printf("G.handCount[p] = %d, expected = %d\n", G.handCount[p], initHandCount + 2);
  assert(G.handCount[p] == initHandCount + 2); // check if the handcount is correct
  
  printf("All tests passed!\n");

  return 0;

}