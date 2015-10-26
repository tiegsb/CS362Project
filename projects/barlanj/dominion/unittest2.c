/*
    This is a test of the updateCoins() function.
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

int testUpdateCoin(int handCount, int testHand[], int bonus, struct gameState G,
                   int numPlayer, int player, int kingdomCards[], int gameSeed);
void compareResult(int actual, int expected);
void clearTestHand(int testHand[], int handCount);

int main()
{

    srand(time(NULL));
    int actual_result, expected_result ;

    int numPlayer = 2;
    int player = 0;
    int k[10] = {adventurer, council_room, feast, gardens, mine,
                 remodel, smithy, village, baron, great_hall
                };

    int bonus = 0;
    int handCount = 7;
    int testHand[handCount];

    struct gameState G;
    int gameSeed = rand() % 1000 + 1;

    //================================================================
    printf("Test 1: handCount = 7, no treasure cards, no bonus \n");
    clearTestHand(testHand, handCount);

    bonus = 0;
    expected_result = 0;
    actual_result = testUpdateCoin(handCount, testHand, bonus, G,
                                   numPlayer, player, k, gameSeed);

    compareResult(actual_result, expected_result);

    //================================================================
    printf("Test 2: handCount = 7, 2 silver, no bonus \n");

    clearTestHand(testHand, handCount);
    testHand[0] = silver;
    testHand[1] = silver;

    bonus = 0;
    expected_result = 4;
    actual_result = testUpdateCoin(handCount, testHand, bonus, G,
                                   numPlayer, player, k, gameSeed);

    compareResult(actual_result, expected_result);


    //================================================================
    printf("Test 3: handCount = 7, 2 silver, 2 bonus \n");

    clearTestHand(testHand, handCount);
    testHand[0] = silver;
    testHand[1] = silver;

    bonus = 2;
    expected_result = 6;
    actual_result = testUpdateCoin(handCount, testHand, bonus, G,
                                   numPlayer, player, k, gameSeed);

    compareResult(actual_result, expected_result);

    //================================================================
    printf("Test 4: handCount = 7, no treasure, 2 bonus \n");

    clearTestHand(testHand, handCount);

    bonus = 2;
    expected_result = 2;
    actual_result = testUpdateCoin(handCount, testHand, bonus, G,
                                   numPlayer, player, k, gameSeed);

    compareResult(actual_result, expected_result);


    //================================================================
    printf("Test 4: handCount = 7, [3 copper, 3 silver, 1 gold], 0 bonus \n");

    clearTestHand(testHand, handCount);
    testHand[0] = copper;
    testHand[1] = copper;
    testHand[2] = copper;
    testHand[3] = silver;
    testHand[4] = silver;
    testHand[5] = silver;
    testHand[6] = gold;

    bonus = 0;
    expected_result = 12;
    actual_result = testUpdateCoin(handCount, testHand, bonus, G,
                                   numPlayer, player, k, gameSeed);

    compareResult(actual_result, expected_result);


    //================================================================
    printf("Test 5: handCount = 7, [3 copper, 3 silver, 1 gold], 3 bonus \n");

    clearTestHand(testHand, handCount);
    testHand[0] = copper;
    testHand[1] = copper;
    testHand[2] = copper;
    testHand[3] = silver;
    testHand[4] = silver;
    testHand[5] = silver;
    testHand[6] = gold;

    bonus = 3;
    expected_result = 15;
    actual_result = testUpdateCoin(handCount, testHand, bonus, G,
                                   numPlayer, player, k, gameSeed);

    compareResult(actual_result, expected_result);

    return 0;
}

int testUpdateCoin(int handCount, int testHand[], int bonus, struct gameState G,
                   int numPlayer, int player, int kingdomCards[], int gameSeed)
{

    memset(&G, 23, sizeof(struct gameState));
    initializeGame(numPlayer, kingdomCards, gameSeed, &G);
    G.handCount[player] = handCount;
    memcpy(G.hand[player], testHand, sizeof(int)*handCount);

    updateCoins(player, &G, bonus);

    return G.coins;
}

void compareResult(int actual, int expected)
{
    if(actual == expected)
    {
        printf("  >> PASSED: ");
    }
    else
    {
        printf("  >> FAILED: ");
    }

    printf("Expected = %d | Actual = %d \n", expected, actual);
}

void clearTestHand(int testHand[], int handCount)
{
    int i;
    for(i = 0; i < handCount; i++)
    {
        testHand[i] = 0;
    }
}
