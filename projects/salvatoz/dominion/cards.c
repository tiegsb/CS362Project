#include "dominion.h"
#include "cards.h"
#include <stdlib.h>
#include <string.h>

struct cardData cardsData[NUM_CARDS];

int drawCard(int player, struct gameState *state);
int discardCard(int handPos, int currentPlayer, struct gameState *state,
                int trashFlag);

static inline int lastDrawn(int currentPlayer, struct gameState *state) {
  // top card of hand is most recently drawn card.
  return state->hand[currentPlayer][state->handCount[currentPlayer] - 1];
}

static inline int isTreasure(int c) {
  return c == copper || c == silver || c == gold;
}

inline int cardExists(struct cardData *cd, int c) {
  return cd[c].effectHandler != 0;
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
    cardDrawn = lastDrawn(currentPlayer, state);
    if (isTreasure(cardDrawn))
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
  int i;
  int currentPlayer = whoseTurn(state);
  //+3 Cards
  for (i = 0; i < 3; i++) {
    drawCard(currentPlayer, state);
  }

  // discard card from hand
  discardCard(handPos, currentPlayer, state, 0);
  return 0;
}

void initializeCardData(struct cardData (*data)[NUM_CARDS]) {
  memset(data, 0, sizeof(struct cardData) * NUM_CARDS);

  struct cardData *cardData = *data;

  // initialize array values
  cardData[adventurer].cost = 6; 
  cardData[adventurer].effectHandler = adventurerHandler;
  cardData[smithy].cost = 4;
  cardData[smithy].effectHandler = smithyHandler;

  // TODO: three other cards

}