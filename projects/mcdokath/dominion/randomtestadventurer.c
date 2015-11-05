/* Name: Kathryn McDonald
 * Class: CS 362
 * File name: randomtestadventurer.c
 * Purpose: Random tester for the "adventurer" card in dominion.c */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <assert.h>

// how many times the tester should run
#define RUNTIMES 100

// to remove printfs, set PRINT_TEST to 0
#define PRINT_TEST 1

// to enable asserts, set ENABLE_ASSERTS to 1
#define ENABLE_ASSERTS 0

int testInitializeGame(int numPlayers, int kingdomCards[10], struct gameState *state) {
  int i;
  int j;
  int it;
  
  /* initialize supply */
  // set number of Curse cards
  if (numPlayers == 2) {
    state->supplyCount[curse] = 10;
  }
  else if (numPlayers == 3) {
    state->supplyCount[curse] = 20;
  }
  else {
    state->supplyCount[curse] = 30;
  }
  
  // set number of Victory cards
  if (numPlayers == 2) {
    state->supplyCount[estate] = 8;
    state->supplyCount[duchy] = 8;
    state->supplyCount[province] = 8;
  }
  else {
    state->supplyCount[estate] = 12;
    state->supplyCount[duchy] = 12;
    state->supplyCount[province] = 12;
  }
  
  // set number of Treasure cards
  state->supplyCount[copper] = 60 - (7 * numPlayers);
  state->supplyCount[silver] = 40;
  state->supplyCount[gold] = 30;
  
  // set number of Kingdom cards
  for (i = adventurer; i <= treasure_map; i++) { // loop all cards
    for (j = 0; j < 10; j++) {			 // loop chosen cards
      if (kingdomCards[j] == i) {
	//check if card is a 'Victory' Kingdom card
	if (kingdomCards[j] == great_hall || kingdomCards[j] == gardens) {
	  if (numPlayers == 2) {
	    state->supplyCount[i] = 8;
	  }
	  else {
	    state->supplyCount[i] = 12;
	  }
	}
	else {
	  state->supplyCount[i] = 10;
	}
	break;
      }
      else {// card is not in the set chosen for the game
	state->supplyCount[i] = -1;
      }
    }
  }
  
  // set player decks
  for (i = 0; i < numPlayers; i++) {
    state->deckCount[i] = 0;
    for (j = 0; j < 3; j++) {
      state->deck[i][j] = estate;
      state->deckCount[i]++;
    }
    for (j = 3; j < 10; j++) {
      state->deck[i][j] = copper;
      state->deckCount[i]++;
    }
  }
  
  //shuffle player decks
  for (i = 0; i < numPlayers; i++) {
    if (shuffle(i,state) < 0) {
      return -1;
    }
  }
  
  //set embargo tokens to 0 for all supply piles
  for (i = 0; i <= treasure_map; i++) {
    state->embargoTokens[i] = 0;
  }
  
  //initialize first player's turn
  state->outpostPlayed = 0;
  state->phase = 0;
  state->numActions = 1;
  state->numBuys = 1;
  state->playedCardCount = 0;
  state->whoseTurn = 0;
  state->handCount[state->whoseTurn] = 0;
  
  return 0;
}

int consistencyCheck(int numPlayers, int kingdomCards[10], struct gameState *currentState, struct gameState *saveState) {
  printf("numPlayers: %d\n", numPlayers);
  return 0;
}

int main() {
  
  /* set up game state */
  int i;
  int handCount;
  int k[10] = {adventurer, council_room, feast, gardens, mine, 
    remodel, smithy, village, baron, great_hall};
  struct gameState G;
  int maxHandCount = 5;
  
  /* randomly generate amount of players */
  int numPlayers;
  
  /* initialize decks */
  testInitializeGame(numPlayers, k, &G);
  
  /* randomly generate which player to test */
  int testedPlayer;
  
  /* randomly generate a hand */
  
  /* randomly include adventurer card in one of the hand positions */
  
  /* play adventurer card */
  
  /* check consistency */
  int testState = consistencyCheck(numPlayers, k, &G, &Save);
  
  /* report */
  if (testState == 0) {
    printf("All tests passed!\n");
  }
  else {
    printf("FAILURE\nnumPlayers: %d, tested player: %d\n",numPlayers,testedPlayer);
  }
 
  /* set up game state */
 /* 
  

  
  /* set up hand for Player 0 */
 /* G.hand[0][0] = copper;
  G.hand[0][1] = copper;
  G.hand[0][2] = copper;
  G.hand[0][3] = copper;
  G.hand[0][4] = adventurer;
  
  G.handCount[0] = 5;
  
  printf("Setup complete.\n");
  
  /* test */
 // printf("Testing Adventurer Card...\n");
  
  /* save game state */
 /* struct gameState Save;
  Save.numActions = G.numActions;
  Save.numBuys = G.numBuys;
  Save.handCount[0] = G.handCount[0];*/
  
  /* play adventurer */
  /*int adventurerResult = adventurerEffect(&G,0);
#if (PRINT_TEST == 1)
  printf("adventurerResult: %d ",adventurerResult);
  if (adventurerResult == 0)
    printf("Pass!\n");
  else
    printf("Fail!\n");
#endif
  
#if (ENABLE_ASSERTS == 1)
  assert(adventurerResult == 0);
#endif
  
  /* confirm +2 cards */
/*#if (PRINT_TEST == 1)
  printf("Hand Count: %d ",G.handCount[0]);
  if (G.handCount[0] - Save.handCount[0] == 2)
    printf("Pass!\n");
  else
    printf("Fail!\n");
#endif
  
#if (ENABLE_ASSERTS == 1)
  assert(G.handCount[0] - Save.handCount[0] == 2);
#endif
  
  /* confirm that drawn cards are Treasure Cards */
 /* for (i = 5; i < G.handCount[0]; i++) { // start after existing hand
#if (PRINT_TEST == 1)
    if (G.hand[0][i] == copper || silver || gold)
      printf("Drawn card is Treasure: Pass!\n");
    else
      printf("Drawn card is Treasure: Fail!\n");
#endif
#if (ENABLE_ASSERTS == 1)
    assert(G.hand[0][i] == copper || silver || gold);
#endif
  }
  
#if (ENABLE_ASSERTS == 1)
  printf("All tests passed!\n");
#endif
  */
  return 0;
}