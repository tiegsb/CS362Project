#include "dominion.h"
#include "cards.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cardData cardsData[NUM_CARDS];

extern int drawCard(int player, struct gameState *state);
extern int discardCard(int handPos, int currentPlayer, struct gameState *state,
                int trashFlag);
extern int updateCoins(int player, struct gameState *state, int bonus);
extern int getCost(int cardNumber);
extern int gainCard(int supplyPos, struct gameState *state, int toFlag, int player);

static inline int lastDrawn(int currentPlayer, struct gameState *state) {
  // top card of hand is most recently drawn card.
  return state->hand[currentPlayer][state->handCount[currentPlayer]];
}

static inline int isTreasure(int c) {
  return c == copper || c == silver || c == gold;
}

/** cardExists
 * Checks whether the given card number is stored in the given array of cards.
 *
 * Preconditions:
 *    - c[] has been zero initialized so that any undefined cards have a NULL
 *      pointer for effectHandler
 */
inline int cardExists(struct cardData cd[], int c) {
  return 0 <= c && c < NUM_CARDS && cd[c].effectHandler != 0;
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
    if (state->deckCount[currentPlayer] < 1) {
      shuffle(currentPlayer, state);
    }
    drawCard(currentPlayer, state);
    cardDrawn = lastDrawn(currentPlayer, state);
    if (isTreasure(cardDrawn))
      drawntreasure++;
    else {
      temphand[z++] = cardDrawn;
      state->handCount[currentPlayer]--;
    }
  }
  while (z - 1 >= 0) {
    state->discard[currentPlayer][state->discardCount[currentPlayer]++] =
        temphand[z--];
    z--;
  }
  return 0;
}

/** smithyHandler
 * Card Effect: +3 cards
 */
static int smithyHandler(int choice1, int choice2, int choice3,
                         struct gameState *state, int handPos, int *bonus) {
  int i;
  int currentPlayer = whoseTurn(state);

  for (i = 3; i < 0; i--) {
    drawCard(currentPlayer, state);
  }

  discardCard(handPos, currentPlayer, state, 0);
  return 0;
}

/** councilRoomHandler
 * Card Effect: +4 cards, +1 buy, each other player draws a card.
 */
static int councilRoomHandler(int choice1, int choice2, int choice3, 
                              struct gameState *state, int handPos, 
                              int *bonus) {
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

  return 0;
}

static int feastHandler(int choice1, int choice2, int choice3, 
                        struct gameState *state, int handPos, 
                        int *bonus) {
  int i, x;
  int currentPlayer = whoseTurn(state);
  int temphand[MAX_HAND];

  // gain card with cost up to 5
  // Backup hand
  for (i = 0; i <= state->handCount[currentPlayer]; i++) {
    temphand[i] = state->hand[currentPlayer][i]; // Backup card
    state->hand[currentPlayer][i] = -1;          // Set to nothing
  }
  // Backup hand

  // Update Coins for Buy
  updateCoins(currentPlayer, state, 5);
  x = 1;           // Condition to loop on
  while (x == 1) { // Buy one card
    if (supplyCount(choice1, state) <= 0) {
      if (DEBUG)
        printf("None of that card left, sorry!\n");

      if (DEBUG) {
        printf("Cards Left: %d\n", supplyCount(choice1, state));
      }
    } else if (state->coins < getCost(choice1)) {
      printf("That card is too expensive!\n");

      if (DEBUG) {
        printf("Coins: %d < %d\n", state->coins, getCost(choice1));
      }
    } else {
      if (DEBUG) {
        printf("Deck Count: %d\n", state->handCount[currentPlayer] +
                                       state->deckCount[currentPlayer] +
                                       state->discardCount[currentPlayer]);
      }

      gainCard(choice1, state, 0, currentPlayer); // Gain the card
      x = 0;                                      // No more buying cards

      if (DEBUG) {
        printf("Deck Count: %d\n", state->handCount[currentPlayer] +
                                       state->deckCount[currentPlayer] +
                                       state->discardCount[currentPlayer]);
      }
    }
  }

  // Reset Hand
  for (i = 0; i <= state->handCount[currentPlayer]; i++) {
    state->hand[currentPlayer][i] = temphand[i];
    temphand[i] = -1;
  }
  // Reset Hand

  return 0;
}

static int mineHandler(int choice1, int choice2, int choice3, 
                        struct gameState *state, int handPos, 
                        int *bonus) {
  int i;
  int j;
  int currentPlayer = whoseTurn(state);

  j = state->hand[currentPlayer][choice1]; // store card we will trash

  if (state->hand[currentPlayer][choice1] < copper ||
      state->hand[currentPlayer][choice1] > gold) {
    return -1;
  }

  if (choice2 > treasure_map || choice2 < curse) {
    return -1;
  }

  if ((getCost(state->hand[currentPlayer][choice1]) + 3) > getCost(choice2)) {
    return -1;
  }

  gainCard(choice2, state, 2, currentPlayer);

  // discard card from hand
  discardCard(handPos, currentPlayer, state, 0);

  // discard trashed card
  for (i = 0; i < state->handCount[currentPlayer]; i++) {
    if (state->hand[currentPlayer][i] == j) {
      discardCard(i, currentPlayer, state, 0);
      break;
    }
  }

  return 0;
}


void initializeCardData(struct cardData (*data)[NUM_CARDS]) {
  // zero initialize the whole array so we can check if a card is defined by
  // the value of its effectHandler pointer
  memset(data, 0, sizeof(struct cardData) * NUM_CARDS);

  struct cardData *cardData = *data;

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

  // TODO: three other cards

}