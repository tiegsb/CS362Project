/******************************************************************************
unittest4.c
Sharon Kuo (kuos@oregonstate.edu)
CS362-400: Assignment 3
Description: Unit testing for the scoreFor() function in dominion.c.
  scoreFor() should return the score for a player, from the hand, discard, and
  deck.
******************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>

void test_scoreFor() {
  int score;  // store result of scoreFor()
  struct gameState game;
  int seed = 1000;
  int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy,
    village, baron, great_hall};  // set kingdom cards
  int numPlayer = 2;
  int player = 0;
  int passing = 1;  // keep track of all tests passing

  printf("************\nTESTING scoreFor()\n************\n");

  memset(&game, 23, sizeof(struct gameState));  // clear the game state
  initializeGame(numPlayer, k, seed, &game);  // initialize new game

  printf("\n******\nTesting scoreFor() with empty hand, discard, and deck"
    "\n******\n");
  game.handCount[0] = 0;
  game.discardCount[0] = 0;
  game.deckCount[0] = 0;
  score = scoreFor(0, &game);

  if (score != 0) {
      printf("FAIL: expected score is 0; actual value is %d\n", score);
    passing = 0;
  }
  else
    printf("PASS: expected score is 0; actual value is %d\n", score);

  memset(&game, 23, sizeof(struct gameState));  // clear the game state
  initializeGame(numPlayer, k, seed, &game);  // initialize new game

  printf("\n******\nTesting scoreFor() with garden cards and treasure cards"
    "\n******\n");
  printf("15 kingdom and 3 garden cards (total of 18 cards)\n");
  game.handCount[0] = 6;
  game.hand[0][0] = mine;
  game.hand[0][1] = smithy;
  game.hand[0][2] = smithy;
  game.hand[0][3] = smithy;
  game.hand[0][4] = mine;
  game.hand[0][5] = gardens;
  game.discardCount[0] = 6;
  game.discard[0][0] = mine;
  game.discard[0][1] = smithy;
  game.discard[0][2] = smithy;
  game.discard[0][3] = smithy;
  game.discard[0][4] = mine;
  game.discard[0][5] = gardens;
  game.deckCount[0] = 6;
  game.deck[0][0] = mine;
  game.deck[0][1] = smithy;
  game.deck[0][2] = smithy;
  game.deck[0][3] = smithy;
  game.deck[0][4] = mine;
  game.deck[0][5] = gardens;

  score = scoreFor(player, &game);
  if (score != 3) {
      printf("FAIL: expected score is 3; actual value is %d\n", score);
    passing = 0;
  }
  else
    printf("PASS: expected score is 3; actual value is %d\n", score);

  memset(&game, 23, sizeof(struct gameState));  // clear the game state
  initializeGame(numPlayer, k, seed, &game);  // initialize new game

  printf("15 treasure and 3 garden cards (total of 18 cards)\n");
  game.handCount[0] = 6;
  game.hand[0][0] = gold;
  game.hand[0][1] = silver;
  game.hand[0][2] = silver;
  game.hand[0][3] = copper;
  game.hand[0][4] = copper;
  game.hand[0][5] = gardens;
  game.discardCount[0] = 6;
  game.discard[0][0] = gold;
  game.discard[0][1] = silver;
  game.discard[0][2] = silver;
  game.discard[0][3] = copper;
  game.discard[0][4] = copper;
  game.discard[0][5] = gardens;
  game.deckCount[0] = 6;
  game.deck[0][0] = gold;
  game.deck[0][1] = silver;
  game.deck[0][2] = silver;
  game.deck[0][3] = copper;
  game.deck[0][4] = copper;
  game.deck[0][5] = gardens;

  score = scoreFor(player, &game);
  if (score != 3) {
      printf("FAIL: expected score is 3; actual value is %d\n", score);
    passing = 0;
  }
  else
    printf("PASS: expected score is 3; actual value is %d\n", score);

  printf("\n******\nTesting scoreFor() with all estate, duchy, provinces, or "
    "curse cards\n******\n");
  memset(&game, 23, sizeof(struct gameState));  // clear the game state
  initializeGame(numPlayer, k, seed, &game);  // initialize new game

  printf("9 estate, 3 duchy, 3 province, 3 curse\n");
  game.handCount[0] = 6;
  game.hand[0][0] = estate;
  game.hand[0][1] = estate;
  game.hand[0][2] = estate;
  game.hand[0][3] = duchy;
  game.hand[0][4] = province;
  game.hand[0][5] = curse;
  game.discardCount[0] = 6;
  game.discard[0][0] = estate;
  game.discard[0][1] = estate;
  game.discard[0][2] = estate;
  game.discard[0][3] = duchy;
  game.discard[0][4] = province;
  game.discard[0][5] = curse;
  game.deckCount[0] = 6;
  game.deck[0][0] = estate;
  game.deck[0][1] = estate;
  game.deck[0][2] = estate;
  game.deck[0][3] = duchy;
  game.deck[0][4] = province;
  game.deck[0][5] = curse;

  score = scoreFor(player, &game);
  if (score != 33) {
      printf("FAIL: expected score is 33; actual value is %d\n", score);
    passing = 0;
  }
  else
    printf("PASS: expected score is 33; actual value is %d\n", score);

  // if all tests passed
  printf("\n");
  if (passing)
    printf("PASS: all tests for scoreFor() passed\n");
  else
    printf("FAIL: one or more tests for scoreFor() failed\n");
}

int main() {
  test_scoreFor();
  return 0;
}
