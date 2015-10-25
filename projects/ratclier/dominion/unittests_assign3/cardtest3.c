#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "unittest_helpers.h"


// Test the treasure map card
//
// NOTE: YOU ADDED A BUG: changed the code that trashes both treasure
// cards to no longer trash them (trashFlag changed from 1 to -1).
//
// From the Dominion Card Game Wiki (dominioncg.wikia.com):
//
// Trash this and another copy of treasure map from your hand. If you do
// trash two treasure maps, gain 4 gold cards, putting them on top of your
// deck.
//
// If you play this and you do not have another treasure map card in your
// hand, you gain nothing. Two cards are required to get gold.
//
// If there aren't enough gold cards left, you gain what you can.
//
int testTreasureMapCard(struct gameState *state)
{
    struct gameState *origState;  // copy of game state

    // Make a copy of the original game state
    //
    origState = copyState(state);

    printf("Here is where the treasure map card will be tested.\n");
    
    // Report what, if anything, changed in the game state
    //
    whatChanged(origState, state);
    printf("\n");

    return 0;
}


int main(int argc, char *argv[])
{
    int numPlayers = 2;
    int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, treasure_map, cutpurse, sea_hag, tribute, smithy};
    int randomSeed = 100;
    struct gameState *state;

    // New game
    //
    state = newGame();
    initializeGame(numPlayers, kingdomCards, randomSeed, state);

    printf("\n");

    // Discard a trashed card
    //
    printf(">>> TESTING: treasure map card...\n");
    testTreasureMapCard(state);

    return 0;
}


