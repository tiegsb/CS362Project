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

// Test the 'endTurn(struct gameState *state)' function

int main () {
    int i, n, players, p_turn, pHand, pDiscard;  // initialize integers used in testing
	       
    struct gameState G;
    
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
    
    
    
    for (n = 0; n < 2000; n++) {
        // set gameState 
        for (i = 0; i < sizeof(struct gameState); i++) {
            ((char*)&G)[i] = rand() % 256; // fill the gameState with random bytes, 0 to 255
        }
        players = (rand() % 3) + 2; // 2 to 4 players in a game
        p_turn = (rand() % players); // set a random players turn
        G.whoseTurn = p_turn;
        G.numPlayers = players;
        for (i = 0; i < players; i++) {
            // Set up proper player hand and deck and discard counts
            G.handCount[i] = 0; // players start with no cards
            G.deckCount[i] = rand() % MAX_DECK; // cards in deck
            G.discardCount[i] = rand() % (MAX_DECK - G.deckCount[i]); // cards in discard
            // total cards should be less than or equal to 500
        }
        pHand = rand() % MAX_HAND; // set a random handCount
        G.handCount[p_turn] = pHand; // Player whose turn could have many cards
        if ((MAX_HAND - pHand) < 2) 
            pDiscard = 0;
        else
            pDiscard = rand() % (MAX_HAND - pHand);
        G.discardCount[p_turn] = pDiscard;
        // Call function
        endTurn(&G);
        assert (G.outpostPlayed == 0);
        assert (G.phase == 0);
        assert (G.numActions == 1);
        assert (G.coins == 0);
        assert (G.numBuys == 1);
        assert (G.playedCardCount == 0);
        assert (G.handCount[p_turn] == 0);
        assert (G.discardCount[p_turn] == (pHand + pDiscard));
        for (i = 0; i < pHand; i++) {
            assert (G.hand[p_turn][i] == -1);
        }
        if (p_turn == (players -1))
            assert (G.whoseTurn == 0);
        else
            assert (G.whoseTurn == (p_turn +1));
        
    }
    
    printf ("All %d tests passed\n", n);
    
    return 0;
}
