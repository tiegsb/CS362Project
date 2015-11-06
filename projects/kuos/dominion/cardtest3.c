/******************************************************************************
cardtest3.c
Sharon Kuo (kuos@oregonstate.edu)
CS362-400: Assignment 3
Description: Unit testing for the village card, as implemented in
  villageCard(). Adds 1 card to the player hand and adds 2 actions to the
  player.
******************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>

void test_villageCard() {
  int seed = 1000;
  int numPlayer = 2;
  int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy,
    village, baron, great_hall};  // set kingdom cards
  struct gameState game;

  printf("************\nTESTING villageCard():\n************\n");

  memset(&game, 23, sizeof(struct gameState));    // clear the game state
  initializeGame(numPlayer, k, seed, &game);  // initialize new game

  // set a 2-player game with identical cards in hand, deck, and discard piles
  // have one village card in each player's hands
  game.handCount[0] = 3;
  game.discardCount[0] = 3;
  game.deckCount[0] = 5;

  game.hand[0][0] = village;
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

  game.hand[1][0] = village;
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
  game.numActions = 1;
  // play the village card
  int turn1 = cardEffect(village, 0, 0, 0, &game, 1, 0);
  if (turn1)
    printf("FAIL: cardEffect(village) returned non-zero value\n");
  else
    printf("PASS: cardEffect(village) returned zero value\n");

  // check if player 0 has 1 cards drawn, and village discarded
  if (game.handCount[0] != 3)
    printf("FAIL: player 0 did not draw 1 card; actual hand count is %d\n",
      game.handCount[0]);
  else
    printf("PASS: player 0 drew 1 card\n");

  // check for discarded card for player 0
  if (game.discardCount[0] != 4)
    printf("FAIL: player 0's discard pile count is not 4; actual discard pile "
      "count is %d\n", game.discardCount[0]);
  else
    printf("PASS: player 0 discarded a card\n");

  // check for cards drawn from deck for player 0
  if (game.deckCount[0] != 4)
    printf("FAIL: player 0's deck is not 4; actual deck count is %d\n",
      game.deckCount[0]);
  else
    printf("PASS: player 0 drew 1 card from their deck\n");

  // check for increased actions
  if (game.numActions != 3)
    printf("FAIL: player 0's actions were not incremented by 2; actual "
      "action count: %d\n", game.numActions);
  else
    printf("PASS: player 0's actions incremented by 1\n");

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
  test_villageCard();
  return 0;
}
