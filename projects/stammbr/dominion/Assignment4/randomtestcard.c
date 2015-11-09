/*****************
 * Author:  Brian Stamm
 * Title:  randomtestcard.c
 * Assignment:  4
 * Date:  11.8.15
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
  int i, counter, card, total, errorNum, failNum, errorTotal;
  int testHandCount, testDeckCount, testPlayedCount, testActions;
  int testTrialCard;

  //Change this - initialize yourself to make it better
  initializeGame(2, k, r, game);

  //First check.  Set up same values
  testTrialCard = game->hand[player][0];
  testHandCount = game->handCount[player];
  testPlayedCount = game->playedCardCount + 1;
  testDeckCount = game->deckCount[player]-1;
  testActions = game->numActions + 2;

  //Initialize testing
  errorNum = 0;
  if(villageMethod(game, player, 0) == 0){
    if(testPlayedCount != game->playedCardCount){
      printf("villageMethod() Initialize Tests:  FAIL, discard amounts NOT equal.\n");
      printf("\tTest:  %d\tSaved:  %d\n", testPlayedCount, game->playedCardCount);
      errorNum++;
    }

    if((testHandCount) != game->handCount[player]){
      printf("villageMethod() Initialize Tests:  FAIL, handCount amounts NOT equal.\n");
      printf("\tTest:  %d\tSaved:  %d\n", testHandCount, game->handCount[player]);
      errorNum++;
    }

    if(testDeckCount != game->deckCount[player]){
      printf("villageMethod() Initialize Tests:  FAIL, deckCount amounts NOT equal.\n");
      printf("\tTest:  %d\tSaved:  %d\n", testDeckCount, game->deckCount[player]);
      errorNum++;
    }
    if(game->numActions != testActions){
      printf("villageMethod() Initialize Tests :  FAILED - action number NOT correct\n");
      printf("\tTest:  %d\tSaved:  %d\n", testActions, game->numActions);
      errorNum++;
    }
  }
  else{
    printf("villageMethod() Initialize Tests:  FAIL.  Unknown error, danger, danger Will Robinson.\n");
  }

  if(errorNum == 0){
  	printf("villageMethod() Initialize Tests:  PASSED ALL.\n");
  }

//Then do random decks, similar to shuffle test.
  printf("\nRandom Testing to Start\n");
  counter = 0;
  errorNum = 0;
  errorTotal = 0;

  while(counter < 100000){
    //Fills player's deck with random cards, random amount
    //gets random number

    r = rand();
    total = r % MAX_DECK;
    if(total == 0){
    	total++;
    }
    //Fills deck
    for(i=0; i < total; i++){
      r = rand();
      card = r % treasure_map;
      game->deck[player][i] = card;
    }
    game->deckCount[player] = total;
    
    //New random number
    r = rand();
    //Gets random number for player's hand, not 0
    total = r % MAX_HAND;
    if(total == 0){
      total++;
    }
    //Fills player's hand randomly
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
      failNum = 0;
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
      if(failNum != 0){
      	errorNum++;
      }
      else{
      	errorTotal += failNum;
      }
    }
    else{
      printf("villageMethod() Random Test %d:  FAIL.  Unknown error, danger, danger Will Robinson.\n", counter);
      errorNum++;
    }
    counter++;      
  }
  printf("Total Random Tests:  %d\n", counter);
  printf("villageMethod() Random Test fail number iterations:  %d\n", errorNum);
  printf("villageMethod() Random Test fail number total:  %d\n", errorTotal);
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
