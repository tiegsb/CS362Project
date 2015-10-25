/* smithy test */
#include <stdio.h>
#include <string.h>
#include "dominion.h"
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

char *printHand(int playerNum, const struct gameState *state) {
  static const char *cardNames[] = {
    "curse ",
    "estate ",
    "duchy ",
    "province ",
    "copper ",
    "silver ",
    "gold ",
    "adventurer ",
    "council_room ",
    "feast ",
    "gardens ",
    "mine ",
    "remodel ",
    "smithy ",
    "village ",
    "baron ",
    "great_hall ",
    "minion ",
    "steward ",
    "tribute ",
    "ambassador ",
    "cutpurse ",
    "embargo ",
    "outpost ",
    "salvager ",
    "sea_hag ",
    "treasure_map "
  };

  static char buf[MAX_HAND * 13] = {0};

  int i;

  for (i = 0; i < state->handCount[playerNum]; i++)
    strcat(buf, cardNames[state->hand[playerNum][i]]);

  return buf;
}

int main(int argc, char **argv) {
  const int player = NUM_PLAYERS - 1;
  int k[10] = {adventurer, council_room, feast,   gardens, mine,
               remodel,    smithy,       village, baron,   great_hall};
  struct gameState state;
  int handCount;
  int numSmithys, numSmithys2;

  initializeGame(NUM_PLAYERS, k, SEED, &state);
  state.whoseTurn = player;

  printf("initial hand: %s\n", printHand(player, &state));

  /* 
  - init hand state with two smithys
  - use one smithy
    - make sure one smithy is left
    - make sure hand has grown by three
  */

  /* put two smithys in hand */
  state.hand[player][0] = smithy;
  state.hand[player][1] = smithy;

  printf("hand with smithys: %s\n", printHand(player, &state));

  handCount = state.handCount[player];
  printf("player hand count before: %d\n", handCount);

  numSmithys = numCard(player, &state, smithy);
  printf("smithys before: %d\n", numSmithys);

  /* use a smithy */
  smithyHandler(0, 0, 0, &state, 0, NULL);
  numSmithys2 = numCard(player, &state, smithy);
  printf("smithys after: %d\n", numSmithys2);

  doTest("one smithy remains", numSmithys2 == numSmithys - 1);
  doTest("correct hand count", state.handCount[player] == handCount + 2);
  
  printf("player hand count after: %d\n", state.handCount[player]);
  printf("final hand: %s\n", printHand(player, &state));

}