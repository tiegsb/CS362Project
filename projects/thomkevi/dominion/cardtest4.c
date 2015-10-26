/* -----------------------------------------------------------------------
 * Unit test for dominion-base playAdventurer function
 * Include the following lines in your makefile:
 *
 * cardtest4: cardtest4.c dominion.c rngs.c
 *      gcc -o cardtest4 cardtest4.c dominion.c rngs.c $(CFLAGS)
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
  int p, r, initHandCount, topCard, secondToTop;
  int k[10] = {adventurer, council_room, feast, gardens, mine
             , remodel, smithy, village, baron, great_hall};
  struct gameState G;
  int maxHandCount = 5;

  printf ("TESTING playAdventurer():\n");
  
  p = 0; // set player 0
  
  memset(&G, 23, sizeof(struct gameState));   // clear the game state
  r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
  r = gainCard(adventurer, &G, 2, p); // add adventurer to player 0s hand

  initHandCount = G.handCount[p];

  r = playAdventurer(&G, 0, initHandCount - 1);

  // +2 coin cards
  topCard = G.hand[p][G.handCount[p]-1];
  secondToTop = G.hand[p][G.handCount[p]-1];
  
  printf("G.handCount[p] = %d, expected = %d\n", G.handCount[p], initHandCount + 2);
  assert(G.handCount[p] == initHandCount + 2); // check if the handcount is correct
  
  printf("topCard = %d, expected = %d || %d || %d\n", topCard, copper, silver, gold);
  assert(topCard == copper || topCard == silver || topCard == gold); // check if the topcard is correct

  printf("secondToTop = %d, expected = %d || %d || %d\n", secondToTop, copper, silver, gold);
  assert(secondToTop == copper || secondToTop == silver || secondToTop == gold); // check if the secondToTop is correct
  
  printf("All tests passed!\n");

  return 0;

}