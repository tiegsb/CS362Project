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
int testCouncilRoom(int player) {
  struct gameState g;

  int i, buyCount, councilPos = -1;
  int handSize[4], deckSize[4], discardSize[4];

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

  // g.hand[player][0] = council_room;

  // save count of cards in all player's hand, deck and discard pile
  for (i = 0; i < 4; ++i) {
    handSize[i] = g.handCount[i];
    deckSize[i] = g.deckCount[i];
    discardSize[i] = g.discardCount[i];
  }

  //save count of player's buys
  buyCount = g.numBuys;
  printf(" TESTING COUNCIL ROOM CARD\n");

#if VERBOSE
  for (i = 0; i < 4; ++i) {
    printf("Starting hand count for %d:\t%d\n", i, handSize[i]);
    printf("Starting deck count for %d:\t%d\n", i, deckSize[i]);
    printf("Starting discard count for %d:\t%d\n", i, discardSize[i]);
  }
  printf("Starting numBuys: %d\n", g.numBuys);

  printf("\n# Player hand BEFORE playing VILLAGE card:\n");
  for (i = 0; i < g.handCount[player]; ++i) {
    printf("Hand Card: %d : %d\n", i, g.hand[player][i]);
  }
#endif
 
  // store hand position of council room card 
  for (i = 0; i < handSize[player]; ++i) {
    if (g.hand[player][i] == council_room) {
      councilPos = i;
    }
  }

  // play card
  playCouncilRoomCard(&g, councilPos);

  // ensure card was actually in hand
  if ((councilPos == -1) && (g.handCount[player] > handSize[player])) {
    printf("ERROR: player %d able to play village card that's not in hand\n", player);
    errorCount++;
  }
 
#if VERBOSE
  printf("\n AFTER PLAYING VILLAGE CARD\n");
  for (i = 0; i < 4; ++i) {
    printf("Ending hand count for %d:\t%d\n", i, g.handCount[i]);
    printf("Ending deck count for %d:\t%d\n", i, g.deckCount[i]);
    printf("Ending discard count for %d:\t%d\n", i,  g.discardCount[i]);
  }
  printf("Ending count numBuys: %d\n", g.numBuys);
  printf("\n# Player hand AFTER playing VILLAGE card:\n");
  for (i = 0; i < g.handCount[player]; ++i) {
    printf("Hand Card: %d : %d\n", i, g.hand[player][i]);
  }
#endif

  // assert that player now has +4 card
  if (g.handCount[player] != handSize[player] + 4) {
    printf ("ERROR: Player given %d cards instead of 1.\n", g.handCount[player] - handSize[player]);
    errorCount++;
  }
#if VERBOSE
  else {
    printf("Player %d PASSED having +4 cards\n", player);
  }
#endif

  // assert that player now has +1 buys
  if (g.numBuys != buyCount + 1) {
    printf("ERROR: Player given %d buys instead of 1.\n", g.numBuys - buyCount);
    errorCount++;
  }
#if VERBOSE
  else {
    printf("Player %d PASSED having +1 buys\n", player);
  }
#endif

  // assert that village card was put on top of discard pile
if (g.discard[player][g.discardCount[player]] != council_room) {
    printf("ERROR: Council Room card not properly discarded.\n");
    errorCount++;
  }
#if VERBOSE
  else {
    printf("Player %d PASSED, properly discarding council card\n", player);
  }
#endif

  // assert that the other players received 1 card
  for (i = 0; i < 4; ++i) {
    if (i != player) {
      if (g.handCount[i] != handSize[i] + 1) {
        printf("ERROR: Player %d did not draw a card\n", i);
        errorCount++;
      } 
#if VERBOSE
      else {
        printf("Player %d PASSED properly drawing a card\n", i);
      }
#endif
    }
  }


  return errorCount;
}

int main() {
  srand(time(0));

  int errorCount = 0;
  errorCount += testCouncilRoom(0);
  errorCount += testCouncilRoom(1);

  printf("\nCOUNCIL ROOM CARD TEST COMPLETE with %d ERRORS\n\n", errorCount);

  return 0;
}
