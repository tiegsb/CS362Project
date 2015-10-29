#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dominion.h"
#include "dominion_helpers.h"

/**
 * Test that 1 and only 1 estate card exists in player discard and only discard.
 * @param  player player number
 * @param  state  
 * @return        1 on success 0 on failure
 */
int estateInDiscard(int player, struct gameState *state) {
    if ((state->discardCount[player] != 1) ||
        (state->handCount[player] != 0) ||
        (state->deckCount[player] != 0) ||
        (state->discard[player][0] != estate))
    {
        return 0;
    }
    else
        return 1;
}

int main(int argc, char *argv[]){
    printf("unittest3.c:\n");
    struct gameState state;
    struct gameState stateCopy;

    /* clear state */
    memset(&state, 0, sizeof(struct gameState));
    
    /* copy of gameState for comparison */
    stateCopy = state;

    state.deckCount[0] = 0;
    state.handCount[0] = 0;
    state.discardCount[0] = 0;
    state.numBuys = 1;
    state.coins = 2;
    state.supplyCount[estate] = 1;

    buyCard(estate, &state);

    printf("buyCard(): %s normal case\n", 
        (estateInDiscard(0, &state)) ? "PASS" : "FAIL" );

    /* clear state */
    memset(&state, 0, sizeof(struct gameState));

    state.deckCount[0] = 0;
    state.handCount[0] = 0;
    state.discardCount[0] = 0;
    state.numBuys = 0;
    state.coins = 2;
    state.supplyCount[estate] = 1;

    buyCard(estate, &state);

    printf("buyCard(): %s 0 buys\n", 
        (!estateInDiscard(0, &state)) ? "PASS" : "FAIL" );

    /* clear state */
    memset(&state, 0, sizeof(struct gameState));

    state.deckCount[0] = 0;
    state.handCount[0] = 0;
    state.discardCount[0] = 0;
    state.numBuys = 1;
    state.coins = 1;
    state.supplyCount[estate] = 1;

    buyCard(estate, &state);

    printf("buyCard(): %s not enough coins\n", 
        (!estateInDiscard(0, &state)) ? "PASS" : "FAIL" );
    
    /* clear state */
    memset(&state, 0, sizeof(struct gameState));
    
    state.deckCount[0] = 0;
    state.handCount[0] = 0;
    state.discardCount[0] = 0;
    state.numBuys = 1;
    state.coins = 2;
    state.supplyCount[estate] = 0;

    buyCard(estate, &state);

    printf("buyCard(): %s no cards left\n", 
        (!estateInDiscard(0, &state)) ? "PASS" : "FAIL" );
    
    /* clear state */
    memset(&state, 0, sizeof(struct gameState));
    
    state.deckCount[0] = 0;
    state.handCount[0] = 0;
    state.discardCount[0] = 0;
    state.numBuys = 1;
    state.coins = 2;
    state.supplyCount[estate] = 1;

    buyCard(estate, &state);

    printf("buyCard(): %s numBuys decremented properly\n", 
        (state.numBuys == 0) ? "PASS" : "FAIL" );

    printf("buyCard(): %s coins decremented properly\n", 
        (state.coins == 0) ? "PASS" : "FAIL" );
    
    printf("buyCard(): %s supplyCount decremented properly\n", 
        (state.supplyCount[estate] == 0) ? "PASS" : "FAIL" );

    /* clear verified changes made by buyCard() */
    memset(&state.handCount[0], 0, sizeof(int));
    memset(&state.deckCount[0], 0, sizeof(int)); 
    memset(&state.discardCount[0], 0, sizeof(int));
    memset(&state.phase, 0, sizeof(int)); 
    memset(&state.hand[0], 0, sizeof(int) * MAX_HAND); 
    memset(&state.deck[0], 0, sizeof(int) * MAX_DECK);
    memset(&state.discard[0], 0, sizeof(int) * MAX_DECK);
    memset(&state.numBuys, 0, sizeof(int));
    memset(&state.coins, 0, sizeof(int));
    memset(&state.supplyCount, 0, sizeof(int) * treasure_map + 1);

    /* verify that no erroneous changes are made to game state */
    printf("buyCard(): %s changes to correct player only\n", 
        (memcmp(&state, &stateCopy, sizeof(struct gameState)) == 0) 
        ? "PASS" : "FAIL");
    return 0;
}
