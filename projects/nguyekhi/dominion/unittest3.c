/*
- I write the test for shuffle() function. I test the valid and invalid input of player, and check the return value of the function.
I also check the unshuffle rate of the function, if it is 100% that means the shuffle() function doesn't work properly
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main (int argc, char* argv[])
{
    printf("Testing shuffle() function.\n");
    struct gameState G;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    initializeGame(2, k, 2, &G);
    // test the invalid and valid input of player, and the function return value
    int r1 = shuffle(2, &G);
    printf("the return value of invalid input = %d\n", r1);
    if (r1 != -1)
        printf("test fail, invalid input, but the function doesn't return -1\n");

    // clone the current deck as temp, so we can compare after we shuffle
    int r2 = shuffle(1, &G);
    printf("the return value of valid input = %d\n", r2);
    if (r2 != 0)
        printf("test fail, valid input and function does not return 0.\n");

    // test the function itself, whether it change the position of the card in the deck around
    int i;
    int j;
    int unshuffle = 0;    // counter to count the number of time the card in the deck stay in the same position after shuffle
    for (i = 0; i < 10; i++)
    {
        int tempDeck[1][10];    // copy the current deck to compare after shuffle
        for (j = 0; j < 10; j++)
        {
            tempDeck[1][j] = G.deck[1][j];
        }
        shuffle(1, &G);
        int k;
        for (k = 0; k < 10; k++)
        {
            //printf("tempDeck[1][%d] = %d\n", k, tempDeck[1][k]);
            //printf("G.deck[1][%d] = %d\n", k, G.deck[1][k]);
            if (tempDeck[1][k] == G.deck[1][k])
                unshuffle++;
        }
    }
    printf("the number of time the card is not shuffle = %d%%\n", unshuffle);
    // I shuffle about 10 times, and so we kind of compare 100 cards and the number of car that is not shuffle is 66% which is high,
    //but if we think about it, it does make a lot of sense because the deck contains 7 coppers and 3 estate, which mean the chance
    //the position replace by the same card is high especially copper. However 33% of the time the card change place, which mean
    // the copper and estate do change their position sometimes
    // if we get 100% unshuffle rate, that means the deck does not shuffle at all, we can display error
    if (unshuffle == 100)
        printf("the shuffle function doesn't work\n");
    printf("shuffle function test pass\n");
    return 0;
}
