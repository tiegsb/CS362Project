/* -----------------------------------------------------------------------
 * Name: Susan Lee
 * Class: CS 362_400_F2015
 * Homework 3
 * Unit test for shuffle(int player, struct gameState *state)
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
     1) If the player only has 0 or 1 card, no shuffling required
     2) Same number of cards are in the player's hand at the beginning and end of the function call
     3) The deck holds the same number of each card in the player's hand
     4) EXPECT a different ordering of the cards, but not necessarily true
*/

void setPlayerDecks(int p, struct gameState *G);
int checkShuffleDeck(int p, struct gameState *post, int expected);

int main(){
     int seed = 1000;
     int numPlayer = 2;
     int result = 0;
     bool pass = true;
     int p=0;
     int r;

     int k[10] = { adventurer, council_room, feast, gardens, mine
          , remodel, smithy, village, baron, great_hall };
     struct gameState G;
     
     memset(&G, 23, sizeof(struct gameState));   // clear the game state
     r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

     printf("TESTING SHUFFLE DECK\n");

     for(p=0; p<numPlayer; p++){
       printf("Testing for player %d\n", p+1);
       /**EDGE CASES***/
       //check for 0 count
       G.deckCount[p] = 0;
       printf("Testing DeckCount of 0\n");
       result = checkShuffleDeck(p, &G, -1);
       if (result == -1){
            pass = false;
       }
       //check for 1 count
       G.deckCount[p] = 1;
       printf("Testing DeckCount of 1\n");
       result = checkShuffleDeck(p, &G, 0);
       if (result == -1){
            pass = false;
       }

       //check for -1
       G.deckCount[p] = -1;
       printf("Testing DeckCount of -1\n");
       result = checkShuffleDeck(p, &G, -1);
       if (result == -1){
            pass = false;
       }
       
       //check for max 
       G.deckCount[p] = MAX_DECK;

       printf("Testing DeckCount of %d\n", MAX_DECK);
       setPlayerDecks(p, &G);
       result = checkShuffleDeck(p, &G, 0);
       if (result == -1){
            pass = false;
       }
      
       /**NORMAL CASES***/
       //check for 15
       G.deckCount[p] = 15;

       printf("Testing DeckCount of 15\n");
       setPlayerDecks(p, &G);
       result = checkShuffleDeck(p, &G, 0);
       if (result == -1){
            pass = false;
       }


       if (pass == true){
            printf("All tests passed!\n");
       }
     }

  return 0;
}

void setPlayerDecks(int p, struct gameState *G){
  int j;

  for (j = 0; j < 3; j++){
    G->deck[p][j] = estate;
   }
  for (j = 3; j < G->deckCount[p]; j++){
    G->deck[p][j] = copper;
  }
}
    
    
    
int checkShuffleDeck(int p, struct gameState *post, int expected) {
     struct gameState pre;
     int i, j, k;
     int result;     //to capture result from function call
     int card; //to capture the current card being counted
     int preCounter = 0; //to keep count of the quantity of each card
     int postCounter = 0; //to keep count for the post gamestate

     //copy the game state to compare pre and post values
     memcpy(&pre, post, sizeof(struct gameState));   

     result = shuffle(p, post);

     //print out results
     printf("DeckCount\t Expected:%d\t Result:%d\n", expected, result);
     printf("DeckCount\t Before:%d\t After:%d\n", pre.deckCount[p], post->deckCount[p]);

//    printf("ITERATE THROUGH PRE\n");
//    for(j = 0; j< pre.deckCount[p]; j++){
//      printf("deck[%d]: %d\n", j, pre.deck[p][j]);
//    }
//    printf("ITERATE THROUGH Post\n");
//    for(j = 0; j< post->deckCount[p]; j++){
//      printf("deck[%d]: %d\n", j, post->deck[p][j]);
//    }

     /***CHECK RESULTS***/
     //check return value of function
     if (expected != result){
          printf("Unexpected Return value\n");
          return -1;
     }
     //check if deckcount changed
     if (pre.deckCount[p] != post->deckCount[p]){
          printf("DeckCount changed\n");
          return -1;
     }
     //check if same number of each card in hand
     for (i = 0; i < pre.deckCount[p]; i++){
          //check to see if card has already been checked
          if (post->deck[p][i] != -1){
               card = post->deck[p][i];
               postCounter++;
               for (j = i + 1; j < pre.deckCount[p]; j++){
                    if (post->deck[p][j] == card){
                         //increment post counter
                         postCounter++;
                         //set value at that index to -1, so we can skip over in next iteration
                         post->deck[p][j] = -1;
                    }
               }
               for (k = 0; k < pre.deckCount[p]; k++){
                    if (pre.deck[p][k] == card){
                         preCounter++;
                    }
               }
          }
     }
     printf("Qty of Cards\t Before:%d\t After:%d\n", preCounter, postCounter);
     if (preCounter != postCounter){
          printf("Number of each card changed\n");
          return -1;
     }

     //check if order is different?
    return 0;
}
