/*
- this program test the function CEsmithy. Since the card allow the current player draw 3 cards and discard the smithy card, we just have
to test the number of cards in hand. If the number of cards in hand (after we play the card) = to the number of cards in hand (before we
play the card) + 3 - 1, we pass the test. Otherwise the test fail
- It is even better to check all the properties in the gameState to make sure they are unchanged, but I look at the code and it doesn't
seem like it change anything else beside the number of card in hand.
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main (int argc, char* argv[])
{
    printf("testing smithy card effect.\n");
    struct gameState G;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    initializeGame(2, k, 2, &G);
    int player = whoseTurn(&G);
    int tempNumCardsHand = G.handCount[player];
    //printf("number of cards in hand before play smithy = %d\n", G.handCount[player]);
    //printf("G.hand[%d][2] = %d\n", player, G.hand[player][2]);
    CEsmithy(player, &G, 2);
    //printf("number of cards in hand after play smithy = %d\n", G.handCount[player]);

    // I also check to make sure the function discard the card at the input hand position (it is not smithy card though, because I never
    //acquire it, but it doesn't matter, because I just want to test the function of smithy card
    //printf("G.hand[%d][2] = %d\n", player, G.hand[player][2]);
    printf("number of cards in hand = %d\n", G.handCount[player]);
    if (G.handCount[player] != tempNumCardsHand + 3 - 1)
        printf("test fail, the player draw more or less than 3 cards\n");
    return 0;
}

