#include "dominion.h"
#include "cards.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* some semi-magic numbers for buffer sizes.
13 is the length of the string "treasure_map" plus one character for a delimiter
10000 seemed like a big enough number of the extra stuff I want in the state
file output */
#define LONGEST_CARD_NAME 13
#define CARD_BUFFER_SIZE LONGEST_CARD_NAME * MAX_HAND
#define PADDING 10000
#define STATE_BUFFER_SIZE PADDING + CARD_BUFFER_SIZE * MAX_PLAYERS

static void quit(void);

static const char *cardNames[] = {
    "curse",
    "estate",
    "duchy",
    "province",
    "copper",
    "silver",
    "gold",
    "adventurer",
    "council_room",
    "feast",
    "gardens",
    "mine",
    "remodel",
    "smithy",
    "village",
    "baron",
    "great_hall",
    "minion",
    "steward",
    "tribute",
    "ambassador",
    "cutpurse",
    "embargo",
    "outpost",
    "salvager",
    "sea_hag",
    "treasure_map"
};

/*
provides a human and machine-readable state struct text format. this is used to
store and load test start states. could also be used as the basis for a mutator
or null space test

For the sake of simplicity, not all state struct fields are stored. It is
assumed that many state struct fields will not affect the adventurer.
*/
static const char STATE_BUFFER_FMT[] = (
            "numPlayers %d\n"
            "whoseTurn %d\n"
            "hand0 %s\n"
            "handCount0 %d\n"
            "hand1 %s\n"
            "handCount1 %d\n"
            "hand2 %s\n"
            "handCount2 %d\n"
            "hand3 %s\n"
            "handCount3 %d\n"
            "deck0 %s\n"
            "deckCount0 %d\n"
            "deck1 %s\n"
            "deckCount1 %d\n"
            "deck2 %s\n"
            "deckCount2 %d\n"
            "deck3 %s\n"
            "deckCount3 %d\n"
            "discard0 %s\n"
            "discardCount0 %d\n"
            "discard1 %s\n"
            "discardCount1 %d\n"
            "discard2 %s\n"
            "discardCount2 %d\n"
            "discard3 %s\n"
            "discardCount3 %d\n");

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
        if (isTreasure(state->hand[playerNum][handIndex]))
            treasureCount++;
    }
    return treasureCount;
}

int treasureInDeck(const struct gameState *state, int playerNum) {
    int treasureCount = 0;
    for (int deckIndex = 0; deckIndex < state->deckCount[playerNum]; 
         deckIndex++) {
        if (isTreasure(state->deck[playerNum][deckIndex]))
            treasureCount++;
    }
    return treasureCount;
}

int treasureInDiscard(const struct gameState *state, int playerNum) {
    int treasureCount = 0;
    for (int discardIndex = 0; discardIndex < state->discardCount[playerNum]; 
         discardIndex++) {
        if (isTreasure(state->discard[playerNum][discardIndex]))
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

/* returns the total number of cards a given player has */
static int countPlayerCards(const struct gameState *state, int playerNum) {
    return state->handCount[playerNum] + state->deckCount[playerNum]
        + state->discardCount[playerNum];
}

/*
Check that the gameState struct doesn't have any incoherent values suggesting
a failure.
*/
static void integrityCheck(const struct gameState *referenceState,
                          const struct gameState *state) {
    assert("Integrity Check - numPlayers", 
           referenceState->numPlayers == state->numPlayers);
    assert("Integrity Check - whoseTurn",
           referenceState->whoseTurn == state->whoseTurn);
    assert("Integrity Check - player 0 counts",
           countPlayerCards(referenceState, 0) == countPlayerCards(state, 0));
    assert("Integrity Check - player 1 counts",
           countPlayerCards(referenceState, 1) == countPlayerCards(state, 1));
    if (state->numPlayers > 2)
        assert("Integrity Check - player 2 counts",
           countPlayerCards(referenceState, 2) == countPlayerCards(state, 2));
    if (state->numPlayers > 3)
        assert("Integrity Check - player 3 counts",
           countPlayerCards(referenceState, 3) == countPlayerCards(state, 3));
}

/* print a comma-delimited list of cards to a buffer 
unsafe function that can't handle buffer overflows... :'(
*/
static void saveCards(char *buffer, int numCards, int *cards) {
    int cardIndex;
    buffer[0] = '\0';
    for (cardIndex = 0; cardIndex < numCards; cardIndex++) {
        strcat(buffer, cardNames[cards[cardIndex]]);

        if (cardIndex < numCards - 1)
            strcat(buffer, ",");
    }
}

/* gets a card from a string card name
returns -1 on failure */
int stringToCardNum(const char *cardName) {
    for (int cardNum = 0; cardNum < NUM_CARDS; cardNum++)
        if (strcmp(cardName, cardNames[cardNum]) == 0)
            return cardNum;
    return -1;
}

/* converts a comma-delimited list of cards to an array of cards 

params:
    cardString: a comma-delimited string with card names
    cards: an array to populate with card numbers
    maxCards: the size of the cards array

returns -1 if it reaches the number of cards given by maxCards, -2 if it finds
an invalid card name, or else the number of cards parsed
*/
static int loadCards(char *cardString, int *cards, int maxCards) {
    int numCards = 0;
    char *cardName = strtok(cardString, ",");
    int card;
    while (cardName) {
        card = stringToCardNum(cardName);
        // make sure the card name is valid
        if (card < 0)
            return -2;
        cards[numCards] = card;
        numCards++;
        // make sure we don't overrun the max number of cards
        if (numCards >= maxCards)
            return -1;
        cardName = strtok(NULL, ",");
    }

    return numCards;
}

/* print the state struct in human and machine-readable format to a buffer 
*/
static void saveState(char buffer[STATE_BUFFER_SIZE], struct gameState *state) {
    char playerHand[MAX_PLAYERS][CARD_BUFFER_SIZE];
    char playerDeck[MAX_PLAYERS][CARD_BUFFER_SIZE];
    char playerDiscard[MAX_PLAYERS][CARD_BUFFER_SIZE];

    for (int playerNum = 0; playerNum < state->numPlayers; playerNum++) {
        saveCards(playerHand[playerNum], state->handCount[playerNum], 
                  state->hand[playerNum]);
        saveCards(playerDeck[playerNum], state->deckCount[playerNum], 
                  state->deck[playerNum]);
        saveCards(playerDiscard[playerNum], state->discardCount[playerNum], 
                  state->discard[playerNum]);
    }

    snprintf(buffer, STATE_BUFFER_SIZE, 
             STATE_BUFFER_FMT,
             state->numPlayers,
             state->whoseTurn,
             playerHand[0],
             state->handCount[0],
             playerHand[1],
             state->handCount[1],
             playerHand[2],
             state->handCount[2],
             playerHand[3],
             state->handCount[3],
             playerDeck[0],
             state->deckCount[0],
             playerDeck[1],
             state->deckCount[1],
             playerDeck[2],
             state->deckCount[2],
             playerDeck[3],
             state->deckCount[3],
             playerDiscard[0],
             state->discardCount[0],
             playerDiscard[1],
             state->discardCount[1],
             playerDiscard[2],
             state->discardCount[2],
             playerDiscard[3],
             state->discardCount[3]);
}

/* load the human and machine-readable state struct data from a buffer */
static void loadState(const char *buffer, 
                      struct gameState *state) {
    char playerHand[MAX_PLAYERS][CARD_BUFFER_SIZE];
    char playerDeck[MAX_PLAYERS][CARD_BUFFER_SIZE];
    char playerDiscard[MAX_PLAYERS][CARD_BUFFER_SIZE];
    int cardsLoaded;
    
    sscanf(buffer, 
           STATE_BUFFER_FMT,
           &state->numPlayers,
           &state->whoseTurn,
           playerHand[0],
           &state->handCount[0],
           playerHand[1],
           &state->handCount[1],
           playerHand[2],
           &state->handCount[2],
           playerHand[3],
           &state->handCount[3],
           playerDeck[0],
           &state->deckCount[0],
           playerDeck[1],
           &state->deckCount[1],
           playerDeck[2],
           &state->deckCount[2],
           playerDeck[3],
           &state->deckCount[3],
           playerDiscard[0],
           &state->discardCount[0],
           playerDiscard[1],
           &state->discardCount[1],
           playerDiscard[2],
           &state->discardCount[2],
           playerDiscard[3],
           &state->discardCount[3]);

    for (int playerNum = 0; playerNum < state->numPlayers; playerNum++) {
        cardsLoaded = loadCards(playerHand[playerNum], state->hand[playerNum], 
                                MAX_HAND);
        if (cardsLoaded < state->handCount[playerNum]) {
            printf("Failed loading player %d hand - expected %d cards but got " 
                   "%d\n", playerNum, state->handCount[playerNum], cardsLoaded);
            if (cardsLoaded == -1)
                printf("error: too many cards\n");
            if (cardsLoaded == -2)
                printf("error: invalid card name\n");
            exit(1);
        }

        cardsLoaded = loadCards(playerDeck[playerNum], state->deck[playerNum], 
                                MAX_DECK);
        if (cardsLoaded < state->deckCount[playerNum]) {
            printf("Failed loading player %d deck - expected %d cards but got " 
                   "%d\n", playerNum, state->deckCount[playerNum], cardsLoaded);
            if (cardsLoaded == -1)
                printf("error: too many cards\n");
            if (cardsLoaded == -2)
                printf("error: invalid card name\n");
            exit(1);
        }

        cardsLoaded = loadCards(playerDiscard[playerNum], 
                                state->discard[playerNum], MAX_DECK);
        if (cardsLoaded < state->discardCount[playerNum]) {
            printf("Failed loading player %d discard - expected %d cards but "
                   "got %d\n", playerNum, state->discardCount[playerNum], 
                   cardsLoaded);
            if (cardsLoaded == -1)
                printf("error: too many cards\n");
            if (cardsLoaded == -2)
                printf("error: invalid card name\n");
            exit(1);
        }
    }
}

static void quit()
{

}

static void genTestSetup(struct gameState *state) {}

static void runTest(struct gameState *state) {}

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
    struct gameState G;
    int k[10] = {adventurer, gardens,  embargo, village, minion,
               mine,       cutpurse, sea_hag, tribute, smithy};
    int status;

    status = initializeGame(2, k, atoi(argv[1]), &G);

  if (status == -1) {
    fprintf(stderr, "error 000: couldn't initialize game\n");
    return 1;
  }

  // print state

    return 0;
}