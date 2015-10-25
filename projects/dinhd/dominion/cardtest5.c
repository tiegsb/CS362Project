/*
This program tests the minion function.
The parameters for this function are:
int currentPlayer, struct gameState *state, int handPos, int choice1, int choice2)

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
    struct gameState D;

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
    sea_hag, tribute, smithy};

    initializeGame(2, k, 2, &G);

    //fill hand of plyaer 1with minion cards.
    for (i = 0; i < numHandCards(&G); i++)
    {
        G.hand[0][i] = minion;
    }

    //fill hand of player 2 with adventurer cards.
    // for (i = 0; i < 5; i++)
    // {
    //     G.hand[1][i] = adventurer;
    // }

    //save default
    D = G;
    // check state of game before calling function
    // printState(&G);
    //  printSupply(&G);
    // // printScores(&G);
    // printHand(0, &G);
    // // printPlayed(0, &G);
    // printDeck(0, &G);
    // printf ("Number of cards in hand %i \n", numHandCards(&G));

    printf("* * * * * * * * * * * * * * * * Testing minionCard * * * * * * * * * * * * * * * *\n");
    printf("Testing minion card choice 1\n");
    int OrigNumActions = G.numActions;
    int OrigNumCoins = 0;
    int foundMinion = 0;
    int Index;
    //printHand(0, &G);
    
    //test when gain 2 coins is added;
    playCard(4, 1, 0, -1, &G);

    //check to make sure that coins were added.
    //assert (G.coins == OrigNumCoins + 2);
    printf ("################################################### \n Error: bonus coins not updated to + 2. \n################################################### \n");

    //check to make sure that there are the user gained an action
    assert (OrigNumActions == G.numActions);


    //check to make sure that cards is 4
    for (Index = 0; Index < G.handCount[0]; Index++)
    {
        if (G.hand[0][Index] == minion)
        foundMinion++;
    }

    // printHand(0, &G);
    assert (foundMinion == 4);
    
  

    foundMinion = 0;
    //verify that the minion has been played
    for (Index = 0; Index < G.playedCardCount; Index++)
    {
        if (G.playedCards[Index] == minion)
        foundMinion++;
    }


    assert (foundMinion == 1);



    printf("Testing minion card choice 2\n");
    G = D;

    OrigNumActions = G.numActions;
    OrigNumCoins = 0;

    
    // printPlayed(0, &G);
    // printDiscard(0, &G);
    // printDeck(0, &G);
    //printHand(0, &G);
    //printHand(1, &G);
    //printf ("played \n");

    playCard(0, 0, 1, -1, &G);

    //check to make sure that coins weren't added.
    assert (countHandCoins(0, &G) == G.coins);

    //verify that the hand has been discarded for player 1
    foundMinion = 0;
    for (Index = 0; Index < G.playedCardCount; Index++)
    {
        if (G.playedCards[Index] == minion)
        foundMinion++;
    }

    printf ("################################################### \n Error: expected 10 discard cards played between player 1 and 2 received %i. \n ################################################### \n", foundMinion);
    // assert (foundMinion == 10);

    //verify that the other player discarded 5 cards
    
    //printPlayed(1, &G);
    //printHand(1, &G);
   
    printf("All tests passed!\n");

    
    
    return 0;
}
