/* mine test */
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

int main(int argc, char **argv) {
  const int player = NUM_PLAYERS - 1;
  const int cardToTrashPos = 0;
  const int badCardToTrash = 3;
  const int badCard = curse;
  const int cardToGain = gardens;
  const int cardToNotGain = province;
  const int handPos = 1;

  int status;
  int k[10] = {adventurer, council_room, feast,   gardens, mine,
               remodel,    smithy,       village, baron,   great_hall};
  struct gameState state;
  int numCards;
  int numMines;
  int numCoppers;

  initializeGame(NUM_PLAYERS, k, SEED, &state);
  state.whoseTurn = player;

  fillHand(player, &state, curse);

  /*
  - put a treasure card to trash in the player's hand
  - try to gain a card costing up to 3 more 

  things to test for:
  - more expensive card
  - nonexistent card
  - right number of cards remaining
  */

  // make sure an overpriced card doesn't gain
  printf("trying to gain card that's too expensive\n");
  state.hand[player][cardToTrashPos] = copper;
  state.hand[player][handPos] = mine;
  numCards = state.handCount[player];
  numMines = numCard(player, &state, mine);
  numCoppers = numCard(player, &state, copper);
  status = mineHandler(cardToTrashPos, cardToNotGain, 0, &state, handPos, NULL);
  doTest("return value", status != 1);
  doTest("hand size the same", state.handCount[player] == numCards);
  doTest("mine still in hand", numCard(player, &state, mine) == numMines);
  doTest("copper still in hand", numCard(player, &state, copper) == numCoppers);

  printf("\ntrying to gain card that's not too expensive\n");
  state.handCount[player] = 5;
  fillHand(player, &state, curse);
  state.hand[player][cardToTrashPos] = copper;
  state.hand[player][handPos] = mine;
  numCards = state.handCount[player];
  numMines = numCard(player, &state, mine);
  numCoppers = numCard(player, &state, copper);
  status = mineHandler(cardToTrashPos, cardToNotGain, 0, &state, handPos, NULL);
  doTest("return value", status == 1);
  doTest("hand size", state.handCount[player] == numCards - 1);
  doTest("mine not still in hand", 
         numCard(player, &state, mine) == numMines - 1);
  doTest("copper not still in hand", 
         numCard(player, &state, copper) == numCoppers - 1);

  printf("\ntrying to trash card that's not treasure\n");
  state.handCount[player] = 5;
  fillHand(player, &state, curse);
  state.hand[player][badCardToTrash] = badCard;
  state.hand[player][handPos] = mine;
  numCards = state.handCount[player];
  numMines = numCard(player, &state, mine);
  status = mineHandler(cardToTrashPos, cardToNotGain, 0, &state, handPos, NULL);
  doTest("return value", status != 1);
  doTest("hand size the same", state.handCount[player] == numCards);
  doTest("mine still in hand", numCard(player, &state, mine) == numMines);
}