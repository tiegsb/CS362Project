/*
This program tests the villageCard function.
The parameters for this function are:
struct gameState *state

*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include "interface.h"
#include <stdlib.h>

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {

    int i;

    //initialize the game
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
    sea_hag, tribute, smithy};

    printf ("* * * * * * * * * * * * * * * *  Testing village card.* * * * * * * * * * * * * * * * \n");

    initializeGame(2, k, 2, &G);

    //replace all cards in hand with a village card
    for (i = 0; i < numHandCards(&G); i++)
    {
        G.hand[0][i] = village;
    }
    


    // check state of game before calling function
    // printState(&G);
    //  printSupply(&G);
    // // printScores(&G);
    // printHand(0, &G);
    // printPlayed(0, &G);
    // printDeck(0, &G);
    //printf ("Number of cards in hand %i \n", numHandCards(&G));


    printf("played card \n");

    //keeps track of played cards
    int playedCards = 0;
    for (i = (numHandCards(&G) -1); i >= 0; i--)
    {
        int numActions = G.numActions;
        playCard(i, -1, -1, -1, &G);

        //check to see if village card goes into discard
        //printPlayed(0, &G);

        assert (G.playedCards[playedCards] == village);
        //check to see if number of actions increased by 2
        assert (numActions + 1 == G.numActions);
        //check to see if the is replaced by a drawn card form the deck
        assert (G.hand[0][i] != village);
        // printState(&G);
        // printHand(0, &G);
        // printPlayed(0, &G);
        // printDeck(0, &G);
        playedCards++;
    }

    printf("All tests passed!\n");

    
    
    return 0;
}
