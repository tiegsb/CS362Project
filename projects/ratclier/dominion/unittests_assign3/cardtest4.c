#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "unittest_helpers.h"


// Test the remodel card
//
// From the Dominion Card Game Wiki (dominioncg.wikia.com):
//
// Trash a card from your hand, gain a card costing up to 2 coins more
// than the trashed card.
//
// You can not trash a remodel card that is in play. If you have another
// remodel card when you play a remodel card, you can trash it.
//
// If you have no card to trash, you can't do anything including gaining a
// new card.
//
// The gained card goes in your discard pile, not in your hand. 
//
// You can only gain cards from the supply pile.
//
int testRemodelCard(struct gameState *state)
{
    struct gameState *origState;  // copy of game state

    // Make a copy of the original game state
    //
    origState = copyState(state);

    printf("Here is where the remodel card will be tested.\n");
    
    // Report what, if anything, changed in the game state
    //
    whatChanged(origState, state);
    printf("\n");

    return 0;
}


int main(int argc, char *argv[])
{
    int numPlayers = 2;
    int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, cutpurse, sea_hag, tribute, smithy, remodel};
    int randomSeed = 100;
    struct gameState *state;

    // New game
    //
    state = newGame();
    initializeGame(numPlayers, kingdomCards, randomSeed, state);

    printf("\n");

    // Discard a trashed card
    //
    printf(">>> TESTING: remodel card...\n");
    testRemodelCard(state);

    return 0;
}



/*
    case remodel:
      j = state->hand[currentPlayer][choice1];  //store card we will trash

      if ( (getCost(state->hand[currentPlayer][choice1]) + 2) > getCost(choice2) )
        {
          return -1;
        }

      gainCard(choice2, state, 0, currentPlayer);

      //discard card from hand
      discardCard(handPos, currentPlayer, state, 0);

      //discard trashed card
      for (i = 0; i < state->handCount[currentPlayer]; i++)
        {
          if (state->hand[currentPlayer][i] == j)
            {
              discardCard(i, currentPlayer, state, 0);                  
              break;
            }
        }

      return 0;
      */
