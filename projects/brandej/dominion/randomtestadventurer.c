#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>


int main() {

    printf("\nTesting Adventurer Card:\n");

    //initial variables
    int randomSeed = 100;
    int kingCards[10] = {0, 1, 2, 10, 12, 18, 16, 22, 25, 26};
    int i, x, p, k, z;
    int maxPlayers = 4;
    int curPlayer, curPlayers;
    int maxCards = 500;
    int failCounter = 0;
    int passCounter = 0;
    int trials = 100000; //number of tests to be run

    struct gameState state;

    srand(time(NULL));
    int tempTreasureCount[maxPlayers][4]; //0 is hand, 1 is deck, 3 is discard, 4 is total
    int tempHand[maxPlayers][maxCards];
    int tempHandCount[maxPlayers];
    int tempDeck[maxPlayers][maxCards];
    int tempDeckCount[maxPlayers];
    int tempDiscard[maxPlayers][maxCards];
    int tempDiscardCount[maxPlayers];

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
            tempTreasureCount[z][0] = 0;
            tempTreasureCount[z][1] = 0;
            tempTreasureCount[z][2] = 0;
            tempTreasureCount[z][3] = 0;
        }

        //init Counts, each character deck is not influenced from others.
        for (z = 0; z < curPlayers; ++z) {
            tempHandCount[z] = rand() % maxCards;
            state.handCount[z] = tempHandCount[z];
            tempDeckCount[z] = rand() % (maxCards - tempHandCount[z]);
            state.deckCount[z] = tempHandCount[z];
            tempDiscardCount[z] = rand() % (maxCards - (tempHandCount[z] + tempDeckCount[z]));
            state.discardCount[z] = tempHandCount[z];
        }

        for (z = 0; z < curPlayers; ++z) {
            for (k = 0; k < tempHandCount[z]; ++k) {
                tempHand[z][k] = rand() % 27;
                if (tempHand[z][k] == 4 || tempHand[z][k] == 5 || tempHand[z][k] == 6) {
                    tempTreasureCount[z][0]++;
                    tempTreasureCount[z][3]++;
                }
            }
            for (k = 0; k < tempDeckCount[z]; ++k) {
                tempDeck[z][k] = rand() % 27;
                if (tempDeck[z][k] == 4 || tempDeck[z][k] == 5 || tempDeck[z][k] == 6) {
                    tempTreasureCount[z][1]++;
                    tempTreasureCount[z][3]++;
                }
            }
            for (k = 0; k < tempDiscardCount[z]; ++k) {
                    tempDiscard[z][k] = rand() % 27;
                if (tempDiscard[z][k] == 4 || tempDiscard[z][k] == 5 || tempDiscard[z][k] == 6) {
                    tempTreasureCount[z][2]++;
                    tempTreasureCount[z][3]++;
                }
            }
        }

       memcpy(&state.hand, &tempHand, sizeof(int) * maxPlayers * maxCards);
       memcpy(state.handCount, tempHandCount, sizeof(int) * maxPlayers);

       memcpy(&state.deck, &tempDeck, sizeof(int) * maxPlayers * maxCards);
       memcpy(state.deckCount, tempDeckCount, sizeof(int) * maxPlayers);

       memcpy(&state.discard, &tempDiscard, sizeof(int) * maxPlayers * maxCards);
       memcpy(&state.discardCount, &tempDiscardCount, sizeof(int) * maxPlayers);


//print tests
//        for (i = 0; i < curPlayers; ++i) {
//            printf("tmpHandCount: %d, handCount: %d\n", tempHandCount[i], state.handCount[i]);
//            printf("Player: %d\ttempHand\tstateHand\n", i);
//            for (x = 0; x < tempHandCount[i]; ++x) {
//                printf("%d\t%d\n", tempHand[i][x], state.hand[i][x]);
//            }
//
//            printf("tmpDeckCount: %d, deckCount: %d\n", tempDeckCount[i], state.deckCount[i]);
//            printf("Player: %d\ttempDeck\tstateDeck\n", i);
//            for (x = 0; x < tempDeckCount[i]; ++x) {
//                printf("%d\t%d\n", tempDeck[i][x], state.deck[i][x]);
//            }
//
//            printf("tmpDiscardCount: %d, discardCount: %d\n", tempDiscardCount[i], state.discardCount[i]);
//            printf("Player: %d\ttempDiscard\tstateDiscard\n", i);
//            for (x = 0; x < tempDiscardCount[i]; ++x) {
//                printf("%d\t%d\n", tempDiscard[i][x], state.discard[i][x]);
//            }
//
//        }

        for (p = 0; p < curPlayers; ++p) {
            int preTreasureCardCount = tempTreasureCount[p][0]; //# of treasure cards in hand before
            int postTreasureCardCount = 0;
            state.whoseTurn = p;
            playAdventurer(&state);

            //compare # of treasure cards


            for (x = 0; x < state.handCount[p]; ++x) {
                if (state.hand[p][x] == 4 || state.hand[p][x] == 5 || state.hand[p][x] == 6) {
                    postTreasureCardCount++;
                }
            }

            if (postTreasureCardCount == preTreasureCardCount + 2) {
                if ((tempTreasureCount[p][1] + tempTreasureCount[p][2]) >= 2) { //if original deck + discard >= 2 treasure
                    passCounter++;
                }
                else {
                    failCounter++;
                }
            }
            else if (postTreasureCardCount == preTreasureCardCount +1) {
                //check for 1 treasure card i temp deck/hand
                if ((tempTreasureCount[p][1] + tempTreasureCount[p][2]) == 1) { //if original deck + discard == 1 treasure
                    passCounter++;
                }
                else {
                    failCounter++;
                }
            }
            else if (postTreasureCardCount == preTreasureCardCount) {
                //check for 0 treasure cards in temp deck/hand
                if ((tempTreasureCount[p][1] + tempTreasureCount[p][2]) == 0) { //if original deck + discard == 0 treasures
                    passCounter++;
                }
                else {
                    failCounter++;
                }
            }
            else if (postTreasureCardCount > preTreasureCardCount + 2){  //
                failCounter++;
            }
            else {
                failCounter++;
            }
            //printf("pre %d, post %d\n", preTreasureCardCount, postTreasureCardCount);
        }
        --trials;
    }



    if (failCounter <= 0) {
        printf("All tests passed the Adventure Card\n");
    }
    else  {
        printf("pass: %d, fail: %d\n", passCounter, failCounter);
    }

    return 0;
}

