/*****************
 * Author:  Brian Stamm
 * Title:  cardTest1.c
 * Assignment:  3
 * Date:  10.25.15
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
  int testHandCount, testDeckCount, testDiscardCount;
  int testTrialCard;

  initializeGame(2, k, r, game);

  testTrialCard = game->hand[player][0];
  testHandCount = game->handCount[player] + 3;
  testDiscardCount = game->discardCount[player] + 1;
  testDeckCount = game->deckCount[player] - 1;

  if(smithyMethod(game, player, 0) == 0){
    if(testDiscardCount == game->discardCount[player]){
      printf("smithyMethod() Test 1a:  PASS, discard amounts equal.\n");
      printf("\tTest:  %d\tSaved:  %d\n", testDiscardCount, game->discardCount[player]);
    }
    else{
      printf("smithyMethod() Test 1a:  FAIL, discard amounts NOT equal.\n");
      printf("\tTest:  %d\tSaved:  %d\n", testDiscardCount, game->discardCount[player]);
    }

    if(testHandCount == game->handCount[player]){
      printf("Test 1b:  PASS, handCount amounts equal.\n");
      printf("\tTest:  %d\tSaved:  %d\n", testHandCount, game->handCount[player]);      
    }
    else{
      printf("Test 1b:  FAIL, handCount amounts NOT equal.\n");
      printf("\tTest:  %d\tSaved:  %d\n", testHandCount, game->handCount[player]); 
    }

    if(testDeckCount == game->deckCount[player]){
      printf("Test 1c:  PASS, deckCount amounts equal.\n");
      printf("\tTest:  %d\tSaved:  %d\n", testDeckCount, game->deckCount[player]); 
    }
    else{
      printf("Test 1c:  FAIL, deckCount amounts NOT equal.\n");
      printf("\tTest:  %d\tSaved:  %d\n", testDeckCount, game->deckCount[player]);      
    }
  }
  else{
    printf("smithyMethod() Test 1:  FAIL.  Unknown error, danger, danger Will Robinson.\n");
  }

//Then do random decks, similar to shuffle test.
  printf("\nRandom Testing to Start\n");
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
    testHandCount = game->handCount[player] + 3;
    testDiscardCount = game->discardCount[player] + 1;
    testDeckCount = game->deckCount[player] - 1;
    printf("\n");
    if(smithyMethod(game, player, 0) == 0){
      if(testDiscardCount != game->discardCount[player]){
        printf("smithyMethod() Random Test %da:  FAIL, discard amounts NOT equal.\n", counter);
        printf("\tTest:  %d\tSaved:  %d\n", testDiscardCount, game->discardCount[player]);
        failNum++;
      }

      if(testHandCount != game->handCount[player]){
        printf("Random Test %db:  FAIL, handCount amounts NOT equal.\n", counter);
        printf("\tTest:  %d\tSaved:  %d\n", testHandCount, game->handCount[player]);
        failNum++;
      }

      if(testDeckCount != game->deckCount[player]){
        printf("Test %dc:  FAIL, deckCount amounts NOT equal.\n", counter);
        printf("\tTest:  %d\tSaved:  %d\n", testDeckCount, game->deckCount[player]);   
        failNum++;
      }
    }
    else{
      printf("smithyMethod() Random Test %d:  FAIL.  Unknown error, danger, danger Will Robinson.\n", counter);
    }
    counter++;      
  }
  printf("\nsmithyMethod() Random Test fail number:  %d\n", failNum);
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