#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set PRINT_OUT to 0 to remove printfs from output
#define PRINT_OUT 1
/** tests discard hand logic in endTurn **/
void testDiscardHand(struct gameState*G){  
    int numPlayers = 2;
    int n,m;
    int zero_count, one_count;
    int turn=0;
    printf("Test 1) Testing that the correct number of cards are discarded for each player\nand that the cards are found in the player's discard pile");
    printf("preconditions: 2 players, 6 turns, 5 cards in each hand, no cards purchased\n");
    printf("post conditions:  players hands are added to the discard pile until deck is empty,\n\t\tthe discard pile is empty if the deck is full minus the\n\t\t current player's hand.\n"); 
    
    for(n = 0; n < 3; n++){
        
        // for each player
        for(m=0; m < numPlayers; m++){
            printf("\nTURN %d\n", turn);
           int player=G->whoseTurn;
            if(turn == 0){
                zero_count=5;       //p0
                one_count=0;
            }
            if(turn == 1) 
            {
                zero_count=5;       //p1
                one_count=5;
            }
            if(turn == 2){
                zero_count=10;     //p0
                one_count=5;
            }
            if(turn == 3){
                zero_count= 0;      //p1 -p0 had to draw a new hand so discard pile was reused
                one_count=10;
            }
            if(turn == 4){
                zero_count=5;       //p0
                one_count=0;
            }
            if(turn == 5){
                zero_count=5;       //p1
                one_count=5;
            }
            printf("results:\n");
            printf("(Pre function call)\n");
            printHand(player,G);
            endTurn(G);
            printf("(Post function call)\nTop 5 cards of \n");
            int discardCount=G->discardCount[player];
            int h;
            printf("Player %d's discard pile: \n",m);
            printf("#  Card \n");
            for(h=discardCount; h > (discardCount-5); h-- ){
                printf("%d  ",h);            
                if(G->discard[player][h] == 1){
                    printf("Estate\n");
                }else{
                    printf("Copper\n");
                }

            }
            printf("\n");
            if(m==0){
                printf("Player 0's discard count...\n" );
                printf("- Expected: %d Actual: %d\n", zero_count,G->discardCount[m]);               
                printf("Player 1's discard count...\n");
                printf("- Expected: %d Actual: %d\n", one_count,G->discardCount[1]);

            }else{
                           
                printf("Player 1's discardCount\n");
                printf("- Expected: %d Actual: %d\n", one_count,G->discardCount[m]);            
                printf("Player 0's discardCount \n");
                printf("- Expected: %d Actual: %d\n", zero_count,G->discardCount[0]);
          
            }
            
            turn++;
        }      
    }
      printf("\n\n");
}

/** tests state variables that are reset by endTurn
**/
void testResetsValues(struct gameState* G){
   
  printf("Test 2) Testing that state varialbes are reset when endTurn is called.\n");
  printf("preconditions: variables outpostPlayed, phase, numActions, numBuys, playedCardCount and hand count\n\t\thave been set to abirtray values.\n");
  printf("post conditions: all variables are reset to initial values.\n");
  G->outpostPlayed = 5; // should be 0
  G->phase=1;             // should be 0
  G->numActions=5;   // should be 1
  G->numBuys = 2;  //should be 1
  G->playedCardCount = 4; // should be 0
  G->handCount[G->whoseTurn] = 9; // should be 0, then 5 post draw

  endTurn(G);
  printf("results:\n");
   printf("Outpost Played\n- Expected: 0 Actual: %d\n", G->outpostPlayed);
   assert(G->outpostPlayed == 0);
   printf("Phase\n- Expected: 0 Actual: %d\n", G->phase);
   printf("numActions\n- Expected: 1 Actual: %d\n", G->numActions);
   printf("numBuys\n- Expected: 1 Actual: %d\n", G->numBuys);
   printf("playedCardCount\n- Expected: 0 Actual: %d\n", G->playedCardCount);
   printf("handCount for current player %d\n- Expected: 5 Actual: %d\n", G->whoseTurn,G->handCount[G->whoseTurn]);
     printf("\n\n");
}
/* Tests that the function correctly switches between players*/
void testCurrentPlayer(struct gameState *G){
    
    G->whoseTurn=0;
   int i,m;
    printf("Test 3) Testing that Current Player is updated\n");
    printf("preconditions: 4 turns are executed\n");
    printf("post conditions: endTurn switches current player each time it is called\n");
    printf("results:\n");
    for( i= 0; i < 4; i++){
        printf("Ending Turn %d\n",i);
        endTurn(G);
        // test current player
            if(i % 2 != 0) {
                    m=0;
            }else{
                    m=1;
             }
    printf("- Expected Player: %d Actual Player: %d\n", m, G->whoseTurn);
 
  }
  printf("\n\n");
}
void testPlayedCards(struct gameState* G){
     int player=G->whoseTurn;
    int i,m;
    printf("Test 4) Testing that played cards return to discard pile\n");
    printf("preconditions: add a smithy card to played pile\n");
    printf("post conditions: smithy card should be moved to discard pile \n\n");
    printf("results:\n");
    
    G->playedCards[0]=13;
    G->playedCardCount++;
    endTurn(G);
    int found_smity=-1;
    for(m=0; m < G->discardCount[0];m++){
        
        if(G->discard[0][m] == 13){
            found_smity=0;
        }
        
    }
  
    printf("(if smithy was found in discard pile, expect 0) \n");
    printf("- Expected: 0 Actual: %d\n", found_smity);
 
 
  printf("\n\n"); 
}
/*                      MAIN                    */
int main () {
  struct gameState G;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
           sea_hag, tribute, smithy};
  
  printf ("Starting Unit Tests for function endTurn...\n\n");
  initializeGame(2, k, 1000, &G);

  testDiscardHand(&G);
  testResetsValues(&G);
  testCurrentPlayer(&G);
     memset(&G, 23, sizeof(struct gameState));   // clear the game state (from template.c)
 int  r = initializeGame(2, k,1000 , &G); // initialize a new game (from template.c)
 testPlayedCards(&G);
 
  
    printf ("FINISHED tests for function endTurn...\n\n");

  return 0;
}
