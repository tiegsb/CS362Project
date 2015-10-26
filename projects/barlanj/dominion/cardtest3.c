/*
    Test for the council room card.

    The council room card allows the player to draw +4 cards, +1 Buy
    and allows the other players to also draw +1 card
*/

#include <stdbool.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "rngs.h"
#include <stdbool.h>

void setStateForPlayer(int player, struct gameState *G,
                       int testHand[], int handCount,
                       int deckPile[], int deckCoun,
                       int discardPile[], int discardCount);
void printGameStateValues(struct gameState *G, int player);

int main()
{
    int i;
    srand(time(NULL));

    int numPlayer = 2;
    int player1 = 0;
    int player2 = 1;
    int k[10] = {adventurer, council_room, feast, gardens, mine,
                 remodel, smithy, village, baron, great_hall
                };

    int handPos = 0;
    int handCount = 5;
    int discardCount = 5;
    int deckCount = 5;

    //player 1
    int testHand1[5] = {council_room, copper, copper, copper, copper}; //use only one council_room for test3!
    int discardPile1[5] = {silver, silver, silver, silver, silver};
    int deckPile1[5] = {gold, gold, gold, gold, gold};

    //player 2
    int testHand2[5] = {council_room, copper, copper, copper, copper};
    int discardPile2[5] = {silver, silver, silver, silver, silver};
    int deckPile2[5] = {gold, gold, gold, gold, gold};


    struct gameState G;
    int gameSeed = rand() % 1000 + 1;
    memset(&G, 23, sizeof(struct gameState));
    initializeGame(numPlayer, k, gameSeed, &G);

    //=========================================================================
    printf("Test 1: Playing the councilroom card from hand. Check if successful play. \n");

    //set states for player 1 and 2
    setStateForPlayer(player1, &G, testHand1, handCount,
                      deckPile1, deckCount, discardPile1, discardCount);
    setStateForPlayer(player2, &G, testHand2, handCount,
                      deckPile2, deckCount, discardPile2, discardCount);
    //player 1 goes first
    G.whoseTurn = player1;

    printf("   BEFORE P1: ");
    printGameStateValues(&G, player1);
    printf("   BEFORE P2: ");
    printGameStateValues(&G, player2);


    if(playCard(handPos, -1, -1, -1, &G) == 0)
    {
        printf("  >> PASSED: successfully played councilroom card. \n");
    }
    else
    {
        printf("  >> FAILED: unable to play councilroom card. \n");
    }

    //=========================================================================
    printf("Test 2: Checking if gamestate of both player changed appropriately. \n");
    printf("        Will check handCount, deckCount, buys, playedCardCount \n");

    printf("   AFTER P1: ");
    printGameStateValues(&G, player1);
    printf("   AFTER P2: ");
    printGameStateValues(&G, player2);



    bool test2_check = true;
    //check hand count of both player
    if(G.handCount[player1] != (handCount + 4 - 1))
    {
        printf("  >> FAILED: got %d for handCount, expected %d for P1 \n",
               G.handCount[player1], handCount+4-1);
        test2_check = false;
    }

    if(G.handCount[player2] != (handCount + 1))
    {
        printf("  >> FAILED: got %d for handCount, expected %d for P2 \n",
               G.handCount[player2], handCount+1);
        test2_check = false;
    }

    if(G.deckCount[player1] != (deckCount - 4))
    {
        printf("  >> FAILED: got %d for deckCount, expected %d for P1 \n",
               G.deckCount[player1], handCount-4);
        test2_check = false;
    }

    if(G.deckCount[player2] != (deckCount - 1))
    {
        printf("  >> FAILED: got %d for deckCount, expected %d for P2 \n",
               G.deckCount[player2], handCount-1);
        test2_check = false;
    }

    if(G.numBuys != 2)
    {
        printf("  >> FAILED: got %d for Buys, expected %d for P1 \n",
               G.numBuys, 2);
        test2_check = false;
    }

    if(G.playedCardCount != 1)
    {
        printf("  >> FAILED: got %d for playedCardCount, expected %d \n",
               G.playedCardCount, 1);
        test2_check = false;
    }

    if(test2_check)
    {
        printf("  >> PASSED: All gamestate properties as expected. \n");
    }

    //=========================================================================
    printf("Test 3: Checking if councilroom discarded from hand. \n");

    bool test3_check = true;
    for(i = 0; i < G.handCount[player1]; i++)
    {
        if(G.hand[player1][i] == council_room)
        {
            test3_check = false;
            break;
        }
    }

    if(test3_check)
    {
        printf("  >> PASSED: councilroom discarded. \n");
    }


    return 0;

}

void printGameStateValues(struct gameState *G, int player)
{
    printf("handCount: %d | deckCount: %d | discardCount: %d | playedCards: %d | buys: %d | coins: %d \n",
           G->handCount[player], G->deckCount[player], G->discardCount[player], G->playedCardCount, G->numBuys, G->coins);
}

void setStateForPlayer(int player, struct gameState *G,
                       int testHand[], int handCount,
                       int deckPile[], int deckCount,
                       int discardPile[], int discardCount)
{
    memcpy(G->hand[player], testHand, sizeof(int)*handCount);
    memcpy(G->discard[player], discardPile, sizeof(int)*handCount);
    memcpy(G->deck[player], deckPile, sizeof(int)*handCount);
    G->handCount[player] = handCount;
    G->deckCount[player] = deckCount;
    G->discardCount[player] = discardCount;
    G->phase = 0;
    G->numActions = 1;
    G->coins = 0;
}

