#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include "rngs.h"

static const int TEST_RUNS = 10000;

// Input: Array of kingdom cards
// Output: Random enum of any of the inputted kingdom cards
  // and victory, curse, and treasure cards
int randomCard(int k[10]) {
  int pool[17];
  int i;
  for (i = 0; i < 7; i++) {
    pool[i] = i; //To match enums of non-kingdom cards
  }
  for (i = 7; i < 17; i++) {
    pool[i] = k[i - 7]; //match enums of kingdom cards
  }
  return pool[rand() % 17];
}

// Randomizes hand
void randomizeHand(struct gameState * G, int k[10], int cur_player) {
  int i;
  G->handCount[cur_player] = 1 + rand() % (MAX_HAND - 2); // 1 to 498
  for (i = 0; i < G->handCount[cur_player]; i++) {
    G->hand[cur_player][i] = randomCard(k);
  }
}

// Randomizes deck
void randomizeDeck(struct gameState * G, int k[10], int cur_player) {
  int i;
  G->deckCount[cur_player] = 1 + rand() % MAX_DECK; // 1 to 500
  for (i = 0; i < G->deckCount[cur_player]; i++) {
    G->deck[cur_player][i] = randomCard(k);
  }
}

// Randomizes discard pile
void randomizeDiscard(struct gameState * G, int k[10], int cur_player) {
  int i;
  G->discardCount[cur_player] = 1 + rand() % (MAX_DECK - 1); // 1 to 499
  for (i = 0; i < G->discardCount[cur_player]; i++) {
    G->discard[cur_player][i] = randomCard(k);
  }
}

int main() {

  srand(time(NULL));

  int i;
  int seed = 1000; // This won't matter since we'll be randomizing the deck/hand
  int numPlayer = 4;
  int k[10] = {adventurer, council_room, feast, gardens, mine
             , remodel, smithy, village, baron, great_hall};
  struct gameState G;
  int cur_player;
  int handPos;
  int ori_handCount, valid_handCount;
  int valid_discard;
  int ori_nonhandCount, valid_nonhandCount;
  int sub_tests_total = TEST_RUNS * 4; // Four tests
  int sub_tests_passed = 0;
  int valid_handCount_passed = 0;
  int ori_actions, valid_actions;
  int valid_actions_passed;
  int valid_discard_passed = 0;
  int valid_nonhandCount_passed = 0;

	printf("Random testing buggyVillage():\n");

  for (i = 0; i < TEST_RUNS; i++) {
    initializeGame(numPlayer, k, seed, &G);
    cur_player = rand() % numPlayer;
    randomizeHand(&G, k, cur_player);
    randomizeDeck(&G, k, cur_player);
    randomizeDiscard(&G, k, cur_player);
    handPos = rand() % G.handCount[cur_player];
    G.hand[cur_player][handPos] = adventurer;
    G.whoseTurn = cur_player;
    ori_handCount = G.handCount[cur_player];
    ori_actions = G.numActions;
    ori_nonhandCount = G.deckCount[cur_player] + G.discardCount[cur_player];

    buggyVillage(&G, handPos);

    // Check net hand count the same as before (1 extra card - 1 village card)

    valid_handCount = 0;
    if (G.handCount[cur_player] == ori_handCount) {
      valid_handCount = 1;
    }

    // Check actions gain 1 net (1 to play village, 2 gained from village)

    valid_actions = 0;
    if (G.numActions == ori_actions + 1) {
      valid_actions = 1;
    }

    // Check village card is on top of discard pile

    valid_discard = 0;
    if (G.discard[cur_player][G.discardCount[cur_player] - 1] == village) {
      valid_discard = 1;
    }

    // Check net total of deck + discard is same as original
      // (1 village - 1 misc)

    valid_nonhandCount = 0;
    if (
      G.deckCount[cur_player] +
      G.discardCount[cur_player] ==
      ori_nonhandCount) {
      valid_nonhandCount = 1;
    }

    valid_handCount_passed += valid_handCount;
    valid_actions_passed += valid_actions;
    valid_discard_passed += valid_discard;
    valid_nonhandCount_passed += valid_nonhandCount;

    sub_tests_passed +=
      valid_handCount +
      valid_actions +
      valid_discard +
      valid_nonhandCount;

  }

  printf("Test Runs: %d\n", TEST_RUNS);
  printf("Total Sub-tests: %d\n", sub_tests_total);
  printf("Sub-tests passed: %d\n", sub_tests_passed);
  printf("\thandCount tests passed: %d\n", valid_handCount_passed);
  printf("\tactions tests passed: %d\n", valid_actions_passed);
  printf("\tdiscard tests passed: %d\n", valid_discard_passed);
  printf("\tnonhandCount tests passed: %d\n", valid_nonhandCount_passed);
  printf("Sub-tests failed: %d\n", sub_tests_total - sub_tests_passed);

	return 0;
}