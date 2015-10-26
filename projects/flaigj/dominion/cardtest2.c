/* -----------------------------------------------------------------------
 * Unit test to check whether discarding works correctly
 *   
 * cardtest2: cardtest2.c dominion.o rngs.o
 * gcc -o cardtest2 -g  cardtest2.c dominion.o rngs.o $(CFLAGS)
 *      
 *       -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() 
{
   int i;
   int seed = 1000;
   int numPlayer = 2;
   int maxBonus = 10;
   int p, r, handCount;
   p = 0;

   int bonus;
   int k[10] = {adventurer, council_room, feast, gardens, mine
      , remodel, smithy, village, baron, great_hall};
   struct gameState G;
   int maxHandCount = 5;

   int myDrawnTrs = 0;
   int z = 0;
   int myTempHand[MAX_HAND];
   int myDrawnCrd = 0;

   memset(&G, 23, sizeof(struct gameState));   // clear the game state
   initializeGame(numPlayer, k, seed, &G); // initialize a new game

   G.hand[0][1] = adventurer;
   // is adventurer 6 coins
   int cost = getCost(adventurer);
   printf("Test 1: Does adventurer cost 6 coins?\n");

   if (cost == 6)
      printf("Passed: Adventurer costs 6 coins.\n\n");
   else
      printf("Failed: Adventurer costs %d coins.\n\n", cost);

   // adventurer in hand
   printf("Test 2: Is Adventurer in hand?\n");

   int isAdventurer = 0;
   for (i = 0; i < G.handCount[0]; i++)
   {
      //printf("Where\n");
      if (G.hand[0][i] == adventurer)
      {
	 isAdventurer = 1;
	 i = G.handCount[0];
      }
   }

   if (isAdventurer == 1)
      printf("Passed: Adventurer in hand.\n\n");
   else
      printf("Failed: Adventurer is not in hand.\n\n");

   // use adventurer
   adventurerCard(0, &G, myDrawnTrs, z, myTempHand, myDrawnCrd);

   isAdventurer = 0;
   for (i = 0; i < G.handCount[0]; i++)
   {
      //printf("Where\n");
      if (G.hand[0][i] == adventurer)
      {
	 isAdventurer = 1;
	 i = G.handCount[0];
      }
   }

   // is adventurer in hand
   printf("Test 3: Is adventurer removed from hand?\n");
   if (isAdventurer == 1)
      printf("Failed: Adventurer not removed from hand.\n\n");
   else
      printf("Passed: Adventurer card removed from hand.\n\n");

   // does adventurer reveal 2 treasures
   printf("Test 4: Does adventurer put two treasures into hand?\n");

   // do the treasures go into your hand
   int flag = 0;

   int last = G.handCount[0] - 1;
   int nextLast = last - 1;
   if (G.hand[0][last] == copper)
   {
      if(G.hand[0][nextLast] == copper)
      {
	 flag = 1;
      } 
   }

   if (flag && G.handCount[0] == 7)
      printf("Passed: 2 treasure cards were added to the hand.\n\n");
   else
      printf("Failed: 2 treasure cards were not added to the last hand.\n\n") ;

   // do the other cards go into discard pile
   return 0;
}
