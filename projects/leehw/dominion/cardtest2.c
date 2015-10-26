/*---------------------------------------------------------------------
  * Name: Susan Lee
  * Class: CS 362_400_F2015
  * Homework 3
  * Card test for adventurer card;
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
int checkAdventurer(int p, struct gameState *post);

int main (){
   
     int seed = 1000;
     int r;
     int result = 0;
     bool pass = true;
     int p=0;

     int k[10] = { adventurer, council_room, feast, gardens, mine
          , remodel, smithy, village, baron, great_hall };
     struct gameState G;
     

     printf("TESTING ADVENTURER CARD\n");

     for(p=0; p<MAX_PLAYERS; p++){
       switch(p){
         case 0:
           printf("Testing for 0 treasure cards in deck\n");
           break;
         case 1: 
           printf("Testing for all gold cards in deck\n");
           break;
         case 2:
           printf("Testing for 2 treasure cards in deck\n");
           break;
         case 3:
           printf("Testing for 4 treasure cards in deck\n");
           break;
       }
       memset(&G, 23, sizeof(struct gameState));   // clear the game state
       r = initializeGame(MAX_PLAYERS, k, seed, &G); // initialize a new game
       setDeck(&G);
       //change each player's hand, with at least 1 adventurer card
       setHand(&G);
       
       result = checkAdventurer(p, &G);
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
      //no treasure cards
      case 0:
        for (j = 0; j < 10; j++){
          G->deck[p][j] = baron ;
          G->deckCount[p]++;
          j++;
          G->deck[p][j] = feast;
          G->deckCount[p]++;
        }
        break;
      //all gold
      case 1:
        for (j = 0; j < 10; j++){
          G->deck[p][j] = gold;
          G->deckCount[p]++;
          j++;
          G->deck[p][j] = gardens;
          G->deckCount[p]++;
        }
        break;
      //2 treasure cards
      case 2:
        j=0;
        G->deck[p][j] = gold;
        j++;
        G->deckCount[p]++;
        G->deck[p][j] = gold;
        G->deckCount[p]++;
        for (j = j+1; j < 10; j++){
          G->deck[p][j] = sea_hag;
          G->deckCount[p]++;
          j++;
          G->deck[p][j] = mine;
          G->deckCount[p]++;
        }
        break;
      // 4 treasure cards
      case 3:
        j=0;
        G->deck[p][j] = gold;
        j++;
        G->deckCount[p]++;
        G->deck[p][j] = gold;
        j++;
        G->deckCount[p]++;
        G->deck[p][j] = gold;
        j++;
        G->deckCount[p]++;
        G->deck[p][j] = gold;
        G->deckCount[p]++;
        for (j = j+1; j < 10; j++){
          G->deck[p][j] = smithy;
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
          if(j== 1) {
            G->hand[p][j] = adventurer;
          }else{
            G->hand[p][j] = copper;
          }
        }
        break;
      case 1:
        G->handCount[p] = 15;
        for(j = 0; j < G->handCount[p]; j++){
          if(j== 3) {
            G->hand[p][j] = adventurer;
          }else{
            G->hand[p][j] = silver;
          }
        }
        break;
      case 2:
        G->handCount[p] = 12;
        for(j = 0; j < G->handCount[p]; j++){
          if(j== 5) {
            G->hand[p][j] = adventurer;
          }else{
            G->hand[p][j] = gold;
          }
        }
        break;
      case 3:
        G->handCount[p] = 5;
        for(j = 0; j < G->handCount[p]; j++){
          if(j== 2) {
            G->hand[p][j] = adventurer;
          }else{
            G->hand[p][j] = council_room;
          }
        }
        break;
    }
  }
}

int checkAdventurer(int p, struct gameState *post) {

     struct gameState pre;
     int i,j;
     int currentPlayer;
     int temphand[MAX_HAND];
     int result; //to store the number of cards cycled through
     int treasureCard1, treasureCard2;
     int preAdventurer, postAdventurer;
     bool fail = false;
     
     //copy the game state to compare pre and post values
     memcpy(&pre, post, sizeof(struct gameState));  

     result = adventurerAction(p, post, temphand);
     //printf("Result is %d\n", result);
     //printf("discardCard is %d\n", post->discardCount[p]);

     if(p != 0){
       //check hand count
       //should be +2 treasure cards -1 discarded adventurer card
       printf("Hand Count\t Expected:%d\t Result:%d\n", pre.handCount[p]+1, post->handCount[p]);
       
       //check deck count
       printf("Deck Count\t Expected:%d\t Result:%d\n", pre.deckCount[p]-result, post->deckCount[p]);

       //check discard pile
       //should be + the cards cycled through and the discarded adventurer card
       printf("Discard Count\t Expected:%d\t Result:%d\n", pre.discardCount[p]+result+1, post->discardCount[p]);

       //check cards in discard pile came from player's hand

       //check cards came from player's deck
       //set treasure cards
       for(i=pre.deckCount[p]-1; i>=0; i--){
         if((pre.deck[p][i] == copper) || (pre.deck[p][i] == silver) || (pre.deck[p][i] == gold)){
           treasureCard1 = pre.deck[p][i];
           for(j=i-1; j>=0; j--){
             if((pre.deck[p][j] == copper) || (pre.deck[p][j] == silver) || (pre.deck[p][j] == gold)){
               treasureCard2 = pre.deck[p][j];
               break;
              }
           }
           break;
         }
       }
//       printf("TreasureCard1 %d\n", treasureCard1);
//       printf("TreasureCard2 %d\n", treasureCard2);


       //check card count for all other players
       currentPlayer = p;
       for(i=0; i< MAX_PLAYERS; i++){
         if(i != currentPlayer)
           printf("HandCount for player %d\t Expected: %d\t Result:%d\n", i+1, pre.handCount[i], post->handCount[i]);
       }

       //check count of coins has not changed
       printf("Coins\t Expected: %d\t Result:%d\n", pre.coins, post->coins);

       //check Adventurer Card has been discarded
       preAdventurer=0;
       postAdventurer=0;
       for(i=0; i< pre.handCount[p]; i++){
       //  printf("prehand[%d][%d]: %d\n", p, i, pre.hand[p][i]);
         if(pre.hand[p][i] == adventurer){
           preAdventurer++;
         }
       }
       //iterate through post hand 
       for(i=0; i< post->handCount[p]; i++){
        //   printf("posthand[%d][%d]: %d\n", p, i, post->hand[p][i]);
         if(post->hand[p][i] == adventurer){
           postAdventurer++;
         }
       }
       printf("Adventurer count\t Expected: %d\t Result:%d\n", preAdventurer-1, postAdventurer);
     

       /***CHECK RESULTS***/
       if(pre.handCount[p]+1 != post->handCount[p]){
         printf("Unexpected handcount\n");
         fail = true;
       }  
       
       if(pre.deckCount[p]-2 != post->deckCount[p]){
         printf("Unexcpected deckCount\n");
         fail = true;
       }
       
       if(pre.discardCount[p]+result+1 != post->discardCount[p]){
         printf("Unexcpected discardCount\n");
         fail = true;
       }
       
       //since no handpos is passed in to function, and no discarding
       //is called in code, can safely assume that the last two cards
       //post hand will be the found treasure cards
       if((post->hand[p][post->handCount[p]-2] != treasureCard1) || (post->hand[p][post->handCount[p]-1] != treasureCard2)){
         printf("Treasurer card not added to hand\n");
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
       //check adventurer count
       if(preAdventurer-1 != postAdventurer){
         printf("Adventurer card not discarded\n");
         fail = true;
       }
    //for 0 deck
     }else{
       //check hand count
       //should be +2 treasure cards -1 discarded adventurer card
       printf("Hand Count\t Expected:%d\t Result:%d\n", pre.handCount[p], post->handCount[p]);
       
       //check deck count
       printf("Deck Count\t Expected:%d\t Result:%d\n", pre.deckCount[p]-result, post->deckCount[p]);

       //check discard pile
       //should be + the cards cycled through and the discarded adventurer card
       printf("Discard Count\t Expected:%d\t Result:%d\n", pre.discardCount[p], post->discardCount[p]);
       
       //check results
       if(pre.handCount[p] != post->handCount[p]){
         printf("Unexpected handcount\n");
         fail = true;
       }  
       
       if(pre.deckCount[p] != post->deckCount[p]){
         printf("Unexcpected deckCount\n");
         fail = true;
       }
       
       if(pre.discardCount[p] != post->discardCount[p]){
         printf("Unexcpected discardCount\n");
         fail = true;
       }
     }

     if(fail ==true){
       return -1;
     }

     return 0;
}

