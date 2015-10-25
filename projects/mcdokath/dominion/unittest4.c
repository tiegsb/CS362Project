/* Name: Kathryn McDonald
 * Class: CS 362
 * File name: unittest4.c
 * Purpose: Tests the "gainCard" function in dominion.c */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <assert.h>

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

int main() {
  
  /* set up game state */
  struct gameState G;
  int k[10] = {adventurer, gardens, embargo, village, minion, 
    mine, cutpurse, sea_hag, tribute, smithy};
    
  /* initialize decks */
  testInitializeGame(2, k, &G);
  
  /* set up hand for Player 0 */
  G.hand[0][0] = copper;
  G.hand[0][1] = copper;
  G.hand[0][2] = copper;
  G.hand[0][3] = copper;
  G.hand[0][4] = copper;
    
  G.handCount[0] = 5; 
  
  /* save game state */
  struct gameState Save;
  Save.handCount[0] = G.handCount[0];
  Save.handCount[1] = G.handCount[1];
  Save.deckCount[0] = G.deckCount[0];
  Save.deckCount[1] = G.deckCount[1];
  Save.discardCount[0] = G.discardCount[0];
  Save.discardCount[1] = G.discardCount[1];
  
  printf("Setup complete.\n");
  
  /* test */
  printf("Testing gainCard()...\n");
  
  /* Player 0 gains estate card in discard pile */
  int gaincardResult = gainCard(1, &G, 0, 0);
  
  /* check gainCard() result */
#if (PRINT_TEST == 1)
  printf("gainCard Player 0.\nResult: %d, Expected: %d\n",gaincardResult, 0);
#endif
  
#if (ENABLE_ASSERTS == 1)
  assert(gaincardResult == 0);
#endif
  
  /* confirm hand, deck, and discard counts */
#if (PRINT_TEST == 1)
  if (Save.handCount[0] == G.handCount[0])
    printf("Player 0 handCount unchanged: Pass!\n");
  else
    printf("Player 0 handCount unchanged: Fail!\n");
  if (Save.handCount[1] == G.handCount[1])
    printf("Player 1 handCount unchanged: Pass!\n");
  else
    printf("Player 1 handCount unchanged: Fail!\n");
  if (Save.deckCount[0] == G.deckCount[0])
    printf("Player 0 deckCount unchanged: Pass!\n");
  else
    printf("Player 0 deckCount unchanged: Fail!\n");
  if (Save.deckCount[1] == G.deckCount[1])
    printf("Player 1 deckCount unchanged: Pass!\n");
  else
    printf("Player 1 deckCount unchanged: Fail!\n");
  if (G.discardCount[0] == Save.discardCount[0] + 1)
    printf("Player 0 discardCount + 1: Pass!\n");
  else
    printf("Player 0 discardCount + 1: Fail!\n");
  if (Save.discardCount[1] == G.discardCount[1])
    printf("Player 1 discardCount unchanged: Pass!\n");
  else
    printf("Player 1 discardCount unchanged: Fail!\n");
#endif

#if (ENABLE_ASSERTS == 1)
  assert(Save.handCount[0] == G.handCount[0]);
  assert(Save.handCount[1] == G.handCount[1]);
  assert(Save.deckCount[0] == G.deckCount[0]);
  assert(Save.deckCount[1] == G.deckCount[1]);
  assert(G.discardCount[0] == Save.discardCount[0] + 1);
  assert(Save.discardCount[1] == G.discardCount[1]);
#endif

#if (ENABLE_ASSERTS == 1)
  printf("All tests passed!\n");
#endif
  
  return 0;
}