/**
*                  author:   Kayla Fitzsimmons
*                 course:   Software Engineering II
*                     term:   Fall 2015
*                       file:    randomtestadventurer.c
*        file contents:    Random Test Suite
*                     card:   Adventurer
*  card description:   Reveal cards from your deck until you reveal 2 Treasure cards. 
*                                Put those cards in your hand and discard the other revealed cards.
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

#define MAX_DISCARD 500

/*
    PLAY ADVENTURER

 int play_adventurer(int currentPlayer,struct gameState *state, int handPos){
   int drawntreasure=0;
   int cardDrawn;
   int temphand[MAX_HAND];
   int z=0; //coutner for tempHand array
   while(drawntreasure<2){
	if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
	  shuffle(currentPlayer, state);
	}
	drawCard(currentPlayer, state);
	cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
	if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
	  drawntreasure++;
	else{
                temphand[z]=cardDrawn;
                state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
                z++;
        }
      }
      // second loop
     while(z-1>=0){
            state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
            z=z-1;
     }
      return 0;
}*/
// test adventurer card in each hand position
// test adventurer in each hand position
// test card behavior for all treasures
// If you have to shuffle in the middle, shuffle. Don't shuffle in the revealed cards as these cards do not go 
// to the Discard pile until you have finished revealing cards.
// If you run out of cards after shuffling and still only have one Treasure, you get just that one Treasure.


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
      int num_to_remove = rand()%init_val + 1;
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
void randomize_kingdom_cards(struct gameState* state){
    
    int card, pile_size;
    
    for(card=7; card < 27; card++){
        if(state->supplyCount[card] != -1){
            if (state->supplyCount[card] == great_hall || state->supplyCount[card]== gardens){
                if (state->numPlayers == 2){
                    pile_size = 8;
                }else{ 
                    pile_size = 12; 
                }
            }else{
                pile_size = 10;
            }
            randomize_pile(state, card, pile_size);
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
 void reset_deck_discard_hand(struct gameState* state){
    int player;
    
    for(player=0; player < state->numPlayers; player++){
        int deckCount = state->deckCount[player];
        memset(state->deck[player], -1, sizeof(int) * deckCount);
        state->deckCount[player]=0;
        assert(state->deckCount[player] == 0);
        
        int discardCount = state->discardCount[player];
        memset(state->discard[player], -1, sizeof(int) * discardCount);
        state->discardCount[player]=0;
         assert(state->discardCount[player]== 0);
         
        int handCount = state->handCount[player];
        memset(state->hand[player], -1, sizeof(int) * handCount);
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
 }
 /**
 *  
 *  param: state Parameter_Description
 *  return: Return_Description
 *  calling function: 
 *  details: Details
 **/ 
 int randomize_supply(struct gameState* state){

   randomize_basic_cards(state);
   randomize_kingdom_cards(state);
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
 void set_hand (struct gameState* state){
     int player;
     for(player=0; player < state->numPlayers; player++){
         state->hand[player][0]=7;
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
 void gen_kindom_cards(int* k){
    int options[19]={8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
    
     int i,j,m,card;
     m=1;
     k[0]=7;
     for(i=1; i < 9; i++){

       while(k[i]==0){
        card = rand()%17;
        if(options[card]!=0){
           k[i]=options[card];
           options[card]=0;
        }
       }
     } 
 }

 /**
 *  find_treasures
 *  return: Return_Description
 *  calling function: 
 *  details: This function should count the number of cards to be discarded
 *              from deck until it finds two treasures
 **/
 int find_treasures(struct gameState* state){
     int player = state->whoseTurn;
     int treasures = 0;
     int num_discard= 0;
     int deck_idx;
   for(deck_idx = 0; deck_idx < state->deckCount[player]; deck_idx++){
         

         if(state->deck[player][deck_idx] == 4 || state->deck[player][deck_idx] == 5 || state->deck[player][deck_idx] == 6 ){
             printf("found: %d\n", state->deck[player][deck_idx]);
             treasures++;

             if(treasures == 2){
                 break;    
             }
        }else{
             num_discard++;
         printf("discarding: %d\n", state->deck[player][deck_idx]);
       }          
                
     }
     if(num_discard==0 && (deck_idx == (state->deckCount[player]))){
         return -1;
     }
     return num_discard;   
 }
// test cards drawn until 2 treasures are found
int main () {

    int rounds;
        printf ("Starting Random Tests for Adventurer Card...\n\n");
            int seed = time(NULL);
    srand(seed);
    for(rounds=0; rounds < 50; rounds++){
    struct gameState state;
    int k[10];
    gen_kindom_cards(k);

    initializeGame(2, k, 6, &state);
    reset_deck_discard_hand(&state);
//    printSupply(&state);
    randomize_supply(&state);
//    printSupply(&state);

 //  print_deck_discard(&state);
    set_hand(&state);
    
    
    int discardCount = state.discardCount[state.whoseTurn];
    
    int discarded = find_treasures(&state);
    if(discarded == -1){
        printf("the pack will be shuffled\n");
    }
    play_adventurer(state.whoseTurn,&state,0);
    
    int postDiscardCount = state.discardCount[state.whoseTurn];
    
 //    printf("discardCount + discarded: %d+%d vs post discard count: %d\n",discardCount,discarded, postDiscardCount);
    printf("\n");
     //  print_deck_discard(&state);
    }     
    //assert()
  //  memset(&state, 23, sizeof(struct gameState));   // clear the game state (from template.c)
   // initializeGame(2, k,1000 , &state); // initialize a new game (from template.c)

    printf ("FINISHED Random tests for Adventurer card...\n\n");
}