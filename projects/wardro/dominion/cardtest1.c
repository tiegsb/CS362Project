#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "rngs.h"

// Smithy Test

int main () {
    int i, j, k, n, x, handcount, discardcount, deckcount, playedcardcount;  // initialize integers used in testing
	       
    struct gameState G;
    
    // start random number generator
    time_t t;
    srand((unsigned) time(&t));
    
    /*
        Initialize a random gameState, but the player number is important. 
        MAX_PLAYERS = 4
        MAX_DECK = 500
        MAX_HAND = 500
        make sure played cards is also less than max
    */
    
    
    
    for (n = 0; n < 2000; n++) {
        // fill the gameState with random bytes, 0 to 255
        printf ("TEST %d\n", n);
        for (i = 0; i < sizeof(struct gameState); i++) {
            ((char*)&G)[i] = rand() % 256; 
        }
        // Set players hands to appropriate sizes
        for (j = 0; j < 4; j++) {
            handcount = rand() % MAX_HAND;
            discardcount = rand() % (MAX_HAND - handcount);
            deckcount = rand() % (MAX_HAND - handcount - discardcount);
            G.handCount[j] = handcount;
            G.discardCount[j] = discardcount;
            G.deckCount[j] = deckcount;
        }
        k = (rand() % 3) + 2; // number of players, 2 to 4
        G.numPlayers = k;
        x = rand() % k; // whose turn
        G.whoseTurn = x;
        playedcardcount = rand() % (MAX_HAND - G.handCount[x] - G.discardCount[x] - G.deckCount[x]);
        handcount = G.handCount[x];
        discardcount = G.discardCount[x];
        deckcount = G.deckCount[x];
        if (handcount > 0 ) {
            k = rand() % G.handCount[x]; // hand position of card to play
            // printf ("On test %d, Hand count = %d, Deck count = %d, discard count = %d\n", n, handcount, deckcount, discardcount);
            assert (0 == playSmithy(k, &G));
            assert (G.handCount[x] == handcount + 3 - 1);
            if (deckcount < 3) {
                assert (G.deckCount[x] == (discardcount - (3 - deckcount)));
                assert (G.discardCount[x] == 0);
            } else {
                assert (G.deckCount[x] == (deckcount - 3));
                assert (G.discardCount[x] == discardcount);
            }
        } else {
            printf ("Handcount < 0, %d\n", playedcardcount);
        }
       assert (playedcardcount + 1 == G.playedCardCount);
        
    }
    
    printf ("All %d tests passed\n", n);
    
    return 0;
}
