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
    int maxPlayers = 4;
    int kingCards[10] = {0, 1, 2, 10, 12, 18, 16, 22, 25, 26};
    int x, k, z;
    struct gameState state;
    int prevHandCount, prevNumActions, handPos, curPlayer, curPlayers;
    int failCounter = 0;
    int passCounter = 0;
    int trials = 1000; //number of tests to be run
    int maxCards = 500;

    srand(time(NULL));
    int tempHand[maxPlayers][maxCards];
    int tempHandCount[maxPlayers];
    int tempDeck[maxPlayers][maxCards];
    int tempDeckCount[maxPlayers];
    int tempDiscard[maxPlayers][maxCards];
    int tempDiscardCount[maxPlayers];
    int villageHandPos[maxPlayers];
    while (trials > 0) {

        //randomize number of players
        curPlayers = (rand() % 3) + 2;
        memset(&state, 'z', sizeof(struct gameState));
        initializeGame(curPlayers, kingCards, randomSeed, &state);

        //reset gameState & test state
        //set all cards = -1, count = 0
        for (z = 0; z < maxPlayers; ++z) {
            for (k = 0; k < maxCards; ++k) {
                tempHand[z][k] = -1;
                tempDeck[z][k] = -1;
                tempDiscard[z][k] = -1;
            }
            tempHandCount[z] = 0;
            tempDeckCount[z] = 0;
            tempDiscardCount[z] = 0;
        }

        //init Counts, each character deck is not influenced from others.
        for (z = 0; z < curPlayers; ++z) {
            tempHandCount[z] = (rand() % maxCards); // always have space for at least 1 adventurer card
            if (tempHandCount[z] == 0) {
                tempHandCount[z] = 1;
            }
            state.handCount[z] = tempHandCount[z];
            tempDeckCount[z] = rand() % (maxCards - tempHandCount[z]);
            state.deckCount[z] = tempHandCount[z];
            tempDiscardCount[z] = rand() % (maxCards - (tempHandCount[z] + tempDeckCount[z]));
            state.discardCount[z] = tempHandCount[z];
        }

        for (z = 0; z < curPlayers; ++z) {
            villageHandPos[z] = rand() % tempHandCount[z];
            for (k = 0; k < tempHandCount[z]; ++k) {
                tempHand[z][k] = rand() % 27;
            }
            //set pos to village card
            tempHand[z][villageHandPos[z]] = village;

            for (k = 0; k < tempDeckCount[z]; ++k) {
                tempDeck[z][k] = rand() % 27;
            }
            for (k = 0; k < tempDiscardCount[z]; ++k) {
                    tempDiscard[z][k] = rand() % 27;
            }
        }

        memcpy(&state.hand, &tempHand, sizeof(int) * maxPlayers * maxCards);
        memcpy(state.handCount, tempHandCount, sizeof(int) * maxPlayers);

        memcpy(&state.deck, &tempDeck, sizeof(int) * maxPlayers * maxCards);
        memcpy(state.deckCount, tempDeckCount, sizeof(int) * maxPlayers);

        memcpy(&state.discard, &tempDiscard, sizeof(int) * maxPlayers * maxCards);
        memcpy(&state.discardCount, &tempDiscardCount, sizeof(int) * maxPlayers);

        for (x = 0; x < curPlayers; ++x) {
            curPlayer = x;
            state.whoseTurn = x;
            handPos = villageHandPos[curPlayer];

            prevNumActions = state.numActions;
            prevHandCount = state.handCount[curPlayer];

            playVillage(&state, handPos);

            //test 3 cards added and 1 removed
            //printf("3 cards added test:\n");
            if (prevHandCount == state.handCount[curPlayer]) {   //1 cards added which discounts 1 lost
                passCounter++;
            }
            else {
                failCounter++;
            }
            if (state.discardCount[curPlayer] == tempDiscardCount[curPlayer] + 1 ) {
                passCounter++;
            }
            else {
                failCounter++;
            }

            //printf("prevActions: %d, numActions %d", prevNumActions, state.numActions);
            if (prevNumActions + 2 == state.numActions) {   //2 actions added
                passCounter++;
            }
            else {
                failCounter++;
            }

        }
        --trials;
    }
    printf("Tests Passed: %d, Test Failed %d\n", passCounter, failCounter);
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
