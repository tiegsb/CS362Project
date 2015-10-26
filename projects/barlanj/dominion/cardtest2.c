/*
    Test for the adventurer card.

    The adventurer card reveals cards from your deck until
    you reveal 2 treasure cards. Put those Treasure cards
    into your hand and discard the other revealed cards.
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
    int i;
    srand(time(NULL));

    int numPlayer = MAX_PLAYERS;
    int player = 0;
    int handPos = 0;
    int k[10] = {adventurer, council_room, feast, gardens, mine,
                 remodel, smithy, village, baron, great_hall
                };

    int handCount = 5;
    int discardCount = 5;
    int deckCount = 5;

    int testHand[5] = {adventurer, remodel, smithy, village, great_hall};
    int discardPile[5] = {copper, copper, copper, copper, copper};
    int deckPile1[5] = {remodel, copper, remodel, adventurer, gold};

    struct gameState G;
    int gameSeed = rand() % 1000 + 1;
    memset(&G, 23, sizeof(struct gameState));
    initializeGame(numPlayer, k, gameSeed, &G);

    //=========================================================================

    printf("Test 1: Playing the adventurer card from hand. Check if successful play. \n");
    player = 0;
    setStateForPlayer(player, &G, testHand, handCount,
                      deckPile1, deckCount, discardPile, discardCount);
    G.whoseTurn = player;

    //play the card
    if(playCard(handPos, -1, -1, -1, &G) == 0)
    {
        printf("  >> PASSED: successfully played adventurer card. \n");
    }
    else
    {
        printf("  >> FAILED: unable to play adventurer card. \n");
    }

    //=========================================================================
    printf("Test 2: Check if gamestate properties properly updated \n");
    printf("        Condition - 2 coins in deck, second coin located at second to last. \n");
    printf("  GameState Before play: handCount: %d | deckCount: %d | discardCount: %d | playedCards: %d \n",
           handCount, deckCount, discardCount, G.playedCardCount);

    printf("  GameState After play : ");
    printGameStateValues(&G);

    bool checked = true;
    if(G.handCount[0] != (handCount - 1 + 3))
    {
        printf("  >> FAILED: handCount was not changed properly \n");
        checked = false;
    }

    if (G.deckCount[0] != 1)   //deckPile1 should leave one card behind, no shuffling
    {
        printf("  >> FAILED: deckCount was not changed properly. \n");
        checked = false;
    }

    if (G.discardCount[0] != (discardCount + 2))   // +2 for the cards between the coins in deckPile1
    {
        printf("  >> FAILED: no discard should have taken place during effect \n");
        checked = false;
    }

    if (G.playedCardCount != 1)
    {
        printf("  >> FAILED: adventure card should have been played \n");
        checked = false;
    }

    if (checked)
    {
        printf("  >> PASSED: adventurer card effect successful \n");
    }

    //=========================================================================
    printf("Test 3: Check if drawn cards were coins \n");

    printf("   Hand: ");
    int count_treasure = 0;
    for(i = 0; i < G.handCount[0]; i++)
    {
        printf(" [ %d ] ", G.hand[player][i]);
        if(G.hand[player][i] == copper || G.hand[player][i] == silver|| G.hand[player][i] == gold)
        {
            count_treasure++;
        }
    }
    printf("\n");

    if(count_treasure != 2)
    {
        printf("  >> FAILED: should only have two treasure card in hand \n");
    }
    else
    {
        printf("  >> PASSED: two treasure card found in hand \n");
    }


    return 0;

}

void printGameStateValues(struct gameState *G)
{
    printf("handCount: %d | deckCount: %d | discardCount: %d | playedCards: %d \n",
           G->handCount[0], G->deckCount[0], G->discardCount[0], G->playedCardCount);
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
