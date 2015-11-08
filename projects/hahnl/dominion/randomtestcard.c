/*****************************************************
Author: Larissa Hahn
randomtestcard.c - Smithy Card Random Test
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
  int handPos = 0;
  int bonus = 0;
  int i = 0;
  int j = 0;
  bool failure = false;
  int totalFailures = 0;
  int discardErrors = 0;
  int drawErrors = 0;
  int playedErrors = 0;

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
  printf("\n\n--------------------------------------\nrandomtestcard.c -- Tests Begin\n--------------------------------------\n\n");
  for (i = 0; i < 1000; i++) {
    //Initialize game with Smithy Card
    memset(&g, 23, sizeof(struct gameState));
    newGame = initializeGame(2, k, 1000, &g);
    assert(newGame == 0);
    g.whoseTurn = 0;
    g.handCount[0] = 1;
    g.hand[0][0] = smithy;

    //Initialize deck
    int randomCard = rand()%27+1;
    for (j = 0; j < 50; j++) {
      g.deck[0][j] = randomCard;
    }
    g.deckCount[0] = 50;

    //Smithy Card
    cardEffect(smithy, 1, 2, 3, &g, handPos, &bonus);

    //TEST 1 - Check for proper discard
    if (g.hand[0][0] == smithy) {
      printf("-- FAIL: Smithy card not discarded.\n");
      failure = true;
      discardErrors++;
    }

    //TEST 2 - Check for proper draw card
    if (g.handCount[0] > 3) {
      printf("-- FAIL: Too MANY cards drawn.\n---- Target: 3 cards. Actual: %d cards.\n", g.handCount[0]);
      failure = true;
      drawErrors++;
    } else if (g.handCount[0] < 3) {
      printf("-- FAIL: Too FEW cards drawn.\n---- Target: 3 cards. Actual: %d cards.\n", g.handCount[0]);
      failure = true;
      drawErrors++;
    }

    //TEST 3 - Check for proper played card
    if (g.playedCardCount > 1) {
      printf("-- FAIL: Too MANY cards played.\n---- Target: 1 cards. Actual: %d cards.\n", g.playedCardCount);
      failure = true;
      playedErrors++;
    } else if (g.playedCardCount < 1) {
      printf("-- FAIL: Too FEW cards played.\n---- Target: 1 cards. Actual: %d cards.\n", g.playedCardCount);
      failure = true;
      playedErrors++;
    }

    if (failure == true) {
      printf("^^^^^^^ Test Number %d out of 1000 ^^^^^^^\n\n", i+1);
      totalFailures++;
    }
  }

  if (failure == true) {
    //FAILURE STATUS REPORT - Random Testing for Smithy Card
    printf("\n****************************************\n");
    printf("  ---- TEST FAILURE STATUS REPORT ----\n");
    printf("  ----        Smithy Card         ----\n");
    printf("****************************************\n");
    printf("Total Test Failures:      %d/1000\n", totalFailures);
    printf("Discard Card Errors:      %d\n", discardErrors);
    printf("Draw Card Errors:         %d\n", drawErrors);
    printf("Played Card Errors:       %d\n", playedErrors);
    printf("****************************************\n\n");
  } else {
    printf("\nALL TESTS PASS.\n");
  }

  return 0;
}
