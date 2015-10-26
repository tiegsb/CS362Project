/* -----------------------------------------------------------------------
 * Unit test to check whether playCard works correctly
 *
 * unittest3: unittest3.c dominion.o rngs.o
 *      gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)
 *
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

void isEqual(int hand, int j)
{
   if (hand == j)
      printf("Passed: Expected: %d Actual: %d\t", j, hand);
   else
      printf("Failed: Expected: %d Actual: %d\t", j, hand);
}

void myTemplate(struct gameState G, int j, int k, int numPlayer)
{
   int i;
   for (i = 0; i < numPlayer; i++)
   {
      int handCnt = G.handCount[i];
      int deckCnt = G.deckCount[i];
      int discardCnt = G.discardCount[i];

      printf("Player %d:\n", i+1);
      isEqual(handCnt, j);
      isEqual(deckCnt, j);
      isEqual(discardCnt, k);
      printf("\n");
      endTurn(&G);
   }
}


void checkCount(struct gameState G, int i, int h, int j, int k)
{
   int handCnt = G.handCount[i];
   int deckCnt = G.deckCount[i];
   int discardCnt = G.discardCount[i];

   printf("Player %d:\n", i+1);
   isEqual(handCnt, h);
   isEqual(deckCnt, j);
   isEqual(discardCnt, k);
   printf("\n");
   //endTurn(&G);
}

int main() 
{
   int seed = 1000;
   int numPlayer = 4;
   int k[10] = {adventurer, council_room, feast, gardens, mine
      , remodel, smithy, village, baron, great_hall};
   // adventurer 7, council_room 8, feast 9, gardens 10, mine 11
   // remodel 12, smithy 13, village 13, baron 14, great_hall 15
   struct gameState G;
   int i;

   printf("Testing whether gain card puts card in correct area.\n\n");

   memset(&G, 23, sizeof(struct gameState));   // clear the game state
   initializeGame(numPlayer, k, seed, &G); 	// initialize a new game

   // test if all players start with same cards
   printf("----------------------------------------------------------------\n");
   printf("Initialized game with 4 players.\n");
   printf("Test 1: Test if all players start out with same card counts.\n");
   printf("1st column: handCount, 2nd column deckCount, 3rd column discardCount\n");
   myTemplate(G, 5, 0, 4);

   // test if gain card has correct numbers for player 1 and 4
   // player 1
   gainCard(7, &G, 2, 0);	// hand
   gainCard(8, &G, 1, 0);	// deck
   gainCard(9, &G, 0, 0);	// discard
   printf("----------------------------------------------------------------\n");
   printf("Adding 1 card to hand, deck and discard pile for player 1.\n");
   printf("Test 2: Checks if player 1 has 6 cards in hand, deck and 1 in discard.\n");
   checkCount(G, 0, 6, 6, 1);
   endTurn(&G);

   // player 2
   printf("\n----------------------------------------------------------------\n");
   printf("Test 3: Checks if player 2 has any modified cards.\n");
   checkCount(G, 1, 5, 5, 0);
   endTurn(&G);

   // player 3
   printf("\n----------------------------------------------------------------\n");
   printf("Test 4: Checks if player 3 has any modified cards.\n");
   checkCount(G, 2, 5, 5, 0);
   endTurn(&G);

   gainCard(10, &G, 2, 3);	// hand
   gainCard(11, &G, 1, 3);	// deck
   gainCard(12, &G, 0, 3);	// discard
   
   // player 4
   gainCard(13, &G, 2, 3);	// hand
   gainCard(14, &G, 1, 3);	// deck
   gainCard(15, &G, 0, 3);	// discard

   // check player 4 while still turn
   printf("\n----------------------------------------------------------------\n");
   printf("Adding 2 cards to hand, deck and discard pile.\n");
   printf("Test 5: Checks if player 4 has 7 cards in hand, deck and 2 in discard.\n");
   checkCount(G, 3, 7, 7, 2);
   endTurn(&G);

   // hand, deck, discard
   printf("\n----------------------------------------------------------------\n");
   printf("\nTest 6: Checks if after turn player 4 has 9 cards in discard, 2 in deck and 5 in hand.\n");
   checkCount(G, 3, 0, 7, 9);

   // p1 turn
   printf("\n----------------------------------------------------------------\n");
   printf("Test 7: Checks if player 4 gains don't modify player 1's cards.\n");
   checkCount(G, 0, 5, 1, 7);
   endTurn(&G);

   // p2
   printf("\n----------------------------------------------------------------\n");
   printf("Test 8: Checks if player 4 gains don't modify player 2's cards.\n");
   checkCount(G, 1, 5, 0, 5);
   endTurn(&G);

   // p3
   printf("\n----------------------------------------------------------------\n");
   printf("Test: Checks if player 4 gains don't modify player 3's cards.\n");
   checkCount(G, 2, 5, 0, 5);
   endTurn(&G);

   return 0;
}
