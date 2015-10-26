/* -----------------------------------------------------------------------
 * Unit test of scoreFor and getWinners to check if scoring works properly
 *
 * unittest4: unittest4.c dominion.o rngs.o
 *      gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)
 *
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
void test(int expected, int actual)
{
   if (expected == actual)
      printf("Passed: Expected = %d Actual = %d\n", expected, actual);
   else
      printf("Failed: Expected = %d Actual = %d\n", expected, actual);
}

int printEnums(int cardNum)
{
   switch (cardNum)
   {
      case curse:
	 printf("curse");
	 return 0;
      case estate:
	 printf("estate");
	 return 0;
      case duchy:
	 printf("duchy");
	 return 0;
      case province:
	 printf("province");
	 return 0;
      case copper:
	 printf("copper");
	 return 0;
      case silver:
	 printf("silver");
	 return 0;
      case gold:
	 printf("gold");
	 return 0;
      case adventurer:
	 printf("adventurer");
	 return 0;
      case council_room:
	 printf("council_room");
	 return 0;
      case feast:
	 printf("feast");
	 return 0;
      case gardens:
	 printf("gardens");
	 return 0;
      case mine:
	 printf("mine");
	 return 0;
      case remodel:
	 printf("remodel");
	 return 0;
      case smithy:
	 printf("smithy");
	 return 0;
      case village:
	 printf("village");
	 return 0;
      case baron:
	 printf("baron");
	 return 0;
      case great_hall:
	 printf("great_hall");
	 return 0;
      case minion:
	 printf("minion");
	 return 0;
      case steward:
	 printf("steward");
	 return 0;
      case tribute:
	 printf("tribute");
	 return 0;
      case ambassador:
	 printf("ambassador");
	 return 0;
      case cutpurse:
	 printf("cutpurse");
	 return 0;
      case embargo:
	 printf("embargo");
	 return 0;
      case outpost:
	 printf("outpost");	 
	 return 0;
      case salvager:
	 printf("salvager");
	 return 0;
      case sea_hag:
	 printf("sea_hag");
	 return 0;
      case treasure_map:
	 printf("treasure_map");
	 return 0;
      default:
	 return 0;
   }
}
void printMyHand(struct gameState G, int player)
{
   int i;
   int count = 5;
   for (i = 0; i < count; i++)
   {
      printEnums(G.hand[player][i]);
      if (i == 4)
	 printf("\n");
      else
	 printf(", ");
   }
}

void printMyDeck(struct gameState G, int player)
{
   int i;
   int count = 5;
   for (i = 0; i < count; i++)
   {
      printEnums(G.deck[player][i]);
      if (i == 4)
	 printf("\n");
      else
	 printf(", ");
   }
}

void printMyDiscards(struct gameState G, int player)
{
   int i;
   int count = 5;
   for (i = 0; i < count; i++)
   {
      printEnums(G.discard[player][i]);
      if (i == 4)
	 printf("\n");
      else
	 printf(", ");
   }
}

int main() {
   int seed = 1000;
   int numPlayer = 4;
   int k[10] = {adventurer, council_room, feast, gardens, mine
      , remodel, smithy, village, baron, great_hall};
   struct gameState G;

   printf("Testing scoreFor function and card values for correctness.\n\n");

   // create a game of 4 players
   memset(&G, 23, sizeof(struct gameState));   // clear the game state
   initializeGame(3, k, seed, &G); 	// initialize a new game    

   G.hand[0][0] = province;
   G.hand[0][1] = copper;
   G.hand[0][2] = copper;
   G.hand[0][3] = copper;
   G.hand[0][4] = copper;

   printf("Test 1: Test score for player 1's hand + deck + discard.\n");
   
   G.deck[0][0] = copper;
   G.deck[0][1] = duchy;
   G.deck[0][2] = copper;
   G.deck[0][3] = copper;
   G.deck[0][4] = copper;
   
   G.discard[0][0] = curse;
   G.discard[0][1] = copper;
   G.discard[0][2] = copper;
   G.discard[0][3] = copper;
   G.discard[0][4] = copper;

   
   printf("Hand: ");
   printMyHand(G, 0);
   test(6, scoreFor(0, &G));
   printf("\n");
   printf("Deck: ");
   printMyDeck(G, 0);
   test(9, scoreFor(0, &G));
   printf("\n");
   printf("Discard: ");
   printMyDiscards(G, 0);
   test(8, scoreFor(0, &G));
   printf("\n");
   
   endTurn(&G);
   
   G.hand[1][0] = great_hall;
   G.hand[1][1] = copper;
   G.hand[1][2] = great_hall;
   G.hand[1][3] = copper;
   G.hand[1][4] = copper;

   printf("Test 2: Test score for player 2's hand + deck + discard.\n");
   
   G.deck[1][0] = copper;
   G.deck[1][1] = province;
   G.deck[1][2] = province;
   G.deck[1][3] = copper;
   G.deck[1][4] = copper;
   
   G.discard[1][0] = province;
   G.discard[1][1] = copper;
   G.discard[1][2] = copper;
   G.discard[1][3] = copper;
   G.discard[1][4] = copper;

   
   printf("Hand: ");
   printMyHand(G, 1);
   scoreFor(1, &G);
   test(2, scoreFor(1, &G));
   printf("\n");
   printf("Deck: ");
   printMyDeck(G, 1);
   test(14, scoreFor(1, &G));
   printf("\n");
   printf("Discard: ");
   printMyDiscards(G, 1);
   test(20, scoreFor(1, &G));
   printf("\n");

   return 0;
}
