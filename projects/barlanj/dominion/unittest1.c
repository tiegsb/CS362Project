
/*
    This is a test of the isGameOver() function. The game ends when
    the last Province is bought, or when three supply piles are depleted.
*/

#include <stdbool.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "rngs.h"

#define RESET  "\033[0m"
#define KRED  "\x1B[31m"

void restoreSupply(struct gameState *G);

int main()
{

    int i;
    int total_test = 30;
    int failed_test = 0;

    srand(time(NULL));
    int status = 0;
    int numPlayer = 2;
    int handCount = 5;
    int p = 0;
    int k[10] = {adventurer, council_room, feast, gardens, mine,
                 remodel, smithy, village, baron, great_hall
                };
    int testHand[3] = {copper, copper, village};

    struct gameState G;
    int gameSeed = rand() % 1000 + 1;
    memset(&G, 23, sizeof(struct gameState));
    initializeGame(numPlayer, k, gameSeed, &G);
    memcpy(G.hand[p], testHand, sizeof(int)*handCount);


    /* Test */
    printf("Test 1: Province count = 0 && No supply piles depleted \n");
    restoreSupply(&G);
    G.supplyCount[province] = 0;
    status = isGameOver(&G);
    if(status == 1)  //game is over
    {
        printf("  >> PASSED: ");
    }
    else
    {
        printf(KRED "  >> FAILED: " RESET);
        failed_test++;
    }
    printf("Expected = %d | Actual = %d \n", 1, status);


    printf("Test 2: Province count > 0 && No supply piles depleted \n");
    restoreSupply(&G);
    G.supplyCount[province] = 1;
    status = isGameOver(&G);
    if(status == 0)
    {
        printf("  >> PASSED: ");
    }
    else
    {
        printf(KRED "  >> FAILED: " RESET);
        failed_test++;
    }
    printf("Expected = %d | Actual = %d \n", 0, status);


    printf("Test 3: Province count > 0 && One Supply pile depleted \n");
    restoreSupply(&G);
    G.supplyCount[province] = 1;
    G.supplyCount[adventurer] = 0;
    status = isGameOver(&G);
    if(status == 0)
    {
        printf("  >> PASSED: ");
    }
    else
    {
        printf(KRED "  >> FAILED: " RESET);
        failed_test++;
    }
    printf("Expected = %d | Actual = %d \n", 0, status);


    printf("Test 4: Province count > 0 && Three Supply pile depleted \n");
    restoreSupply(&G);
    G.supplyCount[province] = 1;
    G.supplyCount[adventurer] = 0;
    G.supplyCount[council_room] = 0;
    G.supplyCount[feast] = 0;
    status = isGameOver(&G);
    if(status == 1)
    {
        printf("  >> PASSED: ");
    }
    else
    {
        printf(KRED "  >> FAILED: " RESET);
        failed_test++;
    }
    printf("Expected = %d | Actual = %d \n", 1, status);


    //===================================================
    enum CARD card1;
    enum CARD card2;
    enum CARD card3;
    int j = total_test - 4;
    for(i = 0; i < j; i++)
    {
        //reset
        memset(&G, 23, sizeof(struct gameState));
        initializeGame(numPlayer, k, gameSeed, &G);

        //pick a random card except province
        do
        {
            card1 = (enum CARD)(rand() % 27);
            card2 = (enum CARD)(rand() % 27);
            card3 = (enum CARD)(rand() % 27);
        }
        while( card1 == province || card2 == province || card3 == province || card1 == card2 || card2 == card3 || card1 == card3);

        //deplete the three random supplies
        restoreSupply(&G);
        G.supplyCount[card1] = 0;
        G.supplyCount[card2] = 0;
        G.supplyCount[card3] = 0;

        //check status
        status = isGameOver(&G);

        printf("Test %d: Province count > 0 && [%d] [%d] [%d] depleted \n", i+5, (int)card1, (int)card2, (int)card3);
        if(status == 1)
        {
            printf("  >> PASSED: ");
        }
        else
        {
            printf(KRED "  >> FAILED: " RESET);
            failed_test++;
        }
        printf("Expected = %d | Actual = %d \n", 1, status);

    }

    printf("----------------------------------------------------\n");
    printf("FAILED = %d | PASSED = %d | TOTAL = %d \n", failed_test, total_test-failed_test, total_test);

    return 0;
}

void restoreSupply(struct gameState *G)
{
    int i;
    for(i = 0; i < 27; i++)
    {
        G->supplyCount[i] = 1;
    }
}
