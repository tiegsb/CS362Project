/*
 * Jason Gourley
 * gourleja@oregonstate.edu
 * CS362-400
 * Assignment 4 - randomtestadventurer.c
 * Description : Random tests for Adventurer card
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dominion.h"
#include "rngs.h"

#define CARDNAME    "adventurer"
#define BASESEED    10
#define TESTNUMBER  500

/*
 * Description:     Create a random array of kingdom cards, always including the card under test
 * Preconditions:   The card array pointer and size has been provided
 * Postconditions:  The randomly generated hand of cards is returned to the calling function
 */
void randomCardSetup(int * kingdomCards, int setupSize)
{
    int i;

    kingdomCards[0] = CARDNAME; // Ensure card to test is always in the set of cards

    for (i = 1; i<setupSize; i++)
    {
        int cardCheck = 0;
        while(cardCheck == 0)
        {
            int testCard = rand()%20 + 7; // 20 kingdom cards available starting at the seventh position
            if (testCard == CARDNAME) // Check for duplication of the card under test
            {
                cardCheck = 0;
            } else // Check cards that are already pulled into the available set
            {
                kingdomCards[i] = testCard;
                int j;
                for (j = 0; j < i; j++)
                {
                    if(kingdomCards[j] == testCard)
                    {
                        cardCheck = 0;
                        break;
                    } else
                    {
                        cardCheck = 1;
                    }
                }
            }
        }
    }
    return;
}


/*
 * Description:     Create a fully random game
 * Preconditions:   The game struct has been provided
 * Postconditions:  The new game is created with a full set of random values
 */
void randomGame(struct gameState *state)
{
    int testSeed = rand()%50000;
    int testPlayers = rand()%2 + 2;
    int cards[10];
    randomCardSetup(cards, 10);
    initializeGame(testPlayers, cards, testSeed, state);
    return;
}

/*
 * Description:     Test the return values of the adventurer card
 * Preconditions:   The games state has been initialized, the seed and method name to test are passed
 * Postconditions:  The general messages and any failed test messages are displayed
 */
int testCard(char* currentTest, int seed, struct gameState *state)
{
    int i;
    int testsPassed = 0;
    int testsFailed = 0;
    int expectedValue = 0;

    printf ("\n\n-------------------------------------------------------------------------------\n");
    printf ("-------------------------------------------------------------------------------\n");
    printf ("Testing Method  : %s()\n", currentTest);

    int currentPlayer = whoseTurn(state);
    int drawntreasure=0;
    int handPos = 0;
    int temphand[MAX_HAND];// moved above the if statement
    int z = 0;// this is the counter for the temp hand
    int cardDrawn;

    //Check reduction of cards in hand
    for (i=0; i<TESTNUMBER;i++){
        randomGame(state);
        expectedValue = state->handCount[state->whoseTurn] - 1;
        cardAdventurer(temphand, z, cardDrawn, drawntreasure, handPos, state->whoseTurn, state);
        if(state->handCount[state->whoseTurn] < expectedValue) {
            printf("  TEST FAIL    : Adventurer remove card from hand failed\n");
            testsFailed++;
        } else {testsPassed++;}
    }


    //Check addition of cards to hand
    for (i=0; i<TESTNUMBER;i++){
        randomGame(state);

        state->handCount[state->whoseTurn] = rand()%10;

        expectedValue = state->handCount[state->whoseTurn];
        cardAdventurer(temphand, z, cardDrawn, drawntreasure, handPos, state->whoseTurn, state);
        if(state->handCount[state->whoseTurn] - expectedValue > 1) {
            printf("  TEST FAIL    : Adventurer add correct number of cards to hand failed : ev = %i , actual = %i\n", expectedValue, state->handCount[state->whoseTurn]);
            testsFailed++;
        } else {testsPassed++;}
    }

int j;

    for (i=0; i<TESTNUMBER;i++){
        //Check hand size with lack of treasure cards to add to hand
        randomGame(state);

        state->deckCount[state->whoseTurn] = rand()%20;
        state->handCount[state->whoseTurn] = rand()%10;
        int card = 0;
        for (j = 0; j < TESTNUMBER; j++)
        {
          state->deck[state->whoseTurn][i] = card;
          state->discard[state->whoseTurn][i] = card;
        }
        expectedValue = state->handCount[state->whoseTurn] - 1;
        if (expectedValue == -1) {expectedValue++;}
        cardAdventurer(temphand, z, cardDrawn, drawntreasure, handPos, state->whoseTurn, state);
        if(state->handCount[state->whoseTurn] != expectedValue) {
            printf("  TEST FAIL    : Adventurer no treasure available but cards to hand failed : ev = %i , actual = %i\n", expectedValue, state->handCount[state->whoseTurn]);
            testsFailed++;
        } else {testsPassed++;}
    }

    printf ("    Tests Passed    : %i\n", testsPassed);
    printf ("    Tests Failed    : %i\n", testsFailed);
    printf ("-------------------------------------------------------------------------------\n\n");

    return 0;
}


/*
 * Preconditions:   The user can pass a seed value for testing or it defaults to a set value
 * Postconditions:  Exit the test program normally
 */
int main (int argc, char** argv)
{

    // Setup Game Seed
    srand(time(NULL));
    int seed;
    char* currentTest = CARDNAME;
    if(argv[1]) {
        seed = atoi(argv[1]);
    } else {
        seed = BASESEED;
    }

    // Initialize Game State
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    initializeGame(2, k, seed, &G);

    testCard(currentTest,seed, &G);

    return 0;
}
