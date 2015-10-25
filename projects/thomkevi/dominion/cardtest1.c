/* -----------------------------------------------------------------------
 * Unit test for dominion-base playVillage function
 * Include the following lines in your makefile:
 *
 * cardtest1: cardtest1.c dominion.c rngs.c
 *      gcc -o cardtest1 cardtest1.c dominion.c rngs.c $(CFLAGS)
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
  int p, r, handCount, initActions, initPlayedCount, initHandCount;
  int k[10] = {adventurer, council_room, feast, gardens, mine
             , remodel, smithy, village, baron, great_hall};
  struct gameState G;
  int maxHandCount = 5;

  printf ("TESTING playVillage():\n");
  
  p = 0; // set player 0
  
  memset(&G, 23, sizeof(struct gameState));   // clear the game state
  r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
  r = gainCard(village, &G, 2, p); // add village to player 0s hand
  
  initPlayedCount = G.playedCardCount;
  initHandCount = G.handCount[p];
  initActions = G.numActions;
  
  r = playVillage(&G, 0, initHandCount - 1);
  
  //Draw +1 card Discard Village - Net 0 Change
  printf("G.handCount[p] = %d, expected = %d\n", G.handCount[p], initHandCount);
  assert(G.handCount[p] == initHandCount); // check if the handcount is correct
  
  //+2 actions
  printf("G.numActions = %d, expected = %d\n", G.numActions, initActions + 2);
  assert(G.numActions == initActions + 2); // check if the num actions is correct
  
  //+1 played card count
  printf("G.playedCardCount = %d, expected = %d\n", G.playedCardCount, initPlayedCount + 1);
  assert(G.playedCardCount == initPlayedCount + 1); // check if the played card count is correct

  printf("All tests passed!\n");

  return 0;

}