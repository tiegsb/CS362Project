#include "notassert.h"

#include "dominion.h"

void testVillageEffect() {
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
        .hand = {{village}},
        .handCount = {1},
        .deckCount = {6, 6, 6},
        .deck = {{0, 1, 2, 3, 4, 5}, {0, 1, 2, 3, 4, 5}, {0, 1, 2, 3, 4, 5},},
        .discard = {{0}},
        .discardCount = {0},
        .playedCards = {0},
        .playedCardCount = 0,
    };

    int ret = villageEffect(1, 0, &gs);
    // Assert the return value is 0.
    assert(ret == 0);
    // Assert that one card was drawn
    assert(gs.handCount[1] == 1);
    // Assert that two actions were added
    assert(gs.numActions == 2);
    assert(gs.deckCount[1] == 5);
    assert(gs.playedCardCount == 1);
    assert(gs.playedCards[1] == village);
}
