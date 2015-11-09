#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "rngs.h"

#define VERBOSE 0

// function to quickly print the values of the relevant gameState vars
int printVillageSpecificGameState(struct gameState* gs, int player) {
  int i;
  
  // printf("Size of gameState = %d\n", gs);
  printf("numPlayers: %d\n", gs->numPlayers);
  
  /*
  for (i = 0; i < 27; i++) {
    printf("supplyCount[%d] = %d\n", i, gs->supplyCount[i]);
  }
  */

  printf("whoseTurn: %d\n", gs->whoseTurn);

  printf("phase: %d\n", gs->phase);
  printf("numActions: %d\n", gs->numActions);
  printf("coins: %d\n", gs->coins);
  printf("numBuys: %d\n", gs->numBuys);

  printf("handCount[%d] = %d\n", player, gs->handCount[player]);
  for (i = 0; i < gs->handCount[player]; i++) {
    printf("--hand[%d][%d] = %d\n", player, i, gs->hand[player][i]);
  }
  printf("deckCount[%d] = %d\n", player, gs->deckCount[player]);
  for (i = 0; i < gs->deckCount[player]; i++) {
    printf("--deck[%d][%d] = %d\n", player, i, gs->deck[player][i]);
  }
  printf("playedCardCount = %d\n", gs->playedCardCount);
  for (i = 0; i < gs->playedCardCount; i++) {
    printf("playedCards[%d] = %d\n", i, gs->playedCards[i]);
  }
  printf("discardCount[%d] = %d\n", player, gs->discardCount[player]);
  for (i = 0; i < gs->discardCount[player]; i++) {
    printf("--discard[%d][%d] = %d\n", player, i, gs->discard[player][i]);
  }

  return 0;
}

// function to randomize gameState vars relevant to village card
int randomizeGameState(struct gameState* g) {
  int i, k;

  g->numActions = rand();
  g->coins = rand();

  for (i = 0; i < g->numPlayers; i++) {
    for (k = 0; k < g->handCount[i]; k++) {
      g->hand[i][k] = rand() % treasure_map;
    }
  }
  for (i = 0; i < g->numPlayers; i++) {
    for (k = 0; k < g->deckCount[i]; k++) {
      g->deck[i][k] = rand() % treasure_map;
    }
  }

  return 0;
}

// function to randomly test the village card
int randomTestVillage(int playerCount, int playerTested) {
  struct gameState g, saved;

  int errorCount = 0;
  int seed = rand();

  int actionCards[10] = { adventurer, council_room, feast, gardens, mine, remodel,
    smithy, village, baron, minion };

  // initialize game state
  if (initializeGame(playerCount, actionCards, seed, &g)) {
    printf("Error initializing gameState\n");
  }

  // randomize gameState vars relevant to the village card
  randomizeGameState(&g);

  // make sure g.hand[playerTested][0] is village card
  g.hand[playerTested][0] = village;

  // and that playerTested is player whose turn is
  g.whoseTurn = playerTested;

  // save initialized game state
  memcpy(&saved, &g, sizeof(struct gameState));

#if VERBOSE
  printf(" -- RANDOMIZED GAME STATE BEFORE PLAYING VILLAGE CARD -- \n");
  printVillageSpecificGameState(&g, playerTested);
#endif
  
  // play card
#if VERBOSE
  printf("\n -- PLAYING VILLAGE CARD -- \n\n");
#endif
  playVillageCard(&g, 0);

  // assert that g.handCount[playerTested] is +1
  if (g.handCount[playerTested] != saved.handCount[playerTested] + 1) {
    errorCount++;
#if VERBOSE
    printf("ERROR: player %d did not gain 2 cards\n", playerTested);
#endif
  }

  // assert that g.numActions is +2
  if (g.numActions != saved.numActions + 2) {
    errorCount++;
#if VERBOSE
    printf("ERROR: player %d did not gain 2 actions\n", playerTested);
#endif
  }

  // assert that g.playedCardCount incremented by 1
  if (g.playedCardCount != saved.playedCardCount + 1) {
    errorCount++;
#if VERBOSE
    printf("ERROR: player %d did not gain 2 actions\n", playerTested);
#endif
  }


#if VERBOSE
  printf(" -- GAME STATE AFTER PLAYING VILLAGE CARD -- \n");
  printVillageSpecificGameState(&g, playerTested);
#endif

  return errorCount;
}


int main() {
  srand(time(0));

  int errorCount = 0;
  int i;

  for (i = 0; i < 100; i++) {
    errorCount = randomTestVillage(2, 0);
    errorCount += randomTestVillage(2, 1);
    errorCount += randomTestVillage(3, 0);
    errorCount += randomTestVillage(3, 1);
    errorCount += randomTestVillage(3, 2);
    errorCount += randomTestVillage(4, 0);
    errorCount += randomTestVillage(4, 1);
    errorCount += randomTestVillage(4, 2);
    errorCount += randomTestVillage(4, 3);
  }



  printf(" -- VILLAGE CARD TESTED %d TIMES WITH %d ERRORS\n", i*9, errorCount);

  return 0;
}
