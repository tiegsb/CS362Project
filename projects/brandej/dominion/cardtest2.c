#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

int main() {

    printf("\nTesting Smithy Card function:\n");

    int randomSeed = 100;
    int players = 4;
    int kingCards[10] = {0, 1, 2, 10, 12, 18, 16, 22, 25, 26};
    int i, x, h;
    struct gameState state;
    int discardCount = 5;
    int maxHandCount = 5;
    int testCounter, curPlayer, prevHandCount, prevDiscardCount, handPos;
    memset(&state, 'z', sizeof(struct gameState));
    initializeGame(players, kingCards, randomSeed, &state);
    testCounter = 0;

    for (x = 0; x < players; ++x) {
        for (h = 0; h < maxHandCount; ++h) {
            curPlayer = x;
            state.whoseTurn = x;
            handPos = h;

            //setup testing state
            for (i = 0; i <= h; ++i) {
                state.hand[curPlayer][i] = curse; //set whole hand = to curse
                state.discard[curPlayer][i] = curse; //set whole discard = to curse
            }

            state.discardCount[curPlayer] = handPos;
            state.handCount[curPlayer] = handPos + 1;
            state.hand[curPlayer][handPos] = smithy;

            prevDiscardCount = state.discardCount[curPlayer];
            prevHandCount = state.handCount[curPlayer];

            playSmithy(&state, handPos);

            //test 3 cards added and 1 removed.
            //printf("3 cards added test:\n");
            if (prevHandCount + 2 == state.handCount[curPlayer]) {   //2 cards added
                printf("Test Passed\n");
            }
            else {
                printf("Test Failed\n");
                //printf("prevDiscard %d, curDiscard %d, prevHandCount %d, curHandCount %d\n", prevDiscardCount, state.discardCount[curPlayer], prevHandCount, state.handCount[curPlayer]);
                testCounter++;
            }

            //test discarded cards count incremented
            //printf("discardCount incremented test:\n");
            if (state.discardCount[curPlayer] == prevDiscardCount + 1) {
                printf("Test Passed\n");
            }
            else {
                printf("Test Failed\n");
                testCounter++;
            }

            //test discarded card is smithy
            //printf("discardCount smithy in discard test:\n");
            if (state.discard[curPlayer][curPlayer + 1] == smithy) {
                printf("Test Passed\n");
            }
            else {
                printf("Test Failed\n");
                testCounter++;
            }
        }
    }
    if (testCounter <= 0) {
        printf("All tests passed the Smithy Card\n");
    }
    else  {
        printf("%d tests failed on the Smithy Card\n\n", testCounter);
    }
    return 0;
}
