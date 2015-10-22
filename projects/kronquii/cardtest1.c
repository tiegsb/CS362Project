#include <assert.h>

#include "dominion.h"


void testSmithyEffectNoTrash() {
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
        .deckCount = {6, 6, 6},
        .deck = {{0, 1, 2, 3, 4, 5}, {0, 1, 2, 3, 4, 5}, {0, 1, 2, 3, 4, 5},},
        .discard = {{0}},
        .discardCount = {0},
        .playedCards = {0},
        .playedCardCount = 0,
    };

    // Save this value to assert it is updated.
    int num_played_cards = gs.playedCardCount;
    // Run the smithy's effect on the first player and discard their first
    // card. Do not trash it.
    int ret = smithyEffect(0, 0, gs, 0);
    // Assert the return value is 0.
    assert(ret == 0);
    // Assert that the first card was discarded
    assert(gs.deck[0][0] != 0);
    // Assert that three cards were drawn
    assert(gs.deckCount[0] == 8);
    // Check that the number of played cards was updated properly
    int last_played_card = gs.playedCardCount;
    assert(last_played_card == num_played_cards + 1);
    // Assert that the card is added into the played cards pile
    assert(gs.playedCards[0][last_played_card-1] == 0);
}

void testSmithyEffectWithTrash() {
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
        .deckCount = {6, 6, 6},
        .deck = {{0, 1, 2, 3, 4, 5}, {0, 1, 2, 3, 4, 5}, {0, 1, 2, 3, 4, 5},},
        .discard = {{0}},
        .discardCount = {0},
        .playedCards = {0},
        .playedCardCount = 0,
    };

    // Save this value to assert it is updated.
    int num_played_cards = gs.playedCardCount;
    // Run the smithy's effect on the first player and discard their first
    // card. Do not trash it.
    int ret = smithyEffect(0, 0, gs, 1);
    // Assert the return value is 0.
    assert(ret == 0);
    // Assert that the first card is no longer in the hand
    assert(gs.deck[0][0] != 0);
    // Assert that three cards were drawn
    assert(gs.deckCount[0] == 8);
    // Check that the number of played cards was not updated
    int last_played_card = gs.playedCardCount;
    assert(last_played_card == num_played_cards);
}
