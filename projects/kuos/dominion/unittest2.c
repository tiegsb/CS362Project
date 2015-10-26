/******************************************************************************
unittest2.c
Sharon Kuo (kuos@oregonstate.edu)
CS362-400: Assignment 3
Description: Unit testing for the isGameOver() function in dominion.c.
  Testing if the stack of provinces is empty, game ends.
  Testing if three different piles of cards are empty, game ends.
******************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>

void test_isGameOver() {
  int r;  // store result of isGameOver()
  int seed = 1000;
  int numPlayer = 2;
  int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy,
    village, baron, great_hall};  // set kingdom cards
  struct gameState game;
  int passing = 1;

  printf("************\nTESTING isGameOver():\n************\n");
  // conditions for game ending:
  //  1. pile of province cards is empty
  //  2. three different piles of cards are empty

  // test if game is not over at the beginning
  memset(&game, 23, sizeof(struct gameState));    // clear the game state
  initializeGame(numPlayer, k, seed, &game);  // initialize new game

  printf("\n******\nTesting isGameOver() at beginning of game\n******\n");
  r = isGameOver(&game);
  if (r) {
    printf("FAIL: initial isGameOver() expected is 0; actual value is "
      "%d\n", r);
    passing = 0;
  }
  else
    printf("PASS: initial isGameOver() expected is 0; actual value is "
      "%d\n", r);

  // test if game is over for a 2-player game for 0, 1, and 8 province cards
  printf("\n******\nTesting isGameOver() for province card counts"
    "\n******\n");
  game.supplyCount[province] = 8;
  r = isGameOver(&game);
  if (r) {
    printf("FAIL: province card count is 8; isGameOver() expected is 0; "
      "actual value is %d\n", r);
    passing = 0;
  }
  else
    printf("PASS: province card count is 8; isGameOver() expected is 0; "
      "actual value is %d\n", r);

  game.supplyCount[province] = 1;
  r = isGameOver(&game);
  if (r) {
    printf("FAIL: province card count is 1; isGameOver() expected is 0; "
      "actual value is %d\n", r);
    passing = 0;
  }
  else
    printf("PASS: province card count is 1; isGameOver() expected is 0; "
      "actual value is %d\n", r);

  game.supplyCount[province] = 0;
  r = isGameOver(&game);
  if (!r) {
    printf("FAIL: province card count is 0; isGameOver() expected is 1; "
      "actual value is %d\n", r);
  passing = 0;
}
  else
    printf("PASS: province card count is 0; isGameOver() expected is 1; "
      "actual value is %d\n", r);

  // test if game over for three-pile ending (three piles of supply cards are
  // empty)
  printf("\n******\nTesting isGameOver() for three-pile ending\n******\n");

  // test isGameOver() if treasure card piles are gone (copper, silver, and
  // gold)
  printf("\n***\nTesting treasure cards\n***\n");
  memset(&game, 23, sizeof(struct gameState));    // clear the game state
  initializeGame(numPlayer, k, seed, &game);  // initialize new game

  game.supplyCount[copper] = 0;
  r = isGameOver(&game);
  if (r) {
    printf("FAIL: only copper cards are gone; isGameOver() expected is 0; "
      "actual value is %d\n", r);
    passing = 0;
  }
  else
    printf("PASS: only copper cards are gone; isGameOver() expected is 0; "
      "actual value is %d\n", r);

  game.supplyCount[silver] = 0;
  r = isGameOver(&game);
  if (r) {
    printf("FAIL: only copper and silver cards are gone; isGameOver() "
      "expected is 0; actual value is %d\n", r);
    passing = 0;
  }
  else
    printf("PASS: only copper and silver cards are gone; isGameOver() "
      "expected is 0; actual value is %d\n", r);

  game.supplyCount[gold] = 0;
  r = isGameOver(&game);
  if (!r) {
    printf("FAIL: all copper, silver, and gold cards are gone; isGameOver() "
      "expected is 1; actual value is %d\n", r);
    passing = 0;
  }
  else
    printf("PASS: all copper, silver, and gold cards are gone; isGameOver() "
      "expected is 1; actual value is %d\n", r);

  // test isGameOver() if three kingdom cards are gone
  printf("\n***\nTesting kingdom cards\n***\n");
  memset(&game, 23, sizeof(struct gameState));    // clear the game state
  initializeGame(numPlayer, k, seed, &game);  // initialize new game

  game.supplyCount[feast] = 0;
  r = isGameOver(&game);
  if (r) {
    printf("FAIL: only feast cards are gone; isGameOver() expected is 0; "
      "actual value is %d\n", r);
    passing = 0;
  }
  else
    printf("PASS: only feast cards are gone; isGameOver() expected is 0; "
      "actual value is %d\n", r);

  game.supplyCount[gardens] = 0;
  r = isGameOver(&game);
  if (r) {
    printf("FAIL: only feast and garden cards are gone; isGameOver() expected "
      "is 0; actual value is %d\n", r);
    passing = 0;
  }
  else
    printf("PASS: only feast and garden cards are gone; isGameOver() expected "
      "is 0; actual value is %d\n", r);

  game.supplyCount[great_hall] = 0;
  r = isGameOver(&game);
  if (!r) {
    printf("FAIL: all feast, garden, and great hall cards are gone; "
      "isGameOver() expected is 1; actual value is %d\n", r);
    passing = 0;
  }
  else
    printf("PASS: all feast, garden, and great hall cards are gone; "
      "isGameOver() expected is 1; actual value is %d\n", r);


  // test isGameOver() if a combination of kingdom and treasure cards are gone
  printf("\n***\nTesting combination of kingdom and treasure cards\n***\n");
  memset(&game, 23, sizeof(struct gameState));    // clear the game state
  initializeGame(numPlayer, k, seed, &game);  // initialize new game

  game.supplyCount[mine] = 0;
  r = isGameOver(&game);
  if (r) {
    printf("FAIL: only mine cards are gone; isGameOver() expected is 0; "
      "actual value is %d\n", r);
    passing = 0;
  }
  else
    printf("PASS: only mine cards are gone; isGameOver() expected is 0; "
      "actual value is %d\n", r);

  game.supplyCount[copper] = 0;
  r = isGameOver(&game);
  if (r) {
    printf("FAIL: only mine and copper cards are gone; isGameOver() "
      "expected is 0; actual value is %d\n", r);
    passing = 0;
  }
  else
    printf("PASS: only mine and copper cards are gone; isGameOver() "
      "expected is 0; actual value is %d\n", r);

  game.supplyCount[baron] = 0;
  r = isGameOver(&game);
  if (!r) {
    printf("FAIL: all mine, copper, and baron cards are gone; isGameOver() "
      "expected is 1; actual value is %d\n", r);
    passing = 0;
  }
  else
    printf("PASS: all mine, copper, and baron cards are gone; isGameOver() "
      "expected is 1; actual value is %d\n", r);

  // if all tests passed
  printf("\n");
  if (passing)
    printf("PASS: all tests for isGameOver() passed\n");
  else
    printf("FAIL: one or more tests for isGameOver() failed\n");
}

int main() {
  test_isGameOver();
  return 0;
}
