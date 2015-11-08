/*
This program will random test the function CEadventurer(). According to the specification, this function
will draw until it obtain 2 treasure cards, and shuffle when the deck is empty (while drawing)
and then discard all the drawn card. Therefore I will compare the game state before and after execute
this function, if they don't match the expected result, the program will display the error at
which part in the function. The randomness of this test is deckCount and handCount and discardCount
This function originally has a bug at z >=0 and temphand[z] where it should be z - 1 >= 0 and temphand[z-1]
But this bug is too severe, and it will cause segmentation fault and crash the program for this random test,
so I have to remove this bug.

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
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState game;
    srand(time(NULL));
    int numTests = 1000;
    int i;
    int numFails = 0;
    for (i = 0; i < numTests; i++)
    {
        int seed = rand();
        initializeGame(2, k, seed, &game);
        int player = rand() % 2;        //random player
        game.deckCount[player] = rand() % MAX_DECK;     //random deckCount
        game.discardCount[player] = (rand() % MAX_DECK);    //random discardCount
        game.handCount[player] = rand() % MAX_HAND;     //random handCount
        struct gameState before;
        struct gameState after;
        memcpy(&before, &game, sizeof(struct gameState));
        int handPos = rand() % 10;  //random the position of the adventurer card
        CEadventurer(&game, player, handPos);
        memcpy(&after, &game, sizeof(struct gameState));

        //check to see if the function draw 2 treasure cards or not
        int cardDrawn = after.hand[player][after.handCount[player] - 1];
        int drawnTreasure = 0;
        if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
            drawnTreasure++;
        cardDrawn = after.hand[player][after.handCount[player] - 1];
        if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
            drawnTreasure++;
        if (drawnTreasure != 2)
        {
            numFails++;
            printf("Error, the function do not draw 2 treasure cards\n");
        }
        //check whether player obtain 2 cards and discard 1 card or not
        if (after.handCount[player] != before.handCount[player] + 2)
        {
            if (after.handCount[player] != before.handCount[player] + 1)
            {
                numFails++;
                printf("Error, the player do not draw 2 cards\n");
            }
        }
        // check the number of deckCount and discardCount
        if (before.deckCount[player] - after.deckCount[player] != after.discardCount[player] - before.discardCount[player] + 1)
        {
            numFails++;
            printf("Error, deckCount and discardCount do not add up\n");
        }
        printf ("gameState before play adventurer card : player %d handCount %d deckCount %d discardCount %d\n",
		player, before.handCount[player], before.deckCount[player], before.discardCount[player]);
		printf ("gameState after play adventurer card : player %d handCount %d deckCount %d discardCount %d\n\n",
		player, after.handCount[player], after.deckCount[player], after.discardCount[player]);
    }
    printf ("%d out of %d Tests failed\n",numFails , numTests * 3);
    return 0;
}
