#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include "rngs.h"



#define MAX_TESTS 800


int main () {
    
    int i, n, r, p, players, player, deckCount, discardCount, handCount, seed, address, handPos;
    int *bonus;
    
    int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};
    
    struct gameState game1;
    struct gameState game2;
    struct gameState game3;

    
    printf ("RANDOM TESTS.\n");
    
   printf("game1 \n");
    for (n = 0; n < MAX_TESTS; n++) {
        //random player
        players = rand() % 4;
        seed = rand();
        
        initializeGame(players, k, seed, &game1);
        
        //initialize variables
        game1.deckCount[player] = rand () % MAX_DECK;
        game1.discardCount[player] = rand () % MAX_DECK;
        game1.handCount[player] = rand () % MAX_HAND;
        
        handCount = game1.handCount[player];
        deckCount = game1.deckCount[player];
        
        cardEffect(smithy, 1, 1, 1, &game1, handPos, 0);
        
        printf("%d , %d, %d\n", n, handCount, deckCount);
    }
    
    printf("game2 \n");
    
    for (n = 0; n < MAX_TESTS; n++) {
        
        
        
        players = rand() % 4;
        seed = rand();

        
        initializeGame(players, k, seed, &game2);
        
        //initialize variables
        game2.deckCount[player] = rand () % MAX_DECK;
        game2.discardCount[player] = rand () % MAX_DECK;
        game2.handCount[player] = rand () % MAX_HAND;
        
        handCount = game2.handCount[player];
        deckCount = game2.deckCount[player];
        
        cardEffect(smithy, 1, 1, 1, &game2, handPos, 0);
        
        printf("%d , %d, %d\n", n, handCount, deckCount);
    }
    printf("game3 \n");
    
    for (n = 0; n < MAX_TESTS; n++) {
        
       
        
        players = rand() % 4;
        seed = rand();
        
        
        
        initializeGame(players, k, seed, &game3);
        
        
        
        //initialize variables
        game3.deckCount[player] = rand () % MAX_DECK;
        game3.discardCount[player] = rand () % MAX_DECK;
        game3.handCount[player] = rand () % MAX_HAND;
        
        handCount = game3.handCount[player];
        deckCount = game3.deckCount[player];
        
        cardEffect(smithy, 1, 1, 1, &game3, handPos, 0);
        
        
        printf("%d , %d, %d\n", n, handCount, deckCount);
    }
    
    return 0;
}
