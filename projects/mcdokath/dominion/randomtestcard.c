/* Name: Kathryn McDonald
 * Class: CS 362
 * File name: randomtestcard.c
 * Purpose: Random tester for the "village" card in dominion.c */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

// how many times the tester should run
#define RUNTIMES 100

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

int generateNumPlayers() {
  /* generate random numbers of players from 2 to 4 */
  int numPlayers = rand() % 2 + 2;
  
  /* check numPlayers within limits */
  assert(numPlayers >= 2 && numPlayers <= MAX_PLAYERS);
  
  return numPlayers;
}

int choosePlayer(int numPlayers) {
  int player = -1;
  
  if (numPlayers == 2) {
    player = rand() % 1;
  }
  else if (numPlayers == 3) {
    player = rand() % 2;
  }
  else if (numPlayers == 4) {
    player = rand() % 3;
  }
  else {
    assert(numPlayers >= 2 && numPlayers <= MAX_PLAYERS);
  }
  
  return player;
}

int generateHand(struct gameState *state, int player, int maxHandCount) {
  int i;
  
  /* randomly generate all cards in hand */
  for (i = 0; i < maxHandCount; i++) {
    int cardNum = rand() % 16;
    switch(cardNum) {
      case 0:
	state->hand[player][i] = adventurer;
	break;
      case 1:
	state->hand[player][i] = council_room;
	break;
      case 2:
	state->hand[player][i] = feast;
	break;
      case 3:
	state->hand[player][i] = gardens;
	break;
      case 4:
	state->hand[player][i] = mine;
	break;
      case 5:
	state->hand[player][i] = remodel;
	break;
      case 6:
	state->hand[player][i] = smithy;
	break;
      case 7:
	state->hand[player][i] = village;
	break;
      case 8:
	state->hand[player][i] = baron;
	break;
      case 9:
	state->hand[player][i] = great_hall;
	break;
      case 10:
	state->hand[player][i] = copper;
	break;
      case 11:
	state->hand[player][i] = silver;
	break;
      case 12:
	state->hand[player][i] = gold;
	break;
      case 13:
	state->hand[player][i] = estate;
	break;
      case 14:
	state->hand[player][i] = duchy;
	break;
      case 15:
	state->hand[player][i] = province;
	break;
      default:
	assert(cardNum >= 0 && cardNum <= 15);
	return -1;
    }
 }
 
 return 0;
}

int checkVillage(struct gameState *state, int player, int maxHandCount, int *villagePos) {
  int i;
  
  /* see if player has village card */
  for (i = 0; i < maxHandCount; i++) {
   if (state->hand[player][i] == village) {
     *villagePos = i;
     return 0;
   }
  }
  
  /* return 1 if no village card found */
  return 1;
}

void insertVillage(struct gameState *state, int player, int maxHandCount, int *villagePos) {
 int handPos = rand() % maxHandCount;

  /* insert village card into random hand position */
  state->hand[player][handPos] = village;
  *villagePos = handPos;
}

int consistencyCheck(int numPlayers, int testedPlayer, int kingdomCards[10], struct gameState *currentState, struct gameState *saveState) {
  /* check that numActions +2, but since playing village was 1 action, numActions will only increase by 1 */
  if (!(currentState->numActions == saveState->numActions + 1)) {
    printf("----------\nERROR: numActions\n");
    return -1;
  }
  
  /* check unchanged game state elements */
  if (!(currentState->numPlayers == saveState->numPlayers)) {
    printf("----------\nERROR: numPlayers\n");
    return -1;
  }
  if (!(currentState->whoseTurn == saveState->whoseTurn)) {
    printf("----------\nERROR: whoseTurn\n");
    return -1;
  }
  if (!(currentState->phase == saveState->phase)) {
    printf("----------\nERROR: phase\n");
    return -1;
  }
  if (!(currentState->numBuys == saveState->numBuys)) {
    printf("----------\nERROR: numBuys\n");
    return -1;
  }
  /* because village has been discarded, the handCount should actually be the same */
  if (!(currentState->handCount[testedPlayer] == saveState->handCount[testedPlayer])) {
    printf("----------\nERROR: handCount\n");
    return -1;
  }
  /* one card has been drawn */
  if (!(currentState->deckCount[testedPlayer] == saveState->deckCount[testedPlayer] - 1)) {
    printf("----------\nERROR: deckCount\n");
    return -1;
  }
  
  /* if all tests passed, return 0 */
  return 0;
}

int main() {
  
  /* set up game state */
  int i;
  int villagePos = -1;
  int k[10] = {adventurer, council_room, feast, gardens, mine, 
    remodel, smithy, village, baron, great_hall};
  struct gameState G;
  struct gameState Save;
  int maxHandCount = 5;
  
  for (i = 0; i < RUNTIMES; i++) {
    /* set random seed */
    time_t t;
    srand((unsigned) time(&t));
    
    /* randomly generate amount of players */
    int numPlayers = generateNumPlayers();
    
    /* initialize decks */
    testInitializeGame(numPlayers, k, &G);
    
    /* randomly generate which player to test */
    int testedPlayer = choosePlayer(numPlayers);
    
    /* set the turn to that player */
    G.whoseTurn = testedPlayer;
    
    /* randomly generate a hand */
    int result = generateHand(&G, testedPlayer, maxHandCount);
    assert(result == 0);
    
    /* randomly include village card in one of the hand positions */
    if (checkVillage(&G, testedPlayer, maxHandCount, &villagePos) != 0) {
      insertVillage(&G, testedPlayer, maxHandCount, &villagePos);
    }
    
    G.handCount[testedPlayer] = 5;
    
    /* save game state */
    Save.numPlayers = G.numPlayers;
    Save.whoseTurn = G.whoseTurn;
    Save.phase = G.phase;
    Save.numActions = G.numActions;
    Save.numBuys = G.numBuys;
    Save.handCount[testedPlayer] = G.handCount[testedPlayer];
    Save.deckCount[testedPlayer] = G.deckCount[testedPlayer];
    
    /* play village card */
    result = playCard(villagePos, -1, -1, -1, &G);
    assert(result == 0);
    
    /* check consistency */
    int testState = consistencyCheck(numPlayers, testedPlayer, k, &G, &Save);
    
    /* report */
    if (testState == 0) {
      printf("All tests passed!\n");
    }
    else {
      printf("FAILURE\nnumPlayers: %d, tested player: %d\n",numPlayers,testedPlayer);
    }
  }
  return 0;
}
