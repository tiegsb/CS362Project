/* Filename: unittest.c
 * Date Created: 2015-10-23
 * Purpose: perform unit testing of _______ function in dominion.c
 *
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {

    printf("Testing buyCard...\n");

    int i;
    int seed = 1000;
    int numPlayer = 2;
    int maxBonus = 10;
    int p, r, handCount, bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel,
                    smithy, village, baron, great_hall};
    struct gameState pre, post;
    int maxHandCount = 5;

/* Functions in dominion.h:
 *  newGame
 *  kingdomCards
 *  initializeGame
 *  shuffle
 *  playCard
 *  buyCard
 *  numHandCards
 *  handCard
 *  supplyCount
 *  fullDeckCount
 *  whoseTurn
 *  endTurn
 *  isGameOver
 *  scoreFor
 *  getwinners
 *
 * In dominion_helpers.h:
 *  drawCard
 *  updateCoins
 *  discardCard
 *  gainCard
 *  getCost
 *  cardEffect
 *
 */

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

    int supplyPos = adventurer;

    //run function to make changes to post
    //try normal function first
    post.numBuys = 1;
    post.coins = 11;
    r = buyCard(supplyPos, &post);
    assert (r == 0);
    for (i = 0; i < MAX_PLAYERS; i++) {
        if (pre.handCount[i] == post.handCount[i]) {
            printf("Player %d no new hand card test: passed\n", i);
        }
        else
            printf("Player %d gained a card unfairly: failed\n", i);

        printf("whose turn: %d, i = %d \n", pre.whoseTurn, i);

        if (pre.deckCount[i] == post.deckCount[i] && i != pre.whoseTurn) {
            printf("Player %d no new deck card test: passed\n", i);
        }
        else if (pre.deckCount[i] != post.deckCount[i] && i != pre.whoseTurn){
            printf("Player %d gained a deck card unfairly: failed\n", i);
        }
    }
    printf("Test normal buyCard works\n");

    post = pre;
    post.numBuys = 0;
    r = buyCard(supplyPos, &post);
    assert (r == -1);
    printf("Test no buys left passed\n");

    post = pre;
    post.coins = 0;
    r = buyCard(supplyPos, &post);
    assert (r == -1);
    printf("Test no coins passed\n");

    post = pre;
    post.supplyCount[supplyPos] = 0;
    r = buyCard(supplyPos, &post);
    assert (r == -1);
    printf("Test none left passed\n");

    return 0;
}

