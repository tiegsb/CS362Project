#include "dominion.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>


int main() {

    printf("\nTesting discardCard() function:\n");

    struct gameState state;
    int randomSeed = 100;
    int kingCards[10] = {0, 1, 2, 10, 12, 18, 16, 22, 25, 26};
    int maxPlayers = 4;
    int i;
    int handCount = 3;
    int flag = 1;
    int player = 0;
    int testCounter = 0;
    memset(&state, 'z', sizeof(struct gameState));
    initializeGame(maxPlayers, kingCards, randomSeed, &state);
    state.handCount[0] = handCount;

    for (i = 0; i < handCount; ++i) {
        state.hand[player][i] = i;
    }

    printf("\nTesting removal of first card in hand\n");
    //remove first with flag = 1
    flag = 1;
    int prevBackCard = state.hand[player][handCount -1];
    int prevHandCount = state.handCount[player];
    int test = discardCard(0, player, &state, flag);
    if (test == 0) {
        //hand count--
        //printf("%d vs %d\n", state.handCount[player], prevHandCount - 1);
        if (state.handCount[player] == prevHandCount - 1) {
            printf("Test passed: s1, t1\n");
        }
        else {
            printf("Test failed: s1, t1\n");
            testCounter++;
        }

        //first == former last
        //printf("%d vs %d\n", state.hand[player][0], prevBackCard);
        if (state.hand[player][0] == prevBackCard) {
            printf("Test passed: s1, t2\n");
        }
        else {
            printf("Test failed: s1, t2\n");
            testCounter++;
        }

        //former last index == -1
        //printf("%d vs %d\n", state.hand[player][prevHandCount -1], -1);
        if (state.hand[player][prevHandCount -1] == -1) {
            printf("Test passed: s1, t3\n");
        }
        else {
            printf("Test failed: s1, t3\n");
            testCounter++;
        }

        //card not trashed
        if (state.playedCardCount == 0) {
            printf("Test passed: s1, t4\n");
        }
        else {
            printf("Test failed: s1, t4\n");
            testCounter++;
        }
    }

    printf("\nTesting removal of last card in hand\n");
    //remove last with flag = 0
    flag = 0;
    prevBackCard = state.hand[player][handCount -1];
    prevHandCount = state.handCount[player];
    test = discardCard(state.handCount[player] - 1, player, &state, flag);
    if (test == 0) {
        //hand count--
        //printf("%d vs %d\n", state.handCount[player], prevHandCount - 1);
        if (state.handCount[player] == prevHandCount - 1) {
            printf("Test passed: s2, t1\n");
        }
        else {
            printf("Test failed: s2, t1\n");
            testCounter++;
        }

        //former last index == -1
        //printf("%d vs %d\n", state.hand[player][prevHandCount -1], -1);
        if(state.hand[player][prevHandCount -1] == -1) {
            printf("Test passed: s2, t2\n");
        }
        else {
            printf("Test failed: s2, t2\n");
            testCounter++;
        }

        //card trashed
        if (state.playedCardCount == 1) {
            printf("Test passed: s2, t3\n");
        }
        else {
            printf("Test failed: s2, t3\n");
            testCounter++;
        }
    }

    printf("\nTesting removal of last remaining card in hand\n");
    //remove final with flag = 1
    flag = 1;
    prevBackCard = state.hand[player][handCount -1];
    prevHandCount = state.handCount[player];
    test = discardCard(state.handCount[player] - 1, player, &state, flag);
    if (test == 0) {
        //hand count--
        //printf("%d vs %d\n", state.handCount[player], prevHandCount - 1);
        if (state.handCount[player] == prevHandCount - 1) {
            printf("Test passed: s3, t1\n");
        }
        else {
            printf("Test failed: s3, t1\n");
            testCounter++;
        }

        //former last index == -1
        //printf("%d vs %d\n", state.hand[player][prevHandCount -1], -1);
        if (state.hand[player][prevHandCount -1] == -1) {
            printf("Test passed: s3, t2\n");
        }
        else {
            printf("Test failed: s3, t2\n");
            testCounter++;
        }

        //card not trashed, playedCardCount stays the same as previous (1)
        if (state.playedCardCount == 1) {
            printf("Test passed: s3, t3\n");
        }
        else {
            printf("Test failed: s3, t3\n");
            testCounter++;
        }
    }
    if (testCounter <= 0) {
        printf("All Tests Passed discardCard()\n");
    }
    else {
        printf("%d tests failed on discardCard()\n\n", testCounter);
    }

    return 0;
}



