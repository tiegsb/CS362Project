/*****************
 * Author:  Brian Stamm
 * Title:  randomtestadventurer.c
 * Assignment:  4
 * Date:  11.8.15
 * Notes:  Random tests for the Adventurer card, adventurerMethod().
 * ****************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

//Function setHand - set up to quickly set the deck for various situations
//Runs through, and depending, fills deck with cards user passes in
int setHand(struct gameState *g, int card, int r, int choice){
  int i, newCard;
  //Fills deck completely
  if(choice == 1){
    for(i=0;i<MAX_HAND; i++){
      g->deck[1][i] = card;
    }
    g->deckCount[1] = MAX_HAND;
    return 0;
  }
  //Fills deck with (card -1), except the last 3 cards, which is filled
  //with card
  else if(choice == 2){
    for(i=0;i<(MAX_HAND-3);i++){
      g->deck[1][i] = (card -1);
    }
    for(;i<MAX_HAND;i++){
      g->deck[1][i] = card;
    }
    g->deckCount[1]= MAX_HAND;
    return 0;
  }
  //Fills deck with random cards - ADDED/CHANGED randomizing the deck
  else if(choice == 3){
    for(i=0;i<MAX_HAND;i++){
      r = rand();
      newCard = r % 27;
      g->hand[1][i] = newCard;
    }
    for(i=0; i<MAX_DECK;i++){
      r = rand();
      newCard = r % 27;
      g->deck[1][i] = newCard;
    }
    g->handCount[1] = MAX_HAND;
    g->deckCount[1] = MAX_DECK;
    return 0;
  }
  //Fills hand and deck with random amounts - ADDED FUNCTION
  else if(choice == 4){
    int handTotal = rand() % MAX_HAND;
    if(handTotal == 0){
      handTotal++;
    }
    for(i=0;i<handTotal;i++){
      r = rand();
      newCard = r % 27;
      g->hand[1][i] = newCard;
    }
    for(i=0; i<MAX_DECK;i++){
      r = rand();
      newCard = r % 27;
      g->deck[1][i] = newCard;
    }
    g->handCount[1] = handTotal;
    g->deckCount[1] = MAX_DECK;
    return 0;
  }
  //ONLY HAND FILLING SITUATION
  //fills hand with 5 cards
  else{
    for(i=0;i<5;i++){
      g->hand[1][i] = card;
    }
    g->handCount[1] = 5;
    return 0;    
  }
  return 1;
}

//ADDED FUNCTION - counts up the total coins in persons hand
int goldCounter(struct gameState *g){
  int h = 0;
  int i;
  for(i = 0; i<g->handCount[1]; i++){
    if(g->hand[1][i] == copper || g->hand[1][i] == silver || g->hand[1][i] == gold){
      h++;
    }
  }
  return h;
}

//Actual test
void test(){
  struct gameState g;
  struct gameState *game = &g;
	int player = 1;
  int counter = 0;
  int tempHand[MAX_HAND];
  srand(time(NULL));
  int r = rand();

  //Initial check
  if(setHand(game, copper, r, 1)){
    printf("%d:  Error setting DECK.\n", counter);
  }
  if(setHand(game, estate, r, 0)){
    printf("%d:  Error setting HAND.\n", counter);
  }
  
  int totalError = 0;
  int unknownError = 0; 

  //While loop, goes through, randomly fills hand & deck w random cards and random amount
  //Counts the total coinage before and after
  while (counter < 100000){

    game->discardCount[player] = 0;
    r = rand();
    setHand(game, gold, r, 4);
    int moneyTotal = goldCounter(game);
    if(adventurerMethod(game, tempHand, player) != 0){
      unknownError++;
    }
    int checkTotal = goldCounter(game);
    if(checkTotal != (moneyTotal + 2)){
      totalError++;
    }

    counter++;
  }

  printf("------------Final-------------\n");
  printf("Total tests:  %d\n", counter);
  printf("Total errors in random:  %d\n", totalError);
  printf("Unknow errors in random:  %d\n", unknownError);

}

int main(int argc, char **argv){

	printf("This is the tests for the Adventurer card, adventurerMethod().\n");
	
	test();

	return 0;
}

/**********************
Method being tested.

int adventurerMethod(struct gameState *state, int *temphand, int currentPlayer){
  int cardDrawn;
  int z = 0;// this is the counter for the temp hand
  int drawntreasure = 0;
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
  while(z>=0){
    state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
    z=z-1;
  }
  return 0;
}
*************************/
