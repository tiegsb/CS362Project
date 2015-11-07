/*****************************************************
Author: Larissa Hahn
randomtestadventurer.c - Adventurer Card Random Test

NOTE: Compile with "make" command, but there IS a wait
time maybe 5-7 minutes or so due to the bugs in the files
which cause the tests to run slow. But they will
eventually complete with a great test report.

UPDATE: I will adjust the number here to make it take
less time to run per Piazza post.

******************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "rngs.h"
#include <assert.h>
#include <stdbool.h>
#include <time.h>
#define NOISY_TEST 0

int main (int argc, char** argv) {
  //Initialize variables
  srand(time(NULL));
  struct gameState g;
  int newGame;
  int drawntreasure = 0;
  int temphand[MAX_HAND];
  int z = 0;
  int cardDrawn = 0;
  int currentPlayer = 0;
  int i = 0;
  int j = 0;
  bool failure = false;
  int totalFailures = 0;
  int discardErrors = 0;
  int drawErrors = 0;
  int treasureCount = 0;
  int treasureErrors = 0;

  int k[10] = {
    smithy,
    adventurer,
    village,
    great_hall,
    council_room,
    gardens,
    feast,
    mine,
    embargo,
    tribute
  };

  //Tests begin
  printf("\n\n--------------------------------------\nrandomtestadventurer.c -- Tests Begin\n--------------------------------------\n\n");
  for (i = 0; i < 2; i++) {  //Reduced number due to bugs causing long wait times
    //Initialize game with Adventurer Card
    memset(&g, 23, sizeof(struct gameState));
    newGame = initializeGame(2, k, 1000, &g);
    assert(newGame == 0);
    g.whoseTurn = currentPlayer;
    g.handCount[0] = 1;
    g.hand[0][0] = adventurer;

    //Initialize deck
    int randomCard = rand()%27+1;
    for (j = 0; j < 50; j++) {
      g.deck[0][j] = randomCard;
    }
    g.deckCount[0] = 50;

    //Adventure card gets played now
    adventurerCard(drawntreasure, &g, currentPlayer, cardDrawn, temphand, z);

    //TEST 1 - Check for proper discard
    if (g.hand[0][0] == adventurer) {
      printf("-- FAIL: Adventurer card not discarded.\n");
      failure = true;
      discardErrors++;
    }

    //TEST 2 - Check for proper draw card
    if (g.handCount[0] > 2) {
      printf("-- FAIL: Too MANY cards drawn.\n---- Target: 2 cards. Actual: %d cards.\n", g.handCount[0]);
      failure = true;
      drawErrors++;
    } else if (g.handCount[0] < 2) {
      printf("-- FAIL: Too FEW cards drawn.\n---- Target: 2 cards. Actual: %d cards.\n", g.handCount[0]);
      failure = true;
      drawErrors++;
    }

    //TEST 3 - Check for proper treasure cards
    for (j = 0; j < g.handCount[0]; j++) {
      if (g.hand[0][j] == gold || g.hand[0][j] == silver || g.hand[0][j] == copper) {
        treasureCount++;
      }
    }
    if (treasureCount > 2) {
      printf("-- FAIL: Too MANY treasure cards.\n---- Target: 2 cards. Actual: %d cards.\n", treasureCount);
      failure = true;
      treasureErrors++;
    } else if (treasureCount < 2) {
      printf("-- FAIL: Too FEW treasure cards.\n---- Target: 2 cards. Actual: %d cards.\n", treasureCount);
      failure = true;
      treasureErrors++;
    }

    if (failure == true) {
      printf("^^^^^^^ Test Number %d out of 2 ^^^^^^^\n\n", i+1);
      totalFailures++;
    }
  }

  if (failure == true) {
    //FAILURE STATUS REPORT - Random Testing for Adventurer Card:
    printf("\n****************************************\n");
    printf("  ---- TEST FAILURE STATUS REPORT ----\n");
    printf("  ----       Adventurer Card      ----\n");
    printf("****************************************\n");
    printf("Total Test Failures:      %d/2\n", totalFailures);
    printf("Discard Card Errors:      %d\n", discardErrors);
    printf("Draw Card Errors:         %d\n", drawErrors);
    printf("Treasure Card Errors:     %d\n", treasureErrors);
    printf("****************************************\n\n");
  }
  else {
    printf("\nALL TESTS PASS.\n");
  }

  return 0;
}
