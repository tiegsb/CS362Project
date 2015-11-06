#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


void testZeroProvinces(struct gameState* G){

    printf("Test 1a) Tests if game ends when there are no provinces in the pile.\n");
    printf("preconditions: zero Province cards in pile\n");
    printf("preconditions: game should end (so return true 0)\n");    
    int result;
    G->supplyCount[province]=0;
    result=isGameOver(G);
    printf("results: \n-Expected: 1 Actual: %d\n\n", result );
    printf("Test 1b) Tests if game ends when there is one province in the pile.\n");    
     printf("preconditions: oneProvince cards in pile\n");
    printf("preconditions: game should not end (so return false 1)\n");    
    G->supplyCount[province]=1;
    result=isGameOver(G);
    printf("results:\n-Expected: 0 Actual: %d\n\n", result );
    
}

void testThreeZeroSupplyCount(struct gameState* G){
    
    printf("Test 2) Test if game ends when three piles are empty.\n");
    printf("preconditions: THREE card piles (curse, silver, duchy) are set to zero\n");
    printf("post-conditions: Game should end.\n");
    int result;
    G->supplyCount[curse]= 0;
    G->supplyCount[silver]= 0;
    G->supplyCount[duchy]=0;

    result=isGameOver(G);
    
    printf("results:\n-Expected: 1 Actual: %d\n\n", result );

    
}

void testAllKingdomCards(struct gameState* G){
    int result;
    printf("Test 3)\n THREE kingdom card piles are set to zero\n");
    printf("preconditions: THREE kingdom card piles (village, minion, cutpurse) are set to zero\n");
    printf("post-conditions: Game should end.\n");

    G->supplyCount[14]= 0; // village
    G->supplyCount[17]= 0; // Minion
    G->supplyCount[21]= 0; // cutpurse
    
    result=isGameOver(G);
    
    printf("results:\n-Expected: 1 Actual: %d\n\n", result );

    
}

/*      MAIN        */
int main(){
  struct gameState G;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
           sea_hag, tribute, smithy};
  
  printf ("Starting Unit Tests for isGameOver()...\n\n");
  initializeGame(2, k, 1000, &G);
  testZeroProvinces(&G);
  memset(&G, 23, sizeof(struct gameState));   // clear the game state (from template.c)
  int r = initializeGame(2, k,1000 , &G); // initialize a new game (from template.c)
  testThreeZeroSupplyCount(&G);
  memset(&G, 23, sizeof(struct gameState));   // clear the game state (from template.c)
  r = initializeGame(2, k,1000 , &G); // initialize a new game (from template.c)
  testAllKingdomCards(&G);
  printf ("FINISHED tests for isGameOver function...\n\n");
}


