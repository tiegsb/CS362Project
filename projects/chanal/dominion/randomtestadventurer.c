/***********************************************
 * Author: Allan Chan
 * ONID: chanal
 * class: CS362
 * Filename: randomtestadventurer.c
 * Description:
 *  Random test for adventurer card effects
 *  Tests if adventurer card is still in hand
 *  and if drawntreasure is correct
 *
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

    struct gameState G;
    int drawntreasure = 0;
    int cardDrawn = 0;
    int z = 0;
    int iteration = 0;

    printf("\nStarting random testing for adventurer card effects...\n");

    for(n = 0; n < randomIt; n++){
        int temphand[MAX_HAND];
        int randNum = rand()% 3;

        p = floor(Random() * 4);
       
        initializeGame(numPlayer, k, gameSeed, &G); //initialize game
    
        /*Randomizing deck count to induce shuffling if deck <=0*/
        if(randNum == 0){
            G.deckCount[p] = 0;
        } else if(randNum == 1) {
            G.deckCount[p] = -1;
        } else{
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

        G.handCount[p] = 1; //set players hand count to 1
        G.hand[p][0] = adventurer;  //set players only card in hand to adventurer for testing purposes
    
        /*Play adventurer card with G gameState*/
        adventurerCard(drawntreasure, &G, p, cardDrawn, temphand, z);   

        drawntreasure = 0;

        /*Loop through hand and find all treasure cards, player's '*/
        for(i = 0; i < G.handCount[p]; i++){
             if(G.hand[p][i] == copper || G.hand[p][i] == silver || G.hand[p][i] == gold){
                drawntreasure++;
            }            
        
       }

        printf("\nTesting iteration: %d...\n", iteration++);
        /*Check if adventurer is still in hand, if so error*/
        if(G.hand[p][0] == adventurer){
            printf("TEST FAILED - Adventurer card is not discarded from hand\n");
            error1++;
        }
        /*Check if drawntreasure is not 2, if so error*/
        if(drawntreasure != 2){
            printf("TEST FAILED - drawntreasure count is inccorect\n");
            error2++;
        }

        memset(&G, 23, sizeof(struct gameState));   //clear game state
    }

    /*Print summary of error counts of both tests after testing finishes*/
    if(error1 != 0){
        printf("\nError count for adventurer card in hand and not discarded: %d of %d tests", error1, randomIt);
    }
    if(error2 != 0){
        printf("\nError count for incorrect drawntreasure in hand: %d of %d tests\n\n", error2, randomIt);
    }

    return 0;
}



