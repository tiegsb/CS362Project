/*
    This is a test of the fullDeckCount() function. The fullDeckCount() counts
    the total number of cards for a specific card-name from the deck,
    the hand, and the discard pile.
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

int testFullDeckCount(enum CARD card, int player, struct gameState *G, int expected_result);
void generateCards(enum CARD card, int inDeck, int inHand, int inDiscard, struct gameState *G, int player);
int main()
{

    srand(time(NULL));
    int expected_result ;

    int numPlayer = MAX_PLAYERS;
    int player;
    int k[10] = {adventurer, council_room, feast, gardens, mine,
                 remodel, smithy, village, baron, great_hall
                };

    int inHand, inDeck, inDiscard;
    enum CARD card;

    struct gameState G;
    int gameSeed = rand() % 1000 + 1;
    memset(&G, 23, sizeof(struct gameState));
    initializeGame(numPlayer, k, gameSeed, &G);


    //================================================================
    int fail_count = 0;
    int run_total = 50;
    int i;
    for(i = 0; i < run_total; i++)
    {
        card = (enum CARD)(rand() % 27); // pick a random card
        inDeck = rand() % 11;
        inHand = rand() % 6;
        inDiscard = rand() % 6;
        player = rand() % MAX_PLAYERS;

        printf("Test %d: [card enum = %d] deck=%d, hand=%d, discard=%d | P%d\n",
               i+1, (int)card, inDeck, inHand, inDiscard, player+1);
        expected_result = inDeck + inHand + inDiscard;
        generateCards(card, inDeck, inHand, inDiscard, &G, player);
        fail_count += testFullDeckCount(card, player, &G, expected_result);
    }


    printf("-------------------------------------\n");
    printf("FAILED: %d | PASSED: %d | TOTAL: %d \n", fail_count, run_total-fail_count, run_total );



    //================================================================

    return 0;
}

int testFullDeckCount(enum CARD card, int player, struct gameState *G, int expected_result)
{

    int actual_result = fullDeckCount(player, card, G);

    if(actual_result == expected_result)
    {
        printf("  >> PASSED ");
    }
    else
    {
        printf("  >> FAILED ");
    }

    printf("Expected = %d | Actual = %d \n", expected_result, actual_result);

    if(actual_result != expected_result)
        return 1;

    return 0;
}

void generateCards(enum CARD card, int inDeck, int inHand, int inDiscard, struct gameState *G, int player)
{

    int i;
    G->deckCount[player] = inDeck;
    for(i = 0; i < inDeck; i++)
    {
        G->deck[player][i] = card;
    }

    G->handCount[player] = inHand;
    for(i = 0; i < inHand; i++)
    {
        G->hand[player][i] = card;
    }

    G->discardCount[player] = inDiscard;
    for(i = 0; i < inDiscard; i++)
    {
        G->discard[player][i] = card;
    }
}




