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
    int i, x, p;
    int maxPlayers = 4;
    int curPlayer, curPlayers;
    int maxCards = 50;
    int failCounter = 0;
    int passCounter = 0;
    int trials = 1000000; //number of tests to be run
    
    struct gameState state;
    memset(&state, 'z', sizeof(struct gameState));
    initializeGame(curPlayers, kingCards, randomSeed, &state);
    
    //      Major edge Cases
    // < 2 & >=2 adventure cards in deck + discard
    // < 2 & >=2 adventure cards in deck
    // < 2 & >=2 adventure cards in discard
    
    //      SETUP
    //randomly set current player
    //split cards randomly to set current deck/discard/hand
    // - make hand more likely to be 0
    // - set deck/discard/hand counts accordingly
    // - record the split for testing.
    //
    
    //      Oracle
    //Check hand == prev hand + 2 treasure cards || if full deck has been seen
    //if prev deck >= 2 t cards, discard == discard + array before and not including t cards
    //if prev deck < 2 t cards,

    
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
        
        //reset gameState & test state
        //set all cards = -1, count = 0
        for (int z = 0; z < maxPlayers; ++z) {
            for (int k = 0; k < maxCards; ++k) {
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
        
        //init new test
        initializeGame(curPlayers, kingCards, randomSeed, &state);
        
        //init Counts, each character deck is not influenced from others.
        for (int z; z < curPlayers; ++z) {
            tempHandCount[z] = rand() % 500;
            state.handCount[z] = tempHandCount[z];
            tempDeckCount[z] = rand() % (500 - tempHandCount[z]);
            state.deckCount[z] = tempHandCount[z];
            tempDiscardCount[z] = rand() % (500 - (tempHandCount[z] + tempDeckCount[z]));
            state.discardCount[z] = tempHandCount[z];
        }
        
        //init card collections
        int numCopper = 60 - (7 * curPlayers);
        int numSilver = 40;
        int numGold = 30;
        
        for (int z; z < curPlayers; ++z) {
            for (int k = 0; k < tempHandCount[z]; ++k) {
                tempHand[z][k] = rand() % 27;
                if (tempHand[z][k] == 4 || tempHand[z][k] == 5 || tempHand[z][k] == 6) {
                    tempTreasureCount[z][0]++;
                    tempTreasureCount[z][3]++;
                }
            }
            for (int k = 0; k < tempDeckCount[z]; ++k) {
                tempDeck[z][k] = rand() % 27;
                if (tempDeck[z][k] == 4 || tempDeck[z][k] == 5 || tempDeck[z][k] == 6) {
                    tempTreasureCount[z][1]++;
                    tempTreasureCount[z][3]++;
                }
            }
            for (int k = 0; k < tempDiscardCount[z]; ++k) {
                    tempDiscard[z][k] = rand() % 27;
                if (tempDiscard[z][k] == 4 || tempDiscard[z][k] == 5 || tempDiscard[z][k] == 6) {
                    tempTreasureCount[z][2]++;
                    tempTreasureCount[z][3]++;
                }
            }
        }
                           
       //copy temp collections into state
       memcpy(state.hand, tempHand, sizeof(int) * maxPlayers * maxCards);
       memcpy(state.deck, tempDeck, sizeof(int) * maxPlayers * maxCards);
       memcpy(state.discard, tempDiscard, sizeof(int) * maxPlayers * maxCards);
                    
        
        //print tests
        for (i = 0; i < curPlayers; ++i) {
            printf("Hand, tmpHandCount: %d, handCount: %d\n", tempHandCount[i], state.handCount[i]);
            printf("Player: %d\tmp\tstate", i);
            for (x = 0; x < tempHandCount[i]; ++x) {
                printf("%d/t%d\n", tempHand[i][x], state.hand[i][x]);
            }
            
            printf("Hand, tmpDeckCount: %d, deckCount: %d\n", tempDeckCount[i], state.deckCount[i]);
            printf("Player: %d\tmp\tstate", i);
            for (x = 0; x < tempDeckCount[i]; ++x) {
                printf("%d/t%d\n", tempDeck[i][x], state.deck[i][x]);
            }
            
            printf("Hand, tmpDiscardCount: %d, discardCount: %d\n", tempDiscardCount[i], state.discardCount[i]);
            printf("Player: %d\tmp\tstate", i);
            for (x = 0; x < tempDiscardCount[i]; ++x) {
                printf("%d/t%d\n", tempDiscard[i][x], state.discard[i][x]);
            }
            
        }
        
        for (p = 0; p < curPlayers; ++p) {
            int preTreasureCardCount = tempTreasureCount[p][0]; //# of treasure cards in hand before
            int postTreasureCardCount;
            int test = 0;
            state.whoseTurn = p;
            playAdventurer(state);
            
            //compare # of treasure cards

            
            for (x = 0; x < state.handCount[p]; ++x) {
                if (state.hand[p][x] == 4 || state.hand[p][x] == 5 || state.hand[p][x] == 6) {
                    postTreasureCardCount++;
                }
            }
            
            if (postTreasureCardCount == preTreasureCardCount + 2) {
                if ((tempTreasureCount[p][1] + tempTreasureCount[p][2]) >= 2) {
                    passCounter++;
                }
                else {
                    failcounter++;
                }
            }
            else if (postTreasureCardCount == preTreasureCardCount +1) {
                //check for 1 treasure card i temp deck/hand
                if ((tempTreasureCount[p][1] + tempTreasureCount[p][2]) == 1) {
                    passCounter++;
                }
                else {
                    failCounter++;
                }
            }
            else if (postTreasureCardCount == preTreasureCardCount) {
                //check for 0 treasure cards in temp deck/hand
                if ((tempTreasureCount[p][1] + tempTreasureCount[p][2]) == 0) {
                    passCounter++;
                }
                else {
                    failCounter++;
                }
            }
        }
        
        
        --trials;
    }
    
    
    
    if (failCounter <= 0) {
        printf("All tests passed the Adventure Card\n");
    }
    else  {
        printf("%d tests failed on the adventure card\n\n", failCounter);
    }
    
    return 0;
}

