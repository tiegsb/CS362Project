#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>
#include <stdlib.h>

#define DEBUG 0
#define NOISY_TEST 1

int checkAdventurerCardEffect(struct gameState *post){


    struct gameState pre;
    memcpy (&pre, post, sizeof(struct gameState));


    int drawntreasure=0;
    int cardDrawn, z;
    int currentPlayer = whoseTurn(&pre);
    int temphand[MAX_HAND];

    while(drawntreasure<2){
        if (pre.deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
            shuffle(currentPlayer, &pre);
        }
        drawCard(currentPlayer, &pre);
        cardDrawn = pre.hand[currentPlayer][pre.handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
        if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
            drawntreasure++;
        else{
            temphand[z]=cardDrawn;
            pre.handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
            z++;
        }
    }
    while(z-1>=0){
        pre.discard[currentPlayer][pre.discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
        z=z-1;
    }


    cardEffect(adventurer, -1, -1, -1, post,-1,0);
//    assert(memcmp(&pre, post, sizeof(struct gameState)) == 0);
    if(memcmp(&pre, post, sizeof(struct gameState)) != 0){
        printf("--Test failed\n");
    }

    return 0;
}


int main () {

    int i, n, r, p;

    int k[10] = {adventurer, council_room, feast, gardens, mine,
        remodel, smithy, village, baron, great_hall};

    struct gameState G;

    printf ("TESTING Adventurer Card.\n");

    SelectStream(2);
    PutSeed(3);

    for (n = 0; n < 2000; n++) {
        for (i = 0; i < sizeof(struct gameState); i++) {
            ((char*)&G)[i] = floor(Random() * 256);
        }


        r = initializeGame(2, k, 1, &G);
        p = floor(Random() * 4);
        G.numPlayers = 2 + floor(Random() * 4);         // max 4 player, min 2
        G.deckCount[p] = floor(Random() * MAX_DECK);
        G.discardCount[p] = floor(Random() * MAX_DECK);
        G.handCount[p] = floor(Random() * MAX_HAND);
        G.whoseTurn = p;

        for (i = 0; i < treasure_map; i++) {
            G.supplyCount[i] = floor(Random() * 25);
        }

        for (i = 0; i < G.handCount[p]; i++) {
            G.hand[p][i] = floor(Random() * MAX_HAND);
        }
        for (i = 0; i < G.discardCount[p]; i++) {
            G.discard[p][i] = floor(Random() * MAX_DECK);
        }
        for (i = 0; i < G.deckCount[p]; i++) {
            G.deck[p][i] = floor(Random() * MAX_DECK);
        }

        for (i = 0; i < G.playedCardCount; i++) {
            G.playedCards[i] = floor(Random() * MAX_DECK);
        }


//        printf("Random player: %d    --deckCount:  %d \n", p,G.deckCount[p]);

        checkAdventurerCardEffect( &G);
    }

    printf ("ALL TESTS OK\n");

    return 0;
}
