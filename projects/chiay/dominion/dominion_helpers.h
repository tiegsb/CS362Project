#ifndef _DOMINION_HELPERS_H
#define _DOMINION_HELPERS_H

#include "dominion.h"

int drawCard(int player, struct gameState *state);
int updateCoins(int player, struct gameState *state, int bonus);
int discardCard(int handPos, int currentPlayer, struct gameState *state, 
		int trashFlag);
int gainCard(int supplyPos, struct gameState *state, int toFlag, int player);
int getCost(int cardNumber);
int cardEffect(int card, int choice1, int choice2, int choice3, 
	       struct gameState *state, int handPos, int *bonus);

//Refactor section
void cardEffect_smithy(int handPos, int currentPlayer, struct gameState *state);
void cardEffect_adventurer(int currentPlayer, struct gameState *state);
void cardEffect_council_room(int handPos, int currentPlayer, struct gameState *state);
int cardEffect_remodal(int handPos, int currentPlayer, struct gameState *state, int choice1, int choice2, int choice3);
void cardEffect_salvager(int handPos, int currentPlayer, struct gameState *state, int choice1);
//End Refactor
#endif
