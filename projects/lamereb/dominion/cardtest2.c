#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "rngs.h"

#define VERBOSE 0

// the purpose here is to test the playSmithy() function
int testVillage(int player) {
  struct gameState g;

  int i, handSize, deckSize, discardSize, actionCount, villagePos = -1;

  int errorCount = 0;
  int seed = rand();

  int actionCards[10] = { adventurer, council_room, feast, gardens, mine, remodel,
    smithy, village, baron, minion };

  // initialize game state
  if (initializeGame(4, actionCards, seed, &g)) {
    printf("Error initializing gameState\n");
  }

  // set player as person with turn
  g.whoseTurn = player;

  // save count of cards in hand, deck and discard pile
  handSize = g.handCount[player];
  deckSize = g.deckCount[player];
  discardSize = g.discardCount[player];
  // save count of actions
  actionCount = g.numActions;
  printf(" TESTING VILLAGE CARD\n");

#if VERBOSE
  printf("Starting hand count: %d\n", handSize);
  printf("Starting deck count: %d\n", deckSize);
  printf("Starting discard count: %d\n", discardSize);
  printf("Starting action count: %d\n", actionCount);
  printf("\n# Hand BEFORE playing VILLAGE card:\n");
  for (i = 0; i < g.handCount[player]; ++i) {
    printf("Hand Card: %d : %d\n", i, g.hand[player][i]);
  }
#endif

  // store hand position of village card 
  for (i = 0; i < handSize; ++i) {
    if (g.hand[player][i] == village) {
      villagePos = i;
    }
  }

  // play village card
  playVillageCard(&g, villagePos);

  // ensure card was actually in hand
  if ((villagePos == -1) && (g.handCount[player] > handSize)) {
    printf("ERROR: player %d able to play village card that's not in hand\n", player);
    errorCount++;
  }
 
#if VERBOSE
  printf("\n AFTER PLAYING VILLAGE CARD\n");
  printf("Ending hand count: %d\n", g.handCount[player]);
  printf("Ending deck count: %d\n", g.deckCount[player]);
  printf("Ending discard count: %d\n", g.discardCount[player]);
  printf("Ending action count: %d\n", g.numActions);
  printf("\n# Hand AFTER playing VILLAGE card:\n");
  for (i = 0; i < g.handCount[player]; ++i) {
    printf("Hand Card: %d : %d\n", i, g.hand[player][i]);
  }
#endif

  // assert that player now has +1 card
  if (g.handCount[player] != handSize + 1) {
    printf ("ERROR: Player given %d cards instead of 1.\n", g.handCount[player] - handSize);
    errorCount++;
  }
  

  // assert that player now has +2 actions
  if (g.numActions != actionCount + 2) {
    printf("ERROR: Player given %d actions instead of 2.\n", g.numActions - actionCount);
    errorCount++;
  }

  // assert that village card was put on top of discard pile
  if (g.discard[player][g.discardCount[player]] != village) {
    printf("ERROR: Village card not properly discarded.\n");
    errorCount++;
  }


  return errorCount;
}

int main() {
  srand(time(0));

  int errorCount = 0;
  errorCount += testVillage(0);
  errorCount += testVillage(1);

  printf("\nVILLAGE CARD TEST COMPLETE with %d ERRORS\n\n", errorCount);

  return 0;
}
