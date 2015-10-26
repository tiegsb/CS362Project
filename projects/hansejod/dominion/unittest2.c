#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include<stdlib.h>
#include<time.h>


int isvalueinarray(int val, int *arr){
    int i;
    for (i=0; i < 3; i++) {
        if (arr[i] == val)
            return 1;
    }
    return 0;
}

int main()
{
    int seed = 1000;
    int numPlayer = 2;
    int k[10] = {adventurer, council_room, feast, gardens, mine
        , remodel, smithy, village, baron, great_hall};
    int result;
    
    struct gameState game;
    
    initializeGame(numPlayer, k, seed, &game);
    
    srand(time(NULL));
    int random;
    int i;
    
    printf("\n");
    printf("*------------------------- Unit Test #2 -------------------------*\n\n");
    printf("Testing if isGameOver returns a 1 when province count equals 0 \n");
    printf("and returns 0 when province card is 1 or more. \n");
    
    //Provide random values for the supply count of province with a range of 0 -9
    //Check to make sure that gameOver returns the correct result when the province
    //count is 0 or more.
    for(i=0; i<50; i++){
        random = rand() % 8;
        game.supplyCount[province] = random;
        
        printf("Calling isGameOver function!\n");
        result = isGameOver(&game);
        
        printf("Print province count: %d, Print isGameOver value: %d\n", random, result);
        if(random == 0){
            assert(result == 1);
        }
        else{
            assert(result == 0);
        }
    }
    
    
    int j;
    int n;
    int y;
    

    printf("\n");
    printf("Testing if game ends when three kingdom cards equals 0. \n");
    
    for(y=0; y<10; y++){
        
        int count = 0;
        
        printf("Pass %d:\n", y);
        
        // Load up the supply cards with random numbers;
        for (j = 0; j < 26; j++){
            random = (rand() % 9) + 1;
            game.supplyCount[j] = random;
            result = game.supplyCount[j];
            if(result != 0){
                count++;
            }
        }
    
        // Double check that the kingdom cards have been replaced.
        if(count == 26){
            printf("All cards are set to a value 1-10. \n");
        }
    
        // Game over should return 0 because all kingdom cards are set to 1 or more.
        printf("Calling isGameOver function!\n");
        result = isGameOver(&game);
        assert(result == 0);
    
        printf("Result value is: %d \n", result);
        printf("Game did not end when cards are set to a value 1-10.\n\n");
    
        int a[5] = {0,0,0,0,0};
    
    
        int dynLoopCounter;
        dynLoopCounter = (rand() % 2) + 3;
    
        // Set 3 - 5 kingdom cards as 0
        for (n = 0; n < dynLoopCounter; n++){
            while(isvalueinarray(random, a)){
                random = (rand() % 26);
            }
            a[n] = random;
            printf("Print card number: %d\n", random);
            game.supplyCount[random] = 0;
            result = game.supplyCount[random];
            printf("Print card value: %d\n", result);
        }
    
        printf("Three or more supply cards are set to 0. \n");
        result = isGameOver(&game);
        if(result==1){
            printf("Result value is: %d \n", result);
            printf("Game ended when three supply cards are set to 0.\n\n");
        }
        else{
            printf("Result value is: %d \n", result);
            printf("Bug found! gameOver does not check all supply cards.\n\n");
        }
    
        // Set all but two kingdom cards to 0. 
        game.supplyCount[a[4]] = 10;
        game.supplyCount[a[3]] = 10;
        game.supplyCount[a[2]] = 10;
        game.supplyCount[province] = 8;


        printf("Two supply cards are set to 0. \n");
        printf("Calling isGameOver function!\n");
        result = isGameOver(&game);
        assert(result==0);
    
        printf("Result value is: %d \n", result);
        printf("Game did not end when two supply cards are set to 0.\n\n");
    
    
    }
    
    printf("All unit #2 tests passed! \n");
    return 0;
}