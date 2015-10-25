/* adventurer test */
/*
make sure up to 2 treasure cards are added to hand
probably just fill deck with treasure, then all curses + 1 treasure, then no 
treasure
*/
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

/* count how many times the card given by cardNum is in hand */
static int numCard(int player, const struct gameState *state, enum CARD cardNum) {
  int i;
  int count = 0;

  for (i = 0; i < state->handCount[player]; i++)
    if (state->hand[player][i] == cardNum)
      count++;

  return count;
}

static void fillHand(int player, struct gameState *state, enum CARD cardNum) {
  int i;
  for (i = 0; i < state->handCount[player]; i++)
    state->hand[player][i] = cardNum;
}

static void fillDeck(int player, struct gameState *state, enum CARD cardNum) {
  int i;
  for (i = 0; i < state->deckCount[player]; i++)
    state->deck[player][i] = cardNum;
}

int main(int argc, char **argv) {
  const int player = NUM_PLAYERS - 1;
  int k[10] = {adventurer, council_room, feast,   gardens, mine,
               remodel,    smithy,       village, baron,   great_hall};
  struct gameState state;
  int handCount;

  initializeGame(NUM_PLAYERS, k, SEED, &state);
  state.whoseTurn = player;

  handCount = state.handCount[player];
  assert(handCount == 5);

  fillHand(player, &state, curse);
  updateCoins(player, &state, 0);
  assert(state.coins == 0);

  // set up for 0 treasure test
  fillDeck(player, &state, curse);
  state.hand[player][0] = adventurer;

  printf("test adventurer\n");
  adventurerHandler(0, 0, 0, &state, 0, NULL);
  updateCoins(player, &state, 0);

  doTest("no treasure", state.coins == 0);

  // set up for 1 treasure test
  state.deck[player][state.deckCount[player] - 1] = copper;
  state.hand[player][0] = adventurer;
  adventurerHandler(0, 0, 0, &state, 0, NULL);
  updateCoins(player, &state, 0);
  doTest("1 treasure", state.coins == 1);


  printf("test done\n");
  return 0;
}