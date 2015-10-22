/*****************
 * Author:  Brian Stamm
 * Title:  cardTest3.c
 * Assignment:  3
 * Date:  10.?.15
 * Notes:  Tests the Village card, in villageMethod().
 * ****************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "dominion.c"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void test(){
	struct gameState *game;
  int player = 1;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
    sea_hag, tribute, smithy};
  srand(time(NULL));
  int r = rand();
  int i, counter, card, total, failNum;
  int testCards[3];
  int testHand[500];
  int testHandCount, testDeckCount, testDiscardCount, testActions;
  int testDiscard[500];
  int testTrialCard;

  initilizeGame(2, k, r, game);

  //First check.  Set up same valuse
  for(i = 0; i < game->discardCount[player]; i++){
    testDiscard[i] = game->discard[player][i];
  }
  for(i = 0; i < game->handCount[player]; i++){
    testHand[i] = game->hand[player][i];
  }
  for(i = 0; i < 3; i++){
    testCards[i] = game->deck[player][i];
  }
  testTrialCard = game->hand[player][0];
  testHandCount = game->handCount[player];
  testDiscardCount = game->discardCount[player];
  testDeckCount = game->deckCount[player];
  testActions = game->numActions;
  testActions += 2;

  if(villageMethod(game, player, 0) == 0){
    if((testDiscardCount+1) == game->discardCount[player]){
      printf("villageMethod() Test 1:  PASS, discard amounts equal.\n");
    }
    else{
      printf("villageMethod() Test 1:  FAIL, discard amounts NOT equal.\n");
    }

    if((testHandCount+2) == game->handCount[player]){
      printf("villageMethod() Test 1:  PASS, handCount amounts equal.\n");
    }
    else{
      printf("villageMethod() Test 1:  FAIL, handCount amounts NOT equal.\n");
    }

    if(testDeckCount == game->deckCount[player]){
      printf("villageMethod() Test 1:  PASS, deckCount amounts equal.\n");
    }
    else{
      printf("villageMethod() Test 1:  FAIL, deckCount amounts NOT equal.\n");
    }
    if(game->numActions == testActions){
      printf("villageMethod() Test :  PASSED - action number correct\n");
    }
    else{
      printf("villageMethod() Test :  FAILED - action number NOT correct\n");
    }
  }
  else{
    printf("villageMethod() Test 1:  FAIL.  Unknown error, danger, danger Will Robinson.\n");
  }

//Then do random decks, similar to shuffle test.
  printf("Random Testing to Start\n");
  counter = 1;
  failNum = 0;
  while(counter < 501){
    for(i=0; i < 10; i++){
      card = r % treasure_map;
      game->deck[player][i] = card;
    }
    game->deckCount[player] = 10;
    total = r % MAX_HAND;
    if(total == 0){
      total++;
    }
    for(i=0; i<total; i++){
      card = r % treasure_map;
      game->hand[player][i] = card;
    }
    game->handCount[player] = total;

    testTrialCard = game->hand[player][0];
    testHandCount = game->handCount[player];
    testDiscardCount = game->discardCount[player];
    testDeckCount = game->deckCount[player];

    if(villageMethod(game, player, 0) == 0){
      if((testDiscardCount+1) != game->discardCount[player]){
        printf("villageMethod() Random Test %d:  FAIL, discard amounts NOT equal.\n", counter);
        failNum++;
      }

      if((testHandCount+2) != game->handCount[player]){
        printf("villageMethod() Test %d:  FAIL, handCount amounts NOT equal.\n", counter);
        failNum++;
      }

      if(testDeckCount != game->deckCount[player]){
        printf("villageMethod() Test %d:  FAIL, deckCount amounts NOT equal.\n", counter);
        failNum++;
      }
    }
    else{
      printf("villageMethod() Random Test %d:  FAIL.  Unknown error, danger, danger Will Robinson.\n", counter);
      failNum++;
    }
    counter++;      
  }
  printf("villageMethod() Random Test fail number:  %d\n", failNum);
}


int main(int argc, char **argv){

	printf("This is the tests for the Village card, the villageMethod().\n");
	
	test();

	return 0;
}

/***************
method being tested:

int villageMethod(struct gameState *state, int currentPlayer, int handPos){
  //+1 Card
  drawCard(currentPlayer, state);
        
  //+2 Actions
  state->numActions = state->numActions + 2;
        
  //discard played card from hand
  discardCard(handPos, currentPlayer, state, 0);
  return 0;
}
***************/
