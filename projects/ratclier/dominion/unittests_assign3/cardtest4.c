#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "unittest_helpers.h"


// Test the feast card
//
// NOTE: YOU ADDED A BUG: after gainCard(), removed the line that would
// set x = 0 to signal the end of card buying.
//
// From the Dominion Card Game Wiki (dominioncg.wikia.com):
//
// Trash this card, gain a card costing up to 5 coins.
//
// The gained card goes in your discard pile, not in your hand. 
//
// You can only gain cards from the supply pile.
//
int testFeastCard(struct gameState *state)
{
    struct gameState *origState;  // copy of game state

    // Make a copy of the original game state
    //
    origState = copyState(state);

    printf("Here is where the feast card will be tested.\n");
    
    // Report what, if anything, changed in the game state
    //
    whatChanged(origState, state);
    printf("\n");

    return 0;
}


int main(int argc, char *argv[])
{
    int numPlayers = 2;
    int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, cutpurse, sea_hag, tribute, smithy, feast};
    int randomSeed = 100;
    struct gameState *state;

    // New game
    //
    state = newGame();
    initializeGame(numPlayers, kingdomCards, randomSeed, state);

    printf("\n");

    // Discard a trashed card
    //
    printf(">>> TESTING: feast card...\n");
    testFeastCard(state);

    return 0;
}


/*
int feastCard(int choice1, struct gameState *state)
{
  int currentPlayer = whoseTurn(state);
  int temphand[MAX_HAND];
  int i; // for loop counter
  int x; // while loop flag

  //gain card with cost up to 5
  //Backup hand
  for (i = 0; i <= state->handCount[currentPlayer]; i++){
        temphand[i] = state->hand[currentPlayer][i];//Backup card
        state->hand[currentPlayer][i] = -1;//Set to nothing
  }
  //Backup hand

  //Update Coins for Buy
  updateCoins(currentPlayer, state, 5);
  x = 1;//Condition to loop on
  while( x == 1) {//Buy one card
          if (supplyCount(choice1, state) <= 0){
            if (DEBUG)
              printf("None of that card left, sorry!\n");
            if (DEBUG){
              printf("Cards Left: %d\n", supplyCount(choice1, state));
            }
          }
          else if (state->coins < getCost(choice1)){
          printf("That card is too expensive!\n");

          if (DEBUG){
            printf("Coins: %d < %d\n", state->coins, getCost(choice1));
          }
          }
          else{
            if (DEBUG){
              printf("Deck Count: %d\n", state->handCount[currentPlayer] + state->deckCount[currentPlayer] + state->discardCount[currentPlayer]);
            }

            gainCard(choice1, state, 0, currentPlayer);//Gain the card

            if (DEBUG){
              printf("Deck Count: %d\n", state->handCount[currentPlayer] + state->deckCount[currentPlayer] + state->discardCount[currentPlayer]);
            }
          }
  }     

  //Reset Hand
  for (i = 0; i <= state->handCount[currentPlayer]; i++){
          state->hand[currentPlayer][i] = temphand[i];
          temphand[i] = -1;
  }

  //Reset Hand
                        
  return 0;
}

*/
