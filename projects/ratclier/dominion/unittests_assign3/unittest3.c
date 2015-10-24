#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "unittest_helpers.h"


// Test the updateCoins() function
/*
  //reset coin count
  state->coins = 0;

  //add coins for each Treasure card in player's hand
  for (i = 0; i < state->handCount[player]; i++)
    {
      if (state->hand[player][i] == copper)
        {
          state->coins += 1;
        }
      else if (state->hand[player][i] == silver)
        {
          state->coins += 2;
        }
      else if (state->hand[player][i] == gold)
        {
          state->coins += 3;
        }       
    }   

  //add bonus
  state->coins += bonus;
*/

int testUpdateCoins(int player, struct gameState *state, int bonus)
{
    struct gameState *origState;  // copy of game state
    int coinCount = 0;

    // Make a copy of the original game state
    //
    origState = copyState(state);

    // Run discardCard()
    //
    updateCoins(player, state, bonus);

    for (i = 0; i < state->handCount[player]; i++)
    {
        if (state->hand[player][i] == copper)
        {
            coinCount += 1;
        }
        else if (state->hand[player][i] == silver)
        {
            coinCount += 2;
        }
        else if (state->hand[player][i] == gold)
        {
            coinCount += 3;
        }       
    }   
    
    coinCount += bonus;

    if(state->coins == coinCount)
    {
        printf("Test PASSED: Game state holds correct number of coins.\n");
    }
    else
    {
        printf("Test FAILED: Game state holds incorrect number of coins.\n");
    }

    return 0;
}


int main(int argc, char *argv[])
{
    int player;
    int bonus;
    int numPlayers = 2;
    int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    int randomSeed = 100;
    struct gameState *state;

    // New game
    //
    state = newGame();
    initializeGame(numPlayers, kingdomCards, randomSeed, state);

    printf("\n");

    // Discard a trashed card
    printf("Testing: Player 0's coins, 5 bonus...\n");
    player = 0;
    bonus = 5;
    testUpdateCoins(player, state, bonus);

    printf("\n");

    // New game
    //
    state = newGame();
    initializeGame(numPlayers, kingdomCards, randomSeed, state);

    // Discard a non-trashed card
    printf("Testing: Player 1's coins, 3 bonus...\n");
    player = 0;
    bonus = 5;
    testUpdateCoins(player, state, bonus);

    return 0;
}



