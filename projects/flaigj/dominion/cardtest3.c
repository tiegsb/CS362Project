/* -----------------------------------------------------------------------
 * Unit test to check whether discarding works correctly
 *
 * cardtest3: cardtest3.c dominion.o rngs.o
 * gcc -o cardtest3 -g  cardtest3.c dominion.o rngs.o $(CFLAGS)
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
   int numPlayer = 2;
   int k[10] = {adventurer, council_room, feast, gardens, mine
      , remodel, smithy, village, baron, great_hall};
   struct gameState G;

   printf("Testing the council room card for correctness.\n\n");

   memset(&G, 23, sizeof(struct gameState));   // clear the game state
   initializeGame(numPlayer, k, seed, &G); 	// initialize a new game

   int count = 5;
   int myHand[count];
   myHand[0] = gold;
   myHand[1] = silver;
   myHand[2] = copper;
   myHand[3] = village;
   myHand[4] = council_room;

   int myHand1[count];

   myHand1[0] = gold;
   myHand1[1] = silver;
   myHand1[2] = copper;
   myHand1[3] = village;
   myHand1[4] = smithy;

   memcpy(G.hand[0], myHand, sizeof(int) * count);
   memcpy(G.hand[1], myHand1, sizeof(int) * count);

   int cost = getCost(council_room);
   printf("Test 1: How many coins is a council room card?\n");
   if (cost == 5)
      printf("Passed: It costs 5 coins.\n\n");
   else
      printf("Failed: It costs %d\n\n", cost);

   // add council_room card to hand
   G.hand[0][4] = council_room;

   printf("Test 2: Is council room in hand?\n");
   int i;
   int isCouncil = 0;
   int pos = -1;
   for (i = 0; i < G.handCount[0]; i++)
   {
      // printf("WHAT?\n");
      if (G.hand[0][i] == council_room)
      {
	 isCouncil = 1;
	 pos = i;
	 i = G.handCount[0];
      }
   }

   printf("Current place %d\n", pos);
   if (isCouncil)
      printf("Passed: council_room in hand.\n\n");
   else 
      printf("Failed: No council_room in hand.\n\n");

   int handBeforePlay = G.handCount[0];
   // play a council_room card
   council_roomCard(0, &G, 4);

   int cardsDrawnCnt = G.handCount[0] - handBeforePlay;
   printf("Test 3: Checking if 4 cards drawn and one discarded.\n");

   if (cardsDrawnCnt == 3)
   {
      printf("Passed: 4 cards were drawn.\n\n");
   }
   else
   {
      printf("Failed: %d cards were drawn instead of 4.\n\n", cardsDrawnCnt+1);
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

   isCouncil = 0;
   for (i = 0; i < G.handCount[0]; i++)
   {
      if (G.discard[0][i] == council_room ||
	    G.hand[0][i] == council_room ||
	    G.deck[0][i] == council_room)
      {
	 isCouncil = 1;
	 i = G.handCount[0];
      }
   }

   printf("Test 6: Is council_room anywhere in player 1's piles?\n");
   if (isCouncil)
      printf("Passed: council_room is somewhere in player 1's piles.\n\n");
   else
      printf("Failed: council_room is not in any piles.\n\n");

   return 0;
}
