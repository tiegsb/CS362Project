/* updateCoins() test */
#include <stdio.h>
#include <string.h>
#include "dominion.h"
#include "dominion_helpers.h"

static void doTest(char *testName, int condition) {
  printf("TEST %s:  ", testName);

  if (condition) {
    printf("PASS\n");
  } else {
    printf("FAIL\n");
  }
}

void fillHand(int playerNum, struct gameState *state, enum CARD card) {
  int i;
  for (i = 0; i < state->handCount[playerNum]; i++)
    state->hand[playerNum][i] = card;
}
  
char *printHand(int playerNum, struct gameState *state) {
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
  struct gameState G;

  const int playerNum = 0;

  // set up gameState
  G.handCount[playerNum] = 5;

  // test no treasure cards
  fillHand(playerNum, &G, curse);
  updateCoins(playerNum, &G, 0);
  doTest("No treasure cards", G.coins == 0);

  // test 1 copper
  G.hand[playerNum][4] = copper;
  updateCoins(playerNum, &G, 0);
  doTest("1 copper", G.coins == 1);

  // test all copper
  fillHand(playerNum, &G, copper);
  updateCoins(playerNum, &G, 0);
  doTest("all copper", G.coins == G.handCount[playerNum]);

  // reset hand
  fillHand(playerNum, &G, curse);

  // test 1 silver
  G.hand[playerNum][4] = silver;
  updateCoins(playerNum, &G, 0);
  doTest("1 silver", G.coins == 2);

  // test all silver
  fillHand(playerNum, &G, silver);
  updateCoins(playerNum, &G, 0);
  doTest("all silver", G.coins == G.handCount[playerNum] * 2);

  // reset hand
  fillHand(playerNum, &G, curse);

  // test 1 gold
  G.hand[playerNum][4] = gold;
  updateCoins(playerNum, &G, 0);
  doTest("1 gold", G.coins == 3);

  // test all gold
  fillHand(playerNum, &G, gold);
  updateCoins(playerNum, &G, 0);
  doTest("all gold", G.coins == G.handCount[playerNum] * 3);

  return 0;
}