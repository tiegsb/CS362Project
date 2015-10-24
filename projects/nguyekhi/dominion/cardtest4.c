/*
- The function for the card great hall is the current player draw 1 card, and numAction increase by 1. So I just have to check the number of cards and number of
actions of the current player after play great_hall card. I also check whether it discard the great_hall card after play it
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main (int argc, char* argv[])
{
    printf("testing great_hall card effect.\n");
    struct gameState G;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    initializeGame(3, k, 2, &G);
    int player = whoseTurn(&G);
    int tempHandCount = G.handCount[player];
    printf("number of card in the hand of current player = %d\n", tempHandCount);
    int tempNumActions = G.numActions;
    printf("number of actions of current player = %d\n", tempNumActions);

    CEgreat_hall(player, &G, 2);
    printf("number of card in the hand of current player = %d\n", G.handCount[player]);
    printf("number of actions of current player = %d\n", G.numActions);
    if (G.handCount[player] != tempHandCount)
        printf("test fail, the player draw more/less than 1 card\n");
    if (tempNumActions != G.numActions)
        printf("test fail, the number of action do not increase by 1\n");
    return 0;
}
