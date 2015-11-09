/******************************************************************************
unittest3.c
Sharon Kuo (kuos@oregonstate.edu)
CS362-400: Assignment 3
Description: Unit testing for the fullDeckCount() function in dominion.c.
  fullDeckCount() should return the count of a specific card in a player's
  discard deck and hand.
******************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>

void test_fullDeckCount() {
  int count;  // store result of fullDeckCount()
  struct gameState game;
  int seed = 1000;
  int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy,
    village, baron, great_hall};  // set kingdom cards
  int numPlayer = 2;
  int player = 0;
  int passing = 1;  // keep track of all tests passing

  printf("************\nTESTING fullDeckCount()\n************\n");

  memset(&game, 23, sizeof(struct gameState));  // clear the game state
  initializeGame(numPlayer, k, seed, &game);  // initialize new game

  printf("\n******\nTesting fullDeckCount() with empty hand and discard pile"
    "\n******\n");
  // counts number of a given card in the deck first
  game.deckCount[0] = 10; // start with 10 cards in deck
  game.deck[0][0] = estate;
  game.deck[0][1] = copper;
  game.deck[0][2] = silver;
  game.deck[0][3] = silver;
  game.deck[0][4] = silver;
  game.deck[0][5] = mine;
  game.deck[0][6] = village;
  game.deck[0][7] = village;
  game.deck[0][8] = silver;
  game.deck[0][9] = silver;
  game.handCount[0] = 0;
  game.discardCount[0] = 0;
  printf("Put 1 estate, 1 copper, 5 silver, 1 mine, and 2 village in deck, "
    "with empty hand and discard piles.\n");

  // test card with multiple copies in deck
  count = fullDeckCount(player, silver, &game);
  if (count != 5) {
      printf("FAIL: expected silver card count is 5; actual value is %d\n",
        count);
    passing = 0;
  }
  else
    printf("PASS: expected silver card count is 5; actual value is %d\n",
      count);

  // test card with single copy in deck
  count = fullDeckCount(player, estate, &game);
  if (count != 1) {
      printf("FAIL: expected estate card count is 1; actual value is %d\n",
        count);
    passing = 0;
  }
  else
    printf("PASS: expected estate card count is 1; actual value is %d\n",
      count);

  // test card in k but not in deck
  count = fullDeckCount(player, adventurer, &game);
  if (count != 0) {
      printf("FAIL: expected adventurer card count is 0; actual value is %d\n",
        count);
    passing = 0;
  }
  else
    printf("PASS: expected adventurer card count is 0; actual value is %d\n",
      count);

  // test card not in k
  count = fullDeckCount(player, cutpurse, &game);
  if (count != 0) {
      printf("FAIL: expected cutpurse card count is 0; actual value is %d\n",
        count);
    passing = 0;
  }
  else
    printf("PASS: expected cutpurse card count is 0; actual value is %d\n",
      count);

  printf("\n******\nTesting fullDeckCount() with non-empty deck, non-empty "
    "hand, and empty discard pile\n******\n");
  // counts number of cards in hand after counting deck
  game.handCount[0] = 3;
  game.hand[0][0] = silver;
  game.hand[0][1] = adventurer;
  game.hand[0][2] = silver;
  printf("Add 2 silver and 1 adventurer to hand.\n");

  // test card in hand but not in deck
  count = fullDeckCount(player, adventurer, &game);
  if (count != 1) {
      printf("FAIL: expected adventurer card count is 1; actual value is %d\n",
        count);
    passing = 0;
  }
  else
    printf("PASS: expected adventurer card count is 1; actual value is %d\n",
      count);

  // test card in k but not in deck or hand
  count = fullDeckCount(player, feast, &game);
  if (count != 0) {
      printf("FAIL: expected feast card count is 0; actual value is %d\n",
        count);
    passing = 0;
  }
  else
    printf("PASS: expected feast card count is 0; actual value is %d\n",
      count);

  // test card in deck and hand
  count = fullDeckCount(player, silver, &game);
  if (count != 7) {
      printf("FAIL: expected silver card count is 7; actual value is %d\n",
        count);
    passing = 0;
  }
  else
    printf("PASS: expected silver card count is 7; actual value is %d\n",
      count);

  // test card not in k
  count = fullDeckCount(player, minion, &game);
  if (count != 0) {
      printf("FAIL: expected minion card count is 0; actual value is %d\n",
        count);
    passing = 0;
  }
  else
    printf("PASS: expected minion card count is 0; actual value is %d\n",
      count);

  printf("\n******\nTesting fullDeckCount() with non-empty deck, hand, and "
    "discard pile\n******\n");
  // counts number of cards in discard pile after counting deck and hand
  game.discardCount[0] = 2;
  game.discard[0][0] = feast;
  game.discard[0][1] = silver;
  printf("Add 1 feast and 1 silver to discard.\n");

  // test card in discard, but not in deck or hand
  count = fullDeckCount(player, feast, &game);
  if (count != 1) {
      printf("FAIL: expected feast card count is 1; actual value is %d\n",
        count);
    passing = 0;
  }
  else
    printf("PASS: expected feast card count is 1; actual value is %d\n",
      count);

  // test card in hand, but not in discard or deck
  count = fullDeckCount(player, adventurer, &game);
  if (count != 1) {
      printf("FAIL: expected adventurer card count is 1; actual value is %d\n",
        count);
    passing = 0;
  }
  else
    printf("PASS: expected adventurer card count is 1; actual value is %d\n",
      count);

  // test card in deck, hand, and discard
  count = fullDeckCount(player, silver, &game);
  if (count != 8) {
      printf("FAIL: expected silver card count is 8; actual value is %d\n",
        count);
    passing = 0;
  }
  else
    printf("PASS: expected silver card count is 8; actual value is %d\n",
      count);

  // test card not in k
  count = fullDeckCount(player, embargo, &game);
  if (count != 0) {
      printf("FAIL: expected embargo card count is 0; actual value is %d\n",
        count);
    passing = 0;
  }
  else
    printf("PASS: expected embargo card count is 0; actual value is %d\n",
      count);

  // if all tests passed
  printf("\n");
  if (passing)
    printf("PASS: all tests for fullDeckCount() passed\n");
  else
    printf("FAIL: one or more tests for fullDeckCount() failed\n");
}

int main() {
  test_fullDeckCount();
  return 0;
}
