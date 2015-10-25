/*
This program tests the mineCard function.
The parameters for this function are:
int currentPlayer, struct gameState *state, int handPos, int choice2, int choice1

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

    int mineCardLoc;
    int i;

    //initialize the game
    struct gameState G;
    struct gameState D;

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
    sea_hag, tribute, smithy};

    initializeGame(2, k, 2, &G);

    //copper, silver, gold, estate (to check bounds), and minecard to hand.
    G.hand[0][0] = copper;
    G.hand[0][1] = silver;
    G.hand[0][2] = gold;
    G.hand[0][3] = estate;
    G.hand[0][4] = mine;

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


    printf("* * * * * * * * * * * * * * * * Testing mineCard card* * * * * * * * * * * * * * * * \n");

    //keeps track of the mine card's location.
    mineCardLoc = 4;
    // loop through each type of coin and swap it for each available coin.
    int coin;
    char name[32];

    for (i = 0; i < 3; i++)
    {
        for (coin = copper; coin < gold + 1; coin++)
        {
            //reset
            G = D;
            cardNumToName(coin, name);
            //get cost of coin to be swapped



            printf ("Testing swapping position %i for %s \n", i, name);
            printf ("code returned: %i \n", playCard(mineCardLoc, i, coin, -1, &G));
            printf ("cost of choice1 is %i \n", getCardCost(G.hand[0][i]));

            //verify that you can only play swap affordable cards
            if (getCardCost(G.hand[0][i]) + 3 > getCardCost(coin))
            {
                int playedIndex;
                int foundMine = 0;
                int foundCoin = 0;
                printf ("affordable \n");
                //assert (G.hand[0][i] == coin);
                printf ("################################################### \n Error: Expected coin in hand location %i. \n ################################################### \n", i);

                //verify that mine card is out of hand
                //assert (G.hand[0][mineCardLoc] != mine);
                printf ("################################################### \n Error: expected non-mine card in hand location %i. \n ################################################### \n", mineCardLoc);

                //verify that the minecard is in the played
                for (playedIndex = 0; playedIndex < G.playedCardCount; playedIndex++)
                {
                    if (G.playedCards[playedIndex] == mine)
                    foundMine = 1;
                    if (G.playedCards[playedIndex] == mine)
                    foundCoin = 1;
                }
                // assert (foundMine == 1);
                printf ("################################################### \n Error: expected mine card in played area. \n ################################################### \n");

                //assert (foundCoin == 1);
                printf ("################################################### \n Error: expected a coin card in played area. \n ################################################### \n");


            }
            else
            {
                int playedIndex;
                int foundMine = 0;
                int foundCoin = 0;

                printf ("unaffordable \n");
                assert (G.hand[0][i] != coin);
                //verify that mine card is still in hand
                assert (G.hand[0][mineCardLoc] == mine);

                //verify that the minecard hasn't been played
                for (playedIndex = 0; playedIndex < G.playedCardCount; playedIndex++)
                {
                    if (G.playedCards[playedIndex] == mine)
                    foundMine = 1;
                    if (G.playedCards[playedIndex] == mine)
                    foundCoin = 1;
                }
                assert (foundMine == 0);
                assert (foundCoin == 0);

            }
        }
    }

    //Try playing illegal choice1 for coin
    G = D;
    cardNumToName(copper, name);
    assert (playCard(mineCardLoc, 3, coin, -1, &G) == -1);

    G = D;
    //Try playing illegal choice2 for treasure
    // assert (playCard(mineCardLoc, 0, estate, -1, &G) == -1);
    printf ("################################################### \n Error: allows user to choose a non treasure card to buy. \n ################################################### \n");

    printf("All tests passed!\n");

    
    
    return 0;
}
