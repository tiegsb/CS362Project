#ifndef _unittestHelper_h
#define _unittestHelper_h

#include "dominion.h"

struct aChangeReturnVals
{
	int stateChange;
	int indexI;
	int indexJ;
};

enum stateChange
{
  E_numPlayers= 0,
  E_supplyCount,
  E_embargoTokens,
  E_outpostPlayed,
  E_outpostTurn,
  E_whoseTurn,
  E_phase,
  E_numActions,
  E_coins,
  E_numBuys,
  E_hand,
  E_handCount,
  E_deck,
  E_deckCount,
  E_discard,
  E_discardCount,
  E_playedCards,
  E_playedCardCount
};

//returns a single difference between the two given states
struct aChangeReturnVals aChange(struct gameState *copyState, struct gameState *newState);

//using aChange(), loops through and prints changes between the two states
//unless caller specifies cases to ignore
//hand[], handCount[], deck[]... etc. are used to specify exact users who are
//to be ignored for that respective attribute.
int printBadDiffs(struct gameState *copyState, struct gameState *afterCopy, int test[], int hand[], int hLen, int handCount[], int hcLen, int discard[], int diLen, int discardCount[], int dicLen, int deck[], int deLen, int deckCount[], int decLen);

//Creates a semi-random game state that takes into account some game restrictions.
//Tries to keep its domain mostly within legal rules.
int createRandState(struct gameState *tempState);

#endif
