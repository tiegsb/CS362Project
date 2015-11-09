/*
This program will random test the function CEsteward(). I haven't test this card in the last assignment
so I decide to do it here. According to the specification, this card will have 3 different choices
1. +2 cards, 2. +2 coins, 3. trash 2 cards from hand. Similar to CEadventurer I will check the cards in hand
and coins of the gameState before and after the player play the card. The randomness of this test is deckCount
and handCount and discardCount, and coins
*/

#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int main()
{
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, steward};
    struct gameState game;
    srand(time(NULL));
    int numTests = 10000;
    int i;
    int numFails = 0;
    for (i = 0; i < numTests; i++)
    {
        int seed = rand();
        initializeGame(2, k, seed, &game);
        int player = rand() % 2;        //random player 1 or 2
        game.deckCount[player] = rand() % MAX_DECK;     //random deckCount
        game.discardCount[player] = (rand() % MAX_DECK);    //random discardCount
        game.handCount[player] = rand() % MAX_HAND;     //random handCount
        game.coins = rand() % 10;  //random coins from 0 to 10
        struct gameState before;
        struct gameState after;
        int handPos = rand() % 10;
        memcpy(&before, &game, sizeof(struct gameState));
        int choice1 = rand() % 3 + 1;   //random choice1
        int choice2 = rand() % 10;  //random choice2
        int choice3 = rand() % 10;  //random choice3
        CEsteward(player, &game, choice1, choice2, choice3, handPos);
        memcpy(&after, &game, sizeof(struct gameState));

        //check to see if the function draw 2 treasure cards or not
        if(choice1 == 1)
        {
            if (after.handCount[player] != before.handCount[player] + 1)
            {
                numFails++;
                printf("Error, the player do not draw 2 cards\n");
            }
            if (after.deckCount[player] != before.deckCount[player] - 2)
            {
                numFails++;
                printf("Error, the player do not draw 2 cards\n");
            }
            if (after.discardCount[player] != before.discardCount[player] + 1)
            {
                numFails++;
                printf("Error, the player do not discard the steward card\n");
            }
        }
        if (choice1 == 2)
        {
            if (after.coins != before.coins + 2)
            {
                numFails++;
                printf("Error, the player do not gain 2 coins\n");
            }
        }
        if (choice1 == 3)
        {
            if (before.discardCount[player] != after.discardCount[player] + 1)
            {
                numFails++;
                printf("Error, the player do not discard 2 cards\n");
            }
        }
        printf("choice1 = %d, choice 2 = %d, choice3 = %d\n", choice1, choice2, choice3);
        printf ("gameState before play adventurer card : player %d coin %d handCount %d deckCount %d discardCount %d\n",
		player, before.coins, before.handCount[player], before.deckCount[player], before.discardCount[player]);
		printf ("gameState after play adventurer card : player %d coin %d handCount %d deckCount %d discardCount %d\n\n",
		player, after.coins, after.handCount[player], after.deckCount[player], after.discardCount[player]);
    }
    printf ("%d out of %d Tests failed\n",numFails , numTests*3);
    return 0;
}

