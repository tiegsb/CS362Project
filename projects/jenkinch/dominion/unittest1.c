/* -----------------------------------------------------------------------
 * unittest1.c
 * Test of isGameOver() in dominion.c
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int testIsGameOver() {
    int seed = 1000;
    int numPlayer = 2;
    int r;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, sea_hag, treasure_map};
    struct gameState G;

    printf ("TESTING isGameOver():\n");
    
    //Test that game is not over immediately after initialization
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
    
    if (!isGameOver(&G))
        printf("isGameOver(): PASS when game is initialized\n");
    else
        printf("isGameOver(): FAIL when game is initialized\n");
    
    //Test when province cards run out
    G.supplyCount[province] = 0;
    
    if (isGameOver(&G))
        printf("isGameOver(): PASS when province pile is empty\n");
    else
        printf("isGameOver(): FAIL when province pile is empty\n");
    
    //Test when there is only one province card
    G.supplyCount[province]++;
    
    if (!isGameOver(&G))
        printf("isGameOver(): PASS when province pile is set to 1\n");
    else
        printf("isGameOver(): FAIL when province pile is set to 1\n");
    
    //Reset and test when gardens cards run out
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
    G.supplyCount[gardens] = 0;
    
    if (!isGameOver(&G))
        printf("isGameOver(): PASS when gardens pile is empty\n");
    else
        printf("isGameOver(): FAIL when gardens pile is empty\n");
    
    //Test when gardens and copper cards run out
    G.supplyCount[copper] = 0;
    
    if (!isGameOver(&G))
        printf("isGameOver(): PASS when gardens and copper piles are empty\n");
    else
        printf("isGameOver(): FAIL when gardens and copper piles are empty\n");
    
    //Test when gardens, copper, and treasure_map cards run out
    G.supplyCount[treasure_map] = 0;
    
    if (isGameOver(&G))
        printf("isGameOver(): PASS when gardens, copper, and treasure_map piles are empty\n");
    else
        printf("isGameOver(): FAIL when gardens, copper, and treasure_map piles are empty\n");
    
    //Reset and test when sea_hag cards run out
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
    G.supplyCount[sea_hag] = 0;
    
    if (!isGameOver(&G))
        printf("isGameOver(): PASS when sea_hag pile is empty\n");
    else
        printf("isGameOver(): FAIL when sea_hag pile is empty\n");
    
    //Test when sea_hag and silver cards run out
    G.supplyCount[silver] = 0;
    
    if (!isGameOver(&G))
        printf("isGameOver(): PASS when sea_hag and silver piles are empty\n");
    else
        printf("isGameOver(): FAIL when sea_hag and silver piles are empty\n");
    
    //Test when sea_hag, silver, and gold cards run out
    G.supplyCount[gold] = 0;
    
    if (isGameOver(&G))
        printf("isGameOver(): PASS when sea_hag, silver, and gold piles are empty\n");
    else
        printf("isGameOver(): FAIL when sea_hag, silver, and gold piles are empty\n");
    
    //Reset and test when curse cards run out
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
    G.supplyCount[curse] = 0;
    
    if (!isGameOver(&G))
        printf("isGameOver(): PASS when curse pile is empty\n");
    else
        printf("isGameOver(): FAIL when curse pile is empty\n");
    
    //Test when curse and estate cards run out
    G.supplyCount[estate] = 0;
    
    if (!isGameOver(&G))
        printf("isGameOver(): PASS when curse and estate piles are empty\n");
    else
        printf("isGameOver(): FAIL when curse and estate piles are empty\n");
    
    //Test when curse, estate, and duchy cards run out
    G.supplyCount[duchy] = 0;
    
    if (isGameOver(&G))
        printf("isGameOver(): PASS when curse, estate, and duchy piles are empty\n");
    else
        printf("isGameOver(): FAIL when curse, estate, and duchy piles are empty\n");

    return 0;
}

int main(int argc, char *argv[])
{
    testIsGameOver();
    return 0;
}