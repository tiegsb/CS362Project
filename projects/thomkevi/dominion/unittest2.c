/* -----------------------------------------------------------------------
 * Unit test for dominion-base gainCard function
 * Include the following lines in your makefile:
 *
 * unittest2: unittest2.c dominion.c rngs.c
 *      gcc -o unittest2 unittest2.c dominion.c rngs.c $(CFLAGS)
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
  int p, r, handCount, supplyPos, toFlag, initDeckCount, initDiscardCount;
  int k[10] = {adventurer, council_room, feast, gardens, mine
             , remodel, smithy, village, baron, great_hall};
  struct gameState G;
  int maxHandCount = 5;

  printf ("TESTING gainCard():\n");
  
  for (p = 0; p < numPlayer; p++)
  {
    for (toFlag = 0; toFlag <= 2; toFlag++)
    {
      for (supplyPos = 0; supplyPos < (treasure_map + 1); supplyPos++)
      {
        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
        G.handCount[p] = maxHandCount;
        initDeckCount = G.deckCount[p];
        initDiscardCount = G.discardCount[p];
        
        if ( supplyCount(supplyPos, &G) < 1 )
        {
          r = gainCard(supplyPos, &G, toFlag, p);
          printf("return code = %d, expected = %d\n", r, -1);
          assert(r == -1); // check if the gainCard return code is correct
          
          printf("handCount = %d, expected = %d\n", G.handCount[p], maxHandCount);
          assert(G.handCount[p] == maxHandCount); // check if the gainCard handCount is correct
          
          printf("deckCount = %d, expected = %d\n", G.deckCount[p], initDeckCount);
          assert(G.deckCount[p] == initDeckCount); // check if the gainCard handCount is correct
          
          printf("discardCount = %d, expected = %d\n", G.discardCount[p], initDiscardCount);
          assert(G.discardCount[p] == initDiscardCount); // check if the gainCard discardCount is correct
        }
        else
        {
          r = gainCard(supplyPos, &G, toFlag, p);
          if (toFlag == 0)
          {
            printf("handCount = %d, expected = %d\n", G.handCount[p], maxHandCount);
            assert(G.handCount[p] == maxHandCount); // check if the gainCard handCount is correct
            
            printf("deckCount = %d, expected = %d\n", G.deckCount[p], initDeckCount);
            assert(G.deckCount[p] == initDeckCount); // check if the gainCard handCount is correct
            
            printf("discardCount = %d, expected = %d\n", G.discardCount[p], initDiscardCount + 1);
            assert(G.discardCount[p] == initDiscardCount + 1); // check if the gainCard discardCount is correct
          }
          else if (toFlag == 1)
          {
            printf("handCount = %d, expected = %d\n", G.handCount[p], maxHandCount);
            assert(G.handCount[p] == maxHandCount); // check if the gainCard handCount is correct
            
            printf("deckCount = %d, expected = %d\n", G.deckCount[p], initDeckCount + 1);
            assert(G.deckCount[p] == initDeckCount + 1); // check if the gainCard handCount is correct
            
            printf("discardCount = %d, expected = %d\n", G.discardCount[p], initDiscardCount);
            assert(G.discardCount[p] == initDiscardCount); // check if the gainCard discardCount is correct
          }
          else if (toFlag == 2)
          {
            printf("handCount = %d, expected = %d\n", G.handCount[p], maxHandCount + 1);
            assert(G.handCount[p] == maxHandCount + 1); // check if the gainCard handCount is correct
            
            printf("deckCount = %d, expected = %d\n", G.deckCount[p], initDeckCount);
            assert(G.deckCount[p] == initDeckCount); // check if the gainCard handCount is correct
            
            printf("discardCount = %d, expected = %d\n", G.discardCount[p], initDiscardCount);
            assert(G.discardCount[p] == initDiscardCount); // check if the gainCard discardCount is correct
          }
        }

      }
    }
  }

  printf("All tests passed!\n");

  return 0;

}