/* Name: Kathryn McDonald
 * Class: CS 362
 * File name: unittest3.c
 * Purpose: Tests the "buyCard" function in dominion.c */

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

void successTest(int numPlayers, int kingdomCards[10], struct gameState *state) {
  /* initialize decks */
  testInitializeGame(numPlayers, kingdomCards, state);
  
  /* set up hand for Player 0 */
  state->hand[0][0] = copper;
  state->hand[0][1] = copper;
  state->hand[0][2] = copper;
  state->hand[0][3] = copper;
  state->hand[0][4] = copper;
  state->coins = 5;
    
  state->handCount[0] = 5; 
  
  printf("Setup complete.\n");
  
  /* test */
  printf("***\nSuccess test buyCard()...\n***\n");
  
  /* save game state */
  struct gameState Save;
  Save.numPlayers = state->numPlayers;
  Save.outpostPlayed = state->outpostPlayed;
  Save.outpostTurn = state->outpostTurn;
  Save.whoseTurn = state->whoseTurn;
  Save.phase = state->phase;
  Save.numActions = state->numActions;
  Save.coins = state->coins;
  Save.numBuys = state->numBuys;
  Save.handCount[0] = state->handCount[0];
  Save.handCount[1] = state->handCount[1];
  Save.deckCount[0] = state->deckCount[0];
  Save.deckCount[1] = state->deckCount[1];
  Save.discardCount[0] = state->discardCount[0];
  Save.discardCount[1] = state->discardCount[1];
  
  /* Player 0 buys a village card, costs 3 coins */
  int buyCardResult = buyCard(14, state);
  
  /* check buyCard() result */
#if (PRINT_TEST == 1)
  printf("buyCard Player 0.\nResult: %d, Expected: %d\n",buyCardResult, 0);
#endif
#if (ENABLE_ASSERTS == 1)
  assert(buyCardResult == 0);
#endif
  
  /* confirm discard */
#if (PRINT_TEST == 1)
  if (state->discardCount[0] == Save.discardCount[0] + 1)
    printf("Player 0 discardCount +1: Pass!\n");
  else
    printf("Player 0 discardCount +1: Fail!\n");
  if (state->discardCount[1] == Save.discardCount[1])
    printf("Player 1 discardCount unchanged: Pass!\n");
  else
    printf("Player 1 discardCount unchanged: Fail!\n");
#endif
  
#if (ENABLE_ASSERTS == 1)
  assert(state->discardCount[0] == Save.discardCount[0] + 1);
  assert(state->discardCount[1] == Save.discardCount[1]);
#endif
  
  /* confirm number of cards in Player 0 and Player 1's decks */
#if (PRINT_TEST == 1)
  if (Save.deckCount[0] == state->deckCount[0])
    printf("Player 0 deckCount unchanged: Pass!\n");
  else
    printf("Player 0 deckCount unchanged: Fail!\n");
  if (Save.deckCount[1] == state->deckCount[1])
    printf("Player 1 deckCount unchanged: Pass!\n");
  else
    printf("Player 1 deckCount unchanged: Fail!\n");
#endif
  
#if (ENABLE_ASSERTS == 1)
  assert(state->deckCount[0] == Save.deckCount[0] + 1);
  assert(Save.deckCount[1] == state->deckCount[1]);
#endif
    
  /* confirm game state elements */
#if (PRINT_TEST == 1)
  if (Save.numPlayers == state->numPlayers)
    printf("numPlayers unchanged: Pass!\n");
  else
    printf("numPlayers unchanged: Fail!\n");
  if (Save.outpostPlayed == state->outpostPlayed)
    printf("outpostPlayed unchanged: Pass!\n");
  else
    printf("outpostPlayed unchanged: Fail!\n");
  if (Save.outpostTurn == state->outpostTurn)
    printf("outpostTurn unchanged: Pass!\n");
  else
    printf("outpostTurn unchanged: Fail!\n");
  if (Save.whoseTurn == state->whoseTurn)
    printf("whoseTurn unchanged: Pass!\n");
  else
    printf("whoseTurn unchanged: Fail!\n");
  if (state->phase == 1)
    printf("Phase %d Expected %d: Pass!\n",state->phase,1);
  else
    printf("Phase %d Expected %d: Fail!\n",state->phase,1);
  if (Save.numActions == state->numActions)
    printf("numActions unchanged: Pass!\n");
  else
    printf("numActions unchanged: Fail!\n");
  if (state->coins == Save.coins - 3)
    printf("Coins -3: Pass!\n");
  else
    printf("Coins -3: Fail!\n");
  if (state->numBuys == Save.numBuys - 1)
    printf("numBuys-1: Pass!\n");
  else
    printf("numBuys-1: Fail!\n");
  if (Save.handCount[0] == state->handCount[0])
    printf("Player 0 handCount unchanged: Pass!\n");
  else
    printf("Player 0 handCount unchanged: Fail!\n");
  if (Save.handCount[1] == state->handCount[1])
    printf("Player 1 handCount unchanged: Pass!\n");
  else
    printf("Player 1 handCount unchanged: Fail!\n");
#endif

#if (ENABLE_ASSERTS == 1)
  assert(Save.numPlayers == state->numPlayers);
  assert(Save.outpostPlayed == state->outpostPlayed);
  assert(Save.outpostTurn == state->outpostTurn);
  assert(Save.whoseTurn == state->whoseTurn);
  assert(state->phase == 1);
  assert(Save.numActions == state->numActions);
  assert(state->coins == Save.coins - 3);
  assert(state->numBuys == Save.numBuys - 1);
  assert(Save.handCount[0] == state->handCount[0]);
  assert(Save.handCount[1] == state->handCount[1]);
#endif
}

void notEnoughBuys(int numPlayers, int kingdomCards[10], struct gameState *state) {
  /* initialize decks */
  testInitializeGame(numPlayers, kingdomCards, state);
  
  /* set up hand for Player 0 */
  state->hand[0][0] = copper;
  state->hand[0][1] = copper;
  state->hand[0][2] = copper;
  state->hand[0][3] = copper;
  state->hand[0][4] = copper;
  state->coins = 5;
    
  state->handCount[0] = 5; 
  
  state->numBuys = 0;
  
  printf("Setup complete.\n");
  
  /* test */
  printf("***\nTest buyCard() not enough buys...\n***\n");
  
  /* save game state */
  struct gameState Save;
  Save.numPlayers = state->numPlayers;
  Save.outpostPlayed = state->outpostPlayed;
  Save.outpostTurn = state->outpostTurn;
  Save.whoseTurn = state->whoseTurn;
  Save.phase = state->phase;
  Save.numActions = state->numActions;
  Save.coins = state->coins;
  Save.numBuys = state->numBuys;
  Save.handCount[0] = state->handCount[0];
  Save.handCount[1] = state->handCount[1];
  Save.deckCount[0] = state->deckCount[0];
  Save.deckCount[1] = state->deckCount[1];
  Save.discardCount[0] = state->discardCount[0];
  Save.discardCount[1] = state->discardCount[1];
  
  /* Player 0 buys a village card, costs 3 coins */
  int buyCardResult = buyCard(14, state);
  
  /* check buyCard() result */
#if (PRINT_TEST == 1)
  printf("buyCard Player 0.\nResult: %d, Expected: %d\n",buyCardResult, -1);
#endif
#if (ENABLE_ASSERTS == 1)
  assert(buyCardResult == -1);
#endif
  
  /* confirm game elements unchanged */
#if (PRINT_TEST == 1)
  if (state->discardCount[0] == Save.discardCount[0])
    printf("Player 0 discardCount unchanged: Pass!\n");
  else
    printf("Player 0 discardCount unchanged: Fail!\n");
  if (state->discardCount[1] == Save.discardCount[1])
    printf("Player 1 discardCount unchanged: Pass!\n");
  else
    printf("Player 1 discardCount unchanged: Fail!\n");
   if (Save.deckCount[0] == state->deckCount[0])
    printf("Player 0 deckCount unchanged: Pass!\n");
  else
    printf("Player 0 deckCount unchanged: Fail!\n");
  if (Save.deckCount[1] == state->deckCount[1])
    printf("Player 1 deckCount unchanged: Pass!\n");
  else
    printf("Player 1 deckCount unchanged: Fail!\n");
  if (Save.numPlayers == state->numPlayers)
    printf("numPlayers unchanged: Pass!\n");
  else
    printf("numPlayers unchanged: Fail!\n");
  if (Save.outpostPlayed == state->outpostPlayed)
    printf("outpostPlayed unchanged: Pass!\n");
  else
    printf("outpostPlayed unchanged: Fail!\n");
  if (Save.outpostTurn == state->outpostTurn)
    printf("outpostTurn unchanged: Pass!\n");
  else
    printf("outpostTurn unchanged: Fail!\n");
  if (Save.whoseTurn == state->whoseTurn)
    printf("whoseTurn unchanged: Pass!\n");
  else
    printf("whoseTurn unchanged: Fail!\n");
  if (state->phase == 0)
    printf("Phase %d Expected %d: Pass!\n",state->phase,0);
  else
    printf("Phase %d Expected %d: Fail!\n",state->phase,0);
  if (Save.numActions == state->numActions)
    printf("numActions unchanged: Pass!\n");
  else
    printf("numActions unchanged: Fail!\n");
  if (state->coins == Save.coins)
    printf("Coins unchanged: Pass!\n");
  else
    printf("Coins unchanged: Fail!\n");
  if (state->numBuys == Save.numBuys)
    printf("numBuys unchanged: Pass!\n");
  else
    printf("numBuys unchanged: Fail!\n");
  if (Save.handCount[0] == state->handCount[0])
    printf("Player 0 handCount unchanged: Pass!\n");
  else
    printf("Player 0 handCount unchanged: Fail!\n");
  if (Save.handCount[1] == state->handCount[1])
    printf("Player 1 handCount unchanged: Pass!\n");
  else
    printf("Player 1 handCount unchanged: Fail!\n");
#endif
  
#if (ENABLE_ASSERTS == 1)
  assert(state->discardCount[0] == Save.discardCount[0]);
  assert(state->discardCount[1] == Save.discardCount[1]);
  assert(state->deckCount[0] == Save.deckCount[0]);
  assert(Save.deckCount[1] == state->deckCount[1]);
  assert(Save.numPlayers == state->numPlayers);
  assert(Save.outpostPlayed == state->outpostPlayed);
  assert(Save.outpostTurn == state->outpostTurn);
  assert(Save.whoseTurn == state->whoseTurn);
  assert(state->phase == 0);
  assert(Save.numActions == state->numActions);
  assert(state->coins == Save.coins);
  assert(state->numBuys == Save.numBuys);
  assert(Save.handCount[0] == state->handCount[0]);
  assert(Save.handCount[1] == state->handCount[1]);
#endif
}

void notEnoughCards(int numPlayers, int kingdomCards[10], struct gameState *state) {
  /* initialize decks */
  testInitializeGame(numPlayers, kingdomCards, state);
  
  /* set up hand for Player 0 */
  state->hand[0][0] = copper;
  state->hand[0][1] = copper;
  state->hand[0][2] = copper;
  state->hand[0][3] = copper;
  state->hand[0][4] = copper;
  state->coins = 5;
    
  state->handCount[0] = 5; 
  
  state->supplyCount[village] = 0;
  
  printf("Setup complete.\n");
  
  /* test */
  printf("***\nTest buyCard() not enough cards...\n***\n");
  
  /* save game state */
  struct gameState Save;
  Save.numPlayers = state->numPlayers;
  Save.outpostPlayed = state->outpostPlayed;
  Save.outpostTurn = state->outpostTurn;
  Save.whoseTurn = state->whoseTurn;
  Save.phase = state->phase;
  Save.numActions = state->numActions;
  Save.coins = state->coins;
  Save.numBuys = state->numBuys;
  Save.handCount[0] = state->handCount[0];
  Save.handCount[1] = state->handCount[1];
  Save.deckCount[0] = state->deckCount[0];
  Save.deckCount[1] = state->deckCount[1];
  Save.discardCount[0] = state->discardCount[0];
  Save.discardCount[1] = state->discardCount[1];
  
  /* Player 0 buys a village card, costs 3 coins */
  int buyCardResult = buyCard(14, state);
  
  /* check buyCard() result */
#if (PRINT_TEST == 1)
  printf("buyCard Player 0.\nResult: %d, Expected: %d\n",buyCardResult, -1);
#endif
#if (ENABLE_ASSERTS == 1)
  assert(buyCardResult == -1);
#endif
  
  /* confirm game elements unchanged */
#if (PRINT_TEST == 1)
  if (state->discardCount[0] == Save.discardCount[0])
    printf("Player 0 discardCount unchanged: Pass!\n");
  else
    printf("Player 0 discardCount unchanged: Fail!\n");
  if (state->discardCount[1] == Save.discardCount[1])
    printf("Player 1 discardCount unchanged: Pass!\n");
  else
    printf("Player 1 discardCount unchanged: Fail!\n");
   if (Save.deckCount[0] == state->deckCount[0])
    printf("Player 0 deckCount unchanged: Pass!\n");
  else
    printf("Player 0 deckCount unchanged: Fail!\n");
  if (Save.deckCount[1] == state->deckCount[1])
    printf("Player 1 deckCount unchanged: Pass!\n");
  else
    printf("Player 1 deckCount unchanged: Fail!\n");
  if (Save.numPlayers == state->numPlayers)
    printf("numPlayers unchanged: Pass!\n");
  else
    printf("numPlayers unchanged: Fail!\n");
  if (Save.outpostPlayed == state->outpostPlayed)
    printf("outpostPlayed unchanged: Pass!\n");
  else
    printf("outpostPlayed unchanged: Fail!\n");
  if (Save.outpostTurn == state->outpostTurn)
    printf("outpostTurn unchanged: Pass!\n");
  else
    printf("outpostTurn unchanged: Fail!\n");
  if (Save.whoseTurn == state->whoseTurn)
    printf("whoseTurn unchanged: Pass!\n");
  else
    printf("whoseTurn unchanged: Fail!\n");
  if (state->phase == 0)
    printf("Phase %d Expected %d: Pass!\n",state->phase,0);
  else
    printf("Phase %d Expected %d: Fail!\n",state->phase,0);
  if (Save.numActions == state->numActions)
    printf("numActions unchanged: Pass!\n");
  else
    printf("numActions unchanged: Fail!\n");
  if (state->coins == Save.coins)
    printf("Coins unchanged: Pass!\n");
  else
    printf("Coins unchanged: Fail!\n");
  if (state->numBuys == Save.numBuys)
    printf("numBuys unchanged: Pass!\n");
  else
    printf("numBuys unchanged: Fail!\n");
  if (Save.handCount[0] == state->handCount[0])
    printf("Player 0 handCount unchanged: Pass!\n");
  else
    printf("Player 0 handCount unchanged: Fail!\n");
  if (Save.handCount[1] == state->handCount[1])
    printf("Player 1 handCount unchanged: Pass!\n");
  else
    printf("Player 1 handCount unchanged: Fail!\n");
#endif
  
#if (ENABLE_ASSERTS == 1)
  assert(state->discardCount[0] == Save.discardCount[0]);
  assert(state->discardCount[1] == Save.discardCount[1]);
  assert(state->deckCount[0] == Save.deckCount[0]);
  assert(Save.deckCount[1] == state->deckCount[1]);
  assert(Save.numPlayers == state->numPlayers);
  assert(Save.outpostPlayed == state->outpostPlayed);
  assert(Save.outpostTurn == state->outpostTurn);
  assert(Save.whoseTurn == state->whoseTurn);
  assert(state->phase == 0);
  assert(Save.numActions == state->numActions);
  assert(state->coins == Save.coins);
  assert(state->numBuys == Save.numBuys);
  assert(Save.handCount[0] == state->handCount[0]);
  assert(Save.handCount[1] == state->handCount[1]);
#endif
}

void notEnoughCoins(int numPlayers, int kingdomCards[10], struct gameState *state) {
  /* initialize decks */
  testInitializeGame(numPlayers, kingdomCards, state);
  
  /* set up hand for Player 0 */
  state->hand[0][0] = copper;
  state->hand[0][1] = copper;
  state->hand[0][2] = copper;
  state->hand[0][3] = copper;
  state->coins = 4;
    
  state->handCount[0] = 4; 
  
  printf("Setup complete.\n");
  
  /* test */
  printf("***\nTest buyCard() not enough coins...\n***\n");
  
  /* save game state */
  struct gameState Save;
  Save.numPlayers = state->numPlayers;
  Save.outpostPlayed = state->outpostPlayed;
  Save.outpostTurn = state->outpostTurn;
  Save.whoseTurn = state->whoseTurn;
  Save.phase = state->phase;
  Save.numActions = state->numActions;
  Save.coins = state->coins;
  Save.numBuys = state->numBuys;
  Save.handCount[0] = state->handCount[0];
  Save.handCount[1] = state->handCount[1];
  Save.deckCount[0] = state->deckCount[0];
  Save.deckCount[1] = state->deckCount[1];
  Save.discardCount[0] = state->discardCount[0];
  Save.discardCount[1] = state->discardCount[1];
  
  /* Player 0 buys a mine card, costs 5 coins */
  int buyCardResult = buyCard(11, state);
  
  /* check buyCard() result */
#if (PRINT_TEST == 1)
  printf("buyCard Player 0.\nResult: %d, Expected: %d\n",buyCardResult, -1);
#endif
#if (ENABLE_ASSERTS == 1)
  assert(buyCardResult == -1);
#endif
  
  /* confirm game elements unchanged */
#if (PRINT_TEST == 1)
  if (state->discardCount[0] == Save.discardCount[0])
    printf("Player 0 discardCount unchanged: Pass!\n");
  else
    printf("Player 0 discardCount unchanged: Fail!\n");
  if (state->discardCount[1] == Save.discardCount[1])
    printf("Player 1 discardCount unchanged: Pass!\n");
  else
    printf("Player 1 discardCount unchanged: Fail!\n");
   if (Save.deckCount[0] == state->deckCount[0])
    printf("Player 0 deckCount unchanged: Pass!\n");
  else
    printf("Player 0 deckCount unchanged: Fail!\n");
  if (Save.deckCount[1] == state->deckCount[1])
    printf("Player 1 deckCount unchanged: Pass!\n");
  else
    printf("Player 1 deckCount unchanged: Fail!\n");
  if (Save.numPlayers == state->numPlayers)
    printf("numPlayers unchanged: Pass!\n");
  else
    printf("numPlayers unchanged: Fail!\n");
  if (Save.outpostPlayed == state->outpostPlayed)
    printf("outpostPlayed unchanged: Pass!\n");
  else
    printf("outpostPlayed unchanged: Fail!\n");
  if (Save.outpostTurn == state->outpostTurn)
    printf("outpostTurn unchanged: Pass!\n");
  else
    printf("outpostTurn unchanged: Fail!\n");
  if (Save.whoseTurn == state->whoseTurn)
    printf("whoseTurn unchanged: Pass!\n");
  else
    printf("whoseTurn unchanged: Fail!\n");
  if (state->phase == 0)
    printf("Phase %d Expected %d: Pass!\n",state->phase,0);
  else
    printf("Phase %d Expected %d: Fail!\n",state->phase,0);
  if (Save.numActions == state->numActions)
    printf("numActions unchanged: Pass!\n");
  else
    printf("numActions unchanged: Fail!\n");
  if (state->coins == Save.coins)
    printf("Coins unchanged: Pass!\n");
  else
    printf("Coins unchanged: Fail!\n");
  if (state->numBuys == Save.numBuys)
    printf("numBuys unchanged: Pass!\n");
  else
    printf("numBuys unchanged: Fail!\n");
  if (Save.handCount[0] == state->handCount[0])
    printf("Player 0 handCount unchanged: Pass!\n");
  else
    printf("Player 0 handCount unchanged: Fail!\n");
  if (Save.handCount[1] == state->handCount[1])
    printf("Player 1 handCount unchanged: Pass!\n");
  else
    printf("Player 1 handCount unchanged: Fail!\n");
#endif
  
#if (ENABLE_ASSERTS == 1)
  assert(state->discardCount[0] == Save.discardCount[0]);
  assert(state->discardCount[1] == Save.discardCount[1]);
  assert(state->deckCount[0] == Save.deckCount[0]);
  assert(Save.deckCount[1] == state->deckCount[1]);
  assert(Save.numPlayers == state->numPlayers);
  assert(Save.outpostPlayed == state->outpostPlayed);
  assert(Save.outpostTurn == state->outpostTurn);
  assert(Save.whoseTurn == state->whoseTurn);
  assert(state->phase == 0);
  assert(Save.numActions == state->numActions);
  assert(state->coins == Save.coins);
  assert(state->numBuys == Save.numBuys);
  assert(Save.handCount[0] == state->handCount[0]);
  assert(Save.handCount[1] == state->handCount[1]);
#endif
}
  
int main() {
  
  /* set up game state */
  struct gameState G;
  int k[10] = {adventurer, gardens, embargo, village, minion, 
    mine, cutpurse, sea_hag, tribute, smithy};
    
  /* Test successful result */
  successTest(2, k, &G);
  
  /* Test not enough buys */
  notEnoughBuys(2, k, &G);
  
  /* Test not enough cards */
  notEnoughCards(2, k, &G);
  
  /* Test not enough coins to buy card */
  notEnoughCoins(2, k, &G);
  
#if (ENABLE_ASSERTS == 1)
  printf("All tests passed!\n");
#endif
  
  return 0;
}