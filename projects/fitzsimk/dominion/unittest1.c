#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


void testEmptyPile(struct  gameState* G){
    
    int player=G->whoseTurn;
    G->supplyCount[5]=0;
    int result = gainCard(5, G, 1, player);
       printf("Test 1) Testing that an empty pile returns error message.\n");
    printf("preconditions: pile 5 at supplyCount set to 0\n");
    printf("post conditions: function should return -1\n"); 
    printf("results: \n");
    printf("- Expected: -1  Actual: %d\n", result);
    printf("\n\n");

}
void testIllegalCard(struct  gameState* G){
     int player=G->whoseTurn;
    int result = gainCard(-3, G, 1, player);
    printf("Test 2a) Testing that a negative value illegal card returns error message.\n");
    printf("preconditions: function called with card -3 \n");
    printf("post conditions: function should return -1\n"); 
    printf("results: \n");
    printf("- Expected: -1  Actual: %d\n", result);
    printf("\n");
    result = gainCard(1000, G, 1, player);
    printf("Test 2b) Testing that a positive valued illegal card returns error message.\n");
    printf("preconditions: function called with card 1000 \n");
    printf("post conditions: function should return -1\n"); 
    printf("results: \n");
    printf("- Expected: -1  Actual: %d\n", result);
    printf("\n\n");
    
}


void testCardAddedToDeck(struct  gameState* G){
        
    int player=G->whoseTurn;
    int result = gainCard(7, G, 1, player);
    printf("Test 3) Testing that gained card is added to deck\n");
    printf("preconditions: call function with flag set to 1 \n");
    printf("post conditions: new card is in player's deck\n"); 
    printf("results: \n");
    printf("Top of Player's Deck\n");
    int deckCount= G->deckCount[player];
    printf("- Expected: 7  Actual: %d\n", G->deck[player][deckCount-1]);
    printf("\n\n");
}

void testCardAddedToHand(struct  gameState* G){
    int player=G->whoseTurn;
    int result = gainCard(7, G, 2, player);
    printf("Test 4) Testing that gained card is added to deck\n");
    printf("preconditions: call function with flag set to 2 \n");
    printf("post conditions: new card is in player's deck\n"); 
    printf("results: \n");
    printf("Top of Player's Hand\n");
    int handCount= G->handCount[player];
    printf("- Expected: 7  Actual: %d\n", G->hand[player][handCount-1]);
    printf("\n\n");
}

void testCardAddedToDiscard(struct  gameState* G){
     int player=G->whoseTurn;
    int result = gainCard(7, G, -1, player);
    printf("Test 5) Testing that gained card is added to discard\n");
    printf("preconditions: call function with flag set to -1 \n");
    printf("post conditions: new card is in player's discard pile\n"); 
    printf("results: \n");
    printf("Top of Player's Discard Pile\n");
    int discardCount= G->discardCount[player];
    printf("- Expected: 7  Actual: %d\n", G->discard[player][discardCount-1]);
    printf("\n\n");
}
void testRemovedFromSupply(struct  gameState* G){
     int player=G->whoseTurn;

    printf("Test 6) Testing that gained card is removed from supply pile\n");
    printf("preconditions: call function with card 7 \n");
    printf("post conditions: card 7's supply pile is one less\n"); 
    printf("results: \n");
    printf("(Supply Count before function call: %d)\n",G->supplyCount[7]);
    int result = gainCard(7, G, -1, player);
    printf("Supply Count post function call");
    printf("- Expected: 9  Actual: %d\n", G->supplyCount[7]);
    printf("\n\n");
}


/*      MAIN        */
int main(){
  struct gameState G;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
           sea_hag, tribute, smithy};
  
  printf ("Starting Unit Tests on gainCard...\n\n");
  initializeGame(2, k, 1000, &G);
  testEmptyPile(&G);
  memset(&G, 23, sizeof(struct gameState));   // clear the game state (from template.c)
  int r = initializeGame(2, k,1000 , &G); // initialize a new game (from template.c)
  testIllegalCard(&G);
  memset(&G, 23, sizeof(struct gameState));   // clear the game state (from template.c)
  r = initializeGame(2, k,1000 , &G); // initialize a new game (from template.c)
 testCardAddedToDeck(&G);
   memset(&G, 23, sizeof(struct gameState));   // clear the game state (from template.c)
  r = initializeGame(2, k,1000 , &G); // initialize a new game (from template.c)
 testCardAddedToHand(&G);
  memset(&G, 23, sizeof(struct gameState));   // clear the game state (from template.c)
  r = initializeGame(2, k,1000 , &G); // initialize a new game (from template.c)
 testCardAddedToDiscard(&G);
   memset(&G, 23, sizeof(struct gameState));   // clear the game state (from template.c)
  r = initializeGame(2, k,1000 , &G); // initialize a new game (from template.c)
 testRemovedFromSupply(&G);
 
   printf ("FINISHED Unit Tests on gainCard...\n\n");
   return 0;
}



