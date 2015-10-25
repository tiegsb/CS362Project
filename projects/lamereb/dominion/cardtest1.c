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
int testSmithy(int player) {
  struct gameState g;

  int i, handSize, discardSize, smithyPos = -1;

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

  // add 10 cards to player's deck so there's enough for testing
  for (i = 0; i < 10; ++i) {
    g.deck[player][g.deckCount[player]++] = gold;
  }
#if VERBOSE
  printf(" TESTING SMITHY CARD\n");
  printf("Starting deck count: %d\n", g.deckCount[player]);
  printf("Starting hand count: %d\n", g.handCount[player]);
  printf("Starting discard count: %d\n", g.discardCount[player]);
#endif

  // save count of cards in player's discard pile and hand
  discardSize = g.discardCount[player];
  handSize = g.handCount[player];
  for (i = 0; i < g.handCount[player]; ++i) {
#if VERBOSE
    printf("Hand Card %d : %d\n", i, g.hand[player][i]);
#endif
    if (g.hand[player][i] == smithy) {
      smithyPos = i;
    }
  }

  // play smithy card
  playSmithyCard(&g, smithyPos);

  // ensure card was actually in hand
  if ((smithyPos == -1) && (g.handCount[player] > handSize)) {
    printf("ERROR: player %d able to play smithy card that's not in hand\n", player);
    errorCount++;
  }

#if VERBOSE
  printf("# Hand AFTER playing SMITHY card:\n");
  for (i = 0; i < g.handCount[player]; ++i) {
    printf("Hand Card %d : %d\n", i, g.hand[player][i]);
  }
#endif

  // add smithy card to player hand
  g.hand[player][g.handCount[player]++] = smithy;
  handSize = g.handCount[player];
  smithyPos = handSize - 1;
  discardSize = g.discardCount[player];

#if VERBOSE
  printf("# Hand AFTER adding SMITHY card:\n");
  for (i = 0; i < g.handCount[player]; ++i) {
    printf("Hand Card %d : %d\n", i, g.hand[player][i]);
  }
#endif

  // play smithy card again
  playSmithyCard(&g, smithyPos);

  // assert that 3 new cards are added to player's discard pile
#if VERBOSE
  printf(" --> %d : hand size before playing smithy\n", handSize);
  printf(" --> %d : hand size after playing smithy\n", g.handCount[player]);
#endif
  if (g.handCount[player] != handSize + 3) {
    printf("ERROR: 3 cards were not added to player's hand\n");
    errorCount++;
  }
  // assert that smithy card is no longer in player's hand
  if (g.hand[player][smithyPos] == smithy) {
    printf("ERROR: smithy card still in player hand\n");
    errorCount++;
  }
#if VERBOSE
  printf("card at pos %d = %d\n", smithyPos, g.hand[player][smithyPos]);
  for (i = 0; i < g.handCount[player]; ++i) {
    printf("Hand Card %d : %d\n", i, g.hand[player][i]);
  }
#endif

  // assert that smithy card is now on top of discard pile
  if (g.discard[player][discardSize] != smithy) {
    printf("ERROR: smithy card never added to discard pile\n");
    errorCount++;
  }
#if VERBOSE
  printf("Discard Card 0 : %d\n", g.discard[player][0]);
  printf("Discard Card 1 : %d\n", g.discard[player][1]);
#endif



  return errorCount;
}

int main() {
  srand(time(0));

  int errorCount = 0;
  errorCount += testSmithy(0);

  printf("\nSMITHY CARD TEST COMPLETE with %d ERRORS\n\n", errorCount);

  return 0;
}
