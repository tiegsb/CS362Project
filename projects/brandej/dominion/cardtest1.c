#include "dominion.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>



int main() {

    printf("\nTesting Adventurer Card:\n");

    int randomSeed = 100;
    int kingCards[10] = {0, 1, 2, 10, 12, 18, 16, 22, 25, 26};
    int i, x, p;
    int curPlayers = 4;
    struct gameState state;
    memset(&state, 'z', sizeof(struct gameState));
    initializeGame(curPlayers, kingCards, randomSeed, &state);
    //set current player
    state.whoseTurn = 0;
    int curPlayer = 0;
    int failCounter = 0;
    //hand == 0 when
        //p == 0, x == 0, 1
        //p == 1, x == 0
        //p == 2, x == 0, 1


    //controls combination of arrays that have cards at any time.
    for (p = 0; p < 3; ++p) {

        //controls which combination of cards get added.
        for (x = 0; x < 3; ++x) {


            //fill deck
            if (p == 0 || p ==1 ) {
                for (i = 0; i < 4; ++i) {
                    state.deck[curPlayer][i] = i + x; //fill deck with cards 0-3 + x
                }
                state.deckCount[curPlayer] = 4;
            }
            else {
                for (i = 0; i < 4; ++i) {
                    state.deck[curPlayer][i] = -1; //empty deck
                }
                state.deckCount[curPlayer] = 0;
            }

            //fill discard
            if (p ==1 || p == 2) {
                for (i = 0; i < 4; ++i) {
                    state.discard[curPlayer][i] = i + x; //fill discard with cards 0-3 + x
                }
                state.discardCount[curPlayer] = 4;
            }
            else {
                for (i = 0; i < 4; ++i) {
                    state.discard[curPlayer][i] = -1; //empty deck
                }
                state.discardCount[curPlayer] = 0;
            }

            //zero hand count
            state.handCount[curPlayer] = 3;
            for (i = 0; i < state.handCount[curPlayer]; ++i) {
                state.hand[curPlayer][i] = -1;
                //printf("card = %d\n", state.hand[curPlayer][i]);
            }
            state.handCount[curPlayer] = 0;

            playAdventurer(&state);


//            printf("x=%d, p=%d, count: %d \n", x, p, state.handCount[curPlayer]);
//                for (i = 0; i < state.handCount[curPlayer]; ++i) {
//                printf("card %d", state.hand[curPlayer][i]);
//            }

//            printf("\n");

            if (p == 0 || p == 2) {
                if (state.handCount[curPlayer] == x && x <= 2) {
                    printf("Test Passed\n");
                }
                else {
                    printf("Test Failed\n");
                    failCounter++;
                }
            }
            else if (p == 1) {
                if (x == 0 && state.handCount[curPlayer] == 0) {
                    printf("Test Passed\n");
                }
                else if (x > 0 && state.handCount[curPlayer] == 2) {
                    printf("Test Passed\n");
                }
                else {
                    printf("Test Failed\n");
                    failCounter++;
                }
            }
        }
    }
    if (failCounter <= 0) {
        printf("All tests passed the Adventure Card\n");
    }
    else  {
        printf("%d tests failed on the adventure card\n\n", failCounter);
    }

    return 0;
}


