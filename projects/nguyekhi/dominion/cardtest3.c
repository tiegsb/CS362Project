/*
- The function for the card council_room is the current player draw 4 cards and the other player draw 1 card. I am going to test the number of cards in each
player hand before and after play the council_room card. The current player also have to discard the council_room card.
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main (int argc, char* argv[])
{
    printf("testing council_room card effect.\n");
    struct gameState G;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    initializeGame(3, k, 2, &G);
    int player = whoseTurn(&G);
    int tempNumCardsHand = G.handCount[player];
    int tempNumCardsDeck = G.deckCount[player];
    int tempNumCardsDisCard = G.discardCount[player];
    int numPlayers = G.numPlayers;
    int currentPlayer = G.whoseTurn;
    //printf("current player = %d\n", currentPlayer);

    int tempArrayPlayer[numPlayers];
    tempArrayPlayer[currentPlayer] = G.handCount[currentPlayer];
    //printf("number of cards in current player hand = %d\n", tempArrayPlayer[currentPlayer]);
    int i;
    for (i = 0; i < numPlayers; i++)
    {
        if ( i != currentPlayer)
            tempArrayPlayer[i] = G.handCount[i];
        //printf("number of cards in player%d hand = %d\n", i, tempArrayPlayer[i]);
    }

    CEcouncil_room(currentPlayer, &G, 2);
    int j;
    for (j = 0; j < numPlayers; j++)
    {
        if ( j == currentPlayer)
        {
            if (G.handCount[currentPlayer] != tempArrayPlayer[currentPlayer] + 3)
                printf("test fail, the number of cards in current player do not add up\n");
            //printf("number of cards in current player hand = %d\n", G.handCount[currentPlayer]);
        }
        else
        {
            if (G.handCount[j] != tempArrayPlayer[j] + 1)
                printf("test fail, the number of cards in player %d do not add up\n", j);
            //printf("number of cards in player%d hand = %d\n", i, G.handCount[i]);
        }
    }
    return 0;
    /*
    So the bug in this function is the bug that I introduce:
    1. I switch the number of card draw (4) of the current player with the number of player. If the game has 4 players, it might pass the test
    2. I switch the number of player that draw 1 card to 4, again if the number of player is 4. The bug will not trigger
    I kind of like this bug
    */
}





