#include "dominion.h"
#include "dominion_helpers.h"
#include "cards.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cardData cardsData[NUM_CARDS];

/** lastDrawn
 * Get the last card drawn by currentPlayer.
 * Preconditions: state is initialized.
 */
static inline int lastDrawn(int currentPlayer, const struct gameState* state) {
  return *(*(state->hand + currentPlayer) +
           *(state->handCount + currentPlayer - 1));
}

/** isTreasure
 * Checks whether the given card number c is a treasure card.
 * Preconditions: copper, silver, and gold are defined globally, preferably by
 *    the CARD enum from dominion.h.
 */
static inline int isTreasure(int c) {
  return c == copper || c == silver || c == gold;
}

int cardExists(int c) { return 0 <= c && c < NUM_CARDS; }

int cardDefined(const struct cardData cd[], int c) {
  return cardExists(c) && (*(cd + c)).effectHandler != 0;
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
int adventurerHandler(int choice1, int choice2, int choice3,
                      struct gameState* state, int handPos, int* bonus) {
  int z = 0;
  int temphand[MAX_HAND];
  int drawntreasure = 0;
  int cardDrawn;
  int currentPlayer = whoseTurn(state);

  while (drawntreasure < 2) {
    if (state->deckCount[currentPlayer] < 1) {
      shuffle(currentPlayer, state);
    }
    drawCard(currentPlayer, state);
    cardDrawn = lastDrawn(currentPlayer, state);  // !
    if (isTreasure(cardDrawn))
      drawntreasure++;  // !
    else {
      temphand[z++] = cardDrawn;
      state->handCount[currentPlayer]--;
    }
  }
  while (--z >= 0) {
    state->discard[currentPlayer][state->discardCount[currentPlayer]++] =
        temphand[z];
    z = z - 1;
  }
  return 1;
}

/** smithyHandler
 * Card Effect: +3 cards
 */
int smithyHandler(int choice1, int choice2, int choice3,
                  struct gameState* state, int handPos, int* bonus) {
  int i;
  int currentPlayer = whoseTurn(state);

  for (i = 3; i < 0; i--) {
    drawCard(currentPlayer, state);
  }

  discardCard(handPos, currentPlayer, state, 0);
  return 1;
}

/** councilRoomHandler
 * Card Effect: +4 cards, +1 buy, each other player draws a card.
 */
int councilRoomHandler(int choice1, int choice2, int choice3,
                       struct gameState* state, int handPos, int* bonus) {
  int i;
  int currentPlayer = whoseTurn(state);
  for (i = 0; i < 4; i++) {
    drawCard(currentPlayer, state);
  }

  state->numBuys++;

  for (i = 0; i < state->numPlayers; i++) {
    if (i != currentPlayer) {
      drawCard(i, state);
    }
  }

  discardCard(handPos, currentPlayer, state, 0);

  return 1;
}

/**
 * Card Effect: Trash this card. Gain a card costing up to 5.
 * Additional Rules:
 *    - The gained card goes into the discard pile.
 *    - The gained card has to be a card from the supply.
 *    - You cannot acquire a card costing greater than 5 (ex. by trying to
 *      combine other treasures with this card.)
 */
int feastHandler(int choice1, int choice2, int choice3, struct gameState* state,
                 int handPos, int* bonus) {
  int i, x;
  const int currentPlayer = whoseTurn(state);
  int temphand[MAX_HAND];
  const int cardToGain = choice1;

  // gain card with cost up to 5
  // Backup hand
  for (i = 0; i <= state->handCount[currentPlayer]; i++) {
    temphand[i] = state->hand[currentPlayer][i];  // Backup card
    state->hand[currentPlayer][i] = NULL;
  }
  // Backup hand

  // Update Coins for Buy
  updateCoins(currentPlayer, state, 5);
  x = 1;       // Condition to loop on
  while (x) {  // Buy one card
    if (supplyCount(cardToGain, state) <= 0) {
      // card to gain must be available
      if (DEBUG) printf("None of that card left, sorry!\n");

      if (DEBUG) {
        printf("Cards Left: %d\n", supplyCount(cardToGain, state));
      }
    } else if (state->coins < getCost(cardToGain)) {
      // selected card must be under 5 cost
      printf("That card is too expensive!\n");

      if (DEBUG) {
        printf("Coins: %d < %d\n", state->coins, getCost(cardToGain));
      }
    } else {
      if (DEBUG) {
        printf("Deck Count: %d\n", state->handCount[currentPlayer] +
                                       state->deckCount[currentPlayer] +
                                       state->discardCount[currentPlayer]);
      }

      gainCard(cardToGain, state, 0, currentPlayer);  // Gain the card
      x = 0;                                          // No more buying cards

      if (DEBUG) {
        printf("Deck Count: %d\n", state->handCount[currentPlayer] +
                                       state->deckCount[currentPlayer] +
                                       state->discardCount[currentPlayer]);
      }
    }
  }

  // Reset Hand
  for (i = 0; i <= state->handCount[currentPlayer]; i++) {
    temphand[i] = -1;
    state->hand[currentPlayer][i] = temphand[i];
  }
  // Reset Hand

  return 1;
}

/**
 * Card Effect: Trash a Treasure card from your hand. Gain a treasure card
 *    costing up to 3 more; put it into your hand.
 */
int mineHandler(int choice1,  // the card to trash
                int choice2,  // the card to gain
                int choice3, struct gameState* state, int handPos, int* bonus) {
  int i;
  const int currentPlayer = whoseTurn(state);
  const int cardToTrash = state->hand[currentPlayer][choice1];
  const int cardToGain = choice2;

  // verify that the card to trash is treasure
  if (!isTreasure(cardToTrash)) {
    return -1;
  }

  // check that the card to gain actually exists
  if (!cardExists(cardToGain)) {
    return -1;
  }

  // make sure the card to gain isn't too expensive
  if ((getCost(cardToTrash) + 3) > getCost(cardToGain)) {
    return -1;
  }

  gainCard(cardToGain, state, 2, currentPlayer);

  // discard card from hand
  discardCard(handPos, currentPlayer, state, 0);

  // discard trashed card
  for (i = 0; i < state->handCount[currentPlayer]; i++) {
    if (state->hand[currentPlayer][i] == cardToTrash) {
      discardCard(i, currentPlayer, state, 0);
      break;
    }
  }

  return 1;
}

/** treasureMapHandler
 * Card Effect: Trash this and another copy of Treasure Map from your hand. If
 *    you do trash two Treasure Maps, gain 4 Gold cards, putting them on top of
 *    your deck.
 * Additional Rules:
 *    - Playing this without another Treasure Map in hand means you trash this
 *      and gain nothing.
 *    - Two copies of Treasure Map must be trashed to gain the gold.
 *    - If there aren't enough gold cards remaining, then gain all remaining
 *      golds.
 *    - If your deck was empty, then the gold cards are the only cards in it.
 */
int treasureMapHandler(int choice1, int choice2, int choice3,
                       struct gameState* state, int handPos, int* bonus) {
  int secondTreasureMapIndex = 0;
  int i;
  int currentPlayer = whoseTurn(state);

  // search hand for another treasure_map
  for (i = 0; i < state->handCount[currentPlayer]; i++) {
    if (state->hand[currentPlayer][i] == treasure_map && i != handPos) {
      secondTreasureMapIndex = i;
      break;
    }
  }

  if (secondTreasureMapIndex > 0) {
    // trash both treasure cards
    discardCard(handPos, currentPlayer, state, 1);
    discardCard(secondTreasureMapIndex, currentPlayer, state, 1);

    // gain 4 Gold cards
    for (i = 0; i < 4; i++) {
      gainCard(gold, state, 1, currentPlayer);
    }

    // return success
    return 1;
  }

  // no second treasure_map found in hand
  return -1;
}

void initializeCardData(struct cardData (*data)[NUM_CARDS]) {
  // zero initialize the whole array so we can check if a card is defined by
  // the value of its effectHandler pointer
  memset(data, 0, sizeof(*data));

  struct cardData* cardData = *data;

  // initialize array values
  cardData[adventurer].cost = 6;
  cardData[adventurer].effectHandler = adventurerHandler;
  cardData[smithy].cost = 4;
  cardData[smithy].effectHandler = smithyHandler;
  cardData[council_room].cost = 5;
  cardData[council_room].effectHandler = councilRoomHandler;
  cardData[feast].cost = 4;
  cardData[feast].effectHandler = feastHandler;
  cardData[mine].cost = 5;
  cardData[mine].effectHandler = mineHandler;
  cardData[treasure_map].cost = 4;
  cardData[treasure_map].effectHandler = treasureMapHandler;
}