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
    int result1,result2,result3, result4, result5, result6, resulta, resultb;
    
    struct gameState game;
    
    initializeGame(numPlayer, k, seed, &game); // initialize a new game
    //memcpy (&G, &H, sizeof(struct gameState));
    
    int i;
    
    printf("\n");
    printf("*------------------------- Card Test #3 -------------------------*\n\n");
    printf("Testing Council Room. Player 1's hand must increase by 3 while player \n");
    printf("2's hand increase by 1. Played pile and numBuys increases by 1. \n");
    
    for(i = 0; i < 10; i++){
        
        printf("Pass: %d\n", i);
        /*Check the before and after state of variables handCount and played pile
         for player 1 and player 2*/
        result1 = game.handCount[0];
        printf("Number of cards in hand player1: %d\n", result1);
        
        result2 = game.playedCardCount;
        printf("Number of cards in played pile player1: %d\n", result2);
        
        result3 = game.handCount[1];
        printf("Number of cards in hand player2: %d\n", result3);
        
        resulta = game.numBuys;
        printf("Number of buys: %d\n", resulta);
        
        printf("Calling CouncilRoom function!\n");
        callCouncilRoom(0, 4, &game);
        
        result4 = game.handCount[0];
        printf("Number of cards in hand player1: %d\n", result4);
        if( result1 != result4 -3){
            printf("Bug found! Hand count of player 1 not increased by 3. \n");
        }
        
        // Compare the before and after state of players 1 and 2
        result5 = game.playedCardCount;
        printf("Number of cards in played pile player1: %d\n", result5);
        result5 -= 1;
        assert(result2 == result5);
        
        result6 = game.handCount[1];
        printf("Number of cards in hand player2: %d\n", result6);
        result6 -= 1;
        assert(result3 == result6);
        
        resultb = game.numBuys;
        printf("Number of buys: %d\n", resultb);
        resultb -= 1;
        if( resulta != resultb){
            printf("Bug found! numBuys is not increased by 1. \n");
        }
    }
    
    printf("All cardtest #3 tests passed! \n");
    return 0;
}