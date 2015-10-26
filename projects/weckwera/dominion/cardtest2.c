/* Filename: cardtest.c
 * Date Created: 2015-10-23
 * Purpose: perform card testing of _______ in dominion.c
 *
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
    printf("Testing adventurer...\n");
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int maxBonux = 10;
    int p, r, handCount, bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel,
                    smithy, village, baron, great_hall};
    struct gameState pre, post;
    int maxHandCount = 5;


/* Things to check for each unit test:
 * -did the function change what it was supposed to change?
 * -did anything else change?
 *      number of players
 *      supply count of cards
 *      whose turn
 *      phase
 *      number actions for a given player
 *      coins for a given player
 *      number of buys for a given player
 *      given player's hand
 *      hand count for player
 *      deck count for player
 *      discard pile for player
 *      discard count for a player
 *      played cards
 *      played card count
 *
 *      did any function return -1?
 *
 */
    memset(&pre, 23, sizeof(struct gameState));
    r = initializeGame(numPlayer, k, seed, &pre);
    assert (r == 0);
    post = pre;

    r = adventurerCard(&post);
    assert (r == 0);
    printf("Adventurer refactor returns 0\n");

    int curPlayer = whoseTurn(&post);

    for (i = 0; i < MAX_PLAYERS; i++) {
        if (i != curPlayer) {
            if (pre.handCount[i] == post.handCount[i]) {
                printf("Player %d no new hand card test: passed\n", i);
            }
            else
                printf("Player %d gained a card unfairly: failed\n", i);

            if (pre.deckCount[i] == post.deckCount[i]) {
                printf("Player %d no new deck card test: passed\n", i);
            }
            else if (pre.deckCount[i] != post.deckCount[i]){
                printf("Player %d gained a deck card unfairly: failed\n", i);
            }
        }
    }


    //run function to make changes to post

    printf("Card Test 2");
    return 0;
}
