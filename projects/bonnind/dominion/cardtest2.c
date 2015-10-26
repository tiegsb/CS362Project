#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"

int main(int argc, char *argv[]){
    PutSeed(-1);
    printf("cardtest2.c\n");
    struct gameState state;
    struct gameState stateCopy;
    memset(&state, 0, sizeof(struct gameState));
    
    /* copy of gameState for comparison */
    stateCopy = state;

    /*Init deck with 4 cards.*/

    state.deck[0][0] = silver;
    state.deck[0][1] = province;
    state.deck[0][2] = gold;
    state.deck[0][3] = duchy;

    state.hand[0][0] = village;
    state.deckCount[0] = 4;
    state.discardCount[0] = 0;
    state.handCount[0] = 1;
    state.numActions = 0;
    state.playedCardCount = 0;

    villageCard(&state, 0, 0);

    printf("villageCard(): %s empty hand (except Village card) case\n", 
        (state.handCount[0] == 1 &&
        state.playedCardCount == 1 &&
        state.deckCount[0] == 3 &&
        state.numActions == 2) ? "PASS" : "FAIL");

    /* clear game state */
    memset(&state, 0, sizeof(struct gameState));

    /*Init deck with 4 cards.*/

    state.deck[0][0] = silver;
    state.deck[0][1] = province;
    state.deck[0][2] = gold;
    state.deck[0][3] = duchy;

    state.hand[0][0] = village;
    state.handCount[0] = 1;
    state.deckCount[0] = 0;
    state.discardCount[0] = 0;
    state.numActions = 0;
    state.playedCardCount = 0;

    villageCard(&state, 0, 0);

    printf("villageCard(): %s empty deck case\n", 
    (state.handCount[0] == 0 &&
    state.playedCardCount == 1 &&
    state.deckCount[0] == 0 &&
    state.numActions == 2) ? "PASS" : "FAIL");

    /* clear verified changes made by villageCard() */
    memset(&state.handCount[0], 0, sizeof(int));
    memset(&state.deckCount[0], 0, sizeof(int)); 
    memset(&state.discardCount[0], 0, sizeof(int));
    memset(&state.playedCardCount, 0, sizeof(int)); 
    memset(&state.hand[0], 0, sizeof(int) * MAX_HAND); 
    memset(&state.deck[0], 0, sizeof(int) * MAX_DECK);
    memset(&state.discard[0], 0, sizeof(int) * MAX_DECK);
    memset(&state.playedCards, 0, sizeof(int) * MAX_DECK);
    memset(&state.numActions, 0, sizeof(int) * MAX_DECK);

    /* verify that no erroneous changes are made to game state */
    printf("villageCard(): %s changes to correct player only\n", 
        (memcmp(&state, &stateCopy, sizeof(struct gameState)) == 0) 
        ? "PASS" : "FAIL");    

    /* clear game state */
    memset(&state, 0, sizeof(struct gameState));

    /*Init deck with 4 cards.*/

    state.deck[0][0] = silver;
    state.deck[0][1] = province;
    state.deck[0][2] = gold;
    state.deck[0][3] = duchy;

    state.hand[0][0] = village;
    state.hand[0][1] = village;
    state.deckCount[0] = 4;
    state.discardCount[0] = 0;
    state.handCount[0] = 2;
    state.numActions = 0;
    state.playedCardCount = 0;

    villageCard(&state, 0, 0);
    villageCard(&state, 0, 1);

    printf("villageCard(): %s 2 consecutive Village cards case\n", 
        (state.handCount[0] == 2 &&
        state.playedCardCount == 2 &&
        state.deckCount[0] == 2 &&
        state.numActions == 4) ? "PASS" : "FAIL");

    // printf("deckCount: %i handCount: %i playedCardCount: %i\n", 
    //     state.deckCount[0], state.handCount[0], state.playedCardCount);
    return 0;
}