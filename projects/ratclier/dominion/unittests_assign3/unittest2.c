#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "unittest_helpers.h"


// Test the gainCard() function.
//
// Checks for an ample supply of cards first, and if one exists, adds a
// specific card to a player's hand, deck, or trash.
//
// supplyPos - enumerated card
// state     - holds the game state
// toFlag    - where to put the card (0 = discard, 1 = deck, 2 = hand)
// player    - who to give the card to
//
// Returns -1 if not enough supply or 0 on success
//
int testGainCard(int supplyPos, struct gameState *state, int toFlag, int player)
{
    struct gameState *origState;  // copy of game state
    
    // Make a copy of the original game state
    //
    origState = copyState(state);

    // Run gainCard()
    //
    // Consider changing the supply deck to have insufficient cards to
    // test the exit error (-1). Do that in state before calling this
    // function.
    //
    if(gainCard(supplyPos, state, toFlag, player))
    {
        // Enough cards exist. Continue with testing card movement
        // results.
    }
    else
    {
        // gainCard() exited w/o success. That should mean there are not
        // enough cards in the supply pile (supplyCount(supplyPos, state) < 1).
        //
        if(toFlag == 1)
        {
            if(state->deck[player][origState->deckCount[player]] == supplyPos)
            {
                printf("Test PASSED: Card added to player deck\n");
            }
            else
            {
                printf("Test FAILED: Card not added to player deck\n");
            }

            if(state->deckCount[player] == origState->deckCount[player]+1)
            {
                printf("Test PASSED: Player deck count incremented\n");
            }
            else
            {
                printf("Test FAILED: Player deck count not incremented\n");
            }
        }

        if(state->deck[player][ state->deckCount[player]] == supplyPos)
        {
            printf("Test PASSED: Exited without enough cards, no action taken\n");
        }

        /* From dominion.c code:
         
        if (toFlag == 1)      // DECK
          {
            state->deck[ player ][ state->deckCount[player] ] = supplyPos;
            state->deckCount[player]++;
          }
        else if (toFlag == 2) // HAND
          {
            state->hand[ player ][ state->handCount[player] ] = supplyPos;
            state->handCount[player]++;
          }
        else                  // DISCARD
          {
            state->discard[player][ state->discardCount[player] ] = supplyPos;
            state->discardCount[player]++;
          }
              
        //decrease number in supply pile
        state->supplyCount[supplyPos]--;
        */

    }



    /*
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
*/
    

    return 0;
}


int main(int argc, char *argv[])
{
    int numPlayers = 2;
    int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    int randomSeed = 100;
    struct gameState *state;

    // New game
    //
    state = newGame();
    initializeGame(numPlayers, kingdomCards, randomSeed, state);

    printf("\n");

    // Gain a card w/ an ample supply deck
    //
    printf("Testing: Sufficient supply deck...\n");
    // Make sure state->supplyCount[supplyPos] >= 1
    testGainCard(handPos, state, toFlag, player);

    printf("\n");

    // New game
    //
    state = newGame();
    initializeGame(numPlayers, kingdomCards, randomSeed, state);

    // Gain a card w/ an empty or insufficient supply deck
    //
    printf("Testing: Insufficient supply deck...\n");
    state->supplyCount[supplyPos] = 0;
    testGainCard(handPos, state, toFlag, player);

    return 0;
}



