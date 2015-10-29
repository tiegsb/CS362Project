#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


void testDrawThreeCards(struct gameState* G){

      int player;  
      player=G->whoseTurn;

       G->hand[player][0]=13;

      play_smithy(player,G,0);
     
   
       printf("Test 1a) Testing if player's hand has three additonal cards after playing smithy card.\n\npreconditions: Card count is 5, card in position 0 is Smithy\npost conditions: Card count is 7, three cards are drawn, Smithy is discarded\n");
       printf("results:\n- Expected: 7 Actual: %d\n\n", G->handCount[player]);
       printf("Test 1b)Testing if player's deck has the right number of cards after playing smithy card.\n\npreconditions: Deck count is 5\npost conditions: Deck should have 2 cards (-3 after Smithy called)\n");
       printf("results:\n- Expected: 2 Actual: %d\n\n", G->deckCount[player]);
       endTurn(G);
  }
  void testSmithyIsDiscarded(struct gameState* G){

      int player;  
      player=G->whoseTurn;
      G->hand[player][0]=13;
      G->supplyCount[13]--;
      play_smithy(player,G,0);
      printf("Test 2a) Tests that the smithy card is discarded after use\npreconditions: Card count is 5, card in position 0 is Smithy\npost conditions: Card count is 7, three cards are drawn, Smithy is discarded\n");
      printf("results:\n- Expected: 1 Actual: %d\n\n", G->discardCount[player]);
      printHand(player,G);
        printf("(Check smithy is in played cards pile)\n");
        printf("- Expected: 13 Actual: %d\n\n", G->playedCards[0]);
      printPlayed(player, G);
      endTurn(G);
  }
  
/*                      MAIN                    */
int main () {
  struct gameState G;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
           sea_hag, tribute, smithy};

  printf ("Starting Unit Tests for function play_smithy...\n\n");

  initializeGame(2, k, 1000, &G);


   testDrawThreeCards(&G);
   testSmithyIsDiscarded(&G);
   printf ("FINISHED Unit Tests for function play_smithy...\n\n");


  

  return 0;
}