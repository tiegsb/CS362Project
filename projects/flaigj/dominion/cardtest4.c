/* -----------------------------------------------------------------------
 * Unit test to check whether discarding works correctly
 *
 * cardtest4: cardtest4.c dominion.o rngs.o
 * gcc -o cardtest4 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)
 *
 *-----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() 
{
   int seed = 1000;
   int numPlayer = 3;
   int k[10] = {adventurer, council_room, curse, feast, gardens, mine, sea_hag, 
      baron, smithy, great_hall, };
   struct gameState G;

   printf("Testing the sea_hag card for correctness.\n\n");

   memset(&G, 23, sizeof(struct gameState));   // clear the game state
   initializeGame(numPlayer, k, seed, &G); 	// initialize a new game

   int cost = getCost(sea_hag);
   printf("Test 1: How many coins is a sea_hag card?\n");
   if (cost == 4)
      printf("Passed: It costs 4 coins.\n\n");
   else
      printf("Failed: It costs %d\n\n", cost);

   // add sea_hag card to hand
   G.hand[0][4] = sea_hag;
   G.hand[1][4] = province;
   G.hand[2][4] = province;

   printf("Test 2: Is sea_hag in hand?\n");
   int i;
   int isSeaHag = 0;
   for (i = 0; i < G.handCount[0]; i++)
   {
      if (G.hand[0][i] == sea_hag)
      {
	 isSeaHag = 1;
	 i = G.handCount[0];
      }
   }

   if (isSeaHag)
      printf("Passed: SeaHag in hand.\n\n");
   else 
      printf("Failed: No sea_hag in hand.\n\n");

   // play a sea_hag card
   cardEffect(sea_hag, 0, 0, 0, &G, 4, 0);

   smithyCard(0, &G, 4);
   //int oldHand = G.deckCount[0]+G.deckCount[0];

   printf("Test 3: Checking quantity in player 1's discard pile.\n");
   
   if (G.discardCount[0] > 0)
      printf("Passed: At least 1 card was discarded.\n\n");
   else
      printf("Failed: There are no cards in the discard pile.\n\n");

   printf("Test 4: Checking if player 1 has a curse card in hand.\n");

   int isCurse = 0;
   for (i = 0; i < G.handCount[0]; i++)
   {
      if (G.hand[0][i] == sea_hag)
      {
	 isCurse = 1;
	 i = G.handCount[0];
      }
   }

   if (isCurse)
      printf("Failed: Curse card in player 1's hand.\n\n");
   else
      printf("Passed: Curse card not in player 1's hand\n\n");

   printf("Test 5: Checking if other players have curse cards at top of deck.\n");

   int isCurseP2 = 0;
   int isCurseP3 = 0;

   if (G.deck[1][G.deckCount[1]-1] == curse)
      isCurseP2 = 1;

   if (G.deck[2][G.deckCount[2]-1] == curse)
      isCurseP3 = 1;

   if (isCurseP2 && isCurseP3)
      printf("Passed: Curse cards in top of deck of other players hands.\n\n");
   else
      printf("Failed: Curse card not int top of deck of other player hands.\n\n");

   printf("Test 6: Total number of cards should be 10 for player 1.\n");
   int totals = G.handCount[0] + G.deckCount[0] + G.discardCount[0];

   if (totals == 10)
      printf("Passed: Total cards correct.\n\n");
   else
      printf("Failed: Total cards are %d.\n\n", totals);

   isSeaHag = 0;
   for (i = 0; i < G.handCount[0]; i++)
   {
      if (G.hand[0][i] == sea_hag || G.deck[0][i] == sea_hag)
      {
	 isSeaHag = 1;
	 i = G.handCount[0];
      }
   }

   printf("Test 7: Is sea_hag anywhere in player 1's piles?\n");
   if (isSeaHag)
      printf("Passed: SeaHag in hand\n\n");
   else
      printf("Failed: SeaHag not in hand.\n\n");

   return 0;
}
