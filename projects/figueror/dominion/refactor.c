Rebecca Figueroa
CS 362 Software Engineering
October 11, 2015

Below are the five cards that I chose to refactor:

adventurer     
smithy   
village
steward    
embargo

I made the following changes to the dominion.c file:

cardEffect() function changes:
    added updated_adventurer function to call and removed original code
    added updated_smithy function to call and removed original code
    added updated_village function to call and removed original code
    added updated_steward function to call and removed original code
    added updated_embargo function to call and removed original code

updated_adventurer() function bugs:
    changed while(drawntreasures<2) to while(drawntreasures<3)
    changed if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold) to if (cardDrawn == copper || cardDrawn == gold || cardDrawn == gold)
    changed state->handCount[currentPlayer]--; to state->handCount[currentPlayer]++;
    changed z++; to z--;
    
updated_smithy() function bugs:
    changed for (i = 0; i < 3; i++) to for (i = 1; i < 3; i++)
    changed discardCard(handPos, currentPlayer, state, 0); to discardCard(handPos, currentPlayer, state, 1);

updated_village() function bugs:
    changed state->numActions = state->numActions + 2; to state->numActions = state->numActions + 4;
    
updated_steward() function bugs:
    changed if (choice1 == 1) to if (choice2 == 1)
    changed else if (choice1 == 2) to else if (choice3 == 2)
    changed state->coins = state->coins + 2; to state->coins = state->coins + 4;
    changed discardCard(handPos, currentPlayer, state, 0); to discardCard(handPos, currentPlayer, state, 1);

updated_embargo() function bugs:
    changed state->coins = state->coins + 2; to state->coins = state->coins + 4;
    changed state->embargoTokens[choice1]++; to state->embargoTokens[choice1]--;

