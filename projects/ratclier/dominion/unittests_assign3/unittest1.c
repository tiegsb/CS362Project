#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "unittest_helpers.h"


// Test the discardCard() function
//
int testDiscardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)
{
    struct gameState *origState;  // copy of game state

    // Make a copy of the original game state
    //
    origState = copyState(state);

    // Run discardCard()
    //
    discardCard(handPos, currentPlayer, state, trashFlag);

    // If the card was trashed, the card should not be added to the played
    // card pile and played card count should not increment. Otherwise,
    // add the card to the played card pile and increment the count.
    //
    if(trashFlag >= 1)
    {
        if(state->playedCardCount == origState->playedCardCount)
        {
            printf("Test PASSED: playedCardCount not incremented\n");
        }
        else
        {
            printf("Test FAILED: playedCardCount incremented\n");
        }
    }
    else
    {
        // If the card was NOT trashed, the card SHOULD be added to the played
        // card pile and played card count SHOULD increment
        //
        if(state->playedCardCount == origState->playedCardCount + 1)
        {
            printf("Test PASSED: playedCardCount incremented\n");
        }
        else
        {
            printf("Test FAILED: playedCardCount not incremented\n");
        }

        if(state->playedCards[state->playedCardCount-1] == origState->hand[currentPlayer][handPos])
        {
            printf("Test PASSED: Card added to played card pile\n");
        }
        else
        {
            printf("Test FAILED: Card not added to played card pile\n");
        }
    }

    // Remove the card from the player's hand
    //
    if(handPos == origState->handCount[currentPlayer] - 1)
    {
        if(state->handCount[currentPlayer] == origState->handCount[currentPlayer] - 1)
        {
            printf("Test PASSED: Current player handcount was decremented\n");
        }
        else
        {
            printf("Test FAILED: Current player handcount was not decremented\n");
        }
    }
    else if(origState->handCount[currentPlayer] == 1)
    {
        if(state->handCount[currentPlayer] == origState->handCount[currentPlayer] - 1)
        {
            printf("Test PASSED: Current player handcount was decremented\n");
        }
        else
        {
            printf("Test FAILED: Current player handcount was not decremented\n");
        }
    }
    else
    {
        // Check if discarded card was replaced with last card in hand
        //
        if(state->hand[currentPlayer][handPos] == origState->hand[currentPlayer][(origState->handCount[currentPlayer] - 1)])
        {
            printf("Test PASSED: Discarded card was replaced with last card in hand\n");
        }
        else
        {
            printf("Test FAILED: Discarded card was not replaced with last card in hand\n");
        }

        // Check if last card was set to -1
        //
        if(state->hand[currentPlayer][origState->handCount[currentPlayer] - 1] == -1)
        {
            printf("Test PASSED: Last card set to -1\n");
        }
        else
        {
            printf("Test FAILED: Last card not set to -1\n");
        }

        // Check if the number of cards in hand was reduced
        //
        if(state->handCount[currentPlayer] == origState->handCount[currentPlayer] - 1)
        {
            printf("Test PASSED: Current player handcount was decremented\n");
        }
        else
        {
            printf("Test FAILED: Current player handcount was not decremented\n");
        }
    }
    

    return 0;
}


int main(int argc, char *argv[])
{
    int numPlayers = 2;
    int handPos = 3;
    int currentPlayer = 0;
    int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    int randomSeed = 100;
    int trashFlag;
    struct gameState *state;

    // New game
    //
    state = newGame();
    initializeGame(numPlayers, kingdomCards, randomSeed, state);

    printf("\n");

    // Discard a trashed card
    printf("Testing: Trashed card...\n");
    trashFlag     = 1;   // trashed
    testDiscardCard(handPos, currentPlayer, state, trashFlag);

    printf("\n");

    // New game
    //
    state = newGame();
    initializeGame(numPlayers, kingdomCards, randomSeed, state);

    // Discard a non-trashed card
    printf("Testing: Non-trashed card...\n");
    trashFlag     = 0;   // not trashed
    testDiscardCard(handPos, currentPlayer, state, trashFlag);

    return 0;
}



