#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

int main() {

    printf("\nTesting Village Card function:\n");

    int randomSeed = 100;
    int players = 4;
    int kingCards[10] = {0, 1, 2, 10, 12, 18, 16, 22, 25, 26};
    int i, x, h;
    struct gameState state;
    int maxHandCount = 5;
    int testCounter, curPlayer, prevHandCount, prevNumActions, handPos;
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
                state.hand[curPlayer][i] = smithy; //set whole hand = to smithy
                state.deck[curPlayer][i] = curse; //set whole deck = to curse
            }
            state.deckCount[curPlayer] = h + 1;
            state.numActions = h;
            state.handCount[curPlayer] = handPos + 1;
            state.hand[curPlayer][handPos] = village;   //set hand at handPos to village


            prevNumActions = state.numActions;
            prevHandCount = state.handCount[curPlayer];

            playVillage(&state, handPos);

            //test 3 cards added and 1 removed
            //printf("3 cards added test:\n");
            if (prevHandCount == state.handCount[curPlayer]) {   //1 cards added which discounts 1 lost
                printf("Test Passed 1.1\n");
            }
            else {
                printf("Test Failed 1\n");
                testCounter++;
            }

            //printf("prevActions: %d, numActions %d", prevNumActions, state.numActions);
            if (prevNumActions + 2 == state.numActions) {   //2 actions added
                printf("Test Passed 2\n");
            }
            else {
                printf("Test Failed 2\n");
                testCounter++;
            }

        }
    }
    if (testCounter <= 0) {
        printf("All tests passed the Village Card\n");
    }
    else  {
        printf("%d tests failed on the Village Card\n\n", testCounter);
    }
    return 0;
}


/**********
Function: playVillage
Purpose: The Council Room card draws 1 extra cards and gives 2 extra buys
Inputs: gameState, handPos
**********/
//int playVillage(struct gameState *state, int handPos) {
//
//    int currentPlayer = whoseTurn(state);
//      //+1 Card
//      drawCard(currentPlayer, state);
//
//      //+2 Actions
//      state->numActions = state->numActions + 2;
//
//      //discard played card from hand
//      discardCard(handPos, currentPlayer, state, 9);
//      return 0;
//}
