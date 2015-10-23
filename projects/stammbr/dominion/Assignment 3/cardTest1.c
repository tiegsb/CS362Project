/*****************
 * Author:  Brian Stamm
 * Title:  cardTest1.c
 * Assignment:  3
 * Date:  10.?.15
 * Notes:  Unit Test for smithyMethod(), the Smithy card.
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
  int testCards[3];
  int testHand[500];
  int testHandCount, testDeckCount, testDiscardCount;
  int testDiscard[500];
  int testTrialCard;

  initializeGame(2, k, r, game);

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

  if(smithyMethod(game, player, 0) == 0){
    if((testDiscardCount+1) == game->discardCount[player]){
      printf("smithyMethod() Test 1:  PASS, discard amounts equal.\n");
    }
    else{
      printf("smithyMethod() Test 1:  FAIL, discard amounts NOT equal.\n");
    }

    if((testHandCount+2) == game->handCount[player]){
      printf("smithyMethod() Test 1:  PASS, handCount amounts equal.\n");
    }
    else{
      printf("smithyMethod() Test 1:  FAIL, handCount amounts NOT equal.\n");
    }

    if(testDeckCount == game->deckCount[player]){
      printf("smithyMethod() Test 1:  PASS, deckCount amounts equal.\n");
    }
    else{
      printf("smithyMethod() Test 1:  FAIL, deckCount amounts NOT equal.\n");
    }

    //need to check 3 cards, are they the same?

  }
  else{
    printf("smithyMethod() Test 1:  FAIL.  Unknown error, danger, danger Will Robinson.\n");
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

    if(smithyMethod(game, player, 0) == 0){
      if((testDiscardCount+1) != game->discardCount[player]){
        printf("smithyMethod() Random Test %d:  FAIL, discard amounts NOT equal.\n", counter);
        failNum++;
      }

      if((testHandCount+2) != game->handCount[player]){
        printf("smithyMethod() Test %d:  FAIL, handCount amounts NOT equal.\n", counter);
        failNum++;
      }

      if(testDeckCount != game->deckCount[player]){
        printf("smithyMethod() Test %d:  FAIL, deckCount amounts NOT equal.\n", counter);
        failNum++;
      }
    }
    else{
      printf("smithyMethod() Random Test %d:  FAIL.  Unknown error, danger, danger Will Robinson.\n", counter);
    }
    counter++;      
  }
  printf("smithyMethod() Random Test fail number:  %d\n", failNum);
}

int main(int argc, char **argv){

	printf("This is the tests the Smithy card - smithyMethod().\n");
	
	test();

	return 0;
}

/*****************
Method being tested

int smithyMethod(struct gameState *state, int currentPlayer, int handPos){
  //+3 Cards
  int i;
  for (i = 0; i <= 3; i++)
  {
    drawCard(currentPlayer, state);
  }

  //discard card from hand
  discardCard(handPos, currentPlayer, state, 0);
  return 0;
}
*******************/
