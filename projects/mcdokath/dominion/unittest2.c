/* Name: Kathryn McDonald
 * Class: CS 362
 * File name: unittest1.c
 * Purpose: Tests the "shuffle" function in dominion.c */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <assert.h>

// to remove printfs, set PRINT_TEST to 0
#define PRINT_TEST 1

// random seed
#define RANDOM_SEED 5

int main() {
  
  /* set up game state */
  struct gameState G;
  int k[10] = {adventurer, gardens, embargo, village, minion, 
    mine, cutpurse, sea_hag, tribute, smithy};
    
  /* set up hand */
  initializeGame(2, k, RANDOM_SEED, &G);
  
  printf("Setup complete.\n");
  
  /* test */
  printf("Testing shuffle()...\n");
  
  /* save game state */
  struct gameState Save;
  Save.numPlayers = G.numPlayers;
  Save.outpostPlayed = G.outpostPlayed;
  Save.outpostTurn = G.outpostTurn;
  Save.whoseTurn = G.whoseTurn;
  Save.phase = G.phase;
  Save.numActions = G.numActions;
  Save.coins = G.coins;
  Save.numBuys = G.numBuys;
  
  
  /* shuffle Player 0's deck */
  int shuffleResult = shuffle(0, &G);
  
  /* check shuffle() result */
#if (PRINT_TEST == 1)
  printf("Shuffle Player 0.\nResult: %d, Expected: %d\n",shuffleResult, 0);
#endif
  assert(shuffleResult == 0);
  
  /* shuffle Player 1's deck */
  shuffleResult = shuffle(1, &G);
  
  /* check shuffle() result */
#if (PRINT_TEST == 1)
  printf("Shuffle Player 1.\nResult: %d, Expected: %d\n",shuffleResult, 0);
#endif
  assert(shuffleResult == 0);
    
  printf("All tests passed!\n");
  
  return 0;
}