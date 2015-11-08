/* -----------------------------------------------------------------------
 * Random test for dominion-base playCouncilRoom function
 * Include the following lines in your makefile:
 *
 * randomtestcard: randomtestcard.c dominion.c rngs.c
 *      gcc -o randomtestcard randomtestcard.c dominion.c rngs.c $(CFLAGS)
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

  printf ("TESTING playCouncilRoom():\n");

  //Run 1000 tests per player of the playCouncilRoom function
  //  Test that players buy count increments by 1
  //  Test that players played card count increments by 1
  //  Test that the other players cards in hand increments by 1
  //  Test that players hand count increases by 3 (+4 cards minus discard council)
  //  Test return code from function
  ExecuteRandomTest();

  return 0;
  
}

void ExecuteRandomTest() {

  int seed = 1000;
  int numPlayer = 2;
  int p, r, handCount, initNumBuys, player, initPlayedCount;
  int initHandCount[4];
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
      r = gainCard(council_room, &G, 2, p); // add village to player 0s hand

      initNumBuys = G.numBuys;
      initPlayedCount = G.playedCardCount;
      
      for (player = 0; player < numPlayer; player++)
      {
        initHandCount[player] = G.handCount[player];
      }

      r = playCouncilRoom(&G, p, initHandCount[p] - 1);

      //+1 buy
      printf("G.numBuys = %d, expected = %d\n", G.numBuys, initNumBuys + 1);
      assert(G.numBuys == initNumBuys + 1); // check if the num buys is correct
      
      //+1 played card count
      printf("G.playedCardCount = %d, expected = %d\n", G.playedCardCount, initPlayedCount + 1);
      assert(G.playedCardCount == initPlayedCount + 1); // check if the played card count is correct

      //+1 card in each other players hand
      for (player = 0; player < numPlayer; player++)
      {
        if (player != p)
        {
          printf("G.handCount[player] = %d, expected = %d\n", G.handCount[player], initHandCount[player] + 1);
          assert(G.handCount[player] == initHandCount[player] + 1); // check if the handcount is correct
        }
      }

      // +4 cards - Discard Council Room = Net +3
      printf("G.handCount[p] = %d, expected = %d\n", G.handCount[p], initHandCount[p] + 3);
      assert(G.handCount[p] == initHandCount[p] + 3); // check if the handcount is correct

      printf("return code = %d, expected = %d\n", r, 0);
      assert(r == 0); // check if the return code is 0
    
      
    }
    
  }
      
  printf("All tests passed!\n");

}