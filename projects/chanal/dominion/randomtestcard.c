/***********************************************
 * Author: Allan Chan
 * ONID: chanal
 * class: CS362
 * Filename: randomtestcard.c
 * Description:
 *  Random testing for smithy card effects
 *  Smithy when played allows plays +3 cards
 * **********************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "interface.c"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int gameSeed = rand();
    int p;
    int numPlayer = 4;
    int i = 0, n;
    int error1 = 0, error2 = 0;
    int randomIt = (rand() % 10000) + 20001;  
    int k[10] = {adventurer, council_room, feast, gardens, mine,
                remodel, smithy, village, baron, great_hall};
    int iteration = 0;

    struct gameState G;
    
    printf("\nStarting random testing for Smithy card effects...\n");

    for(n = 0; n < randomIt; n++){
        int randNum = rand() %3;
        p = floor(Random() * 4);

        memset(&G, 23, sizeof(struct gameState));   //clear game state
        initializeGame(numPlayer, k, gameSeed, &G); //initialize game

        /*Randomly choose a deckcount from 0, -1, to MAX_DECK to induce shuffling*/
        if(randNum == 0){
            G.deckCount[p] = 0;
        } else if(randNum == 1) {
            G.deckCount[p] = -1;
        } else {
            G.deckCount[p] = floor(Random() * MAX_DECK);
        }
        G.discardCount[p] = floor(Random() * MAX_DECK);
        G.playedCardCount = floor(Random() * MAX_DECK);


        /*Set up deck, hand, discard*/
        for(i = 0; i < G.deckCount[p]; i++){
            G.deck[p][i] = floor(Random() * 5);
        }
        for(i = 0; i < G.discardCount[p]; i++){
            G.discard[p][i] = floor(Random() * 5);
        }

        G.handCount[p] = 1; //set player handcount to 1
        G.hand[p][0] = smithy;    //set player's only card in hand to council room for testing purposes

        struct gameState pre;
        struct gameState post = G;


        pre.handCount[p] = G.handCount[p];   //handcount before smithy
    
        smithyCard(p, &G, 0);   //play smithy from hand pos 0

        post.handCount[p] = G.handCount[p];  //handcount after smithy
        post.hand[p][0] = G.hand[p][0];   //post hand card at hand pos 0

        printf("\nTesting iteration: %d...\n", iteration++);


        /*Check hand count after smithy played, +2 since smithy should be discarded*/
        if(pre.handCount[p] + 2 == post.handCount[p]){
            printf("TEST PASSED - obtained correct number of cards\n");
        } else {
            printf("TEST FAILED - did not obtain correct number of cards %d\n", post.handCount[p]);
            error1++;
        }

        /*Check hand if smithy is still there*/
        if(post.hand[p][0] == smithy){
            printf("TEST FAILED - smithy was not discarded\n");
            error2++;
        } else {
            printf("TEST PASSED - smithy is discarded from hand\n");
        }

    }

    /*Print summary of random test results*/
    if(error1 == 0){
        printf("\nAll %d test1 passed, player obtained correct number of cards\n", randomIt);
    } else {
        printf("\nTest1 error count: incorrect number of cards drawn %d of %d tests\n", error1, randomIt);
    }

    if(error2 == 0){
        printf("All %d test2 passed, smithy was discarded from hand\n\n", randomIt);
    } else {
        printf("Test2 error count: smithy not discarded from hand %d of %d tests\n\n", error2, randomIt);
    }

    return 0;

}

