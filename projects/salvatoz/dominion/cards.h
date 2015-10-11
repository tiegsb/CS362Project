/* cards.h
 * New centralized implementation of Dominion cards.
 * Requires dominion.h to be included first.
 */
#ifndef _CARDS_H
#define _CARDS_H

/** NUM_CARDS
 * Defines the number of dominion cards.
 */
#define NUM_CARDS (treasure_map + 1)

/* cardEffectHandler
* What is says on the tin. A pointer to a function that handles a card's
* effect.
*/
typedef int (*cardEffectHandler)(int choice1,
                                 int choice2,
                                 int choice3,
                                 struct gameState* state,
                                 int handPos,
                                 int* bonus);

/* struct cardData
 * Contains relevant data for cards.
 */
struct cardData {
  int cost;
  cardEffectHandler effectHandler;
};

/* initializeCardData
 * Generates data for Dominion cards.
 */
void initializeCardData(struct cardData (*data)[NUM_CARDS]);

/** cardExists
 * Helper function to check whether the given card number is in range.
 */
inline int cardExists(int c);

/** cardDefined
 * Checks whether the given card number is defined in the given array of 
 * cardData structs.
 *
 * Preconditions:
 *    - c[] has been zero initialized so that any undefined cards have a NULL
 *      pointer for effectHandler
 */
inline int cardDefined(const struct cardData cd[], int c);

extern struct cardData cardsData[NUM_CARDS];
#endif