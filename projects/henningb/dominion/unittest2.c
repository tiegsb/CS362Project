/*
 * Tests isGameOver function
 */
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main (){

    int r;
    int failures = 0;   //Number of checks failed
    int comparison;

    int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

    //Initialize game
    struct gameState post;
    r = initializeGame(2, k, 1, &post);

    printf("Testing function isGameOver\n");

    //Test case 1: Provinces empty
    //isGameOver should return 1; game state should not be changed
    printf("Test Case 1: Provinces are empty, no kingdom cards are empty\n");
    post.supplyCount[province] = 0;
    struct gameState pre;
    memcpy(&pre, &post, sizeof(struct gameState));
    r = isGameOver(&post);
    printf("Testing isGameOver return value. Expecting 1. ");
    if(r == 1){
        printf("Returned 1 ... PASS\n");
    }
    else{
        printf("Returned %d ... FAIL\n", r);
        failures++;
    }
    comparison = memcmp(&pre, &post, sizeof(struct gameState));
    printf("Testing that game state is unchanged ... ");
    if(comparison == 0){
        printf("PASS\n");
    }
    else{
        printf("FAIL\n");
        failures++;
    }

    //Test case 2: Provinces not empty. One kingdom card empty
    printf("\nTest Case 2: Provinces not empty. One kingdom card empty\n");
    r = initializeGame(2, k, 1, &post);
    post.supplyCount[council_room] = 0;
    post.supplyCount[province] = 10; //Make sure province not empty
    memcpy(&pre, &post, sizeof(struct gameState));
    r = isGameOver(&post);

    //Test return value
    printf("Testing isGameOver return value. Expecting 0. ");
    if(r == 0){
        printf("Returned 0 ... PASS\n");
    }
    else{
        printf("Returned %d ... FAIL\n", r);
        failures++;
    }

    //Test game state
    comparison = memcmp(&pre, &post, sizeof(struct gameState));
    printf("Testing that game state is unchanged ... ");
    if(comparison == 0){
        printf("PASS\n");
    }
    else{
        printf("FAIL\n");
        failures++;
    }

    //Test case 3: Provinces not empty. Two kingdom cards empty
    printf("\nTest Case 3: Provinces not empty. Two kingdom cards empty\n");
    r = initializeGame(2, k, 1, &post);
    post.supplyCount[council_room] = 0;
    post.supplyCount[baron] = 0;
    post.supplyCount[province] = 10; //Make sure province not empty
    memcpy(&pre, &post, sizeof(struct gameState));
    r = isGameOver(&post);

    //Test return value
    printf("Testing isGameOver return value. Expecting 0. ");
    if(r == 0){
        printf("Returned 0 ... PASS\n");
    }
    else{
        printf("Returned %d ... FAIL\n", r);
        failures++;
    }

    //Test game state
    comparison = memcmp(&pre, &post, sizeof(struct gameState));
    printf("Testing that game state is unchanged ... ");
    if(comparison == 0){
        printf("PASS\n");
    }
    else{
        printf("FAIL\n");
        failures++;
    }

    //Test case 4: Provinces not empty. Three kingdom cards empty
    printf("\nTest Case 4: Provinces not empty. Three kingdom cards empty\n");
    r = initializeGame(2, k, 1, &post);
    post.supplyCount[council_room] = 0;
    post.supplyCount[baron] = 0;
    post.supplyCount[remodel] = 0;
    post.supplyCount[province] = 10; //Make sure province not empty
    memcpy(&pre, &post, sizeof(struct gameState));
    r = isGameOver(&post);

    //Test return value
    printf("Testing isGameOver return value. Expecting 1. ");
    if(r == 1){
        printf("Returned 1 ... PASS\n");
    }
    else{
        printf("Returned %d ... FAIL\n", r);
        failures++;
    }

    //Test game state
    comparison = memcmp(&pre, &post, sizeof(struct gameState));
    printf("Testing that game state is unchanged ... ");
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

   //Test case 5: Provinces not empty. Three kingdom cards almost empty
    printf("\nTest Case 5: Provinces not empty. Three kingdom cards have 1 remaining\n");
    r = initializeGame(2, k, 1, &post);
    post.supplyCount[council_room] = 1;
    post.supplyCount[baron] = 1;
    post.supplyCount[remodel] = 1;
    post.supplyCount[province] = 10; //Make sure province not empty
    memcpy(&pre, &post, sizeof(struct gameState));
    r = isGameOver(&post);

    //Test return value
    printf("Testing isGameOver return value. Expecting 0. ");
    if(r == 0){
        printf("Returned 0 ... PASS\n");
    }
    else{
        printf("Returned %d ... FAIL\n", r);
        failures++;
    }

    //Test game state
    comparison = memcmp(&pre, &post, sizeof(struct gameState));
    printf("Testing that game state is unchanged ... ");
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
