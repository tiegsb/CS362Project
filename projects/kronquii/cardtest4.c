#include "notassert.h"

#include "dominion.h"

void testCouncilRoomEffect() {
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
        .hand = {{council_room}},
        .handCount = {6, 6, 6},
        .deckCount = {6, 6, 6},
        .deck = {{0, 1, 2, 3, 4, 5}, {0, 1, 2, 3, 4, 5}, {0, 1, 2, 3, 4, 5},},
        .discard = {{0}},
        .discardCount = {0},
        .playedCards = {0},
        .playedCardCount = 0,
    };

 
    int ret = council_roomEffect(0, 0, &gs);
    assert(ret == 0);
    // Check that the first player drew 4 cards and discarded one.
    assert(gs.handCount[0] == 9);
    assert(gs.deckCount[0] == 2);
    assert(gs.playedCardCount == 1);
    assert(gs.playedCards[0] == council_room);

    // Check that the second and third players each drew one card.
    assert(gs.handCount[1] == 7);
    assert(gs.deckCount[1] == 5);
    assert(gs.handCount[2] == 7);
    assert(gs.deckCount[2] == 5);

    // Check that 1 buy was added.
    assert(gs.numBuys == 1);
}
