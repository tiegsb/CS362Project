/*
 * Tests updateCoins function
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

    printf("Testing function updateCoins\n\n");

/**********************************************************
    Case 1: hand with 0 copper, 0 silver, 0 gold, no bonus
************************************************************/
    printf("Case 1: 5 card hand, 0 copper, 0 silver, 0 gold, no bonus\n");
    r = initializeGame(2, k, 1, &post);
    post.handCount[player] = 5;
    post.hand[player][0] = baron;
    post.hand[player][1] = baron;
    post.hand[player][2] = baron;
    post.hand[player][3] = baron;
    post.hand[player][4] = baron;

    struct gameState pre;
    memcpy(&pre, &post, sizeof(struct gameState));

    r = updateCoins(player, &post, 0);

    //Coins should be 0
    printf("Testing coins. Expecting 0. ");
    if(post.coins == 0){
        printf("Returned 0 ... PASS\n");
    }
    else{
        printf("Returned %d ... FAIL\n", post.coins);
    }

    //Nothing else in game state should change
    printf("Testing that rest of game state is unchanged ... ");
    pre.coins = post.coins;
    comparison = memcmp(&pre, &post, sizeof(struct gameState));
    if(comparison == 0){
        printf("PASS\n");
    }
    else{
        printf("FAIL\n");
        failures++;
    }


/**********************************************************
    Case 2: hand with 1 copper, 0 silver, 0 gold, no bonus
************************************************************/
    printf("\nCase 2: 5 card hand, 1 copper, 0 silver, 0 gold, no bonus\n");
    r = initializeGame(2, k, 1, &post);
    post.handCount[player] = 5;
    post.hand[player][0] = copper;
    post.hand[player][1] = baron;
    post.hand[player][2] = baron;
    post.hand[player][3] = baron;
    post.hand[player][4] = baron;

    memcpy(&pre, &post, sizeof(struct gameState));

    r = updateCoins(player, &post, 0);

    //Coins should be 1
    printf("Testing coins. Expecting 1. ");
    if(post.coins == 1){
        printf("Returned 1 ... PASS\n");
    }
    else{
        printf("Returned %d ... FAIL\n", post.coins);
    }

    //Nothing else in game state should change
    printf("Testing that rest of game state is unchanged ... ");
    pre.coins = post.coins;
    comparison = memcmp(&pre, &post, sizeof(struct gameState));
    if(comparison == 0){
        printf("PASS\n");
    }
    else{
        printf("FAIL\n");
        failures++;
    }

/**********************************************************
    Case 3: hand with 1 copper, 1 silver, 0 gold, no bonus
************************************************************/
    printf("\nCase 3: 5 card hand, 1 copper, 1 silver, 0 gold, no bonus\n");
    r = initializeGame(2, k, 1, &post);
    post.handCount[player] = 5;
    post.hand[player][0] = copper;
    post.hand[player][1] = baron;
    post.hand[player][2] = silver;
    post.hand[player][3] = baron;
    post.hand[player][4] = baron;

    memcpy(&pre, &post, sizeof(struct gameState));

    r = updateCoins(player, &post, 0);

    //Coins should be 3
    printf("Testing coins. Expecting 3. ");
    if(post.coins == 3){
        printf("Returned 3 ... PASS\n");
    }
    else{
        printf("Returned %d ... FAIL\n", post.coins);
    }

    //Nothing else in game state should change
    printf("Testing that rest of game state is unchanged ... ");
    pre.coins = post.coins;
    comparison = memcmp(&pre, &post, sizeof(struct gameState));
    if(comparison == 0){
        printf("PASS\n");
    }
    else{
        printf("FAIL\n");
        failures++;
    }

/**********************************************************
    Case 4: hand with 1 copper, 1 silver, 1 gold, no bonus
************************************************************/
    printf("\nCase 4: 5 card hand, 1 copper, 1 silver, 1 gold, no bonus\n");
    r = initializeGame(2, k, 1, &post);
    post.handCount[player] = 5;
    post.hand[player][0] = copper;
    post.hand[player][1] = baron;
    post.hand[player][2] = silver;
    post.hand[player][3] = baron;
    post.hand[player][4] = gold;

    memcpy(&pre, &post, sizeof(struct gameState));

    r = updateCoins(player, &post, 0);

    //Coins should be 6
    printf("Testing coins. Expecting 6. ");
    if(post.coins == 6){
        printf("Returned 6 ... PASS\n");
    }
    else{
        printf("Returned %d ... FAIL\n", post.coins);
    }

    //Nothing else in game state should change
    printf("Testing that rest of game state is unchanged ... ");
    pre.coins = post.coins;
    comparison = memcmp(&pre, &post, sizeof(struct gameState));
    if(comparison == 0){
        printf("PASS\n");
    }
    else{
        printf("FAIL\n");
        failures++;
    }

/**********************************************************
    Case 5: hand with 1 copper, 1 silver, 1 gold, 5 bonus
************************************************************/
    printf("\nCase 5: 5 card hand, 1 copper, 1 silver, 1 gold, 5 bonus\n");
    r = initializeGame(2, k, 1, &post);
    post.handCount[player] = 5;
    post.hand[player][0] = copper;
    post.hand[player][1] = baron;
    post.hand[player][2] = silver;
    post.hand[player][3] = baron;
    post.hand[player][4] = gold;

    memcpy(&pre, &post, sizeof(struct gameState));

    r = updateCoins(player, &post, 5);

    //Coins should be 11
    printf("Testing coins. Expecting 11. ");
    if(post.coins == 11){
        printf("Returned 11 ... PASS\n");
    }
    else{
        printf("Returned %d ... FAIL\n", post.coins);
    }

    //Nothing else in game state should change
    printf("Testing that rest of game state is unchanged ... ");
    pre.coins = post.coins;
    comparison = memcmp(&pre, &post, sizeof(struct gameState));
    if(comparison == 0){
        printf("PASS\n");
    }
    else{
        printf("FAIL\n");
        failures++;
    }

/**********************************************************
    Case 6: hand with 1 copper, 1 silver, 2 gold, 5 bonus
************************************************************/
    printf("\nCase 6: 5 card hand, 1 copper, 1 silver, 2 gold, 5 bonus\n");
    r = initializeGame(2, k, 1, &post);
    post.handCount[player] = 5;
    post.hand[player][0] = copper;
    post.hand[player][1] = gold;
    post.hand[player][2] = silver;
    post.hand[player][3] = baron;
    post.hand[player][4] = gold;

    memcpy(&pre, &post, sizeof(struct gameState));

    r = updateCoins(player, &post, 5);

    //Coins should be 11
    printf("Testing coins. Expecting 14. ");
    if(post.coins == 14){
        printf("Returned 14 ... PASS\n");
    }
    else{
        printf("Returned %d ... FAIL\n", post.coins);
    }

    //Nothing else in game state should change
    printf("Testing that rest of game state is unchanged ... ");
    pre.coins = post.coins;
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
