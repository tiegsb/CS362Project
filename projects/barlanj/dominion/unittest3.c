/*
    This is a test of the shuffle() function.
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

void testShuffle(int handCount, struct gameState G, int numPlayer, int kingdomCards[],
                 int gameSeed, int player, int player_deck_post[], int player_deck_pre[]);
void printDeck(int player, int handCount, struct gameState G);
bool isDeckShuffled(int player_deck_pre[], int player_deck_post[], int handCount);

int main()
{

    srand(time(NULL));
    int gameSeed = rand() % 1000 + 1;
    int numPlayer = 2;
    int player1 = 0;
    int player2 = 1;
    int k[10] = {adventurer, council_room, feast, gardens, mine,
                 remodel, smithy, village, baron, great_hall
                };

    int handCount = 5;
    int player_deck_post[5] = {copper, silver, gold, adventurer, council_room};
    int player_deck_pre[5] = {copper, silver, gold, adventurer, council_room};

    struct gameState G;


    //================================================================
    printf("Test 1: player 1 deck - [copper, silver, gold, adventurer, council_room] \n");
    testShuffle(handCount, G, numPlayer, k,
                gameSeed, player1, player_deck_post, player_deck_pre);

    //================================================================
    printf("Test 2: player 2 deck - [copper, silver, gold, adventurer, council_room] \n");
    testShuffle(handCount, G, numPlayer, k,
                gameSeed, player2, player_deck_post, player_deck_pre);

    return 0;
}

void testShuffle(int handCount, struct gameState G, int numPlayer, int kingdomCards[],
                 int gameSeed, int player, int player_deck_post[], int player_deck_pre[])
{

    memset(&G, 23, sizeof(struct gameState));
    initializeGame(numPlayer, kingdomCards, gameSeed, &G);
    memcpy(G.deck[player], player_deck_post, sizeof(int)*handCount);

    G.handCount[player] = handCount;

    int i;
    for(i = 0; i < handCount; i++)
    {
        player_deck_pre[i] = G.deck[player][i];
    }

    printf("  Before shuffle: ");
    printDeck(player, handCount, G);

    shuffle(player, &G);

    printf("  After shuffle : ");
    printDeck(player, handCount, G);

    for(i = 0; i < handCount; i++)
    {
        player_deck_post[i] = G.deck[player][i];
    }

    isDeckShuffled(player_deck_pre, player_deck_post, handCount);
}

void printDeck(int player, int handCount, struct gameState G)
{

    int i;
    for(i = 0; i < handCount; i++)
    {
        printf(" [ %d ] ", G.deck[player][i]);
    }
    printf("\n");
}

bool isDeckShuffled(int player_deck_pre[], int player_deck_post[], int handCount)
{
    int pos_changed;

    int i;
    for(i = 0; i < handCount; i++)
    {
        if(player_deck_pre[i] != player_deck_post[i])
            pos_changed++;
    }

    if(pos_changed)
    {
        printf("  >> PASSED \n");
    }
    else
    {
        printf("  >> FAILED \n");
    }

    return pos_changed;
}
