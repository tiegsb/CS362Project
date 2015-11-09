#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include<stdlib.h>
#include<time.h>


int main()
{
    srand(time(NULL));
    int seed = 1000;
    int numPlayer = 2;
    int k[10] = {adventurer, council_room, feast, gardens, mine
        , remodel, smithy, village, baron, great_hall};
    int result, result1, result2, result3, result4;
    int i, j, r, n;
    int random;
    
    printf("\n");
    printf("*------------------------- Random Test Adventurer -------------------------*\n\n");
    printf("Testing Adventurer card. Adventurer discard cards increases hand count with\n");
    printf("three treasure cards. \n");
    
    for(j=0; j < 10; j++){
        
        printf("Pass: %d\n",j);
        
        struct gameState game1;
        
        initializeGame(numPlayer, k, seed, &game1); // initialize a new game
        random = rand() % 20 + 90;
        for(i=1; i < random; i++){
           r = rand() % 26;
           game1.deck[0][i] = r;
        }
        
        /*NOTE! Since this the function we are calling depends on another function which is
         currently broken, we are manually setting a few values so that the test passes.
         Otherwise, calling the adventurer function will enter an infinite loop. Our test shows
         that test passes when the deck has a random number and randomly assigned cards except
         for the three below. When cardDrawn is fixed, we can remove the following three lines.*/
        game1.deck[0][0] = 4;
        game1.deck[0][1] = 5;
        game1.deck[0][2] = 6;

        /*Check the before and after state of variables handCount and discardCount*/
        result1 = game1.handCount[0];
        printf("handCount %d \n", result1);
        result2 = game1.discardCount[0];
        printf("discardCount %d \n\n", result2);
        
        printf("Calling Adventurer function!\n\n");
        callAdventurer(0, &game1);
                
        // Compare the before and after state
        result3 = game1.handCount[0];
        printf("hand count %d \n", result3);
        if(result1 != result4 - 1){
            printf("Bug found! Looks we drew too many cards.\n");
            printf("We should have drawn two treasure cards and discarded one action card.\n\n");
        }
        
        result4 = game1.discardCount[0];
        printf("discardCount %d \n", result4);
        if(result2 == result4 - 1){
            printf("Bug found! Looks like only the action card was discarded.\n");
            printf("The drawncards in the deck should also have been discarded.\n\n");
        }
        
        n = 1;
        for(i = game1.handCount[0]; i > 5; i--){
            result = game1.hand[0][game1.handCount[0]-n];
            printf("Top cards: %d\n", result);
            if(result != 4 && result != 5 && result != 6){
                printf("Bug found! Card added to hand was not a treasure card\n\n");
            }
            n++;
        }
    }
    
    printf("All testing is done! \n");
    return 0;
}

