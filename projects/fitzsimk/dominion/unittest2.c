
 */
#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

void testHandScore(struct gameState *G){
   int player=G->whoseTurn;
    int i=0;
    G->hand[player][0]=0;
    G->hand[player][1]=1;
    G->hand[player][2]=2;
    G->hand[player][3]=3;    
    G->hand[player][4]=16;   
    G->hand[player][5]=10;   
    
    G->handCount[player]=6;
    G->discardCount[player]=0;
    G->deckCount[player]=0;
    // printHand(player,G);
    int result=scoreFor(player,G);
    
    printf("Test 1) Testing hand score\npreconditions: hand set to curse, estate, duchy, province, great_hall,gardens\npost conditions: none\n");
    printf("results: \n");
    printf("- Expected: 10    Actual:  %d \n", result);
    printDiscard(player,G);
    printDeck(player,G);
    printHand(player,G);
}

void testDeckScore(struct gameState *G){
   int player=G->whoseTurn;
    int i=0;
    G->deck[player][0]=0;
    G->deck[player][1]=1;
    G->deck[player][2]=2;
    G->deck[player][3]=3;    
    G->deck[player][4]=16;   
    G->deck[player][5]=10;   
    
    G->deckCount[player]=6;
    G->discardCount[player]=0;
    G->handCount[player]=0;
 //    printDeck(player,G);
    int result=scoreFor(player,G);
    printf("Test 3) Testing deck score\npreconditions: deck set to curse, estate, duchy, province, great_hall,gardens\n\thand and discard empty\npost conditions: none\n");
    printf("results: \n");   
   printf("- Expected: 10     Actual:  %d \n", result);
    printDiscard(player,G);
    printDeck(player,G);
    printHand(player,G);
    
}
void testDiscardScore(struct gameState *G){
   int player=G->whoseTurn;
    int i=0;
    G->discard[player][0]=0;
    G->discard[player][1]=1;
    G->discard[player][2]=2;
    G->discard[player][3]=3;    
    G->discard[player][4]=16;   
    G->discard[player][5]=10;   
    
    G->discardCount[player]=6;
    G->deckCount[player]=0;
    G->handCount[player]=0;
    // printDeck(player,G);
    int result=scoreFor(player,G);
    printf("Test 2) Testing discard score\npreconditions: deck set to curse, estate, duchy, province, great_hall,gardens\n\t\thand and deck empty\npost conditions: none\n");
    printf("results: \n");
    printf("- Expected: 10     Actual:  %d \n", result); 
    printDiscard(player,G);
    printDeck(player,G);
    printHand(player,G);
    
}

/*                      MAIN                    */
int main () {
  struct gameState G;
  int k[10] = {adventurer, gardens, great_hall, village, minion, mine, cutpurse, 
           sea_hag, tribute, smithy};
  
  printf ("Starting Unit Tests for Function scoreFor...\n\n");
  /*testing purchase*/
  
  /* testing played cards*/
  initializeGame(2, k, 1000, &G);
  printSupply(&G);
  testHandScore(&G);
  memset(&G, 23, sizeof(struct gameState));   // clear the game state (from template.c)
  int r = initializeGame(2, k,1000 , &G); // initialize a new game (from template.c)
    testDiscardScore(&G);
  memset(&G, 23, sizeof(struct gameState));   // clear the game state (from template.c)
  r = initializeGame(2, k,1000 , &G); // initialize a new game (from template.c)
    testDeckScore(&G);
      printf ("FINISHED tests for function scoreFor...\n\n");
}