#include "dominion.h"
#include <stdio.h>

const static char CARD_NAMES = {

};

/* 
if FAST_FAIL is nonzero, the test will quit after a single assertion failure 
*/
const static int FAST_FAIL = 1;

/** isTreasure
 * Checks whether the given card number c is a treasure card.
 * Preconditions: copper, silver, and gold are defined globally, preferably by
 *    the CARD enum from dominion.h.
 */
static inline int isTreasure(int c) {
  return c == copper || c == silver || c == gold;
}

static void assert(const char *msg, int test) {
    printf("TEST %s: %s\n", msg, test ? "PASS" : "FAIL");
    if (!test && FAST_FAIL) {
        printf("Assertion failed, quitting!\n");
        quit();
    }
}

int treasureInHand(const struct gameState *state, int playerNum) {
    int treasureCount = 0;
    for (int handIndex = 0; handIndex < state->handCount[playerNum]; 
         handIndex++) {
        if (isTreasure(state->hand[handIndex]))
            treasureCount++;
    }
    return treasureCount;
}

int treasureInDeck(const struct gameState *state, int playerNum) {
    int treasureCount = 0;
    for (int deckIndex = 0; deckIndex < state->deckCount[playerNum]; 
         deckIndex++) {
        if (isTreasure(state->deck[deckIndex]))
            treasureCount++;
    }
    return treasureCount;
}

int treasureInDiscard(const struct gameState *state, int playerNum) {
    int treasureCount = 0;
    for (int discardIndex = 0; discardIndex < state->discardCount[playerNum]; 
         discardIndex++) {
        if (isTreasure(state->discard[discardIndex]))
            treasureCount++;
    }
    return treasureCount;
}

/* 
returns the number of treasure the player is expected to gain after playing
adventurer -- at most 2, or else the number of treasure in deck and discard

return: 2, 1, or 0
*/
int treasureToGain(const struct gameState *state, int playerNum) {
    int treasureAvailable = treasureInDeck(state, playerNum) 
                            + treasureInDiscard(state, playerNum);
    return treasureAvailable >= 2 ? 2 : treasureAvailable;
}

static int totalCards(const struct gameState *state, int playerNum) {
    return state->handCount[playerNum] + state->deckCount[playerNum]
        + state->discardCount[playerNum];
}

/*
Check that the gameState struct doesn't have any incoherent values suggesting
a failure.
*/
static int integrityCheck(const struct gameState *referenceState,
                          const struct gameState *state) {
    assert("Integrity Check - numPlayers", 
           referenceState->numPlayers == state->numPlayers);
    assert("Integrity Check - whoseTurn",
           referenceState->whoseTurn == state->whoseTurn);
    assert("Integrity Check - player 0 counts",
           totalCards(referenceState, 0) == totalCards(state, 0));
    assert("Integrity Check - player 1 counts",
           totalCards(referenceState, 1) == totalCards(state, 1));
    if (state->numPlayers > 2)
        assert("Integrity Check - player 2 counts",
           totalCards(referenceState, 2) == totalCards(state, 2));
    if (state->numPlayers > 3)
        assert("Integrity Check - player 3 counts",
           totalCards(referenceState, 3) == totalCards(state, 3));
}

static int countPlayerCards(const struct gameState *state, int player) {

}

/*
Saves the gameState struct to a file for easy access.
*/
static void saveState(const char *filename, const struct gameState *state) {
    FILE *savefile = fopen(filename, "w");
    size_t 
}

static void loadState(const char *filename, const struct gameState *state) {

}

/* print a list of cards to a buffer */
static void snprintCards(char *buffer, int buffer_size, int numCards, 
                         enum CARD *cards) {
    int remaining_buffer = buffer_size;
    int cardIndex;
    int charsPrinted;
    for (cardIndex = 0; cardIndex < numCards; cardIndex++) {
        charsPrinted = snprintf(buffer, remaining_buffer, "%s", )
    }
}

/* print the state struct in human-readable format to a buffer */
static void snprintStateReadable(char *buffer, int buffer_size, 
                                 const char *state) {

}

/* print the human-readable state struct data to a file  */
static void saveStateReadable(const char *filename, 
                              const struct gameState *state) {
    // fprintf

}

static void quit()
{

}

/*
Usage: randomtestadventurer [options] [command] ...

Commands:
    run [statefile]
        Generates a random hand, deck, and discard, then tests adventurer to
        make sure it works correctly.
        statefile specifies a file to save the hand/deck/discard state to.
    replay [statefile]
        Loads the initial state from statefile and runs the test to check that
        adventurer works correctly.
        This can be used to re-check a previous test case.


*/
int main(int argc, char **argv) {

}