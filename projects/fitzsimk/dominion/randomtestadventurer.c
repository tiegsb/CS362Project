/**
*                  author:   Kayla Fitzsimmons
*                 course:   Software Engineering II
*                     term:   Fall 2015
*                       file:    randomtestadventurer.c
*        file contents:    Random Test Suite
*                     card:   Adventurer
*  card description:   Reveal cards from your deck until you reveal 2 Treasure cards. 
*                                   Put those cards in your hand and discard the other revealed cards.
*   
**/
#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>  
#include <time.h>       
#include <math.h>
#include "rngs.h"
#include "randomizer.h"
#include "randomtestadventurer.h"

#define TESTS 300000
#define MAX_DISCARD 500
#define MORE 0

 /**
 *  find_treasures
 *  return: number of cards from deck to be discarded
 *  details: This function should count the number of cards to be discarded
 *                   from deck until it finds two treasures
 **/
 int find_treasures(struct gameState* state){
     int player = state->whoseTurn;
     int treasures = 0;
     int num_discard= 0;
     int deck_idx;
 #if(MORE == 1)
     printf("Counting Discarded and Finding Treasures...\n");
#endif
   for(deck_idx = 0; deck_idx < state->deckCount[player]; deck_idx++){
         

         if(state->deck[player][deck_idx] == 4 || state->deck[player][deck_idx] == 5 || state->deck[player][deck_idx] == 6 ){
#if(MORE == 1)
             printf("found: %d\n", state->deck[player][deck_idx]);
#endif
             treasures++;

             if(treasures == 2){
                 break;    
             }
        }else{
             num_discard++;
 #if(MORE == 1)
         printf("discarding: %d\n", state->deck[player][deck_idx]);
#endif
       }          
                
     }
     if(num_discard==0 && (deck_idx == (state->deckCount[player]))){
         return -1;
     }
     return num_discard;   
 }
 /**
 *  test_adventurer
 *  param: seed random to initalize game state
 *  return: 0 on success
 *  details: contains random test 'oracle' and outputs results to stdout / file
 **/
 int test_adventurer(int seed){
     int passed =0; 
     int failed=0;
     int rounds;
     printf ("Starting Random Tests for Adventurer Card...\n\n");  
     FILE * fp = fopen("randomtestadventurer.out","w");
      int test_card = 7;
    for(rounds=0; rounds < TESTS; rounds++){
    printf("\tTEST %d\n", rounds+1);
    int o_seed = rand() % 900000000;
    struct gameState* state= malloc(sizeof(struct gameState));
    int*k= malloc(sizeof(int)*10);
    gen_kindom_cards(k,test_card);
    
    int numPlayers = rand()% 4 +2;
    if(numPlayers > 4){
        numPlayers = 2;
    }
    int player= rand()%numPlayers; 
    if(player < 0 || player > numPlayers-1){
        player = 0;
    }
   initializeGame(numPlayers, k, o_seed, state); 
   
   state->whoseTurn = player;
   
   reset_deck_discard_hand(state);
   randomize_supply(state,test_card);
   set_hand(state, test_card);
   int discardCount = state->discardCount[state->whoseTurn];
    

    int discarded = find_treasures(state);
    if(discarded == -1){
        printf("No treasure cards in deck, the pack will be shuffled, check for treasures cannot be perfomed\n");
        continue;
    }
    int postDiscardCount = state->discardCount[state->whoseTurn];
    play_adventurer(state->whoseTurn,state,0);
    
    if(discardCount + discarded == postDiscardCount){   
        printf("Expected: %d Actual: %d\n\tPASSED\n\n", discardCount+discarded, postDiscardCount);
        passed++;
    }else{
        printf("Expected: %d Actual: %d\n\tFAILED\n", discardCount+discarded, postDiscardCount);
        failed++;
#if(MORE == 1)    
        printf(" Test Reproduction Conditions\n");
        printf(" time seed: %d\n", seed);
        printf(" init seed: %d\n", o_seed);
        printf(" numPlayers: %d\n", numPlayers);  
        printf(" Player who played adventurer card: %d\n\n", state->whoseTurn); 
#endif     
    }
    printf("\n"); 

     free(k);
    free(state);
    }      
   
    printf("FINISHED Random tests for Adventurer card...\n\n");
    printf("Total Tests Run: %d\n", TESTS);
    printf("Total Tests Passed: %d\n", passed);
    printf("Total Tests Failed: %d\n", failed);
    fprintf(fp,"Total Tests Run: %d\n", TESTS);
    fprintf(fp,"Total Tests Passed: %d\n", passed);
    fprintf(fp,"Total Tests Failed: %d\n\n", failed);
    fclose(fp);
  return 0;   
 }
/**
*  MAIN 
**/
int main () {


     int seed = time(NULL);
    srand(seed);
     test_adventurer(seed);
   
  return 0;
}