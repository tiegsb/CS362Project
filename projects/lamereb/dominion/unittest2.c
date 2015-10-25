#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "rngs.h"

#define VERBOSE 0

//the purpose here is to test the updateCoins() function
int testBuyCard(int card) {
  struct gameState g;
  int i;
  int numBuys, supplyCount;

  int cardCost = getCost(card);
  int seed = rand();

  int actionCards[10] = { adventurer, council_room, feast, gardens, mine, remodel,
    smithy, village, baron, minion };

  // initialize game state
  if (initializeGame(4, actionCards, seed, &g)) {
    printf("Error initializing gameState\n");
  }

  // save number of buys player has
  numBuys = g.numBuys;
  // save count of supplied card
  supplyCount = g.supplyCount[card];
  // set number of coins as less than cost of card
  g.coins = cardCost - 1;

  // try to buy card now. should cost more than player has
  buyCard(card, &g);

  // make sure that player still has a buy left
  if (numBuys > g.numBuys) {
    printf ("Error: unsuccessful buy decremented numBuys\n");
  }
  // printf(" cards in deck after buying card:\n");
  for (i = 0; i < g.handCount[0]; ++i) {
    if (g.hand[0][i] == card) {
      printf("Error: was able to buy card without enough coins\n");
    }
    // printf(" - hand cards: %d\n", g.hand[0][i]);
  }
  for (i = 0; i < g.deckCount[0]; ++i) {
    if (g.deck[0][i] == card) {
      printf("Error: was able to buy card without enough coins\n");
    }
    // printf (" - deck cards: %d\n", g.deck[0][i]);
  }
  for (i = 0; i < g.discardCount[0]; ++i) {
    if (g.deck[0][i] == card) {
      printf("Error: was able to buy card without enough coins\n");
    }
    // printf (" - discard cards: %d\n", g.discard[0][i]);
  }

  // now try to buy a card that is not in actionCards
  g.coins = cardCost * 2; // for buying twice
  buyCard(steward, &g);
  if (numBuys > g.numBuys) {
    printf ("Error: buy of nonexistent card decremented numBuys\n");
  }
  for (i = 0; i < g.handCount[0]; ++i) {
    if (g.hand[0][i] == steward) {
      printf("Error: was able to buy card without enough coins\n");
    }
  }
  for (i = 0; i < g.deckCount[0]; ++i) {
    if (g.deck[0][i] == steward) {
      printf("Error: was able to buy card without enough coins\n");
    }
  }
  for (i = 0; i < g.discardCount[0]; ++i) {
    if (g.deck[0][i] == steward) {
      printf("Error: was able to buy card without enough coins\n");
    }
  }

  // now successfully buy a card
  buyCard(card, &g);

  // assert that supply count for that card decremented by 1
  // printf ("Prev Sup Count %d New Sup Count %d\n", supplyCount, g.supplyCount[adventurer]);
  if (supplyCount != (g.supplyCount[card] + 1)) {
    printf("Error: supply card count did not decrement properly\n");
  }

  // and assert that that card is now in discard pile
  if (g.discard[0][0] != card) {
    printf("ERROR: bought card was not added to discard pile\n");
  }
  
  // deplete supply of card
  g.supplyCount[card] = 0;
  // increment buying power
  g.numBuys++;
  // and try to buy again
  buyCard(card, &g);
  for (i = 1; i < g.discardCount[0]; ++i) {
    if (g.discard[0][i] == card) {
      printf("ERROR: bought card that was not in supply\n");
    }
  } 
  // and make sure supply count didn't change'
  if (g.supplyCount[card] != 0) {
    printf("ERROR: supply count of card %d should be empty", card);
  }


  return 0;
}


int main() {
  srand(time(0));

  int errorCount = 0;

  if (testBuyCard(adventurer)) {
    printf("Error testing buyCard() with card #%d\n", adventurer);
    errorCount++;
  }
  if (testBuyCard(council_room)) {
    printf("Error testing buyCard() with card #%d\n", council_room);
    errorCount++;
  }
  if (testBuyCard(feast)) {
    printf("Error testing buyCard() with card #%d\n", feast);
    errorCount++;
  }
  if (testBuyCard(gardens)) {
    printf("Error testing buyCard() with card #%d\n", gardens);
    errorCount++;
  }
  if (testBuyCard(mine)) {
    printf("Error testing buyCard() with card #%d\n", mine);
    errorCount++;
  }
  if (testBuyCard(mine)) {
    printf("Error testing buyCard() with card #%d\n", remodel);
    errorCount++;
  }







  printf("\nUNIT TEST 2 COMPLETE with %d ERRORS\n\n", errorCount);

  return 0;

}
