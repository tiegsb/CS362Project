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
    int result;
    int random;
    
    srand(time(NULL));
    
    struct gameState game1;
    struct gameState game2;
    
    
    initializeGame(numPlayer, k, seed, &game1);
    
    printf("\n");
    printf("*------------------------- Unit Test #3 -------------------------*\n\n");
    printf("Testing if the deck is the same before and after shuffling. \n");
    printf("Iterations add 5 new cards at a time. \n");
    
    int i,j;

    
    for(i = 0; i < 20; i++){
        
        for ( j = 0; j < 5; j++) {
            random = rand() % 25;
            game1.deck[ 0 ][ game1.deckCount[0] ] = random;
            game1.deckCount[0]++;
        }
        
        // Copy over game1 to game2, call function and compare the pre and post deck
        memcpy (&game2, &game1, sizeof(struct gameState));
 
        assert(memcmp(&game1, &game2, sizeof(struct gameState)) == 0);
        
        printf("Pass: %d, card deck is the same before shuffle.\n",i);
        
        printf("Calling shuffle function!\n");
        shuffle(0,&game1);
   
        assert(memcmp(&game1, &game2, sizeof(struct gameState)) != 0);
        
        printf("Pass: %d, card deck is different after shuffle.\n",i);
        
    }
    
    // Set deck count to 0. Test that shuffle returns 1
        game1.deckCount[0] = 0;
        result = shuffle(0,&game1);
        assert(result == -1);
    
    
    printf("All unit #3 tests passed! \n");
    return 0;
}