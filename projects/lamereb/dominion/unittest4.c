#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "rngs.h"

#define VERBOSE 0

// the purpose here is to test the gainCard() function
// NOTE: only tests addition of cards that are part of supply, so 
// only cards that are part of the actionCards[] array
int testGainCard(int cardToTest, int player) {
  struct gameState g;
  int i, supplyCount, deckSize, discardSize, handSize;
  int prevTestCardDeck = 0, prevTestCardDiscard = 0, prevTestCardHand = 0;
  int postTestCardDeck = 0, postTestCardDiscard = 0, postTestCardHand = 0;

  int TO_DISCARD = 0, TO_DECK = 1, TO_HAND = 2;

  int errorCount = 0;
  int seed = rand();

  int actionCards[10] = { adventurer, council_room, feast, gardens, mine, remodel,
    smithy, village, baron, minion };

  // initialize game state
  if (initializeGame(4, actionCards, seed, &g)) {
    printf("Error initializing gameState\n");
  }

  // save current size of piles: supply for cardToTest, deck, discard, and hand
  supplyCount = g.supplyCount[cardToTest];
  deckSize = g.deckCount[player];
  discardSize = g.discardCount[player];
  handSize = g.handCount[player];
  
  // save count of cardToTest in player's cards
  for (i = 0; i < g.deckCount[player]; ++i) {
    if (g.deck[player][i] == cardToTest) {
      prevTestCardDeck++;
    }
  }
  for (i = 0; i < g.discardCount[player]; ++i) {
    if (g.discard[player][i] == cardToTest) {
      prevTestCardDiscard++;
    }
  }
  for (i = 0; i < g.handCount[player]; ++i) {
    if (g.hand[player][i] == cardToTest) {
      prevTestCardHand++;
    }
  }

  // a) gain card for player, add to deck[]
  gainCard(cardToTest, &g, TO_DECK, player);
  // b) assert that g.deckCount increments & g.supplyCount[cardToTest] decrements
  if (g.deckCount[player] != (deckSize + 1)) {
    printf("ERROR: player deckCount didn't increment on gainCard() call\n");
    errorCount++;
  }
#if VERBOSE
  else {
    printf("\n#Adding card to player's deck via gainCard():\n");
    printf("--> %d : previous deck size\n", deckSize);
    printf("--. %d : current deck size\n\n", g.deckCount[player]);
  }
#endif

  if (g.supplyCount[cardToTest] != (supplyCount - 1)) {
    printf("ERROR: supplyCount[%d] didn't decrement on gainCard()\n", cardToTest);
    errorCount++;
  }
  else {
#if VERBOSE
    printf("#Decrementing supply pile for card %d\n", cardToTest);
    printf("--> %d : previous supply size\n", supplyCount);
    printf("--> %d : current supply size\n\n", g.supplyCount[cardToTest]);
#endif
    supplyCount--;
  }
  // c) also assert that test card was actually added
  for (i = 0; i < g.deckCount[player]; ++i) {
    if (g.deck[player][i] == cardToTest) {
      postTestCardDeck++;
    }
  }
#if VERBOSE
  printf("#Checking deck for addition of card %d\n", cardToTest);
  printf("--> %d : previous count of card\n", prevTestCardDeck);
  printf("--> %d : current count of card\n\n", postTestCardDeck);
#endif
  if (prevTestCardDeck != postTestCardDeck - 1) {
    printf("ERROR: card was not added to deck\n");
    errorCount++;
  }

  // do the same for discard pile .. 
  // a) gain card for player, add to discard[]
  gainCard(cardToTest, &g, TO_DISCARD, player);
  // b) assert that g.discardCount increments & g.supplyCount[cardToTest] decrements
  if (g.discardCount[player] != (discardSize + 1)) {
    printf("ERROR: player discardCount didn't increment on gainCard() call\n");
    errorCount++;
  }
#if VERBOSE
  else {
    printf("#Adding card to player's discard pile via gainCard():\n");
    printf("--> %d : previous discard size\n", discardSize);
    printf("--. %d : current discard size\n\n", g.discardCount[player]);
  }
#endif
 if (g.supplyCount[cardToTest] != (supplyCount - 1)) {
    printf("ERROR: supplyCount[%d] didn't decrement on gainCard()\n", cardToTest);
    errorCount++;
  }
  else {
#if VERBOSE
    printf("#Decrementing supply pile for card %d\n", cardToTest);
    printf("--> %d : previous supply size\n", supplyCount);
    printf("--> %d : current supply size\n\n", g.supplyCount[cardToTest]);
#endif
    supplyCount--;
  }
  // c) also assert that test card was actually added
  for (i = 0; i < g.discardCount[player]; ++i) {
    if (g.discard[player][i] == cardToTest) {
      postTestCardDiscard++;
    }
  }
#if VERBOSE
  printf("#Checking discard for addition of card %d\n", cardToTest);
  printf("--> %d : previous count of card\n", prevTestCardDiscard);
  printf("--> %d : current count of card\n\n", postTestCardDiscard);
#endif
  if (prevTestCardDiscard != postTestCardDiscard - 1) {
    printf("ERROR: card was not added to discard\n");
    errorCount++;
  }


  // and do the same for hand .. 
  // a) gain card for player, add to hand[]
  gainCard(cardToTest, &g, TO_HAND, player);
  // b) assert that g.handCount increments & g.supplyCount[cardToTest] decrements
  if (g.handCount[player] != (handSize + 1)) {
    printf("ERROR: player handCount didn't increment on gainCard() call\n");
    errorCount++;
  }
#if VERBOSE
  else {
    printf("#Adding card to player's hand via gainCard():\n");
    printf("--> %d : previous hand size\n", handSize);
    printf("--. %d : current hand size\n\n", g.handCount[player]);
  }
#endif
  if (g.supplyCount[cardToTest] != (supplyCount - 1)) {
    printf("ERROR: supplyCount[%d] didn't decrement on gainCard()\n", cardToTest);
    errorCount++;
  }
  else {
#if VERBOSE
    printf("#Decrementing supply pile for card %d\n", cardToTest);
    printf("--> %d : previous supply size\n", supplyCount);
    printf("--> %d : current supply size\n\n", g.supplyCount[cardToTest]);
#endif
    supplyCount--;
  }
  // c) also assert that test card was actually added
  for (i = 0; i < g.handCount[player]; ++i) {
    if (g.hand[player][i] == cardToTest) {
      postTestCardHand++;
    }
  }
#if VERBOSE
  printf("#Checking hand for addition of card %d\n", cardToTest);
  printf("--> %d : previous count of card\n", prevTestCardHand);
  printf("--> %d : current count of card\n\n", postTestCardHand);
#endif
  if (prevTestCardHand != postTestCardHand - 1) {
    printf("ERROR: card was not added to hand\n");
    errorCount++;
  }


  // empty supplyCount for cardToTest
  g.supplyCount[cardToTest] = 0;
  deckSize = g.deckCount[player];

  // and now try gaining a card from it
  gainCard(cardToTest, &g, TO_DECK, player);

  // assert that no new card was added to player's deck
  if (g.deckCount[player] > deckSize) {
    printf("ERROR: when gainCard() added card from empty supply\n");
    errorCount++;
  }
#if VERBOSE
  else {
    printf("#Adding card from empty supply:\n");
    printf("--> %d = previous deckSize\n", deckSize);
    printf("--> %d = new deckSize\n", g.deckCount[player]);
  }
#endif
  // and that supplyCount is still at 0;
  if (g.supplyCount[cardToTest] != 0) {
    printf("ERROR: gainCard() failed on supplyCount of 0\n");
    errorCount++;
  }
#if VERBOSE
  else {
    printf("--> %d = supply size\n", g.supplyCount[cardToTest]);
  }
#endif

  return errorCount;
}

int main() {
  srand(time(0));

  int errorCount = 0;
  errorCount = testGainCard(adventurer, 0);
  errorCount += testGainCard(adventurer, 1);
  errorCount += testGainCard(adventurer, 2);
  errorCount += testGainCard(adventurer, 3);
  errorCount += testGainCard(smithy, 0);
  errorCount += testGainCard(smithy, 1);
  errorCount += testGainCard(smithy, 2);
  errorCount += testGainCard(smithy, 3);
  errorCount += testGainCard(village, 0);
  errorCount += testGainCard(village, 1);
  errorCount += testGainCard(village, 2);
  errorCount += testGainCard(village, 3);

  if (errorCount) {
    printf("Error testing gainCard()\n");
  }
  printf("\nUNIT TEST 4 COMPLETE with %d ERRORS\n\n", errorCount);

  return 0;
}
