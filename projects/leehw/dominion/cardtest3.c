/*----------------------------------------------------------------------
  * Name: Susan Lee
  * Class: CS 362_400_F2015
  * Homework 3
  * Card test for council card;
  * -----------------------------------------------------------------------
  */
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

/*******************************
Assumptions: 
1) Player gains 4 cards in their hand from their deck
  Player's hand is incremented by 4
  Player's deck is decremented by 4 
2) player gains 1 extra buy
3) Every other player gains 1 extra cazrd in their hand
  Other players' decks are decremented by 1
  Other players' hands are incremented by 1
4) Council card is discarded from hand
  Player's hand is decremented by 1
******************************/

void setDeck(struct gameState *G);
void setHand(struct gameState *G);
int checkCouncil(int p, struct gameState *post, int handPos);

int main (){
   
     int seed = 1000;
     int r,i;
     int result = 0;
     bool pass = true;
     int p=0;
     int handPos;

     int k[10] = { adventurer, council_room, feast, gardens, mine
          , remodel, smithy, village, baron, great_hall };
     struct gameState G;
     

     printf("TESTING COUNCIL CARD\n");

     for(p=0; p<MAX_PLAYERS; p++){
       
       switch(p){
         case 0:
           printf("Testing for council card at index 0 of hand\n");
           break;
         case 1: 
           printf("Testing for council card at last index of hand\n");
           break;
         case 2:
           printf("Normal testing mode\n");
           break;
         case 3:
           printf("Normal testing mode\n");
           break;
       }
       memset(&G, 23, sizeof(struct gameState));   // clear the game state
       r = initializeGame(MAX_PLAYERS, k, seed, &G); // initialize a new game
       //set deck for each player
       setDeck(&G);
       //change each player's hand, with at least 1 council card
       setHand(&G);
       //set handpos of council card
       for(i=0; i< G.handCount[p]; i++){
         if(G.hand[p][i] == council_room){
           handPos = i;
         }
       }

       result = checkCouncil(p, &G, handPos);
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


void setDeck(struct gameState *G){
  int j, p;

  for(p=0; p < MAX_PLAYERS; p++){
    G->deckCount[p] = 0;

    switch(p){
      case 0:
        for (j = 0; j < 10; j++){
          G->deck[p][j] = baron ;
          G->deckCount[p]++;
          j++;
          G->deck[p][j] = feast;
          G->deckCount[p]++;
        }
        break;
      case 1:
        for (j = 0; j < 10; j++){
          G->deck[p][j] = village;
          G->deckCount[p]++;
          j++;
          G->deck[p][j] = gardens;
          G->deckCount[p]++;
        }
        break;
      case 2:
        for (j = 0; j < 10; j++){
          G->deck[p][j] = sea_hag;
          G->deckCount[p]++;
          j++;
          G->deck[p][j] = mine;
          G->deckCount[p]++;
        }
        break;
      case 3:
        for (j = 0; j < 10; j++){
          G->deck[p][j] = adventurer;
          G->deckCount[p]++;
          j++;
          G->deck[p][j] = remodel;
          G->deckCount[p]++;
        }
        break;
    }
  }
}

void setHand(struct gameState *G){
  int j, p;

  for(p=0; p < MAX_PLAYERS; p++){
    switch(p){
      case 0:
        G->handCount[p] = 10;
        for(j = 0; j < G->handCount[p]; j++){
          if(j== 0) {
            G->hand[p][j] = council_room;
          }else{
            G->hand[p][j] = copper;
          }
        }
        break;
      case 1:
        G->handCount[p] = 15;
        for(j = 0; j < G->handCount[p]; j++){
          if(j== 15) {
            G->hand[p][j] = council_room;
          }else{
            G->hand[p][j] = silver;
          }
        }
        break;
      case 2:
        G->handCount[p] = 12;
        for(j = 0; j < G->handCount[p]; j++){
          if(j== 5) {
            G->hand[p][j] = council_room;
          }else{
            G->hand[p][j] = gold;
          }
        }
        break;
      case 3:
        G->handCount[p] = 5;
        for(j = 0; j < G->handCount[p]; j++){
          if(j== 2) {
            G->hand[p][j] = council_room;
          }else{
            G->hand[p][j] = gardens;
          }
        }
        break;
    }
  }
}

int checkCouncil(int p, struct gameState *post, int handPos) {

     struct gameState pre;
     int i;
     int currentPlayer;
     bool fail = false;
     int newCard1, newCard2, newCard3, newCard4;
     int deckCard1, deckCard2, deckCard3, deckCard4;
     int postCouncil, preCouncil=0;
     
     //copy the game state to compare pre and post values
     memcpy(&pre, post, sizeof(struct gameState));  

     councilAction(p, post, handPos);
     
     //expected hand count
     printf("Hand Count\t Expected: %d\t Result:%d\n", pre.handCount[p]+2, post->handCount[p]);    
     //check deck count
     printf("Deck Count\t Expected: %d\t Result:%d\n", pre.deckCount[p]-4, post->deckCount[p]);
     //check expected cards added to hand
     //assumes no shuffling is done
     newCard1 = post->hand[p][pre.handCount[p]];
     newCard2 = post->hand[p][pre.handCount[p]+1];
     newCard3 = post->hand[p][pre.handCount[p]+2];
     newCard4 = post->hand[p][handPos];
     deckCard1 = pre.deck[p][pre.deckCount[p]-1];
     deckCard2 = pre.deck[p][pre.deckCount[p]-2];
     deckCard3 = pre.deck[p][pre.deckCount[p]-3];
     deckCard4 = pre.deck[p][pre.deckCount[p]-4];
     printf("Added Cards (No.1)\t Expected: %d\t Result:%d\n", deckCard1, newCard1);
     printf("Added Cards (No.2)\t Expected: %d\t Result:%d\n", deckCard2, newCard2);
     printf("Added Cards (No.3)\t Expected: %d\t Result:%d\n", deckCard3, newCard3);
     printf("Added Cards (No.4)\t Expected: %d\t Result:%d\n", deckCard4, newCard4);

     //check number of buys
     printf("Buys\t Expected: %d\t Result:%d\n", pre.numBuys+1, post->numBuys);

     //check card count for all other players
     currentPlayer = p;
     for(i=0; i< MAX_PLAYERS; i++){
       if(i != currentPlayer){
         printf("HandCount p%d\t Expected: %d\t Result:%d\n", i+1, pre.handCount[i]+1, post->handCount[i]);
         printf("DeckCount p%d\t Expected: %d\t Result:%d\n", i+1, pre.deckCount[i]-1, post->deckCount[i]);
         printf("AddedCard p%d\t Expected: %d\t Result:%d\n", i+1, pre.deck[i][pre.deckCount[i]-1], post->hand[i][post->handCount[i]-1]);
       }
     }

     //check count of coins has not changed
     printf("Coins\t Expected: %d\t Result:%d\n", pre.coins, post->coins);

     //check Council Card has been discarded
     preCouncil=0;
     postCouncil=0;
     for(i=0; i< pre.handCount[p]; i++){
     //  printf("prehand[%d][%d]: %d\n", p, i, pre.hand[p][i]);
       if(pre.hand[p][i] == council_room){
         preCouncil++;
       }
     }
     //iterate through post hand - NOTE: no new smithy cards were added from deck to hand
     for(i=0; i< post->handCount[p]; i++){
     //    printf("posthand[%d][%d]: %d\n", p, i, post->hand[p][i]);
       if(post->hand[p][i] == council_room){
         postCouncil++;
       }
     }
     printf("Council count\t Expected: %d\t Result:%d\n", preCouncil-1, postCouncil);
     //check discard count incremenetd
     printf("Discard count \t Expected: %d\t Result:%d\n", pre.discardCount[p]+1, post->discardCount[p]);


     /***CHECK RESULTS***/
     if(pre.handCount[p]+2 != post->handCount[p]){
       printf("Unexpected handcount\n");
       fail = true;
     }  
     if(pre.deckCount[p]-3 != post->deckCount[p]){
       printf("Unexpected deckCount\n");
       fail = true;
     }
     if((deckCard1 != newCard1) || (deckCard2 != newCard2) || (deckCard3!= newCard3) ||(deckCard4 != newCard4)){
       printf("Unexpected card added to hand\n");
       fail = true;
     }
     
     if(pre.numBuys+1 !=post->numBuys){
        printf("Unexpected number of buys\n");
        fail = true;
     };
     //check card count for other players
     for(i=0; i< MAX_PLAYERS; i++){
       if(i != currentPlayer){
         if(pre.handCount[i]+1 !=post->handCount[i]){
           printf("Unexpected Handcount p%d\n", i+1);
           fail = true;
         };
         if(pre.deckCount[i]-1 != post->deckCount[i]){
           printf("Unexpected Deckcount p%d\n", i+1);
           fail = true;
         }
         if(pre.deck[i][pre.deckCount[i]-1] != post->hand[i][post->handCount[i]-1]){
           printf("Unexpected cardAdded p%d\n", i+1);
           fail = true;
         }
       }
     }
     //check coin count has not changed
     if(pre.coins != post->coins){
       printf("Unexpected change in coin count\n");
       fail = true;
     }
     //check council count
     if(preCouncil-1 != postCouncil){
       printf("Council card not discarded\n");
       fail = true;
     }

     //check discard pile incremented
     if(pre.discardCount[p]+1 != post->discardCount[p]){
       printf("Discard count not incremented\n");
       fail = true;
     }

     if(fail ==true){
       return -1;
     }

     return 0;
}

