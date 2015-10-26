#include "dominion.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

/* Testing of getWinners() funciton
    -gardens causes errors due to passing numHandsCards 0 for a card and only finding curses

*/

int main() {

    printf("\nTesting getWinners() function:\n");

    int randomSeed = 100;
    int maxPlayers = 4;
    int kingCards[10] = {0, 1, 2, 10, 12, 18, 16, 22, 25, 26};
    int officialPlayersScore[maxPlayers];
    int testPlayersScore[maxPlayers];
    int i, x;
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
    //scoreFor function
    officialPlayersScore[p1] = scoreFor(p1, &state);

    //player 2
    int p2 = 1;
    for (i = 0; i < handCount; ++i) {
        state.hand[p2][i]    = gardens;
        state.discard[p2][i] = great_hall;
        state.deck[p2][i]    = province;
    }
    //scoreFor function
    officialPlayersScore[p2] = scoreFor(p2, &state);

    //player 3
    int p3 = 2;
    for (i = 0; i < handCount; ++i) {
        state.hand[p3][i]    = great_hall;
        state.discard[p3][i] = gardens;
        state.deck[p3][i]    = province;
    }
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
    officialPlayersScore[p4] = scoreFor(p4, &state);
    memcpy(testPlayersScore, officialPlayersScore, sizeof(int) * curPlayers);

    //loop through players with different ending turns
    int temp;
    int counter = 0;
    for (x = 0; x < curPlayers; ++x) {
        state.whoseTurn = x;
        temp = getWinners(officialPlayersScore, &state);
        if (temp == 0) {
            if (officialPlayersScore[0] == 0 &&
                    officialPlayersScore[1] == 1 &&
                    officialPlayersScore[2] == 1 &&
                    officialPlayersScore[3] == 0)
            {
                printf("Player %d turn test Passed\n", x + 1);
            }
            //increment of whoseTurn should make player 3 win
            else if (officialPlayersScore[0] == 0 &&
                    officialPlayersScore[1] == 0 &&
                    officialPlayersScore[2] == 1 &&
                    officialPlayersScore[3] == 0)
            {
                printf("Player %d turn test Passed\n", x + 1);
            }
            else if (officialPlayersScore[0] == 0 &&
                officialPlayersScore[1] == 1 &&
                officialPlayersScore[2] == 1 &&
                officialPlayersScore[3] == 0)
            {
                printf("Player %d turn test Passed\n", x + 1);
            }
            else if (officialPlayersScore[0] == 0 &&
                officialPlayersScore[1] == 1 &&
                officialPlayersScore[2] == 1 &&
                officialPlayersScore[3] == 0)
            {
                printf("Player %d turn test Passed\n", x + 1);
            }
            else {
                counter++;
            }
        }
        if (temp != 0 || counter > 0) {
            printf("Player %d turn test Failed\n", x + 1);
        }
    }

    if (counter <= 0) {
        printf("All tests passed getWinners()\n");
    }
    else {
        printf("%d tests failed on getWinners()\n\n", counter);
    }

    return 0;
}
