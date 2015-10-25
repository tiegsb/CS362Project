#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "unittest_helpers.h"


// Test the mine card
//
// From the Dominion Card Game Wiki (dominioncg.wikia.com):
//
// Trash a treaure card from your hand, gain a treasure card worth up to 3
// coins more than the trashed treasure card and add it to your hand.
//
// If you don't have a treasure card to trash, you can't do anything
// including gaining a new card.
//
// The gained card goes in your hand, so it can be played in the same
// turn.
//
// *** VERIFY THE FOLLOWING! COPIED FROM HANDOUT! ***
//
// Order of operations: cardEffect() [switch(mine)]
//                      store card we will trash 
//                      gainCard()
//                      discardCard() [discard card from hand]
//                      discardCard() [discard trashed card]
//
int testMineCard(struct gameState *state)
{
    struct gameState *origState;  // copy of game state

    // Make a copy of the original game state
    //
    origState = copyState(state);

    printf("Here is where the mine card will be tested.\n");
    
    // Report what, if anything, changed in the game state
    //
    whatChanged(origState, state);
    printf("\n");

    return 0;
}


int main(int argc, char *argv[])
{
    int numPlayers = 2;
    int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    int randomSeed = 100;
    struct gameState *state;

    // New game
    //
    state = newGame();
    initializeGame(numPlayers, kingdomCards, randomSeed, state);

    printf("\n");

    // Discard a trashed card
    //
    printf(">>> TESTING: mine card...\n");
    testMineCard(state);

    return 0;
}


/*
int mineCard(int choice1, int choice2, struct gameState *state, int handPos)
{
  int currentPlayer = whoseTurn(state);
  int i; // for loop counter
  int j; // holds card to trash

  j = state->hand[currentPlayer][choice1];  //store card we will trash

  if (state->hand[currentPlayer][choice1] < copper || state->hand[currentPlayer][choice1] > gold)
        {
          return -1;
        }
                
  if (choice2 > treasure_map || choice2 < curse)
        {
          return -1;
        }

  if ( (getCost(state->hand[currentPlayer][choice1]) + 3) > getCost(choice2) )
        {
          return -1;
        }

  gainCard(choice2, state, 2, currentPlayer);

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
}
*/
