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
    int result1,result2,result3, result4, result5, result6;
    
    struct gameState game;
    
    initializeGame(numPlayer, k, seed, &game); // initialize a new game
    //memcpy (&G, &H, sizeof(struct gameState));
    
    int i;
    int n;
    int r;
    int random;
    
    printf("\n");
    printf("*------------------------- Random Test card -------------------------*\n\n");
    printf("Testing Smithy card function. Function must add three cards from the  \n");
    printf("deck to the hand and discard one card from the hand. \n");
    
    //Fill up the deck with random supply cards.

    /*Test the pre and post state of variables handCount, deckCount, and playedCardCoutn.*/
    
    for(n=0; n < 25; n++){
    
        game.handCount[0] = 5;
        
        r = rand() % 30;
        
        game.deckCount[0] = r;
        
        for(i=0; i < r; i++){
            random = rand() % 26;
            game.deck[0][i] = random;
        }
        
        random = rand() % 30;
        game.playedCardCount = random;
        
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
        if(result1 != result4){
            printf("Bug found! Hand count is not increased by two.\n");
        }
        else{
            printf("Hand count is increased by two.\n");
        }
        
        result5 = game.deckCount[0];
        printf("Number of cards in deck: %d\n", result5);
        result5 += 3;
        if(result2 != result5){
            printf("Bug found! Deck count is not decreased by three.\n");
        }
        else{
            printf("Deck count is decreased by three.\n");
        }
        
        result6 = game.playedCardCount;
        printf("Number of cards in played pile: %d\n", result6);
        result6 -= 1;
        assert(result3 == result6);
        
        // Decrease the handCount back to 5.
        game.handCount[0]--;
        game.handCount[0]--;
    }

  
    printf("All testing is done! \n");
    return 0;
}

