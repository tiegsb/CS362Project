/*****************
 * Author:  Brian Stamm
 * Title:  cardTest3.c
 * Assignment:  3
 * Date:  10.25.15
 * Notes:  Tests the Village card, in villageMethod().
 * ****************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void test(){
  struct gameState g;
  struct gameState *game = &g;
  int player = 1;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
    sea_hag, tribute, smithy};
  srand(time(NULL));
  int r = rand();
  int i, counter, card, total, failNum;
  int testHandCount, testDeckCount, testPlayedCount, testActions;
  int testTrialCard;

  initializeGame(2, k, r, game);

  //First check.  Set up same valuse
  testTrialCard = game->hand[player][0];
  testHandCount = game->handCount[player];
  testPlayedCount = game->playedCardCount + 1;
  testDeckCount = game->deckCount[player]-1;
  testActions = game->numActions + 2;

  if(villageMethod(game, player, 0) == 0){
    if(testPlayedCount == game->playedCardCount){
      printf("villageMethod() Test 1:  PASS, played card amounts equal.\n");
      printf("\tTest:  %d\tSaved:  %d\n", testPlayedCount, game->playedCardCount);
    }
    else{
      printf("villageMethod() Test 1:  FAIL, discard amounts NOT equal.\n");
      printf("\tTest:  %d\tSaved:  %d\n", testPlayedCount, game->playedCardCount);
    }

    if((testHandCount) == game->handCount[player]){
      printf("villageMethod() Test 1:  PASS, handCount amounts equal.\n");
      printf("\tTest:  %d\tSaved:  %d\n", testHandCount, game->handCount[player]);
    }
    else{
      printf("villageMethod() Test 1:  FAIL, handCount amounts NOT equal.\n");
      printf("\tTest:  %d\tSaved:  %d\n", testHandCount, game->handCount[player]);
    }

    if(testDeckCount == game->deckCount[player]){
      printf("villageMethod() Test 1:  PASS, deckCount amounts equal.\n");
      printf("\tTest:  %d\tSaved:  %d\n", testDeckCount, game->deckCount[player]);
    }
    else{
      printf("villageMethod() Test 1:  FAIL, deckCount amounts NOT equal.\n");
      printf("\tTest:  %d\tSaved:  %d\n", testDeckCount, game->deckCount[player]);
    }
    if(game->numActions == testActions){
      printf("villageMethod() Test :  PASSED - action number correct\n");
      printf("\tTest:  %d\tSaved:  %d\n", testActions, game->numActions);
    }
    else{
      printf("villageMethod() Test :  FAILED - action number NOT correct\n");
      printf("\tTest:  %d\tSaved:  %d\n", testActions, game->numActions);
    }
  }
  else{
    printf("villageMethod() Test 1:  FAIL.  Unknown error, danger, danger Will Robinson.\n");
  }

//Then do random decks, similar to shuffle test.
  printf("\nRandom Testing to Start\n");
  counter = 1;
  failNum = 0;
  while(counter < 501){
    for(i=0; i < 10; i++){
      r = rand();
      card = r % treasure_map;
      game->deck[player][i] = card;
    }
    game->deckCount[player] = 10;
    r = rand();
    total = r % MAX_HAND;
    if(total == 0){
      total++;
    }
    for(i=0; i<total; i++){
      r = rand();
      card = r % treasure_map;
      game->hand[player][i] = card;
    }
    game->handCount[player] = total;

    testTrialCard = game->hand[player][0];
    testHandCount = game->handCount[player];
    game->playedCardCount = 0;
    testPlayedCount = 1;
    testDeckCount = game->deckCount[player] -1;
    testTrialCard = game->hand[player][0];
    testActions = game->numActions + 2;

    if(villageMethod(game, player, 0) == 0){
      if(testPlayedCount != game->playedCardCount){
        printf("villageMethod() Random Test %d:  FAIL, played amounts NOT equal.\n", counter);
        printf("\tTest:  %d\tSaved:  %d\n", testPlayedCount, game->playedCardCount);
        failNum++;
      }

      if(testHandCount != game->handCount[player]){
        printf("villageMethod() Test %d:  FAIL, handCount amounts NOT equal.\n", counter);
        printf("\tTest:  %d\tSaved:  %d\n", testHandCount, game->handCount[player]);
        failNum++;
      }

      if(testDeckCount != game->deckCount[player]){
        printf("villageMethod() Test %d:  FAIL, deckCount amounts NOT equal.\n", counter);
        printf("\tTest:  %d\tSaved:  %d\n", testDeckCount, game->deckCount[player]);
        failNum++;
      }
      if(testActions != game->numActions){
        printf("villageMethod() Test :  FAILED - action number NOT correct\n");
        printf("\tTest:  %d\tSaved:  %d\n", testActions, game->numActions);
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
