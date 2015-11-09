#include "notassert.h"
#include <string.h>
#include "dominion.h"

void test_shuffle() {
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
        .hand = {{0}},
        .handCount = {0},
        .deckCount = {0, 6, 6},
        .deck = {{0, 1, 2, 3, 4, 5}, {0, 1, 2, 3, 4, 5}, {0, 1, 2, 3, 4, 5},},
        .discard = {{0}},
        .discardCount = {0},
        .playedCards = {0},
        .playedCardCount = 0,
    };
    // When the player has no cards, refuse to shuffle.
    assert(shuffle(0, &gs) == -1);

    gs.deckCount[0] = 6;

    int ret = shuffle(0, &gs);
    assert(ret == 0);
    // Check that the other hands are *not* shuffled.
    for (int i = 0; i < 6; i++) {
        assert(gs.deck[1][i] == i);
        assert(gs.deck[2][i] == i);
    }
    // The length of the hands was not changed by shuffling.
    assert(gs.deckCount[0] == 6);
    assert(gs.deckCount[1] == 6);
    assert(gs.deckCount[2] == 6);

    // WARNING: NON-DETERMINISTIC TEST! There is a one in 6! = 720 chance that
    // this test will fail.
    int original[] = {0, 1, 2, 3, 4, 5};
    assert(memcmp(original, gs.deck[0], 6*sizeof(int)) != 0);
}
