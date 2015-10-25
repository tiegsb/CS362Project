#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "rngs.h"

#define VERBOSE 0

//the purpose here is to test the shuffle() function
int testShuffle(int player, int deckSize) {
  struct gameState g;
  int i;
  int addCard, previousDeckSize;

  int errorCount = 0;
  int seed = rand();

  int actionCards[10] = { adventurer, council_room, feast, gardens, mine, remodel,
    smithy, village, baron, minion };
  // these 2 arrays used to track card count of each card type in deck, pre & post shuffle
  int preShuffle[treasure_map + 1];
  int postShuffle[treasure_map + 1];
  // initialize arrays 
  for (i = 0; i <= treasure_map; ++i) {
    preShuffle[i] = 0;
    postShuffle[i] = 0;
  }
  // initialize game state
  if (initializeGame(4, actionCards, seed, &g)) {
    printf("Error initializing gameState\n");
  }
  // nullify cards currently in deck
  for (i = 0; i < g.deckCount[player]; ++i) {
    g.deck[player][i] = 0;
  }
  g.deckCount[player] = 0;
  // now populate player's deck with random cards
  for (i = 0; i < deckSize; ++i) {
    // put a card in player's deck
    addCard = rand() % treasure_map;
    g.deck[player][i] = addCard;
    // increase count
    g.deckCount[player]++;
    // and keep count of each card in deck
    preShuffle[addCard]++;
  }
  // add a card to the discard pile to ensure it is untouched by shuffle
  g.discard[player][0] = adventurer;
  g.discardCount[player]++;
  // save size of deck to check later that it doesn't change sizes
  previousDeckSize = g.deckCount[player];

#if VERBOSE
  printf("Discard pile before shuffle: ");
  for (i = 0; i < g.discardCount[player]; ++i) {
    printf("%d, ", g.discard[player][i]);
  }
  printf("\n");
  printf("Size of deck before shuffle = %d\n", previousDeckSize);
  printf("Deck before shuffle: ");
  for (i = 0; i < g.deckCount[player]; ++i) {
    printf("%d, ", g.deck[player][i]);
  }
  printf("\n");
#endif

  // now, shuffle deck
  shuffle(player, &g);

  // make sure deck size didn't change
  if (g.deckCount[player] != previousDeckSize) {
    printf("Deck-size mismatch post-shuffle. Pre = %d, Post = %d\n", 
        previousDeckSize, g.deckCount[player]);
    errorCount++;
  }

  // populate postShuffle array with count of cards in deck post-shuffle
  for (i = 0; i < g.deckCount[player]; ++i) {
    postShuffle[g.deck[player][i]]++;
  }

  // now, make sure preShuffle & postShuffle have same cards
  for (i = 0; i <= treasure_map; ++i) {
    if (preShuffle[i] != postShuffle[i]) {
     printf("Mismatch in shuffle of card %d\n", i);
     errorCount++;
    }
  }

#if VERBOSE
   printf("Discard pile after shuffle: ");
  for (i = 0; i < g.discardCount[player]; ++i) {
    printf("%d, ", g.discard[player][i]);
  }
  printf("\n"); 
  printf("Size of deck after shuffle = %d\n", g.deckCount[player]);
  printf("Deck after shuffle: ");
  for (i = 0; i < g.deckCount[player]; ++i) {
    printf("%d, ", g.deck[player][i]);
  }
  printf("\n");
#endif

  return errorCount;
}


int main() {
  srand(time(0));

  int errorCount = 0;
  errorCount += testShuffle(1, 5);
  errorCount += testShuffle(0, 5);
  errorCount += testShuffle(3, 20);
  errorCount += testShuffle(2, 11);

  if (errorCount) {
    printf("Error testing shuffle()\n");
  }

  printf("\nUNIT TEST 3 COMPLETE with %d ERRORS\n\n", errorCount);

  return 0;

}
