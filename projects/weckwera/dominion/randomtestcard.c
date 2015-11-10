/* Filename: randomtestcard.c
 * Author: Andrew Weckwerth
 * Date Modified: 2015-11-08
 *
 * Description: Random test methods for feast card in dominion game.
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG0 0
//#define NOISY_TEST 1

int buildDeck(int players, struct gameState *g, int k[10]) {
    int i, j, x;
    //go through for each player
    for (i = 0; i < players; i++) {
        for (j = 0; j < (Random() * MAX_DECK); j++) {
            //generate a random number to get a card
            x = Random() * 16; //10 kingdom cards, 3 treasure, 3 victory
            if (x < 10) {
                g->deck[i][j] = k[x];
            }
            else if (x == 10) {
                g->deck[i][j] = copper;
            }
            else if (x == 11) {
                g->deck[i][j] = silver;
            }
            else if (x == 12) {
                g->deck[i][j] = gold;
            }
            else if (x == 13) {
                g->deck[i][j] = estate;
            }
            else if (x == 14) {
                g->deck[i][j] = duchy;
            }
            else if (x == 15) {
                g->deck[i][j] = province;
            }
            else if (x == 16) {
                g->deck[i][j] = curse;
            }
        }
        for (j = 0; j < (Random() * MAX_HAND); j++) {
            //generate a random number to get a card
            x = Random() * 16; //10 kingdom cards, 3 treasure, 3 victory
            if (x < 10) {
                g->hand[i][j] = k[x];
            }
            else if (x == 10) {
                g->hand[i][j] = copper;
            }
            else if (x == 11) {
                g->hand[i][j] = silver;
            }
            else if (x == 12) {
                g->hand[i][j] = gold;
            }
            else if (x == 13) {
                g->hand[i][j] = estate;
            }
            else if (x == 14) {
                g->hand[i][j] = duchy;
            }
            else if (x == 15) {
                g->hand[i][j] = province;
            }
            else if (x == 16) {
                g->hand[i][j] = curse;
            }
        }
    }
    return 0;
}

int checkFeastCard(int p, struct gameState *pre, struct gameState *post,
                            int k[10]) {
    int r, x, i, j[3], n;

    for (i = 0; i < 3; i++) {
        x = Random() * 16; //10 kingdom cards, 3 treasure, 3 victory
        if (x < 10) {
            j[i] = k[x];
        }
        else if (x == 10) {
        j[i] = copper;
        }
        else if (x == 11) {
        j[i] = silver;
        }
        else if (x == 12) {
        j[i] = gold;
        }
        else if (x == 13) {
        j[i] = estate;
        }
        else if (x == 14) {
        j[i] = duchy;
        }
        else if (x == 15) {
        j[i] = province;
        }
        else if (x == 16) {
        j[i] = curse;
        }
    }

    r = feastCard(j[1], j[2], j[3], post, p);
    if (r == 0) {
        if (post->handCount[p] != pre->handCount[p]) {
            printf("Test failed: number cards in hand changed\n");
            return 0;
        }
        if ((post->handCount[p] + post->deckCount[p] + post->discardCount[p]) !=
                (post->handCount[p] + post->deckCount[p] + post->discardCount[p])) {
            printf("Test failed: total card number changed\n");
            return 0;
        }
        for(n = 0; n < pre->handCount[p]; n++) {
            if (pre->hand[p][n] != post->hand[p][n]){
                printf("Test failed: card value changed\n");
                return 0;
            }
        }
        printf("Test passed!\n");
    }
    else
        printf("Test failed: function error\n");
    return 0;
}

int main() {

    long ss = 2, ps = 3;
    //initialize for random generator
    SelectStream(2);
    PutSeed(3);

    int i, j, x;
    int seed = Random();
    int numP = 2;

    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel,
                    smithy, village, baron, great_hall};

    struct gameState G, base, test;

    char *cardName[] = {"adventurer", "council_room", "feast", "gardens", "mine",
                    "remodel", "smithy", "village", "baron", "great_hall"};
    int numCardTypes = 10, minCards = 0, maxCards = 12;

    //initialize a game state and player cards
    initializeGame(numP, k, seed, &G);

    memcpy(&base, &G, sizeof(struct gameState));

    printf ("Testing adventurer card \n");
    printf("Random tests:\n");

    //random tests
    for (i = 0; i < 10; i++) {

        memcpy(&G, &base, sizeof(struct gameState));

        //build a random deck for each player
        buildDeck(numP, &G, k);

        int p;
        p = (Random() * 2); // get player's turn
        G.whoseTurn = p;
        G.deckCount[p] = (Random() * (MAX_DECK - 1)); //provide a random deck count
        G.discardCount[p] = (Random() * (MAX_DECK - 1)); // random discardCount
        G.handCount[p] = (Random() * (MAX_DECK - 1)); // random handCount
        //copy game state to test case
        memcpy(&test, &G, sizeof(struct gameState));
        checkFeastCard(p, &G, &test, k);
        memset(&test, '\0', sizeof(struct gameState));
        memset(&G, '\0', sizeof(struct gameState));
        //printf("Done with %d tests\n", i);
    }
    return 0;
}



