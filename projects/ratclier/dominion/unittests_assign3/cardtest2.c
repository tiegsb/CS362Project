#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "unittest_helpers.h"

// Test the adventurer card
//
// NOTE: YOU ADDED A BUG: changed cardDrawn assignment to not place drawn
// card at the end of the hand.
//
// The Adventurer card draws cards from the player's deck until two
// Treasure (coin) cards are drawn. If the drawn card is not a Treasure
// card, it is added to a temporary hand; if it is a Treasure card, it is
// added to the player's hand. At the end of the process, whatever is in
// the temporary hand (which contains no Treasure cards) is discarded.
// 
// If the player's deck is empty when the Adventurer card is played, the
// player's discard pile is shuffled and becomes the player's deck. (This
// seems pointless as the drawCard() function does this already.)
//
// From the Dominion Card Game Wiki (dominioncg.wikia.com):
//
// Reveal cards from your deck until you reveal 2 treasure cards. Put
// those treasure cards in your hand and discard the other revealed cards.
//
// If you have to shuffle in the middle, shuffle. Don't shuffle in the
// revealed cards as these cards do not go to the discard pile until you
// have finished revealing cards. If you run out of cards after shuffling
// and still only have one treasure, you get just that one treasure.
//
//
int testAdventurerCard(struct gameState *state)
{
    struct gameState *origState;  // copy of game state

    // Make a copy of the original game state
    //
    origState = copyState(state);

    printf("Here is where the adventurer card will be tested.\n");

    // TO TEST:
    //
    // - Deck is empty, need to shuffle discard and add to deck
    // - Deck is not empty
    //
    // - Treasure on top? What happens? (added to 2 treasure cards)
    // - Treasure not on top? What happens? (goes straight to discard?)
    
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
    printf(">>> TESTING: adventurer card...\n");
    testAdventurerCard(state);

    return 0;
}


/*
int adventurerCard(struct gameState *state)
{
  int currentPlayer = whoseTurn(state);
  int drawntreasure = 0;
  int cardDrawn;
  int temphand[MAX_HAND];
  int z = 0; // counter for temp hand

  while(drawntreasure<2){

    //if the deck is empty we need to shuffle discard and add to deck
          if (state->deckCount[currentPlayer] <1){
            shuffle(currentPlayer, state);
          }
          drawCard(currentPlayer, state);

    //top card of hand is most recently drawn card.
          cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]];

          if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
            drawntreasure++;
          else{
            temphand[z]=cardDrawn;
      //this should just remove the top card (the most recently drawn one).
            state->handCount[currentPlayer]--; 
            z++;
          }
  }
  while(z-1>=0){
    // discard all cards in play that have been drawn
          state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; 
          z=z-1;
  }
  return 0;
}
*/
