/* -----------------------------------------------------------------------
 * Unit test to check whether discarding works correctly
 *
 * unittest2: unittest2.c dominion.o rngs.o
 *      gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)
 *
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
   int k[10] = {adventurer, council_room, feast, gardens, mine
      , remodel, smithy, village, baron, great_hall};
   struct gameState G;

   printf("Testing discardCard function to see if it works properly.\n\n");

   memset(&G, 23, sizeof(struct gameState));   // clear the game state
   initializeGame(numPlayer, k, seed, &G); 	// initialize a new game


   // test if both players get starting hands
   printf("Test 1: Check if all players receive cards from an initialized game.\n");

   if ((G.handCount[0] > 0) && (G.handCount[1] > 0))
      printf("Passed: Both players have cards in their hands.\n\n");
   else
      printf("Failed: Both players don't have cards in their hands.\n\n");


   // test if player 1 gets a starting hand
   printf("Test 2: Checks if initialize game gives Player 1 a starting hand.\n");

   if (G.handCount[0] > 0)
      printf("Passed: Player 1 has a starting hand.\n\n");
   else
      printf("Failed: Player 1 doesn't have a starting hand.\n\n");


   // test if player 2 has starting hand 
   printf("Test 3: Checks if Player 2 has a starting hand.\n");

   if (G.handCount[1] > 0)
      printf("Passed: Player 2 has a starting hand.\n\n");
   else
      printf("Failed: Player 2 doesn't have a starting hand.\n\n");


   // test if player 1's discard removes card from hand
   int oldHandCount = G.handCount[0];
   printf("Test 4: Checks if a card was removed from Player 1's hand.\n");
   discardCard(4, 0, &G, 0);

   if (G.handCount[0] < oldHandCount)
      printf("Passed: A card was removed from player 1's hand.\n\n");
   else
      printf("Failed: A card wasn't removed from player 1's hand.\n\n");


   // test if discard card is actually discarding into discard pile
   printf("Test 5: Checks if a card was added to Player 1's discard pile.\n");

   if (G.discardCount[0] > 0)
      printf("Passed: A card was added to player 1's discard pile.\n\n");
   else
      printf("Failed: A card wasn't added to player 1's discard pile.\n\n");


   int handCountP2 = G.handCount[1];
   endTurn(&G);

   printf("Running endTurn function.\n");
   printf("Test 6: Rechecking if a card was added to Player 1's discard pile.\n");
   if (G.discardCount[0] > 0)
      printf("Passed: A card was added to player 1's discard pile.\n\n");
   else
      printf("Failed: A card wasn't added to player 1's discard pile.\n\n");


   // test if discarded cards don't increase or decrease other players cards
   printf("Test 7: Checks if Player 2 received any cards into discard pile from player 1.\n");

   if (G.discardCount[1] > 0)
      printf("Failed: Player 2 shouldn't have a discard pile but does.\n\n");
   else
      printf("Passed: Player 2 doesn't have a discard pile.\n\n");

   printf("What is the handcount of player 2? Answer = %d\n", G.handCount[1]);
   printf("What is the handcount of player 1? Expected = 5, Actual = %d\n", G.handCount[0]);
   printf("What is player 2's count before endTurn()? Expected 0, Actual = %d\n", handCountP2);
   printf("What is player 1's discard count? Expected = 1, Actual = %d\n", G.discardCount[0]);
   return 0;
}
