/**
*                  author:   Kayla Fitzsimmons
*                 course:   Software Engineering II
*                     term:   Fall 2015
*                       file:    randomtestcard.c
*        file contents:    Random Test Suite
*                     card:   Mine
*  card description:   trash one treasure card from your hand and gain one that
*                                   is worth no more than 3 more coin
*   
**/
#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.h"
#include "randomizer.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>  
#include <time.h>       
#include <math.h>
#include "rngs.h"

#define TESTS 3000000
#define MAX_DISCARD 500
#define MORE 0

int pick_trash_card(struct gameState * state){
    
    
    int trash_card_idx;
    do{
      trash_card_idx= (rand()%5)+1;
        
    }while( trash_card_idx<1 ||  trash_card_idx> 4);
    return trash_card_idx;
}
/**
*  pick_gain_card
*  param: state, gameState pointer
*  return: gain card
*  details: Choses the gain card
**/
int pick_gain_card(struct gameState * state){
    
    int gain_card = (rand()%7)+3;
    
    return gain_card;
    
}
/**
*  is_treasure
*  param: card 
*  return: true if treasure
*  details: Tests if a card is a treasure
**/
int is_treasure(int card){
    
     if( card >6 || card < 4){
         return -1;
     }
     return 0;
    
}

/**
*  cost_legal
*  param: trash_card 
*  param: gain_card 
*  return: true if legal
*  details: Tests that gain card costs at most 3
*                 coins more than the trash card       
**/
int cost_legal(int trash_card, int gain_card){
   
    if(getCost(trash_card ) <= getCost(gain_card)-3) {
        return 0; 
    }  
    return -1;
}
/**
*  test_mine
*  param: seed, random to init game
*  return: 0 on success
*  details: contains oracle, runs tests, outputs results to stdout/ file
**/
int test_mine(int seed){

    
    FILE*  fp = fopen("randomtestcard.out", "w");
    int passed=0;
    int failed=0;
    printf ("Starting Random Tests for Mine Card...\n\n");  
    int test_card = 11 ;
    int rounds;
    for(rounds=0; rounds < TESTS; rounds++){

    int o_seed = rand() % 900000000;

    struct gameState* state= malloc(sizeof(struct gameState));
    int*k= malloc(sizeof(int)*10);
     gen_kindom_cards(k,test_card);


    int numPlayers = rand()% 4 +2;
    if(numPlayers > 4){
        numPlayers = 2;
    }
    
    int player= rand()%numPlayers;
    initializeGame(numPlayers, k, o_seed, state); 
    state->whoseTurn = player;
    reset_deck_discard_hand(state);
    randomize_supply(state,test_card);
    set_hand(state, test_card);

    int gain_card = pick_gain_card(state);
  
  int trash_card_idx=pick_trash_card(state);
  int trash_card=state->hand[state->whoseTurn][trash_card_idx];
  
  int trash_validity = is_treasure(trash_card);
  int gain_validity = is_treasure(gain_card);
  int cost_validity = cost_legal(trash_card, gain_card);
  
#if(MORE == 1)
  printf("\tTEST %d\n", rounds+1);
#endif
  int expected = 0;
  if(trash_validity == 0 && gain_validity == -1){
#if(MORE == 1)      
    printf("Trash card (choice 1) is VALID\n");
    printf("Gain card (choice 2) is INVALID\n");
#endif
  expected = -1;
  }else if(trash_validity == 0 && gain_validity == -1){
#if(MORE == 1)      
    printf("Trash card (choice 1) is INVALID\n");
    printf("Gain card (choice 2) is VALID\n");
#endif
    expected = -1;
  }else if(trash_validity == 0 && gain_validity == 0){
#if(MORE == 1)      
    printf("Trash card (choice 1) is VALID\n");
    printf("Gain card (choice 2) is VALID\n");
#endif       
    if(cost_validity ==0){
#if(MORE == 1)
            printf("Cost differenece is VALID\n");
#endif
            expected = 0;
        }else{
#if(MORE == 1)
            printf("Cost differenece is INVALID\n");
#endif         
            expected = -1;
        }

    }else if(trash_validity == -1 && gain_validity == -1){
#if(MORE == 1)
    printf("Trash card (choice 1) is INVALID\n");
    printf("Gain card (choice 2) is INVALID\n");
#endif
    expected = -1;
    }
    

   int actual= play_mine( trash_card,gain_card,player,state,0);
 #if(MORE == 1)  
   printf("Expected: %d Actual: %d\n", expected, actual);
 #endif  
   if(expected == actual){
 #if(MORE == 1)
       printf("\tPASSED\n\n");
 #endif
    passed++;
   }else{
#if(MORE == 0) 
   printf("\tTEST %d\n", rounds+1);
   printf("Expected: %d Actual: %d\n", expected, actual);
#endif    
    printf("\tFAILED\n");  
#if(MORE == 1)   
    fprintf(fp, "\tTEST %d FAILED\n", rounds+1);
    fprintf(fp,"Expected: %d Actual: %d\n", expected, actual);
    fprintf(fp, " Test Reproduction Conditions\n");
    fprintf(fp, " time seed: %d\n", seed);
    fprintf(fp, " init seed: %d\n", o_seed);
    fprintf(fp, " numPlayers: %d\n", numPlayers);  
    fprintf(fp, " Player who played mine card: %d\n", state->whoseTurn); 
    fprintf(fp, " Card from Hand to Trash: %d, Card cost: %d\n", trash_card, getCost(trash_card));
    fprintf(fp, " Card from Supply to Gain: %d, Card cost: %d\n\n", gain_card, getCost(gain_card));
#endif
    failed++;
   }

     free(k);
    free(state);
    }      

   printf("FINISHED Random tests for Mine card...\n\n");
   printf("Total Tests Run: %d\n", TESTS);
   printf("Total Tests Passed: %d\n", passed);
   printf("Total Tests Failed: %d\n", failed);
   fprintf(fp,"Total Tests Run: %d\n", TESTS);
   fprintf(fp,"Total Tests Passed: %d\n", passed);
   fprintf(fp,"Total Tests Failed: %d\n", failed);

   fclose(fp);
    return 0;
}

/**
*  MAIN
**/
int main () {

     int seed = time(NULL);
    srand(seed);
     
test_mine(seed);

  return 0;
}