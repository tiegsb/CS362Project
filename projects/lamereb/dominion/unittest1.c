#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "rngs.h"

#define VERBOSE 0

//the purpose here is to test the updateCoins() function
int testUpdateCoins(int numPlayers, int bonus) {
  struct gameState pre;
  int i, coinSum = 0;

  int seed = rand();

  int actionCards[10] = { adventurer, council_room, feast, gardens, mine, remodel,
    smithy, village, baron, minion };
  
  // initialize game state
  if (initializeGame(numPlayers, actionCards, seed, &pre)) {
    printf("Error initializing gameState\n");
  }

/*
 // pre.hand[0][1] = 5;
 printf("num players = %d\n", numPlayers);
  for (i = 0; i < numPlayers; ++i) {
    printf("player %d handCount = %d\n", i, pre.handCount[i]);
    printf("player %d deckCount = %d\n", i, pre.deckCount[i]);
    for (k = 0; k < pre.handCount[i]; ++k) {
      printf("player %d card %d = %d\n", i, k, pre.hand[i][k]);
    }
    for (l = 0; l < pre.deckCount[i]; ++l) {
      printf("player %d deckcard %d = %d\n", i, l, pre.deck[i][l]);

    }
  }
*/
  // get a sum of coin cards currently in player's hand
  for (i = 0; i < pre.handCount[0]; ++i) {
    if (pre.hand[0][i] == copper) {
      coinSum += 1;
    } 
    else if (pre.hand[0][i] == silver) {
      coinSum += 2;
    }
    else if (pre.hand[0][i] == gold) {
      coinSum += 3;
    }
  }
#if VERBOSE
  printf ("Sum of coins in hand before bonus: %d\n", coinSum);
#endif

  // add supplied bonus to sum
  coinSum += bonus;
#if VERBOSE
  printf("Sum of coins in hand after bonus: %d\n", coinSum);
  printf("State of gameState coins var before updateCoins() applied: %d\n", pre.coins);
  // printf("^should be correc b/c updateCoins is called in initializeGame()\n");
#endif

  // run updateCoins using supplied bonus
  if (updateCoins(0, &pre, bonus)) {
    printf("Error running updateCoins()\n");
  }

#if VERBOSE
  printf("State of gameState coins var after updateCoins() applied: %d\n", pre.coins);
#endif

  if (pre.coins != coinSum) {
    printf("Error in updateCoins()\n");
  }

  // make sure that other players do not have any cards in their hand
  for (i = 1; i < numPlayers; ++i) {
    if (pre.handCount[i] != 0) {
      printf("Player %d has cards in his hand!\n", i);
    }
  }

  return 0;
}


int main() {
  srand(time(0));

  int errorCount = 0;

  if (testUpdateCoins(2, 0)) {
    printf("Error testing updateCoins()\n");
    errorCount++;
  }
  if (testUpdateCoins(2, 1)) {
    printf("Error testing updateCoins()\n");
    errorCount++;
  }
  if (testUpdateCoins(2, 5)) {
    printf("Error testing updateCoins()\n");
    errorCount++;
  }
  if (testUpdateCoins(2, -1)) {
    printf("Error testing updateCoins()\n");
    errorCount++;

  }
  if (testUpdateCoins(2, 100)) {
    printf("Error testing updateCoins()\n");
    errorCount++;
  }

  printf("\nUNIT TEST 1 COMPLETE with %d ERRORS\n\n", errorCount);

  return 0;

}
