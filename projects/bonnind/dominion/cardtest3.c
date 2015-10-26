#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"

int main(int argc, char *argv[]){
    PutSeed(-1);
    printf("cardtest3.c\n");
    struct gameState state;
    struct gameState stateCopy;

    /* clear game state */
    memset(&state, 0, sizeof(struct gameState));
    
    /* copy of gameState for comparison */
    stateCopy = state;
    
    /*Init deck with 4 cards.*/

    state.deck[0][0] = silver;
    state.deck[0][1] = province;
    state.deck[0][2] = gold;
    state.deck[0][3] = duchy;

    state.hand[0][0] = great_hall;
    state.deckCount[0] = 4;
    state.discardCount[0] = 0;
    state.handCount[0] = 1;
    state.numActions = 0;
    state.playedCardCount = 0;

    greatHallCard(&state, 0, 0);

    printf("greatHallCard(): %s empty hand (except Great Hall card) case\n", 
        (state.handCount[0] == 1 &&
        state.playedCardCount == 1 &&
        state.deckCount[0] == 3 &&
        state.numActions == 1) ? "PASS" : "FAIL");

    /* clear game state */
    memset(&state, 0, sizeof(struct gameState));

    /*Init deck with 4 cards.*/

    state.deck[0][0] = silver;
    state.deck[0][1] = province;
    state.deck[0][2] = gold;
    state.deck[0][3] = duchy;

    state.hand[0][0] = great_hall;
    state.handCount[0] = 1;
    state.deckCount[0] = 0;
    state.discardCount[0] = 0;
    state.numActions = 0;
    state.playedCardCount = 0;
    greatHallCard(&state, 0, 0);

    printf("greatHallCard(): %s empty deck case\n", 
    (state.handCount[0] == 0 &&
    state.playedCardCount == 1 &&
    state.deckCount[0] == 0 &&
    state.numActions == 1) ? "PASS" : "FAIL");

    /* clear game state */
    memset(&state, 0, sizeof(struct gameState));

    /*Init deck with 4 cards.*/

    state.deck[0][0] = silver;
    state.deck[0][1] = province;
    state.deck[0][2] = gold;
    state.deck[0][3] = duchy;

    state.hand[0][0] = great_hall;
    state.hand[0][1] = great_hall;
    state.deckCount[0] = 4;
    state.discardCount[0] = 0;
    state.handCount[0] = 2;
    state.numActions = 0;
    state.playedCardCount = 0;

    greatHallCard(&state, 0, 0);
    greatHallCard(&state, 0, 1);

    printf("greatHallCard(): %s 2 consecutive Great Hall cards case:\n", 
        (state.handCount[0] == 2 &&
        state.playedCardCount == 2 &&
        state.deckCount[0] == 2 &&
        state.numActions == 2) ? "PASS" : "FAIL");

    /* clear game state */
    memset(&state, 0, sizeof(struct gameState));

    /*Set deckCount for player 1 to be 0*/

    state.deck[1][0] = silver;
    state.deck[1][1] = province;
    state.deck[1][2] = gold;
    state.deck[1][3] = duchy;

    state.hand[1][0] = great_hall;

    state.handCount[1] = 1;
    state.deckCount[1] = 4;
    state.discardCount[1] = 0;
    state.numActions = 0;
    state.playedCardCount = 0;

    greatHallCard(&state, 1, 0);

    printf("greatHallCard(): %s normal deck case with second player\n", 
    (state.handCount[1] == 1 &&
    state.playedCardCount == 1 &&
    state.deckCount[1] == 3 &&
    state.numActions == 1) ? "PASS" : "FAIL");
    // printf("deckCount: %i handCount: %i playedCardCount: %i\n", 
    //     state.deckCount[1], state.handCount[1], state.playedCardCount);
    return 0;
}