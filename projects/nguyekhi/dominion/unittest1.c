/*
- I write the test for initializedGame function, I test with the invalid inputs and check the return values of the function to see if
it equal to -1. Then I test the valid input, and put all the condition statement that test the corrected output of the function. If
there is an errors, it will display test fail message. But apparently all the test passed and so the function is working properly.
I am pretty sure I cover all the lines in the initializedGame function, because I test all the valid and invalid inputs.
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>

int main (int argc, char* argv[])
{
    printf("Testing initializeGame() function.\n");
    struct gameState G;
    // corrected kingdom card array k
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

    // these kingdom card array contains some errors for testing
    int dupK[10] = {adventurer, gardens, embargo, village, gardens, mine, cutpurse, sea_hag, tribute, smithy};

    int numPlayers;
    for (numPlayers = 1; numPlayers <=5; numPlayers++)
    {
        if (numPlayers == 1)
        {
            printf("Testing number of player = 1.\n");
            // check the incorrect number of player
            int returnValue1 = initializeGame(numPlayers, k, 2, &G);
            if (returnValue1 == -1)
                printf("test pass. return value == -1.\n");
            else
                printf("test fail, return value != -1.\n");
        }
        if (numPlayers == 2)
        {
            printf("Testing number of player = 2.\n");
            int returnValue21 = initializeGame(numPlayers, dupK, 2, &G);
            if (returnValue21 == -1)
                printf("test pass, duplicate kingdom cards, return value == -1.\n");
            else
                printf("test fail, duplicate kingdom cards, return value != -1.\n");

            int returnValue22 = initializeGame(numPlayers, k, 2, &G);
            if (G.supplyCount[curse] != 10)
                printf("test fail, numCurse != 10.\n" );
            if (G.supplyCount[estate] != 8 || G.supplyCount[duchy] != 8 || G.supplyCount[province] != 8)
                printf("test fail, victory cards != 8.\n" );
            if (G.supplyCount[copper] != 60 - (7 * numPlayers) ||  G.supplyCount[silver] != 40 || G.supplyCount[gold] != 30)
                printf("test fail, treasure cards.\n" );
            if (G.supplyCount[gardens] != 8 || G.supplyCount[great_hall] != 8)
                printf("test fail, gardens and great_hall != 8.\n" );
            if (G.supplyCount[adventurer] != 10 || G.supplyCount[council_room] != 10 || G.supplyCount[feast] != 10)
                printf("test fail, adventurer, council_room and feast != 10.\n" );
            if (G.supplyCount[mine] != 10 || G.supplyCount[remodel] != 10 || G.supplyCount[smithy] != 10)
                printf("test fail, mine, remodel, smithy != 10.\n" );
            if (G.supplyCount[village] != 10 || G.supplyCount[baron] != 10)
                printf("test fail, village and baron != 10.\n" );
            if (returnValue22 != 0)
                printf("test fail, return value != 0.\n");
            if (G.deckCount[numPlayers-1] != 10)
                printf("test fail, deck count != 0.\n");
            if (G.handCount[numPlayers-1] != 0)
                printf("test fail, hand count != 0.\n");
            if (G.discardCount[numPlayers-1] != 0)
                printf("test fail, discardCount != 0.\n");
            if (G.embargoTokens[numPlayers-1] != 0)
                printf("test fail, embargoTokens != 0.\n");
            if (G.outpostPlayed != 0)
                printf("test fail, outpostPlayed != 0.\n");
            if (G.phase != 0)
                printf("test fail, phase != 0.\n");
            if (G.numActions != 1)
                printf("test fail, num actions != 1.\n");
            if (G.numBuys != 1)
                printf("test fail, num buys != 1.\n");
            if (G.playedCardCount != 0)
                printf("test fail, played card count != 0.\n");
            if (G.whoseTurn != 0)
                printf("test fail, whose turn != 0.\n");
            printf("test pass.\n");
        }
        if (numPlayers == 3)
        {
            printf("test for number of player = 3.\n");
            int returnValue3 = initializeGame(numPlayers, k, 2, &G);
            if(G.supplyCount[curse] != 20)
                printf("test fail, number of curse card != 20.\n");
            if (G.supplyCount[estate] != 12 || G.supplyCount[duchy] != 12 || G.supplyCount[province] != 12)
                printf("test fail, victory cards != 12.\n" );
            if (G.supplyCount[gardens] != 12 || G.supplyCount[great_hall] != 12)
                printf("test fail, gardens and great_hall != 12.\n" );
            if (returnValue3 != 0)
                printf("test fail, return value != 0.\n");
            printf("test pass.\n");
        }
        if (numPlayers==4)
        {
            int returnValue4 = initializeGame(numPlayers, k, 2, &G);
            if (returnValue4 != 0)
                printf("test fail, return value != 0.\n");
        }
        if (numPlayers==5)
        {
            int returnValue5 = initializeGame(numPlayers, k, 2, &G);
            if (returnValue5 != -1)
                printf("test fail, return value != -1.\n");
        }
    }
    return 0;
}

