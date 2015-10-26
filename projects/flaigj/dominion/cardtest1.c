/* -----------------------------------------------------------------------
 * Unit test to check whether discarding works correctly
 *
 * cardtest1: cardtest1.c dominion.o rngs.o
 * gcc -o cardtest1 -g  cardtest1.c dominion.o rngs.o $(CFLAGS)
 *
 *-----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

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
   int count = G.handCount[player];
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
   int count = G.handCount[player];
   for (i = 0; i < count; i++)
   {
      printEnums(G.deck[player][i]);
      if (i == 4)
	 printf("\n");
      else
	 printf(", ");
   }
}

void printMyDiscard(struct gameState G, int player)
{
   int i;
   int count = G.handCount[player];
   for (i = 0; i < count; i++)
   {
      printEnums(G.discard[player][i]);
      if (i == 4)
	 printf("\n");
      else
	 printf(", ");
   }
}

int main() 
{
   int seed = 1000;
   int numPlayer = 2;
   int k[10] = {adventurer, council_room, feast, gardens, mine
      , remodel, smithy, village, baron, great_hall};
   struct gameState G;

   printf("Testing the smithy card for correctness.\n\n");

   memset(&G, 23, sizeof(struct gameState));   // clear the game state
   initializeGame(numPlayer, k, seed, &G); 	// initialize a new game

   int cost = getCost(smithy);
   printf("Test 1: How many coins is a smithy card?\n");
   if (cost == 4)
      printf("Passed: It costs 4 coins.\n\n");
   else
      printf("Failed: It costs %d\n\n", cost);

   // add smithy card to hand
   G.hand[0][4] = smithy;

   printf("Test 2: Is smithy in hand?\n");
   int i;
   int isSmithy = 0;
   for (i = 0; i < G.handCount[0]; i++)
   {
      if (G.hand[0][i] == smithy)
      {
	 isSmithy = 1;
	 i = G.handCount[0];
      }
   }

   if (isSmithy)
      printf("Passed: Smithy in hand.\n\n");
   else 
      printf("Failed: No smithy in hand.\n\n");

   int handBeforePlay = G.handCount[0];
   // play a smithy card
   smithyCard(0, &G, 4);

   int cardsDrawnCnt = G.handCount[0] - handBeforePlay;
   printf("Test 3: Checking if 3 cards drawn and one discarded.\n");

   if (cardsDrawnCnt == 2)
   {
      printf("Passed: 3 cards were drawn.\n\n");
   }
   else
   {
      printf("Failed: %d extra cards were drawn instead of 3.\n\n", cardsDrawnCnt+1);
   }

   printf("Test 4: Checking quantity in discard pile.\n");
   if (G.discardCount[0] > 0)
      printf("Passed: At least 1 card was discarded.\n\n");
   else
      printf("Failed: There are no cards in the discard pile.\n\n");

   printf("Test 5: Total number of cards should be 10.\n");
   int totals = G.handCount[0] + G.deckCount[0] + G.discardCount[0];

   if (totals == 10)
      printf("Passed: Total cards correct.\n\n");
   else
      printf("Failed: Total cards are %d.\n\n", totals);

   isSmithy = 0;
   for (i = 0; i < G.handCount[0]; i++)
   {
      if (G.hand[0][i] == smithy || G.deck[0][i] == smithy || G.discard[0][i] == smithy)
      {
	 isSmithy = 1;
	 i = G.handCount[0];
      }
   }

   printf("Test 6: Is smithy anywhere in player 1's piles?\n");
   if (isSmithy)
      printf("Passed: Smithy in one of player 1's piles.\n\n");
   else
      printf("Failed: Smithy not anywhere in player 1's piles.\n\n");

   return 0;
}
