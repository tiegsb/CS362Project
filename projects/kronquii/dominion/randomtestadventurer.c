#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <assert.h>
#include "dominion.h"


// Get a random card. Abuse the fact that enums are integers
enum CARD get_rand_card() {
    return rand() % (treasure_map + 1);
}


void too_long(int signo) {
    puts("The function took too long! There may be an infinite loop.");
    assert(0);
}


void test_adventurer() {
    // Install a signal on an alarm to fail the test if it runs for more than
    // 5s. Such a case would be either an awful performance bug or an infinite
    // loop.
    signal(SIGALRM, too_long);
    srand(time(0));
    unsigned short player_treasure_count[MAX_PLAYERS] = {0};

    struct gameState gs = {0};

    // For some random number of players less than MAX_PLAYERS
    int num_players = rand() % MAX_PLAYERS;
    gs.numPlayers = num_players;
    for (int i = 0; i < num_players; i++) {
        // player should have some random number of card in their deck.
        int deck_cards = rand() % MAX_HAND;
        gs.deckCount[i] = deck_cards;
        // Put an adventurer in their hand.
        gs.handCount[i] = 0;
        gs.hand[i][0] = adventurer;
        // Give the player that many cards and count how many treasures we give
        // them, capped at 2.
        for (int j = 1; j < deck_cards; j++) {
            enum CARD new_card = get_rand_card();
            gs.deck[i][j] = new_card;
            if ((new_card == gold || new_card == silver || new_card == copper)
                    && player_treasure_count[i] < 2) {
                player_treasure_count[i]++;
            }
        }
    }
    // Arm alarm to trigger after 5s
    alarm(5);
    for (int i = 0; i < num_players; i++) {
        gs.numActions = rand() % 12;
        adventurerEffect(0, i, &gs);

        // The player drew the number of treasures we counted (capped at 2)
        printf("The number of cards in player %d's hand  (%d) should be the number of cards counted (%d).\n", i, gs.handCount[i], player_treasure_count[i]);
        assert(gs.handCount[i] == player_treasure_count[i]);
    }
    // disarm alarm.
    alarm(0);
}

int main() {
    test_adventurer();
    return 0;
}
