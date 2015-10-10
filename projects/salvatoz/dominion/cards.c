#include "cards.h"
#include <stdlib.h>

static const int NUM_CARDS = treasure_map + 1;

static inline int lastDrawn(struct gameState *state, int currentPlayer) {
  return state->hand[currentPlayer][state->handCount[currentPlayer] - 1];
}

static inline int isTreasure(int card) {
  return card == copper || card == silver || card == gold;
}

/** adventurerHandler
 * Card effect: Reveal cards from your deck until you reveal 2 treasure cards.
 * Put those Treasure cards in your hand and discard the other revealed cards.
 *
 * Additional rules: If you have to shuffle in the middle, shuffle. Don't
 * shuffle in the revealed cards as these cards do not go into the Discard pile
 * until you have finished revealing cards. If you run out of cards while
 * shuffling and still have only one Treasure, you get just that one Treasure.
 */
static int adventurerHandler(int choice1, int choice2, int choice3, 
                             struct gameState *state, int handPos, int *bonus) {
  int z = 0;
  int temphand[MAX_HAND];
  int drawntreasure = 0;
  int cardDrawn;
  int currentPlayer = whoseTurn(state);

  while (drawntreasure < 2) {
    // if the deck is empty we need to shuffle discard and add to deck
    if (state->deckCount[currentPlayer] < 1) {
      shuffle(currentPlayer, state);
    }
    drawCard(currentPlayer, state);
    // top card of hand is most recently drawn card.
    cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer] - 1];
    if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
      drawntreasure++;
    else {
      temphand[z] = cardDrawn;
      // this should just remove the top card (the most recently drawn one).
      state->handCount[currentPlayer]--;
      z++;
    }
  }
  while (z - 1 >= 0) {
    state->discard[currentPlayer][state->discardCount[currentPlayer]++] =
        temphand[z - 1]; // discard all cards in play that have been drawn
    z = z - 1;
  }
  return 0;
}

static int smithyHandler(int choice1, int choice2, int choice3,
                         struct gameState *state, int handPos, int *bonus) {
  //+3 Cards
  for (i = 0; i < 3; i++) {
    drawCard(currentPlayer, state);
  }

  // discard card from hand
  discardCard(handPos, currentPlayer, state, 0);
  return 0;
}

struct cardData *initializeCardData() {
  struct cardData *data;

  // initialize an array of cardData structs with 0 so every value is NULL
  data = (struct cardData *) calloc(NUM_CARDS, sizeof(struct cardData));

  // initialize array values
  data[adventurer] = {.cost = 6, .effectHandler = adventurerHandler};
  data[smithy] = {.cost = 4, .effectHandler = smithyHandler};

  // TODO: three other cards

  return data;
}