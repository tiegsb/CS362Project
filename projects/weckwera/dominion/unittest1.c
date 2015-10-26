/* Filename: unittest1.c
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

    printf ("Testing gainCard().... \n");

    int i;
    int seed = 10;
    int numPlayer = 2;
    int maxBonus = 10;
    int p, r, handCount, bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel,
                    smithy, village, baron, great_hall};
    struct gameState pre, post;
    int maxHandCount = MAX_HAND;

    //srand (time(NULL)); //set random seed

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

// Test gainCard()
// -each player can gain a card
//      -to hand
//      -to draw deck
//      -to discard deck
// -gaining a card doesn't affect the game state otherwise
//      - that player deck size should +1, supply of that card should -1
// -test at max_hand +/- 1 card
// -test at max_deck +/- 1 card
//
// -try to add supply count 0


// For loop iterating through players
    for (p = 0; p < numPlayer; p++) {
    //reset and reinitialize game state
        // Taken from provided testUpdateCoins.c, class website
        memset(&pre, 23, sizeof(struct gameState));
        r = initializeGame(numPlayer, k, seed, &pre);
        assert (r == 0);
        pre.handCount[p] = 5; //hand count set at arbitrary number for player tests
        int supplyPos = adventurer; //gain adventurer

        printf ("Testing player %d: \n", p);
        post = pre;

        printf ("Card to deck: ");
        r = gainCard(supplyPos, &post, 1, p);
        //check for success of gainCard
        assert (r == 0);
        //check that one card was gained in hand
        assert (pre.deckCount[p] == (post.deckCount[p] - 1));
        printf ("Player %d card to deck test passed\n", p);
        //printf ("Test failed\n");
        memcpy (&pre, &post, sizeof(struct gameState)); //reset post to pre

        printf ("Card to hand: ");
        r = gainCard(supplyPos, &post, 2, p);
        assert (r == 0);
        //check that one card was gained in hand
        assert (pre.handCount[p] == (post.handCount[p] - 1));
        printf ("Test passed\n");
        //printf ("Test failed\n");
        memcpy (&pre, &post, sizeof(struct gameState));

        printf ("Card to discard: ");
        r = gainCard(supplyPos, &post, 3, p);
        assert (r == 0);
        assert (pre.discardCount[p] == (post.discardCount[p] - 1));
        printf ("Test passed\n");
        //printf ("Test failed\n");
    }
    return 0;
}


