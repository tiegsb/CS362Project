//############################################################
// Filename: randomtestcard.c
// Random Test Objective: Tests the executeSmithyCard method
//                        with a randomized state
//############################################################

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1

int checkSmithyCard(int p, struct gameState *post);
void randomizeHandCount(struct gameState *state);
void randomizeHandCards(struct gameState *state);
void printIntArray(int arrayLength, int *arr, char *msg);
void randomizeGameStruct(struct gameState *state);
void randomizeDeck(struct gameState *state);
void randomizeDeckCards(struct gameState *state);
void randomizeDiscardPile(struct gameState *state);
void randomizeDiscardCards(struct gameState *state);
void randomizePlayedCards(struct gameState *state);
void SetCoinSupply(struct gameState *state);
int countTreasuresInHand(int player, struct gameState *state);
int checkTreasures(struct gameState *state);
void checkFailure(int result);

int main () {

  int n, player;
  struct gameState G;

  printf ("Random Tests for executeSmithyCard().\n");

  SelectStream(2);
  PutSeed(3);

  int numRandomTests = 2000;
  for (n = 0; n < numRandomTests; n++) {
    printf("------ Random Test %d ------\n", n + 1);
    randomizeGameStruct(&G);
    randomizeHandCount(&G);
    randomizeHandCards(&G);
    randomizeDeck(&G);
    player = floor(Random() * 2);
    randomizeDiscardPile(&G);
    randomizePlayedCards(&G);
    SetCoinSupply(&G);
    checkSmithyCard(player, &G);
  }

  return 0;
}

int checkSmithyCard(int player, struct gameState *state) {
  // Test Checklist:
  // - Check hand count for current player
  // - Check deck count for current player
  // - Check treasure count for current player
  // - Check that the cards added to the discard pile are not treasures
  // - Check that played cards count increased by 1
  // - Check hand count for other player
  // - Check deck count for other player
  // - Check discard pile for count for other player
  // - Check the coin supply did not change

  // Determine who the other player that is not playing is
  int otherPlayer = 1;
  if (player == 1)
  {
    otherPlayer = 0;
  }

  // Take a snapshot of the "before" game state
  int preHandCount = state->handCount[player];
  int preHandCountOtherPlayer = state->handCount[otherPlayer];
  int preDeckCount = state->deckCount[player];
  int preDeckCountOtherPlayer = state->deckCount[otherPlayer];
  int preDiscardCount = state->discardCount[player];
  int preDiscardCountOtherPlayer = state->discardCount[otherPlayer];
  int prePlayedCardsCount = state->playedCardCount;
  int preCopper = state->supplyCount[copper];
  int preSilver = state->supplyCount[silver];
  int preGold = state->supplyCount[gold];

  // Execute the method under test
  int handPos = 0;
  executeSmithyCard(player, state, handPos);

  // Save the snapshot of the "after" game state
  int postHandCount = state->handCount[player];
  int postHandCountOtherPlayer = state->handCount[otherPlayer];
  int postDeckCount = state->deckCount[player];
  int postDeckCountOtherPlayer = state->deckCount[otherPlayer];
  int postDiscardCount = state->discardCount[player];
  int postDiscardCountOtherPlayer = state->discardCount[otherPlayer];
  int postPlayedCardsCount = state->playedCardCount;
  int postCopper = state->supplyCount[copper];
  int postSilver = state->supplyCount[silver];
  int postGold = state->supplyCount[gold];

  // --------- Perform Asserts ---------
  int testPassed = 1;
  int overallTestsPassed = 1;

  // Tests cards were taken from the deck
  printf("Test - Cards were taken from the deck -- ");
  testPassed = postDeckCount < preDeckCount;
  checkFailure(testPassed);
  overallTestsPassed = overallTestsPassed ? (testPassed ? 1 : 0) : 0;
  assert (testPassed);

  // Tests hand count is increased by 3
  // This is a failing test!
  printf("Test - Expected hand count: %d, Actual amount: %d -- ", preHandCount + 3, postHandCount);
  testPassed = preHandCount + 3 == postHandCount;
  checkFailure(testPassed);
  overallTestsPassed = overallTestsPassed ? (testPassed ? 1 : 0) : 0;
  // assert (postHandCount == preHandCount + 3);

  // Tests that no coins were discarded
  int discardedCoins = recentDiscardDoesNotContainCoins(player, state, postDiscardCount - preDiscardCount);
  printf("Test - Expected amount of discarded treasures: 0, Actual amount: %d -- ", discardedCoins);
  testPassed = discardedCoins == 0;
  checkFailure(testPassed);
  overallTestsPassed = overallTestsPassed ? (testPassed ? 1 : 0) : 0;
  assert (testPassed);

  // Tests that the smithy card was put into the played card pile
  printf("Test - Expected played card count: %d, Actual amount: %d -- ", prePlayedCardsCount + 1, postPlayedCardsCount);
  testPassed = postPlayedCardsCount == prePlayedCardsCount + 1;
  checkFailure(testPassed);
  overallTestsPassed = overallTestsPassed ? (testPassed ? 1 : 0) : 0;
  assert (testPassed);

  // Tests that the hand of the other player did not change
  printf("Test - Expected hand count of other player: %d, Actual amount: %d -- ", preHandCountOtherPlayer, postHandCountOtherPlayer);
  testPassed = postHandCountOtherPlayer == preHandCountOtherPlayer;
  checkFailure(testPassed);
  overallTestsPassed = overallTestsPassed ? (testPassed ? 1 : 0) : 0;
  assert (testPassed);

  // Tests that the deck of the other player did not change
  printf("Test - Expected deck count of other player: %d, Actual amount: %d -- ", preHandCountOtherPlayer, postHandCountOtherPlayer);
  testPassed = postDeckCountOtherPlayer == preDeckCountOtherPlayer;
  checkFailure(testPassed);
  overallTestsPassed = overallTestsPassed ? (testPassed ? 1 : 0) : 0;
  assert (testPassed);

  // Tests that the discard pile of the other player did not change
  printf("Test - Expected discard count of other player: %d, Actual amount: %d -- ", preDiscardCountOtherPlayer, postDiscardCountOtherPlayer);
  testPassed = postDiscardCountOtherPlayer == preDiscardCountOtherPlayer;
  checkFailure(testPassed);
  overallTestsPassed = overallTestsPassed ? (testPassed ? 1 : 0) : 0;
  assert (testPassed);

  // Tests that the copper supply did not change
  printf("Test - Expected copper supply count: %d, Actual amount: %d -- ", preCopper, postCopper);
  testPassed = postCopper == preCopper;
  checkFailure(testPassed);
  overallTestsPassed = overallTestsPassed ? (testPassed ? 1 : 0) : 0;
  assert (testPassed);

  // Tests that the silver supply did not change
  printf("Test - Expected silver supply count: %d, Actual amount: %d -- ", preSilver, preSilver);
  testPassed = postSilver == preSilver;
  checkFailure(testPassed);
  overallTestsPassed = overallTestsPassed ? (testPassed ? 1 : 0) : 0;
  assert (testPassed);

  // Tests that the gold supply did not change
  printf("Test - Expected gold supply count: %d, Actual amount: %d -- ", preGold, postGold);
  testPassed = postGold == preGold;
  checkFailure(testPassed);
  overallTestsPassed = overallTestsPassed ? (testPassed ? 1 : 0) : 0;
  assert (testPassed);

  if (overallTestsPassed == 1)
  {
    printf("!---- All tests passed ----!\n");
  }
  else
  {
    printf("!---- Some or all tests failed ----!\n");
  }
  return 1;
}

void checkFailure(int result) {
  if (result == 0)
  {
    printf("Failed!\n");
  }
  else
  {
    printf("Passed!\n");
  }
}

int recentDiscardDoesNotContainCoins(int player, struct gameState *state, int postDiscardCount) {
  int i;
  int currentCard = 0;
  for (i = 0; i < postDiscardCount; ++i)
  {
    currentCard = state->discard[player][state->discardCount[player] - 1 - i];
    if ((currentCard == copper)
        || (currentCard == silver)
        || (currentCard == gold))
    {
      return 1;
    }
  }

  return 0;
}

int countTreasuresInHand(int player, struct gameState *state) {
  int i;
  int treasureCount = 0;

  for (i = 0; i < state->handCount[player]; i++)
  {
    if ((state->hand[player][i] == copper)
        || (state->hand[player][i] == silver)
        || (state->hand[player][i] == gold))
    {
      treasureCount++;
    }
  }

  return treasureCount;
}

void randomizeHandCount(struct gameState *state) {
  // Randomize the hand count
  int ranHandCountPlayer1 = floor(Random() * MAX_HAND);
  int ranHandCountPlayer2 = floor(Random() * MAX_HAND);
  state->handCount[0] = ranHandCountPlayer1;
  state->handCount[1] = ranHandCountPlayer2;

  // For debugging
  // printf("hand count of player 1: %d\n", state->handCount[0]);
  // printf("hand count of player 2: %d\n", state->handCount[1]);
}

void randomizeHandCards(struct gameState *state) {
  int i, j, cardToAdd;

  // Loop to iterate through 2 players
  for (j = 0; j < 2; j++)
  {
    // Loop to iterate through the player's cards
    for (i = 0; i < state->handCount[j]; i++)
    {
      cardToAdd = floor(Random() * 26); // Only add cards between 0 and 25, inclusive
      state->hand[j][i] = cardToAdd;
      // printf("Added: %d\n", cardToAdd);
    }
  }

  // For debugging
  // char msg[100] = "p2 card:";
  // printIntArray(state->handCount[1], state->hand[1], msg);
}

void randomizeDeck(struct gameState *state) {
  int ranDeckCountPlayer1, ranDeckCountPlayer2;
  int containsTreasures = 0; // 0 means does not contain treasures

  while (containsTreasures == 0) {
    // Randomize the deck count
    ranDeckCountPlayer1 = floor(Random() * MAX_DECK);
    ranDeckCountPlayer2 = floor(Random() * MAX_DECK);
    state->deckCount[0] = ranDeckCountPlayer1;
    state->deckCount[1] = ranDeckCountPlayer2;

    // Populate the deck with random cards
    randomizeDeckCards(state);

    // Treasure count need be to greater than 7
    containsTreasures = checkTreasures(state);
  }

  // For debugging
  // containsTreasures = checkTreasures(state);
  // if (containsTreasures == 1)
  // {
  //   printf("Contains treasures \n");
  // }
  // else
  // {
  //   printf("No treasures \n");
  //   printf("deck count of player 2: %d\n", state->deckCount[1]);
  //   printf("copper: %d\n", copper);
  //   printf("silver: %d\n", silver);
  //   printf("gold: %d\n", gold);
  //   char msg[100] = "p2 deck card:";
  //   printIntArray(state->deckCount[1], state->deck[1], msg);
  // }

  // printf("deck count of player 1: %d\n", state->deckCount[0]);
  // printf("deck count of player 2: %d\n", state->deckCount[1]);
}

void randomizeDeckCards(struct gameState *state) {
  int i, j, cardToAdd;

  // Loop to iterate through 2 players
  for (j = 0; j < 2; j++)
  {
    // Loop to iterate through the player's cards
    for (i = 0; i < state->deckCount[j]; i++)
    {
      cardToAdd = floor(Random() * 26); // Only add cards between 0 and 25, inclusive
      state->deck[j][i] = cardToAdd;
      // printf("Added: %d\n", cardToAdd);
    }
  }

  // For debugging
  // char msg[100] = "p1 deck card:";
  // printIntArray(state->deckCount[1], state->deck[1], msg);
}

void randomizeDiscardPile(struct gameState *state) {
  int ranDiscardCountPlayer1, ranDiscardCountPlayer2;

  // Randomize the deck count
  ranDiscardCountPlayer1 = floor(Random() * MAX_DECK);
  ranDiscardCountPlayer2 = floor(Random() * MAX_DECK);
  state->discardCount[0] = ranDiscardCountPlayer1;
  state->discardCount[1] = ranDiscardCountPlayer2;

  // Populate the deck with random cards
  randomizeDiscardCards(state);
}

void randomizeDiscardCards(struct gameState *state) {
  int i, j, cardToAdd;

  // Loop to iterate through 2 players
  for (j = 0; j < 2; j++)
  {
    // Loop to iterate through the player's cards
    for (i = 0; i < state->discardCount[j]; i++)
    {
      cardToAdd = floor(Random() * 26); // Only add cards between 0 and 25, inclusive
      state->discard[j][i] = cardToAdd;
      // printf("Added: %d\n", cardToAdd);
    }
  }

  // For debugging
  // char msg[100] = "p1 discard card:";
  // printIntArray(state->discardCount[0], state->discard[1], msg);
}

int checkTreasures(struct gameState *state) {
  int i, j, cardDrawn, numTreasures;

  // Loop to iterate through 2 players
  for (j = 0; j < 2; j++)
  {
    numTreasures = 0;
    // Loop to iterate through the player's cards
    for (i = 0; i < state->deckCount[j]; i++)
    {
      cardDrawn = state->deck[j][i];

      if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
      {
        numTreasures++;
      }
    }

    if (numTreasures < 7)
    {
      // Not enough treasures in player's deck
      return 0;
    }
  }

  // Enough treasures
  return 1;
}

void randomizeGameStruct(struct gameState *state) {
  int i;
  for (i = 0; i < sizeof(struct gameState); i++) {
    ((char*)state)[i] = floor(Random() * 256);
  }
}

void SetCoinSupply(struct gameState *state) {
  state->supplyCount[copper] = 100;
  state->supplyCount[silver] = 100;
  state->supplyCount[gold] = 100;
}

void randomizePlayedCards(struct gameState *state) {
  int i;
  int cardToAdd = 0;

  // Randomize the played cards count
  state->playedCardCount = floor(Random() * MAX_DECK);

  // Randomize the played cards
  for (i = 0; i < state->playedCardCount; i++)
  {
    cardToAdd = floor(Random() * 26); // Only add cards between 0 and 25, inclusive
    state->playedCards[i] = cardToAdd;
  }
}

void printIntArray(int arrayLength, int *arr, char *msg) {
  int i;
  for (i = 0; i < arrayLength; i++)
  {
    printf("%s %d\n", msg, arr[i]);
  }
}
