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
    int result1,result2,result3, result4, result5, result6;
    
    struct gameState game;
    
    initializeGame(numPlayer, k, seed, &game); // initialize a new game
    //memcpy (&G, &H, sizeof(struct gameState));
    
    srand(time(NULL));
    int random;
    int i;
    int j = 5;
    int n;
    
    printf("\n");
    printf("*------------------------- Card Test #1 -------------------------*\n\n");
    printf("Testing Smithy card function. Function must add three cards from the  \n");
    printf("deck to the hand and discard one card from the hand. \n");
    
    //Fill up the deck with random supply cards.
    for(i=0; i < 30; i++){
        random = rand() % 26;
        game.deck[0][j] = random;
        game.deckCount[0]++;
        j++;
    }
    
    /*Test the pre and post state of variables handCount, deckCount, and playedCardCoutn.*/
    for(n=0; n < 10; n++){
        printf("Pass: %d\n", n);
        result1 = game.handCount[0];
        printf("Number of cards in hand: %d\n", result1);
        
        result2 = game.deckCount[0];
        printf("Number of cards in deck: %d\n", result2);
        
        result3 = game.playedCardCount;
        printf("Number of cards in played pile: %d\n", result3);
        
        printf("Calling Smithy function!\n");
        callSmithy(0, 2, &game);
        
        result4 = game.handCount[0];
        printf("Number of cards in hand: %d\n", result4);
        result4 -= 2;
        assert(result1 == result4);
        
        result5 = game.deckCount[0];
        printf("Number of cards in deck: %d\n", result5);
        result5 += 3;
        assert(result2 == result5);
        
        result6 = game.playedCardCount;
        printf("Number of cards in played pile: %d\n", result6);
        result6 -= 1;
        assert(result3 == result6);
        
        // Decrease the handCount back to 5.
        game.handCount[0]--;
        game.handCount[0]--;
    }

  
    printf("All cardtest #1 tests passed! \n");
    return 0;
}

