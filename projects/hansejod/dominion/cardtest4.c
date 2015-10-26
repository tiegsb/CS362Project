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
    int result,result1,result2,result3, result4;
    
    struct gameState game;
    //struct gameState game2
    
    initializeGame(numPlayer, k, seed, &game); // initialize a new game
    //memcpy (&game2, &game1, sizeof(struct gameState));
    
    srand(time(NULL));
    int random;
    int i;
    
    printf("\n");
    printf("*------------------------- Card Test #4 -------------------------*\n\n");
    printf("Testing seaHag. Discarded count for player 1 must go up by one  \n");
    printf("and last card in the deck must change.  \n");
    
    for(i = 0; i < 10; i++){
        
        printf("Pass: %d\n", i);
        
        /*Check the before and after state of last card in deck, number of discarded cards
         for player 1 and player 2, and number of cards in deck for player 1 and 2.*/
        result = game.deck[1][game.deckCount[1]];
        printf("Last card in deck player 2: %d\n", result);
  
        result = game.discardCount[0];
        printf("Number of discarded cards player 1: %d\n", result);
        assert(result == 0);
        result = game.discardCount[1];
        printf("Number of discarded cards player 2: %d\n", result);
        assert(result == i);
    
        result1 = game.deckCount[0];
        printf("Number of cards player 1: %d\n", result1);
    
        result2 = game.deckCount[1];
        printf("Number of cards player 2: %d\n", result2);
        
        printf("Calling SeaHag function!\n");
        callSeaHag(0, &game);
    
        // Compare the before and after state of variables for player 1 and 2
        result = game.deck[1][game.deckCount[1]-3];
        printf("Last card in deck player 2: %d\n", result);
        if( result != 0){
            printf("Bug found! last card for player 2 does not equal 0: %d\n", result);
        }
    
        result = game.discardCount[0];
        printf("Number of discarded cards player 1: %d\n", result);
        assert(result == 0);
        result = game.discardCount[1];
        printf("Number of discarded cards player 2: %d\n", result);
        assert(result != i);
    
        result3 = game.deckCount[0];
        printf("Number of cards player 1: %d\n", result3);
        assert(result1 == result3);
    
        result4 = game.deckCount[1];
        printf("Number of cards player 2: %d\n", result4);
        if( result2-1 != result4){
            printf("Bug found! Deck is decreased by more than 1.\n");
        }
    
    }
    
    printf("All cardtest #4 tests passed! \n");

    
    return 0;
}