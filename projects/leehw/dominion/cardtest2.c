
/*----------------------------------------------------------------------
  * Name: Susan Lee
  * Class: CS 362_400_F2015
  * Homework 3
  * Card test for smithy card;
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
 * Adventurer
 * *****************************
The adventurer card enables the player to go through the cards in 
their deck until they find 2 treasure cards.  It does this by 
looping through the deck until the drawntreasure count equals 2.  
Once inside the loop, it checks to see if there is at least 1 card 
in the deck to draw from, if not, it calls the shuffle() function 
to return shuffled cards from the discarded pile into the deck.  
Then it calls the drawCard() function to place another card in the 
player’s hand.  That card is then set to the cardDrawn variable, 
  and inspected to see if it is a treasure card (copper, silver, or gold).  
  If it is, the drawntreasure count is incremented, else the card 
  is removed from the player’s hand to a temporary hand.

  Once the player draws 2 treasure cards, the loop ends, and the 
  other non-treasure cards that were revealed are discarded.  
  This is done by looping through the temporary hand, and placing 
  each card in the player’s discard pile.  

Assumptions: 
1) Checks to see if drawn card is a treasure card
2) If it is, increments count
3) If drawn card is not a treasure card, then it is placed in a temphand.
4) All drawn cards that are not treasure cards should be in temphand
5) All cards in temphand should be placed in player's discard pile, discard pile should incrememnt by that amount
6) Once two treasure cards are found, loop ends.
7) Adventurer card should be discarded as well
  */

void setDeck(struct gameState *G);
void setHand(struct gameState *G);
int checkSmithy(int p, struct gameState *post, int handPos);

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
     

     printf("TESTING SMITHY CARD\n");

     for(p=0; p<MAX_PLAYERS; p++){
       printf("Testing for player %d\n", p+1);
       memset(&G, 23, sizeof(struct gameState));   // clear the game state
       r = initializeGame(MAX_PLAYERS, k, seed, &G); // initialize a new game
       //set deck for each player
       setDeck(&G);
       //change each player's hand, with at least 1 smithy card
       setHand(&G);
       //set handpos of smithy card
       for(i=0; i< G.handCount[p]; i++){
         if(G.hand[p][i] == smithy){
           handPos = i;
         }
       }

       result = checkSmithy(p, &G, handPos);
       if (result == -1){
            pass = false;
       //if no treasure cards
       //if 1 treasure card
       //if 2 or more treasure cards
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
        }
        break;
      case 1:
        for (j = 0; j < 10; j++){
          G->deck[p][j] = village;
          G->deckCount[p]++;
        }
        break;
      case 2:
        for (j = 0; j < 10; j++){
          G->deck[p][j] = sea_hag;
          G->deckCount[p]++;
        }
        break;
      case 3:
        for (j = 0; j < 10; j++){
          G->deck[p][j] = adventurer;
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
          if(j== 1) {
            G->hand[p][j] = smithy;
          }else{
            G->hand[p][j] = copper;
          }
        }
        break;
      case 1:
        G->handCount[p] = 15;
        for(j = 0; j < G->handCount[p]; j++){
          if(j== 3) {
            G->hand[p][j] = smithy;
          }else{
            G->hand[p][j] = silver;
          }
        }
        break;
      case 2:
        G->handCount[p] = 12;
        for(j = 0; j < G->handCount[p]; j++){
          if(j== 5) {
            G->hand[p][j] = smithy;
          }else{
            G->hand[p][j] = gold;
          }
        }
        break;
      case 3:
        G->handCount[p] = 5;
        for(j = 0; j < G->handCount[p]; j++){
          if(j== 2) {
            G->hand[p][j] = smithy;
          }else{
            G->hand[p][j] = council_room;
          }
        }
        break;
    }
  }
}

int checkSmithy(int p, struct gameState *post, int handPos) {

     struct gameState pre;
     int i;
     int currentPlayer;
     bool found = false;
     bool fail = false;
     int newCard1, newCard2, newCard3;
     int deckCard1, deckCard2, deckCard3;
     int postSmithy, preSmithy=0;
     
     //copy the game state to compare pre and post values
     memcpy(&pre, post, sizeof(struct gameState));  

     smithyAction(p, post, handPos);
     
     //expected hand count
     printf("Hand Count\t Expected: %d\t Result:%d\n", pre.handCount[p]+2, post->handCount[p]);    
     //check deck count
     printf("Deck Count\t Expected: %d\t Result:%d\n", pre.deckCount[p]-3, post->deckCount[p]);
     //check cards added to hand
     newCard1 = post->hand[p][pre.handCount[p]];
     newCard2 = post->hand[p][pre.handCount[p]+1];
     newCard3 = post->hand[p][pre.handCount[p]+2];
     deckCard1 = pre.deck[p][pre.deckCount[p]-1];
     deckCard2 = pre.deck[p][pre.deckCount[p]-2];
     deckCard3 = pre.deck[p][pre.deckCount[p]-3];
     printf("Added Cards (No.1)\t Expected: %d\t Result:%d\n", deckCard1, newCard1);
     printf("Added Cards (No.2)\t Expected: %d\t Result:%d\n", deckCard2, newCard2);
     printf("Added Cards (No.3)\t Expected: %d\t Result:%d\n", deckCard3, newCard3);

     //check cards came from player's deck
     //check for first new card
     for(i=0; i < pre.deckCount[p]; i++){
       if(pre.deck[p][i] == newCard1){
         found = true;
         break;
       }
     }
     //check for second new card
     for(i=0; i < pre.deckCount[p]; i++){
       if(pre.deck[p][i] == newCard2){
         found = true;
         break;
       }
     }
     //check for third new card
     for(i=0; i < pre.deckCount[p]; i++){
       if(pre.deck[p][i] == newCard3){
         found = true;
         break;
       }
     }

     //check card count for all other players
     currentPlayer = p;
     for(i=0; i< MAX_PLAYERS; i++){
       if(i != currentPlayer)
         printf("HandCount for player %d\t Expected: %d\t Result:%d\n", i+1, pre.handCount[i], post->handCount[i]);
     }

     //check count of coins has not changed
     printf("Coins\t Expected: %d\t Result:%d\n", pre.coins, post->coins);

     //check Smithy Card has been discarded
     preSmithy=0;
     postSmithy=0;
     for(i=0; i< pre.handCount[p]; i++){
     //  printf("prehand[%d][%d]: %d\n", p, i, pre.hand[p][i]);
       if(pre.hand[p][i] == smithy){
         preSmithy++;
       }
     }
     //iterate through post hand - NOTE: no new smithy cards were added from deck to hand
     for(i=0; i< post->handCount[p]; i++){
     //    printf("posthand[%d][%d]: %d\n", p, i, post->hand[p][i]);
       if(post->hand[p][i] == smithy){
         postSmithy++;
       }
     }
     printf("Smithy count\t Expected: %d\t Result:%d\n", preSmithy-1, postSmithy);
     //check discard count incremenetd
     printf("Discard count \t Expected: %d\t Result:%d\n", pre.discardCount[p]+1, post->discardCount[p]);


     /***CHECK RESULTS***/
     if(pre.handCount[p]+2 != post->handCount[p]){
       printf("Unexpected handcount\n");
       fail = true;
     }  
     if(pre.deckCount[p]-3 != post->deckCount[p]){
       printf("Unexcpected deckCount\n");
       fail = true;
     }
     if((deckCard1 != newCard1) || (deckCard2 != newCard2) || (deckCard3!= newCard3)){
       printf("Unexpected card added to hand\n");
       fail = true;
     }
     if(found != true){
       printf("New Card not found in player's previous deck\n");
       fail = true;
     }
     //check card count for other players
     for(i=0; i< MAX_PLAYERS; i++){
       if(i != currentPlayer)
         if(pre.handCount[i] != post->handCount[i]){
           printf("Unexpected handcount change in other player\n");
           fail = true;
           break;
         }
     }
     //check coin count has not changed
     if(pre.coins != post->coins){
       printf("Unexpected change in coin count\n");
       return -1;
       fail = true;
     }
     //check smithy count
     if(preSmithy-1 != postSmithy){
       printf("Smithy card not discarded\n");
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

