/* -----------------------------------------------------------------------
 * Demonstration of how to write unit tests for dominion-base
 * Include the following lines in your makefile:
 *
 * testUpdateCoins: testUpdateCoins.c dominion.o rngs.o
 *      gcc -o testUpdateCoins -g  testUpdateCoins.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int main() {

     int i = 0;
     int result;
     bool pass = true;
     int desired[27]= {0};
     

     //create array of desired results
     desired[0] = 0;
     desired[1] = 2;
     desired[2] = 5;
     desired[3] = 8;
     desired[4] = 0;
     desired[5] = 3;
     desired[6] = 6;
     desired[7] = 6;
     desired[8] = 5;
     desired[9] = 4;
     desired[10] = 4;
     desired[11] = 5;
     desired[12] = 4;
     desired[13] = 4;
     desired[14] = 3;
     desired[15] = 4; 
     desired[16] = 3;
     desired[17] = 5;
     desired[18] = 3;
     desired[19] = 5;
     desired[20] = 3;
     desired[21] = 4;
     desired[22] = 2;
     desired[23] = 5;
     desired[24] = 4;
     desired[25] = 4;
     desired[26] = 4;
 
     printf("TESTING getCost():\n");
    
     //test for every card
     for (i = 0; i < 27; i++){
          result = getCost(i);
          printf("Result: %d \t Expected: %d\n", result, desired[i]);
          if (result != desired[i]){
               pass = false;
          }
     }
     //test for out of bounds
     result = getCost(-1);
     printf("Result: %d \t Expected: %d\n", result, -1);
     if (result != -1){
          pass = false;
     }

     result = getCost(500);
     printf("Result: %d \t Expected: %d\n", result, -1);
     if (result != -1){
          pass = false;
     }

     if (pass == false)
          printf("All tests did not pass\n");
     else
          printf("All tests passed\n");
     return 0;
}
