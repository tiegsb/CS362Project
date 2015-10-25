/*****************
 * Author:  Brian Stamm
 * Title:  unitTest3.c
 * Assignment:  3
 * Date:  10.25.15
 * Notes:  Test for gainCard().
 * ****************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

 void test() {
  struct gameState g;
	struct gameState *game = &g;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
	int supplyPos, toFlag, player, testA, testB;

  srand(time(NULL));
  int r = rand();

  //Setting up a game, so all values are filled.
  initializeGame(2, k, r, game);
  supplyPos = 1;
  game->supplyCount[supplyPos] = 0;

  //Check the first if
  if(gainCard(supplyPos, game, toFlag, player) == -1){
    printf("gainCard():  PASSED test one, first if.\n");
  }
  else{
    printf("gainCard():  FAILED test one, first if.\n");
  }

  //Resetting values, initializing testing, checking discard.
  game->supplyCount[supplyPos] = 8;
  player = 1;
  toFlag = 0;
  testA = game->discardCount[player];
  testB = game->supplyCount[supplyPos];
  if(gainCard(supplyPos, game, toFlag, player) == -1){
    printf("gainCard():  Error test two, first if.\n");
  }
  else{
    if(game->discardCount[player] > testA){
      if(game->supplyCount[supplyPos] < testB){
        printf("gainCard():  PASSED test two, discard.\n");
      }
      else{
        printf("gainCard():  FAILED test two, discard supplyCount.\n");
      }
    }
    else{
      printf("gainCard():  FAILED test two, discard discardCount.\n");
    }
  }

  //Resetting values, checking adding to deck.
  toFlag = 1;
  game->discardCount[player] = testA;
  game->supplyCount[supplyPos] = testB;
  testA = game->deckCount[player];
  if(gainCard(supplyPos, game, toFlag, player) == -1){
    printf("gainCard():  Error test three, first if.\n");
  }
  else{
    if(game->deckCount[player] > testA){
      if(game->supplyCount[supplyPos] < testB){
        printf("gainCard():  PASSED test three, add card.\n");
      }
      else{
        printf("gainCard():  FAILED test three, add supplyCount.\n");
      }
    }
    else{
      printf("gainCard():  FAILED test three, add deckCount.\n");
    }
  }

  //Resetting values, checking adding to deck.
  toFlag = 2;
  game->deckCount[player] = testA;
  game->supplyCount[supplyPos] = testB;
  testA = game->handCount[player];
  if(gainCard(supplyPos, game, toFlag, player) == -1){
    printf("gainCard():  Error test four, first if.\n");
  }
  else{
    if(game->handCount[player] > testA){
      if(game->supplyCount[supplyPos] < testB){
        printf("gainCard():  PASSED test four, add card.\n");
      }
      else{
        printf("gainCard():  FAILED test four, add supplyCount.\n");
      }
    }
    else{
      printf("gainCard():  FAILED test four, add deckCount.\n");
    }
  }

}


int main(int argc, char **argv){

	printf("This is the tests for the gainCard() function.\n");
	
	test();

	return 0;
}

/*
int gainCard(int supplyPos, struct gameState *state, int toFlag, int player)
{
  //Note: supplyPos is enum of choosen card
	
  //check if supply pile is empty (0) or card is not used in game (-1)
  if ( supplyCount(supplyPos, state) < 1 )
    {
      return -1;
    }
	
  //added card for [whoseTurn] current player:
  // toFlag = 0 : add to discard
  // toFlag = 1 : add to deck
  // toFlag = 2 : add to hand

  if (toFlag == 1)
    {
      state->deck[ player ][ state->deckCount[player] ] = supplyPos;
      state->deckCount[player]++;
    }
  else if (toFlag == 2)
    {
      state->hand[ player ][ state->handCount[player] ] = supplyPos;
      state->handCount[player]++;
    }
  else
    {
      state->discard[player][ state->discardCount[player] ] = supplyPos;
      state->discardCount[player]++;
    }
	
  //decrease number in supply pile
  state->supplyCount[supplyPos]--;
	 
  return 0;
}

int supplyCount(int card, struct gameState *state) {
  return state->supplyCount[card];
}
*/
