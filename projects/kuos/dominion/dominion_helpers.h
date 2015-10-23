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

int smithyCard(int player, struct gameState* state, int handPos);
int adventurerCard(int player, struct gameState* state, int* tempHand);
int councilRoomCard(int currentPlayer, struct gameState* state, int handPos);
int villageCard(int player, struct gameState* state, int handPos);
int remodelCard(int player, struct gameState* state, int handPos, int choice1,
  int choice2);

#endif
