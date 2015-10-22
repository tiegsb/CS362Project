/*****************
 * Author:  Brian Stamm
 * Title:  cardTest4.c
 * Assignment:  3
 * Date:  10.?.15
 * Notes:  Tests the Council card, in the councilMethod.
 * ****************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void test(){
	struct gameState *game;
	int player = 1;
  int testBuys;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
    sea_hag, tribute, smithy};
  srand(time(NULL));
  int r = rand();
  int i, counter, card, total, failNum;
  int testCards[3];
  int testHand[500];
  int testHandCount, testDeckCount, testDiscardCount;
  int testDiscard[500];
  int testTrialCard;

  initializeGame(4, k, r, game);


  //same tests as smithy card
  //Also, every player beside current player gets card, need to check them too
  //Max players is 4
  testBuys = game->numBuys;
  testBuys += 1;
  testTrialCard = game->hand[player][0];  //Do this?
  testHandCount = game->handCount[player];
  testDiscardCount = game->discardCount[player];
  testDeckCount = game->deckCount[player];

  printf("This is first initial test.\n");

  if(councilMethod(game, player, 0) == 0){
    if((testDiscardCount+1) == game->discardCount[player]){
      printf("councilMethod() Test 1:  PASS, discard amounts equal.\n");
    }
    else{
      printf("councilMethod() Test 1:  FAIL, discard amounts NOT equal.\n");
    }

    if((testHandCount+2) == game->handCount[player]){
      printf("councilMethod() Test 1:  PASS, handCount amounts equal.\n");
    }
    else{
      printf("councilMethod() Test 1:  FAIL, handCount amounts NOT equal.\n");
    }

    if(testDeckCount == game->deckCount[player]){
      printf("councilMethod() Test 1:  PASS, deckCount amounts equal.\n");
    }
    else{
      printf("councilMethod() Test 1:  FAIL, deckCount amounts NOT equal.\n");
    }
    if(game->numBuys == testBuys){
      printf("Council Test :  PASSED - buy number correct\n");
    }
    else{
      printf("Council Test :  FAILED - buy number NOT correct\n");
    }
  }
  else{
    printf("councilMethod() Test 1:  FAIL.  Unknown error, danger, danger Will Robinson.\n");
  }

  printf("This is random testing.\n");
  printf("Random Testing to Start\n");
  counter = 1;
  failNum = 0;
  int j;
  while(counter < 501){
    for(i=0; i < 10; i++){
      card = r % treasure_map;
      for(j=0;j<4;j++){
        game->deck[j][i] = card;
      }
    }
    for(i=0;i<4;i++){
      game->deckCount[i] = 10;
    }
    total = r % MAX_HAND;
    if(total == 0){
      total++;
    }
    for(i=0; i<total; i++){
      card = r % treasure_map;
      for(j=0;j<4;j++){
        game->hand[j][i] = card;
      }
    }
    for(i=0;i<4;i++){
      game->handCount[player] = total;
    }
    testTrialCard = game->hand[player][0];
    testHandCount = game->handCount[player];
    testDiscardCount = game->discardCount[player];
    testDeckCount = game->deckCount[player];

    if(councilMethod(game, player, 0) == 0){
      if((testDiscardCount+1) != game->discardCount[player]){
        printf("councilMethod() Random Test %d:  FAIL, discard amounts NOT equal.\n", counter);
        failNum++;
      }

      if((testHandCount+2) != game->handCount[player]){
        printf("councilMethod() Test %d:  FAIL, handCount amounts NOT equal.\n", counter);
        failNum++;
      }

      if(testDeckCount != game->deckCount[player]){
        printf("councilMethod() Test %d:  FAIL, deckCount amounts NOT equal.\n", counter);
        failNum++;
      }
      if(game->numBuys != testBuys){
        printf("councilMethod() Test %d:  FAILED - buy number NOT correct\n", counter);
        failNum++;
      }
    }
    else{
      printf("councilMethod() Random Test %d:  FAIL.  Unknown error, danger, danger Will Robinson.\n", counter);
    }
    counter++;
  }
  printf("smithyMethod() Random Test fail number:  %d\n", failNum);
}


int main(int argc, char **argv){

	printf("This is the tests for the Council card, in councilMethod().\n");
	
	test();

	return 0;
}

/*******************
Method being tested:

int councilMethod(struct gameState *state, int currentPlayer, int handPos){
  //+4 Cards
  int i;
  for (i = 0; i < 4; i++)
  {
    drawCard(currentPlayer, state);
  }
        
  //+1 Buy
  state->numBuys++;
        
  //Each other player draws a card
  for (i = 0; i < state->numPlayers; i++)
  {
    if ( i == currentPlayer )
    {
      drawCard(i, state);
    }
  }
        
  //put played card in played card pile
  discardCard(handPos, currentPlayer, state, 0);
        
  return 0;
}
*********************/
