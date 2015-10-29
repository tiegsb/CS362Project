#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1

// Test the 'getCost' function

int main () {
    int i, j, k;  // initialize integers used in testing
    
    
    // start random number generator
    time_t t;
    srand((unsigned) time(&t));
    
    /*
        getCost
        The getCost function takes an int argument and returns an int. The argument is the 
        cardNumber and the return value is the cost of the card. The expected inputs are 
        integer values between 0 and 26. Any other values should return -1. 
        To test getCost random integers will be inserted into the function and the output
        will be checked. 
    */
    
    for (i = 0; i < 1000; i++) {
        j = (rand() % 1000) - 200; // testing random numbers between -200 and 799, should be enough range for test
        k = getCost(j);
        if (j < 27 && j > -1)
            assert (0 <= k && k <=8); // the return values should be between 0 and 8 for valid cards
        else
            assert (k == -1);
    }
    
    printf ("All %d tests passed\n", i);
    
    return 0;
}
