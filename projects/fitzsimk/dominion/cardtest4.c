#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


  void testZeroTreasureMap(struct gameState *G){
     
     int player=G->whoseTurn;
     
    int result=play_treasure_map(player,G,0);
        printf("Test 4) Test if function returns -1 if there are no treasure maps in hand.\n");
        printf("preconditions: hand at 0 is treasure map card.\n");
        printf("post conditions: Function should return with -1.\n");
        printf("Expected: -1, Actual: %d\n\n", result);  
     
 }
 
 void testOneTreasureMap(struct gameState *G){
     
     int player=G->whoseTurn;
     G->hand[player][0]= 26;
     
    int result=play_treasure_map(player,G,0);
        printf("Test 3) Test if function returns -1 if only one treasure map in hand.\n");
        printf("preconditions: hand at 0 is treasure map card.\n");
        printf("post conditions: Function should return with -1.\n");
        printf("Expected: -1, Actual: %d\n\n", result);  
     
 }
 
 void testBothTreasuresDiscarded(struct gameState *G){
     
     int m;
     for(m=0; m < 4; m++){
     //   printf("TURN %d\n", m);
       int player = G->whoseTurn; 
       printf("PLAYER %d\n", player);
        printf("Test 2) Testing discard count.\n");
        printf("preconditions: hand at 1, and at 3 are set to treasure cards.\n");
        printf("post conditions: Discard count should be > 0.\n");
        int firstCard=G->hand[player][1];
        int secondCard=G->hand[player][3];
        
        // putting removed cards back
        int d;
        for(d=0; d < treasure_map+1; d++){
            if(G->supplyCount[d] == firstCard || G->supplyCount[d] == secondCard){
                G->supplyCount[d]++;             
            }
        }
        //adding two treasure cards from supply
        G->supplyCount[26]=G->supplyCount[26]-2;
        G->hand[player][1]= 26;
        G->hand[player][3]= 26;
        
        
        int result=play_treasure_map(player,G,1);
        int discardCount=G->discardCount[player]; 
        printf("Discard Count... Expected: at least 2, Actual: %d\n\n", discardCount);
           
        if(discardCount > 0){
            printf("Test 2a) Testing both treasure cards are discarded.\n");
            printf("preconditions: State from test 2 is preserved.\n");
            printf("post conditions: Top two cards of discard pile are Treasure Map cards.\n\n");
            
            printf("Top of discard pile...\n");
            int c;
            int map_count=0;
        
           for(c=discardCount; c > 0; c--){
                 printf("Card at Position %d: %d\n",c-1, G->discard[player][(c-1)]);
                 if(G->discard[player][c-1] == 26){
                     map_count++;
                 }
             }
             printf("\n");
             printf("Number of Treasure Maps, Expected: 2   Actual: %d\n", map_count);
      }else{
          printf("Discard count too low to execute Test 2a...");
      }
        endTurn(G);
        printf("\n\n");
     }
 }
 void testGainFourGold(struct gameState* G){
   
        int m;
        for(m=0; m<4; m++){
            printf("PLAYER %d\n",m);
            int player = G->whoseTurn; 
        printf("Test 1) Testing player gains 4 Golds when two treasure cards are present their hand.\n");
        printf("preconditions: hand at 0, and at 4 are set to treasure cards.\n");
        printf("post conditions: User gains 4 Golds.\n");
            G->hand[player][0]= 26;
            G->hand[player][4]= 26;

            int result=play_treasure_map(player,G,0);
            printf("-Return Value...Expected: 1 Actual: %d\n\n", result);

            if(result == 1){
                printf("Test 1a) Testing 4 Golds are sent to top of deck.\n");
                printf("preconditions: hand at 0, and at 4 are set to treasure cards. No golds in deck.\n");
                printf("post conditions: Top of player deck should contain 4 gold cards.\n");

                int k;
                printf("Player %d Deck\n",m);
                
                for(k=G->deckCount[player] ; k > 0; k--){ 
                    if(k > G->deckCount[player]-4){
                        printf("%d  Expected: 6 (Gold) Actual: %d\n", k,G->deck[player][k]);
                    }else{
                        printf("%d  Actual: %d\n", k,G->deck[player][k]);
                    }
                } 
                printf("\n\n");
            endTurn(G);
            }
        
    }
     
 }
int main () {
  struct gameState G;
  int k[10] = { adventurer, treasure_map, embargo, village, minion, mine, cutpurse, 
           sea_hag, tribute, smithy };
 
  printf ("Starting Tests.\n\n");
  initializeGame(4, k, 1000, &G);
   testGainFourGold(&G);
   memset(&G, 23, sizeof(struct gameState));   // clear the game state (from template.c)
   int r = initializeGame(2, k,1000 , &G);              // initialize a new game (from template.c)
    testBothTreasuresDiscarded(&G);
   memset(&G, 23, sizeof(struct gameState));   // clear the game state (from template.c)
   r = initializeGame(4, k,1000 , &G);              // initialize a new game (from template.c)
   testOneTreasureMap(&G);
   memset(&G, 23, sizeof(struct gameState));   // clear the game state (from template.c)
   r = initializeGame(4, k,1000 , &G);              // initialize a new game (from template.c) 
 testZeroTreasureMap(&G);



  

  return 0;
}
    