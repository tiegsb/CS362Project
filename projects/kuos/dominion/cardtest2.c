/******************************************************************************
cardtest2.c
Sharon Kuo (kuos@oregonstate.edu)
CS362-400: Assignment 3
Description: Unit testing for the adventurer card, as implemented in
  adventurerCard(). Reveals adventure cards in the player's deck until 2 are
  shown. The revealed treasure cards are placed in the player's hand and the
  other revealed cards are discarded.
******************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>

void test_adventurerCard() {
  int seed = 1000;
  int numPlayer = 2;
  int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy,
    village, baron, great_hall};  // set kingdom cards
  struct gameState game;

  printf("************\nTESTING adventurerCard():\n************\n");

  memset(&game, 23, sizeof(struct gameState));    // clear the game state
  initializeGame(numPlayer, k, seed, &game);  // initialize new game

  // set a 2-player game with identical cards in hand, deck, and discard piles
  // have one adventurer card in each player's hands
  game.handCount[0] = 3;
  game.discardCount[0] = 3;
  game.deckCount[0] = 5;

  game.hand[0][0] = adventurer;
  game.hand[0][1] = copper;
  game.hand[0][2] = silver;
  game.discard[0][0] = copper;
  game.discard[0][1] = copper;
  game.discard[0][2] = silver;
  game.deck[0][0] = silver;
  game.deck[0][1] = silver;
  game.deck[0][2] = silver;
  game.deck[0][3] = silver;
  game.deck[0][4] = silver;

  game.handCount[1] = 3;
  game.discardCount[1] = 3;
  game.deckCount[1] = 5;

  game.hand[1][0] = adventurer;
  game.hand[1][1] = copper;
  game.hand[1][2] = silver;
  game.discard[1][0] = copper;
  game.discard[1][1] = copper;
  game.discard[1][2] = silver;
  game.deck[1][0] = silver;
  game.deck[1][1] = silver;
  game.deck[1][2] = silver;
  game.deck[1][3] = silver;
  game.deck[1][4] = silver;

  game.whoseTurn = 0; // set to player 0's turn
  // play the adventurer card
  int turn1 = cardEffect(adventurer, 0, 0, 0, &game, 1, 0);
  if (turn1)
    printf("FAIL: cardEffect(adventurer) returned non-zero value\n");
  else
    printf("PASS: cardEffect(adventurer) returned zero value\n");

  // check if player 0 has 2 cards drawn, and adventurer discarded
  if (game.handCount[0] != 4)
    printf("FAIL: player 0 did not draw 2 cards; actual hand count is %d\n",
      game.handCount[0]);
  else
    printf("PASS: player 0's hand gained 2 cards\n");

  // check for discarded card for player 0
  if (game.discardCount[0] != 4)
    printf("FAIL: player 0's discard pile count is not 4; actual discard pile "
      "count is %d\n", game.discardCount[0]);
  else
    printf("PASS: player 0 discarded a card\n");

  // check for cards drawn from deck for player 0
  if (game.deckCount[0] != 3)
    printf("FAIL: player 0's deck is not 3; actual deck count is %d\n",
      game.deckCount[0]);
  else
    printf("PASS: player 0 drew 2 cards from their deck\n");

  // check if player 1's cards are not affected
  if (game.handCount[1] != 3)
    printf("FAIL: player 1's hand count changed; actual count is %d\n",
      game.handCount[1]);
  else
    printf("PASS: player 1's hand count is unchanged\n");

  if (game.discardCount[1] != 3)
    printf("FAIL: player 1's discard count changed; actual count is %d\n",
      game.discardCount[1]);
  else
    printf("PASS: player 1's discard count is unchanged\n");

  if (game.deckCount[1] != 5)
    printf("FAIL: player 1's deck count changed; actual count is %d\n",
      game.deckCount[1]);
  else
    printf("PASS: player 1's deck count is unchanged\n");
}

int main() {
  test_adventurerCard();
  return 0;
}
