/*****************
 * Author:  Brian Stamm
 * Title:  cardTest2.c
 * Assignment:  3
 * Date:  10.?.15
 * Notes:  Unit tests for the Adventurer card, adventurerMethod().
 * ****************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "dominion.c"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int setHand(struct gameState *g, int card, int r, int choice){
  int i, newCard;
  if(choice == 1){
    for(i=0;i<MAX_HAND; i++){
      g->deck[1][i] = card;
    }
    g->deckCount[1] = MAX_HAND;
    return 0;
  }
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
  else if(choice == 3){
    for(i=0;i<MAX_HAND;i++){
      newCard = r % 27;
      g->hand[1][i] = newCard;
    }
    g->deck[1] = MAX_HAND;
    return 0;
  }
  else{
    for(i=0;i<5;i++){
      g->hand[1][i] = card;
    }
    g->handCount[1] = 5;
    return 0;    
  }
  return 1;
}

void test{
	struct gameState game;
	int player = 1;
  int counter = 1;
  int treasureCounter, i;
  int tempHand[MAX_HAND];
  srand(time(NULL));
  int r = rand();

  //Initial check
  if(setHand(&game, copper, r, 1)){
    printf("%d:  Error setting DECK.\n", counter);
    if(setHand(&game, estate, r, 0)){
      printf("%d:  Error setting HAND.\n", counter);
    }
  }
  if(adventurerMethod(&game, temphand, player) != 0){
    printf("%d:  Error unknown.\n", counter);
    counter++;
  }
  else{
    treasureCounter = 0;
    for(i=0;i<game->handCount;i++){
      if(game->hand[player][i] == copper){
        treasureCounter++;
      }
    }
    if(treasureCounter != 2){
      printf("%d:  adventureMethod():  FAIL, error initial, tcount - %d.\n", counter, treasureCounter);
    }
    else{
      printf("%d:  adventurerMethod():  PASSED initial.\n", counter);
    }
    counter++;
  }

  //Second check, large deck, only last cards are copper
  if(setHand(&game, copper, r, 2)){
    printf("%d:  Error setting DECK.\n", counter);
    if(setHand(&game, estate, r, 0)){
      printf("%d:  Error setting HAND.\n", counter);
    }
  }
  if(adventurerMethod(&game, temphand, player) != 0){
    printf("%d:  Error unknown.\n", counter);
    counter++;
  }
  else{
    treasureCounter = 0;
    for(i=0;i<game->handCount;i++){
      if(game->hand[player][i] == copper){
        treasureCounter++;
      }
    }
    if(treasureCounter != 2){
      printf("%d:  adventureMethod():  FAIL, large deck, last are copper, tcount - %d.\n", counter, treasureCounter);
    }
    else{
      printf("%d:  adventurerMethod():  PASSED large deck.\n", counter);
    }
    counter++;
  }

  //Third check, random deck, only last cards are copper
  if(setHand(&game, copper, r, 3)){
    printf("%d:  Error setting DECK.\n", counter);
    if(setHand(&game, estate, r, 0)){
      printf("%d:  Error setting HAND.\n", counter);
    }
  }
  if(adventurerMethod(&game, temphand, player) != 0){
    printf("%d:  Error unknown.\n", counter);
    counter++;
  }
  else{
    treasureCounter = 0;
    for(i=0;i<game->handCount;i++){
      if(game->hand[player][i] == copper){
        treasureCounter++;
      }
    }
    if(treasureCounter != 2){
      printf("%d:  adventureMethod():  FAIL, random deck.  tcount - %d.\n", counter, treasureCounter);
    }
    else{
      printf("%d:  adventurerMethod():  PASSED random.\n", counter);
    }
    counter++;
  }

  //Fourth check, no treasure in deck, only last cards are copper
  if(setHand(&game, curse, r, 1)){
    printf("%d:  Error setting DECK.\n", counter);
    if(setHand(&game, estate, r, 0)){
      printf("%d:  Error setting HAND.\n", counter);
    }
  }
  if(adventurerMethod(&game, temphand, player) != 0){
    printf("%d:  Error unknown.  NO TREASURE.\n", counter);
    counter++;
  }
  else{
    treasureCounter = 0;
    for(i=0;i<game->handCount;i++){
      if(game->hand[player][i] == copper){
        treasureCounter++;
      }
    }
    if(treasureCounter > 0){
      printf("%d:  adventureMethod():  FAIL, no treasure deck.  tcount - %d.\n", counter, treasureCounter);
    }
    else{
      printf("%d:  adventurerMethod():  PASSED no treasure?.\n", counter);
    }
    counter++;
  }

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
