#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"


int main(int argc, char *argv[]){
    int i = 0;
    printf("unittest2.c:\n");
    struct gameState state;
    for (i = 0; i <= treasure_map; i++) {
        state.supplyCount[i] = 5;
    }
    state.deckCount[0] = 0;
    state.handCount[0] = 0;
    state.discardCount[0] = 0;

    gainCard(curse, &state, 0, 0);

    printf("gainCard(): %s discardCount is incremented\n", 
        (state.discardCount[0] == 1) ? "PASS" : "FAIL" );

    gainCard(curse, &state, 1, 0);

    printf("gainCard(): %s deckCount is incremented\n", 
        (state.deckCount[0] == 1) ? "PASS" : "FAIL" );

    gainCard(curse, &state, 2, 0);
    
    printf("gainCard(): %s handCount is incremented\n", 
        (state.handCount[0] == 1) ? "PASS" : "FAIL" );

    printf("gainCard(): %s supplyCount is decremented\n", 
        (state.supplyCount[curse] == 2) ? "PASS" : "FAIL" );

    state.supplyCount[curse] = 0;

    printf("gainCard(): %s empty card pile\n", 
        (gainCard(curse, &state, 0, 0) == -1) ? "PASS" : "FAIL" );    

    state.supplyCount[curse] = -1;

    printf("gainCard(): %s out-of-play card\n", 
        (gainCard(curse, &state, 0, 0) == -1) ? "PASS" : "FAIL" ); 

    return 0;
}