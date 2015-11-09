
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

#define MAX_TEST_CASE 500000
#define TEST_DEBUG false

#define RESET  "\033[0m"
#define KBLU  "\x1B[34m"
#define KRED  "\x1B[31m"
#define KYEL  "\x1B[33m"
#define KGRN  "\x1B[32m"

void setStateForPlayer(int player, struct gameState *G,
                       int testHand[], int handCount,
                       int deckPile[], int deckCoun,
                       int discardPile[], int discardCount);
void printGameStateValues(struct gameState *G);
int getRandomFromRange(int M, int N);
int findCardFromList(enum CARD card, struct gameState *g, int player, int handCount);
int countCardFromDeck(enum CARD card, struct gameState *G);
int countCardFromHand(enum CARD card, struct gameState *G);

int main()
{
    int pass_count = 0;
    int fail_count = 0;
    bool failed;
    int i, j, m;
    srand(time(NULL));
    int player;
    int numPlayer;
    int k_cards[13] = {adventurer, council_room, feast, gardens, mine,
                       remodel, smithy, village, baron, great_hall,
                       copper, silver, gold
                      };
    int smithy_count = 0;
    int handCount;
    int discardCount;
    int deckCount;

    int* playerHands[MAX_PLAYERS];
    int* playerDiscardPile[MAX_PLAYERS];
    int* playerDeckPile[MAX_PLAYERS];

    struct gameState G;
    int gameSeed;


    //=========================================================================

    for(i = 0; i < MAX_TEST_CASE; i++)
    {
        failed = false;

        if(TEST_DEBUG)
        {
            printf("------------------\n");
            printf(KYEL "Test %d: " RESET, i+1);
        }

        //clear and start new game
        numPlayer = getRandomFromRange(2, MAX_PLAYERS);
        gameSeed = rand() % 1000 + 1;
        memset(&G, 23, sizeof(struct gameState));
        initializeGame(numPlayer, k_cards, gameSeed, &G);

        //set random parameters
        handCount = getRandomFromRange(0, MAX_HAND);
        discardCount = getRandomFromRange(0, MAX_HAND);
        deckCount = getRandomFromRange(0, MAX_DECK);
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
                testHand[j] = k_cards[rand() % 13];
            }
            for(j = 0; j < discardCount; j++)
            {
                discardPile[j] = k_cards[rand() % 13];
            }
            for(j = 0; j < deckCount; j++)
            {
                deckPile1[j] = k_cards[rand() % 13];
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
        smithy_count = countCardFromHand(smithy, &G);

        if(TEST_DEBUG)
        {
            printf("HAND: Smithy = %d, Cards = %d", smithy_count, G.handCount[player]);
        }

        int foundSmithy = findCardFromList(smithy, &G, player, handCount);
        if(countCardFromDeck(adventurer, &G) > 0)
        {
            if(foundSmithy == -1)
            {
                if(TEST_DEBUG)
                    printf(KRED "  >> FAILED: unable to play card. \n" RESET);
                failed = true;
            }
            else
            {
                playCard(foundSmithy, -1, -1, -1, &G);
                if(G.handCount[player] != (handCount - 1 + 3))
                {
                    if(TEST_DEBUG)
                        printf(KRED "  >> FAILED: handCount not updated properly. \n" RESET);
                    failed = true;
                }
                else if(G.deckCount[player] != (deckCount - 3)) //should have decreased or shuffled
                {
                    if(TEST_DEBUG)
                        printf(KRED "  >> FAILED: deckCount not updated properly. \n" RESET);
                    failed = true;
                }
            }
        }

        if(failed)
        {
            fail_count++;
        }
        else
        {
            pass_count++;
            if(TEST_DEBUG)
                printf(KGRN "  >> PASSED \n" RESET);
        }

        //clean up
        for(m = 0; m < numPlayer; m++)
        {
            free(playerHands[m]);
            free(playerDiscardPile[m]);
            free(playerDeckPile[m]);
        }

    }

    printf("=====================================\n");
    printf("PASSED: %d  |  FAILED: %d   |  TOTAL: %d \n", pass_count, fail_count, MAX_TEST_CASE);
    printf("=====================================\n");


    return 0;

}

int countCardFromDeck(enum CARD card, struct gameState *G)
{
    int count = 0;

    int i;
    for(i = 0; i < G->deckCount[G->whoseTurn]; i++)
    {
        if(G->deck[G->whoseTurn][i] == card)
            count++;
    }

    return count;
}

int countCardFromHand(enum CARD card, struct gameState *G)
{
    int count = 0;

    int i;
    for(i = 0; i < G->handCount[G->whoseTurn]; i++)
    {
        if(G->hand[G->whoseTurn][i] == card)
            count++;
    }

    return count;
}

int findCardFromList(enum CARD card, struct gameState *G, int player, int handCount)
{
    int i;
    for(i = 0; i < G->handCount[player]; i++)
    {
        if(G->hand[player][i] == card)
            return i;
    }

    return -1; //not found
}

void printGameStateValues(struct gameState *G)
{
    printf("handCount: %d | deckCount: %d |  playedCards: %d \n",
           G->handCount[G->whoseTurn], G->deckCount[G->whoseTurn], G->playedCardCount);
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

int getRandomFromRange(int M, int N)
{
    return (M + rand() / (RAND_MAX / (N - M + 1) + 1));
}
