#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(NULL));
    
    int randNum;
    int randPlus;
    int randAdd;
    int result;
    int i;
   
 
    printf("\n");
    printf("*------------------------- Unit Test #1 -------------------------*\n\n");
    printf("Testing if compare returns -1 when a > b, 1 when a < b, and 0 when a=b. \n");

    for(i=0; i < 10; i++){
        
        printf("Pass: %d\n", i);
        
        randNum = rand() % 1000;
        randAdd = rand() % 1000;
        randAdd += 1;
        
        //Add a number so that it is bigger than the first random number
        randPlus = randNum + randAdd;
        
        //Compare the bigger and smaller number to test for correct result.
        result = compare(&randNum, &randPlus);
        assert(result == -1);
        printf("%d\n", result);
        
        result = compare(&randPlus, &randNum);
        assert(result == 1);
        printf("%d\n", result);

        result = compare(&randNum, &randNum);
        assert(result == 0);
        printf("%d\n", result);
        
    }
        
    printf("All unittest #1 tests passed!\n");

    
    return 0;
}
