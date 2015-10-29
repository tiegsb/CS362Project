#include "notassert.h"

#include "dominion.h"


void testSmithyEffect() {
    struct gameState gs = {
        .numPlayers = 3,
        .supplyCount = {0},
        .embargoTokens = {0},
        .outpostPlayed = 0,
        .outpostTurn = 0,
        .whoseTurn = 0,
        .phase = 0,
        .numActions = 0,
        .coins = 0,
        .numBuys = 0,
        .hand = {{smithy}},
        .handCount = {1},
        .deckCount = {6, 6, 6},
        .deck = {{0, 1, 2, 3, 4, 5}, {0, 1, 2, 3, 4, 5}, {0, 1, 2, 3, 4, 5},},
        .discard = {{0}},
        .discardCount = {0},
        .playedCards = {0},
        .playedCardCount = 0,
    };

    int ret = smithyEffect(0, 0, &gs);
    // Assert the return value is 0.
    assert(ret == 0);
    // Assert that three cards were drawn and one was discarded
    assert(gs.handCount[0] == 3);
    // Assert the smithy was placed in the played cards pile
    assert(gs.playedCardCount == 1);
    // Check that the smithy is the first card in the played cards file.
    assert(gs.playedCards[0] == smithy);
}
