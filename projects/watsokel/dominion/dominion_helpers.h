#ifndef _DOMINION_HELPERS_H
#define _DOMINION_HELPERS_H

#include "dominion.h"

int drawCard(int player, struct gameState *state);
int updateCoins(int player, struct gameState *state, int bonus);
int discardCard(int handPos, int currentPlayer, struct gameState *state, 
		int trashFlag);
int gainCard(int supplyPos, struct gameState *state, int toFlag, int player);
int getCost(int cardNumber);

int smithyEffect(int currentPlayer, struct gameState *state, int handPos); 
/* Adds three cards to hand. */

int adventurerEffect(struct gameState *state, int currentPlayer); 
/* Draws cards until two Treasure cards drawn. Adds the two Treasure cards to hand, 
and discards non-Treasure cards */

int adventurerEffect2(struct gameState *state, int currentPlayer); 
/* Draws cards until two Treasure cards drawn. Adds the two Treasure cards to hand, 
and discards non-Treasure cards (bug introduced) 
I needed to write a new adventurerEffect() method because my previous buggy version
creates an infinite loop */

int councilRoomEffect(int currentPlayer, struct gameState *state, int handPos); 
/* Draws 4 cards, addes 1 buy, other players draw 1 card */ 

int mineEffect(struct gameState *state, int currentPlayer, int choice1, int choice2, int handPos); 
/* Trash a Treasure card, places chosen card costing up to 3 coins more into hand. 
Returns -1 on error, returns 0 on success */

int salvagerEffect(int currentPlayer, struct gameState *state, int choice1, int handPos); /**/
/* Adds 1 buy, trashes a card, gains coins equal to cost of trashed card */

int cardEffect(int card, int choice1, int choice2, int choice3, 
	       struct gameState *state, int handPos, int *bonus);
         
#endif
