#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"

int main(int argc, char *argv[]){
    int i = 0;
    printf("unittest1.c:\n");
    struct gameState fullDecksState;
    struct gameState emptyDecksState;
    struct gameState singleCardDecksState;

    /* Max size deck state*/
    fullDecksState.deckCount[0] = MAX_DECK;
    fullDecksState.handCount[0] = MAX_HAND;
    fullDecksState.discardCount[0] = MAX_DECK;
    for (i = 0; i < fullDecksState.deckCount[0]; i++) {
        fullDecksState.deck[0][i] = 0;
        fullDecksState.hand[0][i] = 0;
        fullDecksState.discard[0][i] = 0;
    }
    printf("fullDeckCount(): %s deck, hand, discard full of selected card\n", 
        (fullDeckCount(0, 0, &fullDecksState) == fullDecksState.deckCount[0] + 
            fullDecksState.handCount[0] + fullDecksState.discardCount[0]) ? "PASS" : "FAIL");
    printf("fullDeckCount(): %s deck, hand, discard have none of selected card\n", 
        (fullDeckCount(0, 1, &fullDecksState) == 0) ? "PASS" : "FAIL");

    fullDecksState.deck[0][fullDecksState.deckCount[0] - 1] = 1;
    fullDecksState.hand[0][fullDecksState.handCount[0] - 1] = 1;
    fullDecksState.discard[0][fullDecksState.discardCount[0] - 1] = 1;
    printf("fullDeckCount(): %s deck, hand, discard have one of selected card\n",
        (fullDeckCount(0, 1, &fullDecksState) == 3) ? "PASS" : "FAIL");

    printf("fullDeckCount(): %s deck, hand, discard have (all - 1) of selected card\n",
        (fullDeckCount(0, 0, &fullDecksState) == fullDecksState.deckCount[0] - 1 +
            fullDecksState.handCount[0] - 1 + fullDecksState.discardCount[0] - 1) 
        ? "PASS" : "FAIL");

    /* Empty deck state */
    emptyDecksState.deckCount[0] = 0;
    emptyDecksState.handCount[0] = 0;
    emptyDecksState.discardCount[0] = 0;
    printf("fullDeckCount(): %s check for curse card on empty deck\n",
        (fullDeckCount(0, 0, &emptyDecksState) == 0) ? "PASS" : "FAIL");
    
    /* Deck with 1 member */
    singleCardDecksState.deckCount[0] = 1;
    singleCardDecksState.handCount[0] = 1;
    singleCardDecksState.discardCount[0] = 1;
    singleCardDecksState.deck[0][0] = 1;
    singleCardDecksState.hand[0][0] = 1;
    singleCardDecksState.discard[0][0] = 1;
    printf("fullDeckCount(): %s check for card that exists\n",
        (fullDeckCount(0, 1, &singleCardDecksState) == 3) ? "PASS" : "FAIL");
    printf("fullDeckCount(): %s check for card that is absent\n",
        (fullDeckCount(0, 0, &singleCardDecksState) == 0) ? "PASS" : "FAIL");

    return 0;
}
