#ifndef _CARDS_H
#define _CARDS_H
/* cards.h
 * New centralized implementation of Dominion cards.
 * Requires dominion.h to be included first.
 */

/* cardEffectHandler
 * What is says on the tin. A pointer to a function that handles a card's 
 * effect.
 */
typedef int (*cardEffectHandler)(int, int, int, struct gameState *, int, int *);

static int adventurerHandler(int, int, int, struct gameState *, int, int *);

static int smithyHandler(int, int, int, struct gameState *, int, int *);

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
struct cardData *initializeCardData();
#endif