
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
#include <assert.h>

#define MAX_TEST_CASE 20

void setStateForPlayer(int player, struct gameState *G,
                       int testHand[], int handCount,
                       int deckPile[], int deckCoun,
                       int discardPile[], int discardCount);
void printGameStateValues(struct gameState *G);

int main()
{
    int i, j, m;
    srand(time(NULL));
    int player;
    int numPlayer;
    int handPos = 0;
    int k_cards[10] = {adventurer, council_room, feast, gardens, mine,
                 remodel, smithy, village, baron, great_hall
                };

    int handCount;
    int discardCount;
    int deckCount;

    int* playerHands[MAX_PLAYERS];
    int* playerDiscardPile[MAX_PLAYERS];
    int* playerDeckPile[MAX_PLAYERS];

    //int *testHand; //= {adventurer, remodel, smithy, village, great_hall};
    //int *discardPile; //[5] = {copper, copper, copper, copper, copper};
    //int *deckPile1; //[5] = {remodel, copper, remodel, adventurer, gold};

    struct gameState G;
    int gameSeed;


    //=========================================================================

    for(i = 0; i < MAX_TEST_CASE; i++)
    {
        printf("Test %d: \n", i+1);

        //clear and start new game
        numPlayer = rand() % MAX_PLAYERS + 1;
        gameSeed = rand() % 1000 + 1;;
        memset(&G, 23, sizeof(struct gameState));
        initializeGame(numPlayer, k_cards, gameSeed, &G);

        //set random parameters
        handCount = rand() % MAX_HAND + 1;
        discardCount = rand() % MAX_DECK + 1;
        deckCount = rand() % MAX_DECK + 1;

        //assign cards to test hand, discard, and deck
        for(m = 0; m < numPlayer; m++)
        {

            int *testHand = calloc(handCount, sizeof(int));
            int *discardPile = calloc(discardCount, sizeof(int));
            int *deckPile1 =  calloc(deckCount, sizeof(int));

            assert(testHand != NULL);
            assert(discardPile != NULL);
            assert(deckPile1 != NULL);

            for(j = 0; j < handCount; j++)
            {
                testHand[j] = k_cards[rand() % 10];
            }
            for(j = 0; j < discardCount; j++)
            {
                discardPile[j] = k_cards[rand() % 10];
            }
            for(j = 0; j < deckCount; j++)
            {
                deckPile1[j] = k_cards[rand() % 10];
            }

            playerHands[m] = testHand;
            playerDiscardPile[m] = discardPile;
            playerDeckPile[m] = deckPile1;

            setStateForPlayer(m, &G, testHand, handCount,
                              deckPile1, deckCount, discardPile, discardCount);
        }

        //pick a random player
        player = rand() % numPlayer;
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

        //clean up
        for(m = 0; m < numPlayer; m++)
        {
            free(playerHands[m]);
            free(playerDiscardPile[m]);
            free(playerDeckPile[m]);
        }

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
