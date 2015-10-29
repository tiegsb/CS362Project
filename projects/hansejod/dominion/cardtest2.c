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
    int seed = 1000;
    int numPlayer = 2;
    int k[10] = {adventurer, council_room, feast, gardens, mine
        , remodel, smithy, village, baron, great_hall};
    int result1, result2, result3, result4, result5;
    
    struct gameState game1;
    struct gameState game2;
    
    initializeGame(numPlayer, k, seed, &game1); // initialize a new game
    
    int j;
    
    printf("\n");
    printf("*------------------------- Card Test #2 -------------------------*\n\n");
    printf("Testing Adventurer card. Adventurer discard cards, decreases hand count, \n");
    printf("and suffle cards when deckCount is 0. \n");
    
    int temphand1[10] = {0,0,0,0,0,0,0,0,0,0};
    int temphand2[10] = {0,0,0,0,0,0,0,0,0,0};
    
    memcpy(temphand1, temphand2, sizeof(int));
    
    for(j=0; j < 10; j++){
        
        printf("Pass: %d\n",j);
        
        //Make sure the deck is the same before the function is called
        game1.deckCount[0]=0;
        memcpy (&game2, &game1, sizeof(struct gameState));
        assert(memcmp(&game1, &game2, sizeof(struct gameState)) == 0);
        printf("Card deck is the same before shuffle.\n");
        
        /*Check the before and after state of variables handCount and discardCount*/
        result1 = game1.handCount[0];
        printf("handCount %d \n", result1);
        result2 = game1.discardCount[0];
        printf("discardCount %d \n", result2);
        
        printf("Calling Adventurer function!\n");
        callAdventurer(0, 14, &temphand1, &game1);
        
        if(memcmp(&game1, &game2, sizeof(struct gameState)) == 0){
            printf("Shuffle returns a -1 when the deckcount is 0.\n");
        }
        
        // Compare the before and after state
        result3 = game1.handCount[0];
        printf("hand count %d \n", result3);
        assert(result1 == result3);
        
        result4 = game1.discardCount[0];
        printf("discardCount %d \n", result4);
        if(result2 == result4){
            printf("Bug found! Cards were not discarded.\n");
        }
        
        result5 = memcmp(temphand1, temphand2, sizeof(int));
        if(result5 == 0){
            printf("Bug found! Temp hand is the same before and after function call. %d \n", result5);
        }
    }
    
    printf("All cardtest #2 tests passed! \n");
    return 0;
}
