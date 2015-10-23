//#############################################
// Filename: unittest2.c
// Unit Test Objective: Tests the fullDeckCount()
//                      method in dominion.c
//#############################################

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

#define DEBUG 0
#define NOISY_TEST 1

void checkFullDeckCount(int expectedDeckCount, int cardType, int player, struct gameState *state) {
  int actualDeckCount;

  actualDeckCount = fullDeckCount(player, cardType, state);

  if (expectedDeckCount != actualDeckCount)
  {
    printf("Test Failed: Expected card count was %d. Actual card count was %d\n", expectedDeckCount, actualDeckCount);
  }
  else
  {
    printf("Test Passed: Expected card count was %d. Actual card count was %d\n", expectedDeckCount, actualDeckCount);
  }

  assert (expectedDeckCount == actualDeckCount);
}

int main () {
  int i;
  int k[10] =
  {
    adventurer, council_room, feast, gardens, mine,
    remodel, smithy, village, baron, great_hall
  };

  struct gameState G;

  printf ("Unit Testing: fullDeckCount().\n");

  // Test for a single card
  printf ("Test for a single card type in the deck...\n");
  initializeGame(2, k, 1, &G);
  G.deckCount[0] = 3;
  G.deck[0][0] = adventurer;
  G.deck[0][1] = adventurer;
  G.deck[0][2] = adventurer;

  G.handCount[0] = 1;
  G.hand[0][0] = adventurer;

  G.discardCount[0] = 1;
  G.discard[0][0] = adventurer;
  checkFullDeckCount(5, adventurer, 0, &G);

  // Test for multiple card types in the deck for different players
  initializeGame(4, k, 1, &G);
  for (i = 0; i < MAX_PLAYERS; ++i)
  {
    printf ("Tests for a multiple card types in the deck for player %d...\n", i);
    G.deckCount[i] = 10;
    G.deck[i][0] = adventurer;
    G.deck[i][1] = council_room;
    G.deck[i][2] = feast;
    G.deck[i][3] = gardens;
    G.deck[i][4] = mine;
    G.deck[i][5] = remodel;
    G.deck[i][6] = smithy;
    G.deck[i][7] = village;
    G.deck[i][8] = baron;
    G.deck[i][9] = great_hall;

    G.handCount[i] = 5;
    G.hand[i][0] = adventurer;
    G.hand[i][1] = council_room;
    G.hand[i][2] = feast;
    G.hand[i][3] = feast;
    G.hand[i][4] = feast;

    G.discardCount[i] = 5;
    G.discard[i][0] = gardens;
    G.discard[i][1] = mine;
    G.discard[i][2] = remodel;
    G.discard[i][3] = smithy;
    G.discard[i][4] = village;
    checkFullDeckCount(2, adventurer, i, &G);
    checkFullDeckCount(2, council_room, i, &G);
    checkFullDeckCount(4, feast, i, &G);
    checkFullDeckCount(2, gardens, i, &G);
    checkFullDeckCount(2, mine, i, &G);
    checkFullDeckCount(2, remodel, i, &G);
    checkFullDeckCount(2, smithy, i, &G);
    checkFullDeckCount(2, village, i, &G);
    checkFullDeckCount(1, baron, i, &G);
    checkFullDeckCount(1, great_hall, i, &G);
  }

  return 0;
}
