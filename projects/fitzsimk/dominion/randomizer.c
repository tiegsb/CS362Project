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
#include"randomizer.h"





 /**
*  
*  param: a Parameter_Description
*  param: b Parameter_Description
*  return: Return_Description
*  calling function: 
*  details: Details
**/
int comp(const void* a, const void* b) {
  if (*(int*)a > *(int*)b)
    return 1;
  if (*(int*)a < *(int*)b)
    return -1;
  return 0;
} 
  /**
  *  
  *  param: state    Parameter_Description
  *  param: card_idx Parameter_Description
  *  param: init_val Parameter_Description
  *  return: Return_Description
  *  calling function: 
  *  details: Details
  **/
  void randomize_pile(struct gameState* state,int card_idx, int init_val){
      
      state->supplyCount[card_idx]= init_val;
      int num_to_remove = rand()%init_val;
    //  printf("num to remove: %d\n", num_to_remove);
      int cards_removed;
      for(cards_removed=0; cards_removed < num_to_remove; cards_removed++){
          state->supplyCount[card_idx]--;
          int player = rand()% state->numPlayers;
        //  printf("player: %d\n", player);
          int pile = rand() % 2;
         //  printf("pile: %d\n", pile);         
         
         if(pile == 0){
             int deckCount = state->deckCount[player];
             state->deck[player][deckCount] = card_idx;
             state->deckCount[player]++;
         }else{
            int discardCount = state->discardCount[player];
             state->discard[player][discardCount] = card_idx;
             state->discardCount[player]++;
         }
      }
  }
  /**
  *  
  *  param: state Parameter_Description
  *  return: Return_Description
  *  calling function: 
  *  details: Details
  **/
  void randomize_basic_cards(struct gameState* state){
      
      // #      name     copies
      // 0      curse       30
      randomize_pile(state, 0, 30);
      // 1      Estate      24
      randomize_pile(state, 1, 24);
      // 2      Duchy      12
      randomize_pile(state, 2, 12);
      // 3      Province   12
     randomize_pile(state, 3, 12);
      // 4      Copper   
      randomize_pile(state, 4, 60);      
      // 5      Silver
     randomize_pile(state, 5, 40);
     // 6      Gold     30
     randomize_pile(state, 6, 30);
  }
  /**
*  
*  param: state Parameter_Description
*  return: Return_Description
*  calling function: 
*  details: Details
**/
void randomize_kingdom_cards(struct gameState* state, int test_card){
    
    int card, pile_size;
    
    for(card=7; card < 27; card++){
         pile_size = 10;
        if(state->supplyCount[card] != -1){
            if (card == great_hall || card == gardens){
                if (state->numPlayers == 2){
                    pile_size = 8;
                }else{ 
                    pile_size = 12; 
                }
            }
           if(card == test_card){ 
                    state->supplyCount[card] = pile_size;
            }else{
                     randomize_pile(state, card, pile_size);
            }
        }
    }
} 
 /**
 *  reset_deck_discard_hand
 *  param: state Parameter_Description
 *  return: Return_Description
 *  calling function: 
 *  details: Details
 **/
 void reset_deck_discard_hand(struct gameState* state){
    int player;
    
    for(player=0; player < state->numPlayers; player++){
        int deckCount = state->deckCount[player];
        memset(state->deck[player], -1, sizeof(int) * deckCount);
        state->deckCount[player]=0;
        assert(state->deckCount[player] == 0);
        
        int n;
        for(n=0; n< MAX_DISCARD; n++){
            state->discard[player][n]=-1;

        }
        state->discardCount[player]=0;
         assert(state->discardCount[player]== 0);
         
        int m;
        for(m=0; m < MAX_HAND; m++){
            state->hand[player][m]=-1;

        }
                    state->handCount[player]=0;

            assert(state->handCount[player]== 0);  

    }
 }
 /**
*  shuffle_disc
*  param: player Parameter_Description
*  param: state  Parameter_Description
*  return: Return_Description
*  calling function: 
*  details: Details
**/
int shuffle_disc(int player, struct gameState *state) {
 
  int newDiscard[MAX_DISCARD];
  int newDiscardPos = 0;
  int card;
  int i;

  if (state->discardCount[player] < 1)
    return -1;
  qsort ((void*)(state->discard[player]), state->discardCount[player], sizeof(int), comp); 
  /* SORT CARDS IN DISCARD TO ENSURE DETERMINISM! */

  while (state->discardCount[player] > 0) {
    card = floor(Random() * state->discardCount[player]);
    newDiscard[newDiscardPos] = state->discard[player][card];
    newDiscardPos++;
    for (i = card; i < state->discardCount[player]-1; i++) {
      state->discard[player][i] = state->discard[player][i+1];
    }
    state->discardCount[player]--;
  }
  for (i = 0; i < newDiscardPos; i++) {
    state->discard[player][i] = newDiscard[i];
    state->discardCount[player]++;
  }

  return 0;
}
/**
*  
*  param: state Parameter_Description
*  return: Return_Description
*  calling function: 
*  details: Details
**/
int shuffle_discard(struct gameState* state){
int i;
for (i = 0; i < state->numPlayers; i++){
    if ( shuffle_disc(i, state) < 0 ){
        return -1;
    }
}
return 0;
}
 /**
 *  
 *  param: state Parameter_Description
 *  return: Return_Description
 *  calling function: 
 *  details: Details
 **/
 int shuffle_deck(struct gameState* state){
   int i;
   for (i = 0; i < state->numPlayers; i++){
        if ( shuffle(i, state) < 0 ){
            return -1;
        }
   }
   return 0;
 }
 /**
 *  
 *  param: state Parameter_Description
 *  return: Return_Description
 *  calling function: 
 *  details: Details
 **/ 
 int randomize_supply(struct gameState* state, int test_card){

    randomize_basic_cards(state);
    randomize_kingdom_cards(state, test_card);
    shuffle_deck(state);
    shuffle_discard(state);
return 0;
 }
 /**
 *  
 *  param: state Parameter_Description
 *  return: Return_Description
 *  calling function: 
 *  details: Details
 **/
 void set_hand (struct gameState* state, int test_card){
     int player;
     for(player=0; player < state->numPlayers; player++){
         state->hand[player][0]=test_card;
         state->supplyCount[test_card]--;
         state->handCount[player]++;
        int i;
        for(i=0; i<5; i++){
            drawCard(player, state);
        }
  }
     
 }
 /**
 *  printDeck
 *  param: 
 *  return: Return_Description
 *  calling function: 
 *  details: Details
 **/
 void print_deck_discard(struct gameState* state){
     int player;
     for(player=0; player < state->numPlayers; player++){
         printDeck(player,state);
        printDiscard(player,state);
  }
 }
 /**
 *  gen_kindom_cards
 *  param: k - array of kingdom cards
 *  details: assigns random selection of kingdom cards to array
 **/
void gen_kindom_cards(int *k,int test_card){
    int options[20]={7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
   
    
     int i,m,card;
     m=1;
     k[0]=test_card;
     for(i=1; i < 9; i++){
       do{
        card = rand()%20;
        if( (options[card]!=0) && (options[card] != test_card)){
           k[i]=options[card];
           options[card]=0;

        }

       }while(k[i]==0);
    //  printf("k[i]: %d\n", k[i]);
 }
}


 /**
 *  free_kc
 *  param: k Parameter_Description
 *  return: Return_Description
 *  calling function: 
 *  details: Details
 **/
 void free_kc(int*k){   
 free(k);
/*     int j;
    for(j=0; j < 10; j++){
        free(k[j]);
    } */
 }