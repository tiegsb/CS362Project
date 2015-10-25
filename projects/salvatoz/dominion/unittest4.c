/* test shuffle
Dependencies:
  gameState::deckCount,deck
*/
#include <stdio.h>
#include "dominion.h"

const int SEED = 37;

static void doTest(char *testName, int condition) {
  printf("TEST %s: ", testName);

  if (condition) {
    printf("PASS\n");
  } else {
    printf("FAIL\n");
  }
}

int main(int argc, char **argv) {
  struct gameState state;
  const int numPlayers = 4;
  const int player = 3;
  int playerDeckCount;

  /* init game state */
  int k[10] = {adventurer, council_room, feast,   gardens, mine,
               remodel,    smithy,       village, baron,   great_hall};
  initializeGame(numPlayers, k, SEED, &state);

  playerDeckCount = state.deckCount[player];

  printf("Testing shuffle()\n");

  /* test empty deck */
  state.deckCount[player] = 0;
  doTest("empty deck", shuffle(player, &state) == -1);

  /* test not empty deck */
  state.deckCount[player] = playerDeckCount;  /* restore saved deck count */
  doTest("not empty deck returns 0", shuffle(player, &state) == 0);
  doTest("player deck count preserved", 
         state.deckCount[player] == playerDeckCount);

  return 0;
}