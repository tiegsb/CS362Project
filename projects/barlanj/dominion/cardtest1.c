/*
    Test for the smithy card.

    The smithy card cost 4 treasures and has +3 cards when played.
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

void setStateForPlayer(int player, struct gameState *G,
                       int testHand[], int handCount,
                       int deckPile[], int deckCoun,
                       int discardPile[], int discardCount);
void printGameStateValues(struct gameState *G);

int main()
{
    srand(time(NULL));
    int numPlayer = MAX_PLAYERS;
    int player = 0;
    int handPos = 0;
    int k[10] = {adventurer, council_room, feast, gardens, mine,
                 remodel, smithy, village, baron, great_hall
                };

    int handCount = 5;
    int discardCount = 10;
    int deckCount = 10;

    int testHand[5] = {smithy, copper, copper, silver, gold};
    int discardPile[5] = {copper, copper, copper, copper, copper};
    int deckPile[5] = {adventurer, adventurer, adventurer, adventurer, adventurer};

    struct gameState G;

    int gameSeed = rand() % 1000 + 1;
    memset(&G, 23, sizeof(struct gameState));
    initializeGame(numPlayer, k, gameSeed, &G);

    //=========================================================================
    printf("Test 1: Playing the smithy card from hand. Check if successful play. \n");
    player = 0;
    setStateForPlayer(player, &G, testHand, handCount,
                      deckPile, deckCount, discardPile, discardCount);
    G.whoseTurn = player;

    //play the card
    //cardEffect_smithy(player, &G, handPos);
    if(playCard(handPos, -1, -1, -1, &G) == 0)
    {
        printf("  >> PASSED: successfully played smithy card. \n");
    }
    else
    {
        printf("  >> FAILED: unable to play smithy card. \n");
    }

    //=========================================================================
    printf("Test 2: Check if gamestate properties properly updated \n");
    printf("  GameState Before play: handCount: %d | deckCount: %d \n",
           handCount, deckCount);

    printf("  GameState After play : ");
    printGameStateValues(&G);

    if(G.handCount[0] != (handCount - 1 + 3))
    {
        printf("  >> FAILED: handCount was not changed properly \n");
    }
    else if (G.deckCount[0] != (deckCount - 3))
    {
        printf("  >> FAILED: deckCount was not changed properly. \n");
    }
    else
    {
        printf("  >> PASSED: smithy card effect successful \n");
    }

    return 0;

}

void printGameStateValues(struct gameState *G)
{
    printf("handCount: %d | deckCount: %d \n",
           G->handCount[0], G->deckCount[0]);
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
}
