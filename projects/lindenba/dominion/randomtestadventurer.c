#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include "rngs.h"




#define MAX_TESTS 10000


int main () {
    
    int i, n, r, p, players, player, deckCount, discardCount, handCount, seed, handPos;
    int cardDrawn, drawntreasure, tempcoins, card;
    
    int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};
    
    struct gameState game1;
    
    
    
    printf ("RANDOM TESTS.\n");
    
    
    for (n = 0; n < MAX_TESTS; n++) {
        
        //random players
        players = rand() % 4;
        seed = rand();
        
        //initialize player
        initializeGame(players, k, seed, &game1);
        
        player = game1.whoseTurn;
        
        for(i = 0; i< 500; i++)
        {
            drawntreasure = rand() % 9;
            
            tempcoins = game1.coins;
            
            card = cardAdventurer(&game1);
            if(tempcoins > game1.coins)
            {
                printf("error: tempcoins %d game1.coins %d\n", tempcoins, game1.coins);
            }
        }
        
       
    }
    
    printf("All Tests ok\n");
    
    return 0;
}