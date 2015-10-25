 /*----------------------------------------------------------------------
  * Name: Susan Lee
  * Class: CS 362_400_F2015
  * Homework 3
  * Unit test for updateCoins(int player, struct gameState *state, int bonus)
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
   * 1) resets coins for player's hand to 0
   * 2) adds 1 for copper coins
   * 3) adds 2 for siler coins
   * 4) adds 3 for gold coins
   * 5) adds passed in value for bonus coins
   * 6) total coins cannot be more than max coin value in the game
   *  a) copper = 60 -(7*numplayers)
   *  b) siler = 40
   *  c) gold = 30
   * 7) total coin value cannot be negative
   * 8) total coins do not remain as a stat in gamestate for the player
   *    it simply is calculated when needed
   *
  */

//sets the hand equal to all copper, silver, gold, nothing, or a mix.  
//if a mix, the total coins in the hand must be divisor of 3.
void setCoins(int p, struct gameState *G, int numCoins, int flag);

int checkUpdateCoins(int p, struct gameState *post, int numCoins, int bonus, int expected);

int main (){
   
     int seed = 1000;
     int numPlayer = 2;
     int r;
     int numCoins=0;
     int bonus =0;
     int flag = 0; //0=null, 1=all copper, 2=all silver, 3=all gold, 4=mix
     int result = 0;
     bool pass = true;
     int p=0;

     int k[10] = { adventurer, council_room, feast, gardens, mine
          , remodel, smithy, village, baron, great_hall };
     struct gameState G;
     
     memset(&G, 23, sizeof(struct gameState));   // clear the game state
     r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

     printf("TESTING UPDATE COINS\n");

     for(p=0; p<numPlayer; p++){
       printf("Testing for player %d\n", p+1);

      /*EDGE CASES*/
       //CHECK Fof 0 count
       printf("Testing for no coins\n");
       numCoins =0;
       bonus = 0;
       flag = 0;
       setCoins(p, &G, numCoins, flag);
       result = checkUpdateCoins(p, &G, numCoins, bonus, 0);
       if (result == -1){
            pass = false;
       }
       
       //CHECK For all copper out of bounds
       printf("Testing for all copper more than max allowed, no bonus\n");
       numCoins =60;
       bonus = 0;
       flag = 1;
       setCoins(p, &G, numCoins, flag);
       result = checkUpdateCoins(p, &G, numCoins, bonus, 60);
       if (result == -1){
            pass = false;
       }
       
       //CHECK For mix + bonus for max hand
       printf("Testing for all gold, 100 bonus for max hand\n");
       numCoins = MAX_HAND;
       bonus = 100;
       flag = 3;
       setCoins(p, &G, numCoins, flag);
       result = checkUpdateCoins(p, &G, numCoins, bonus, 1600);
       if (result == -1){
            pass = false;
       }
       
       /****REGULAR CASES****/
       //CHECK For all copper
       printf("Testing for all copper, no bonus\n");
       numCoins =15;
       bonus = 0;
       flag = 1;
       setCoins(p, &G, numCoins, flag);
       result = checkUpdateCoins(p, &G, numCoins, bonus, 15);
       if (result == -1){
            pass = false;
       }

       //CHECK For all silver
       printf("Testing for all silver, no bonus\n");
       numCoins =15;
       bonus = 0;
       flag = 2;
       setCoins(p, &G, numCoins, flag);
       result = checkUpdateCoins(p, &G, numCoins, bonus, 30);
       if (result == -1){
            pass = false;
       }

       //CHECK For all gold
       printf("Testing for all gold, no bonus\n");
       numCoins =15;
       bonus = 0;
       flag = 3;
       setCoins(p, &G, numCoins, flag);
       printf("Hand is%d\n", G.handCount[p]);
       result = checkUpdateCoins(p, &G, numCoins, bonus, 45);
       if (result == -1){
            pass = false;
       }
       
       //CHECK For mix
       printf("Testing for mix, no bonus\n");
       numCoins =15;
       bonus = 0;
       flag = 4;
       setCoins(p, &G, numCoins, flag);
       result = checkUpdateCoins(p, &G, numCoins, bonus, 30);
       if (result == -1){
            pass = false;
       }
       
       //CHECK For mix + bonus
       printf("Testing for mix, 20 bonus\n");
       numCoins =15;
       bonus = 20;
       flag = 4;
       setCoins(p, &G, numCoins, flag);
       result = checkUpdateCoins(p, &G, numCoins, bonus, 50);
       if (result == -1){
            pass = false;
      } 
       
       //CHECK For some copper in hand
       printf("Testing for 5 copper, 3 other cards\n");
       numCoins =5;
       bonus = 0;
       flag = 1;
       setCoins(p, &G, numCoins, flag);
       G.handCount[p] = 8;
       G.hand[p][5] = baron;
       G.hand[p][6] = duchy;
       G.hand[p][7] = ambassador;

       result = checkUpdateCoins(p, &G, numCoins, bonus, 5);
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



void setCoins(int p, struct gameState *G, int numCoins, int flag){
  int j;
  G->handCount[p] = 0;

  switch(flag){
    //no coins, no bonus
    case 0:
      break;
    // all copper
    case 1:
      for (j = 0; j < numCoins; j++){
        G->hand[p][j] = copper;
        G->handCount[p]++;
       }
      break;
    //all silver
    case 2: 
      for (j = 0; j < numCoins; j++){
        G->hand[p][j] = silver;
        G->handCount[p]++;
       }
      break;
    //all gold
    case 3:
      for (j = 0; j < numCoins; j++){
        G->hand[p][j] = gold;
        G->handCount[p]++;
       }
      break;
    //mix
    case 4:
      for (j = 0; j < numCoins/3; j++){
        G->hand[p][j] = copper;
        G->handCount[p]++;
       }
      for (j=numCoins/3 ; j < 2*(numCoins/3); j++){
        G->hand[p][j] = silver;
        G->handCount[p]++;
       }
      for (j=2*(numCoins/3); j < 3*(numCoins/3); j++){
        G->hand[p][j] = gold;
        G->handCount[p]++;
       }
      break;
  }
}

int checkUpdateCoins(int p, struct gameState *post, int numCoins, int bonus, int expected) {

     struct gameState pre;
     
     //copy the game state to compare pre and post values
     memcpy(&pre, post, sizeof(struct gameState));   

     updateCoins(p, post, bonus);
     
     //print out results
     printf("Total Coins\t Expected: %d\t Result:%d\n", expected, post->coins);

     /***CHECK RESULTS***/
     //check coint count
     if (expected != post->coins){
          printf("Unexpected coin count\n");
          return -1;
     }
     return 0;
}

