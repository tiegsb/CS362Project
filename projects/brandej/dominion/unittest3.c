#include "dominion.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

/* Testing of scoreFor() funciton
    -gardens causes errors due to passing numHandsCards 0 for a card and only finding curses

*/
int main() {

    printf("\nTesting scoreFor() function:\n");

    int randomSeed = 100;
    int maxPlayers = 4;
    int kingCards[10] = {0, 1, 2, 10, 12, 18, 16, 22, 25, 26};
    int officialPlayersScore[maxPlayers];
    int testPlayersScore[maxPlayers];
    int i;
    struct gameState state;
    int handCount = 5;
    int discardCount = 5;
    int deckCount = 5;


    int curPlayers = 4;

    memset(&state, 'z', sizeof(struct gameState));
    initializeGame(curPlayers, kingCards, randomSeed, &state);
    for (i = 0; i < curPlayers; ++i) {
        state.handCount[i] = handCount;
        state.discardCount[i] = discardCount;
        state.deckCount[i] = deckCount;
    }


    //player 1
    int p1 = 0;
    for (i = 0; i < handCount; ++i) {
        state.hand[p1][i] = curse;
        state.discard[p1][i] = curse;
        state.deck[p1][i] = curse;
    }
    //math based on card values
    testPlayersScore[p1] = -1 * (3 * handCount);
    //scoreFor function
    officialPlayersScore[p1] = scoreFor(p1, &state);

    //player 2
    int p2 = 1;
    for (i = 0; i < handCount; ++i) {
        state.hand[p2][i]    = gardens;
        state.discard[p2][i] = great_hall;
        state.deck[p2][i]    = province;
    }
    //math based on card values
    testPlayersScore[p2] = ((handCount * 3) / 10) + (1 * handCount) + (6 * handCount);
    //scoreFor function
    officialPlayersScore[p2] = scoreFor(p2, &state);

    //player 3
    int p3 = 2;
    for (i = 0; i < handCount; ++i) {
        state.hand[p3][i]    = great_hall;
        state.discard[p3][i] = gardens;
        state.deck[p3][i]    = curse;
    }
    //math based on card values
    testPlayersScore[p3] = (1 * handCount) + ((handCount * 3) / 10) + (-1 * handCount);
    //scoreFor function
    officialPlayersScore[p3] = scoreFor(p3, &state);

    //player 4
    int p4 = 3;
    for (i = 0; i < handCount; ++i) {
        state.hand[p4][i]    = estate;
        state.discard[p4][i] = duchy;
        state.deck[p4][i]    = gardens;
    }
    //math based on card values
    testPlayersScore[p4] = (1 * handCount) + (3 * handCount) + ((handCount * 3) / 10);
    //scoreFor function
    officialPlayersScore[p4] = scoreFor(p4, &state);

    //test score is calculated by hand, offical score is via the functions
    int counter = 0;
    for (i = 0; i < curPlayers; ++i) {
        if(testPlayersScore[i] != officialPlayersScore[i]) {
            //printf("test score: %d, \"offical score\" %d\n", testPlayersScore[i], officialPlayersScore[i]);
            printf("Test failed on player %d\n", i);
            counter++;
            //assert(testPlayersScore[i] == officialPlayersScore[i]);
        }
        else {
            printf("Test passed on player %d\n", i);
        }
    }
    if (counter <= 0) {
        printf("All tests passed scoreFor()");
    }
    else {
        printf("%d tests failed on scoreFor()\n\n", counter);
    }

    return 0;
}
