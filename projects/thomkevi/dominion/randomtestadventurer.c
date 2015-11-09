/* -----------------------------------------------------------------------
 * Random Tester for dominion-base playAdventurer function
 * Include the following lines in your makefile:
 *
 * randomtestadventurer.c: randomtestadventurer.c.c dominion.c rngs.c
 *      gcc -o randomtestadventurer randomtestadventurer.c dominion.c rngs.c $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

void ExecuteRandomTest();

int main() {

  printf ("TESTING playAdventurer():\n");

  //Run 1000 tests per player of the playAdventurer function
  //  Test that players handcount increments by 2 cards
  //  Test that the 2 new cards are a copper, silver or gold card
  //  Test return code from function
  ExecuteRandomTest();
  
  return 0;
}
  
void ExecuteRandomTest() {
  
  int seed = 1000;
  int numPlayer = 2;
  int p, r, initHandCount, topCard, secondToTop;
  int k[10] = {adventurer, council_room, feast, gardens, mine
             , remodel, smithy, village, baron, great_hall};
  struct gameState G;
  int maxHandCount = 5;
  int i;
  
  for (i = 0; i < 1000; i++)
  {
  
    for (p = 0; p < numPlayer; p++) // set player
    {
    
      memset(&G, 23, sizeof(struct gameState));   // clear the game state
      r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
      r = gainCard(adventurer, &G, 2, p); // add adventurer to player 0s hand

      initHandCount = G.handCount[p];

      r = playAdventurer(&G, p, initHandCount - 1);

      // +2 coin cards
      topCard = G.hand[p][G.handCount[p]-1];
      secondToTop = G.hand[p][G.handCount[p]-1];
      
      printf("G.handCount[p] = %d, expected = %d\n", G.handCount[p], initHandCount + 2);
      assert(G.handCount[p] == initHandCount + 2); // check if the handcount is correct
      
      printf("topCard = %d, expected = %d || %d || %d\n", topCard, copper, silver, gold);
      assert(topCard == copper || topCard == silver || topCard == gold); // check if the topcard is correct

      printf("secondToTop = %d, expected = %d || %d || %d\n", secondToTop, copper, silver, gold);
      assert(secondToTop == copper || secondToTop == silver || secondToTop == gold); // check if the secondToTop is correct
      
      printf("return code = %d, expected = %d\n", r, 0);
      assert(r == 0); // check if the return code is 0
    
    }
  }
    
  printf("All random tests passed!\n");

}