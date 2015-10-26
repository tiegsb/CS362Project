#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

void testDeckShuffle(struct gameState* G){
    
    int deckCount;
    int player= G->whoseTurn;
    int empty_deck[MAX_DECK];
    int i;
   
    for (i = 0; i < MAX_DECK; i++)
    { 
        empty_deck[i]="";
    }
    int j;
    
        G->discardCount[player]=G->deckCount[player];
    for(j=0;j<G->discardCount[player]; j++){
       
        G->discard[player][j]= j;
    }



    printf("Test 1) Testing when deck is empty, discard pile is shuffled, then added to deck\npreconditions: deck is empty, discard is full of unique cards (to check shuffle)\npostconditions: deck has cards\n");
    deckCount=G->deckCount[player]; //deck count stored
    G->deckCount[player]=0;                 // deck count in state set to zero
    G->hand[player][0]=7;                       // adventurer card put in player's hand at pos zero
    memcpy(G->deck[player], empty_deck, sizeof(int) * deckCount);   // player's deck is emptied
    printf("\n(before function call, to compare with deck cards post function call)\n");   
   printDiscard(player,G);                     

    printf("\n(deckCount before calling play_adventurer: %d)\n",G->deckCount[player]);
    printf("results: \n");
    play_adventurer(player,G,0);           //takes player, game ptr, and hand position of adventurer card
    printf("(deck count after calling play_adventurer)\n - Expected: at least 1 Actual: %d\n\n", G->deckCount[player]);
    
    printf("(Visual check to see that new cards in deck are shuffled)\n");
    printDeck(player,G);
    
    
         
}

void testDrawTreasure(struct gameState* G){
    
    int player=G->whoseTurn;
    printf("Test 2)Testing that two treasure cards are drawn\npreconditions: none \npostconditions: 2 treasure cards drawn\n");
    printf("\nresults:\n(Number of Cards in Hand after discard adventurer -1, add treasures +2)\n- Expected: 6 Actual: %d\n\n", G->handCount[player]);
    //state->hand[currentPlayer][state->handCount[currentPlayer]-1]
}

int main () {
  struct gameState G;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine,cutpurse,sea_hag, tribute, smithy};
  
  printf ("Starting Unit tests for play_adventurer.\n\n");
  initializeGame(2, k, 1000, &G);
  

  //printSupply(&G);
  testDeckShuffle(&G);
  memset(&G, 23, sizeof(struct gameState));   // clear the game state (from template.c)
  int r = initializeGame(2, k,1000 , &G); // initialize a new game (from template.c)
  testDrawTreasure(&G);
   
  printf ("FINISHED Unit tests for play_adventurer...\n\n");

  

  return 0;
}