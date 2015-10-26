#include "notassert.h"

#include "dominion.h"

void testAdventurerEffect() {
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
        .hand = {{adventurer}},
        .handCount = {1},
        .deckCount = {4, 4, 4},
        .deck = {{silver, silver, curse, curse},
                 {curse, curse, curse, curse},
                 {curse, silver, curse, silver},},
        .discard = {{0}},
        .discardCount = {0},
        .playedCards = {0},
        .playedCardCount = 0,
    };

    // Test the first player's hand
    adventurerEffect(0, 0, &gs);
    // Assert the hand will have 2 cards in it because there are 2 silvers and
    // the adventurer is discarded.
    assert(gs.handCount[0] == 2);
    // Assert that the deck will have 2 cards in it because the coins are the
    // first two cards.
    assert(gs.deckCount[0] == 2);
    // Assert that there were no cards discarded because the first two drawn
    // were coins.
    assert(gs.discardCount[0] == 2);

    // Check that the adventurer was placed in the played pile.
    assert(gs.playedCardCount == 1);

    // Test the third player's hand
    adventurerEffect(2, 0, &gs);
    // Check that they have 2 cards in their hand
    assert(gs.handCount[2] == 2);
    // Check that they discarded the two other cards in their deck because the
    // second treasure is the last card in the deck.
    assert(gs.discardCount[2] == 2);
    // Check that there are no cards in the deck for the same reason as above.
    assert(gs.deckCount[2] == 0);

    // Test the second player's hand.
    adventurerEffect(1, 0, &gs);
    // Check that their hand is empty because there are no treasure cards in
    // the deck.
    assert(gs.handCount[1] == 0);
    // Check that their deck has no cards because all of their cards were
    // drawn.
    assert(gs.deckCount[1] == 0);
    // Check that they discarded their whole deck.
    assert(gs.discardCount[1] == 4);
}
