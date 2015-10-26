#include "notassert.h"
#include "dominion.h"

void test_updateCoins() {
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
        .handCount = {6, 6, 6},
        .hand = {{copper, copper, copper, copper, copper, curse},   // $5
                 {gold, silver, copper, gold, silver, curse},       // $11
                 {silver, silver, copper, curse, silver, copper},}, // $8
        .deck = {{0}},
        .deckCount = {0},
        .discard = {{0}},
        .discardCount = {0},
        .playedCards = {0},
        .playedCardCount = 0,
    };

    // Player 0 should have $5 in coins
    int ret = updateCoins(0, &gs, 0);
    assert(gs.coins == 5);
    assert(ret == 0);

    // Player 1 should have $11 in coins
    ret = updateCoins(1, &gs, 0);
    assert(gs.coins == 11);
    assert(ret == 0);

    // Player 2 should have $8 in coins
    ret = updateCoins(2, &gs, 0);
    assert(gs.coins == 8);
    assert(ret == 0);

    // Player 0 should have $5 in coins plus a bonus of $5
    ret = updateCoins(0, &gs, 5);
    assert(gs.coins == 10);
    assert(ret == 0);

    // Player 1 should have $11 in coins plus a bonus of $6
    ret = updateCoins(1, &gs, 6);
    assert(gs.coins == 17);
    assert(ret == 0);

    // Player 2 should have $8 in coins plus a bonus of -1
    ret = updateCoins(2, &gs, -1);
    assert(gs.coins == 7);
    assert(ret == 0);
}
