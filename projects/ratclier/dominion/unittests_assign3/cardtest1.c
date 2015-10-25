#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "unittest_helpers.h"


// Test the smithy card
//
// NOTE: YOU ADDED A BUG: changed the trashFlag in the call to discardCard
// from 0 to 1 (sets the card as trashed).
//
// The Smithy card draws 3 cards from the player's deck and adds them to
// the player's hand. Once that is done, the Smithy card itself is
// discarded.
//
// Order of operations: cardEffect()    [switch(smithy)]
//                      drawCard()      [draw 3 cards]
//                      discardCard()   [discard a card from hand]
//
// TO TEST:
//
// - 3 cards are drawn from the deck and added to hand.
// - Discarded smithy card goes in the played pile.
//
int testSmithyCard(struct gameState *state)
{
    struct gameState *origState;  // copy of game state

    // Make a copy of the original game state
    //
    origState = copyState(state);

    printf("Here is where the smithy card will be tested.\n");
    
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
    printf(">>> TESTING: smithy card...\n");
    testSmithyCard(state);

    return 0;
}


/*
int smithyCard(struct gameState *state, int handPos)
{
  int currentPlayer = whoseTurn(state);
  int i; // loop counter

  //+3 Cards
  for (i = 0; i < 3; i++)
        {
          drawCard(currentPlayer, state);
        }
                        
  //discard card from hand
  discardCard(handPos, currentPlayer, state, 1);
  return 0;
}
*/
