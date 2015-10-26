#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include <time.h>
// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1


int main()
{
    srand(time(NULL));
    int randNum = rand() % 10;

    int gardenCalc;
    int i = 0;
    int j = 0;
    int pass = 0;
    int fail = 0;

    int p = 2;
    int numPlayers = 3;
    int seed = 1000;
    int kings[10] = {adventurer, council_room, feast, gardens, mine,
                     remodel, smithy, village, baron, great_hall};
    int score;

    struct gameState G;

    initializeGame(numPlayers, kings, seed, &G);
    printf("*****Testing scoreFor function*****\n");

    G.deckCount[p] = 0;
    for (j = 0; j < randNum; j++)
    {
        G.deck[p][j] = estate;
        G.deckCount[p]++;
    }
    printf("Estate score is %d; expected score is %d\n", randNum, (randNum * 1));
    score = scoreFor(p, &G);
    if(score == (randNum * 1))
    {
        printf("Test passed\n");
        pass++;
    }
    else
    {
        printf("Test failed\n");
        fail++;
    }

    G.deckCount[p] = 0;
    for (j = 0; j < randNum; j++)
    {
        G.deck[p][j] = duchy;
        G.deckCount[p]++;
    }
    printf("Duchy score is %d; expected score is %d\n", randNum, (randNum * 3));
    score = scoreFor(p, &G);
    if(score == (randNum * 3))
    {
        printf("Test passed\n");
        pass++;
    }
    else
    {
        printf("Test failed\n");
        fail++;
    }

    G.deckCount[p] = 0;
    for (j = 0; j < randNum; j++)
    {
        G.deck[p][j] = province;
        G.deckCount[p]++;
    }
    printf("Province score is %d; expected score is %d\n", randNum, (randNum * 6));
    score = scoreFor(p, &G);
    if(score == (randNum * 6))
    {
        printf("Test passed\n");
        pass++;
    }
    else
    {
        printf("Test failed\n");
        fail++;
    }

    G.deckCount[p] = 0;
    for (j = 0; j < randNum; j++)
    {
        G.deck[p][j] = curse;
        G.deckCount[p]++;
    }
    printf("Curse score is %d; expected score is %d\n", randNum, (randNum * (-1)));
    score = scoreFor(p, &G);
    if(score == (randNum * (-1)))
    {
        printf("Test passed\n");
        pass++;
    }
    else
    {
        printf("Test failed\n");
        fail++;
    }

    G.deckCount[p] = 0;
    for (j = 0; j < randNum; j++)
    {
        G.deck[p][j] = great_hall;
        G.deckCount[p]++;
    }
    printf("Great hall score is %d; expected score is %d\n", randNum, (randNum * 1));
    score = scoreFor(p, &G);
    if(score == (randNum * 1))
    {
        printf("Test passed\n");
        pass++;
    }
    else
    {
        printf("Test failed\n");
        fail++;
    }

    G.deckCount[p] = 0;
    for (j = 0; j < randNum; j++)
    {
        G.deck[p][j] = gardens;
        G.deckCount[p]++;
    }
    gardenCalc = fullDeckCount(0, 0, &G);
    printf("Garden score is %d; expected score is %d\n", randNum, (randNum * gardenCalc / 10));
    score = scoreFor(p, &G);
    if(score == (randNum * (randNum * gardenCalc / 10)))
    {
        printf("Test passed\n");
        pass++;
    }
    else
    {
        printf("Test failed\n");
        fail++;
    }

//    for (i = 0; i < numPlayers; i++):q
//    {
        i = 1;
        G.deckCount[i] = 0;
        for (j = 0; j < 3; j++)
        {
            G.deck[i][j] = estate;
            G.deckCount[i]++;
        }
        for (j = 3; j < 6; j++)
        {
            G.deck[i][j] = duchy;
            G.deckCount[i]++;
        }
        for (j = 6; j < 9; j++)
        {
            G.deck[i][j] = province;
            G.deckCount[i]++;
        }
        for (j = 9; j < 12; j++)
        {
            G.deck[i][j] = curse;
            G.deckCount[i]++;
        }
        for (j = 12; j < 15; j++)
        {
            G.deck[i][j] = great_hall;
            G.deckCount[i]++;
        }
        for (j = 15; j < 18; j++)
        {
            G.deck[i][j] = gardens;
            G.deckCount[i]++;
        }
//    }
    score = scoreFor(i, &G);
    gardenCalc = fullDeckCount(i, 0, &G);
    printf("gardenCalc is %d \n", gardenCalc);
    int calcScore;
    calcScore = (3 * 1) + (3 * 3) + (3 * 6) + (3 * (-1)) + (3 * 1) + (3 * (gardenCalc % 10));
    printf("Calculated score is %d; expected score is %d\n", score, calcScore);
    if(score == calcScore)
    {
        printf("Test passed\n");
        pass++;
    }
    else
    {
        printf("Test failed\n");
        fail++;
    }
    printf("%d tests passed, %d tests failed\n", pass, fail);

    printf("\n");

    return 0;
}
