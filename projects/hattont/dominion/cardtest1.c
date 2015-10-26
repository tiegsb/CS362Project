#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"

int main(int argc, char *argv[]){
    int i = 0;
    PutSeed(-1);
    printf("cardtest1.c\n");
    struct gameState state;
    struct gameState stateCopy;

    /* clear state */
    memset(&state, 0, sizeof(struct gameState));
    
    /* copy of gameState for comparison */
    stateCopy = state;

    /*Init deck with 3 coin cards and 3 other cards.*/

    state.deck[0][0] = silver;
    state.deck[0][1] = province;
    state.deck[0][2] = gold;
    state.deck[0][3] = duchy;

    state.deckCount[0] = 4;
    state.discardCount[0] = 0;
    state.handCount[0] = 0;

    adventurerCard(&state, 0);

    printf("adventurerCard(): %s empty hand case\n", 
        (state.handCount[0] == 2 &&
        state.discardCount[0] == 2 &&
        state.deckCount[0] == 0) ? "PASS" : "FAIL");
    
    /* clear game state */
    memset(&state, 0, sizeof(struct gameState));
    
    state.deck[0][0] = estate;
    state.deck[0][1] = province;
    state.deck[0][2] = gold;
    state.deck[0][3] = duchy;

    state.deckCount[0] = 4;
    state.discardCount[0] = 0;
    state.handCount[0] = 0;

    adventurerCard(&state, 0);
    
    printf("adventurerCard(): %s not enough Treasure case\n", 
        (state.handCount[0] == 1 &&
        state.discardCount[0] == 3 &&
        state.deckCount[0] == 0) ? "PASS" : "FAIL");

    /* clear game state */
    memset(&state, 0, sizeof(struct gameState));

    for (i = 0; i < MAX_DECK; i++) {
        state.deck[0][i] = floor(Random() * (treasure_map + 1));
    }

    state.deckCount[0] = MAX_DECK;
    state.discardCount[0] = 0;
    state.handCount[0] = 0;

    adventurerCard(&state, 0);

    printf("adventurerCard(): %s full deck case\n", 
        (state.handCount[0] == 2 &&
        (state.discardCount[0] + state.deckCount[0]) == MAX_DECK - 2) ? "PASS" : "FAIL");

    /* Cannot test empty deck state due to open bug. */
    /* clear game state */
    memset(&state, 0, sizeof(struct gameState));
    
    state.playedCards[0] = copper;
    state.playedCards[1] = province;
    state.playedCards[2] = gold;
    state.playedCards[3] = duchy;

    state.deckCount[0] = 0;
    state.discardCount[0] = 0;
    state.handCount[0] = 0;
    state.playedCardCount = 4;

    adventurerCard(&state, 0);
    
    printf("adventurerCard(): %s empty deck case\n", 
        (state.handCount[0] == 2 &&
        state.discardCount[0] == 2 &&
        state.deckCount[0] == 0) ? "PASS" : "FAIL");
    // printf("deckCount: %i handCount: %i discardCount: %i\n", state.deckCount[0],
    //     state.handCount[0], state.discardCount[0]);

    /* clear verified changes made by adventurerCard() */
    memset(&state.handCount[0], 0, sizeof(int));
    memset(&state.deckCount[0], 0, sizeof(int)); 
    memset(&state.discardCount[0], 0, sizeof(int));
    memset(&state.playedCardCount, 0, sizeof(int)); 
    memset(&state.hand[0], 0, sizeof(int) * MAX_HAND); 
    memset(&state.deck[0], 0, sizeof(int) * MAX_DECK);
    memset(&state.discard[0], 0, sizeof(int) * MAX_DECK);
    memset(&state.playedCards, 0, sizeof(int) * MAX_DECK);

    /* verify that no erroneous changes are made to game state */
    printf("adventurerCard(): %s changes to correct player only\n", 
        (memcmp(&state, &stateCopy, sizeof(struct gameState)) == 0) 
        ? "PASS" : "FAIL");

    return 0;
}