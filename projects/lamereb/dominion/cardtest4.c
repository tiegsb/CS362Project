#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "rngs.h"

#define VERBOSE 0

// the purpose here is to test the playCouncilRoomCard() function
int testAdventure(int player) {
  struct gameState g;

  int i, advPos = -1;
  int handSize, deckSize, discardSize;
  int coinCountPrev = 0;
  int coinCountPost = 0;

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

  // store count of cards in player's hand, deck & discard piles
  handSize = g.handCount[player];
  deckSize = g.deckCount[player];
  discardSize = g.discardCount[player];

  // store count of coin cards in player's hand
  for (i = 0; i < g.handCount[player]; ++i) {
    if (g.hand[player][i] == copper || g.hand[player][i] == silver || g.hand[player][i] == gold) {
      coinCountPrev++;
    }
  }

  printf(" TESTING ADVENTURER CARD\n");

#if VERBOSE
    printf("Starting hand count:\t%d\n", handSize);
    printf("Starting deck count:\t%d\n", deckSize);
    printf("Starting discard count:\t%d\n", discardSize);

  printf("\n# Player hand BEFORE playing ADVENTURER card:\n");
  for (i = 0; i < g.handCount[player]; ++i) {
    printf("Hand Card: %d : %d\n", i, g.hand[player][i]);
  }
#endif

  // store hand position of adventurer card 
  for (i = 0; i < handSize; ++i) {
    if (g.hand[player][i] == adventurer) {
      advPos = i;
    }
  }

  // play card
  playAdventureCard(&g);

  // ensure card was actually in hand
  if ((advPos == -1) && (g.handCount[player] > handSize)) {
    printf("ERROR: player %d able to play ADVENTURER card that's not in hand\n", player);
    errorCount++;
  }

 #if VERBOSE
  printf("\n AFTER PLAYING ADVENTURER CARD\n");
  printf("Ending hand count:\t%d\n", g.handCount[player]);
  printf("Ending deck count:\t%d\n", g.deckCount[player]);
  printf("Ending discard count:\t%d\n",  g.discardCount[player]);

  printf("\n# Player hand AFTER playing ADVENTURER card:\n");
  for (i = 0; i < g.handCount[player]; ++i) {
    printf("Hand Card: %d : %d\n", i, g.hand[player][i]);
  }
#endif


  // assert that count of coin cards is 2 greater than previous count
  for (i = 0; i < g.handCount[player]; ++i) {
    if (g.hand[player][i] == copper || g.hand[player][i] == silver || g.hand[player][i] == gold) {
      coinCountPost++;
    }
  }
  if (coinCountPost != coinCountPrev + 2) {
    printf("ERROR: coin count is not +2, but +%d", coinCountPost - coinCountPrev);
    errorCount++;
  }
#if VERBOSE
  else {
    printf(" -- previous count of coin cards:\t%d\n", coinCountPrev);
    printf(" -- current count of coin cards:\t%d\n", coinCountPost);
  }
#endif

  // assert that adventurer card was put on top of discard pile
  if (g.discard[player][g.discardCount[player]] != adventurer) {
    printf("ERROR: Council Room card not properly discarded.\n");
    errorCount++;
  }
#if VERBOSE
  else {
    printf("Player %d PASSED, properly discarding council card\n", player);
  }
#endif

  return errorCount;
}

int main() {
  srand(time(0));

  int errorCount = 0;
  errorCount += testAdventure(0);

  printf("\nADVENTURE CARD TEST COMPLETE with %d ERRORS\n\n", errorCount);

  return 0;
}
