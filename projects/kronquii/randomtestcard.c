#include <stdio.h>
#include <time.h>
#include <assert.h>
#include <stdlib.h>
#include "dominion.h"


// Get a random card. Abuse the fact that enums are integers
enum CARD get_rand_card() {
    return rand() % (treasure_map + 1);
}


void test_village() {
    srand(time(0));

    struct gameState gs = {0};

    // For some random number of players less than MAX_PLAYERS
    int num_players = rand() % MAX_PLAYERS;
    gs.numPlayers = num_players;
    for (int i = 0; i < num_players; i++) {
        // put some random number of cards in their deck.
        int deck_cards = rand() % 12;
        gs.deckCount[i] = deck_cards;
        // Put  village in their hand.
        gs.handCount[i] = 1;
        gs.hand[i][0] = village;
        // Fill the player's deck
        for (int j = 1; j < deck_cards; j++) {
            gs.deck[i][j] = get_rand_card();
        }
    }

    // For each player assert that the villageEffect happens properly
    for (int i = 0; i < num_players; i++) {
        gs.numActions = rand() % 12;
        int orig_hand_count = gs.handCount[i];
        int orig_deck_count = gs.deckCount[i];
        int orig_num_actions = gs.numActions;
        villageEffect(0, i, &gs);

        printf("The new number of actions (%d) should be 2 more than the original number %d.\n", gs.numActions, orig_num_actions);
        assert(gs.numActions == orig_num_actions + 2);
        // If the deck is not empty
        if (orig_deck_count > 0) {
            printf("One card was drawn and one was discarded. The new hand conut (%d) is the same as the original (%d).\n", gs.handCount[i], orig_hand_count);
            // + 1 card -1 village.
            assert(gs.handCount[i] == orig_hand_count);
            printf("One card was drawn from the deck. The new deck count is %d while the old was %d.\n", gs.deckCount[i], orig_deck_count);
            // -1 card which was drawn
            assert(gs.deckCount[i] == orig_deck_count - 1);
        } else {
            // there is nothing to draw!
            printf("The deck was empty, so should the number of cards (%d) should be 0.\n", gs.deckCount[i]);
            assert(gs.deckCount[i] == 0);
            printf("Since the deck was empty the villager was player and the number of cards in the hand (%d) should be 0.\n", gs.handCount[i]);
            assert(gs.handCount[i] == 0);
        }
    }
}


int main() {
    test_village();
    return 0;
}
