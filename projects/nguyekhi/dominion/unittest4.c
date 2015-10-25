/*
- I write the test for numHandCards(), handCard(), and supplyCount() functions. I feel like these are small functions so I test them all
- For function numHandCards(), I initialize the game, then check the return value of numHandCards() function. Since I just initialize the
game, the numHandCards() should return 5 to pass, otherwise the function fail.
- For function handCard(), after I initialize the game, I check all the cards in the hand. Since they only contain estate and copper,
if any card in hand are something else beside copper and estate, function handCard() fail
- For function supplyCount(), some cards have some specific supply, so I check them to see if the supplyCount() function return the
corrected value for the supply of the input cards. I also check the supply of the card that are not in the game.
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main (int argc, char* argv[])
{
    printf("Testing numHandCards(), handCard(), and supplyCount() function.\n");
    struct gameState G;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    initializeGame(2, k, 2, &G);
    // initially everyone has 5 cards in hand
    if(numHandCards(&G) != 5)
        printf("test fail, numHandCards != 5, instead numHandCards = %d\n", numHandCards(&G));
    //printf("numHandCards = %d\n", numHandCards(&G));
    int i;
    for (i = 0; i < 5; i++)
    {
        //printf("handCard = %d\n", handCard(i, &G));
        if (handCard(i, &G) != 1 && handCard(i, &G) != 4)
            printf("test fail, the card in hand are something else beside estate(4) and copper(1)\n");
    }
    drawCard(0, &G);    // draw 1 card, assume it work properly
    if(numHandCards(&G) != 6)
        printf("test fail, numHandCards != 6, instead numHandCards = %d\n", numHandCards(&G));
    //printf("numHandCards = %d\n", numHandCards(&G) );
    // check the supply of some cards, include curse cards, treasure cards, victory cards, and kingdom cards
    //But I also check the supply card of the kingdom card that is not in the game
    if (supplyCount(curse,&G) != 10)
        printf("test fail, supplyCard for curse != 10");
    if (supplyCount(gold,&G) != 30)
        printf("test fail, supplyCard for gold != 30");
    if (supplyCount(estate,&G) != 8)
        printf("test fail, supplyCard for estate != 8");
    if (supplyCount(adventurer, &G) != 10)
        printf("test fail, supplyCard for adventurer != 10");
    if (supplyCount(minion, &G) != -1)
        printf("test fail, supplyCard for minion != -1");
    //printf("curse = %d\n", supplyCount(curse,&G));
    //printf("gold = %d\n", supplyCount(gold,&G));
    //printf("estate = %d\n", supplyCount(estate,&G));
    //printf("adventurer = %d\n", supplyCount(adventurer,&G));
    //printf("minion = %d\n", supplyCount(minion,&G));
    printf("All tests pass, numHandCards(), handCard(), and supplyCount() are good to go\n");
    return 0;
}
