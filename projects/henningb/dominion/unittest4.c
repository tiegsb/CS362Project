/*
 * Tests buyCard function
 */
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main (){

    int r, player;
    int failures = 0;   //Number of checks failed
    int comparison;

    int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

    //Initialize game
    struct gameState post;

    player = 1;

    printf("Testing function buyCard\n\n");

/**********************************************************
    Case 1: Attempt to buy card with no buys
************************************************************/
    printf("Case 1: Attempt to buy card with no buys\n");
    r = initializeGame(2, k, 1, &post);
    post.whoseTurn = 1; //Player 1's turn
    post.coins = 100;   //Coins should not be an issue here
    post.supplyCount[7] = 1;   //Player will attempt to buy adventurer. Should be in stock.
    post.numBuys = 0;      //Player should have no buys

    struct gameState pre;
    memcpy(&pre, &post, sizeof(struct gameState));

    //Try to buy adventurer
    r = buyCard(7, &post);

    //Return value should be -1
    printf("Testing return value. Expecting -1. ");
    if(r == -1){
        printf("Returned -1 ... PASS\n");
    }
    else{
        printf("Returned %d ... FAIL\n", r);
        failures++;
    }

    //Game state should be unchanged
    printf("Testing that game state is unchanged ... ");
    comparison = memcmp(&pre, &post, sizeof(struct gameState));
    if(comparison == 0){
        printf("PASS\n");
    }
    else{
        printf("FAIL\n");
        failures++;
    }

/**********************************************************
    Case 2: Attempt to buy card that is out of stock
************************************************************/
    printf("\nCase 2: Attempt to buy sold-out card\n");
    r = initializeGame(2, k, 1, &post);
    post.whoseTurn = 1; //Player 1's turn
    post.coins = 100;   //Coins should not be an issue here
    post.supplyCount[7] = 0;   //Player will attempt to buy adventurer. Make sure none left.
    post.numBuys = 1;      //Player should have buys

    memcpy(&pre, &post, sizeof(struct gameState));

    //Try to buy adventurer
    r = buyCard(7, &post);

    //Return value should be -1
    printf("Testing return value. Expecting -1. ");
    if(r == -1){
        printf("Returned -1 ... PASS\n");
    }
    else{
        printf("Returned %d ... FAIL\n", r);
        failures++;
    }

    //Game state should be unchanged
    printf("Testing that game state is unchanged ... ");
    comparison = memcmp(&pre, &post, sizeof(struct gameState));
    if(comparison == 0){
        printf("PASS\n");
    }
    else{
        printf("FAIL\n");
        failures++;
    }

/**********************************************************
    Case 3: Attempt to buy card with insufficient coins
************************************************************/
    printf("\nCase 3: Attempt to buy card with insufficient coins\n");
    r = initializeGame(2, k, 1, &post);
    post.whoseTurn = 1; //Player 1's turn
    post.coins = 1;   //Not enough coins for adventurer
    post.supplyCount[7] = 1;   //Player will attempt to buy adventurer.
    post.numBuys = 1;      //Player should have buys

    memcpy(&pre, &post, sizeof(struct gameState));

    //Try to buy adventurer
    r = buyCard(7, &post);

    //Return value should be -1
    printf("Testing return value. Expecting -1. ");
    if(r == -1){
        printf("Returned -1 ... PASS\n");
    }
    else{
        printf("Returned %d ... FAIL\n", r);
        failures++;
    }

    //Game state should be unchanged
    printf("Testing that game state is unchanged ... ");
    comparison = memcmp(&pre, &post, sizeof(struct gameState));
    if(comparison == 0){
        printf("PASS\n");
    }
    else{
        printf("FAIL\n");
        failures++;
    }

/**********************************************************
    Case 4: Attempt to buy card with just enough coins
************************************************************/
    printf("\nCase 4: Attempt to buy card just enough coins\n");
    r = initializeGame(2, k, 1, &post);
    post.whoseTurn = 1; //Player 1's turn
    post.coins = 6;   //Just enough coins for adventurer
    post.supplyCount[7] = 1;   //Make sure adventurer is in stock
    post.numBuys = 1;      //Player should have buys

    memcpy(&pre, &post, sizeof(struct gameState));

    //Try to buy adventurer
    r = buyCard(7, &post);

    //Return value should be 0
    printf("Testing return value. Expecting 0. ");
    if(r == 0){
        printf("Returned 0 ... PASS\n");
    }
    else{
        printf("Returned %d ... FAIL\n", r);
        failures++;
    }

    //Test that coins were used. Should now be 0
    printf("Testing number of coins after purchase. Expecting 0. ");
    if(post.coins == 0){
        printf("Returned 0 ... PASS\n");
    }
    else{
        printf("Returned %d ... FAIL\n", post.coins);
        failures++;
    }

    //Test that supply of purchased card is decremented
    printf("Testing that adventurer supply is decremented. Should now be 0 ... ");
    if(post.supplyCount[7] == 0){
        printf("PASS\n");
    }
    else{
        printf("FAIL\n");
        failures++;
    }

    //Test that player's discard pile is incremented (purchased card goes in discard pile)
    printf("Testing that player's discard pile is incremented ... ");
    if(post.discardCount[player] == pre.discardCount[player] + 1){
        printf("PASS\n");
    }
    else{
        printf("FAIL\n");
        failures++;
    }

    //Test that numBuys is decremented
    printf("Testing that player's numBuys was decremented ... ");
    if(post.numBuys == 0){
        printf("PASS\n");
    }
    else{
        printf("FAIL\n");
        failures++;
    }

    //Test that last card in player's discard pile is adventurer
    printf("Testing that new card in player's discard pile is adventurer ... ");
    if(post.discard[player][post.discardCount[player]-1] == adventurer){
        printf("PASS\n");
    }
    else{
        printf("FAIL\n");
        failures++;
    }


    //Nothing else in game state should be unchanged
    printf("Testing that rest of game state is unchanged ... ");
    //Update game state pre to match the tested parts above
    pre.coins = pre.coins - 6;
    pre.supplyCount[7]--;
    pre.discardCount[player]++;
    pre.numBuys--;
    pre.discard[player][post.discardCount[player]-1] = adventurer;

    comparison = memcmp(&pre, &post, sizeof(struct gameState));
    if(comparison == 0){
        printf("PASS\n");
    }
    else{
        printf("FAIL\n");
        failures++;
    }


   if(failures == 0){
        printf("All tests passed\n");
   }
   else{
        printf("%d failures occurred\n", failures);
   }

    return 0;
}
