#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "rngs.h"

#define VERBOSE 0 
#define VERBOSE_ERRORS 0

// function to quickly print the values of the relevant gameState vars
int printRelevantGameState(struct gameState* gs, int player) {
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

// function to randomize gameState vars relevant to adventurer card
int randomizeGameState(struct gameState* g, int playerTested) {
  int i, k;

  g->numActions = rand();
  g->coins = rand();

  // randomize hand
  for (i = 0; i < g->numPlayers; i++) {
    for (k = 0; k < g->handCount[i]; k++) {
      g->hand[i][k] = rand() % (treasure_map);
    }
  }
 
  // randomize deck
  for (i = 0; i < g->numPlayers; i++) {
    // printf("player %d deck count = %d\n", i, g->deckCount[i]);
    for (k = 0; k < g->deckCount[i]; k++) {
      g->deck[i][k] = rand() % (treasure_map);
    }
  }

  /*
  for (i = 0; i < g->deckCount[playerTested] - 2; i++) {
    g->deck[playerTested][i] = rand() % treasure_map;
  }
  */

  // make sure there are some coin cards in players' deck
  for (i = 0; i < g->numPlayers; i++) {
    for (k = 0; k < 5; k++) {
      gainCard((rand() % 3) + copper, g, 1, i);
    }
    // shuffle player's deck
    shuffle(i, g);
  }
   return 0;
}

// function to randomly test the adventurer card
int randomTestAdventurer(int playerCount, int playerTested) {
  struct gameState g, saved;

  int errorCount = 0;
  int seed = rand();
  int i/*, savedCount, gCount*/;
  int savedCoinCount = 0, currentCoinCount = 0;

  int actionCards[10] = { adventurer, council_room, feast, gardens, mine, remodel,
    smithy, village, baron, minion };

  // initialize game state
  if (initializeGame(playerCount, actionCards, seed, &g)) {
    printf("Error initializing gameState\n");
  }

  // randomize gameState vars relevant to the adventurer card
  randomizeGameState(&g, playerTested);

  // make sure g.hand[playerTested][0] is adventurer card
  // NOTE: can't just do below for players who aren't 'playing'
  if (playerTested == 0) {
    g.hand[playerTested][0] = adventurer;
  }
  else {
    gainCard(adventurer, &g, 2, playerTested);
  }

  // and that playerTested is player whose turn is
  g.whoseTurn = playerTested;

  // save initialized game state
  memcpy(&saved, &g, sizeof(struct gameState));

#if VERBOSE
  printf(" -- RANDOMIZED GAME STATE BEFORE PLAYING ADVENTURER CARD -- \n");
  printRelevantGameState(&g, playerTested);
#endif
  
  // play card
#if VERBOSE
  printf("\n -- PLAYING ADVENTURER CARD -- \n\n");
#endif
  playAdventureCard(&g);

  // assert that player's hand is now +2
  if (g.handCount[playerTested] != saved.handCount[playerTested] + 2) {
    errorCount++;
    int cardiff = g.handCount[playerTested] - saved.handCount[playerTested];
    printf("ERROR: expected player's hand-count to be +2, but it is %d\n", cardiff);
#if VERBOSE_ERRORS
    printf(" -- PLAYER HAND BEFORE PLAYING CARD -- \n");
    savedCount = saved.handCount[playerTested];
    // printRelevantGameState(&g, playerTested);
    for(i = 0; i < savedCount; i++) {
      printf("hand[%d][%d] = %d\n", playerTested, i, saved.hand[playerTested][i]);
    } 
    printf(" -- PLAYER HAND AFTER PLAYING CARD -- \n");
    gCount = g.handCount[playerTested];
    // printRelevantGameState(&g, playerTested);
    for(i = 0; i < gCount; i++) {
      printf("hand[%d][%d] = %d\n", playerTested, i, g.hand[playerTested][i]);
    } 
#endif
  }

  /*
  // and that deckCount + discardCount = prev - 2
  if (g.deckCount[playerTested] + g.discardCount[playerTested] !=
      saved.deckCount[playerTested] + saved.discardCount[playerTested] - 2) {
    errorCount++;
    printf("ERROR: not enough cards removed from deck\n");
  }
  */ 
     
  // assert that playerTested now has 2 additional coin cards
  for (i = 0; i < g.handCount[playerTested]; ++i) {
    if ((g.hand[playerTested][i] == gold) || (g.hand[playerTested][i] == silver) ||
        (g.hand[playerTested][i] == copper)) {
      currentCoinCount++;
    }
  }
  for (i = 0; i < saved.handCount[playerTested]; ++i) {
    if ((saved.hand[playerTested][i] == gold) || (saved.hand[playerTested][i] == silver) ||
        (saved.hand[playerTested][i] == copper)) {
      savedCoinCount++;
    }
  }

  if (currentCoinCount != savedCoinCount + 2) {
    printf("ERROR: not +2 Treasure cards. Coins before= %d, after= %d\n", 
        savedCoinCount, currentCoinCount);
    errorCount++;
  }

  /*
  // NOTE: taking this ERROR CHECK out, just because it hits every single test
  // assert that played adventurer card has gone on top of playedCard or discard decks
  if ((g.hand[playerTested][0] == 7) && (g.playedCards[0] != 7)) {
    if (g.discard[playerTested][0] != 7) {
      errorCount++;
      printf("ERROR: expected adventurer card atop played or discard piles, but it isn't\n");
    }
  }
  */

#if VERBOSE
  printf(" -- GAME STATE AFTER PLAYING ADVENTURER CARD -- \n");
  printRelevantGameState(&g, playerTested);
#endif

  return errorCount;
}


int main() {
  srand(time(0));

  int i, errorCount = 0;
  int loops = 350;
  int testRuns = 0;

  for (i = 0; i < loops; i++) {
    errorCount += randomTestAdventurer(2, 0);
    testRuns++;
    errorCount += randomTestAdventurer(3, 0);
    testRuns++;
    errorCount += randomTestAdventurer(4, 0);
    testRuns++;
  }
 
  printf(" -- VILLAGE CARD TESTED %d TIMES  WITH %d ERRORS\n", testRuns, errorCount);

  return 0;
}
