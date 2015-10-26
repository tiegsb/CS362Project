#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"

int main(int argc, char *argv[]){
    PutSeed(-1);
    printf("cardtest4.c\n");
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

    state.hand[0][0] = smithy;
    state.deckCount[0] = 4;
    state.discardCount[0] = 0;
    state.handCount[0] = 1;
    state.numActions = 0;
    state.playedCardCount = 0;

    smithyCard(&state, 0, 0);

    printf("smithyCard(): %s handCount properly incremented\n", 
        (state.handCount[0] == 3 &&
        state.playedCardCount == 1 &&
        state.deckCount[0] == 1 &&
        state.numActions == 0) ? "PASS" : "FAIL");

    /* When smithy is played, cards will be drawn from deck in reverse index
     * order. When smithy card is discarded, it will be replaced with last
     * card in hand array. hand[0] expected: {province, duchy, gold} */
    printf("smithyCard(): %s correct cards, order in correct user's hand\n", 
        (state.hand[0][0] == province &&
        state.hand[0][1] == duchy &&
        state.hand[0][2] == gold) ? "PASS" : "FAIL");

    /* clear verified changes made by smithyCard() */
    memset(&state.handCount[0], 0, sizeof(int));
    memset(&state.deckCount[0], 0, sizeof(int)); 
    memset(&state.discardCount[0], 0, sizeof(int));
    memset(&state.playedCardCount, 0, sizeof(int)); 
    memset(&state.hand[0], 0, sizeof(int) * MAX_HAND); 
    memset(&state.deck[0], 0, sizeof(int) * MAX_DECK);
    memset(&state.discard[0], 0, sizeof(int) * MAX_DECK);
    memset(&state.playedCards, 0, sizeof(int) * MAX_DECK);

    /* verify that no erroneous changes are made to game state */
    printf("smithyCard(): %s changes to correct player only\n", 
        (memcmp(&state, &stateCopy, sizeof(struct gameState)) == 0) 
        ? "PASS" : "FAIL");

    return 0;
}