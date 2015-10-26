 /*----------------------------------------------------------------------
  * Name: Susan Lee
  * Class: CS 362_400_F2015
  * Homework 3
  * Unit test for drawCard(int player, struct gameState *state);
  * -----------------------------------------------------------------------
  */
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

  /*assumptions:
   * 1) draws a card from the player's deck
   * 2) if deck is empty, places discard pile in deck and shuffles
   * 3) deck count is now equal to previous discard count, and current
   * discard count is now 0
   * 4) Once card is drawn, it is placed in player's hand
   * 5) player's hand count is increased by 1
   * 6) Card is drawns from player's deck
   * 7) player's deck is decreased by 1
   *
  */

void setDiscardDeck(int p, struct gameState *G);
void setDeck(int p, struct gameState *G);
int checkDrawCard(int p, struct gameState *post, int expected); 

int main (){
   
     int seed = 1000;
     int numPlayer = 2;
     int flag; //0=no cards in deck, 
     int r;
     int result = 0;
     bool pass = true;
     int p=0;

     int k[10] = { adventurer, council_room, feast, gardens, mine
          , remodel, smithy, village, baron, great_hall };
     struct gameState G;
     
     memset(&G, 23, sizeof(struct gameState));   // clear the game state
     r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

     printf("TESTING DRAW CARD\n");

     for(p=0; p<numPlayer; p++){
       printf("Testing for player %d\n", p+1);

      /*EDGE CASES*/
       //CHECK for 0 cards in deck
       printf("Testing for no cards in deck\n");
       flag = 0;
       G.deckCount[p] = 0;
       setDiscardDeck(p, &G);
       result = checkDrawCard(p, &G, flag);
       if (result == -1){
            pass = false;
       }

       //check for neg cards in deck
       printf("Testing for neg cards in deck\n");
       flag = 0;
       G.deckCount[p] = -5;
       setDiscardDeck(p, &G);
       result = checkDrawCard(p, &G, flag);
       if (result == -1){
            pass = false;
       }
       
       //testing for max cards in deck
       printf("Testing for max cards in deck\n");
       flag = 1;
       G.deckCount[p] = MAX_DECK;
       setDeck(p, &G);
       result = checkDrawCard(p, &G, flag);
       if (result == -1){
            pass = false;
       }

     
       /**NORMAL CASES**/
       printf("Testing for 10 cards in deck\n");
       flag = 1;
       G.deckCount[p] = 10;
       setDiscardDeck(p, &G);
       result = checkDrawCard(p, &G, flag);
       if (result == -1){
            pass = false;
       }

       //check for 0 cards in hand
       printf("Testing for 0 cards in hand\n");
       flag = 1;
       G.deckCount[p] = 10;
       G.handCount[p] =0;
       setDiscardDeck(p, &G);
       result = checkDrawCard(p, &G, flag);
       if (result == -1){
            pass = false;
       }




       if (pass == true){
         printf("ALL TESTS PASSED!\n");
       }else{
         printf("FAILURES\n");
       }

     }


  return 0;
} 


void setDiscardDeck(int p, struct gameState *G){
  int j;

  G->discardCount[p] = 0;
  for (j = 0; j < 10; j++){
    G->discard[p][j] = copper;
    G->discardCount[p]++;
   }
}

void setDeck(int p, struct gameState *G){
  int j;

  for (j = 0; j < G->deckCount[p]; j++){
    G->deck[p][j] = silver;
   }
}

int checkDrawCard(int p, struct gameState *post, int flag) {

     struct gameState pre;
     
     //copy the game state to compare pre and post values
     memcpy(&pre, post, sizeof(struct gameState));  

     drawCard(p, post);
     
     //print out results
     if(flag == 0){
       //expected deck count is the previous discardCount -1
       printf("Deck Count\t Expected: %d\t Result:%d\n", pre.discardCount[p]-1, post->deckCount[p]);    
       //check discard count
       printf("Discard Count\t Expected: %d\t Result:%d\n", flag, post->discardCount[p]);
     }else{
       printf("Deck Count\t Expected: %d\t Result:%d\n", pre.deckCount[p]-1, post->deckCount[p]);
       printf("Discard Count\t Expected: %d\t Result:%d\n", pre.discardCount[p], post->discardCount[p]);
       //check card drawn is now in hand
       printf("Drawn Card\t Expected: %d\t Result:%d\n", pre.deck[p][pre.deckCount[p]-1], post->hand[p][post->handCount[p]-1]);
      //check last card in hand is a silver (newly drawn card)
       printf("Drawn Card:\t Expected:5\t Result:%d\n", post->hand[p][post->handCount[p]-1]);
     }

     //check hand count
     printf("Hand Count\t Expected: %d\t Result:%d\n", pre.handCount[p]+1, post->handCount[p]);

     //int i;
     //for(i=0; i< pre.handCount[p]; i++){
     //  printf("prehand[%d][%d]: %d\n", p, i, pre.hand[p][i]);
     //}
     //for(i=0; i< post->handCount[p]; i++){
     //    printf("posthand[%d][%d]: %d\n", p, i, post->hand[p][i]);
     // }



     /***CHECK RESULTS***/
     if(flag == 0){
       //check deck count
       if (pre.discardCount[p]-1 != post->deckCount[p]){
            printf("Unexpected deck count\n");
            return -1;
       }
       //check discard count
       if (flag != post->discardCount[p]){
            printf("Unexpected discard count\n");
            return -1;
       }
     }else{
       //check deck count
       if (pre.deckCount[p]-1 != post->deckCount[p]){
            printf("Unexpected deck count\n");
            return -1;
       }
       //check card drawn is now in hand
       if (pre.deck[p][pre.deckCount[p]-1] != post->hand[p][post->handCount[p]-1]){
            printf("Unexpected discard count\n");
            return -1;
       }
       //check drawn card
       if(post->hand[p][post->handCount[p]-1] != 5){
         printf("Unexpected drawn card\n");
         return -1;
       }

     }

     //check hand count
     if (pre.handCount[p]+1 != post->handCount[p]){
          printf("Unexpected hand count\n");
          return -1;
     }

     return 0;
}

