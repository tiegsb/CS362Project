#include "dominion.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

//gameOver doesn't check treasure map
int main() {

    printf("\nTesting isGameOver() function:\n");

    struct gameState state;
    int randomSeed = 100;
    int i, y;
    int numPlayers = 3;

    srand(time(NULL));

    //chosen to cover edges and middle of possibilities
    int kingCards[10] = {0, 1, 2, 10, 12, 18, 16, 22, 25, 26};

    int testCounter = 0;
    int gameOver = 0;
    int counter;

    printf("\nTesting three cards = 0 calcuation\n");
    while (gameOver != 1) {

        //reset gamestate
        memset(&state, 'z', sizeof(struct gameState));
        initializeGame(numPlayers, kingCards, randomSeed, &state);

        counter = 0;
        for (i = 0; i <= 26; ++i) { //all the possible supply cards
            for (y = 0; y <= 10; ++y) { //the 10 chosen supply cards
                if (kingCards[y] == i) { //if the current card matches the supply card index in state
                    state.supplyCount[i] = (rand() % 13); //set card in state
                    if (state.supplyCount[i] == 0) {
                        ++counter;
                    }
                    break;
                }
            }
        }
        if (isGameOver(&state) == 1) {
            //printf("Counter = %d, expected 3\n", counter);
            //printf("Game Over Criteria\n");
            if (counter == 3) {
                printf("Test Passed\n");
            }
            else if (counter > 3) {
                printf("Test Failed\n");
                testCounter++;
            }
            gameOver = 1;
        }
        else {
            //printf("Counter = %d, expected < 3\n", counter);
            if (counter < 3) {
                printf("Test Passed\n");
            }
            else {
                printf("Test Failed\n");
                testCounter++;
            }
        }
    }

    memset(&state, 'z', sizeof(struct gameState));
    initializeGame(numPlayers, kingCards, randomSeed, &state);

    gameOver = 0;

    printf("\nTesting Province calcuation\n");
    while (gameOver != 1) {
        state.supplyCount[3] = (rand() % 13); //province card
        if (isGameOver(&state) == 1) {
            //printf("Province = %d, expected 0\n", state.supplyCount[province]);
            //printf("Game Over Criteria\n");
            if (state.supplyCount[province] == 0) {
                printf("Test Passed\n");
            }
            else {
                printf("Test Failed\n");
                testCounter++;
            }
            gameOver = 1;
        }
        else {
            //printf("Province = %d, expected > 0\n", state.supplyCount[province]);
            if (state.supplyCount[province] > 0) {
                printf("Test Passed\n");
            }
            else {
                printf("Test Failed\n");
                testCounter++;
            }
        }
    }

    if (testCounter <= 0) {
        printf("All tests passed isGameOver()\n");
    }
    else {
        printf("%d tests failed on isGameOver()\n\n", testCounter);
    }

    return 0;
}
