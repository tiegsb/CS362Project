/* cards.h
 * New centralized implementation of Dominion cards.
 * Requires dominion.h to be included first.
 */
#ifndef _CARDS_H
#define _CARDS_H

/** NUM_CARDS
 * Defines the number of dominion cards.
 */
#define NUM_CARDS treasure_map

/* cardEffectHandler
* What is says on the tin. A pointer to a function that handles a card's
* effect.
*/
typedef int (*cardEffectHandler)(int choice1, int choice2, int choice3,
                                 struct gameState* state, int handPos,
                                 int* bonus);

int adventurerHandler(int choice1, int choice2, int choice3,
                      struct gameState* state, int handPos, int* bonus);

int smithyHandler(int choice1, int choice2, int choice3,
                  struct gameState* state, int handPos, int* bonus);

/* struct cardData
 * Contains relevant data for cards.
 */
struct cardData {
  int cost;
  cardEffectHandler effectHandler;
};

/* initializeCardData
 * Generates data for Dominion cards.
 *
 * Preconditions: data must point to an initialized area of memory capable of
 *    storing the total number of cards. NUM_CARDS must be initialized.
 * Postconditions: The region of memory pointed to by data will be initialized
 *    with the data for each defined card.
 */
void initializeCardData(struct cardData (*data)[NUM_CARDS]);

/** cardExists
 * Checks whether the given card number c is in the range of valid card numbers.
 * Preconditions: NUM_CARDS is defined.
 * Assumptions: Card numbers are contiguously defined (i.e. there are no "holes"
 * in the range of card numbers).
 */
int cardExists(int c);

/** cardDefined
 * Checks whether the given card number is defined in the given array of
 * cardData structs.
 *
 * Preconditions:
 *    - c[] has been zero initialized so that any undefined cards have a NULL
 *      pointer for effectHandler
 */
int cardDefined(const struct cardData cd[], int c);

extern struct cardData cardsData[NUM_CARDS];
#endif