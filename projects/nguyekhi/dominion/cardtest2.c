/*
- The function for the card adventurer is draw card until you draw 2 treasure cards and put it in your hand discard the other drawn cards
that are not treasure cards. I also notice that you always discard the played card, but in this function I don't see that execution.
Therefore the test I will have is check the number of cards in hand before and after playing the adventurer card.
The numCardsHand (after playing the adventurer card) should = numCardsHand (before playing the adventurer card) + 2 - 1.
The last 2 cards in hand (which are the treasure cards we just drawn) must be treasure cards.
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main (int argc, char* argv[])
{
    printf("testing adventurer card effect.\n");
    struct gameState G;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    initializeGame(2, k, 2, &G);
    int player = whoseTurn(&G);
    int tempNumCardsHand = G.handCount[player];
    int tempNumCardsDeck = G.deckCount[player];
    int tempNumCardsDisCard = G.discardCount[player];
    //printf("number of cards in hand before play adventurer = %d\n", tempNumCardsHand);
    //printf("number of cards in deck before play adventurer = %d\n", tempNumCardsDeck);
    //printf("number of cards in discard before play adventurer = %d\n", tempNumCardsDisCard);

    CEadventurer(&G, player, 2);

    //printf("number of cards in hand after play adventurer = %d\n", G.handCount[player]);
    //printf("number of cards in deck after play adventurer = %d\n", G.deckCount[player]);
    //printf("number of cards in discard after play adventurer = %d\n", G.discardCount[player]);
    int lastCard1 = G.hand[player][G.handCount[player]-1];
    int lastCard2 = G.hand[player][G.handCount[player]-2];
    //printf("the last card in hand = %d\n", lastCard1);
    //printf("the second to last card in hand = %d\n", lastCard2);

    int numCardDrawn = tempNumCardsDeck - G.deckCount[player];
    //printf("number of card draw = %d\n", numCardDrawn);

    if (G.handCount[player] != tempNumCardsHand + 2 - 1)
        printf("test fail, the number of card in hand do not add up\n");
    if (lastCard1 != copper || lastCard2 != copper)
        printf("test fail, the player did not acquire the treasure cards\n");
    if (G.discardCount[player] != numCardDrawn - 2 + 1)     // -2 are the treasure cards they should be in hand not discard, +1 is the discard of adventurer
        printf("test fail,  the number of card in discard do not add up\n");

    /* there are a lot of bugs in the function of adventurer, the number of cards in hand, deck and discard do not add up to the correct number after
    execute the adventurer() function. The bugs are:
    1. while (drawntreasure <= 2), it will draw 3 treasure cards instead of 2. So it should be drawntreasure < 2
    2. cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]]; It should be state->handCount[currentPlayer] - 1. this execution is trying
    to access the last card in hand by using the handCount. However the array start at 0, so the last card is hand[handSize - 1], not the handSize.
    3. while(z >=0), and tempHand[z], it should be z - 1 >= 0, and tempHand[z-1]. the first tempHand[z] is null. This is the bug I introduce
    4. The major bug in this function is it does not discard the adventurer card.
    */
    return 0;
}



