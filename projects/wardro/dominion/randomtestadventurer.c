#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1

// Test the adventurer card function

int main () {
    int i, n, players, seed, coins;  // initialize integers used in testing
    int k[10] = {adventurer, council_room, feast, gardens, mine,
	                remodel, smithy, village, baron, great_hall};
    struct gameState G, testG;
    
    // start random number generator
    time_t t;
    srand((unsigned) time(&t));
    
    /*
        Initialize a random gameState, but the player number is important. 
        MAX_PLAYERS = 4
        MAX_HAND 500
        MAX_DECK 500
        set random numPlayers, 2 to 4
        handCount less than 500
        discardCount less than 500 - handCount
    */
    
    
    
    for (n = 0; n < 20000; n++) {
        // set gameState 
        for (i = 0; i < sizeof(struct gameState); i++) {
            ((char*)&G)[i] = rand() % 256; // fill the gameState with random bytes, 0 to 255
        }
        
        // New code
        players = (rand() % 3) + 2; // 2 to 4 players in a game
        seed = rand();
        initializeGame(players, k, seed, &G);
        
            // Assign random cards to hand/discard?
        G.discardCount[G.whoseTurn] = rand() % MAX_DECK;
        G.deckCount[G.whoseTurn] = rand() % (MAX_DECK - G.discardCount[G.whoseTurn]);
        G.handCount[G.whoseTurn] = rand() % (MAX_DECK - G.deckCount[G.whoseTurn]);
        coins = 0;
        for (i = 0; i < G.discardCount[G.whoseTurn]; i++) {
            G.discard[G.whoseTurn][i] = rand() % (treasure_map + 1);
            if (G.discard[G.whoseTurn][i] == copper || G.discard[G.whoseTurn][i] == silver || G.discard[G.whoseTurn][i] == gold) {
                coins++;
            }
        }
        for (i = 0; i < G.deckCount[G.whoseTurn]; i++) {
            G.deck[G.whoseTurn][i] = rand() % (treasure_map + 1);
            if (G.deck[G.whoseTurn][i] == copper || G.deck[G.whoseTurn][i] == silver || G.deck[G.whoseTurn][i] == gold) {
                coins++;
            }
        }
        for (i = 0; i < G.handCount[G.whoseTurn]; i++) {
            G.hand[G.whoseTurn][i] = rand() % (treasure_map + 1);
        }
        // end new code
        memcpy(&testG, &G, sizeof(struct gameState));
        // After memcpy the calls should insue
        // Call function
        //printf("(BEFORE) G.handCount = %d, testG.handCount = %d, coins = %d\n", G.handCount[G.whoseTurn], (testG.handCount[testG.whoseTurn]), coins );
        cardEffect(adventurer, rand(), rand(), rand(), &G, rand(), &seed );
        // playAdventurer(&G);
        if (coins >= 2) {
            assert (G.handCount[G.whoseTurn] == (testG.handCount[testG.whoseTurn] + 2));
        } else {
            assert (G.handCount[G.whoseTurn] == (testG.handCount[testG.whoseTurn] + coins));
            assert (G.deckCount[G.whoseTurn] == 0);
        }
        
        
        
    }
    
    printf ("All %d tests passed\n", n);
    
    return 0;
}
