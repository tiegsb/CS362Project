/* council room test */
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "cards.h"
#include "card_handlers.h"

const int SEED = 17;
const int NUM_PLAYERS = 4;

static void doTest(const char *testName, int condition) {
  printf("TEST %s:  ", testName);

  if (condition) {
    printf("PASS\n");
  } else {
    printf("FAIL\n");
  }
}

int main(int argc, char **argv) {
  const int player = NUM_PLAYERS - 1;
  int k[10] = {adventurer, council_room, feast,   gardens, mine,
               remodel,    smithy,       village, baron,   great_hall};
  struct gameState state;
  int numCards;
  int numBuys;

  initializeGame(NUM_PLAYERS, k, SEED, &state);
  state.whoseTurn = player;
  numCards = state.handCount[player];
  numBuys = state.numBuys;

  state.hand[player][0] = council_room;
  
  councilRoomHandler(0, 0, 0, &state, 0, 0);
  doTest("gain 4 cards", state.handCount[player] == numCards + 3);
  doTest("gain 1 buy", state.numBuys = numBuys + 1);
}